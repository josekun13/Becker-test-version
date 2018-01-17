#!/usr/bin/python

import smbus
import math
import rospy
from time import sleep 
from std_msgs.msg import String

# Power management registers pagina 41 de la hoja de datos
power_mgmt_1 = 0x6b #reloj
power_mgmt_2 = 0x6c #wake up time "despertar"
bus = smbus.SMBus(1)
address = 0x68


def read_byte(adr):
    return bus.read_byte_data(address, adr)

def read_word(adr): #El valor del gyroscopio es de 16 bits
	high = bus.read_byte_data(address, adr)
	low = bus.read_byte_data(address, adr+1)
	val = (high << 8) + low
	return val
  
def read_word_2c(adr):
    val = read_word(adr)
    if (val >= 0x8000):
        return -((65535 - val) + 1)
    else:
        return val    
    
def x_accel(ax,ay,az):
	if ay*ay+az*az < 0.00001:
		m=0.00001
	else:
		m=ay*ay+az*az
	if ax/math.sqrt(m)>1:
		return 0
	elif ax/math.sqrt(m)<-1:
		return 180
	else:
		return math.degrees(math.acos(ax/math.sqrt(m)))
	

def x_pos(xa,gx,x):
	return 0.97*(xa+gx*0.02)+(0.03)*x	
	


def setoffset():
	xprom=0.0
	gxprom=0.0
	for i in range(1000):
		ax=read_word_2c(0x3b)
		ay=read_word_2c(0x3d)
		az=read_word_2c(0x3f)
		gx=read_word_2c(0x43)/131
		xprom=xprom+x_accel(ax,ay,az)
		gxprom=gxprom+gx
	xprom=xprom/i
	gxprom=gxprom/i
	return [xprom,gxprom]

def sendcont():
	pub = rospy.Publisher('imumsg', String, queue_size=2)
	rospy.init_node('imunode', anonymous=True)
	rate = rospy.Rate(500)
	bus.write_byte_data(address, power_mgmt_1, 0) #El 0 indica que utiliza el reloj interno 8khz
	bus.write_byte_data(address, 0x1c, 24) #Filtro pasa altas -+16g
	bus.write_byte_data(address, 0x1a, 4) #Filtro pasa bajas 44Hz accel 42hz gyro 
	offset=setoffset() #offset de inicio
	xf=0.0
	xa=0.0
	vel=([0.0 , 0.0, 0.0, 0.0])
	
	while not rospy.is_shutdown():
		gx=read_word_2c(0x43)/131
		ax=read_word_2c(0x3b)
		ay=read_word_2c(0x3d)
		az=read_word_2c(0x3f)
		x=x_accel(ax,ay,az)-offset[0]
		vel[3]=(vel[0]+vel[1]+vel[2]+vel[3]+x)/5 #filtro de 5to orden
		xg=gx-offset[1]
		xf=x_pos(xa,xg,vel[3])
		xf=int(100*xf)*0.01
		control_str=str(xf)
		xa=xf
		vel[0]=vel[1]
		vel[1]=vel[2]
		vel[2]=vel[3]
		pub.publish(control_str)
		rate.sleep()


if __name__ == '__main__':
	try:
		sendcont()
	except rospy.ROSInterruptException:
		pass


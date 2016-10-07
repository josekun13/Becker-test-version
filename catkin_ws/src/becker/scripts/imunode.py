#!/usr/bin/python

import smbus
import math
import rospy
from time import sleep 
from std_msgs.msg import String

# Power management registers
power_mgmt_1 = 0x6b
power_mgmt_2 = 0x6c
bus = smbus.SMBus(1)
address = 0x68


def read_byte(adr):
    return bus.read_byte_data(address, adr)

def read_word(adr):
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
    
def R_vector(ax,ay,az):
	if(ax*ax+ay*ay+az*az==0):
		return 0.0000000001
	else:
		return math.sqrt(ax*ax+ay*ay+az*az)
	
def x_accel(ax,r):
	return math.degrees(math.acos(ax/r))
	
def y_accel(ay,r):
	return math.degrees(math.acos(ay/r))
	
def z_accel(az,r):
	return math.degrees(math.acos(az/r))
	
def x_pos(xf,gx,x):
	return 0.985*(xf+gx*0.000125)+0.015*x	
	

def y_pos(yf,gy,y):
	return 0.985*(yf+gy*0.000125)+0.015*y
	
def z_pos(zf,gz,z):
	return 0.985*(zf+gz*0.000125)+0.015*z

def setoffset():
	ax=read_word_2c(0x3b)
	ay=read_word_2c(0x3d)
	az=read_word_2c(0x3f)
	gx=read_word_2c(0x43)
	gy=read_word_2c(0x45)
	gz=read_word_2c(0x47)
	r=R_vector(ax,ay,az)
	xprom=0.0
	yprom=0.0
	zprom=0.0
	gxprom=0.0
	gyprom=0.0
	gzprom=0.0
	for i in range(100):
		xprom=xprom+x_accel(ax,r)
		yprom=yprom+y_accel(ay,r)
		zprom=zprom+z_accel(az,r)
		gxprom=gxprom+gx
		gyprom=gyprom+gy
		gzprom=gzprom+gz
		sleep(0.01)
	xprom=xprom/i
	yprom=yprom/i
	zprom=zprom/i
	gxprom=gxprom/i
	gyprom=gyprom/i
	gzprom=gzprom/i
	return [xprom,yprom,zprom,gxprom,gyprom,gzprom]

def sendcont():
	pub = rospy.Publisher('imumsg', String, queue_size=10)
	rospy.init_node('imunode', anonymous=True)
	rate = rospy.Rate(100)
	bus.write_byte_data(address, power_mgmt_1, 0)
	offset=setoffset()
	xf=0.0
	yf=0.0
	zf=0.0
	while not rospy.is_shutdown():
		gx=read_word_2c(0x43)
		gy=read_word_2c(0x45)
		gz=read_word_2c(0x47)
		ax=read_word_2c(0x3b)
		ay=read_word_2c(0x3d)
		az=read_word_2c(0x3f)
		r=R_vector(ax,ay,az)
		x=x_accel(ax,r)-offset[0]
		y=y_accel(ay,r)-offset[1]
		z=z_accel(az,r)-offset[2]
		xg=gx-offset[3]
		yg=gy-offset[4]
		zg=gz-offset[5]
		xf=x_pos(xf,xg,x)
		yf=y_pos(yf,yg,y)
		zf=z_pos(zf,zg,z)
		control_str=str(int(xf))+" "+str(int(yf))+" "+str(int(zf))
		#rospy.loginfo(str(offset))
		pub.publish(control_str)
		rate.sleep()


if __name__ == '__main__':
	try:
		sendcont()
	except rospy.ROSInterruptException:
		pass


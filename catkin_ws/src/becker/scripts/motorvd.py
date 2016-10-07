#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  motor_vel_dir.py
#  
#  Copyright 2016  Jose Angel Martinez Navarro
#  
#  This program is free software; you can redistribute it and/or modify
#  it under the terms of the GNU General Public License as published by
#  the Free Software Foundation; either version 2 of the License, or
#  (at your option) any later version.
#  
#  This program is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#  
#  You should have received a copy of the GNU General Public License
#  along with this program; if not, write to the Free Software
#  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
#  MA 02110-1301, USA.
#  
#  

import rospy 
from std_msgs.msg import String
from gpiozero import Motor
from time import sleep 
from gpiozero import PWMLED

motor = Motor(forward=4, backward=14)
led=PWMLED(17,active_high=1,initial_value=0,frequency=1000)
motor1 = Motor(forward=27, backward=22)
led1=PWMLED(18,active_high=1,initial_value=0,frequency=1000)

def pwmanddir(data):
	m= data.data
	a=m.split()
	dirmot1=int(a[0])
	pwmmot1=float(a[1])
	dirmot2=int(a[2])
	pwmmot2=float(a[3])
	if dirmot1 > 1:
		dirmot1=1
	elif dirmot1 < 0:
		dirmot1=0
	if dirmot2 > 1:
		dirmot2=1
	elif dirmot2 < 0:
		dirmot2=0
	if pwmmot1 > 1.0:
		pwmmot1=1.0
	elif pwmmot1 < 0.0:
		pwmmot1= 0.0
	if pwmmot2 > 1.0:
		pwmmot2=1.0
	elif pwmmot2 < 0.0:
		pwmmot2=0.0
	if dirmot1 ==1:
		motor.forward()
		led.value=pwmmot1
	else:
		motor.backward()
		led.value=pwmmot1
	if dirmot2 == 1:
		motor1.backward()
		led1.value=pwmmot2
	else:
		motor1.forward()
		led1.value=pwmmot2
		
	
	

def motorvd():
	rospy.init_node('motorvd',  anonymous=True)
	rospy.Subscriber("controlmv" ,String, pwmanddir)
	rospy.spin()
	
if __name__ == '__main__':
	motorvd()

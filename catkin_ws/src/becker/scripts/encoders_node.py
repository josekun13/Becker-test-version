#!/usr/bin/env python
# -*- coding: utf-8 -*-
#
#  sendcont.py
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
import RPi.GPIO as GPIO


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

motor1a=5
motor1b=6
motor2a=13
motor2b=19

GPIO.setup(motor1a,GPIO.IN)
GPIO.setup(motor1b,GPIO.IN)
GPIO.setup(motor2a,GPIO.IN)
GPIO.setup(motor2b,GPIO.IN)

def sendpos():
	pub = rospy.Publisher('encinf', String, queue_size=10)
	rospy.init_node('encoders_node', anonymous=True)
	rate = rospy.Rate(10)
	GPIO.add_event_detect(motor1a,GPIO.BOTH)
	GPIO.add_event_detect(motor1b,GPIO.BOTH)
	GPIO.add_event_detect(motor2a,GPIO.BOTH)
	GPIO.add_event_detect(motor2b,GPIO.BOTH)
	motora=[0,0]
	ac=0
	motorb=[0,0]
	while not rospy.is_shutdown():
		if GPIO.event_detected(motor1a):
			motora[0]=motora[0]+1
		if GPIO.event_detected(motor1b):
			motora[1]=motora[1]+1
		if GPIO.event_detected(motor2a):
			motorb[0]=motorb[0]+1
		if GPIO.event_detected(motor2b):
			motorb[1]=motorb[1]+1
		control_str=str(motora)+" "+str(motorb)
		rospy.loginfo(control_str)
		pub.publish(control_str)
		rate.sleep()
		
if __name__ == '__main__':
	try:
		sendpos()
	except rospy.ROSInterruptException:
		pass
	



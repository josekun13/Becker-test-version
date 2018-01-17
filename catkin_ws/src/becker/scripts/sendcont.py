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

def sendcont():
	pub = rospy.Publisher('controlmv', String, queue_size=10)
	rospy.init_node('sendcont', anonymous=True)
	rate = rospy.Rate(8)
	while not rospy.is_shutdown():
		control_str="1 1.0 1 1.0"
		rospy.loginfo(control_str)
		pub.publish(control_str)
		rate.sleep()
		control_str="0 1.0 0 1.0"
		rospy.loginfo(control_str)
		pub.publish(control_str)
		rate.sleep()


if __name__ == '__main__':
	try:
		sendcont()
	except rospy.ROSInterruptException:
		pass


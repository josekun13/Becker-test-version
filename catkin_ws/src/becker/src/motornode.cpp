/*
 * motornode.cpp
 * 
 * Copyright 2017  <Jose Angel Martinez Navarro>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */
 
// Librerias
 
#include <sstream>
#include <iostream>
#include <wiringPi.h>
#include <softPwm.h>
#include <unistd.h>
#include <stdio.h>
#include "ros/ros.h"
#include "std_msgs/String.h"

int val[4];  //variables globales
int i;
std::stringstream ss;
int a1=12,b1=16,a2=27,b2=22,pwm1=26,pwm2=25; //pines 

//funcion que genera los pwm y mensajes
void genPwmPos(const std_msgs::String::ConstPtr& msg)
{                             //2=un robot debe proteger su propia existencia en la medida que esta proteccion no entre en conflicto con la 1ra o la 2da Ley.
	ss<<msg->data.c_str();    // lee los datos
	for(i=0;i<4;i++)
	{
		ss>>val[i];
	}
	if(val[0]==1)			//obtiene la direccion
	{
		digitalWrite(a1,1);
		digitalWrite(b1,0);
	}
	else{
		digitalWrite(a1,0);
	    digitalWrite(b1,1);
	}
	if(val[2]==1)
	{
		digitalWrite(a2,0);
		digitalWrite(b2,1);
	}
	else{
		digitalWrite(a2,1);
	    digitalWrite(b2,0);
	}							//genera el pwm
	softPwmWrite(pwm1,val[1]);
	softPwmWrite(pwm2,val[3]);
	ss.clear();
}

int main(int argc, char **argv)
{
	wiringPiSetupGpio(); //se declaran los nodos
	pinMode(a1,OUTPUT);
	pinMode(b1,OUTPUT);
	pinMode(a2,OUTPUT);
	pinMode(b2,OUTPUT);
	softPwmCreate(pwm1,0,100);
	softPwmCreate(pwm2,0,100);
	ros::init(argc, argv, "motornode"); //inicializa el nodo
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("controlmv",1000,genPwmPos); //lee el mensaje
	ros::spin();
	return 0;
}


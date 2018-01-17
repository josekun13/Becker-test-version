/*
 * encodernode.cpp
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

//Librerias

#include <wiringPi.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
//funcion principal
int main(int argc, char **argv)
{
	ros::init(argc, argv, "encodernode");//inicializa el nodo
	ros::NodeHandle n;
	int contador = 0;//contadores
	int contador2=0;
	int clk = 13;//pines
	int clk2=5;
	int dt=19;
	int dt2=6;
	wiringPiSetupGpio();//inicia wiring pi //1=un robot no puede hacer dano a un ser humano o, por inaccion, permitir que un humano sufra dano
	pinMode(clk,INPUT);
	pinMode(dt,INPUT);
	pinMode(clk2,INPUT);
	pinMode(dt2,INPUT);
	bool clkLastState=digitalRead(clk);
	bool clkLastState2=digitalRead(clk2);
	bool dtState;
	bool dtState2;
	bool clkState;
	bool clkState2;
	ros::Publisher wheelpos_pub=n.advertise<std_msgs::String>("wheelpos", 1000);//mensaje
	ros::Rate loop_rate(15000);//veces que se ejecuta por segundo
	while(ros::ok())
		{ 
		for (int i=0; i<30; i++){ //contador de la rueda 2
			clkState=digitalRead(clk);
			dtState=digitalRead(dt);
			if (clkState!=clkLastState){
				if(dtState!=clkState){
					contador++;
				}
				else{
					contador--;
				}
			}
			clkLastState=clkState;
			//------------------------------
			clkState2=digitalRead(clk2); //contador de la rueda 1
			dtState2=digitalRead(dt2);
			if (clkState2!=clkLastState2){
				if(dtState2!=clkState2){
					contador2++;
				}
				else{
					contador2--;
				}
			}
			clkLastState2=clkState2;
			loop_rate.sleep();
		}
		std_msgs::String msg;
		std::stringstream ss;
		ss << contador2*0.225 << " " << contador*0.225; //conversion a grados y publicacion
		msg.data=ss.str();
		wheelpos_pub.publish(msg);
		ros::spinOnce();
	}
	return 0;
}


/*
 * control1node.cpp
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

#include "ros/ros.h"					//libreria de ROS
#include "std_msgs/String.h"			//leer y enviar mensajes String en ROS
#include <iostream>                     
#include <sstream>
#include <math.h>
//--------------------------------------variables globales
float val[3]={0.0,0.0,0.0};				//entradas
int sal[4]={0,0,0,0};                   //salidas
float ki,kf[4],angpro;					//constantes y promedio del angulo
float derpsi,dertheta,psiac[2]={0.0,0.0},thetac[2]={0.0,0.0},integ=0.0,u; //acumuladore, integrales y salida

//--------------------------------------funcion que recibe los datos de la IMU
void imudata(const std_msgs::String::ConstPtr& msg)
{ 	                                                 
	std::stringstream ss;
	ss<<msg->data.c_str();
	ss>>val[0];
}
//--------------------------------------funcion que recibe los datos de los Encoders  // 2=un robot debe odebdecer las ordenes dadas por los seres humanos, excepto si estas ordenes entran en conflicto con la primera ley
void encoderdata(const std_msgs::String::ConstPtr& msg){
		std::stringstream  sa;
		sa<<msg->data.c_str();
		sa>>val[1];
		sa>>val[2];

}
//---------------------------------------funcion donde se realiza el algoritmo de control
void control()
{
	angpro=(val[1]+val[2])/2;			//obtiene el promedio de los encoders
	psiac[0]=val[0];					//derivadas sucias
	thetac[0]=angpro;
	derpsi=(psiac[0]-psiac[1])/0.01;
	dertheta=(thetac[0]-thetac[1])/0.01;
	psiac[1]=psiac[0];
	thetac[1]=thetac[0];
	integ=integ+angpro;					//integral discreta
	u=ki*(-integ)+kf[0]*(-angpro)+kf[1]*(-val[0])+kf[2]*(-dertheta)+kf[3]*(-derpsi); //calculo del SERVOCONTROL (PD-I)
	if (u>0)                                                                         //direccion de las ruedas
	{
		sal[0]=1;
		sal[2]=1;
	}
	else
	{
		sal[0]=0;
		sal[2]=0;
		u=-u;
	}
	if(u>100)            //tope
	{
		u=100;
	}
	sal[1]=u;
	sal[3]=u;
	
	
}
//--------------------------------------funcion principal
int main(int argc, char **argv)
{
	ros::init(argc, argv, "control1node");  //inicializa el nodo
	//--------------------------------------constantes de control
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("imumsg",1000,imudata);   //se declaran los datos de entrada y se inicializan los hilos
	ros::Subscriber sub2 = n.subscribe("wheelpos",1000,encoderdata);
	n.getParam("ki",ki);
	n.getParam("kf0",kf[0]);
	n.getParam("kf1",kf[1]);
	n.getParam("kf2",kf[2]);
	n.getParam("kf3",kf[3]);
	/*ki=-0.7071;
	kf[0]=-1.3933;
	kf[1]=-74.2680;
	kf[2]=-1.6141;
	kf[3]=-1.3836;*/
	ros::Publisher control_pub=n.advertise<std_msgs::String>("controlmv", 1000); //se declara el tipo de mensaje
	ros::Rate loop_rate(400); //la cantidad de veces que se repite por segundo
	while(ros::ok()){
		std::stringstream sb;
		control();   // el control
		sb << sal[0] << " " << sal[1] << " " << sal[2]<< " " << sal[3];
		std_msgs::String mss;
		mss.data=sb.str();
		control_pub.publish(mss); //la funcion que publica en ROS
		ros::spinOnce(); //revisa los hilos
		loop_rate.sleep();		
	}
	return 0;
}



//la IMU es una MPU 6050
// Librerias

#include <wiringPiI2C.h> //i2c
#include <wiringPi.h>//puertos
#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>
#include <sstream>
#include <math.h>

#define MPU6050_ADDRESS (0x68) //Direccion del dispositivo
#define MPU6050_CLOCK (0x6b) //Reloj interno 8MHz
#define MPU6050_PASABAJAS (0x1a) //Filtro pasa bajas
#define MPU6050_ACELEROMETRO (0x1c) //Rango del acelerometro
//funciones
float x_pos(float xa, float gx, float x);
float setoffAcell(int fd);
float setoffGyro(int fd);
float x_accel(int ax, int ay, int az);//0=un robot no puede hacer dano a la humanidad o, por inaccion, permitir que la humanidad sufra dano
int readword(int fd,int dir);
//programa principal
int main(int argc, char **argv)
{
	ros::init(argc, argv, "imunode"); //inicializa el nodo
	ros::NodeHandle n;
	int fd;
	float ante=0.0;
	float setg,seta,gx,accel,ang,sal;
	int ax,ay,az,i;
	if (wiringPiI2CSetup(0x68) == -1)
	{
		printf("Error X.x");
		return 0;
	}
	fd=wiringPiI2CSetup(MPU6050_ADDRESS);//comunicacion i2c
	wiringPiI2CWriteReg8(fd,MPU6050_CLOCK,0);//reloj interno 8MHz
	wiringPiI2CWriteReg8(fd,MPU6050_ACELEROMETRO,4);//Rango del acelerometro +-4g 
	wiringPiI2CWriteReg8(fd,MPU6050_PASABAJAS,4);//filtro pasa bajas accl y gyro 
	setg=setoffGyro(fd);//obtiene el 0 en el gyroscopio
	seta=setoffAcell(fd);//obtiene el 0 en el acelerometro
	ros::Publisher imumsg_pub=n.advertise<std_msgs::String>("imumsg", 1);
	ros::Rate loop_rate(47);// veces que se ejecuta por segundo
	while(ros::ok())
		{ 
			gx=(readword(fd,0x43)/131-setg);//lee el gyroscopio
			ax=readword(fd,0x3b);//lee el accel en x
			ay=readword(fd,0x3d);//lee el accel en y
			az=readword(fd,0x3f);//lee el accel en z
			accel=x_accel(ax,ay,az)-seta;//obtiene la velocidad angular en x
			ang=x_pos(ante,gx,accel);//obtiene la posicion en x
			loop_rate.sleep();
			ante=ang;
			sal=ang;
			sal=((float)((int)(sal*10)))/10;
			std_msgs::String msg;
			if(1.5>sal&&sal>-1.5)
			{
				sal=0.0;
			}
			std::stringstream ss;
			ss << sal;
			msg.data=ss.str();
			imumsg_pub.publish(msg);//publica los mensajes
			ros::spinOnce();
		}
	
	return 0;
}
//lee la imu
int readword(int fd, int dir)
{
	int msb,lsb,sal;
	msb=wiringPiI2CReadReg8(fd,dir);
	lsb=wiringPiI2CReadReg8(fd,dir+1);
	sal=  msb << 8 | lsb;
	if(sal>0x8000){
		sal=sal-0x10000;
	}
	return sal;
}
//obtiene la velocidad angular en x
float x_accel(int x, int y , int z)
{
	int m;
	if(y*y+z*z==0)
	{
		m=0.0000001;
	}
	else{
		m=y*y+z*z;
	}
	if(x/sqrt(m)>1)
	{
		return 0.0;
	}
	else if(x/sqrt(m)<-1)
	{
		return 180.0;
	}
	else
	{
		return (180/M_PI)*acos(x/sqrt(m));
	}
}


//obtiene el cero en el acelerometro
float setoffAcell(int fd)
{
	float Xprom=0.0;
	float x,y,z;
	for(int i=0; i<100; i++)
	{	
		x=readword(fd,0x3b);
		y=readword(fd,0x3d);
		z=readword(fd,0x3f);
		Xprom=Xprom+x_accel(x,y,z);
		delay(5);
	}
	return (Xprom/100);
}
//obtiene el cero en el gyroscopio
float setoffGyro(int fd)
{
	float Gprom=0.0;
	float gx;
	for(int i=0; i<100; i++)
	{
		gx=(readword(fd,0x43)/131);
		Gprom=Gprom+gx;
		delay(5);
	}
	return (Gprom/100);
}

//obtiene el angulo en x
float x_pos(float xa, float gx, float x)
{
	return (0.9*(xa+gx*0.021)+0.1*x);//filtro complementario
}

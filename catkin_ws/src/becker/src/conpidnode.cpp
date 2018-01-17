


#include "ros/ros.h"
#include "std_msgs/String.h"
/*#include <sstream.h>*/
#include <string>
#include <stdlib.h>

string salida;
float p=20.78;
float i=0;
float d=2.368;
float ang,sal,acu,ant;
char dir;
ant=acu=0.0;

void pidconback(const std_msgs::String::constPtr& msg)
{
	ang=strtof(msg);
	if (ang<0.1 && ang>-0.1){
		ang = 0.0;
	}
	ang=-ang
	acu=(acu+ang);
	sal=p*ang+i*acu+d*((ang-ant)/0.02);
	ant=ang
	if(sal<0.0)
	{
		dir='1';
		sal=-sal;
	}
	else
	{
		dir='0';
	}
	if (sal>1.0)
		sal=1.0;
	salida= dir + " " + sal + " " + dir + " "  + sal;
	
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "pidcon");
	ros::NodeHandle n;
	ros::Publisher controlmv_pub = n.advertise<std_msgs::String>("controlmv",1000);
	while (ros::ok()){
		ros::Subscriber sub=n.subscribe("imumsg", 1000,pidconback);
		ros::Rate loop_rate(100);
		controlmv_pub.publish(salida);
		ros::spinOnce();
		loop_rate.sleep();
	}	
	
	return 0;
}


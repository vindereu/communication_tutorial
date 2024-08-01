#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Vector3.h>
#include "control_system/pid.h"
#include <array>

std::array<double,2> gps;
std::array<double,3> target;
double height;

void cb_gps(geometry_msgs::Point msg)
{
	gps[0] = msg.x;
	gps[1] = msg.y;
}

void cb_height(std_msgs::Float64 msg)
{
	height = msg.data;
}

void cb_remote(geometry_msgs::Point msg)
{
	target[0] = msg.x;
	target[1] = msg.y;
	target[2] = msg.z;
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "computer");
	ros::NodeHandle nh;
	
	ros::Publisher pub = nh.advertise<geometry_msgs::Vector3>("cmd_vel", 10);
	geometry_msgs::Vector3 cmdMsg;

	ros::Subscriber sub_gps = nh.subscribe<geometry_msgs::Point>("gps_xy", 10, cb_gps);
	ros::Subscriber sub_height = nh.subscribe<std_msgs::Float64>("height", 10, cb_height);
	ros::Subscriber sub_cmd = nh.subscribe<geometry_msgs::Point>("remote_command", 10, cb_remote);
	
	PID<3> controller({2,0,0}, {0,0,0}, {0.1,0,0});

	ros::Rate rate(30);
	while (ros::ok()) {
		double timeNow = ros::Time::now().toSec();
		controller.target = target;
	    auto velOut = controller.update({gps[0], gps[1], height}, timeNow);
		cmdMsg.x = velOut[0];
		cmdMsg.y = velOut[1];
		cmdMsg.z = velOut[2];

		pub.publish(cmdMsg);

	    ros::spinOnce();
	    rate.sleep();
	}
	    
}
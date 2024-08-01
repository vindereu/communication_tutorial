#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <geometry_msgs/Pose.h>
// Noise
#include <random>
#include <ctime>

ros::Publisher pub;

// height sensor simulate
void callback(geometry_msgs::Pose msg)
{
    std_msgs::Float64 outMsg;
    
    //Noise Process
	double noise = (rand()%20 - 10) / 1000.0;  // +-0.01
	outMsg.data = msg.position.z + noise;
    
    // Publish
    pub.publish(outMsg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "fake_height_sensor");
	ros::NodeHandle nh;
	srand(time(0));  // set random seed by current time
	
	pub = nh.advertise<std_msgs::Float64>("height", 10);
	ros::Subscriber sub = nh.subscribe<geometry_msgs::Pose>("drone_attitude", 10, callback);
	
	ros::spin();
}
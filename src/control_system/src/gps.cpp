#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Point.h>
// Noise
#include <random>
#include <ctime>

ros::Publisher pub;

// gps simulate
void callback(geometry_msgs::Pose msg)
{
    geometry_msgs::Point outMsg;
    
    //Noise Process
	double noise = 0; //(rand()%2 - 1) / 1000.0;  // +-0.001
	outMsg.x = msg.position.x + noise;
	outMsg.y = msg.position.y + noise;
	outMsg.z = 0;
    
    // Publish
    pub.publish(outMsg);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "fake_gps");
	ros::NodeHandle nh;
	
	pub = nh.advertise<geometry_msgs::Point>("gps_xy", 10);
	ros::Subscriber sub = nh.subscribe("drone_attitude",10,callback);
	
	ros::spin();
}
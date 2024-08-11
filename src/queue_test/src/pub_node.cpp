#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "pub_node");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<std_msgs::Int32>("chat", 100);
    std_msgs::Int32 msg;

    int count = 0;
    ros::Rate rate(1);
    while (ros::ok()) {
        msg.data = count;
        count = (count == 100) ? 0 : count+1;
        std::cout << msg.data << '\n';
        pub.publish(msg);
        rate.sleep();
    }
}
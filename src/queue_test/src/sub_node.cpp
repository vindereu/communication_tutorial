#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

void callback(std_msgs::Int32 msg)
{
    std::cout << msg.data << '\n';
    ros::Duration(5).sleep();
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "sub_node");
    ros::NodeHandle nh;

    const size_t QUEUE_SIZE = 2;
    std::cout << "[Info]Queue size for subscriber: " << QUEUE_SIZE << '\n';
    ros::Subscriber sub = nh.subscribe("chat", QUEUE_SIZE, callback);
    ros::spin();
}
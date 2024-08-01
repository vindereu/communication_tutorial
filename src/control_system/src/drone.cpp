#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>
#include <geometry_msgs/Pose.h>
#include "control_system/filter.h"
#include <array>

std::array<double, 3> command;
void callback(geometry_msgs::Vector3 msg)
{
    command[0] = msg.x;
    command[1] = msg.y;
    command[2] = msg.z;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "drone");
    ros::NodeHandle nh;

    ros::Publisher pub = nh.advertise<geometry_msgs::Pose>("drone_attitude", 10);
    geometry_msgs::Pose attitudeMsg;
    attitudeMsg.position.x = 0;
    attitudeMsg.position.y = 0;
    attitudeMsg.position.z = 0;
    attitudeMsg.orientation.x = 0;
    attitudeMsg.orientation.y = 0;
    attitudeMsg.orientation.z = 0;
    attitudeMsg.orientation.w = 1;

    ros::Subscriber sub = nh.subscribe<geometry_msgs::Vector3>("cmd_vel", 10, callback);

    // Assume drone velocity response is same as the first order system
    RC_LowPass<3> system({0.01, 0.01, 0.05}, {0, 0, 0});
    double lastTime = ros::Time::now().toSec();

    ros::Rate rate(100);
    while (ros::ok()) {
        double timeNow = ros::Time::now().toSec();
        double dt = timeNow - lastTime;
        lastTime = timeNow;
        
        auto velNow = system.update(command, timeNow);

        attitudeMsg.position.x += velNow[0] * dt;
        attitudeMsg.position.y += velNow[1] * dt;
        attitudeMsg.position.z += velNow[2] * dt;
        pub.publish(attitudeMsg);
        
        ros::spinOnce();
        rate.sleep();
    }
}


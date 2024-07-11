#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "send_then_result/Arithmetic.h"
#include <limits>

void callback(send_then_result::Arithmetic msg);

ros::Publisher pub;
int main(int argc, char **argv)
{
    ros::init(argc, argv, "result_cpp");
    ros::NodeHandle nh;

    pub = nh.advertise<std_msgs::Float64>("arithmetic_result", 10);
    ros::Subscriber sub = nh.subscribe<send_then_result::Arithmetic>("arithmetic_input", 10, callback);
    ros::spin();
}

void callback(send_then_result::Arithmetic msg)
{
    static std_msgs::Float64 msgResult;

    switch (msg.operation)
    {
    case '+':
        msgResult.data = msg.left + msg.right;
        break;
    case '-':
        msgResult.data = msg.left - msg.right;
        break;
    case '*':
        msgResult.data = msg.left * msg.right;
        break;
    case '/':
        msgResult.data = (msg.right == 0.0)
                        ? std::numeric_limits<double>::quiet_NaN()
                        : (msg.left / msg.right);
        break;
    default:
        msgResult.data = std::numeric_limits<double>::quiet_NaN();
        break;
    }

    pub.publish(msgResult);
}

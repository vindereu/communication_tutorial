#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include "send_then_result/Arithmetic.h"
#include <iostream>
#include <limits>
#include <csignal>  // TODO: Use SIGINT to stop the program

bool hasResult = false;

void clean_input_buffer(std::istream &src);
bool reset_input_error(std::istream &src);

void callback(std_msgs::Float64 msg)
{
    std::cout << "[Out]" << msg.data << "\n\n";
    hasResult = true;
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "calculator_cpp");
    ros::NodeHandle nh;

    send_then_result::Arithmetic msgInput;
    ros::Publisher pub = nh.advertise<send_then_result::Arithmetic>("arithmetic_input", 10);
    ros::Subscriber sub = nh.subscribe<std_msgs::Float64>("arithmetic_result", 10, callback);

    std::cout << "[Info]Hint: <left> <operation> <right>\n"
              << "[Info]e.g. 4 + 5\n";
    while (ros::ok()) {
        std::cout << "[In]";
        std::cin >> msgInput.left >> msgInput.operation >> msgInput.right;

        if (std::cin.eof()) {
            break;
        }

        if (reset_input_error(std::cin)) {
            std::cout << "[Error]Wrong input\n\n";
            continue;
        }

        clean_input_buffer(std::cin);

        hasResult = false;
        pub.publish(msgInput);
        while (!hasResult)
            ros::spinOnce();
    }

    std::cout << "\r[Info]Done\n";
}


bool reset_input_error(std::istream &src)
{
    if (src.good())
        return false;

    src.clear();
    clean_input_buffer(src);

    return true;
}

void clean_input_buffer(std::istream &src)
{
    src.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

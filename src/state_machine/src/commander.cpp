#include <ros/ros.h>
#include "state_machine/Command.h"
#include "state_machine/command.h"
#include <iostream>
#include <csignal>  // TODO: Use SIGINT to stop the program

bool reset_input_error(std::istream &src);
void clean_input_buffer(std::istream &src);
Command parse_command(int cmd);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "commander_cpp");
    ros::NodeHandle nh;

    ros::ServiceClient client = nh.serviceClient<state_machine::Command>("command_resp_cmd");
    state_machine::Command srv;

    std::cout << "[Info]Wait the service open\n";
    client.waitForExistence();
    std::cout << "[Info]Serivce opened\n";

    std::cout << "[INFO]Hints:\n";
    std::cout << "Power off: 0\n" << "Power on: 1\n" << "Stop: 2\n"
              << "Count up: 3\n" << "Count down: 4\n" << '\n';

    int select;
    while (ros::ok()) {
        std::cout << "[In]";
        std::cin >> select;
        if (std::cin.eof())
            break;

        if (reset_input_error(std::cin)) {
            std::cout << "[Error]Wrong input\n";
            continue;
        };
        clean_input_buffer(std::cin);

        srv.request.cmd = parse_command(select);
        if (!client.call(srv)) {
            std::cout << "[Error]ROS service error\n";
            break;
        }

        std::cout << "[Out]" << srv.response.response << "\n\n";
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

Command parse_command(int cmd)
{
    switch (cmd)
    {
    case 0:
        return Command::POWER_OFF;
    case 1:
        return Command::POWER_ON;
    case 2:
        return Command::STOP;
    case 3:
        return Command::COUNT_UP;
    case 4:
        return Command::COUNT_DOWN;
    }
}

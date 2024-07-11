#include <ros/ros.h>
#include "state_machine/Command.h"
#include "state_machine/command.h"
#include <iostream>

Command state = Command::POWER_OFF;

void machine_process();

bool callback(state_machine::Command::Request &req,
              state_machine::Command::Response &resp);

int main(int argc, char **argv)
{
    ros::init(argc, argv, "machine_response_command_cpp");
    ros::NodeHandle nh;

    ros::ServiceServer service = nh.advertiseService("command_resp_cmd", callback);

    ros::Rate rate(2);
    while (ros::ok()) {
        machine_process();
        rate.sleep();
        ros::spinOnce();
    }
}

void machine_process()
{
    static int8_t count = 0;
    switch (state)
    {
    case Command::POWER_OFF:
        std::cout << "Power off\n";
        break;
    case Command::POWER_ON:
        std::cout << "Power on\n";
        break;
    case Command::STOP:
        std::cout << "Stop\n";
        break;
    case Command::COUNT_UP:
        std::cout << (int)count++ << '\n';
        break;
    case Command::COUNT_DOWN:
        std::cout << (int)count-- << '\n';
        break;
    }
}

bool callback(state_machine::Command::Request &req,
              state_machine::Command::Response &resp)
{
    switch (req.cmd)
    {
    case Command::POWER_ON:
        break;
    case Command::POWER_OFF:
        if (state == COUNT_UP || state == COUNT_DOWN) {
            resp.response = "stop first";
            return true;
        }
        break;
    case Command::COUNT_UP:
    case Command::COUNT_DOWN:
    case Command::STOP:
        if (state == POWER_OFF) {
            resp.response = "power on first";
            return true;
        }
        break;
    default:
        resp.response = "wrong command";
        return true;
    }

    resp.response = "accept";
    state = (Command)req.cmd;
    return true;
}

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <iostream>
#include <limits>

bool reset_input_error(std::istream &src);
void clean_input_buffer(std::istream &src);

int main(int argc, char **argv)
{
	ros::init(argc, argv, "remote_commander");
	ros::NodeHandle nh;
	
	ros::Publisher pub = nh.advertise<geometry_msgs::Point>("remote_command", 10);
	geometry_msgs::Point msg;
	
	std::cout << "[Info]Hint: x y z\n";
	while (ros::ok()) {
	    // get input
	    std::cout << "[In]";
	    std::cin >> msg.x >> msg.y >> msg.z;
	    
		// reset cin error flag
	    if (std::cin.eof())
	        break;
	        
	    if (reset_input_error(std::cin)) {
	        std::cout << "[Error]Wrong input\n";
	        continue;
	    }
	    clean_input_buffer(std::cin);
	    
	    // publish
	    pub.publish(msg);
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

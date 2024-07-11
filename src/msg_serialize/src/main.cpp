#include <iostream>
#include <std_msgs/Int16.h>
#include <std_msgs/Int16MultiArray.h>
#include <std_msgs/String.h>
#include <geometry_msgs/Point.h>

template<typename T>
void serialize_print(const T& data);

int main()
{
    std_msgs::Int16 msgInt;
    std_msgs::Int16MultiArray msgIntArr;
    std_msgs::String msgStr;
    geometry_msgs::Point msgPoint;

    msgInt.data = 5;
    std::cout << "msgInt:\n" << msgInt;
    serialize_print(msgInt);
    std::cout << '\n';

    msgIntArr.data.push_back(2);
    msgIntArr.data.push_back(4);
    msgIntArr.data.push_back(6);
    std::cout << "msgIntArr:\n" << msgIntArr;
    serialize_print(msgIntArr);
    std::cout << '\n';

    msgPoint.x = 1.0;
    msgPoint.y = 2.0;
    msgPoint.z = 0.0;
    std::cout << "msgPoint:\n" << msgPoint;
    serialize_print(msgPoint);
    std::cout << '\n';

    msgStr.data = "Hello";
    std::cout << "msgStr:\n" << msgStr;
    serialize_print(msgStr);
    std::cout << '\n';

}

template<typename T>
void serialize_print(const T& data)
{
    std::cout << "Size: " << sizeof(data) << '\n';
    std::cout << "Bytes: ";

    unsigned char *ptr = (unsigned char*)&data;

    std::cout.fill('0');
    // Bytes iteration, heximal number display
    for (size_t i=0; i<sizeof(data); i++) {
        std::cout.width(2);  // 2 hex digits are equal to 1 byte
        std::cout << std::hex << +(*(ptr + i)) << ' ';  // implicit conversion by integer promotion(+a)
    }
    std::cout << '\n';

    std::cout << std::dec;  // reset number display format
    std::cout.fill(' ');  // reset fill character
}

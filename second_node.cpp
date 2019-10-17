#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>
void onRecieve(const std_msgs::Int32& number)
{
    std::cout << "/subscriber: data: " << number.data << "\n";
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "subscriber");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("/topic", 1000, onRecieve);
    ros::spin();
}
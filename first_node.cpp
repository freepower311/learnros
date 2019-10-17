#include <ros/ros.h>
#include <std_msgs/Int32.h>
#include <iostream>

int main(int argc, char **argv)
{
    ros::init(argc, argv, "node");
    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<std_msgs::Int32>("/topic", 1000);
    ros::Rate loop_rate(20);
    int a;
    while(std::cin >> a)
    {
        std_msgs::Int32 msg;
        msg.data = a;
        ROS_INFO("pub%d", a);
        pub.publish(msg);
        loop_rate.sleep();
    }
}
#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <visualization_msgs/Marker.h>
ros::Publisher *pub = 0;

void onRecieve(const geometry_msgs::Point& point)
{
    visualization_msgs::Marker msg;
    msg.header.frame_id = "/point_on_map";
    msg.header.stamp = ros::Time::now();
    msg.ns = "there_is_point";
    static int ids = 0;
    msg.id = ids++;
    msg.action = visualization_msgs::Marker::ADD;
    msg.type = visualization_msgs::Marker::POINTS;
    msg.scale.x = 0.5;
    msg.scale.y = 0.5;
    msg.color.r = 1.0;
    msg.color.g = 0.0;
    msg.color.b = 0.0;
    msg.color.a = 1.0;
    msg.points.push_back(point);
    pub->publish(msg);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "point_to_marker");
    ros::NodeHandle n;
    pub = new ros::Publisher(n.advertise<visualization_msgs::Marker>("/output", 100));
    ros::Subscriber sub = n.subscribe("/input", 1000, onRecieve);
    ros::spin();
    delete pub;
}
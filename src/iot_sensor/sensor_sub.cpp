#include "ros/ros.h"
#include "my_ros_projects/my_sensor.h"

// Topic messages callback
void chatterCallback(const my_ros_projects::my_sensor::ConstPtr& msg)
{
    ROS_INFO("[sensor sub] I heard: [%d, %s, %f, %f]\n", msg->id,msg->name.c_str(),msg->temp,msg->humidity);
}

int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "sensor_sub_node");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;


    // Subscribe to a given topic, in this case "chatter".
	//chatterCallback: is the name of the callback function that will be executed each time a message is received.
    ros::Subscriber sub = node.subscribe("weather", 1000, chatterCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}
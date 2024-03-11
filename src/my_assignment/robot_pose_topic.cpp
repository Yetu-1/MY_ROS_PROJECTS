#include "ros/ros.h"
#include "turtlesim/Pose.h"

// Topic messages callback
void chatterCallback(const turtlesim::Pose::ConstPtr& msg)
{
    ROS_INFO("[Listener] I heard: [%f]\n", msg->x);
}

int main(int argc, char **argv)
{
    // Initiate a new ROS node named "listener"
	ros::init(argc, argv, "pose_listener_node");
	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle node;


    // Subscribe to a given topic, in this case "chatter".
	//chatterCallback: is the name of the callback function that will be executed each time a message is received.
    ros::Subscriber sub = node.subscribe("/turtle1/pose", 1000, chatterCallback);

    // Enter a loop, pumping callbacks
    ros::spin();

    return 0;
}

/*Create a subscriber for the topic that will show the location of the robot*/

/*Create a publisher to the topic that will make the robot move*/

/*What is the topic of the position: /turtle1/pose */

/*What is the topic that will make the robot move: /turtle1/cmd_vel */
/*
 * Author: Anis Koubaa for Gaitech EDU
 * Year: 2016
 *
 */


#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "turtlesim/Pose"
#include <sstream>

int main(int argc, char **argv)
{
	// Initiate new ROS node named "talker"
	ros::init(argc, argv, "controller_node");

	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle n;
	//create a publisher with a topic "chatter" that will send a String message
	ros::Publisher speed_publisher = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
	//Rate is a class the is used to define frequency for a loop. Here we send a message each two seconds.
	ros::Rate loop_rate(1); //1 message per second

   int count = 0;
   while (ros::ok()) // Keep spinning loop until user presses Ctrl+C
   {
       //create a new String ROS message.
	   //Message definition in this link http://docs.ros.org/api/std_msgs/html/msg/String.html
	   geometry_msgs::Twist msg;
      // testing changes
       msg.linear.x = 1.0;

    //    //print the content of the message in the terminal
    //    ROS_INFO("[Talker] I published %s\n", msg.data.c_str());

       //Publish the message
       speed_publisher.publish(msg);

       ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages

      loop_rate.sleep(); // Sleep for the rest of the cycle, to enforce the loop rate
       count++;
   }
   return 0;
}


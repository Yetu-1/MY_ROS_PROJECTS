#include "ros/ros.h"
#include "my_ros_projects/my_sensor.h"
#include <sstream>
 
int main(int argc, char **argv)
{
	// Initiate new ROS node named "talker"
	ros::init(argc, argv, "sensor_pub_node");

	//create a node handle: it is reference assigned to a new node
	ros::NodeHandle n;
	//create a publisher with a topic "chatter" that will send a String message
	ros::Publisher sensor_publisher = n.advertise<my_ros_projects::my_sensor>("weather", 1000);
	//Rate is a class the is used to define frequency for a loop. Here we send a message each two seconds.
	ros::Rate loop_rate(1); //2 message per second

   int count = 0;
   while (ros::ok()) // Keep spinning loop until user presses Ctrl+C
   {
       //create a new String ROS message.
	   //Message definition in this link http://docs.ros.org/api/std_msgs/html/msg/String.html
	   my_ros_projects::my_sensor msg;

       //create a string for the data
       msg.id = 123;
       msg.name = "yetu's sensor";
       msg.temp = 32.7;
       msg.humidity = 57.6;

       //print the content of the message in the terminal
       ROS_INFO("[sensor pub] I published [%d, %s, %f, %f]\n", msg.id,msg.name.c_str(),msg.temp,msg.humidity);

       //Publish the message
       sensor_publisher.publish(msg);

       ros::spinOnce(); // Need to call this function often to allow ROS to process incoming messages

      loop_rate.sleep(); // Sleep for the rest of the cycle, to enforce the loop rate
       count++;
   }
   return 0;
}



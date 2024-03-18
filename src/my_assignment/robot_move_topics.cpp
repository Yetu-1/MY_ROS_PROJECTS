
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
#include "turtlesim/Pose.h"
#include <sstream>
#include <math.h>

// global variables for publisher(vel) and subscriber(Pose)
ros::Publisher velocity_pub;
ros::Subscriber position_sub;
int x , y;
void move(double speed, double distance, bool isForward);

void chatterCallback(const turtlesim::Pose::ConstPtr& msg) {
   x = msg->x;
   y = msg->y;
}

int main(int argc, char **argv)
{
	// Initiate new ROS node
	ros::init(argc, argv, "robot_node");

	ros::NodeHandle n;

	velocity_pub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1000);
   //position_sub = n.subscribe("/turtle1/pose", 1000, chatterCallback);
   ros::Rate loop_rate(0.5);
   int count = 0;

   move(2, 4, false);

   ros::spin();

   return 0;
}


void move(double speed, double distance, bool isForward) {
   double distanceMoved = 0.0;

   geometry_msgs::Twist msg;
   if(isForward)
      msg.linear.x = abs(speed);
   else 
      msg.linear.x = -abs(speed);


   ros::Rate loop_rate(10); //1 message per second
	double t0 = ros::Time::now().toSec();
   ROS_INFO("begin");
   do{
      velocity_pub.publish(msg);

      double t = ros::Time::now().toSec();
      distanceMoved = speed * (t - t0);
      
      ros::spinOnce();
      loop_rate.sleep();


   }while(distanceMoved < distance);
   ROS_INFO("done");
   msg.linear.x = 0;
   velocity_pub.publish(msg);
}
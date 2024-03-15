#include "ros/ros.h"
#include "my_ros_projects/summer.h"

bool add(my_ros_projects::summer::Request  &req,
         my_ros_projects::summer::Response &res)
{
  res.sum = req.num1 + req.num2;
  ROS_INFO("request: x=%ld, y=%ld", (long int)req.num1, (long int)req.num2);
  ROS_INFO("sending back response: [%ld]", (long int)res.sum);
  return true;
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "summer_server");
  ros::NodeHandle n;

  ros::ServiceServer service = n.advertiseService("my_summer", add);
  ROS_INFO("Ready to add two ints.");
  ros::spin();

  return 0;
}
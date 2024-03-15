#include "ros/ros.h"
#include "my_ros_projects/summer.h"
#include <cstdlib>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "summer_client");
  if (argc != 3)
  {
    ROS_INFO("usage: add_two_ints_client X Y");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<my_ros_projects::summer>("my_summer");
  my_ros_projects::summer srv;
  srv.request.num1 = atoll(argv[1]);
  srv.request.num2 = atoll(argv[2]);
  if (client.call(srv))
  {
    ROS_INFO("Sum: %ld", (long int)srv.response.sum);
  }
  else
  {
    ROS_ERROR("Failed to call service add_two_ints");
    return 1;
  }

  return 0;
}
#include <ros/ros.h>
// #include "ros_package_template/RosPackageTemplate.hpp"
#include "ros_package_template/gener_alldata_node.hpp"
#include <eigen3/Eigen/Core>


int main(int argc, char** argv)
{
  ros::init(argc, argv, "gener_alldata_node");
  ros::NodeHandle nodeHandle("~");

  // ros_package_template::RosPackageTemplate rosPackageTemplate(nodeHandle);

  ros::spin();
  return 0;
}

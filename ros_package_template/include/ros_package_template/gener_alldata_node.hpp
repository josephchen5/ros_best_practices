#pragma once

#include "ros_package_template/param.hpp"

// ROS
#include <ros/ros.h>
#include <sensor_msgs/Temperature.h>
#include <std_srvs/Trigger.h>

namespace gener_alldata_node {

/*!
 * Main class for the node to handle the ROS interfacing.
 */
class Gener_Alldata_Node
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  Gener_Alldata_Node(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~Gener_Alldata_Node();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallback(const sensor_msgs::Temperature& message);

  /*!
   * ROS service server callback.
   * @param request the request of the service.
   * @param response the provided response.
   * @return true if successful, false otherwise.
   */
  bool serviceCallback(std_srvs::Trigger::Request& request,
                       std_srvs::Trigger::Response& response);

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber.
  ros::Subscriber subscriber_;

  //! ROS topic name to subscribe to.
  std::string subscriberTopic_;

  //! ROS service server.
  ros::ServiceServer serviceServer_;

  //! Algorithm computation object.

  Param param_;
};

} /* namespace */

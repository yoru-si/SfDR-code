// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xrf2_msgs:msg/Xeno2Ros.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__XENO2_ROS__BUILDER_HPP_
#define XRF2_MSGS__MSG__DETAIL__XENO2_ROS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xrf2_msgs/msg/detail/xeno2_ros__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xrf2_msgs
{

namespace msg
{

namespace builder
{

class Init_Xeno2Ros_steer_right
{
public:
  explicit Init_Xeno2Ros_steer_right(::xrf2_msgs::msg::Xeno2Ros & msg)
  : msg_(msg)
  {}
  ::xrf2_msgs::msg::Xeno2Ros steer_right(::xrf2_msgs::msg::Xeno2Ros::_steer_right_type arg)
  {
    msg_.steer_right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xrf2_msgs::msg::Xeno2Ros msg_;
};

class Init_Xeno2Ros_steer_left
{
public:
  Init_Xeno2Ros_steer_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Xeno2Ros_steer_right steer_left(::xrf2_msgs::msg::Xeno2Ros::_steer_left_type arg)
  {
    msg_.steer_left = std::move(arg);
    return Init_Xeno2Ros_steer_right(msg_);
  }

private:
  ::xrf2_msgs::msg::Xeno2Ros msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xrf2_msgs::msg::Xeno2Ros>()
{
  return xrf2_msgs::msg::builder::Init_Xeno2Ros_steer_left();
}

}  // namespace xrf2_msgs

#endif  // XRF2_MSGS__MSG__DETAIL__XENO2_ROS__BUILDER_HPP_

// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__BUILDER_HPP_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "xrf2_msgs/msg/detail/ros2_xeno__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace xrf2_msgs
{

namespace msg
{

namespace builder
{

class Init_Ros2Xeno_set_pos_right
{
public:
  explicit Init_Ros2Xeno_set_pos_right(::xrf2_msgs::msg::Ros2Xeno & msg)
  : msg_(msg)
  {}
  ::xrf2_msgs::msg::Ros2Xeno set_pos_right(::xrf2_msgs::msg::Ros2Xeno::_set_pos_right_type arg)
  {
    msg_.set_pos_right = std::move(arg);
    return std::move(msg_);
  }

private:
  ::xrf2_msgs::msg::Ros2Xeno msg_;
};

class Init_Ros2Xeno_set_pos_left
{
public:
  explicit Init_Ros2Xeno_set_pos_left(::xrf2_msgs::msg::Ros2Xeno & msg)
  : msg_(msg)
  {}
  Init_Ros2Xeno_set_pos_right set_pos_left(::xrf2_msgs::msg::Ros2Xeno::_set_pos_left_type arg)
  {
    msg_.set_pos_left = std::move(arg);
    return Init_Ros2Xeno_set_pos_right(msg_);
  }

private:
  ::xrf2_msgs::msg::Ros2Xeno msg_;
};

class Init_Ros2Xeno_pos_right
{
public:
  explicit Init_Ros2Xeno_pos_right(::xrf2_msgs::msg::Ros2Xeno & msg)
  : msg_(msg)
  {}
  Init_Ros2Xeno_set_pos_left pos_right(::xrf2_msgs::msg::Ros2Xeno::_pos_right_type arg)
  {
    msg_.pos_right = std::move(arg);
    return Init_Ros2Xeno_set_pos_left(msg_);
  }

private:
  ::xrf2_msgs::msg::Ros2Xeno msg_;
};

class Init_Ros2Xeno_pos_left
{
public:
  Init_Ros2Xeno_pos_left()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Ros2Xeno_pos_right pos_left(::xrf2_msgs::msg::Ros2Xeno::_pos_left_type arg)
  {
    msg_.pos_left = std::move(arg);
    return Init_Ros2Xeno_pos_right(msg_);
  }

private:
  ::xrf2_msgs::msg::Ros2Xeno msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::xrf2_msgs::msg::Ros2Xeno>()
{
  return xrf2_msgs::msg::builder::Init_Ros2Xeno_pos_left();
}

}  // namespace xrf2_msgs

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__BUILDER_HPP_

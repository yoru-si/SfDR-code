// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from xrf2_msgs:msg/Ros2Xeno.idl
// generated code does not contain a copyright notice

#ifndef XRF2_MSGS__MSG__DETAIL__ROS2_XENO__TRAITS_HPP_
#define XRF2_MSGS__MSG__DETAIL__ROS2_XENO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "xrf2_msgs/msg/detail/ros2_xeno__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace xrf2_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const Ros2Xeno & msg,
  std::ostream & out)
{
  out << "{";
  // member: pos_left
  {
    out << "pos_left: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_left, out);
    out << ", ";
  }

  // member: pos_right
  {
    out << "pos_right: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_right, out);
    out << ", ";
  }

  // member: set_pos_left
  {
    out << "set_pos_left: ";
    rosidl_generator_traits::value_to_yaml(msg.set_pos_left, out);
    out << ", ";
  }

  // member: set_pos_right
  {
    out << "set_pos_right: ";
    rosidl_generator_traits::value_to_yaml(msg.set_pos_right, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Ros2Xeno & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: pos_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_left: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_left, out);
    out << "\n";
  }

  // member: pos_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "pos_right: ";
    rosidl_generator_traits::value_to_yaml(msg.pos_right, out);
    out << "\n";
  }

  // member: set_pos_left
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_pos_left: ";
    rosidl_generator_traits::value_to_yaml(msg.set_pos_left, out);
    out << "\n";
  }

  // member: set_pos_right
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "set_pos_right: ";
    rosidl_generator_traits::value_to_yaml(msg.set_pos_right, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Ros2Xeno & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace xrf2_msgs

namespace rosidl_generator_traits
{

[[deprecated("use xrf2_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const xrf2_msgs::msg::Ros2Xeno & msg,
  std::ostream & out, size_t indentation = 0)
{
  xrf2_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use xrf2_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const xrf2_msgs::msg::Ros2Xeno & msg)
{
  return xrf2_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<xrf2_msgs::msg::Ros2Xeno>()
{
  return "xrf2_msgs::msg::Ros2Xeno";
}

template<>
inline const char * name<xrf2_msgs::msg::Ros2Xeno>()
{
  return "xrf2_msgs/msg/Ros2Xeno";
}

template<>
struct has_fixed_size<xrf2_msgs::msg::Ros2Xeno>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<xrf2_msgs::msg::Ros2Xeno>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<xrf2_msgs::msg::Ros2Xeno>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // XRF2_MSGS__MSG__DETAIL__ROS2_XENO__TRAITS_HPP_

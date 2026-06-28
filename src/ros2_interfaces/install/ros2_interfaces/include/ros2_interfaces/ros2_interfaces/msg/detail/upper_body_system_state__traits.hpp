// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__TRAITS_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace ros2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const UpperBodySystemState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: state
  {
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << ", ";
  }

  // member: run_mode
  {
    out << "run_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.run_mode, out);
    out << ", ";
  }

  // member: ready_motor_count
  {
    out << "ready_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.ready_motor_count, out);
    out << ", ";
  }

  // member: enabled_motor_count
  {
    out << "enabled_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.enabled_motor_count, out);
    out << ", ";
  }

  // member: fault_motor_count
  {
    out << "fault_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_motor_count, out);
    out << ", ";
  }

  // member: is_connected
  {
    if (msg.is_connected.size() == 0) {
      out << "is_connected: []";
    } else {
      out << "is_connected: [";
      size_t pending_items = msg.is_connected.size();
      for (auto item : msg.is_connected) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: all_motors_enabled
  {
    out << "all_motors_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.all_motors_enabled, out);
    out << ", ";
  }

  // member: command_accepted
  {
    out << "command_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.command_accepted, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const UpperBodySystemState & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: state
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "state: ";
    rosidl_generator_traits::value_to_yaml(msg.state, out);
    out << "\n";
  }

  // member: run_mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "run_mode: ";
    rosidl_generator_traits::value_to_yaml(msg.run_mode, out);
    out << "\n";
  }

  // member: ready_motor_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ready_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.ready_motor_count, out);
    out << "\n";
  }

  // member: enabled_motor_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enabled_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.enabled_motor_count, out);
    out << "\n";
  }

  // member: fault_motor_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fault_motor_count: ";
    rosidl_generator_traits::value_to_yaml(msg.fault_motor_count, out);
    out << "\n";
  }

  // member: is_connected
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.is_connected.size() == 0) {
      out << "is_connected: []\n";
    } else {
      out << "is_connected:\n";
      for (auto item : msg.is_connected) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: all_motors_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "all_motors_enabled: ";
    rosidl_generator_traits::value_to_yaml(msg.all_motors_enabled, out);
    out << "\n";
  }

  // member: command_accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "command_accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.command_accepted, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const UpperBodySystemState & msg, bool use_flow_style = false)
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

}  // namespace ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros2_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_interfaces::msg::UpperBodySystemState & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::msg::UpperBodySystemState & msg)
{
  return ros2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::msg::UpperBodySystemState>()
{
  return "ros2_interfaces::msg::UpperBodySystemState";
}

template<>
inline const char * name<ros2_interfaces::msg::UpperBodySystemState>()
{
  return "ros2_interfaces/msg/UpperBodySystemState";
}

template<>
struct has_fixed_size<ros2_interfaces::msg::UpperBodySystemState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ros2_interfaces::msg::UpperBodySystemState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ros2_interfaces::msg::UpperBodySystemState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__TRAITS_HPP_

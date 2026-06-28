// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:srv/SimpleMotorResult.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__TRAITS_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interfaces/srv/detail/simple_motor_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SimpleMotorResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: motor_id_list
  {
    if (msg.motor_id_list.size() == 0) {
      out << "motor_id_list: []";
    } else {
      out << "motor_id_list: [";
      size_t pending_items = msg.motor_id_list.size();
      for (auto item : msg.motor_id_list) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SimpleMotorResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: motor_id_list
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_id_list.size() == 0) {
      out << "motor_id_list: []\n";
    } else {
      out << "motor_id_list:\n";
      for (auto item : msg.motor_id_list) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SimpleMotorResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_interfaces::srv::SimpleMotorResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::SimpleMotorResult_Request & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::SimpleMotorResult_Request>()
{
  return "ros2_interfaces::srv::SimpleMotorResult_Request";
}

template<>
inline const char * name<ros2_interfaces::srv::SimpleMotorResult_Request>()
{
  return "ros2_interfaces/srv/SimpleMotorResult_Request";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SimpleMotorResult_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::SimpleMotorResult_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::SimpleMotorResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SimpleMotorResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SimpleMotorResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SimpleMotorResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace ros2_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use ros2_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ros2_interfaces::srv::SimpleMotorResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::SimpleMotorResult_Response & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::SimpleMotorResult_Response>()
{
  return "ros2_interfaces::srv::SimpleMotorResult_Response";
}

template<>
inline const char * name<ros2_interfaces::srv::SimpleMotorResult_Response>()
{
  return "ros2_interfaces/srv/SimpleMotorResult_Response";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SimpleMotorResult_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::SimpleMotorResult_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::SimpleMotorResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_interfaces::srv::SimpleMotorResult>()
{
  return "ros2_interfaces::srv::SimpleMotorResult";
}

template<>
inline const char * name<ros2_interfaces::srv::SimpleMotorResult>()
{
  return "ros2_interfaces/srv/SimpleMotorResult";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SimpleMotorResult>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_interfaces::srv::SimpleMotorResult_Request>::value &&
    has_fixed_size<ros2_interfaces::srv::SimpleMotorResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_interfaces::srv::SimpleMotorResult>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_interfaces::srv::SimpleMotorResult_Request>::value &&
    has_bounded_size<ros2_interfaces::srv::SimpleMotorResult_Response>::value
  >
{
};

template<>
struct is_service<ros2_interfaces::srv::SimpleMotorResult>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_interfaces::srv::SimpleMotorResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_interfaces::srv::SimpleMotorResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__SRV__DETAIL__SIMPLE_MOTOR_RESULT__TRAITS_HPP_

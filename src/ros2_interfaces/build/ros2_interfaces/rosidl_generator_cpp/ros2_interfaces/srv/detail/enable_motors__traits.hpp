// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:srv/EnableMotors.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__TRAITS_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interfaces/srv/detail/enable_motors__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const EnableMotors_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: enable_all
  {
    out << "enable_all: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_all, out);
    out << ", ";
  }

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
  const EnableMotors_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: enable_all
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "enable_all: ";
    rosidl_generator_traits::value_to_yaml(msg.enable_all, out);
    out << "\n";
  }

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

inline std::string to_yaml(const EnableMotors_Request & msg, bool use_flow_style = false)
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
  const ros2_interfaces::srv::EnableMotors_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::EnableMotors_Request & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::EnableMotors_Request>()
{
  return "ros2_interfaces::srv::EnableMotors_Request";
}

template<>
inline const char * name<ros2_interfaces::srv::EnableMotors_Request>()
{
  return "ros2_interfaces/srv/EnableMotors_Request";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::EnableMotors_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::EnableMotors_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::EnableMotors_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const EnableMotors_Response & msg,
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
    out << ", ";
  }

  // member: enabled_motor_ids
  {
    if (msg.enabled_motor_ids.size() == 0) {
      out << "enabled_motor_ids: []";
    } else {
      out << "enabled_motor_ids: [";
      size_t pending_items = msg.enabled_motor_ids.size();
      for (auto item : msg.enabled_motor_ids) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: failed_motor_ids
  {
    if (msg.failed_motor_ids.size() == 0) {
      out << "failed_motor_ids: []";
    } else {
      out << "failed_motor_ids: [";
      size_t pending_items = msg.failed_motor_ids.size();
      for (auto item : msg.failed_motor_ids) {
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
  const EnableMotors_Response & msg,
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

  // member: enabled_motor_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.enabled_motor_ids.size() == 0) {
      out << "enabled_motor_ids: []\n";
    } else {
      out << "enabled_motor_ids:\n";
      for (auto item : msg.enabled_motor_ids) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: failed_motor_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.failed_motor_ids.size() == 0) {
      out << "failed_motor_ids: []\n";
    } else {
      out << "failed_motor_ids:\n";
      for (auto item : msg.failed_motor_ids) {
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

inline std::string to_yaml(const EnableMotors_Response & msg, bool use_flow_style = false)
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
  const ros2_interfaces::srv::EnableMotors_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::EnableMotors_Response & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::EnableMotors_Response>()
{
  return "ros2_interfaces::srv::EnableMotors_Response";
}

template<>
inline const char * name<ros2_interfaces::srv::EnableMotors_Response>()
{
  return "ros2_interfaces/srv/EnableMotors_Response";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::EnableMotors_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::EnableMotors_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::EnableMotors_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_interfaces::srv::EnableMotors>()
{
  return "ros2_interfaces::srv::EnableMotors";
}

template<>
inline const char * name<ros2_interfaces::srv::EnableMotors>()
{
  return "ros2_interfaces/srv/EnableMotors";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::EnableMotors>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_interfaces::srv::EnableMotors_Request>::value &&
    has_fixed_size<ros2_interfaces::srv::EnableMotors_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_interfaces::srv::EnableMotors>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_interfaces::srv::EnableMotors_Request>::value &&
    has_bounded_size<ros2_interfaces::srv::EnableMotors_Response>::value
  >
{
};

template<>
struct is_service<ros2_interfaces::srv::EnableMotors>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_interfaces::srv::EnableMotors_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_interfaces::srv::EnableMotors_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__TRAITS_HPP_

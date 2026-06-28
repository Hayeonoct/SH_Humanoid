// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:srv/SetRunMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_interfaces/srv/set_run_mode.hpp"


#ifndef ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__TRAITS_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interfaces/srv/detail/set_run_mode__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetRunMode_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
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
  const SetRunMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
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

inline std::string to_yaml(const SetRunMode_Request & msg, bool use_flow_style = false)
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
  const ros2_interfaces::srv::SetRunMode_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::SetRunMode_Request & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::SetRunMode_Request>()
{
  return "ros2_interfaces::srv::SetRunMode_Request";
}

template<>
inline const char * name<ros2_interfaces::srv::SetRunMode_Request>()
{
  return "ros2_interfaces/srv/SetRunMode_Request";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SetRunMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::SetRunMode_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::SetRunMode_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetRunMode_Response & msg,
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

  // member: applied_motor_ids
  {
    if (msg.applied_motor_ids.size() == 0) {
      out << "applied_motor_ids: []";
    } else {
      out << "applied_motor_ids: [";
      size_t pending_items = msg.applied_motor_ids.size();
      for (auto item : msg.applied_motor_ids) {
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
  const SetRunMode_Response & msg,
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

  // member: applied_motor_ids
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.applied_motor_ids.size() == 0) {
      out << "applied_motor_ids: []\n";
    } else {
      out << "applied_motor_ids:\n";
      for (auto item : msg.applied_motor_ids) {
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

inline std::string to_yaml(const SetRunMode_Response & msg, bool use_flow_style = false)
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
  const ros2_interfaces::srv::SetRunMode_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::SetRunMode_Response & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::SetRunMode_Response>()
{
  return "ros2_interfaces::srv::SetRunMode_Response";
}

template<>
inline const char * name<ros2_interfaces::srv::SetRunMode_Response>()
{
  return "ros2_interfaces/srv/SetRunMode_Response";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SetRunMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::SetRunMode_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<ros2_interfaces::srv::SetRunMode_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__traits.hpp"

namespace ros2_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetRunMode_Event & msg,
  std::ostream & out)
{
  out << "{";
  // member: info
  {
    out << "info: ";
    to_flow_style_yaml(msg.info, out);
    out << ", ";
  }

  // member: request
  {
    if (msg.request.size() == 0) {
      out << "request: []";
    } else {
      out << "request: [";
      size_t pending_items = msg.request.size();
      for (auto item : msg.request) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: response
  {
    if (msg.response.size() == 0) {
      out << "response: []";
    } else {
      out << "response: [";
      size_t pending_items = msg.response.size();
      for (auto item : msg.response) {
        to_flow_style_yaml(item, out);
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
  const SetRunMode_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: info
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "info:\n";
    to_block_style_yaml(msg.info, out, indentation + 2);
  }

  // member: request
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.request.size() == 0) {
      out << "request: []\n";
    } else {
      out << "request:\n";
      for (auto item : msg.request) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: response
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.response.size() == 0) {
      out << "response: []\n";
    } else {
      out << "response:\n";
      for (auto item : msg.response) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetRunMode_Event & msg, bool use_flow_style = false)
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
  const ros2_interfaces::srv::SetRunMode_Event & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::srv::SetRunMode_Event & msg)
{
  return ros2_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::srv::SetRunMode_Event>()
{
  return "ros2_interfaces::srv::SetRunMode_Event";
}

template<>
inline const char * name<ros2_interfaces::srv::SetRunMode_Event>()
{
  return "ros2_interfaces/srv/SetRunMode_Event";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SetRunMode_Event>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<ros2_interfaces::srv::SetRunMode_Event>
  : std::integral_constant<bool, has_bounded_size<ros2_interfaces::srv::SetRunMode_Request>::value && has_bounded_size<ros2_interfaces::srv::SetRunMode_Response>::value && has_bounded_size<service_msgs::msg::ServiceEventInfo>::value> {};

template<>
struct is_message<ros2_interfaces::srv::SetRunMode_Event>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<ros2_interfaces::srv::SetRunMode>()
{
  return "ros2_interfaces::srv::SetRunMode";
}

template<>
inline const char * name<ros2_interfaces::srv::SetRunMode>()
{
  return "ros2_interfaces/srv/SetRunMode";
}

template<>
struct has_fixed_size<ros2_interfaces::srv::SetRunMode>
  : std::integral_constant<
    bool,
    has_fixed_size<ros2_interfaces::srv::SetRunMode_Request>::value &&
    has_fixed_size<ros2_interfaces::srv::SetRunMode_Response>::value
  >
{
};

template<>
struct has_bounded_size<ros2_interfaces::srv::SetRunMode>
  : std::integral_constant<
    bool,
    has_bounded_size<ros2_interfaces::srv::SetRunMode_Request>::value &&
    has_bounded_size<ros2_interfaces::srv::SetRunMode_Response>::value
  >
{
};

template<>
struct is_service<ros2_interfaces::srv::SetRunMode>
  : std::true_type
{
};

template<>
struct is_service_request<ros2_interfaces::srv::SetRunMode_Request>
  : std::true_type
{
};

template<>
struct is_service_response<ros2_interfaces::srv::SetRunMode_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__TRAITS_HPP_

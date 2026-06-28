// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__TRAITS_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ros2_interfaces/msg/detail/upper_motor_state__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace ros2_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const UpperMotorState & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: is_ready
  {
    if (msg.is_ready.size() == 0) {
      out << "is_ready: []";
    } else {
      out << "is_ready: [";
      size_t pending_items = msg.is_ready.size();
      for (auto item : msg.is_ready) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: is_enabled
  {
    if (msg.is_enabled.size() == 0) {
      out << "is_enabled: []";
    } else {
      out << "is_enabled: [";
      size_t pending_items = msg.is_enabled.size();
      for (auto item : msg.is_enabled) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: has_fault
  {
    if (msg.has_fault.size() == 0) {
      out << "has_fault: []";
    } else {
      out << "has_fault: [";
      size_t pending_items = msg.has_fault.size();
      for (auto item : msg.has_fault) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: motor_id
  {
    if (msg.motor_id.size() == 0) {
      out << "motor_id: []";
    } else {
      out << "motor_id: [";
      size_t pending_items = msg.motor_id.size();
      for (auto item : msg.motor_id) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: position
  {
    if (msg.position.size() == 0) {
      out << "position: []";
    } else {
      out << "position: [";
      size_t pending_items = msg.position.size();
      for (auto item : msg.position) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: velocity
  {
    if (msg.velocity.size() == 0) {
      out << "velocity: []";
    } else {
      out << "velocity: [";
      size_t pending_items = msg.velocity.size();
      for (auto item : msg.velocity) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: effort
  {
    if (msg.effort.size() == 0) {
      out << "effort: []";
    } else {
      out << "effort: [";
      size_t pending_items = msg.effort.size();
      for (auto item : msg.effort) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: error_code
  {
    if (msg.error_code.size() == 0) {
      out << "error_code: []";
    } else {
      out << "error_code: [";
      size_t pending_items = msg.error_code.size();
      for (auto item : msg.error_code) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: temperature
  {
    if (msg.temperature.size() == 0) {
      out << "temperature: []";
    } else {
      out << "temperature: [";
      size_t pending_items = msg.temperature.size();
      for (auto item : msg.temperature) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: voltage
  {
    if (msg.voltage.size() == 0) {
      out << "voltage: []";
    } else {
      out << "voltage: [";
      size_t pending_items = msg.voltage.size();
      for (auto item : msg.voltage) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: current
  {
    if (msg.current.size() == 0) {
      out << "current: []";
    } else {
      out << "current: [";
      size_t pending_items = msg.current.size();
      for (auto item : msg.current) {
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
  const UpperMotorState & msg,
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

  // member: is_ready
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.is_ready.size() == 0) {
      out << "is_ready: []\n";
    } else {
      out << "is_ready:\n";
      for (auto item : msg.is_ready) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: is_enabled
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.is_enabled.size() == 0) {
      out << "is_enabled: []\n";
    } else {
      out << "is_enabled:\n";
      for (auto item : msg.is_enabled) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: has_fault
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.has_fault.size() == 0) {
      out << "has_fault: []\n";
    } else {
      out << "has_fault:\n";
      for (auto item : msg.has_fault) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: motor_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.motor_id.size() == 0) {
      out << "motor_id: []\n";
    } else {
      out << "motor_id:\n";
      for (auto item : msg.motor_id) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.position.size() == 0) {
      out << "position: []\n";
    } else {
      out << "position:\n";
      for (auto item : msg.position) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: velocity
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.velocity.size() == 0) {
      out << "velocity: []\n";
    } else {
      out << "velocity:\n";
      for (auto item : msg.velocity) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: effort
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.effort.size() == 0) {
      out << "effort: []\n";
    } else {
      out << "effort:\n";
      for (auto item : msg.effort) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: error_code
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.error_code.size() == 0) {
      out << "error_code: []\n";
    } else {
      out << "error_code:\n";
      for (auto item : msg.error_code) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: temperature
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.temperature.size() == 0) {
      out << "temperature: []\n";
    } else {
      out << "temperature:\n";
      for (auto item : msg.temperature) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: voltage
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.voltage.size() == 0) {
      out << "voltage: []\n";
    } else {
      out << "voltage:\n";
      for (auto item : msg.voltage) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: current
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.current.size() == 0) {
      out << "current: []\n";
    } else {
      out << "current:\n";
      for (auto item : msg.current) {
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

inline std::string to_yaml(const UpperMotorState & msg, bool use_flow_style = false)
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
  const ros2_interfaces::msg::UpperMotorState & msg,
  std::ostream & out, size_t indentation = 0)
{
  ros2_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ros2_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const ros2_interfaces::msg::UpperMotorState & msg)
{
  return ros2_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ros2_interfaces::msg::UpperMotorState>()
{
  return "ros2_interfaces::msg::UpperMotorState";
}

template<>
inline const char * name<ros2_interfaces::msg::UpperMotorState>()
{
  return "ros2_interfaces/msg/UpperMotorState";
}

template<>
struct has_fixed_size<ros2_interfaces::msg::UpperMotorState>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ros2_interfaces::msg::UpperMotorState>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ros2_interfaces::msg::UpperMotorState>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__TRAITS_HPP_

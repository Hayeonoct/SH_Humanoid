// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_motor_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_interfaces/msg/detail/upper_motor_state__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace ros2_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
cdr_serialize(
  const ros2_interfaces::msg::UpperMotorState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: is_ready
  {
    cdr << ros_message.is_ready;
  }
  // Member: is_enabled
  {
    cdr << ros_message.is_enabled;
  }
  // Member: has_fault
  {
    cdr << ros_message.has_fault;
  }
  // Member: motor_id
  {
    cdr << ros_message.motor_id;
  }
  // Member: position
  {
    cdr << ros_message.position;
  }
  // Member: velocity
  {
    cdr << ros_message.velocity;
  }
  // Member: effort
  {
    cdr << ros_message.effort;
  }
  // Member: error_code
  {
    cdr << ros_message.error_code;
  }
  // Member: temperature
  {
    cdr << ros_message.temperature;
  }
  // Member: voltage
  {
    cdr << ros_message.voltage;
  }
  // Member: current
  {
    cdr << ros_message.current;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_interfaces::msg::UpperMotorState & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: is_ready
  {
    cdr >> ros_message.is_ready;
  }

  // Member: is_enabled
  {
    cdr >> ros_message.is_enabled;
  }

  // Member: has_fault
  {
    cdr >> ros_message.has_fault;
  }

  // Member: motor_id
  {
    cdr >> ros_message.motor_id;
  }

  // Member: position
  {
    cdr >> ros_message.position;
  }

  // Member: velocity
  {
    cdr >> ros_message.velocity;
  }

  // Member: effort
  {
    cdr >> ros_message.effort;
  }

  // Member: error_code
  {
    cdr >> ros_message.error_code;
  }

  // Member: temperature
  {
    cdr >> ros_message.temperature;
  }

  // Member: voltage
  {
    cdr >> ros_message.voltage;
  }

  // Member: current
  {
    cdr >> ros_message.current;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
get_serialized_size(
  const ros2_interfaces::msg::UpperMotorState & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: is_ready
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.is_ready[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_enabled
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.is_enabled[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: has_fault
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.has_fault[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: motor_id
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.motor_id[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: position
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.position[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: velocity
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.velocity[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: effort
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.effort[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: error_code
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.error_code[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: temperature
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.temperature[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: voltage
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.voltage[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: current
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.current[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
max_serialized_size_UpperMotorState(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        inner_full_bounded, inner_is_plain, current_alignment);
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Member: is_ready
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_enabled
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: has_fault
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: motor_id
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: position
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: velocity
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: effort
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: error_code
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint16_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint16_t));
  }

  // Member: temperature
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: voltage
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: current
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _UpperMotorState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::UpperMotorState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UpperMotorState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_interfaces::msg::UpperMotorState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UpperMotorState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::UpperMotorState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UpperMotorState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UpperMotorState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UpperMotorState__callbacks = {
  "ros2_interfaces::msg",
  "UpperMotorState",
  _UpperMotorState__cdr_serialize,
  _UpperMotorState__cdr_deserialize,
  _UpperMotorState__get_serialized_size,
  _UpperMotorState__max_serialized_size
};

static rosidl_message_type_support_t _UpperMotorState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UpperMotorState__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ros2_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ros2_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<ros2_interfaces::msg::UpperMotorState>()
{
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_UpperMotorState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, msg, UpperMotorState)() {
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_UpperMotorState__handle;
}

#ifdef __cplusplus
}
#endif

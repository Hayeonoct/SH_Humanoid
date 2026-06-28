// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_body_system_state__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.hpp"

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
  const ros2_interfaces::msg::UpperBodySystemState & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: state
  cdr << ros_message.state;
  // Member: run_mode
  cdr << ros_message.run_mode;
  // Member: ready_motor_count
  cdr << ros_message.ready_motor_count;
  // Member: enabled_motor_count
  cdr << ros_message.enabled_motor_count;
  // Member: fault_motor_count
  cdr << ros_message.fault_motor_count;
  // Member: is_connected
  {
    cdr << ros_message.is_connected;
  }
  // Member: all_motors_enabled
  cdr << (ros_message.all_motors_enabled ? true : false);
  // Member: command_accepted
  cdr << (ros_message.command_accepted ? true : false);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ros2_interfaces::msg::UpperBodySystemState & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: state
  cdr >> ros_message.state;

  // Member: run_mode
  cdr >> ros_message.run_mode;

  // Member: ready_motor_count
  cdr >> ros_message.ready_motor_count;

  // Member: enabled_motor_count
  cdr >> ros_message.enabled_motor_count;

  // Member: fault_motor_count
  cdr >> ros_message.fault_motor_count;

  // Member: is_connected
  {
    cdr >> ros_message.is_connected;
  }

  // Member: all_motors_enabled
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.all_motors_enabled = tmp ? true : false;
  }

  // Member: command_accepted
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.command_accepted = tmp ? true : false;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
get_serialized_size(
  const ros2_interfaces::msg::UpperBodySystemState & ros_message,
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
  // Member: state
  {
    size_t item_size = sizeof(ros_message.state);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: run_mode
  {
    size_t item_size = sizeof(ros_message.run_mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: ready_motor_count
  {
    size_t item_size = sizeof(ros_message.ready_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: enabled_motor_count
  {
    size_t item_size = sizeof(ros_message.enabled_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: fault_motor_count
  {
    size_t item_size = sizeof(ros_message.fault_motor_count);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: is_connected
  {
    size_t array_size = 15;
    size_t item_size = sizeof(ros_message.is_connected[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: all_motors_enabled
  {
    size_t item_size = sizeof(ros_message.all_motors_enabled);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: command_accepted
  {
    size_t item_size = sizeof(ros_message.command_accepted);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ros2_interfaces
max_serialized_size_UpperBodySystemState(
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

  // Member: state
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: run_mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: ready_motor_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: enabled_motor_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: fault_motor_count
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: is_connected
  {
    size_t array_size = 15;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: all_motors_enabled
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: command_accepted
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _UpperBodySystemState__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::UpperBodySystemState *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _UpperBodySystemState__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ros2_interfaces::msg::UpperBodySystemState *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _UpperBodySystemState__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ros2_interfaces::msg::UpperBodySystemState *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _UpperBodySystemState__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_UpperBodySystemState(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _UpperBodySystemState__callbacks = {
  "ros2_interfaces::msg",
  "UpperBodySystemState",
  _UpperBodySystemState__cdr_serialize,
  _UpperBodySystemState__cdr_deserialize,
  _UpperBodySystemState__get_serialized_size,
  _UpperBodySystemState__max_serialized_size
};

static rosidl_message_type_support_t _UpperBodySystemState__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_UpperBodySystemState__callbacks,
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
get_message_type_support_handle<ros2_interfaces::msg::UpperBodySystemState>()
{
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_UpperBodySystemState__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ros2_interfaces, msg, UpperBodySystemState)() {
  return &ros2_interfaces::msg::typesupport_fastrtps_cpp::_UpperBodySystemState__handle;
}

#ifdef __cplusplus
}
#endif

// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__msg__UpperBodySystemState __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__msg__UpperBodySystemState __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UpperBodySystemState_
{
  using Type = UpperBodySystemState_<ContainerAllocator>;

  explicit UpperBodySystemState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->run_mode = 0;
      this->ready_motor_count = 0;
      this->enabled_motor_count = 0;
      this->fault_motor_count = 0;
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_connected.begin(), this->is_connected.end(), false);
      this->all_motors_enabled = false;
      this->command_accepted = false;
    }
  }

  explicit UpperBodySystemState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    is_connected(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->state = 0;
      this->run_mode = 0;
      this->ready_motor_count = 0;
      this->enabled_motor_count = 0;
      this->fault_motor_count = 0;
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_connected.begin(), this->is_connected.end(), false);
      this->all_motors_enabled = false;
      this->command_accepted = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _state_type =
    uint8_t;
  _state_type state;
  using _run_mode_type =
    uint8_t;
  _run_mode_type run_mode;
  using _ready_motor_count_type =
    uint8_t;
  _ready_motor_count_type ready_motor_count;
  using _enabled_motor_count_type =
    uint8_t;
  _enabled_motor_count_type enabled_motor_count;
  using _fault_motor_count_type =
    uint8_t;
  _fault_motor_count_type fault_motor_count;
  using _is_connected_type =
    std::array<bool, 15>;
  _is_connected_type is_connected;
  using _all_motors_enabled_type =
    bool;
  _all_motors_enabled_type all_motors_enabled;
  using _command_accepted_type =
    bool;
  _command_accepted_type command_accepted;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__state(
    const uint8_t & _arg)
  {
    this->state = _arg;
    return *this;
  }
  Type & set__run_mode(
    const uint8_t & _arg)
  {
    this->run_mode = _arg;
    return *this;
  }
  Type & set__ready_motor_count(
    const uint8_t & _arg)
  {
    this->ready_motor_count = _arg;
    return *this;
  }
  Type & set__enabled_motor_count(
    const uint8_t & _arg)
  {
    this->enabled_motor_count = _arg;
    return *this;
  }
  Type & set__fault_motor_count(
    const uint8_t & _arg)
  {
    this->fault_motor_count = _arg;
    return *this;
  }
  Type & set__is_connected(
    const std::array<bool, 15> & _arg)
  {
    this->is_connected = _arg;
    return *this;
  }
  Type & set__all_motors_enabled(
    const bool & _arg)
  {
    this->all_motors_enabled = _arg;
    return *this;
  }
  Type & set__command_accepted(
    const bool & _arg)
  {
    this->command_accepted = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t POWER_OFF =
    0u;
  static constexpr uint8_t DRIVER_INIT =
    1u;
  static constexpr uint8_t READY =
    2u;
  static constexpr uint8_t ENABLING =
    3u;
  static constexpr uint8_t ENABLED =
    4u;
  static constexpr uint8_t RUNNING =
    5u;
  static constexpr uint8_t FAULT =
    6u;
  static constexpr uint8_t MODE_IDLE =
    0u;
  static constexpr uint8_t MODE_TORQUE =
    1u;
  static constexpr uint8_t MODE_VELOCITY =
    2u;
  static constexpr uint8_t MODE_POSITION =
    3u;
  static constexpr uint8_t MODE_IMPEDANCE =
    4u;

  // pointer types
  using RawPtr =
    ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__msg__UpperBodySystemState
    std::shared_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__msg__UpperBodySystemState
    std::shared_ptr<ros2_interfaces::msg::UpperBodySystemState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpperBodySystemState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->state != other.state) {
      return false;
    }
    if (this->run_mode != other.run_mode) {
      return false;
    }
    if (this->ready_motor_count != other.ready_motor_count) {
      return false;
    }
    if (this->enabled_motor_count != other.enabled_motor_count) {
      return false;
    }
    if (this->fault_motor_count != other.fault_motor_count) {
      return false;
    }
    if (this->is_connected != other.is_connected) {
      return false;
    }
    if (this->all_motors_enabled != other.all_motors_enabled) {
      return false;
    }
    if (this->command_accepted != other.command_accepted) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpperBodySystemState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpperBodySystemState_

// alias to use template instance with default allocator
using UpperBodySystemState =
  ros2_interfaces::msg::UpperBodySystemState_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::POWER_OFF;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::DRIVER_INIT;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::READY;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::ENABLING;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::ENABLED;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::RUNNING;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::FAULT;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::MODE_IDLE;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::MODE_TORQUE;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::MODE_VELOCITY;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::MODE_POSITION;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodySystemState_<ContainerAllocator>::MODE_IMPEDANCE;

}  // namespace msg

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_SYSTEM_STATE__STRUCT_HPP_

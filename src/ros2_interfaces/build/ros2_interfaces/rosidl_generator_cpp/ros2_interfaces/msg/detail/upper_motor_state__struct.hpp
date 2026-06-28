// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_HPP_

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
# define DEPRECATED__ros2_interfaces__msg__UpperMotorState __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__msg__UpperMotorState __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UpperMotorState_
{
  using Type = UpperMotorState_<ContainerAllocator>;

  explicit UpperMotorState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_ready.begin(), this->is_ready.end(), false);
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_enabled.begin(), this->is_enabled.end(), false);
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->has_fault.begin(), this->has_fault.end(), false);
      std::fill<typename std::array<uint16_t, 15>::iterator, uint16_t>(this->motor_id.begin(), this->motor_id.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->effort.begin(), this->effort.end(), 0.0f);
      std::fill<typename std::array<uint16_t, 15>::iterator, uint16_t>(this->error_code.begin(), this->error_code.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->temperature.begin(), this->temperature.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->voltage.begin(), this->voltage.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->current.begin(), this->current.end(), 0.0f);
    }
  }

  explicit UpperMotorState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    is_ready(_alloc),
    is_enabled(_alloc),
    has_fault(_alloc),
    motor_id(_alloc),
    position(_alloc),
    velocity(_alloc),
    effort(_alloc),
    error_code(_alloc),
    temperature(_alloc),
    voltage(_alloc),
    current(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_ready.begin(), this->is_ready.end(), false);
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->is_enabled.begin(), this->is_enabled.end(), false);
      std::fill<typename std::array<bool, 15>::iterator, bool>(this->has_fault.begin(), this->has_fault.end(), false);
      std::fill<typename std::array<uint16_t, 15>::iterator, uint16_t>(this->motor_id.begin(), this->motor_id.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->effort.begin(), this->effort.end(), 0.0f);
      std::fill<typename std::array<uint16_t, 15>::iterator, uint16_t>(this->error_code.begin(), this->error_code.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->temperature.begin(), this->temperature.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->voltage.begin(), this->voltage.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->current.begin(), this->current.end(), 0.0f);
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _is_ready_type =
    std::array<bool, 15>;
  _is_ready_type is_ready;
  using _is_enabled_type =
    std::array<bool, 15>;
  _is_enabled_type is_enabled;
  using _has_fault_type =
    std::array<bool, 15>;
  _has_fault_type has_fault;
  using _motor_id_type =
    std::array<uint16_t, 15>;
  _motor_id_type motor_id;
  using _position_type =
    std::array<float, 15>;
  _position_type position;
  using _velocity_type =
    std::array<float, 15>;
  _velocity_type velocity;
  using _effort_type =
    std::array<float, 15>;
  _effort_type effort;
  using _error_code_type =
    std::array<uint16_t, 15>;
  _error_code_type error_code;
  using _temperature_type =
    std::array<float, 15>;
  _temperature_type temperature;
  using _voltage_type =
    std::array<float, 15>;
  _voltage_type voltage;
  using _current_type =
    std::array<float, 15>;
  _current_type current;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__is_ready(
    const std::array<bool, 15> & _arg)
  {
    this->is_ready = _arg;
    return *this;
  }
  Type & set__is_enabled(
    const std::array<bool, 15> & _arg)
  {
    this->is_enabled = _arg;
    return *this;
  }
  Type & set__has_fault(
    const std::array<bool, 15> & _arg)
  {
    this->has_fault = _arg;
    return *this;
  }
  Type & set__motor_id(
    const std::array<uint16_t, 15> & _arg)
  {
    this->motor_id = _arg;
    return *this;
  }
  Type & set__position(
    const std::array<float, 15> & _arg)
  {
    this->position = _arg;
    return *this;
  }
  Type & set__velocity(
    const std::array<float, 15> & _arg)
  {
    this->velocity = _arg;
    return *this;
  }
  Type & set__effort(
    const std::array<float, 15> & _arg)
  {
    this->effort = _arg;
    return *this;
  }
  Type & set__error_code(
    const std::array<uint16_t, 15> & _arg)
  {
    this->error_code = _arg;
    return *this;
  }
  Type & set__temperature(
    const std::array<float, 15> & _arg)
  {
    this->temperature = _arg;
    return *this;
  }
  Type & set__voltage(
    const std::array<float, 15> & _arg)
  {
    this->voltage = _arg;
    return *this;
  }
  Type & set__current(
    const std::array<float, 15> & _arg)
  {
    this->current = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__msg__UpperMotorState
    std::shared_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__msg__UpperMotorState
    std::shared_ptr<ros2_interfaces::msg::UpperMotorState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpperMotorState_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->is_ready != other.is_ready) {
      return false;
    }
    if (this->is_enabled != other.is_enabled) {
      return false;
    }
    if (this->has_fault != other.has_fault) {
      return false;
    }
    if (this->motor_id != other.motor_id) {
      return false;
    }
    if (this->position != other.position) {
      return false;
    }
    if (this->velocity != other.velocity) {
      return false;
    }
    if (this->effort != other.effort) {
      return false;
    }
    if (this->error_code != other.error_code) {
      return false;
    }
    if (this->temperature != other.temperature) {
      return false;
    }
    if (this->voltage != other.voltage) {
      return false;
    }
    if (this->current != other.current) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpperMotorState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpperMotorState_

// alias to use template instance with default allocator
using UpperMotorState =
  ros2_interfaces::msg::UpperMotorState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_MOTOR_STATE__STRUCT_HPP_

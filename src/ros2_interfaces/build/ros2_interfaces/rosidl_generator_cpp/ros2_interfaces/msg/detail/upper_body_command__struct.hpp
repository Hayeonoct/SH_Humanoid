// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_HPP_
#define ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_HPP_

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
# define DEPRECATED__ros2_interfaces__msg__UpperBodyCommand __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__msg__UpperBodyCommand __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct UpperBodyCommand_
{
  using Type = UpperBodyCommand_<ContainerAllocator>;

  explicit UpperBodyCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_mode = 0;
      std::fill<typename std::array<uint8_t, 15>::iterator, uint8_t>(this->motor_id.begin(), this->motor_id.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->effort.begin(), this->effort.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->kp.begin(), this->kp.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->kd.begin(), this->kd.end(), 0.0f);
      this->duration = 0.0f;
    }
  }

  explicit UpperBodyCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    motor_id(_alloc),
    position(_alloc),
    velocity(_alloc),
    effort(_alloc),
    kp(_alloc),
    kd(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_mode = 0;
      std::fill<typename std::array<uint8_t, 15>::iterator, uint8_t>(this->motor_id.begin(), this->motor_id.end(), 0);
      std::fill<typename std::array<float, 15>::iterator, float>(this->position.begin(), this->position.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->velocity.begin(), this->velocity.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->effort.begin(), this->effort.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->kp.begin(), this->kp.end(), 0.0f);
      std::fill<typename std::array<float, 15>::iterator, float>(this->kd.begin(), this->kd.end(), 0.0f);
      this->duration = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _command_mode_type =
    uint8_t;
  _command_mode_type command_mode;
  using _motor_id_type =
    std::array<uint8_t, 15>;
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
  using _kp_type =
    std::array<float, 15>;
  _kp_type kp;
  using _kd_type =
    std::array<float, 15>;
  _kd_type kd;
  using _duration_type =
    float;
  _duration_type duration;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__command_mode(
    const uint8_t & _arg)
  {
    this->command_mode = _arg;
    return *this;
  }
  Type & set__motor_id(
    const std::array<uint8_t, 15> & _arg)
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
  Type & set__kp(
    const std::array<float, 15> & _arg)
  {
    this->kp = _arg;
    return *this;
  }
  Type & set__kd(
    const std::array<float, 15> & _arg)
  {
    this->kd = _arg;
    return *this;
  }
  Type & set__duration(
    const float & _arg)
  {
    this->duration = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t STOP =
    0u;
  static constexpr uint8_t POSITION =
    1u;
  static constexpr uint8_t VELOCITY =
    2u;
  static constexpr uint8_t TORQUE =
    3u;
  static constexpr uint8_t POSITION_VELOCITY =
    4u;
  static constexpr uint8_t IMPEDANCE =
    5u;

  // pointer types
  using RawPtr =
    ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__msg__UpperBodyCommand
    std::shared_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__msg__UpperBodyCommand
    std::shared_ptr<ros2_interfaces::msg::UpperBodyCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const UpperBodyCommand_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->command_mode != other.command_mode) {
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
    if (this->kp != other.kp) {
      return false;
    }
    if (this->kd != other.kd) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    return true;
  }
  bool operator!=(const UpperBodyCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct UpperBodyCommand_

// alias to use template instance with default allocator
using UpperBodyCommand =
  ros2_interfaces::msg::UpperBodyCommand_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::STOP;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::POSITION;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::VELOCITY;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::TORQUE;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::POSITION_VELOCITY;
template<typename ContainerAllocator>
constexpr uint8_t UpperBodyCommand_<ContainerAllocator>::IMPEDANCE;

}  // namespace msg

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__MSG__DETAIL__UPPER_BODY_COMMAND__STRUCT_HPP_

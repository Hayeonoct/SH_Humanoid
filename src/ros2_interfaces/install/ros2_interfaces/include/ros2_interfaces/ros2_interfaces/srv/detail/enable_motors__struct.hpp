// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:srv/EnableMotors.idl
// generated code does not contain a copyright notice

#ifndef ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__STRUCT_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__EnableMotors_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__EnableMotors_Request __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EnableMotors_Request_
{
  using Type = EnableMotors_Request_<ContainerAllocator>;

  explicit EnableMotors_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_all = false;
    }
  }

  explicit EnableMotors_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->enable_all = false;
    }
  }

  // field types and members
  using _enable_all_type =
    bool;
  _enable_all_type enable_all;
  using _motor_id_list_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _motor_id_list_type motor_id_list;

  // setters for named parameter idiom
  Type & set__enable_all(
    const bool & _arg)
  {
    this->enable_all = _arg;
    return *this;
  }
  Type & set__motor_id_list(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->motor_id_list = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__EnableMotors_Request
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__EnableMotors_Request
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnableMotors_Request_ & other) const
  {
    if (this->enable_all != other.enable_all) {
      return false;
    }
    if (this->motor_id_list != other.motor_id_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnableMotors_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnableMotors_Request_

// alias to use template instance with default allocator
using EnableMotors_Request =
  ros2_interfaces::srv::EnableMotors_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces


#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__EnableMotors_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__EnableMotors_Response __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct EnableMotors_Response_
{
  using Type = EnableMotors_Response_<ContainerAllocator>;

  explicit EnableMotors_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit EnableMotors_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _message_type message;
  using _enabled_motor_ids_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _enabled_motor_ids_type enabled_motor_ids;
  using _failed_motor_ids_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _failed_motor_ids_type failed_motor_ids;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->message = _arg;
    return *this;
  }
  Type & set__enabled_motor_ids(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->enabled_motor_ids = _arg;
    return *this;
  }
  Type & set__failed_motor_ids(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->failed_motor_ids = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__EnableMotors_Response
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__EnableMotors_Response
    std::shared_ptr<ros2_interfaces::srv::EnableMotors_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EnableMotors_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->enabled_motor_ids != other.enabled_motor_ids) {
      return false;
    }
    if (this->failed_motor_ids != other.failed_motor_ids) {
      return false;
    }
    return true;
  }
  bool operator!=(const EnableMotors_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EnableMotors_Response_

// alias to use template instance with default allocator
using EnableMotors_Response =
  ros2_interfaces::srv::EnableMotors_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces

namespace ros2_interfaces
{

namespace srv
{

struct EnableMotors
{
  using Request = ros2_interfaces::srv::EnableMotors_Request;
  using Response = ros2_interfaces::srv::EnableMotors_Response;
};

}  // namespace srv

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__ENABLE_MOTORS__STRUCT_HPP_

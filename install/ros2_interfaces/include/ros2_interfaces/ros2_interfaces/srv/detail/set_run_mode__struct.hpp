// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from ros2_interfaces:srv/SetRunMode.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ros2_interfaces/srv/set_run_mode.hpp"


#ifndef ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_HPP_
#define ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Request __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Request __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetRunMode_Request_
{
  using Type = SetRunMode_Request_<ContainerAllocator>;

  explicit SetRunMode_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit SetRunMode_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    uint8_t;
  _mode_type mode;
  using _motor_id_list_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _motor_id_list_type motor_id_list;

  // setters for named parameter idiom
  Type & set__mode(
    const uint8_t & _arg)
  {
    this->mode = _arg;
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
    ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Request
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Request
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetRunMode_Request_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    if (this->motor_id_list != other.motor_id_list) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetRunMode_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetRunMode_Request_

// alias to use template instance with default allocator
using SetRunMode_Request =
  ros2_interfaces::srv::SetRunMode_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces


#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Response __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Response __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetRunMode_Response_
{
  using Type = SetRunMode_Response_<ContainerAllocator>;

  explicit SetRunMode_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->message = "";
    }
  }

  explicit SetRunMode_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
  using _applied_motor_ids_type =
    std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>>;
  _applied_motor_ids_type applied_motor_ids;
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
  Type & set__applied_motor_ids(
    const std::vector<uint8_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<uint8_t>> & _arg)
  {
    this->applied_motor_ids = _arg;
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
    ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Response
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Response
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetRunMode_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    if (this->applied_motor_ids != other.applied_motor_ids) {
      return false;
    }
    if (this->failed_motor_ids != other.failed_motor_ids) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetRunMode_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetRunMode_Response_

// alias to use template instance with default allocator
using SetRunMode_Response =
  ros2_interfaces::srv::SetRunMode_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces


// Include directives for member types
// Member 'info'
#include "service_msgs/msg/detail/service_event_info__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Event __attribute__((deprecated))
#else
# define DEPRECATED__ros2_interfaces__srv__SetRunMode_Event __declspec(deprecated)
#endif

namespace ros2_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SetRunMode_Event_
{
  using Type = SetRunMode_Event_<ContainerAllocator>;

  explicit SetRunMode_Event_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_init)
  {
    (void)_init;
  }

  explicit SetRunMode_Event_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : info(_alloc, _init)
  {
    (void)_init;
  }

  // field types and members
  using _info_type =
    service_msgs::msg::ServiceEventInfo_<ContainerAllocator>;
  _info_type info;
  using _request_type =
    rosidl_runtime_cpp::BoundedVector<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>>;
  _request_type request;
  using _response_type =
    rosidl_runtime_cpp::BoundedVector<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>>;
  _response_type response;

  // setters for named parameter idiom
  Type & set__info(
    const service_msgs::msg::ServiceEventInfo_<ContainerAllocator> & _arg)
  {
    this->info = _arg;
    return *this;
  }
  Type & set__request(
    const rosidl_runtime_cpp::BoundedVector<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros2_interfaces::srv::SetRunMode_Request_<ContainerAllocator>>> & _arg)
  {
    this->request = _arg;
    return *this;
  }
  Type & set__response(
    const rosidl_runtime_cpp::BoundedVector<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>, 1, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<ros2_interfaces::srv::SetRunMode_Response_<ContainerAllocator>>> & _arg)
  {
    this->response = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> *;
  using ConstRawPtr =
    const ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Event
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__ros2_interfaces__srv__SetRunMode_Event
    std::shared_ptr<ros2_interfaces::srv::SetRunMode_Event_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SetRunMode_Event_ & other) const
  {
    if (this->info != other.info) {
      return false;
    }
    if (this->request != other.request) {
      return false;
    }
    if (this->response != other.response) {
      return false;
    }
    return true;
  }
  bool operator!=(const SetRunMode_Event_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SetRunMode_Event_

// alias to use template instance with default allocator
using SetRunMode_Event =
  ros2_interfaces::srv::SetRunMode_Event_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace ros2_interfaces

namespace ros2_interfaces
{

namespace srv
{

struct SetRunMode
{
  using Request = ros2_interfaces::srv::SetRunMode_Request;
  using Response = ros2_interfaces::srv::SetRunMode_Response;
  using Event = ros2_interfaces::srv::SetRunMode_Event;
};

}  // namespace srv

}  // namespace ros2_interfaces

#endif  // ROS2_INTERFACES__SRV__DETAIL__SET_RUN_MODE__STRUCT_HPP_

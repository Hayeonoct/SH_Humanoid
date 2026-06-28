// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:msg/UpperBodyCommand.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_body_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ros2_interfaces__msg__UpperBodyCommand__init(ros2_interfaces__msg__UpperBodyCommand * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_interfaces__msg__UpperBodyCommand__fini(msg);
    return false;
  }
  // command_mode
  // motor_id
  // position
  // velocity
  // effort
  // kp
  // kd
  // duration
  return true;
}

void
ros2_interfaces__msg__UpperBodyCommand__fini(ros2_interfaces__msg__UpperBodyCommand * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // command_mode
  // motor_id
  // position
  // velocity
  // effort
  // kp
  // kd
  // duration
}

bool
ros2_interfaces__msg__UpperBodyCommand__are_equal(const ros2_interfaces__msg__UpperBodyCommand * lhs, const ros2_interfaces__msg__UpperBodyCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // command_mode
  if (lhs->command_mode != rhs->command_mode) {
    return false;
  }
  // motor_id
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->motor_id[i] != rhs->motor_id[i]) {
      return false;
    }
  }
  // position
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->position[i] != rhs->position[i]) {
      return false;
    }
  }
  // velocity
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->velocity[i] != rhs->velocity[i]) {
      return false;
    }
  }
  // effort
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->effort[i] != rhs->effort[i]) {
      return false;
    }
  }
  // kp
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->kp[i] != rhs->kp[i]) {
      return false;
    }
  }
  // kd
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->kd[i] != rhs->kd[i]) {
      return false;
    }
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  return true;
}

bool
ros2_interfaces__msg__UpperBodyCommand__copy(
  const ros2_interfaces__msg__UpperBodyCommand * input,
  ros2_interfaces__msg__UpperBodyCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // command_mode
  output->command_mode = input->command_mode;
  // motor_id
  for (size_t i = 0; i < 15; ++i) {
    output->motor_id[i] = input->motor_id[i];
  }
  // position
  for (size_t i = 0; i < 15; ++i) {
    output->position[i] = input->position[i];
  }
  // velocity
  for (size_t i = 0; i < 15; ++i) {
    output->velocity[i] = input->velocity[i];
  }
  // effort
  for (size_t i = 0; i < 15; ++i) {
    output->effort[i] = input->effort[i];
  }
  // kp
  for (size_t i = 0; i < 15; ++i) {
    output->kp[i] = input->kp[i];
  }
  // kd
  for (size_t i = 0; i < 15; ++i) {
    output->kd[i] = input->kd[i];
  }
  // duration
  output->duration = input->duration;
  return true;
}

ros2_interfaces__msg__UpperBodyCommand *
ros2_interfaces__msg__UpperBodyCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodyCommand * msg = (ros2_interfaces__msg__UpperBodyCommand *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperBodyCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__msg__UpperBodyCommand));
  bool success = ros2_interfaces__msg__UpperBodyCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__msg__UpperBodyCommand__destroy(ros2_interfaces__msg__UpperBodyCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_interfaces__msg__UpperBodyCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_interfaces__msg__UpperBodyCommand__Sequence__init(ros2_interfaces__msg__UpperBodyCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodyCommand * data = NULL;

  if (size) {
    data = (ros2_interfaces__msg__UpperBodyCommand *)allocator.zero_allocate(size, sizeof(ros2_interfaces__msg__UpperBodyCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__msg__UpperBodyCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__msg__UpperBodyCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ros2_interfaces__msg__UpperBodyCommand__Sequence__fini(ros2_interfaces__msg__UpperBodyCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ros2_interfaces__msg__UpperBodyCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ros2_interfaces__msg__UpperBodyCommand__Sequence *
ros2_interfaces__msg__UpperBodyCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodyCommand__Sequence * array = (ros2_interfaces__msg__UpperBodyCommand__Sequence *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperBodyCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__msg__UpperBodyCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__msg__UpperBodyCommand__Sequence__destroy(ros2_interfaces__msg__UpperBodyCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_interfaces__msg__UpperBodyCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_interfaces__msg__UpperBodyCommand__Sequence__are_equal(const ros2_interfaces__msg__UpperBodyCommand__Sequence * lhs, const ros2_interfaces__msg__UpperBodyCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__msg__UpperBodyCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__UpperBodyCommand__Sequence__copy(
  const ros2_interfaces__msg__UpperBodyCommand__Sequence * input,
  ros2_interfaces__msg__UpperBodyCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__msg__UpperBodyCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_interfaces__msg__UpperBodyCommand * data =
      (ros2_interfaces__msg__UpperBodyCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__msg__UpperBodyCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_interfaces__msg__UpperBodyCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_interfaces__msg__UpperBodyCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

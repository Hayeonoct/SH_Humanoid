// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:msg/UpperMotorState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_motor_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ros2_interfaces__msg__UpperMotorState__init(ros2_interfaces__msg__UpperMotorState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_interfaces__msg__UpperMotorState__fini(msg);
    return false;
  }
  // is_ready
  // is_enabled
  // has_fault
  // motor_id
  // position
  // velocity
  // effort
  // error_code
  // temperature
  // voltage
  // current
  return true;
}

void
ros2_interfaces__msg__UpperMotorState__fini(ros2_interfaces__msg__UpperMotorState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // is_ready
  // is_enabled
  // has_fault
  // motor_id
  // position
  // velocity
  // effort
  // error_code
  // temperature
  // voltage
  // current
}

bool
ros2_interfaces__msg__UpperMotorState__are_equal(const ros2_interfaces__msg__UpperMotorState * lhs, const ros2_interfaces__msg__UpperMotorState * rhs)
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
  // is_ready
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->is_ready[i] != rhs->is_ready[i]) {
      return false;
    }
  }
  // is_enabled
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->is_enabled[i] != rhs->is_enabled[i]) {
      return false;
    }
  }
  // has_fault
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->has_fault[i] != rhs->has_fault[i]) {
      return false;
    }
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
  // error_code
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->error_code[i] != rhs->error_code[i]) {
      return false;
    }
  }
  // temperature
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->temperature[i] != rhs->temperature[i]) {
      return false;
    }
  }
  // voltage
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->voltage[i] != rhs->voltage[i]) {
      return false;
    }
  }
  // current
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->current[i] != rhs->current[i]) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__UpperMotorState__copy(
  const ros2_interfaces__msg__UpperMotorState * input,
  ros2_interfaces__msg__UpperMotorState * output)
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
  // is_ready
  for (size_t i = 0; i < 15; ++i) {
    output->is_ready[i] = input->is_ready[i];
  }
  // is_enabled
  for (size_t i = 0; i < 15; ++i) {
    output->is_enabled[i] = input->is_enabled[i];
  }
  // has_fault
  for (size_t i = 0; i < 15; ++i) {
    output->has_fault[i] = input->has_fault[i];
  }
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
  // error_code
  for (size_t i = 0; i < 15; ++i) {
    output->error_code[i] = input->error_code[i];
  }
  // temperature
  for (size_t i = 0; i < 15; ++i) {
    output->temperature[i] = input->temperature[i];
  }
  // voltage
  for (size_t i = 0; i < 15; ++i) {
    output->voltage[i] = input->voltage[i];
  }
  // current
  for (size_t i = 0; i < 15; ++i) {
    output->current[i] = input->current[i];
  }
  return true;
}

ros2_interfaces__msg__UpperMotorState *
ros2_interfaces__msg__UpperMotorState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperMotorState * msg = (ros2_interfaces__msg__UpperMotorState *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperMotorState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__msg__UpperMotorState));
  bool success = ros2_interfaces__msg__UpperMotorState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__msg__UpperMotorState__destroy(ros2_interfaces__msg__UpperMotorState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_interfaces__msg__UpperMotorState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_interfaces__msg__UpperMotorState__Sequence__init(ros2_interfaces__msg__UpperMotorState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperMotorState * data = NULL;

  if (size) {
    data = (ros2_interfaces__msg__UpperMotorState *)allocator.zero_allocate(size, sizeof(ros2_interfaces__msg__UpperMotorState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__msg__UpperMotorState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__msg__UpperMotorState__fini(&data[i - 1]);
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
ros2_interfaces__msg__UpperMotorState__Sequence__fini(ros2_interfaces__msg__UpperMotorState__Sequence * array)
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
      ros2_interfaces__msg__UpperMotorState__fini(&array->data[i]);
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

ros2_interfaces__msg__UpperMotorState__Sequence *
ros2_interfaces__msg__UpperMotorState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperMotorState__Sequence * array = (ros2_interfaces__msg__UpperMotorState__Sequence *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperMotorState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__msg__UpperMotorState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__msg__UpperMotorState__Sequence__destroy(ros2_interfaces__msg__UpperMotorState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_interfaces__msg__UpperMotorState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_interfaces__msg__UpperMotorState__Sequence__are_equal(const ros2_interfaces__msg__UpperMotorState__Sequence * lhs, const ros2_interfaces__msg__UpperMotorState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__msg__UpperMotorState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__UpperMotorState__Sequence__copy(
  const ros2_interfaces__msg__UpperMotorState__Sequence * input,
  ros2_interfaces__msg__UpperMotorState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__msg__UpperMotorState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_interfaces__msg__UpperMotorState * data =
      (ros2_interfaces__msg__UpperMotorState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__msg__UpperMotorState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_interfaces__msg__UpperMotorState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_interfaces__msg__UpperMotorState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

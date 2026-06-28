// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice
#include "ros2_interfaces/msg/detail/upper_body_system_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ros2_interfaces__msg__UpperBodySystemState__init(ros2_interfaces__msg__UpperBodySystemState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ros2_interfaces__msg__UpperBodySystemState__fini(msg);
    return false;
  }
  // state
  // run_mode
  // ready_motor_count
  // enabled_motor_count
  // fault_motor_count
  // is_connected
  // all_motors_enabled
  // command_accepted
  return true;
}

void
ros2_interfaces__msg__UpperBodySystemState__fini(ros2_interfaces__msg__UpperBodySystemState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // state
  // run_mode
  // ready_motor_count
  // enabled_motor_count
  // fault_motor_count
  // is_connected
  // all_motors_enabled
  // command_accepted
}

bool
ros2_interfaces__msg__UpperBodySystemState__are_equal(const ros2_interfaces__msg__UpperBodySystemState * lhs, const ros2_interfaces__msg__UpperBodySystemState * rhs)
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
  // state
  if (lhs->state != rhs->state) {
    return false;
  }
  // run_mode
  if (lhs->run_mode != rhs->run_mode) {
    return false;
  }
  // ready_motor_count
  if (lhs->ready_motor_count != rhs->ready_motor_count) {
    return false;
  }
  // enabled_motor_count
  if (lhs->enabled_motor_count != rhs->enabled_motor_count) {
    return false;
  }
  // fault_motor_count
  if (lhs->fault_motor_count != rhs->fault_motor_count) {
    return false;
  }
  // is_connected
  for (size_t i = 0; i < 15; ++i) {
    if (lhs->is_connected[i] != rhs->is_connected[i]) {
      return false;
    }
  }
  // all_motors_enabled
  if (lhs->all_motors_enabled != rhs->all_motors_enabled) {
    return false;
  }
  // command_accepted
  if (lhs->command_accepted != rhs->command_accepted) {
    return false;
  }
  return true;
}

bool
ros2_interfaces__msg__UpperBodySystemState__copy(
  const ros2_interfaces__msg__UpperBodySystemState * input,
  ros2_interfaces__msg__UpperBodySystemState * output)
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
  // state
  output->state = input->state;
  // run_mode
  output->run_mode = input->run_mode;
  // ready_motor_count
  output->ready_motor_count = input->ready_motor_count;
  // enabled_motor_count
  output->enabled_motor_count = input->enabled_motor_count;
  // fault_motor_count
  output->fault_motor_count = input->fault_motor_count;
  // is_connected
  for (size_t i = 0; i < 15; ++i) {
    output->is_connected[i] = input->is_connected[i];
  }
  // all_motors_enabled
  output->all_motors_enabled = input->all_motors_enabled;
  // command_accepted
  output->command_accepted = input->command_accepted;
  return true;
}

ros2_interfaces__msg__UpperBodySystemState *
ros2_interfaces__msg__UpperBodySystemState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodySystemState * msg = (ros2_interfaces__msg__UpperBodySystemState *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperBodySystemState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ros2_interfaces__msg__UpperBodySystemState));
  bool success = ros2_interfaces__msg__UpperBodySystemState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ros2_interfaces__msg__UpperBodySystemState__destroy(ros2_interfaces__msg__UpperBodySystemState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ros2_interfaces__msg__UpperBodySystemState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ros2_interfaces__msg__UpperBodySystemState__Sequence__init(ros2_interfaces__msg__UpperBodySystemState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodySystemState * data = NULL;

  if (size) {
    data = (ros2_interfaces__msg__UpperBodySystemState *)allocator.zero_allocate(size, sizeof(ros2_interfaces__msg__UpperBodySystemState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ros2_interfaces__msg__UpperBodySystemState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ros2_interfaces__msg__UpperBodySystemState__fini(&data[i - 1]);
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
ros2_interfaces__msg__UpperBodySystemState__Sequence__fini(ros2_interfaces__msg__UpperBodySystemState__Sequence * array)
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
      ros2_interfaces__msg__UpperBodySystemState__fini(&array->data[i]);
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

ros2_interfaces__msg__UpperBodySystemState__Sequence *
ros2_interfaces__msg__UpperBodySystemState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ros2_interfaces__msg__UpperBodySystemState__Sequence * array = (ros2_interfaces__msg__UpperBodySystemState__Sequence *)allocator.allocate(sizeof(ros2_interfaces__msg__UpperBodySystemState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ros2_interfaces__msg__UpperBodySystemState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ros2_interfaces__msg__UpperBodySystemState__Sequence__destroy(ros2_interfaces__msg__UpperBodySystemState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ros2_interfaces__msg__UpperBodySystemState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ros2_interfaces__msg__UpperBodySystemState__Sequence__are_equal(const ros2_interfaces__msg__UpperBodySystemState__Sequence * lhs, const ros2_interfaces__msg__UpperBodySystemState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ros2_interfaces__msg__UpperBodySystemState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ros2_interfaces__msg__UpperBodySystemState__Sequence__copy(
  const ros2_interfaces__msg__UpperBodySystemState__Sequence * input,
  ros2_interfaces__msg__UpperBodySystemState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ros2_interfaces__msg__UpperBodySystemState);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ros2_interfaces__msg__UpperBodySystemState * data =
      (ros2_interfaces__msg__UpperBodySystemState *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ros2_interfaces__msg__UpperBodySystemState__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ros2_interfaces__msg__UpperBodySystemState__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ros2_interfaces__msg__UpperBodySystemState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}

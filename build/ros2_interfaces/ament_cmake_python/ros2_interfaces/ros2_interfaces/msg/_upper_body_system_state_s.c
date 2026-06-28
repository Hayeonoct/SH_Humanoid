// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ros2_interfaces:msg/UpperBodySystemState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__struct.h"
#include "ros2_interfaces/msg/detail/upper_body_system_state__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool ros2_interfaces__msg__upper_body_system_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[66];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("ros2_interfaces.msg._upper_body_system_state.UpperBodySystemState", full_classname_dest, 65) == 0);
  }
  ros2_interfaces__msg__UpperBodySystemState * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // state
    PyObject * field = PyObject_GetAttrString(_pymsg, "state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // run_mode
    PyObject * field = PyObject_GetAttrString(_pymsg, "run_mode");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->run_mode = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // ready_motor_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "ready_motor_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->ready_motor_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // enabled_motor_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "enabled_motor_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->enabled_motor_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // fault_motor_count
    PyObject * field = PyObject_GetAttrString(_pymsg, "fault_motor_count");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->fault_motor_count = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // is_connected
    PyObject * field = PyObject_GetAttrString(_pymsg, "is_connected");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'is_connected'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = 15;
      bool * dest = ros_message->is_connected;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyBool_Check(item));
        bool tmp = (item == Py_True);
        memcpy(&dest[i], &tmp, sizeof(bool));
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // all_motors_enabled
    PyObject * field = PyObject_GetAttrString(_pymsg, "all_motors_enabled");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->all_motors_enabled = (Py_True == field);
    Py_DECREF(field);
  }
  {  // command_accepted
    PyObject * field = PyObject_GetAttrString(_pymsg, "command_accepted");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->command_accepted = (Py_True == field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ros2_interfaces__msg__upper_body_system_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of UpperBodySystemState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ros2_interfaces.msg._upper_body_system_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "UpperBodySystemState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ros2_interfaces__msg__UpperBodySystemState * ros_message = (ros2_interfaces__msg__UpperBodySystemState *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // run_mode
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->run_mode);
    {
      int rc = PyObject_SetAttrString(_pymessage, "run_mode", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // ready_motor_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->ready_motor_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ready_motor_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // enabled_motor_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->enabled_motor_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "enabled_motor_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // fault_motor_count
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->fault_motor_count);
    {
      int rc = PyObject_SetAttrString(_pymessage, "fault_motor_count", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // is_connected
    PyObject * field = NULL;
    size_t size = 15;
    bool * src = ros_message->is_connected;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      int rc = PyList_SetItem(field, i, PyBool_FromLong(src[i] ? 1 : 0));
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "is_connected", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // all_motors_enabled
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->all_motors_enabled ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "all_motors_enabled", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // command_accepted
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->command_accepted ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "command_accepted", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}

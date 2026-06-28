# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_interfaces:msg/UpperMotorState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'motor_id'
# Member 'position'
# Member 'velocity'
# Member 'effort'
# Member 'error_code'
# Member 'temperature'
# Member 'voltage'
# Member 'current'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpperMotorState(type):
    """Metaclass of message 'UpperMotorState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_interfaces.msg.UpperMotorState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__upper_motor_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__upper_motor_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__upper_motor_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__upper_motor_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__upper_motor_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class UpperMotorState(metaclass=Metaclass_UpperMotorState):
    """Message class 'UpperMotorState'."""

    __slots__ = [
        '_header',
        '_is_ready',
        '_is_enabled',
        '_has_fault',
        '_motor_id',
        '_position',
        '_velocity',
        '_effort',
        '_error_code',
        '_temperature',
        '_voltage',
        '_current',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'is_ready': 'boolean[15]',
        'is_enabled': 'boolean[15]',
        'has_fault': 'boolean[15]',
        'motor_id': 'uint16[15]',
        'position': 'float[15]',
        'velocity': 'float[15]',
        'effort': 'float[15]',
        'error_code': 'uint16[15]',
        'temperature': 'float[15]',
        'voltage': 'float[15]',
        'current': 'float[15]',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint16'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.is_ready = kwargs.get(
            'is_ready',
            [bool() for x in range(15)]
        )
        self.is_enabled = kwargs.get(
            'is_enabled',
            [bool() for x in range(15)]
        )
        self.has_fault = kwargs.get(
            'has_fault',
            [bool() for x in range(15)]
        )
        if 'motor_id' not in kwargs:
            self.motor_id = numpy.zeros(15, dtype=numpy.uint16)
        else:
            self.motor_id = numpy.array(kwargs.get('motor_id'), dtype=numpy.uint16)
            assert self.motor_id.shape == (15, )
        if 'position' not in kwargs:
            self.position = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.position = numpy.array(kwargs.get('position'), dtype=numpy.float32)
            assert self.position.shape == (15, )
        if 'velocity' not in kwargs:
            self.velocity = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.velocity = numpy.array(kwargs.get('velocity'), dtype=numpy.float32)
            assert self.velocity.shape == (15, )
        if 'effort' not in kwargs:
            self.effort = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.effort = numpy.array(kwargs.get('effort'), dtype=numpy.float32)
            assert self.effort.shape == (15, )
        if 'error_code' not in kwargs:
            self.error_code = numpy.zeros(15, dtype=numpy.uint16)
        else:
            self.error_code = numpy.array(kwargs.get('error_code'), dtype=numpy.uint16)
            assert self.error_code.shape == (15, )
        if 'temperature' not in kwargs:
            self.temperature = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.temperature = numpy.array(kwargs.get('temperature'), dtype=numpy.float32)
            assert self.temperature.shape == (15, )
        if 'voltage' not in kwargs:
            self.voltage = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.voltage = numpy.array(kwargs.get('voltage'), dtype=numpy.float32)
            assert self.voltage.shape == (15, )
        if 'current' not in kwargs:
            self.current = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.current = numpy.array(kwargs.get('current'), dtype=numpy.float32)
            assert self.current.shape == (15, )

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.is_ready != other.is_ready:
            return False
        if self.is_enabled != other.is_enabled:
            return False
        if self.has_fault != other.has_fault:
            return False
        if all(self.motor_id != other.motor_id):
            return False
        if all(self.position != other.position):
            return False
        if all(self.velocity != other.velocity):
            return False
        if all(self.effort != other.effort):
            return False
        if all(self.error_code != other.error_code):
            return False
        if all(self.temperature != other.temperature):
            return False
        if all(self.voltage != other.voltage):
            return False
        if all(self.current != other.current):
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def is_ready(self):
        """Message field 'is_ready'."""
        return self._is_ready

    @is_ready.setter
    def is_ready(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'is_ready' field must be a set or sequence with length 15 and each value of type 'bool'"
        self._is_ready = value

    @builtins.property
    def is_enabled(self):
        """Message field 'is_enabled'."""
        return self._is_enabled

    @is_enabled.setter
    def is_enabled(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'is_enabled' field must be a set or sequence with length 15 and each value of type 'bool'"
        self._is_enabled = value

    @builtins.property
    def has_fault(self):
        """Message field 'has_fault'."""
        return self._has_fault

    @has_fault.setter
    def has_fault(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, bool) for v in value) and
                 True), \
                "The 'has_fault' field must be a set or sequence with length 15 and each value of type 'bool'"
        self._has_fault = value

    @builtins.property
    def motor_id(self):
        """Message field 'motor_id'."""
        return self._motor_id

    @motor_id.setter
    def motor_id(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'motor_id' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 15, \
                "The 'motor_id' numpy.ndarray() must have a size of 15"
            self._motor_id = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'motor_id' field must be a set or sequence with length 15 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._motor_id = numpy.array(value, dtype=numpy.uint16)

    @builtins.property
    def position(self):
        """Message field 'position'."""
        return self._position

    @position.setter
    def position(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'position' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'position' numpy.ndarray() must have a size of 15"
            self._position = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'position' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._position = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def velocity(self):
        """Message field 'velocity'."""
        return self._velocity

    @velocity.setter
    def velocity(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'velocity' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'velocity' numpy.ndarray() must have a size of 15"
            self._velocity = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'velocity' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._velocity = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def effort(self):
        """Message field 'effort'."""
        return self._effort

    @effort.setter
    def effort(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'effort' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'effort' numpy.ndarray() must have a size of 15"
            self._effort = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'effort' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._effort = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def error_code(self):
        """Message field 'error_code'."""
        return self._error_code

    @error_code.setter
    def error_code(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint16, \
                "The 'error_code' numpy.ndarray() must have the dtype of 'numpy.uint16'"
            assert value.size == 15, \
                "The 'error_code' numpy.ndarray() must have a size of 15"
            self._error_code = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 65536 for val in value)), \
                "The 'error_code' field must be a set or sequence with length 15 and each value of type 'int' and each unsigned integer in [0, 65535]"
        self._error_code = numpy.array(value, dtype=numpy.uint16)

    @builtins.property
    def temperature(self):
        """Message field 'temperature'."""
        return self._temperature

    @temperature.setter
    def temperature(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'temperature' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'temperature' numpy.ndarray() must have a size of 15"
            self._temperature = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'temperature' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._temperature = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def voltage(self):
        """Message field 'voltage'."""
        return self._voltage

    @voltage.setter
    def voltage(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'voltage' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'voltage' numpy.ndarray() must have a size of 15"
            self._voltage = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'voltage' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._voltage = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def current(self):
        """Message field 'current'."""
        return self._current

    @current.setter
    def current(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'current' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'current' numpy.ndarray() must have a size of 15"
            self._current = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 len(value) == 15 and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -3.402823466e+38 or val > 3.402823466e+38) or math.isinf(val) for val in value)), \
                "The 'current' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._current = numpy.array(value, dtype=numpy.float32)

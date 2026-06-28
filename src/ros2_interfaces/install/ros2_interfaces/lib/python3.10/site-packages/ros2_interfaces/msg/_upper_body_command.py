# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_interfaces:msg/UpperBodyCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

# Member 'motor_id'
# Member 'position'
# Member 'velocity'
# Member 'effort'
# Member 'kp'
# Member 'kd'
import numpy  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpperBodyCommand(type):
    """Metaclass of message 'UpperBodyCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'STOP': 0,
        'POSITION': 1,
        'VELOCITY': 2,
        'TORQUE': 3,
        'POSITION_VELOCITY': 4,
        'IMPEDANCE': 5,
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
                'ros2_interfaces.msg.UpperBodyCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__upper_body_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__upper_body_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__upper_body_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__upper_body_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__upper_body_command

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'STOP': cls.__constants['STOP'],
            'POSITION': cls.__constants['POSITION'],
            'VELOCITY': cls.__constants['VELOCITY'],
            'TORQUE': cls.__constants['TORQUE'],
            'POSITION_VELOCITY': cls.__constants['POSITION_VELOCITY'],
            'IMPEDANCE': cls.__constants['IMPEDANCE'],
        }

    @property
    def STOP(self):
        """Message constant 'STOP'."""
        return Metaclass_UpperBodyCommand.__constants['STOP']

    @property
    def POSITION(self):
        """Message constant 'POSITION'."""
        return Metaclass_UpperBodyCommand.__constants['POSITION']

    @property
    def VELOCITY(self):
        """Message constant 'VELOCITY'."""
        return Metaclass_UpperBodyCommand.__constants['VELOCITY']

    @property
    def TORQUE(self):
        """Message constant 'TORQUE'."""
        return Metaclass_UpperBodyCommand.__constants['TORQUE']

    @property
    def POSITION_VELOCITY(self):
        """Message constant 'POSITION_VELOCITY'."""
        return Metaclass_UpperBodyCommand.__constants['POSITION_VELOCITY']

    @property
    def IMPEDANCE(self):
        """Message constant 'IMPEDANCE'."""
        return Metaclass_UpperBodyCommand.__constants['IMPEDANCE']


class UpperBodyCommand(metaclass=Metaclass_UpperBodyCommand):
    """
    Message class 'UpperBodyCommand'.

    Constants:
      STOP
      POSITION
      VELOCITY
      TORQUE
      POSITION_VELOCITY
      IMPEDANCE
    """

    __slots__ = [
        '_header',
        '_command_mode',
        '_motor_id',
        '_position',
        '_velocity',
        '_effort',
        '_kp',
        '_kd',
        '_duration',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'command_mode': 'uint8',
        'motor_id': 'uint8[15]',
        'position': 'float[15]',
        'velocity': 'float[15]',
        'effort': 'float[15]',
        'kp': 'float[15]',
        'kd': 'float[15]',
        'duration': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('uint8'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('float'), 15),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.command_mode = kwargs.get('command_mode', int())
        if 'motor_id' not in kwargs:
            self.motor_id = numpy.zeros(15, dtype=numpy.uint8)
        else:
            self.motor_id = numpy.array(kwargs.get('motor_id'), dtype=numpy.uint8)
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
        if 'kp' not in kwargs:
            self.kp = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.kp = numpy.array(kwargs.get('kp'), dtype=numpy.float32)
            assert self.kp.shape == (15, )
        if 'kd' not in kwargs:
            self.kd = numpy.zeros(15, dtype=numpy.float32)
        else:
            self.kd = numpy.array(kwargs.get('kd'), dtype=numpy.float32)
            assert self.kd.shape == (15, )
        self.duration = kwargs.get('duration', float())

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
        if self.command_mode != other.command_mode:
            return False
        if all(self.motor_id != other.motor_id):
            return False
        if all(self.position != other.position):
            return False
        if all(self.velocity != other.velocity):
            return False
        if all(self.effort != other.effort):
            return False
        if all(self.kp != other.kp):
            return False
        if all(self.kd != other.kd):
            return False
        if self.duration != other.duration:
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
    def command_mode(self):
        """Message field 'command_mode'."""
        return self._command_mode

    @command_mode.setter
    def command_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command_mode' field must be an unsigned integer in [0, 255]"
        self._command_mode = value

    @builtins.property
    def motor_id(self):
        """Message field 'motor_id'."""
        return self._motor_id

    @motor_id.setter
    def motor_id(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.uint8, \
                "The 'motor_id' numpy.ndarray() must have the dtype of 'numpy.uint8'"
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
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'motor_id' field must be a set or sequence with length 15 and each value of type 'int' and each unsigned integer in [0, 255]"
        self._motor_id = numpy.array(value, dtype=numpy.uint8)

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
    def kp(self):
        """Message field 'kp'."""
        return self._kp

    @kp.setter
    def kp(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'kp' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'kp' numpy.ndarray() must have a size of 15"
            self._kp = value
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
                "The 'kp' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._kp = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def kd(self):
        """Message field 'kd'."""
        return self._kd

    @kd.setter
    def kd(self, value):
        if isinstance(value, numpy.ndarray):
            assert value.dtype == numpy.float32, \
                "The 'kd' numpy.ndarray() must have the dtype of 'numpy.float32'"
            assert value.size == 15, \
                "The 'kd' numpy.ndarray() must have a size of 15"
            self._kd = value
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
                "The 'kd' field must be a set or sequence with length 15 and each value of type 'float' and each float in [-340282346600000016151267322115014000640.000000, 340282346600000016151267322115014000640.000000]"
        self._kd = numpy.array(value, dtype=numpy.float32)

    @builtins.property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'duration' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'duration' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._duration = value

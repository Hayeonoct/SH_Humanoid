# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_interfaces:msg/UpperBodySystemState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UpperBodySystemState(type):
    """Metaclass of message 'UpperBodySystemState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'POWER_OFF': 0,
        'DRIVER_INIT': 1,
        'READY': 2,
        'ENABLING': 3,
        'ENABLED': 4,
        'RUNNING': 5,
        'FAULT': 6,
        'MODE_IDLE': 0,
        'MODE_TORQUE': 1,
        'MODE_VELOCITY': 2,
        'MODE_POSITION': 3,
        'MODE_IMPEDANCE': 4,
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
                'ros2_interfaces.msg.UpperBodySystemState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__upper_body_system_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__upper_body_system_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__upper_body_system_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__upper_body_system_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__upper_body_system_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'POWER_OFF': cls.__constants['POWER_OFF'],
            'DRIVER_INIT': cls.__constants['DRIVER_INIT'],
            'READY': cls.__constants['READY'],
            'ENABLING': cls.__constants['ENABLING'],
            'ENABLED': cls.__constants['ENABLED'],
            'RUNNING': cls.__constants['RUNNING'],
            'FAULT': cls.__constants['FAULT'],
            'MODE_IDLE': cls.__constants['MODE_IDLE'],
            'MODE_TORQUE': cls.__constants['MODE_TORQUE'],
            'MODE_VELOCITY': cls.__constants['MODE_VELOCITY'],
            'MODE_POSITION': cls.__constants['MODE_POSITION'],
            'MODE_IMPEDANCE': cls.__constants['MODE_IMPEDANCE'],
        }

    @property
    def POWER_OFF(self):
        """Message constant 'POWER_OFF'."""
        return Metaclass_UpperBodySystemState.__constants['POWER_OFF']

    @property
    def DRIVER_INIT(self):
        """Message constant 'DRIVER_INIT'."""
        return Metaclass_UpperBodySystemState.__constants['DRIVER_INIT']

    @property
    def READY(self):
        """Message constant 'READY'."""
        return Metaclass_UpperBodySystemState.__constants['READY']

    @property
    def ENABLING(self):
        """Message constant 'ENABLING'."""
        return Metaclass_UpperBodySystemState.__constants['ENABLING']

    @property
    def ENABLED(self):
        """Message constant 'ENABLED'."""
        return Metaclass_UpperBodySystemState.__constants['ENABLED']

    @property
    def RUNNING(self):
        """Message constant 'RUNNING'."""
        return Metaclass_UpperBodySystemState.__constants['RUNNING']

    @property
    def FAULT(self):
        """Message constant 'FAULT'."""
        return Metaclass_UpperBodySystemState.__constants['FAULT']

    @property
    def MODE_IDLE(self):
        """Message constant 'MODE_IDLE'."""
        return Metaclass_UpperBodySystemState.__constants['MODE_IDLE']

    @property
    def MODE_TORQUE(self):
        """Message constant 'MODE_TORQUE'."""
        return Metaclass_UpperBodySystemState.__constants['MODE_TORQUE']

    @property
    def MODE_VELOCITY(self):
        """Message constant 'MODE_VELOCITY'."""
        return Metaclass_UpperBodySystemState.__constants['MODE_VELOCITY']

    @property
    def MODE_POSITION(self):
        """Message constant 'MODE_POSITION'."""
        return Metaclass_UpperBodySystemState.__constants['MODE_POSITION']

    @property
    def MODE_IMPEDANCE(self):
        """Message constant 'MODE_IMPEDANCE'."""
        return Metaclass_UpperBodySystemState.__constants['MODE_IMPEDANCE']


class UpperBodySystemState(metaclass=Metaclass_UpperBodySystemState):
    """
    Message class 'UpperBodySystemState'.

    Constants:
      POWER_OFF
      DRIVER_INIT
      READY
      ENABLING
      ENABLED
      RUNNING
      FAULT
      MODE_IDLE
      MODE_TORQUE
      MODE_VELOCITY
      MODE_POSITION
      MODE_IMPEDANCE
    """

    __slots__ = [
        '_header',
        '_state',
        '_run_mode',
        '_ready_motor_count',
        '_enabled_motor_count',
        '_fault_motor_count',
        '_is_connected',
        '_all_motors_enabled',
        '_command_accepted',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'state': 'uint8',
        'run_mode': 'uint8',
        'ready_motor_count': 'uint8',
        'enabled_motor_count': 'uint8',
        'fault_motor_count': 'uint8',
        'is_connected': 'boolean[15]',
        'all_motors_enabled': 'boolean',
        'command_accepted': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.Array(rosidl_parser.definition.BasicType('boolean'), 15),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.state = kwargs.get('state', int())
        self.run_mode = kwargs.get('run_mode', int())
        self.ready_motor_count = kwargs.get('ready_motor_count', int())
        self.enabled_motor_count = kwargs.get('enabled_motor_count', int())
        self.fault_motor_count = kwargs.get('fault_motor_count', int())
        self.is_connected = kwargs.get(
            'is_connected',
            [bool() for x in range(15)]
        )
        self.all_motors_enabled = kwargs.get('all_motors_enabled', bool())
        self.command_accepted = kwargs.get('command_accepted', bool())

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
        if self.state != other.state:
            return False
        if self.run_mode != other.run_mode:
            return False
        if self.ready_motor_count != other.ready_motor_count:
            return False
        if self.enabled_motor_count != other.enabled_motor_count:
            return False
        if self.fault_motor_count != other.fault_motor_count:
            return False
        if self.is_connected != other.is_connected:
            return False
        if self.all_motors_enabled != other.all_motors_enabled:
            return False
        if self.command_accepted != other.command_accepted:
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
    def state(self):
        """Message field 'state'."""
        return self._state

    @state.setter
    def state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'state' field must be an unsigned integer in [0, 255]"
        self._state = value

    @builtins.property
    def run_mode(self):
        """Message field 'run_mode'."""
        return self._run_mode

    @run_mode.setter
    def run_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'run_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'run_mode' field must be an unsigned integer in [0, 255]"
        self._run_mode = value

    @builtins.property
    def ready_motor_count(self):
        """Message field 'ready_motor_count'."""
        return self._ready_motor_count

    @ready_motor_count.setter
    def ready_motor_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'ready_motor_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'ready_motor_count' field must be an unsigned integer in [0, 255]"
        self._ready_motor_count = value

    @builtins.property
    def enabled_motor_count(self):
        """Message field 'enabled_motor_count'."""
        return self._enabled_motor_count

    @enabled_motor_count.setter
    def enabled_motor_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'enabled_motor_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'enabled_motor_count' field must be an unsigned integer in [0, 255]"
        self._enabled_motor_count = value

    @builtins.property
    def fault_motor_count(self):
        """Message field 'fault_motor_count'."""
        return self._fault_motor_count

    @fault_motor_count.setter
    def fault_motor_count(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'fault_motor_count' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'fault_motor_count' field must be an unsigned integer in [0, 255]"
        self._fault_motor_count = value

    @builtins.property
    def is_connected(self):
        """Message field 'is_connected'."""
        return self._is_connected

    @is_connected.setter
    def is_connected(self, value):
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
                "The 'is_connected' field must be a set or sequence with length 15 and each value of type 'bool'"
        self._is_connected = value

    @builtins.property
    def all_motors_enabled(self):
        """Message field 'all_motors_enabled'."""
        return self._all_motors_enabled

    @all_motors_enabled.setter
    def all_motors_enabled(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'all_motors_enabled' field must be of type 'bool'"
        self._all_motors_enabled = value

    @builtins.property
    def command_accepted(self):
        """Message field 'command_accepted'."""
        return self._command_accepted

    @command_accepted.setter
    def command_accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'command_accepted' field must be of type 'bool'"
        self._command_accepted = value

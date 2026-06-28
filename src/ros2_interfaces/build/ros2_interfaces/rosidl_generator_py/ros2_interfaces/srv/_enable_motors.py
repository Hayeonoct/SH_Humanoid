# generated from rosidl_generator_py/resource/_idl.py.em
# with input from ros2_interfaces:srv/EnableMotors.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'motor_id_list'
import array  # noqa: E402, I100

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_EnableMotors_Request(type):
    """Metaclass of message 'EnableMotors_Request'."""

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
                'ros2_interfaces.srv.EnableMotors_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__enable_motors__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__enable_motors__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__enable_motors__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__enable_motors__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__enable_motors__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnableMotors_Request(metaclass=Metaclass_EnableMotors_Request):
    """Message class 'EnableMotors_Request'."""

    __slots__ = [
        '_enable_all',
        '_motor_id_list',
    ]

    _fields_and_field_types = {
        'enable_all': 'boolean',
        'motor_id_list': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.enable_all = kwargs.get('enable_all', bool())
        self.motor_id_list = array.array('B', kwargs.get('motor_id_list', []))

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
        if self.enable_all != other.enable_all:
            return False
        if self.motor_id_list != other.motor_id_list:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def enable_all(self):
        """Message field 'enable_all'."""
        return self._enable_all

    @enable_all.setter
    def enable_all(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'enable_all' field must be of type 'bool'"
        self._enable_all = value

    @builtins.property
    def motor_id_list(self):
        """Message field 'motor_id_list'."""
        return self._motor_id_list

    @motor_id_list.setter
    def motor_id_list(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'motor_id_list' array.array() must have the type code of 'B'"
            self._motor_id_list = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'motor_id_list' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._motor_id_list = array.array('B', value)


# Import statements for member types

# Member 'enabled_motor_ids'
# Member 'failed_motor_ids'
# already imported above
# import array

# already imported above
# import builtins

# already imported above
# import rosidl_parser.definition


class Metaclass_EnableMotors_Response(type):
    """Metaclass of message 'EnableMotors_Response'."""

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
                'ros2_interfaces.srv.EnableMotors_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__enable_motors__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__enable_motors__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__enable_motors__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__enable_motors__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__enable_motors__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class EnableMotors_Response(metaclass=Metaclass_EnableMotors_Response):
    """Message class 'EnableMotors_Response'."""

    __slots__ = [
        '_success',
        '_message',
        '_enabled_motor_ids',
        '_failed_motor_ids',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'message': 'string',
        'enabled_motor_ids': 'sequence<uint8>',
        'failed_motor_ids': 'sequence<uint8>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('uint8')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.message = kwargs.get('message', str())
        self.enabled_motor_ids = array.array('B', kwargs.get('enabled_motor_ids', []))
        self.failed_motor_ids = array.array('B', kwargs.get('failed_motor_ids', []))

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
        if self.success != other.success:
            return False
        if self.message != other.message:
            return False
        if self.enabled_motor_ids != other.enabled_motor_ids:
            return False
        if self.failed_motor_ids != other.failed_motor_ids:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @builtins.property
    def message(self):
        """Message field 'message'."""
        return self._message

    @message.setter
    def message(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'message' field must be of type 'str'"
        self._message = value

    @builtins.property
    def enabled_motor_ids(self):
        """Message field 'enabled_motor_ids'."""
        return self._enabled_motor_ids

    @enabled_motor_ids.setter
    def enabled_motor_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'enabled_motor_ids' array.array() must have the type code of 'B'"
            self._enabled_motor_ids = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'enabled_motor_ids' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._enabled_motor_ids = array.array('B', value)

    @builtins.property
    def failed_motor_ids(self):
        """Message field 'failed_motor_ids'."""
        return self._failed_motor_ids

    @failed_motor_ids.setter
    def failed_motor_ids(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'B', \
                "The 'failed_motor_ids' array.array() must have the type code of 'B'"
            self._failed_motor_ids = value
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
                 all(isinstance(v, int) for v in value) and
                 all(val >= 0 and val < 256 for val in value)), \
                "The 'failed_motor_ids' field must be a set or sequence and each value of type 'int' and each unsigned integer in [0, 255]"
        self._failed_motor_ids = array.array('B', value)


class Metaclass_EnableMotors(type):
    """Metaclass of service 'EnableMotors'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('ros2_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'ros2_interfaces.srv.EnableMotors')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__enable_motors

            from ros2_interfaces.srv import _enable_motors
            if _enable_motors.Metaclass_EnableMotors_Request._TYPE_SUPPORT is None:
                _enable_motors.Metaclass_EnableMotors_Request.__import_type_support__()
            if _enable_motors.Metaclass_EnableMotors_Response._TYPE_SUPPORT is None:
                _enable_motors.Metaclass_EnableMotors_Response.__import_type_support__()


class EnableMotors(metaclass=Metaclass_EnableMotors):
    from ros2_interfaces.srv._enable_motors import EnableMotors_Request as Request
    from ros2_interfaces.srv._enable_motors import EnableMotors_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')

# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xrf2_msgs:msg/Xeno2Ros.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Xeno2Ros(type):
    """Metaclass of message 'Xeno2Ros'."""

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
            module = import_type_support('xrf2_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'xrf2_msgs.msg.Xeno2Ros')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__xeno2_ros
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__xeno2_ros
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__xeno2_ros
            cls._TYPE_SUPPORT = module.type_support_msg__msg__xeno2_ros
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__xeno2_ros

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Xeno2Ros(metaclass=Metaclass_Xeno2Ros):
    """Message class 'Xeno2Ros'."""

    __slots__ = [
        '_steer_left',
        '_steer_right',
    ]

    _fields_and_field_types = {
        'steer_left': 'double',
        'steer_right': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.steer_left = kwargs.get('steer_left', float())
        self.steer_right = kwargs.get('steer_right', float())

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
        if self.steer_left != other.steer_left:
            return False
        if self.steer_right != other.steer_right:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def steer_left(self):
        """Message field 'steer_left'."""
        return self._steer_left

    @steer_left.setter
    def steer_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steer_left' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_left' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_left = value

    @builtins.property
    def steer_right(self):
        """Message field 'steer_right'."""
        return self._steer_right

    @steer_right.setter
    def steer_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'steer_right' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'steer_right' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._steer_right = value

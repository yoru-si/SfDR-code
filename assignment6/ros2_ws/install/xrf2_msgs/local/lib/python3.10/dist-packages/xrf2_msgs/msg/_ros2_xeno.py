# generated from rosidl_generator_py/resource/_idl.py.em
# with input from xrf2_msgs:msg/Ros2Xeno.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_Ros2Xeno(type):
    """Metaclass of message 'Ros2Xeno'."""

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
                'xrf2_msgs.msg.Ros2Xeno')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__ros2_xeno
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__ros2_xeno
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__ros2_xeno
            cls._TYPE_SUPPORT = module.type_support_msg__msg__ros2_xeno
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__ros2_xeno

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class Ros2Xeno(metaclass=Metaclass_Ros2Xeno):
    """Message class 'Ros2Xeno'."""

    __slots__ = [
        '_pos_left',
        '_pos_right',
        '_set_pos_left',
        '_set_pos_right',
    ]

    _fields_and_field_types = {
        'pos_left': 'double',
        'pos_right': 'double',
        'set_pos_left': 'double',
        'set_pos_right': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.pos_left = kwargs.get('pos_left', float())
        self.pos_right = kwargs.get('pos_right', float())
        self.set_pos_left = kwargs.get('set_pos_left', float())
        self.set_pos_right = kwargs.get('set_pos_right', float())

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
        if self.pos_left != other.pos_left:
            return False
        if self.pos_right != other.pos_right:
            return False
        if self.set_pos_left != other.set_pos_left:
            return False
        if self.set_pos_right != other.set_pos_right:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def pos_left(self):
        """Message field 'pos_left'."""
        return self._pos_left

    @pos_left.setter
    def pos_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_left' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pos_left' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pos_left = value

    @builtins.property
    def pos_right(self):
        """Message field 'pos_right'."""
        return self._pos_right

    @pos_right.setter
    def pos_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'pos_right' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'pos_right' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._pos_right = value

    @builtins.property
    def set_pos_left(self):
        """Message field 'set_pos_left'."""
        return self._set_pos_left

    @set_pos_left.setter
    def set_pos_left(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'set_pos_left' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'set_pos_left' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._set_pos_left = value

    @builtins.property
    def set_pos_right(self):
        """Message field 'set_pos_right'."""
        return self._set_pos_right

    @set_pos_right.setter
    def set_pos_right(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'set_pos_right' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'set_pos_right' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._set_pos_right = value

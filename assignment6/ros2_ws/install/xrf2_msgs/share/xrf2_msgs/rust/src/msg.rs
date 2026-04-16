#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to xrf2_msgs__msg__Ros2Xeno

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Ros2Xeno {

    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_left: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub pos_right: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub left_wheel_vel: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub right_wheel_vel: f64,

}



impl Default for Ros2Xeno {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Ros2Xeno::default())
  }
}

impl rosidl_runtime_rs::Message for Ros2Xeno {
  type RmwMsg = super::msg::rmw::Ros2Xeno;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        pos_left: msg.pos_left,
        pos_right: msg.pos_right,
        left_wheel_vel: msg.left_wheel_vel,
        right_wheel_vel: msg.right_wheel_vel,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      pos_left: msg.pos_left,
      pos_right: msg.pos_right,
      left_wheel_vel: msg.left_wheel_vel,
      right_wheel_vel: msg.right_wheel_vel,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      pos_left: msg.pos_left,
      pos_right: msg.pos_right,
      left_wheel_vel: msg.left_wheel_vel,
      right_wheel_vel: msg.right_wheel_vel,
    }
  }
}


// Corresponds to xrf2_msgs__msg__Xeno2Ros

// This struct is not documented.
#[allow(missing_docs)]

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct Xeno2Ros {

    // This member is not documented.
    #[allow(missing_docs)]
    pub steer_left: f64,


    // This member is not documented.
    #[allow(missing_docs)]
    pub steer_right: f64,

}



impl Default for Xeno2Ros {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::Xeno2Ros::default())
  }
}

impl rosidl_runtime_rs::Message for Xeno2Ros {
  type RmwMsg = super::msg::rmw::Xeno2Ros;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        steer_left: msg.steer_left,
        steer_right: msg.steer_right,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      steer_left: msg.steer_left,
      steer_right: msg.steer_right,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      steer_left: msg.steer_left,
      steer_right: msg.steer_right,
    }
  }
}



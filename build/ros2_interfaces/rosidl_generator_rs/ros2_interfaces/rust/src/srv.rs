#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};




// Corresponds to ros2_interfaces__srv__EnableMotors_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EnableMotors_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enable_all: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: Vec<u8>,

}



impl Default for EnableMotors_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::EnableMotors_Request::default())
  }
}

impl rosidl_runtime_rs::Message for EnableMotors_Request {
  type RmwMsg = super::srv::rmw::EnableMotors_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        enable_all: msg.enable_all,
        motor_id_list: msg.motor_id_list.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      enable_all: msg.enable_all,
        motor_id_list: msg.motor_id_list.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      enable_all: msg.enable_all,
      motor_id_list: msg.motor_id_list
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_interfaces__srv__EnableMotors_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EnableMotors_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enabled_motor_ids: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub failed_motor_ids: Vec<u8>,

}



impl Default for EnableMotors_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::EnableMotors_Response::default())
  }
}

impl rosidl_runtime_rs::Message for EnableMotors_Response {
  type RmwMsg = super::srv::rmw::EnableMotors_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        enabled_motor_ids: msg.enabled_motor_ids.into(),
        failed_motor_ids: msg.failed_motor_ids.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
        enabled_motor_ids: msg.enabled_motor_ids.as_slice().into(),
        failed_motor_ids: msg.failed_motor_ids.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      enabled_motor_ids: msg.enabled_motor_ids
          .into_iter()
          .collect(),
      failed_motor_ids: msg.failed_motor_ids
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_interfaces__srv__SetRunMode_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRunMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: Vec<u8>,

}



impl Default for SetRunMode_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetRunMode_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SetRunMode_Request {
  type RmwMsg = super::srv::rmw::SetRunMode_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        mode: msg.mode,
        motor_id_list: msg.motor_id_list.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      mode: msg.mode,
        motor_id_list: msg.motor_id_list.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      mode: msg.mode,
      motor_id_list: msg.motor_id_list
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_interfaces__srv__SetRunMode_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRunMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub applied_motor_ids: Vec<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub failed_motor_ids: Vec<u8>,

}



impl Default for SetRunMode_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SetRunMode_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SetRunMode_Response {
  type RmwMsg = super::srv::rmw::SetRunMode_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
        applied_motor_ids: msg.applied_motor_ids.into(),
        failed_motor_ids: msg.failed_motor_ids.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
        applied_motor_ids: msg.applied_motor_ids.as_slice().into(),
        failed_motor_ids: msg.failed_motor_ids.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
      applied_motor_ids: msg.applied_motor_ids
          .into_iter()
          .collect(),
      failed_motor_ids: msg.failed_motor_ids
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_interfaces__srv__SimpleMotorResult_Request

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SimpleMotorResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: Vec<u8>,

}



impl Default for SimpleMotorResult_Request {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SimpleMotorResult_Request::default())
  }
}

impl rosidl_runtime_rs::Message for SimpleMotorResult_Request {
  type RmwMsg = super::srv::rmw::SimpleMotorResult_Request;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_id_list: msg.motor_id_list.into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        motor_id_list: msg.motor_id_list.as_slice().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      motor_id_list: msg.motor_id_list
          .into_iter()
          .collect(),
    }
  }
}


// Corresponds to ros2_interfaces__srv__SimpleMotorResult_Response

// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SimpleMotorResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: std::string::String,

}



impl Default for SimpleMotorResult_Response {
  fn default() -> Self {
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::srv::rmw::SimpleMotorResult_Response::default())
  }
}

impl rosidl_runtime_rs::Message for SimpleMotorResult_Response {
  type RmwMsg = super::srv::rmw::SimpleMotorResult_Response;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        success: msg.success,
        message: msg.message.as_str().into(),
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
      success: msg.success,
        message: msg.message.as_str().into(),
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      success: msg.success,
      message: msg.message.to_string(),
    }
  }
}






#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__EnableMotors() -> *const std::ffi::c_void;
}

// Corresponds to ros2_interfaces__srv__EnableMotors
#[allow(missing_docs, non_camel_case_types)]
pub struct EnableMotors;

impl rosidl_runtime_rs::Service for EnableMotors {
    type Request = EnableMotors_Request;
    type Response = EnableMotors_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__EnableMotors() }
    }
}




#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__SetRunMode() -> *const std::ffi::c_void;
}

// Corresponds to ros2_interfaces__srv__SetRunMode
#[allow(missing_docs, non_camel_case_types)]
pub struct SetRunMode;

impl rosidl_runtime_rs::Service for SetRunMode {
    type Request = SetRunMode_Request;
    type Response = SetRunMode_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__SetRunMode() }
    }
}




#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__SimpleMotorResult() -> *const std::ffi::c_void;
}

// Corresponds to ros2_interfaces__srv__SimpleMotorResult
#[allow(missing_docs, non_camel_case_types)]
pub struct SimpleMotorResult;

impl rosidl_runtime_rs::Service for SimpleMotorResult {
    type Request = SimpleMotorResult_Request;
    type Response = SimpleMotorResult_Response;

    fn get_type_support() -> *const std::ffi::c_void {
        // SAFETY: No preconditions for this function.
        unsafe { rosidl_typesupport_c__get_service_type_support_handle__ros2_interfaces__srv__SimpleMotorResult() }
    }
}



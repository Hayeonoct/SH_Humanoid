#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__EnableMotors_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__EnableMotors_Request__init(msg: *mut EnableMotors_Request) -> bool;
    fn ros2_interfaces__srv__EnableMotors_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Request>, size: usize) -> bool;
    fn ros2_interfaces__srv__EnableMotors_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Request>);
    fn ros2_interfaces__srv__EnableMotors_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EnableMotors_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Request>) -> bool;
}

// Corresponds to ros2_interfaces__srv__EnableMotors_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EnableMotors_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub enable_all: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for EnableMotors_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__EnableMotors_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__EnableMotors_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EnableMotors_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EnableMotors_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EnableMotors_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/EnableMotors_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__EnableMotors_Request() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__EnableMotors_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__EnableMotors_Response__init(msg: *mut EnableMotors_Response) -> bool;
    fn ros2_interfaces__srv__EnableMotors_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Response>, size: usize) -> bool;
    fn ros2_interfaces__srv__EnableMotors_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Response>);
    fn ros2_interfaces__srv__EnableMotors_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<EnableMotors_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<EnableMotors_Response>) -> bool;
}

// Corresponds to ros2_interfaces__srv__EnableMotors_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct EnableMotors_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enabled_motor_ids: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub failed_motor_ids: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for EnableMotors_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__EnableMotors_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__EnableMotors_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for EnableMotors_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__EnableMotors_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for EnableMotors_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for EnableMotors_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/EnableMotors_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__EnableMotors_Response() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SetRunMode_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__SetRunMode_Request__init(msg: *mut SetRunMode_Request) -> bool;
    fn ros2_interfaces__srv__SetRunMode_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Request>, size: usize) -> bool;
    fn ros2_interfaces__srv__SetRunMode_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Request>);
    fn ros2_interfaces__srv__SetRunMode_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetRunMode_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Request>) -> bool;
}

// Corresponds to ros2_interfaces__srv__SetRunMode_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRunMode_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for SetRunMode_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__SetRunMode_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__SetRunMode_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetRunMode_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetRunMode_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetRunMode_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/SetRunMode_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SetRunMode_Request() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SetRunMode_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__SetRunMode_Response__init(msg: *mut SetRunMode_Response) -> bool;
    fn ros2_interfaces__srv__SetRunMode_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Response>, size: usize) -> bool;
    fn ros2_interfaces__srv__SetRunMode_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Response>);
    fn ros2_interfaces__srv__SetRunMode_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SetRunMode_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SetRunMode_Response>) -> bool;
}

// Corresponds to ros2_interfaces__srv__SetRunMode_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SetRunMode_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,


    // This member is not documented.
    #[allow(missing_docs)]
    pub applied_motor_ids: rosidl_runtime_rs::Sequence<u8>,


    // This member is not documented.
    #[allow(missing_docs)]
    pub failed_motor_ids: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for SetRunMode_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__SetRunMode_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__SetRunMode_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SetRunMode_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SetRunMode_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SetRunMode_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SetRunMode_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/SetRunMode_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SetRunMode_Response() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SimpleMotorResult_Request() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__SimpleMotorResult_Request__init(msg: *mut SimpleMotorResult_Request) -> bool;
    fn ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Request>, size: usize) -> bool;
    fn ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Request>);
    fn ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SimpleMotorResult_Request>, out_seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Request>) -> bool;
}

// Corresponds to ros2_interfaces__srv__SimpleMotorResult_Request
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SimpleMotorResult_Request {

    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id_list: rosidl_runtime_rs::Sequence<u8>,

}



impl Default for SimpleMotorResult_Request {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__SimpleMotorResult_Request__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__SimpleMotorResult_Request__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SimpleMotorResult_Request {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Request__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SimpleMotorResult_Request {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SimpleMotorResult_Request where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/SimpleMotorResult_Request";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SimpleMotorResult_Request() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SimpleMotorResult_Response() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__srv__SimpleMotorResult_Response__init(msg: *mut SimpleMotorResult_Response) -> bool;
    fn ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Response>, size: usize) -> bool;
    fn ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Response>);
    fn ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<SimpleMotorResult_Response>, out_seq: *mut rosidl_runtime_rs::Sequence<SimpleMotorResult_Response>) -> bool;
}

// Corresponds to ros2_interfaces__srv__SimpleMotorResult_Response
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]


// This struct is not documented.
#[allow(missing_docs)]

#[allow(non_camel_case_types)]
#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct SimpleMotorResult_Response {

    // This member is not documented.
    #[allow(missing_docs)]
    pub success: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub message: rosidl_runtime_rs::String,

}



impl Default for SimpleMotorResult_Response {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__srv__SimpleMotorResult_Response__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__srv__SimpleMotorResult_Response__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for SimpleMotorResult_Response {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__srv__SimpleMotorResult_Response__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for SimpleMotorResult_Response {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for SimpleMotorResult_Response where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/srv/SimpleMotorResult_Response";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__srv__SimpleMotorResult_Response() }
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



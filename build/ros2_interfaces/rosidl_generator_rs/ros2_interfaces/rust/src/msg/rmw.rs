#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperBodyCommand() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__msg__UpperBodyCommand__init(msg: *mut UpperBodyCommand) -> bool;
    fn ros2_interfaces__msg__UpperBodyCommand__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UpperBodyCommand>, size: usize) -> bool;
    fn ros2_interfaces__msg__UpperBodyCommand__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UpperBodyCommand>);
    fn ros2_interfaces__msg__UpperBodyCommand__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UpperBodyCommand>, out_seq: *mut rosidl_runtime_rs::Sequence<UpperBodyCommand>) -> bool;
}

// Corresponds to ros2_interfaces__msg__UpperBodyCommand
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Upper body command for 15 motors.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperBodyCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id: [u8; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub kp: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub kd: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub duration: f32,

}

impl UpperBodyCommand {
    /// Command modes
    pub const STOP: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSITION: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const VELOCITY: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const TORQUE: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const POSITION_VELOCITY: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const IMPEDANCE: u8 = 5;

}


impl Default for UpperBodyCommand {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__msg__UpperBodyCommand__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__msg__UpperBodyCommand__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UpperBodyCommand {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodyCommand__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodyCommand__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodyCommand__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UpperBodyCommand {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UpperBodyCommand where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/msg/UpperBodyCommand";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperBodyCommand() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperBodySystemState() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__msg__UpperBodySystemState__init(msg: *mut UpperBodySystemState) -> bool;
    fn ros2_interfaces__msg__UpperBodySystemState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UpperBodySystemState>, size: usize) -> bool;
    fn ros2_interfaces__msg__UpperBodySystemState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UpperBodySystemState>);
    fn ros2_interfaces__msg__UpperBodySystemState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UpperBodySystemState>, out_seq: *mut rosidl_runtime_rs::Sequence<UpperBodySystemState>) -> bool;
}

// Corresponds to ros2_interfaces__msg__UpperBodySystemState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Upper body system-level state.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperBodySystemState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub state: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub run_mode: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub ready_motor_count: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub enabled_motor_count: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub fault_motor_count: u8,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_connected: [bool; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub all_motors_enabled: bool,


    // This member is not documented.
    #[allow(missing_docs)]
    pub command_accepted: bool,

}

impl UpperBodySystemState {
    /// FSM states
    pub const POWER_OFF: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const DRIVER_INIT: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const READY: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ENABLING: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const ENABLED: u8 = 4;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const RUNNING: u8 = 5;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const FAULT: u8 = 6;

    /// Run mode values (SamHyun OD 0x7005)
    pub const MODE_IMPEDANCE: u8 = 0;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_POSITION: u8 = 1;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_VELOCITY: u8 = 2;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_TORQUE: u8 = 3;


    // This constant is not documented.
    #[allow(missing_docs)]
    pub const MODE_POSITION_ALT: u8 = 5;

}


impl Default for UpperBodySystemState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__msg__UpperBodySystemState__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__msg__UpperBodySystemState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UpperBodySystemState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodySystemState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodySystemState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperBodySystemState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UpperBodySystemState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UpperBodySystemState where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/msg/UpperBodySystemState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperBodySystemState() }
  }
}


#[link(name = "ros2_interfaces__rosidl_typesupport_c")]
extern "C" {
    fn rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperMotorState() -> *const std::ffi::c_void;
}

#[link(name = "ros2_interfaces__rosidl_generator_c")]
extern "C" {
    fn ros2_interfaces__msg__UpperMotorState__init(msg: *mut UpperMotorState) -> bool;
    fn ros2_interfaces__msg__UpperMotorState__Sequence__init(seq: *mut rosidl_runtime_rs::Sequence<UpperMotorState>, size: usize) -> bool;
    fn ros2_interfaces__msg__UpperMotorState__Sequence__fini(seq: *mut rosidl_runtime_rs::Sequence<UpperMotorState>);
    fn ros2_interfaces__msg__UpperMotorState__Sequence__copy(in_seq: &rosidl_runtime_rs::Sequence<UpperMotorState>, out_seq: *mut rosidl_runtime_rs::Sequence<UpperMotorState>) -> bool;
}

// Corresponds to ros2_interfaces__msg__UpperMotorState
#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]

/// Upper motor state feedback for 15 motors.

#[repr(C)]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperMotorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::rmw::Header,


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_ready: [bool; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub is_enabled: [bool; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub has_fault: [bool; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub motor_id: [u16; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub position: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub velocity: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub effort: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub error_code: [u16; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub temperature: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub voltage: [f32; 15],


    // This member is not documented.
    #[allow(missing_docs)]
    pub current: [f32; 15],

}



impl Default for UpperMotorState {
  fn default() -> Self {
    unsafe {
      let mut msg = std::mem::zeroed();
      if !ros2_interfaces__msg__UpperMotorState__init(&mut msg as *mut _) {
        panic!("Call to ros2_interfaces__msg__UpperMotorState__init() failed");
      }
      msg
    }
  }
}

impl rosidl_runtime_rs::SequenceAlloc for UpperMotorState {
  fn sequence_init(seq: &mut rosidl_runtime_rs::Sequence<Self>, size: usize) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperMotorState__Sequence__init(seq as *mut _, size) }
  }
  fn sequence_fini(seq: &mut rosidl_runtime_rs::Sequence<Self>) {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperMotorState__Sequence__fini(seq as *mut _) }
  }
  fn sequence_copy(in_seq: &rosidl_runtime_rs::Sequence<Self>, out_seq: &mut rosidl_runtime_rs::Sequence<Self>) -> bool {
    // SAFETY: This is safe since the pointer is guaranteed to be valid/initialized.
    unsafe { ros2_interfaces__msg__UpperMotorState__Sequence__copy(in_seq, out_seq as *mut _) }
  }
}

impl rosidl_runtime_rs::Message for UpperMotorState {
  type RmwMsg = Self;
  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> { msg_cow }
  fn from_rmw_message(msg: Self::RmwMsg) -> Self { msg }
}

impl rosidl_runtime_rs::RmwMessage for UpperMotorState where Self: Sized {
  const TYPE_NAME: &'static str = "ros2_interfaces/msg/UpperMotorState";
  fn get_type_support() -> *const std::ffi::c_void {
    // SAFETY: No preconditions for this function.
    unsafe { rosidl_typesupport_c__get_message_type_support_handle__ros2_interfaces__msg__UpperMotorState() }
  }
}



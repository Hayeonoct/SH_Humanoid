#[cfg(feature = "serde")]
use serde::{Deserialize, Serialize};



// Corresponds to ros2_interfaces__msg__UpperBodyCommand
/// Upper body command for 15 motors.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperBodyCommand {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UpperBodyCommand::default())
  }
}

impl rosidl_runtime_rs::Message for UpperBodyCommand {
  type RmwMsg = super::msg::rmw::UpperBodyCommand;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        command_mode: msg.command_mode,
        motor_id: msg.motor_id,
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
        kp: msg.kp,
        kd: msg.kd,
        duration: msg.duration,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      command_mode: msg.command_mode,
        motor_id: msg.motor_id,
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
        kp: msg.kp,
        kd: msg.kd,
      duration: msg.duration,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      command_mode: msg.command_mode,
      motor_id: msg.motor_id,
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
      kp: msg.kp,
      kd: msg.kd,
      duration: msg.duration,
    }
  }
}


// Corresponds to ros2_interfaces__msg__UpperBodySystemState
/// Upper body system-level state.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperBodySystemState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UpperBodySystemState::default())
  }
}

impl rosidl_runtime_rs::Message for UpperBodySystemState {
  type RmwMsg = super::msg::rmw::UpperBodySystemState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        state: msg.state,
        run_mode: msg.run_mode,
        ready_motor_count: msg.ready_motor_count,
        enabled_motor_count: msg.enabled_motor_count,
        fault_motor_count: msg.fault_motor_count,
        is_connected: msg.is_connected,
        all_motors_enabled: msg.all_motors_enabled,
        command_accepted: msg.command_accepted,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
      state: msg.state,
      run_mode: msg.run_mode,
      ready_motor_count: msg.ready_motor_count,
      enabled_motor_count: msg.enabled_motor_count,
      fault_motor_count: msg.fault_motor_count,
        is_connected: msg.is_connected,
      all_motors_enabled: msg.all_motors_enabled,
      command_accepted: msg.command_accepted,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      state: msg.state,
      run_mode: msg.run_mode,
      ready_motor_count: msg.ready_motor_count,
      enabled_motor_count: msg.enabled_motor_count,
      fault_motor_count: msg.fault_motor_count,
      is_connected: msg.is_connected,
      all_motors_enabled: msg.all_motors_enabled,
      command_accepted: msg.command_accepted,
    }
  }
}


// Corresponds to ros2_interfaces__msg__UpperMotorState
/// Upper motor state feedback for 15 motors.

#[cfg_attr(feature = "serde", derive(Deserialize, Serialize))]
#[derive(Clone, Debug, PartialEq, PartialOrd)]
pub struct UpperMotorState {

    // This member is not documented.
    #[allow(missing_docs)]
    pub header: std_msgs::msg::Header,


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
    <Self as rosidl_runtime_rs::Message>::from_rmw_message(super::msg::rmw::UpperMotorState::default())
  }
}

impl rosidl_runtime_rs::Message for UpperMotorState {
  type RmwMsg = super::msg::rmw::UpperMotorState;

  fn into_rmw_message(msg_cow: std::borrow::Cow<'_, Self>) -> std::borrow::Cow<'_, Self::RmwMsg> {
    match msg_cow {
      std::borrow::Cow::Owned(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Owned(msg.header)).into_owned(),
        is_ready: msg.is_ready,
        is_enabled: msg.is_enabled,
        has_fault: msg.has_fault,
        motor_id: msg.motor_id,
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
        error_code: msg.error_code,
        temperature: msg.temperature,
        voltage: msg.voltage,
        current: msg.current,
      }),
      std::borrow::Cow::Borrowed(msg) => std::borrow::Cow::Owned(Self::RmwMsg {
        header: std_msgs::msg::Header::into_rmw_message(std::borrow::Cow::Borrowed(&msg.header)).into_owned(),
        is_ready: msg.is_ready,
        is_enabled: msg.is_enabled,
        has_fault: msg.has_fault,
        motor_id: msg.motor_id,
        position: msg.position,
        velocity: msg.velocity,
        effort: msg.effort,
        error_code: msg.error_code,
        temperature: msg.temperature,
        voltage: msg.voltage,
        current: msg.current,
      })
    }
  }

  fn from_rmw_message(msg: Self::RmwMsg) -> Self {
    Self {
      header: std_msgs::msg::Header::from_rmw_message(msg.header),
      is_ready: msg.is_ready,
      is_enabled: msg.is_enabled,
      has_fault: msg.has_fault,
      motor_id: msg.motor_id,
      position: msg.position,
      velocity: msg.velocity,
      effort: msg.effort,
      error_code: msg.error_code,
      temperature: msg.temperature,
      voltage: msg.voltage,
      current: msg.current,
    }
  }
}



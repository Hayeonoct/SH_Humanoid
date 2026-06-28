# Upper body system-level state.
std_msgs/Header header

# FSM states
uint8 POWER_OFF=0
uint8 DRIVER_INIT=1
uint8 READY=2
uint8 ENABLING=3
uint8 ENABLED=4
uint8 RUNNING=5
uint8 FAULT=6

# Run mode values (SamHyun OD 0x7005)
uint8 MODE_IMPEDANCE=0
uint8 MODE_POSITION=1
uint8 MODE_VELOCITY=2
uint8 MODE_TORQUE=3
uint8 MODE_POSITION_ALT=5

uint8 state
uint8 run_mode
uint8 ready_motor_count
uint8 enabled_motor_count
uint8 fault_motor_count
bool[15] is_connected
bool all_motors_enabled
bool command_accepted

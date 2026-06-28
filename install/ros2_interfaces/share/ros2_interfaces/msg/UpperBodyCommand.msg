# Upper body command for 15 motors.
std_msgs/Header header

# Command modes
uint8 STOP=0
uint8 POSITION=1
uint8 VELOCITY=2
uint8 TORQUE=3
uint8 POSITION_VELOCITY=4
uint8 IMPEDANCE=5

uint8 command_mode
uint8[15] motor_id

float32[15] position
float32[15] velocity
float32[15] effort

float32[15] kp
float32[15] kd

float32 duration

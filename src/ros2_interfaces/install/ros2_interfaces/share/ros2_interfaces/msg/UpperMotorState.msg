# Upper motor state feedback for 15 motors.
std_msgs/Header header

bool[15] is_ready
bool[15] is_enabled
bool[15] has_fault
uint16[15] motor_id

float32[15] position
float32[15] velocity
float32[15] effort

uint16[15] error_code
float32[15] temperature
float32[15] voltage
float32[15] current

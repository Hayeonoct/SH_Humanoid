#include <memory>
#include <unordered_map>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"
#include "ros2_interfaces/msg/upper_motor_state.hpp"

class JointStateBridge : public rclcpp::Node
{
public:
    JointStateBridge()
    : Node("joint_state_bridge")
    {
        joint_pub_ =
            create_publisher<sensor_msgs::msg::JointState>(
                "/joint_states", 10);

        motor_sub_ =
            create_subscription<ros2_interfaces::msg::UpperMotorState>(
                "/upper_body/motor_states",
                10,
                std::bind(
                    &JointStateBridge::motorStateCallback,
                    this,
                    std::placeholders::_1));

        joint_msg_.name =
        {
            "joint1", "joint2", "joint3", "joint4", "joint5",
            "joint6", "joint7", "joint8", "joint9", "joint10",
            "joint11", "joint12", "joint13", "joint14", "Revolute 15"
        };

        joint_msg_.position.resize(15, 0.0);
        joint_msg_.velocity.resize(15, 0.0);
        joint_msg_.effort.resize(15, 0.0);

        motor_to_joint_[51]  = 0;
        motor_to_joint_[32]  = 1;
        motor_to_joint_[33]  = 2;
        motor_to_joint_[31]  = 3;
        motor_to_joint_[35]  = 4;
        motor_to_joint_[36]  = 5;
        motor_to_joint_[37]  = 6;
        motor_to_joint_[34]  = 7;
        motor_to_joint_[113] = 8;
        motor_to_joint_[125] = 9;
        motor_to_joint_[52]  = 10;
        motor_to_joint_[105] = 11;
        motor_to_joint_[115] = 12;
        motor_to_joint_[57]  = 13;
        motor_to_joint_[0]   = 14;

        // 10Hz 타이머 — 값 갱신과 무관하게 항상 최신 stamp로 퍼블리시
        timer_ = create_wall_timer(
            std::chrono::milliseconds(100),
            std::bind(&JointStateBridge::publishJointState, this));

        RCLCPP_INFO(get_logger(), "Joint State Bridge Started");
    }

private:

    // 모터 값만 업데이트, publish는 타이머에 맡김
    void motorStateCallback(
        const ros2_interfaces::msg::UpperMotorState::SharedPtr msg)
    {
        for (size_t i = 0; i < msg->motor_id.size(); ++i)
        {
            uint16_t id = msg->motor_id[i];

            auto it = motor_to_joint_.find(id);
            if (it == motor_to_joint_.end())
            {
                continue;  // 없는 ID는 건너뜀
            }

            size_t joint_index = it->second;

            double sign_multiplier = 1.0;
            switch (joint_index)
            {
                case 0:   // joint1  (오른팔)
                case 4:   // joint5  (오른팔)
                case 5:   // joint6  (오른팔)
                case 7:   // joint8  (왼팔)
                case 9:   // joint10 (왼팔)
                case 12:  // joint13 (왼팔)
                    sign_multiplier = -1.0;
                    break;
                default:
                    sign_multiplier = 1.0;
                    break;
            }

            joint_msg_.position[joint_index] = msg->position[i] * sign_multiplier;
            joint_msg_.velocity[joint_index] = msg->velocity[i] * sign_multiplier;
            joint_msg_.effort[joint_index]   = msg->effort[i]   * sign_multiplier;
        }
    }

    // 타이머 콜백 — stamp를 항상 현재 시각으로 찍어서 퍼블리시
    void publishJointState()
    {
        joint_msg_.header.stamp    = now();
        joint_msg_.header.frame_id = "";
        joint_pub_->publish(joint_msg_);

        RCLCPP_INFO_THROTTLE(
            get_logger(),
            *get_clock(),
            1000,
            "J1:%.3f J2:%.3f J3:%.3f J4:%.3f J5:%.3f J6:%.3f J7:%.3f | "
            "J8:%.3f J9:%.3f J10:%.3f J11:%.3f J12:%.3f J13:%.3f J14:%.3f | "
            "Rev15:%.3f",
            joint_msg_.position[0],
            joint_msg_.position[1],
            joint_msg_.position[2],
            joint_msg_.position[3],
            joint_msg_.position[4],
            joint_msg_.position[5],
            joint_msg_.position[6],
            joint_msg_.position[7],
            joint_msg_.position[8],
            joint_msg_.position[9],
            joint_msg_.position[10],
            joint_msg_.position[11],
            joint_msg_.position[12],
            joint_msg_.position[13],
            joint_msg_.position[14]);
    }

    rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr joint_pub_;
    rclcpp::Subscription<ros2_interfaces::msg::UpperMotorState>::SharedPtr motor_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    sensor_msgs::msg::JointState joint_msg_;
    std::unordered_map<uint16_t, size_t> motor_to_joint_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<JointStateBridge>());
    rclcpp::shutdown();
    return 0;
}
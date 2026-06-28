#include <memory>
#include <cstdint>

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "ros2_interfaces/msg/upper_body_command.hpp"

using FollowJT = control_msgs::action::FollowJointTrajectory;
using GoalHandle = rclcpp_action::ServerGoalHandle<FollowJT>;

class TrajectoryBridge : public rclcpp::Node
{
public:
    TrajectoryBridge()
        : Node("trajectory_bridge_node")
    {
        server_ =
            rclcpp_action::create_server<FollowJT>(
                this,
                "/right_arm_controller/follow_joint_trajectory",

                std::bind(
                    &TrajectoryBridge::goalCallback,
                    this,
                    std::placeholders::_1,
                    std::placeholders::_2),

                std::bind(
                    &TrajectoryBridge::cancelCallback,
                    this,
                    std::placeholders::_1),

                std::bind(
                    &TrajectoryBridge::acceptedCallback,
                    this,
                    std::placeholders::_1));

        command_pub_ =
            create_publisher<ros2_interfaces::msg::UpperBodyCommand>(
                "/upper_body/command",
                10);

        RCLCPP_INFO(get_logger(), "Trajectory Bridge Started");
    }

private:

    rclcpp_action::Server<FollowJT>::SharedPtr right_server_;
    rclcpp_action::Server<FollowJT>::SharedPtr left_server_;

    rclcpp::Publisher<
        ros2_interfaces::msg::UpperBodyCommand>::SharedPtr command_pub_;

    rclcpp_action::GoalResponse goalCallback(
        const rclcpp_action::GoalUUID &,
        std::shared_ptr<const FollowJT::Goal> goal)
    {
        RCLCPP_INFO(
            get_logger(),
            "Received trajectory (%zu points)",
            goal->trajectory.points.size());

        RCLCPP_INFO(get_logger(), "==============================");
        RCLCPP_INFO(get_logger(), "Joint Names");
        RCLCPP_INFO(get_logger(), "==============================");

        for (const auto &name : goal->trajectory.joint_names)
        {
            RCLCPP_INFO(get_logger(), "%s", name.c_str());
        }

        const uint8_t motor_id_table[15] =
        {
            // joint1 ~ joint7  -> axis8 ~ axis14 (오른팔)
            51,   // joint1
            32,   // joint2
            33,   // joint3
            31,   // joint4
            35,   // joint5
            36,   // joint6
            37,   // joint7

            // joint8 ~ joint14 -> axis1 ~ axis7 (왼팔)
            34,   // joint8
            113,  // joint9
            125,  // joint10
            52,   // joint11
            105,  // joint12
            115,  // joint13
            57,   // joint14

            // Head
            0
        };

        for (size_t p = 0; p < goal->trajectory.points.size(); ++p)
        {
            const auto &point = goal->trajectory.points[p];

            ros2_interfaces::msg::UpperBodyCommand cmd;

            cmd.command_mode =
                ros2_interfaces::msg::UpperBodyCommand::POSITION;

            for (size_t i = 0; i < 15; ++i)
            {
                cmd.motor_id[i] = motor_id_table[i];

                cmd.position[i] = 0.0;
                cmd.velocity[i] = 0.0;
                cmd.effort[i] = 0.0;

                cmd.kp[i] = 0.0;
                cmd.kd[i] = 0.0;
            }

            for (size_t i = 0;
                 i < point.positions.size() && i < 15;
                 ++i)
            {
                cmd.position[i] = point.positions[i];

                if (i < point.velocities.size())
                    cmd.velocity[i] = point.velocities[i];
            }

            cmd.duration =
                point.time_from_start.sec +
                point.time_from_start.nanosec * 1e-9;

            cmd.header.stamp = this->now();
            cmd.header.frame_id = "upper_body_link";

            RCLCPP_INFO(
                get_logger(),
                "Publishing point %zu / %zu",
                p + 1,
                goal->trajectory.points.size());

            command_pub_->publish(cmd);

            RCLCPP_INFO(
                get_logger(),
                "========== Point %zu ==========",
                p);

            RCLCPP_INFO(
                get_logger(),
                "duration : %.3f",
                cmd.duration);

            for (size_t i = 0;
                 i < point.positions.size() && i < 15;
                 ++i)
            {
                RCLCPP_INFO(
                    get_logger(),
                    "motor %3d (%s)"
                    "  pos=%8.4f"
                    "  vel=%8.4f",
                    cmd.motor_id[i],
                    goal->trajectory.joint_names[i].c_str(),
                    cmd.position[i],
                    cmd.velocity[i]);
            }

            RCLCPP_INFO(
                get_logger(),
                "UpperBodyCommand Published");
        }

        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse cancelCallback(
        const std::shared_ptr<GoalHandle>)
    {
        return rclcpp_action::CancelResponse::ACCEPT;
    }

    void acceptedCallback(
        const std::shared_ptr<GoalHandle> goal_handle)
    {
        RCLCPP_INFO(get_logger(), "Goal accepted!");

        auto result =
            std::make_shared<FollowJT::Result>();

        goal_handle->succeed(result);

        RCLCPP_INFO(get_logger(), "Goal finished!");
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    rclcpp::spin(
        std::make_shared<TrajectoryBridge>());

    rclcpp::shutdown();

    return 0;
}
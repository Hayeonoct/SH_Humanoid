#include <memory>
#include <array>
#include <mutex>
#include <thread>
#include <chrono>
#include <cstdint>
#include <vector>
#include <algorithm> //추가

#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"

#include "control_msgs/action/follow_joint_trajectory.hpp"
#include "trajectory_msgs/msg/joint_trajectory_point.hpp"
#include "ros2_interfaces/msg/upper_body_command.hpp"

using FollowJT = control_msgs::action::FollowJointTrajectory;
using GoalHandle = rclcpp_action::ServerGoalHandle<FollowJT>;

class TrajectoryBridge : public rclcpp::Node
{
public:

    TrajectoryBridge()
    : Node("trajectory_bridge_node")
    {
            // 콜백 그룹 생성
        timer_cb_group_ =
            create_callback_group(
                rclcpp::CallbackGroupType::MutuallyExclusive);

        action_cb_group_ =
            create_callback_group(
                rclcpp::CallbackGroupType::MutuallyExclusive);
        

        right_server_ =
            rclcpp_action::create_server<FollowJT>(
                this,
                "/right_arm_controller/follow_joint_trajectory",
                std::bind(&TrajectoryBridge::goalCallbackRight, this,
                    std::placeholders::_1, std::placeholders::_2),
                std::bind(&TrajectoryBridge::cancelCallback, this,
                    std::placeholders::_1),
                std::bind(&TrajectoryBridge::acceptedCallbackRight, this,
                    std::placeholders::_1),
                rcl_action_server_get_default_options(),
                action_cb_group_);  // 추가

        left_server_ =
            rclcpp_action::create_server<FollowJT>(
                this,
                "/left_arm_controller/follow_joint_trajectory",
                std::bind(&TrajectoryBridge::goalCallbackLeft, this,
                    std::placeholders::_1, std::placeholders::_2),
                std::bind(&TrajectoryBridge::cancelCallback, this,
                    std::placeholders::_1),
                std::bind(&TrajectoryBridge::acceptedCallbackLeft, this,
                    std::placeholders::_1),
                rcl_action_server_get_default_options(),
                action_cb_group_);  // 추가

        command_pub_ =
            create_publisher<ros2_interfaces::msg::UpperBodyCommand>(
                "/upper_body/command", 10);

        current_position_.fill(0.0f);
        current_velocity_.fill(0.0f);

        RCLCPP_INFO(get_logger(), "Trajectory Bridge Started");
    }

private:

    rclcpp_action::Server<FollowJT>::SharedPtr right_server_;
    rclcpp_action::Server<FollowJT>::SharedPtr left_server_;

    rclcpp::Publisher
        <ros2_interfaces::msg::UpperBodyCommand>::SharedPtr command_pub_;

    std::mutex mutex_;

    std::array<float, 15> current_position_;
    std::array<float, 15> current_velocity_;

    rclcpp::TimerBase::SharedPtr exec_timer_;
    std::vector<trajectory_msgs::msg::JointTrajectoryPoint> point_queue_;
    size_t current_point_idx_ = 0;
    rclcpp::Time traj_start_time_;
    bool is_right_arm_ = true;
    bool is_running_ = false;  // 추가
    std::shared_ptr<GoalHandle> active_goal_handle_;
    // 여기에 추가
    rclcpp::CallbackGroup::SharedPtr timer_cb_group_;
    rclcpp::CallbackGroup::SharedPtr action_cb_group_;

    const uint16_t motor_id_table_[15] =
    {
        34, 113, 125, 52, 105, 115, 57,  // axis1~7  (왼팔)
        51,  32,  33, 31,  35,  36, 37,  // axis8~14 (오른팔)
        0                                 // head
    };

    // -------------------------------------------------------

    rclcpp_action::GoalResponse goalCallbackRight(
        const rclcpp_action::GoalUUID &,
        std::shared_ptr<const FollowJT::Goal>)
    {
        RCLCPP_INFO(get_logger(), "Right arm goal received");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::GoalResponse goalCallbackLeft(
        const rclcpp_action::GoalUUID &,
        std::shared_ptr<const FollowJT::Goal>)
    {
        RCLCPP_INFO(get_logger(), "Left arm goal received");
        return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    }

    rclcpp_action::CancelResponse cancelCallback(
        const std::shared_ptr<GoalHandle> goal_handle)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        RCLCPP_INFO(get_logger(), "Goal cancelled");

        is_running_ = false;
        point_queue_.clear();
        current_point_idx_ = 0;

        auto result = std::make_shared<FollowJT::Result>();
        result->error_code = FollowJT::Result::SUCCESSFUL;
        result->error_string = "Trajectory cancelled";

        if (goal_handle && goal_handle->is_active())
            goal_handle->canceled(result);

        if (active_goal_handle_ == goal_handle)
            active_goal_handle_ = nullptr;

        return rclcpp_action::CancelResponse::ACCEPT;
    }

        double pointTime( // 추가
        const trajectory_msgs::msg::JointTrajectoryPoint &point)
    {
        return point.time_from_start.sec +
            point.time_from_start.nanosec * 1e-9;
    }
        void acceptedCallbackRight(
        const std::shared_ptr<GoalHandle> goal_handle)
    {
        startTrajectory(goal_handle, true);
    }

    void acceptedCallbackLeft(
        const std::shared_ptr<GoalHandle> goal_handle)
    {
        startTrajectory(goal_handle, false);
    }

    // -------------------------------------------------------

    void startTrajectory(
        const std::shared_ptr<GoalHandle> goal_handle,
        bool is_right)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (exec_timer_)
            exec_timer_->cancel();

        auto goal = goal_handle->get_goal();

        for (size_t i = 0; i < goal->trajectory.joint_names.size(); ++i)
        {
            RCLCPP_INFO(get_logger(),
                "trajectory.joint_names[%zu] = %s",
                i,
                goal->trajectory.joint_names[i].c_str());
        }

        point_queue_        = goal->trajectory.points;
        current_point_idx_  = 0;
        is_right_arm_       = is_right;
        traj_start_time_    = now();
        active_goal_handle_ = goal_handle;
        is_running_         = true;  // 추가

        RCLCPP_INFO(get_logger(),
            "%s trajectory started — %zu points",
            is_right ? "RIGHT" : "LEFT",
            point_queue_.size());

        // 50Hz = 20ms
        exec_timer_ = create_wall_timer(
            std::chrono::milliseconds(20),
            std::bind(&TrajectoryBridge::onTimer, this),
            timer_cb_group_);  // 추가
    }

    // -------------------------------------------------------

    void onTimer()
    {
        std::lock_guard<std::mutex> lock(mutex_);

        if (!is_running_ || point_queue_.empty())
            return;

        double elapsed = (now() - traj_start_time_).seconds();
        double last_time = pointTime(point_queue_.back());

        // trajectory 끝
        if (elapsed >= last_time)
        {
            updatePosition(point_queue_.back(), is_right_arm_);
            publishCommand(0.02);

            is_running_ = false;
            point_queue_.clear();
            current_point_idx_ = 0;

            if (active_goal_handle_)
            {
                auto result = std::make_shared<FollowJT::Result>();
                result->error_code = FollowJT::Result::SUCCESSFUL;
                result->error_string = "Trajectory finished successfully";

                if (active_goal_handle_->is_active())
                    active_goal_handle_->succeed(result);

                active_goal_handle_ = nullptr;

                RCLCPP_INFO(get_logger(), "%s trajectory finished",
                    is_right_arm_ ? "RIGHT" : "LEFT");
            }
            
            return;
        }

        // 현재 elapsed가 포함되는 구간 찾기
        while (current_point_idx_ + 1 < point_queue_.size() &&
            elapsed >= pointTime(point_queue_[current_point_idx_ + 1]))
        {
            current_point_idx_++;
        }

        if (current_point_idx_ + 1 >= point_queue_.size())
            return;

        const auto &p0 = point_queue_[current_point_idx_];
        const auto &p1 = point_queue_[current_point_idx_ + 1];

        double t0 = pointTime(p0);
        double t1 = pointTime(p1);
        double segment_dt = t1 - t0;

        double ratio = 0.0;
        if (segment_dt > 1e-6)
            ratio = (elapsed - t0) / segment_dt;

        updatePositionInterpolated(
            p0,
            p1,
            ratio,
            segment_dt,
            is_right_arm_);

        publishCommand(0.02);

        RCLCPP_INFO_THROTTLE(
            get_logger(),
            *get_clock(),
            500,
            "%s interp idx=%zu/%zu elapsed=%.3f ratio=%.2f",
            is_right_arm_ ? "RIGHT" : "LEFT",
            current_point_idx_,
            point_queue_.size(),
            elapsed,
            ratio);
    }
    // -------------------------------------------------------

    void updatePositionInterpolated( //추가
        const trajectory_msgs::msg::JointTrajectoryPoint &p0,
        const trajectory_msgs::msg::JointTrajectoryPoint &p1,
        double ratio,
        double dt,
        bool is_right)
    {
        ratio = std::clamp(ratio, 0.0, 1.0);

        size_t n = std::min(p0.positions.size(), p1.positions.size());
        n = std::min(n, static_cast<size_t>(7));

        for (size_t i = 0; i < n; ++i)
        {
            double pos0 = p0.positions[i];
            double pos1 = p1.positions[i];

            double pos = pos0 + ratio * (pos1 - pos0);
            double vel = 0.0;

            if (dt > 1e-6)
                vel = (pos1 - pos0) / dt;

            if (is_right)
            {
                double sign = (i == 0 || i == 4 || i == 5) ? -1.0 : 1.0;
                current_position_[7 + i] = pos * sign;
                current_velocity_[7 + i] = vel * sign;
            }
            else
            {
                double sign = (i == 0 || i == 2 || i == 5) ? -1.0 : 1.0;
                current_position_[i] = pos * sign;
                current_velocity_[i] = vel * sign;
            }
        }
    }
    void updatePosition(
        const trajectory_msgs::msg::JointTrajectoryPoint &point,
        bool is_right)
    {
        if (is_right)
        {
            for (size_t i = 0; i < point.positions.size() && i < 7; ++i)
            {
                double sign = (i == 0 || i == 4 || i == 5) ? -1.0 : 1.0;
                current_position_[7 + i] = point.positions[i] * sign;
                if (i < point.velocities.size())
                    current_velocity_[7 + i] = point.velocities[i] * sign;
            }
        }
        else
        {
            for (size_t i = 0; i < point.positions.size() && i < 7; ++i)
            {
                double sign = (i == 0 || i == 2 || i == 5) ? -1.0 : 1.0;
                current_position_[i] = point.positions[i] * sign;
                if (i < point.velocities.size())
                    current_velocity_[i] = point.velocities[i] * sign;
            }
        }
    }

    // -------------------------------------------------------

    void publishCommand(double dt)
    {
        ros2_interfaces::msg::UpperBodyCommand cmd;

        cmd.header.stamp    = now();
        cmd.header.frame_id = "upper_body_link";
        cmd.command_mode    = ros2_interfaces::msg::UpperBodyCommand::POSITION;
        cmd.duration        = dt;

        for (size_t i = 0; i < 15; ++i)
        {
            cmd.motor_id[i] = motor_id_table_[i];
            cmd.position[i] = current_position_[i];
            cmd.velocity[i] = current_velocity_[i];
            cmd.effort[i]   = 0.0f;
            cmd.kp[i]       = 0.0f;
            cmd.kd[i]       = 0.0f;
        }

        command_pub_->publish(cmd);

        RCLCPP_INFO(
            get_logger(),
            "[CMD] dt=%.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n"
            "ID:%3d Pos:%7.3f\n\n",
            dt,

            cmd.motor_id[0],  cmd.position[0],
            cmd.motor_id[1],  cmd.position[1],
            cmd.motor_id[2],  cmd.position[2],
            cmd.motor_id[3],  cmd.position[3],
            cmd.motor_id[4],  cmd.position[4],
            cmd.motor_id[5],  cmd.position[5],
            cmd.motor_id[6],  cmd.position[6],
            cmd.motor_id[7],  cmd.position[7],
            cmd.motor_id[8],  cmd.position[8],
            cmd.motor_id[9],  cmd.position[9],
            cmd.motor_id[10], cmd.position[10],
            cmd.motor_id[11], cmd.position[11],
            cmd.motor_id[12], cmd.position[12],
            cmd.motor_id[13], cmd.position[13],
            cmd.motor_id[14], cmd.position[14]);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TrajectoryBridge>();

    // 싱글 스레드 대신 멀티 스레드 executor
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
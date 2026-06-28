#include <memory>
#include <array>
#include <mutex>
#include <chrono>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <functional>

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
                action_cb_group_);

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
                action_cb_group_);

        command_pub_ =
            create_publisher<ros2_interfaces::msg::UpperBodyCommand>(
                "/upper_body/command", 10);

        current_position_.fill(0.0f);
        current_velocity_.fill(0.0f);

        // 타이머는 생성자에서 한 번만 생성.
        // CONTROL_PERIOD_MS = 20이면 50Hz.
        exec_timer_ = create_wall_timer(
            std::chrono::milliseconds(CONTROL_PERIOD_MS),
            std::bind(&TrajectoryBridge::onTimer, this),
            timer_cb_group_);

        RCLCPP_INFO(get_logger(), "Trajectory Bridge Started");
    }

private:
    // -------------------------------------------------------
    // 제어 주기 설정
    // -------------------------------------------------------

    static constexpr int CONTROL_PERIOD_MS = 20;
    static constexpr double CONTROL_PERIOD_SEC = 0.02;

    // 200Hz로 바꾸고 싶으면 위 두 값을 아래처럼 변경:
    // static constexpr int CONTROL_PERIOD_MS = 5;
    // static constexpr double CONTROL_PERIOD_SEC = 0.005;

    // -------------------------------------------------------
    // 팔별 상태
    // -------------------------------------------------------

    struct ArmState
    {
        std::vector<trajectory_msgs::msg::JointTrajectoryPoint> point_queue;
        std::vector<std::string> joint_names;

        size_t current_point_idx = 0;
        rclcpp::Time traj_start_time;

        bool is_running = false;
        bool is_right = false;

        std::shared_ptr<GoalHandle> active_goal_handle;
    };

    ArmState right_arm_;
    ArmState left_arm_;

    // -------------------------------------------------------
    // ROS 객체
    // -------------------------------------------------------

    rclcpp_action::Server<FollowJT>::SharedPtr right_server_;
    rclcpp_action::Server<FollowJT>::SharedPtr left_server_;

    rclcpp::Publisher<ros2_interfaces::msg::UpperBodyCommand>::SharedPtr
        command_pub_;

    rclcpp::TimerBase::SharedPtr exec_timer_;

    rclcpp::CallbackGroup::SharedPtr timer_cb_group_;
    rclcpp::CallbackGroup::SharedPtr action_cb_group_;

    // -------------------------------------------------------
    // 공유 상태
    // -------------------------------------------------------

    std::mutex mutex_;

    std::array<float, 15> current_position_;
    std::array<float, 15> current_velocity_;

    // command 배열 기준:
    // index 0~6  = axis1~7  = 왼팔
    // index 7~13 = axis8~14 = 오른팔
    // index 14   = head
    const uint16_t motor_id_table_[15] =
    {
        34, 113, 125, 52, 105, 115, 57,  // axis1~7  왼팔
        51,  32,  33, 31,  35,  36, 37,  // axis8~14 오른팔
        0                                // head
    };

    // MoveIt joint 이름 → /upper_body/command 배열 index
    // MoveIt: joint1~7 = 오른팔, joint8~14 = 왼팔
    const std::unordered_map<std::string, size_t> joint_to_cmd_index_ =
    {
        // 오른팔: MoveIt joint1~7 → axis8~14 → cmd index 7~13
        {"joint1",   7},
        {"joint2",   8},
        {"joint3",   9},
        {"joint4",  10},
        {"joint5",  11},
        {"joint6",  12},
        {"joint7",  13},

        // 왼팔: MoveIt joint8~14 → axis1~7 → cmd index 0~6
        {"joint8",   0},
        {"joint9",   1},
        {"joint10",  2},
        {"joint11",  3},
        {"joint12",  4},
        {"joint13",  5},
        {"joint14",  6}
    };

    // -------------------------------------------------------
    // Helper
    // -------------------------------------------------------

    double pointTime(
        const trajectory_msgs::msg::JointTrajectoryPoint &point) const
    {
        return point.time_from_start.sec +
               point.time_from_start.nanosec * 1e-9;
    }

    double signForCmdIndex(size_t cmd_idx) const
    {
        // 왼팔 axis1~7 → cmd index 0~6
        if (cmd_idx < 7)
        {
            // 기존 코드 기준:
            // 왼팔 axis1, axis3, axis6 부호 반전
            return (cmd_idx == 0 || cmd_idx == 2 || cmd_idx == 5)
                ? -1.0
                : 1.0;
        }

        // 오른팔 axis8~14 → cmd index 7~13
        if (cmd_idx < 14)
        {
            size_t axis_idx = cmd_idx - 7;

            // 기존 코드 기준:
            // 오른팔 axis8, axis12, axis13 부호 반전
            return (axis_idx == 0 || axis_idx == 4 || axis_idx == 5)
                ? -1.0
                : 1.0;
        }

        // head 등
        return 1.0;
    }

    // -------------------------------------------------------
    // Action goal callbacks
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

        RCLCPP_INFO(get_logger(), "Goal cancel requested");

        cancelArmIfMatched(right_arm_, goal_handle);
        cancelArmIfMatched(left_arm_, goal_handle);

        return rclcpp_action::CancelResponse::ACCEPT;
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
    // Trajectory control
    // -------------------------------------------------------

    void startTrajectory(
        const std::shared_ptr<GoalHandle> goal_handle,
        bool is_right)
    {
        std::lock_guard<std::mutex> lock(mutex_);

        ArmState &arm = is_right ? right_arm_ : left_arm_;

        // 같은 팔에 기존 goal이 살아 있으면 중단 처리
        if (arm.active_goal_handle && arm.active_goal_handle->is_active())
        {
            auto result = std::make_shared<FollowJT::Result>();
            result->error_code = FollowJT::Result::INVALID_GOAL;
            result->error_string = "Preempted by new trajectory goal";

            arm.active_goal_handle->abort(result);
            arm.active_goal_handle = nullptr;
        }

        auto goal = goal_handle->get_goal();

        if (goal->trajectory.points.empty())
        {
            auto result = std::make_shared<FollowJT::Result>();
            result->error_code = FollowJT::Result::INVALID_GOAL;
            result->error_string = "Empty trajectory";

            if (goal_handle->is_active())
                goal_handle->abort(result);

            RCLCPP_WARN(get_logger(),
                "%s received empty trajectory",
                is_right ? "RIGHT" : "LEFT");

            return;
        }

        arm.joint_names        = goal->trajectory.joint_names;
        arm.point_queue        = goal->trajectory.points;
        arm.current_point_idx  = 0;
        arm.traj_start_time    = now();
        arm.is_running         = true;
        arm.is_right           = is_right;
        arm.active_goal_handle = goal_handle;

        for (size_t i = 0; i < arm.joint_names.size(); ++i)
        {
            RCLCPP_INFO(get_logger(),
                "%s trajectory.joint_names[%zu] = %s",
                is_right ? "RIGHT" : "LEFT",
                i,
                arm.joint_names[i].c_str());
        }

        RCLCPP_INFO(get_logger(),
            "%s trajectory started — %zu points",
            is_right ? "RIGHT" : "LEFT",
            arm.point_queue.size());
    }

    void cancelArmIfMatched(
        ArmState &arm,
        const std::shared_ptr<GoalHandle> goal_handle)
    {
        if (arm.active_goal_handle != goal_handle)
            return;

        arm.is_running = false;
        arm.point_queue.clear();
        arm.joint_names.clear();
        arm.current_point_idx = 0;

        auto result = std::make_shared<FollowJT::Result>();
        result->error_code = FollowJT::Result::SUCCESSFUL;
        result->error_string = "Trajectory cancelled";

        if (goal_handle && goal_handle->is_active())
            goal_handle->canceled(result);

        arm.active_goal_handle = nullptr;
    }

    // -------------------------------------------------------
    // Timer
    // -------------------------------------------------------

    void onTimer()
    {
        std::lock_guard<std::mutex> lock(mutex_);

        bool was_running =
            right_arm_.is_running || left_arm_.is_running;

        processArm(right_arm_);
        processArm(left_arm_);

        bool is_running_now =
            right_arm_.is_running || left_arm_.is_running;

        // was_running을 같이 보는 이유:
        // 이번 tick에서 trajectory가 끝났더라도 마지막 position을 한 번 publish하기 위함.
        if (was_running || is_running_now)
            publishCommand(CONTROL_PERIOD_SEC);
    }

    void processArm(ArmState &arm)
    {
        if (!arm.is_running || arm.point_queue.empty())
            return;

        double elapsed = (now() - arm.traj_start_time).seconds();
        double last_time = pointTime(arm.point_queue.back());

        // trajectory 끝
        if (elapsed >= last_time)
        {
            updatePosition(
                arm.point_queue.back(),
                arm.joint_names);

            arm.is_running = false;
            arm.point_queue.clear();
            arm.joint_names.clear();
            arm.current_point_idx = 0;

            if (arm.active_goal_handle)
            {
                auto result = std::make_shared<FollowJT::Result>();
                result->error_code = FollowJT::Result::SUCCESSFUL;
                result->error_string =
                    "Trajectory finished successfully";

                if (arm.active_goal_handle->is_active())
                    arm.active_goal_handle->succeed(result);

                arm.active_goal_handle = nullptr;

                RCLCPP_INFO(get_logger(),
                    "%s trajectory finished",
                    arm.is_right ? "RIGHT" : "LEFT");
            }

            return;
        }

        // 현재 elapsed가 포함되는 trajectory segment 찾기
        while (arm.current_point_idx + 1 < arm.point_queue.size() &&
               elapsed >= pointTime(
                   arm.point_queue[arm.current_point_idx + 1]))
        {
            arm.current_point_idx++;
        }

        if (arm.current_point_idx + 1 >= arm.point_queue.size())
            return;

        const auto &p0 = arm.point_queue[arm.current_point_idx];
        const auto &p1 = arm.point_queue[arm.current_point_idx + 1];

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
            arm.joint_names);

        RCLCPP_INFO_THROTTLE(
            get_logger(),
            *get_clock(),
            500,
            "%s interp idx=%zu/%zu elapsed=%.3f ratio=%.2f",
            arm.is_right ? "RIGHT" : "LEFT",
            arm.current_point_idx,
            arm.point_queue.size(),
            elapsed,
            ratio);
    }

    // -------------------------------------------------------
    // Position update
    // -------------------------------------------------------

    void updatePositionInterpolated(
        const trajectory_msgs::msg::JointTrajectoryPoint &p0,
        const trajectory_msgs::msg::JointTrajectoryPoint &p1,
        double ratio,
        double segment_dt,
        const std::vector<std::string> &joint_names)
    {
        ratio = std::clamp(ratio, 0.0, 1.0);

        size_t n = std::min({
            p0.positions.size(),
            p1.positions.size(),
            joint_names.size()
        });

        for (size_t traj_idx = 0; traj_idx < n; ++traj_idx)
        {
            const std::string &joint_name = joint_names[traj_idx];

            auto it = joint_to_cmd_index_.find(joint_name);
            if (it == joint_to_cmd_index_.end())
            {
                RCLCPP_WARN_THROTTLE(
                    get_logger(),
                    *get_clock(),
                    1000,
                    "Unknown joint name in trajectory: %s",
                    joint_name.c_str());
                continue;
            }

            size_t cmd_idx = it->second;

            double pos0 = p0.positions[traj_idx];
            double pos1 = p1.positions[traj_idx];

            double pos = pos0 + ratio * (pos1 - pos0);

            double vel = 0.0;
            if (segment_dt > 1e-6)
                vel = (pos1 - pos0) / segment_dt;

            double sign = signForCmdIndex(cmd_idx);

            current_position_[cmd_idx] =
                static_cast<float>(pos * sign);

            current_velocity_[cmd_idx] =
                static_cast<float>(vel * sign);
        }
    }

    void updatePosition(
        const trajectory_msgs::msg::JointTrajectoryPoint &point,
        const std::vector<std::string> &joint_names)
    {
        size_t n = std::min(
            point.positions.size(),
            joint_names.size());

        for (size_t traj_idx = 0; traj_idx < n; ++traj_idx)
        {
            const std::string &joint_name = joint_names[traj_idx];

            auto it = joint_to_cmd_index_.find(joint_name);
            if (it == joint_to_cmd_index_.end())
            {
                RCLCPP_WARN_THROTTLE(
                    get_logger(),
                    *get_clock(),
                    1000,
                    "Unknown joint name in trajectory: %s",
                    joint_name.c_str());
                continue;
            }

            size_t cmd_idx = it->second;
            double sign = signForCmdIndex(cmd_idx);

            current_position_[cmd_idx] =
                static_cast<float>(point.positions[traj_idx] * sign);

            if (traj_idx < point.velocities.size())
            {
                current_velocity_[cmd_idx] =
                    static_cast<float>(
                        point.velocities[traj_idx] * sign);
            }
            else
            {
                current_velocity_[cmd_idx] = 0.0f;
            }
        }
    }

    // -------------------------------------------------------
    // Publish
    // -------------------------------------------------------

    void publishCommand(double dt)
    {
        ros2_interfaces::msg::UpperBodyCommand cmd;

        cmd.header.stamp    = now();
        cmd.header.frame_id = "upper_body_link";
        cmd.command_mode    =
            ros2_interfaces::msg::UpperBodyCommand::POSITION;
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

        RCLCPP_INFO_THROTTLE(
            get_logger(),
            *get_clock(),
            1000,
            "[CMD] dt=%.3f | "
            "L: %.3f %.3f %.3f %.3f %.3f %.3f %.3f | "
            "R: %.3f %.3f %.3f %.3f %.3f %.3f %.3f | "
            "H: %.3f",
            dt,
            cmd.position[0],  cmd.position[1],  cmd.position[2],
            cmd.position[3],  cmd.position[4],  cmd.position[5],
            cmd.position[6],
            cmd.position[7],  cmd.position[8],  cmd.position[9],
            cmd.position[10], cmd.position[11], cmd.position[12],
            cmd.position[13],
            cmd.position[14]);
    }
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<TrajectoryBridge>();

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}
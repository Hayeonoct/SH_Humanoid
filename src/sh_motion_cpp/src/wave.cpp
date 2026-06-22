#include <rclcpp/rclcpp.hpp>
#include <moveit/move_group_interface/move_group_interface.hpp>

#include <thread>
#include <chrono>

int main(int argc, char * argv[])
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<rclcpp::Node>(
        "wave_demo",
        rclcpp::NodeOptions().automatically_declare_parameters_from_overrides(true));

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(node);

    std::thread spinner([&executor]() {
        executor.spin();
    });

    moveit::planning_interface::MoveGroupInterface move_group(node, "left_arm");

    std::vector<std::string> poses = {
        "wave_ready",
        "wave_in",
        "wave_out",
        "wave_in",
        "wave_out",
        "home"
    };

    for (const auto & pose : poses)
    {
        RCLCPP_INFO(node->get_logger(), "Moving to %s", pose.c_str());

        move_group.setNamedTarget(pose);

        moveit::planning_interface::MoveGroupInterface::Plan plan;

        bool success =
            (move_group.plan(plan) ==
             moveit::core::MoveItErrorCode::SUCCESS);

        if (!success)
        {
            RCLCPP_ERROR(node->get_logger(),
                         "Planning failed: %s",
                         pose.c_str());
            continue;
        }

        move_group.execute(plan);

        std::this_thread::sleep_for(
            std::chrono::milliseconds(500));
    }

    rclcpp::shutdown();
    spinner.join();

    return 0;
}

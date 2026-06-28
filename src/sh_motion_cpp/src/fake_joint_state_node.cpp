#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/joint_state.hpp"

#include <yaml-cpp/yaml.h>
#include <ament_index_cpp/get_package_share_directory.hpp>

using namespace std::chrono_literals;

class FakeJointStateNode : public rclcpp::Node
{
public:
  FakeJointStateNode()
  : Node("fake_joint_state_node")
  {
    pub_ = create_publisher<sensor_msgs::msg::JointState>(
        "/joint_states", 10);

    joint_msg_.name = {
      "joint1",
      "joint2",
      "joint3",
      "joint4",
      "joint5",
      "joint6",
      "joint7",
      "joint8",
      "joint9",
      "joint10",
      "joint11",
      "joint12",
      "joint13",
      "joint14",
      "Revolute 15"
    };

    joint_msg_.position.resize(15);
    joint_msg_.velocity.resize(15, 0.0);
    joint_msg_.effort.resize(15, 0.0);

    loadInitialPositions();

    timer_ = create_wall_timer(
        20ms,
        std::bind(&FakeJointStateNode::publishJointState, this));

    RCLCPP_INFO(get_logger(), "Fake Joint State Started");
  }

private:

  void loadInitialPositions()
  {
    try
    {
      std::string package_path =
          ament_index_cpp::get_package_share_directory(
              "SH_moveit_head_config");

      std::string yaml_path =
          package_path + "/config/initial_positions.yaml";

      YAML::Node config = YAML::LoadFile(yaml_path);

      YAML::Node init = config["initial_positions"];

      for (size_t i = 0; i < joint_msg_.name.size(); i++)
      {
        std::string joint = joint_msg_.name[i];

        if (init[joint])
        {
          joint_msg_.position[i] =
              init[joint].as<double>();

          RCLCPP_INFO(
              get_logger(),
              "%s = %.4f",
              joint.c_str(),
              joint_msg_.position[i]);
        }
        else
        {
          joint_msg_.position[i] = 0.0;

          RCLCPP_WARN(
              get_logger(),
              "%s not found in initial_positions.yaml",
              joint.c_str());
        }
      }
    }
    catch(const std::exception &e)
    {
      RCLCPP_ERROR(
          get_logger(),
          "Failed to load initial_positions.yaml");

      RCLCPP_ERROR(
          get_logger(),
          "%s",
          e.what());

      std::fill(
          joint_msg_.position.begin(),
          joint_msg_.position.end(),
          0.0);
    }
  }

  void publishJointState()
  {
    joint_msg_.header.stamp = now();
    pub_->publish(joint_msg_);
  }

  rclcpp::Publisher<sensor_msgs::msg::JointState>::SharedPtr pub_;
  rclcpp::TimerBase::SharedPtr timer_;

  sensor_msgs::msg::JointState joint_msg_;
};

int main(int argc,char** argv)
{
  rclcpp::init(argc,argv);

  rclcpp::spin(
      std::make_shared<FakeJointStateNode>());

  rclcpp::shutdown();

  return 0;
}
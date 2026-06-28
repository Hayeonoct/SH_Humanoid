#!/usr/bin/env python3

import time

from moveit.planning import MoveItPy


def main():

    print("Starting MoveItPy...")

    robot = MoveItPy(node_name="wave_demo")

    left_arm = robot.get_planning_component("left_arm")

    poses = [
        "wave_ready",
        "wave_in",
        "wave_out",
        "wave_in",
        "wave_out",
        "home",
    ]

    for pose in poses:

        print(f"Moving to {pose}")

        left_arm.set_goal_state(configuration_name=pose)

        plan_result = left_arm.plan()

        if not plan_result:
            print(f"Planning failed: {pose}")
            continue

        robot.execute(plan_result.trajectory)

        time.sleep(1.0)

    print("Done")


if __name__ == "__main__":
    main()

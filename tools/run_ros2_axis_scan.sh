#!/usr/bin/env bash
set -eo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
REBUILD=0
source "$ROOT_DIR/tools/ros2_conda_env.sh"

if [[ "${1:-}" == "--rebuild" ]]; then
	REBUILD=1
	shift
fi

setup_ros2_env

cd "$ROOT_DIR"

if [[ $REBUILD -eq 1 || ! -f "$ROOT_DIR/install/ros2_interfaces/share/ros2_interfaces/local_setup.bash" ]]; then
	colcon build --base-paths ros2_interfaces --packages-select ros2_interfaces \
		--cmake-args -DPython3_EXECUTABLE="$ROS2_PYTHON" -DPython3_FIND_STRATEGY=LOCATION
fi

source "$ROOT_DIR/install/ros2_interfaces/share/ros2_interfaces/local_setup.bash"

exec "$ROS2_PYTHON" "$ROOT_DIR/tools/ros2_axis_scan.py" "$@"

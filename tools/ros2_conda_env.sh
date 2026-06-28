#!/usr/bin/env bash

resolve_conda_base() {
  local conda_exe

  if conda_exe="$(command -v conda 2>/dev/null)" && [[ -n "$conda_exe" ]]; then
    dirname "$(dirname "$conda_exe")"
    return 0
  fi

  local candidate
  for candidate in \
    "$HOME/miniforge3/bin/conda" \
    "$HOME/mambaforge/bin/conda" \
    "/opt/conda/bin/conda" \
    "/opt/miniforge3/bin/conda" \
    "/opt/homebrew/Caskroom/miniforge/base/bin/conda"
  do
    if [[ -x "$candidate" ]]; then
      dirname "$(dirname "$candidate")"
      return 0
    fi
  done

  return 1
}

setup_ros2_env() {
  local conda_base
  local system_ros_setup="/opt/ros/jazzy/setup.bash"

  if conda_base="$(resolve_conda_base)"; then
    if [[ -n "${VIRTUAL_ENV:-}" ]]; then
      PATH="$(echo "$PATH" | tr ':' '\n' | awk -v v="$VIRTUAL_ENV/bin" '$0 != v' | paste -sd ':' -)"
      unset VIRTUAL_ENV
    fi
    unset PYTHONHOME
    unset PYTHONPATH

    eval "$($conda_base/bin/conda shell.bash hook)"
    conda activate ros2_humble
    export ROS2_PYTHON="$CONDA_PREFIX/bin/python"
  elif [[ -f "$system_ros_setup" ]]; then
    # Use the system ROS2 install when conda is unavailable.
    # The workspace overlay is sourced by the launcher scripts after this helper.
    # shellcheck disable=SC1090
    source "$system_ros_setup"
    export ROS2_PYTHON="$(command -v python3)"
  else
    echo "[error] neither conda nor a system ROS2 install was found"
    echo "[hint] install Miniforge/Mambaforge, or source /opt/ros/jazzy/setup.bash"
    return 2
  fi
}

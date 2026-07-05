#!/usr/bin/env bash
#
# start_lidar.sh -- 라이다 + Foxglove bridge + TF + (선택) 카메라를 한 번에 실행.
#
# 이거 하나만 실행하면:
#   1) hesai 라이다 드라이버
#   2) foxglove_bridge (ws://<이 PC IP>:8765) -- 라이다/TF/카메라를 하나의 연결로 송출
#   3) static TF  base_link -> hesai_lidar
#   4) 카메라 프리뷰를 ROS 토픽(/camera/image)으로 발행 (make_motions.py --ros-image)
#
# 사용법:
#   ./start_lidar.sh              # 전부 실행 (라이다 + 카메라)
#   ./start_lidar.sh --no-cam     # 카메라 없이 라이다만
#   ./start_lidar.sh --wrist ...  # --no-cam 외의 인자는 make_motions.py 로 전달
#
# Foxglove Studio:
#   Open connection -> ws://localhost:8765  (원격이면 이 PC IP)
#   3D 패널: 포인트클라우드 + TF,   Image 패널 topic: /camera/image
#
# 종료: 이 터미널에서 Ctrl+C  (자식 프로세스 전부 정리됨)

set -u

# --- 경로/환경 ---
ROS_SETUP="/opt/ros/jazzy/setup.bash"
HESAI_SETUP="$HOME/hesai_ws/install/setup.bash"
SH_WS="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"   # 이 스크립트가 있는 폴더(SH_ws)

# --- 인자 파싱: --no-cam 만 여기서 처리, 나머지는 make_motions 로 ---
RUN_CAM=1
CAM_ARGS=()
for a in "$@"; do
  if [ "$a" = "--no-cam" ]; then
    RUN_CAM=0
  else
    CAM_ARGS+=("$a")
  fi
done

# --- ROS 환경 소싱 ---
# shellcheck disable=SC1090
source "$ROS_SETUP"
if [ -f "$HESAI_SETUP" ]; then
  # shellcheck disable=SC1090
  source "$HESAI_SETUP"
else
  echo "[warn] $HESAI_SETUP 없음 -- hesai_ws 를 빌드했는지 확인하세요."
fi
# SH_ws 커스텀 메시지(ros2_interfaces: /upper_body/*) 를 foxglove_bridge 가 읽을 수 있도록 소싱
SH_WS_SETUP="$SH_WS/install/setup.bash"
if [ -f "$SH_WS_SETUP" ]; then
  # shellcheck disable=SC1090
  source "$SH_WS_SETUP"
else
  echo "[warn] $SH_WS_SETUP 없음 -- SH_ws 를 colcon build 했는지 확인하세요."
fi

# --- 자식 프로세스 추적 + Ctrl+C 시 전부 정리 ---
PIDS=()
cleanup() {
  echo ""
  echo "[stop] 종료 중... 자식 프로세스 정리"
  for pid in "${PIDS[@]}"; do
    kill "$pid" 2>/dev/null
  done
  # 그래도 남은 것들 정리
  wait 2>/dev/null
  echo "[stop] 완료."
}
trap cleanup INT TERM EXIT

echo "[1/4] hesai 라이다 드라이버..."
ros2 launch hesai_ros_driver start.py &
PIDS+=($!)
sleep 2

echo "[2/4] foxglove_bridge (8765)..."
ros2 run foxglove_bridge foxglove_bridge &
PIDS+=($!)
sleep 1

echo "[3/4] static TF  base_link -> hesai_lidar ..."
ros2 run tf2_ros static_transform_publisher 0 0 0 3.14159 0 0 base_link hesai_lidar &
PIDS+=($!)
sleep 1

if [ "$RUN_CAM" -eq 1 ]; then
  echo "[4/4] 카메라 발행 make_motions.py --ros-image ${CAM_ARGS[*]:-}"
  echo "      (카메라 창에서 SPACE=녹화, q=종료. q 로 카메라만 닫아도 라이다는 계속 돕니다.)"
  # 카메라는 포그라운드로 실행(cv2 창/키 입력 필요). 종료돼도 라이다는 유지.
  python3 "$SH_WS/make_motions.py" --ros-image "${CAM_ARGS[@]}"
  echo "[info] 카메라 종료됨. 라이다는 계속 실행 중. 전체 종료하려면 Ctrl+C."
fi

echo ""
echo "[ready] Foxglove Studio 에서 ws://localhost:8765 로 연결하세요."
echo "        종료: 이 터미널에서 Ctrl+C"

# 라이다/브리지/TF 가 살아있는 동안 대기
wait
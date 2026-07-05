#!/usr/bin/env python3
"""
play_csv.py  --  각도 CSV를 MoveIt(move_group)에 입력해 재생  [SH_Humanoid]
동작 (Option A):
    * 이미 실행 중인 move_group 에 클라이언트로만 붙음 (기존 설정 무수정).
    * CSV 전체를 하나의 연속 궤적으로 만들어
        1) /display_planned_path 로 RViz plan 미리보기
        2) Enter 대기 (실시간 아님)
        3) /execute_trajectory 액션으로 실행 (재플래닝 없이 '본 그대로' 실행)
      -> move_group이 joint1~7(오른팔) / joint8~14(왼팔) / Revolute15(머리) 를 각 컨트롤러로 자동 분배.
    * CSV의 time 열을 그대로 time_from_start 로 사용 (리타이밍 불필요).
    * 실행 전에 URDF 리밋으로 각도 검증(초과 시 중단, --clamp 로 잘라내기).
사용:
    python3 play_csv.py --csv motion.csv
옵션:
    --time-scale 1.5   느리게(>1)/빠르게(<1)
    --lead-in 2.0      현재 자세 -> CSV 첫 행 진입 시간(초). 시작오차 방지
    --clamp            리밋 초과 각도를 리밋으로 잘라내고 계속
    --no-confirm       Enter 생략하고 바로 실행
    --preview-only     미리보기만
"""
import argparse
import csv
import time
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient
from builtin_interfaces.msg import Duration
from sensor_msgs.msg import JointState
from trajectory_msgs.msg import JointTrajectory, JointTrajectoryPoint
from moveit_msgs.msg import RobotTrajectory, DisplayTrajectory, RobotState
from moveit_msgs.action import ExecuteTrajectory
MOVEIT_SUCCESS = 1
TIME_COLUMN = "time"
# URDF에서 추출한 조인트 리밋 (lower, upper) [rad]
JOINT_LIMITS = {
    "joint1":  (-1.658063, 1.658063),
    "joint2":  (-1.658063, 0.0),
    "joint3":  (-2.181662, 2.181662),
    "joint4":  (-1.745329, 1.745329),
    "joint5":  (-1.570796, 1.570796),
    "joint6":  (-1.658063, 1.658063),
    "joint7":  (-1.396263, 1.396263),
    "joint8":  (-1.658063, 1.658063),
    "joint9":  (0.0, 1.658063),
    "joint10": (-2.181662, 2.181662),
    "joint11": (-1.745329, 1.745329),
    "joint12": (-1.570796, 1.570796),
    "joint13": (-1.658063, 1.658063),
    "joint14": (-1.396263, 1.396263),
    # [머리] URDF의 Revolute15 실제 리밋으로 반드시 교체하세요.
    #  - 이 값이 실제 URDF보다 크면 move_group 이 execute 를 거부할 수 있습니다.
    #  - make_motion 의 HEAD_LIMITS 와 동일하게 맞추는 것을 권장.
    "Revolute15": (-1.658063, 1.658063),
}

# [home] 차렷 자세 = 전 관절 0 (abd joint2/9 의 0 이 '팔 내림'이라 전 관절 0 ≈ 차렷).
#  다른 자세로 복귀하려면 이 dict 값만 바꾸세요(예: "joint4": 0.2).
HOME_POSE = {j: 0.0 for j in JOINT_LIMITS}

# [home] --home-time 을 지정하지 않으면 이동량 기준으로 복귀 시간을 자동 계산.
HOME_SPEED    = 0.8   # rad/s. 가장 크게 움직이는 관절의 목표 속도(작을수록 천천히).
HOME_MIN_TIME = 1.0   # s. 아주 조금만 움직여도 최소 이 시간은 확보(급정지 방지).


def clamp_to_limit(joint, v):
    if joint in JOINT_LIMITS:
        lo, hi = JOINT_LIMITS[joint]
        return max(lo, min(hi, v))
    return v


def sec_to_duration(t: float) -> Duration:
    sec = int(t)
    nanosec = int(round((t - sec) * 1e9))
    if nanosec >= 1_000_000_000:
        sec += 1
        nanosec -= 1_000_000_000
    return Duration(sec=sec, nanosec=nanosec)
class CsvPlayer(Node):
    def __init__(self, args):
        super().__init__("csv_player")
        self.args = args
        self.display_pub = self.create_publisher(
            DisplayTrajectory, "/display_planned_path", 1)
        self.exec_client = ActionClient(self, ExecuteTrajectory, "/execute_trajectory")
        self._js = None
        self.create_subscription(JointState, "/joint_states", self._js_cb, 10)
    def _js_cb(self, msg):
        self._js = msg
    def wait_js(self, timeout=5.0):
        start = time.time()
        while self._js is None and (time.time() - start) < timeout:
            rclpy.spin_once(self, timeout_sec=0.1)
        return self._js
    # ---------- CSV ----------
    def load_csv(self):
        with open(self.args.csv, newline="") as f:
            reader = csv.DictReader(f)
            header = reader.fieldnames or []
            if TIME_COLUMN not in header:
                raise ValueError(f"'{TIME_COLUMN}' column not found in {header}")
            joints = [c for c in header if c != TIME_COLUMN]
            rows = list(reader)
        if not rows:
            raise ValueError("CSV has no data rows")
        unknown = [j for j in joints if j not in JOINT_LIMITS]
        if unknown:
            self.get_logger().warn(f"joints not in URDF limit table (unchecked): {unknown}")
        self.get_logger().info(f"loaded {len(rows)} rows, joints={joints}")
        return joints, rows
    def check_limits(self, joints, rows):
        violations = 0
        clamped = 0
        for r in rows:
            for j in joints:
                if j not in JOINT_LIMITS:
                    continue
                lo, hi = JOINT_LIMITS[j]
                v = float(r[j])
                if v < lo or v > hi:
                    if self.args.clamp:
                        r[j] = max(lo, min(hi, v))
                        clamped += 1
                    else:
                        violations += 1
                        if violations <= 5:
                            self.get_logger().error(
                                f"limit violation {j}={v:.4f} not in [{lo:.4f},{hi:.4f}] "
                                f"at t={r[TIME_COLUMN]}")
        if self.args.clamp and clamped:
            self.get_logger().warn(f"clamped {clamped} out-of-limit values")
        if violations:
            raise ValueError(
                f"{violations} joint-limit violations (use --clamp to auto-clamp)")
        return rows
    def build(self, joints, rows) -> RobotTrajectory:
        jt = JointTrajectory()
        jt.joint_names = joints
        offset = 0.0
        cur = self.wait_js()
        if self.args.lead_in > 0.0 and cur is not None:
            name_to_pos = dict(zip(cur.name, cur.position))
            try:
                p0 = JointTrajectoryPoint()
                p0.positions = [name_to_pos[j] for j in joints]
                p0.time_from_start = sec_to_duration(0.0)
                jt.points.append(p0)
                offset = self.args.lead_in
                self.get_logger().info(f"lead-in from current pose ({offset:.1f}s)")
            except KeyError as e:
                self.get_logger().warn(f"joint {e} not in /joint_states; skipping lead-in")
        elif cur is None:
            self.get_logger().warn("no /joint_states; skipping lead-in")
        for r in rows:
            p = JointTrajectoryPoint()
            p.positions = [float(r[j]) for j in joints]
            t = float(r[TIME_COLUMN]) * self.args.time_scale + offset
            p.time_from_start = sec_to_duration(t)
            jt.points.append(p)

        # [home] 재생 끝난 뒤 차렷 자세(전 관절 HOME_POSE, 기본 0)로 자동 복귀
        if not self.args.no_home and jt.points:
            last_pt = jt.points[-1]
            last_t = last_pt.time_from_start.sec + last_pt.time_from_start.nanosec * 1e-9
            home_pos = [clamp_to_limit(j, HOME_POSE.get(j, 0.0)) for j in joints]

            # 복귀 시간: --home-time 을 주면 그 값, 안 주면(<=0) 이동량 기준 자동 산정.
            if self.args.home_time and self.args.home_time > 0.0:
                home_dt = self.args.home_time
                how = f"{home_dt:.1f}s(지정)"
            else:
                max_delta = max(
                    (abs(hp - cp) for hp, cp in zip(home_pos, last_pt.positions)),
                    default=0.0)
                # 가장 크게 움직이는 관절이 HOME_SPEED[rad/s] 로 움직인다고 보고 시간 산정.
                home_dt = max(HOME_MIN_TIME, max_delta / HOME_SPEED)
                how = f"{home_dt:.1f}s(자동: 최대이동 {max_delta:.2f}rad)"

            ph = JointTrajectoryPoint()
            ph.positions = home_pos
            ph.time_from_start = sec_to_duration(last_t + home_dt)
            jt.points.append(ph)
            self.get_logger().info(f"return-home appended: 차렷 복귀 {how}")

        prev = -1.0
        for i, p in enumerate(jt.points):
            t = p.time_from_start.sec + p.time_from_start.nanosec * 1e-9
            if t <= prev:
                raise ValueError(f"time not increasing at point {i} (t={t:.3f})")
            prev = t
        rt = RobotTrajectory()
        rt.joint_trajectory = jt
        return rt
    # ---------- preview / execute ----------
    def preview(self, rt):
        disp = DisplayTrajectory()
        start = RobotState()
        if self._js is not None:
            start.joint_state = self._js
        disp.trajectory_start = start
        disp.trajectory.append(rt)
        for _ in range(5):
            self.display_pub.publish(disp)
            rclpy.spin_once(self, timeout_sec=0.1)
        self.get_logger().info(f"preview published: {len(rt.joint_trajectory.points)} points "
                               f"on {self.display_pub.topic_name}")
        # RViz 설정을 만지는 동안 궤적이 계속 보이도록 반복 퍼블리시
        if self.args.loop_preview > 0.0:
            self.get_logger().info(
                f"looping preview for {self.args.loop_preview:.0f}s "
                "(RViz > MotionPlanning > Planned Path: Loop Animation ON) ...")
            t0 = time.time()
            while time.time() - t0 < self.args.loop_preview:
                self.display_pub.publish(disp)
                rclpy.spin_once(self, timeout_sec=0.1)
                time.sleep(0.9)
    def execute(self, rt) -> bool:
        if not self.exec_client.wait_for_server(timeout_sec=10.0):
            self.get_logger().error(
                "/execute_trajectory server not available -- is move_group running?")
            return False
        goal = ExecuteTrajectory.Goal()
        goal.trajectory = rt
        self.get_logger().info("sending to move_group ...")
        sf = self.exec_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, sf)
        gh = sf.result()
        if gh is None or not gh.accepted:
            self.get_logger().error("goal rejected")
            return False
        rf = gh.get_result_async()
        rclpy.spin_until_future_complete(self, rf)
        code = rf.result().result.error_code.val
        if code == MOVEIT_SUCCESS:
            self.get_logger().info("execution SUCCEEDED")
            return True
        self.get_logger().error(f"execution failed (MoveItErrorCode={code})")
        return False
def main():
    ap = argparse.ArgumentParser(description="Play a joint-angle CSV via MoveIt2 (SH_Humanoid).")
    ap.add_argument("--csv", required=True)
    ap.add_argument("--time-scale", type=float, default=1.0, dest="time_scale")
    ap.add_argument("--lead-in", type=float, default=2.0, dest="lead_in")
    ap.add_argument("--loop-preview", type=float, default=0.0, dest="loop_preview",
                    help="미리보기를 N초간 반복 퍼블리시(RViz 설정 확인용). 0=끄기")
    ap.add_argument("--clamp", action="store_true")
    ap.add_argument("--no-confirm", action="store_true", dest="no_confirm")
    ap.add_argument("--preview-only", action="store_true", dest="preview_only")
    ap.add_argument("--home-time", type=float, default=0.0, dest="home_time",
                    help="차렷 복귀 시간(초). 0/미지정이면 이동량 기준 자동 산정.")
    ap.add_argument("--no-home", action="store_true", dest="no_home",
                    help="차렷 복귀 구간을 붙이지 않음(재생만).")
    args = ap.parse_args()
    rclpy.init()
    node = CsvPlayer(args)
    try:
        joints, rows = node.load_csv()
        rows = node.check_limits(joints, rows)
        rt = node.build(joints, rows)
        node.preview(rt)
        if args.preview_only:
            node.get_logger().info("preview-only -> done.")
            return
        if not args.no_confirm:
            node.get_logger().info("RViz에서 plan 확인 후 Enter 를 누르세요 ...")
            try:
                input()
            except EOFError:
                pass
        node.execute(rt)
    except Exception as e:
        node.get_logger().error(f"{type(e).__name__}: {e}")
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()
if __name__ == "__main__":
    main()
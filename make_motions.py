#!/usr/bin/env python3
"""
make_motion.py  --  모션(각도 CSV) 생성  [SH_Humanoid]   (v5: 머리 Revolute15 yaw 감지 추가)

v4 대비 변경점(팔 로직은 1도 손대지 않음. 아래 항목만 '추가'):
  [v5-1] 머리 관절 Revolute15(=head) 감지 추가. [v5.2] 눈 기준으로 갱신.
         - MediaPipe Pose 의 얼굴 랜드마크(코 0, 좌눈 2, 우눈 5)로 머리 회전을 구한다.
         - 좌우 기준선 = 좌눈-우눈. 코가 두 눈 사이에서 옆으로 치우친 정도로 yaw 를 계산.
             yaw   = asin( (코-눈중점)·눈선 / 눈간격반 )   (기본: 얼굴 좌우 회전)
             pitch = asin( (코-눈중점)_up / 눈간격반 )     (끄덕임; HEAD_AXIS 로 선택)
         - 깊이(z)에 의존하지 않아 정면 카메라에서 안정적. 정면=0, 옆모습=±90도로 포화.
         - 귀는 사용하지 않는다(카메라 특성상 잘 안 보임). 눈이 안 보이면 마지막 값 홀드.
  [v5-2] CSV 에 마지막 열로 'Revolute15' 추가(라디안, 다른 관절과 동일 단위).
  [v5-3] 머리 전용 필터/홀드/슬루제한(HeadTracker) 추가. 팔의 Stabilizer/bank 는 그대로 사용.
  [v5-4] demo / demo_wrist 도 머리 열을 채우도록 값만 추가(축 확인용).

  * 머리는 팔이 감지된 프레임 안에서 함께 계산된다(녹화 조건=팔 관측, 기존 동작 유지).
    팔이 잡혀도 얼굴이 안 잡히면 머리만 홀드된다.
  * 부호가 반대면 HEAD_SIGN 만 뒤집기. 크기는 HEAD_GAIN. 범위는 HEAD_LIMITS(URDF 기준으로 맞추기).

---------------------------------------------------------------------------
아래는 v4 원본 설명(변경 없음):

핵심 변경 (v3 대비):
  1) joint3/joint10 재정의 : (v3)전완 twist 위쪽 -> (v4)'상완 축회전(humeral roll)'.
  2) joint3 <-> joint5 분리 : v3 의 7:3 twist 분배 폐기.
  3) 폐색/튐 대응(캡처 경로): 팔 길이 홀드 / 슬루 제한 / 관측성 게이팅.
  4) joint6/13(손목 굽힘), joint7/14(손목 좌우)는 유지.

관절 배정:
  팔 앞뒤(pitch)        : joint1 / joint8
  팔 좌우 벌림(abd)     : joint2 / joint9
  상완 축회전(humeral)  : joint3 / joint10
  팔꿈치 굽힘(elbow)    : joint4 / joint11
  전완 pronation(pron)  : joint5 / joint12   <-- --wrist
  손목 굽힘(w_pitch)    : joint6 / joint13   <-- --wrist
  손목 좌우(w_yaw)      : joint7 / joint14   <-- --wrist
  머리 회전(head)       : Revolute15         <-- [v5] --wrist 없이도 계산

모드:
  --mode realsense : RealSense(color) + MediaPipe. SPACE=녹화 시작, q=종료.
  --mode demo      : 카메라 없이 합성 동작.
  --mode demo_wrist: 축 확인용.
"""

import argparse
import csv
import math

import numpy as np

# ===================== 로봇 정의 =====================
JOINT_LIMITS = {
    "joint1":  (-1.658063, 1.658063), "joint2":  (-1.658063, 0.0),
    "joint3":  (-2.181662, 2.181662), "joint4":  (-1.745329, 1.745329),
    "joint5":  (-1.570796, 1.570796), "joint6":  (-1.658063, 1.658063),
    "joint7":  (-1.396263, 1.396263),
    "joint8":  (-1.658063, 1.658063), "joint9":  (0.0, 1.658063),
    "joint10": (-2.181662, 2.181662), "joint11": (-1.745329, 1.745329),
    "joint12": (-1.570796, 1.570796), "joint13": (-1.658063, 1.658063),
    "joint14": (-1.396263, 1.396263),
}
RIGHT_ARM = [f"joint{i}" for i in range(1, 8)]
LEFT_ARM  = [f"joint{i}" for i in range(8, 15)]
JOINTS = RIGHT_ARM + LEFT_ARM

# 사용자관례(바깥/앞/굽힘/외회전 = +) -> MoveIt 실제 부호(좌우 거울 보정)
USER_TO_MOVEIT_SIGN = {
    'joint1': -1.0, 'joint2': 1.0, 'joint3': 1.0, 'joint4': -1.0,
    'joint5': -1.0, 'joint6': 1.0, 'joint7':  1.0,
    'joint8':  1.0, 'joint9':  1.0, 'joint10': 1.0, 'joint11': 1.0,
    'joint12': 1.0, 'joint13': 1.0, 'joint14': 1.0,
}

# 담당 관절.
DRIVE = {
    "right": {"pitch": "joint1", "abd": "joint2", "elbow": "joint4",
              "humeral": "joint3", "pron": "joint5",
              "w_pitch": "joint6", "w_yaw": "joint7"},
    "left":  {"pitch": "joint8", "abd": "joint9", "elbow": "joint11",
              "humeral": "joint10", "pron": "joint12",
              "w_pitch": "joint13", "w_yaw": "joint14"},
}

# 게인
PITCH_GAIN   = 1.0    # 앞으로 듦 -> joint1/joint8
ELBOW_GAIN   = 1.0    # 팔꿈치 굽힘 -> joint4/joint11
HUMERAL_GAIN = 1.0    # 상완 축회전 -> joint3/joint10
PRON_GAIN    = 1.0    # 전완 pronation -> joint5/joint12 (노이즈 크면 낮추기)
WRIST_PITCH_GAIN = 1.0   # 손목 굽힘 -> joint6/joint13
WRIST_YAW_GAIN   = 1.0   # 손목 좌우 -> joint7/joint14
MIRROR = True

# ===================== [v5] 머리 관절(Revolute15) 정의 =====================
HEAD_JOINT  = "Revolute15"
# URDF 기준으로 실제 리밋을 넣으세요(임시로 다른 관절과 비슷하게 ±95도).
HEAD_LIMITS = (-1.658063, 1.658063)
HEAD_AXIS   = "yaw"    # "yaw"=얼굴 좌우 회전(기본), "pitch"=끄덕임. 로봇에서 확인 후 선택.
HEAD_GAIN   = 1.0      # 감지된 각을 크게/작게. 사람 목 각도가 로봇에 과하면 낮추기.
HEAD_SIGN   = 1.0      # 방향이 반대면 -1.0 로 뒤집기.
# 머리 감지에 쓰는 최소 baseline(코-귀중점 벡터 길이). 이보다 짧으면 관측 불가 취급.
HEAD_MIN_BASELINE = 1e-3

# --- 관측성 게이팅 임계값 ---
FLEX_MIN_SIN = 0.25      # humeral 신뢰 최소 굽힘(약 14도)
PALM_MIN_SIN = 0.20      # pronation 신뢰 최소 손가락 벌어짐

# --- 폐색/튐 대응 파라미터(캡처 경로) ---
ARMLEN_TOL   = 0.35      # 상완/전완 길이가 러닝중앙값 대비 이 비율 넘게 튀면 그 팔 홀드
MAX_JOINT_RATE = 6.0     # rad/s. 프레임 간 각속도 상한(슬루 제한).

# 문서 2 방식 EMA(--filter ema 일 때).
EMA_ALPHA = 0.15

# --- 옆으로 벌림(abd: joint2/joint9)은 비대칭 리밋이라 '내림값->올림값' 보간 ---
ABD_DOWN = {"joint2": 0.0,    "joint9": 0.0}
ABD_UP   = {"joint2": -1.571, "joint9": 1.571}
ABD_OFFSET = {"joint2": 0.0,  "joint9": -0.0}


# ===================== One Euro Filter =====================
class OneEuro:
    def __init__(self, min_cutoff=1.0, beta=0.02, d_cutoff=1.0):
        self.min_cutoff = float(min_cutoff); self.beta = float(beta)
        self.d_cutoff = float(d_cutoff)
        self.x_prev = None; self.dx_prev = 0.0; self.t_prev = None

    @staticmethod
    def _alpha(cutoff, dt):
        tau = 1.0 / (2.0 * math.pi * cutoff)
        return 1.0 / (1.0 + tau / dt)

    def __call__(self, x, t):
        if self.x_prev is None:
            self.x_prev, self.t_prev = x, t
            return x
        dt = t - self.t_prev
        if dt <= 0.0:
            dt = 1e-3
        dx = (x - self.x_prev) / dt
        a_d = self._alpha(self.d_cutoff, dt)
        dx_hat = a_d * dx + (1.0 - a_d) * self.dx_prev
        cutoff = self.min_cutoff + self.beta * abs(dx_hat)
        a = self._alpha(cutoff, dt)
        x_hat = a * x + (1.0 - a) * self.x_prev
        self.x_prev, self.dx_prev, self.t_prev = x_hat, dx_hat, t
        return x_hat


def make_filter_bank(kind, min_cutoff, beta):
    if kind == "oneeuro":
        return {"kind": "oneeuro", "f": {j: OneEuro(min_cutoff, beta, 1.0) for j in JOINTS}}
    if kind == "ema":
        return {"kind": "ema", "alpha": EMA_ALPHA, "prev": None}
    return {"kind": "none"}


def apply_filter(bank, raw, t):
    kind = bank["kind"]
    if kind == "none":
        return dict(raw)
    if kind == "ema":
        prev = bank["prev"]; a = bank["alpha"]
        out = dict(raw) if prev is None else {j: a * raw[j] + (1.0 - a) * prev[j] for j in JOINTS}
        bank["prev"] = out
        return dict(out)
    return {j: bank["f"][j](raw[j], t) for j in JOINTS}


# ===================== 캡처 경로 안정화기(홀드 + 슬루 제한) =====================
class Stabilizer:
    """홀드(hold) 관절은 마지막 유효값 유지, 이후 슬루 속도 제한으로 비물리적 점프 컷."""
    def __init__(self, max_rate=MAX_JOINT_RATE):
        self.max_rate = float(max_rate)
        self.last = None        # 마지막 출력(dict)
        self.t_last = None

    def process(self, raw, hold_joints, t):
        out = dict(raw)
        if self.last is not None:
            for j in hold_joints:
                out[j] = self.last[j]
        if self.last is not None and self.t_last is not None:
            dt = max(1e-3, t - self.t_last)
            cap = self.max_rate * dt
            for j in JOINTS:
                d = out[j] - self.last[j]
                if d > cap:
                    out[j] = self.last[j] + cap
                elif d < -cap:
                    out[j] = self.last[j] - cap
        self.last = dict(out)
        self.t_last = t
        return out


# ===================== [v5] 머리 전용 트래커(필터 + 홀드 + 슬루 제한) =====================
class HeadTracker:
    """
    머리 각도(1축) 전용. 팔의 bank/Stabilizer 와 독립적으로 동작해서
    기존 팔 파이프라인을 건드리지 않는다.
      - raw is None  -> 관측 불가(얼굴 폐색 등): 마지막 값 홀드
      - filt_kind    -> 'oneeuro' 면 One Euro, 그 외엔 EMA
      - 마지막에 슬루 속도 제한 + HEAD_LIMITS 클램프
    """
    def __init__(self, filt_kind, min_cutoff, beta, max_rate=MAX_JOINT_RATE):
        self.euro = OneEuro(min_cutoff, beta, 1.0) if filt_kind == "oneeuro" else None
        self.alpha = EMA_ALPHA
        self.prev = None
        self.last = 0.0
        self.t_last = None
        self.max_rate = float(max_rate)

    def update(self, raw, t):
        if raw is None:
            target = self.last
        elif self.euro is not None:
            target = self.euro(raw, t)
        else:
            target = raw if self.prev is None else self.alpha * raw + (1.0 - self.alpha) * self.prev
            self.prev = target
        # 슬루 속도 제한
        if self.t_last is not None:
            dt = max(1e-3, t - self.t_last)
            cap = self.max_rate * dt
            d = target - self.last
            if d > cap:
                target = self.last + cap
            elif d < -cap:
                target = self.last - cap
        self.last = target
        self.t_last = t
        return clamp(target, *HEAD_LIMITS)


# ===================== [v5.1] 머리 중립 영점(calibration) =====================
class HeadZero:
    """
    카메라가 위/아래에 있어 정면을 봐도 각이 0이 아닐 수 있으므로,
    시작 몇 초간(또는 'z' 키로) '정면 응시' 자세를 모아 중앙값을 영점으로 잡고 뺀다.
      - 영점이 잡히기 전엔 지금까지 모은 값의 중앙값을 빼서 근사 0 을 출력.
      - reset() 하면 다시 정면을 응시해 재보정.
    """
    def __init__(self, calib_sec=1.0):
        self.calib_sec = float(calib_sec)
        self.reset()

    def reset(self):
        self.buf = []
        self.zero = None
        self.t0 = None

    def locked(self):
        return self.zero is not None

    def value(self, raw, t):
        if raw is None:
            return None
        if self.zero is not None:
            return raw - self.zero
        if self.t0 is None:
            self.t0 = t
        self.buf.append(raw)
        med = float(np.median(self.buf))
        if (t - self.t0) >= self.calib_sec and len(self.buf) >= 5:
            self.zero = med
        return raw - med


# ===================== 사람 특징 -> MoveIt 각도 =====================
def clamp(v, lo, hi):
    return max(lo, min(hi, v))


def map_arm(side, u, flex, humeral, pron, w_pitch, w_yaw, mv, hold):
    """humeral/pron 이 None 이면 해당 관절을 hold 집합에 넣어 마지막 값 유지하도록 표시."""
    a_side, a_up, a_fwd = float(u[0]), float(u[1]), float(u[2])

    elev = math.acos(clamp(-a_up, -1.0, 1.0))
    lift = clamp(elev / (math.pi / 2.0), 0.0, 1.0)
    azim = math.atan2(a_side, a_fwd) if (a_side * a_side + a_fwd * a_fwd) > 1e-6 else 0.0
    f_abd = clamp(lift * math.sin(azim), 0.0, 1.0)
    pit   = lift * math.cos(azim) * (math.pi / 2.0)

    d = DRIVE[side]
    jp, ja, je = d["pitch"], d["abd"], d["elbow"]
    jh, jpr = d["humeral"], d["pron"]
    jwp, jwy = d["w_pitch"], d["w_yaw"]

    abd_val = ABD_DOWN[ja] + f_abd * (ABD_UP[ja] - ABD_DOWN[ja]) + ABD_OFFSET[ja]
    mv[ja] = clamp(abd_val, *JOINT_LIMITS[ja])
    mv[jp] = clamp(USER_TO_MOVEIT_SIGN[jp] * PITCH_GAIN * pit,  *JOINT_LIMITS[jp])
    mv[je] = clamp(USER_TO_MOVEIT_SIGN[je] * ELBOW_GAIN * flex, *JOINT_LIMITS[je])

    if humeral is None:
        hold.add(jh)
    else:
        mv[jh] = clamp(USER_TO_MOVEIT_SIGN[jh] * HUMERAL_GAIN * humeral, *JOINT_LIMITS[jh])

    if pron is None:
        hold.add(jpr)
    else:
        mv[jpr] = clamp(USER_TO_MOVEIT_SIGN[jpr] * PRON_GAIN * pron, *JOINT_LIMITS[jpr])

    mv[jwp] = clamp(USER_TO_MOVEIT_SIGN[jwp] * WRIST_PITCH_GAIN * w_pitch, *JOINT_LIMITS[jwp])
    mv[jwy] = clamp(USER_TO_MOVEIT_SIGN[jwy] * WRIST_YAW_GAIN   * w_yaw,   *JOINT_LIMITS[jwy])
    return mv


def map_features_to_joints(feat_right, feat_left):
    """-> (mv dict, hold set). hold 는 이번 프레임에 관측 불가라 유지할 관절 집합."""
    fr, fl = feat_right, feat_left
    if MIRROR:
        fr, fl = feat_left, feat_right
    mv = {j: 0.0 for j in JOINTS}
    hold = set()
    if fr is not None:
        map_arm("right", fr["u"], fr["flex"], fr.get("humeral"), fr.get("pron"),
                fr.get("w_pitch", 0.0), fr.get("w_yaw", 0.0), mv, hold)
    else:
        hold.update(RIGHT_ARM)
    if fl is not None:
        map_arm("left", fl["u"], fl["flex"], fl.get("humeral"), fl.get("pron"),
                fl.get("w_pitch", 0.0), fl.get("w_yaw", 0.0), mv, hold)
    else:
        hold.update(LEFT_ARM)
    for j in JOINTS:
        lo, hi = JOINT_LIMITS[j]
        mv[j] = clamp(mv[j], lo, hi)
    return mv, hold


# ===================== 카메라 -> 로봇 base_link 축 정렬 =====================
AXIS_FWD_SIGN = -1.0
AXIS_LR_SIGN  = +1.0
AXIS_UD_SIGN  = +1.0


def _unit(v):
    n = float(np.linalg.norm(v))
    return v / n if n > 1e-9 else v


def mp_to_base(v):
    x, y, z = float(v[0]), float(v[1]), float(v[2])
    return np.array([AXIS_FWD_SIGN * (-z),
                     AXIS_LR_SIGN  * ( x),
                     AXIS_UD_SIGN  * (-y)], dtype=float)


# ===================== [v5] 머리 회전 감지 =====================
def head_feature(nose, eyeL, eyeR):
    """
    [v5.2] 눈만 기준으로 머리 회전 감지(귀 미사용).
      - 좌우 기준선(baseline) = 좌눈-우눈. 코가 두 눈 사이에서 옆으로 얼마나 치우쳤는지로 yaw.
        asin(오프셋/half) 형태라 깊이(z)에 의존하지 않아 정면 카메라에서 안정적.
        정면=0, 옆모습=±90도로 자연스럽게 포화.
      - pitch: 코가 눈선 위/아래로 치우친 정도(HEAD_AXIS='pitch' 일 때).
    눈 간격이 너무 짧으면(랜드마크 뭉침) None 반환 -> 홀드.
    HEAD_AXIS 로 yaw/pitch 선택, HEAD_SIGN*HEAD_GAIN 적용.
    """
    mid = 0.5 * (eyeL + eyeR)                   # 두 눈의 중점

    side = mp_to_base(eyeR - eyeL)             # 좌우 기준선 = 눈선(base frame)
    half = 0.5 * float(np.linalg.norm(side))
    if half < HEAD_MIN_BASELINE:
        return None
    u_side = side / (2.0 * half)               # 눈선 단위벡터(_unit)

    off = mp_to_base(nose - mid)               # 코의 눈중점 대비 오프셋
    s_yaw = clamp(float(np.dot(off, u_side)) / half, -1.0, 1.0)  # -1..+1 (좌우 치우침)
    yaw   = math.asin(s_yaw)
    s_pit = clamp(float(off[2]) / half, -1.0, 1.0)               # 위/아래 치우침(base_z=상)
    pitch = math.asin(s_pit)

    val = yaw if HEAD_AXIS == "yaw" else pitch
    return HEAD_SIGN * HEAD_GAIN * val


def arm_features(sh, el, wr, outward_sign, hand=None):
    """v4 그대로. (팔 특징 계산)"""
    uvec = mp_to_base(el - sh)
    fvec = mp_to_base(wr - el)
    u = _unit(uvec)
    f = _unit(fvec)

    a_fwd  = float(u[0])
    a_side = outward_sign * float(u[1])
    a_up   = float(u[2])

    flex = math.acos(clamp(float(np.dot(u, f)), -1.0, 1.0))

    fp = f - float(np.dot(f, u)) * u
    fp_sin = float(np.linalg.norm(fp))
    humeral = None
    if fp_sin >= FLEX_MIN_SIN:
        ref = np.array([0.0, 0.0, 1.0])
        e1 = ref - float(np.dot(ref, u)) * u
        if float(np.linalg.norm(e1)) < 1e-3:
            ref2 = np.array([1.0, 0.0, 0.0])
            e1 = ref2 - float(np.dot(ref2, u)) * u
        e1 = _unit(e1)
        e2 = np.cross(u, e1)
        humeral = math.atan2(outward_sign * float(np.dot(fp, e2)), float(np.dot(fp, e1)))

    pron = None
    w_pitch = w_yaw = 0.0
    if hand is not None:
        idx = mp_to_base(hand["index"] - wr)
        pky = mp_to_base(hand["pinky"] - wr)
        hp = _unit(idx + pky)

        up_ref = np.array([0.0, 0.0, 1.0])
        e_up = up_ref - float(np.dot(up_ref, f)) * f
        if float(np.linalg.norm(e_up)) < 1e-3:
            e_up = np.array([1.0, 0.0, 0.0]) - float(np.dot(np.array([1.0, 0.0, 0.0]), f)) * f
        e_up = _unit(e_up)
        e_side = _unit(np.cross(f, e_up))

        c_f = float(np.dot(hp, f))
        w_pitch = math.atan2(float(np.dot(hp, e_up)), c_f)
        w_yaw   = math.atan2(outward_sign * float(np.dot(hp, e_side)), c_f)

        iu = _unit(idx); pu = _unit(pky)
        spread = float(np.linalg.norm(np.cross(iu, pu)))
        if spread >= PALM_MIN_SIN:
            n = _unit(np.cross(idx, pky))
            pron = math.atan2(outward_sign * float(np.dot(n, e_side)), float(np.dot(n, e_up)))

    return {"u": (a_side, a_up, a_fwd), "flex": flex,
            "humeral": humeral, "pron": pron, "w_pitch": w_pitch, "w_yaw": w_yaw,
            "_len_u": float(np.linalg.norm(uvec)), "_len_f": float(np.linalg.norm(fvec))}


# ===================== RealSense(color) + MediaPipe =====================
# [v5] 얼굴 랜드마크(코 0, 좌귀 7, 우귀 8, 좌눈 2, 우눈 5) 추가.
LM = {"Rsh": 12, "Rel": 14, "Rwr": 16, "Lsh": 11, "Lel": 13, "Lwr": 15,
      "Rindex": 20, "Rpinky": 18, "Lindex": 19, "Lpinky": 17,
      "nose": 0, "Lear": 7, "Rear": 8, "Leye": 2, "Reye": 5}


class RunningMedian:
    def __init__(self, n=31):
        self.n = n; self.buf = []
    def push_and_median(self, x):
        self.buf.append(x)
        if len(self.buf) > self.n:
            self.buf.pop(0)
        return float(np.median(self.buf))


def capture_realsense(duration, fps, countdown, filt_kind, min_cutoff, beta,
                      min_vis, use_wrist=False, head_calib_sec=1.0,
                      use_foxglove=False, foxglove_port=8765,
                      headless=False, autostart=False, frame_timeout_ms=15000,
                      use_ros_image=False, ros_image_topic="/camera/image"):
    import cv2
    import pyrealsense2 as rs
    import mediapipe as mp
    import time as _t

    mp_pose = mp.solutions.pose
    mp_draw = mp.solutions.drawing_utils

    pipeline = rs.pipeline()
    cfg = rs.config()
    cfg.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, fps)
    profile = pipeline.start(cfg)

    # [foxglove] 로컬 창 대신(또는 함께) Foxglove 로 프리뷰 스트리밍
    #   - use_foxglove   : 자체 Foxglove 서버(별도 포트). 라이다 bridge 와 포트 충돌 주의.
    #   - use_ros_image  : ROS2 토픽으로 발행 -> 실행 중인 foxglove_bridge 가 라이다와 함께 통합 송출(권장).
    fox = None
    if use_ros_image:
        from ros_stream import RosImageStreamer     # 사용자 모듈
        fox = RosImageStreamer(topic=ros_image_topic)
    elif use_foxglove:
        from foxglove_stream import FoxgloveStreamer   # 사용자 모듈
        fox = FoxgloveStreamer(port=foxglove_port)
    if headless and fox is None:
        print("[headless] 로컬 창도 스트림도 없습니다(화면 확인 불가). --ros-image 또는 --foxglove 권장.")
    if headless and not autostart and duration and duration > 0:
        print("[headless] 창 키 입력 불가 -> --autostart 없으면 녹화가 시작되지 않습니다.")

    bank = make_filter_bank(filt_kind, min_cutoff, beta)
    stab = Stabilizer(MAX_JOINT_RATE)
    head_tracker = HeadTracker(filt_kind, min_cutoff, beta, MAX_JOINT_RATE)  # [v5]
    head_zeroer = HeadZero(head_calib_sec)  # [v5.1] 정면 응시 영점 보정
    med = {"Ru": RunningMedian(), "Rf": RunningMedian(),
           "Lu": RunningMedian(), "Lf": RunningMedian()}

    rows = []
    last = None
    state = "wait"; t0 = None; count_start = None; cancelled = False

    arm_keys = ("Rsh", "Rel", "Rwr", "Lsh", "Lel", "Lwr")
    face_keys = ("nose", "Leye", "Reye")  # [v5.1] 눈 기준(귀 폐색에 강건). 귀는 보이면 보조로 사용.
    print("프리뷰 중. SPACE=녹화 시작, q/ESC=취소.")

    frame_misses = 0
    try:
        with mp_pose.Pose(model_complexity=1, smooth_landmarks=True,
                          min_detection_confidence=0.6, min_tracking_confidence=0.6) as pose:
            while True:
                try:
                    frames = pipeline.wait_for_frames(timeout_ms=frame_timeout_ms)
                    frame_misses = 0
                except RuntimeError as e:
                    frame_misses += 1
                    print(f"[warn] RealSense 프레임 미도착({frame_misses}): {e}")
                    if frame_misses >= 3:
                        raise RuntimeError(
                            "RealSense 프레임이 계속 도착하지 않습니다. 점검: "
                            "①USB3(SS) 포트/케이블(USB2·허브 금지)  "
                            "②다른 프로세스 점유(realsense-viewer 종료)  "
                            "③rs-enumerate-devices 로 640x480 bgr8 @FPS 지원 여부  "
                            "④--fps 를 15 로 낮추거나 --frame-timeout-ms 를 늘려보기."
                        ) from e
                    continue
                color_frame = frames.get_color_frame()
                if not color_frame:
                    continue
                img = np.asanyarray(color_frame.get_data())
                res = pose.process(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))

                now = _t.time()
                angles = last
                detected = False
                head_detected = False  # [v5] 미리보기 표시용

                if res.pose_world_landmarks and res.pose_landmarks:
                    wl = res.pose_world_landmarks.landmark
                    vl = res.pose_landmarks.landmark
                    ok = all(vl[LM[k]].visibility >= min_vis for k in arm_keys)
                    if ok:
                        keys = arm_keys + (("Rindex", "Rpinky", "Lindex", "Lpinky")
                                           if use_wrist else ())
                        P = {k: np.array([wl[LM[k]].x, wl[LM[k]].y, wl[LM[k]].z], float)
                             for k in keys}

                        handR = handL = None
                        if use_wrist:
                            if all(vl[LM[k]].visibility >= min_vis for k in ("Rindex", "Rpinky")):
                                handR = {"index": P["Rindex"], "pinky": P["Rpinky"]}
                            if all(vl[LM[k]].visibility >= min_vis for k in ("Lindex", "Lpinky")):
                                handL = {"index": P["Lindex"], "pinky": P["Lpinky"]}

                        fR = arm_features(P["Rsh"], P["Rel"], P["Rwr"], -1.0, handR)
                        fL = arm_features(P["Lsh"], P["Lel"], P["Lwr"], +1.0, handL)

                        raw, hold = map_features_to_joints(fR, fL)

                        mRu = med["Ru"].push_and_median(fR["_len_u"])
                        mRf = med["Rf"].push_and_median(fR["_len_f"])
                        mLu = med["Lu"].push_and_median(fL["_len_u"])
                        mLf = med["Lf"].push_and_median(fL["_len_f"])

                        def bad(v, m):
                            return m > 1e-6 and abs(v - m) / m > ARMLEN_TOL
                        if bad(fR["_len_u"], mRu) or bad(fR["_len_f"], mRf):
                            hold.update(RIGHT_ARM)
                        if bad(fL["_len_u"], mLu) or bad(fL["_len_f"], mLf):
                            hold.update(LEFT_ARM)

                        stabilized = stab.process(raw, hold, now)
                        angles = apply_filter(bank, stabilized, now)

                        # ---------- [v5.2] 머리 회전 감지: 눈 기준(귀 미사용) ----------
                        face_ok = all(vl[LM[k]].visibility >= min_vis for k in face_keys)
                        if face_ok:
                            def _p(k):
                                return np.array([wl[LM[k]].x, wl[LM[k]].y, wl[LM[k]].z], float)
                            nose = _p("nose")
                            eyeL, eyeR = _p("Leye"), _p("Reye")
                            head_raw = head_feature(nose, eyeL, eyeR)   # 눈만 기준
                        else:
                            head_raw = None   # 눈 폐색 -> 홀드
                        head_raw = head_zeroer.value(head_raw, now)  # [v5.1] 중립 영점 빼기
                        head_val = head_tracker.update(head_raw, now)
                        head_detected = head_raw is not None
                        angles = dict(angles)
                        angles[HEAD_JOINT] = head_val
                        # --------------------------------------------------------

                        last = angles
                        detected = True

                    mp_draw.draw_landmarks(img, res.pose_landmarks, mp_pose.POSE_CONNECTIONS)

                # [foxglove/headless] 창 키 입력이 없으니 자동으로 녹화 시작
                if autostart and state == "wait":
                    if countdown > 0:
                        state = "count"; count_start = now
                        print(f"[autostart] 카운트다운 {countdown:.0f}s")
                    else:
                        state = "rec"; t0 = now; print("[autostart] 녹화 시작!")

                if state == "count":
                    remain = countdown - (now - count_start)
                    if remain <= 0:
                        state = "rec"; t0 = now; print("녹화 시작!")
                    else:
                        cv2.putText(img, f"{int(remain) + 1}", (280, 260),
                                    cv2.FONT_HERSHEY_SIMPLEX, 4.0, (0, 0, 255), 6)
                if state == "rec":
                    t = now - t0
                    if duration > 0 and t > duration:
                        break
                    if angles is not None:
                        rows.append((round(t, 3), angles))
                    label = f"REC t={t:5.2f}s frames={len(rows)} q=stop"; col = (0, 0, 255)
                elif state == "count":
                    label = "get ready..."; col = (0, 165, 255)
                else:
                    head_tag = "HEAD" if head_detected else "head?"  # [v5]
                    zero_tag = "ZERO-OK" if head_zeroer.locked() else "look-front"  # [v5.1]
                    label = (f"PREVIEW ({'DETECT' if detected else 'NO POSE'}/{head_tag}/{zero_tag}) "
                             f"SPACE=start z=rezero q=cancel")
                    col = (0, 255, 0) if detected else (0, 165, 255)

                cv2.putText(img, label, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.6, col, 2)

                if fox is not None:                 # [foxglove] 프리뷰를 웹소켓으로 송출
                    fox.publish(img)
                if not headless:
                    cv2.imshow("make_motion (v5: arm + head + foxglove)", img)
                    key = cv2.waitKey(1) & 0xFF
                else:
                    key = -1                        # headless: 창 키 입력 불가(자동시작/자동정지 사용)
                if key in (ord('q'), 27):
                    if state == "rec":
                        break
                    cancelled = True; break
                if key == ord('z'):                       # [v5.1] 정면 응시 후 영점 재보정
                    head_zeroer.reset()
                    print("머리 영점 재보정: 정면을 응시하세요.")
                if key == 32 and state == "wait":
                    if countdown > 0:
                        state = "count"; count_start = _t.time(); print(f"카운트다운 {countdown:.0f}s")
                    else:
                        state = "rec"; t0 = _t.time(); print("녹화 시작!")
    finally:
        pipeline.stop()
        if fox is not None:
            try:
                fox.close()
            except Exception:
                pass
        if not headless:
            cv2.destroyAllWindows()

    if cancelled:
        raise RuntimeError("사용자가 취소했습니다.")
    if not rows:
        raise RuntimeError("캡처된 유효 프레임 없음.")
    return rows


# ===================== 데모 =====================
def capture_demo(duration, dt, use_wrist=False):
    rows = []
    n = int(round(duration / dt)) + 1
    for i in range(n):
        t = round(i * dt, 3)
        ph = t / duration if duration > 0 else 0.0
        u = (0.5, -0.3, 0.3)
        flex = math.pi / 2.0
        humeral = math.radians(45.0) * math.sin(2 * math.pi * 2 * ph)
        w_pitch = math.radians(20.0) * math.sin(2 * math.pi * 2 * ph) if use_wrist else 0.0
        pron    = math.radians(25.0) * math.sin(2 * math.pi * 1 * ph) if use_wrist else None
        f = {"u": u, "flex": flex, "humeral": humeral, "pron": pron,
             "w_pitch": w_pitch, "w_yaw": 0.0}
        mv = map_features_to_joints(f, f)[0]
        # [v5] 데모 머리 좌우 흔들기(1Hz)
        mv[HEAD_JOINT] = clamp(math.radians(30.0) * math.sin(2 * math.pi * 1 * ph), *HEAD_LIMITS)
        rows.append((t, mv))
    return rows


def capture_demo_wrist(duration, dt, amp=0.8):
    """구간 분리 확인: 1)humeral 2)pron 3)w_pitch 4)w_yaw. (머리는 0 유지)"""
    rows = []
    n = int(round(duration / dt)) + 1
    u = (0.3, -0.2, 0.2)
    flex = math.pi / 2.0
    for i in range(n):
        t = round(i * dt, 3)
        ph = t / duration if duration > 0 else 0.0
        seg = ph * 4.0
        s = seg - math.floor(seg)
        swing = amp * math.sin(2 * math.pi * s)
        hume = 0.0; pron = 0.0; wp = 0.0; wy = 0.0
        if seg < 1.0:
            hume = swing
        elif seg < 2.0:
            pron = swing
        elif seg < 3.0:
            wp = swing
        else:
            wy = swing
        f = {"u": u, "flex": flex, "humeral": hume, "pron": pron, "w_pitch": wp, "w_yaw": wy}
        mv = map_features_to_joints(f, f)[0]
        mv[HEAD_JOINT] = 0.0  # [v5]
        rows.append((t, mv))
    return rows


# ===================== 저장 =====================
def write_csv(rows, out, decimals):
    cols = ["time"] + JOINTS + [HEAD_JOINT]   # [v5] 머리 열 추가
    with open(out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=cols)
        w.writeheader()
        for t, angles in rows:
            row = {"time": t}
            for j in JOINTS:
                lo, hi = JOINT_LIMITS[j]
                v = round(clamp(float(angles[j]), lo, hi), decimals)
                row[j] = clamp(v, lo, hi)
            # [v5] 머리 열(라디안). 없는 행은 0.
            lo, hi = HEAD_LIMITS
            hv = round(clamp(float(angles.get(HEAD_JOINT, 0.0)), lo, hi), decimals)
            row[HEAD_JOINT] = clamp(hv, lo, hi)
            w.writerow(row)
    print(f"wrote {len(rows)} rows to {out}")


def main():
    global MAX_JOINT_RATE, HEAD_AXIS, HEAD_SIGN, HEAD_GAIN
    ap = argparse.ArgumentParser(description="SH_Humanoid motion CSV (v5: arm + head).")
    ap.add_argument("--mode", choices=["realsense", "demo", "demo_wrist"], default="realsense")
    ap.add_argument("--out", default="motion.csv")
    ap.add_argument("--duration", type=float, default=8.0)
    ap.add_argument("--fps", type=int, default=30)
    ap.add_argument("--countdown", type=float, default=3.0)
    ap.add_argument("--dt", type=float, default=0.1)
    ap.add_argument("--decimals", type=int, default=4)
    ap.add_argument("--filter", choices=["oneeuro", "ema", "none"], default="oneeuro")
    ap.add_argument("--mincutoff", type=float, default=1.0)
    ap.add_argument("--beta", type=float, default=0.02)
    ap.add_argument("--minvis", type=float, default=0.5)
    ap.add_argument("--wrist", action="store_true",
                    help="전완 pronation(5/12)+손목(6/7,13/14) 사용. 손 랜드마크 필요. "
                         "(joint3/10 humeral, 머리 Revolute15 는 --wrist 없이도 계산됨)")
    ap.add_argument("--maxrate", type=float, default=MAX_JOINT_RATE,
                    help="슬루 속도 상한(rad/s). 튐이 남으면 낮추기.")
    # [v5] 머리 축/부호/게인을 커맨드라인에서도 조정 가능하게
    ap.add_argument("--head-axis", choices=["yaw", "pitch"], default=HEAD_AXIS,
                    help="머리(Revolute15) 구동 축. yaw=좌우 회전(기본), pitch=끄덕임.")
    ap.add_argument("--head-sign", type=float, default=HEAD_SIGN,
                    help="머리 방향 부호. 반대면 -1.")
    ap.add_argument("--head-gain", type=float, default=HEAD_GAIN,
                    help="머리 각 크기 배율.")
    ap.add_argument("--head-calib-sec", type=float, default=1.0,
                    help="시작 시 '정면 응시' 영점 보정 시간(초). 카메라가 위/아래에 있어 "
                         "생기는 바이어스 제거. 프리뷰에서 'z' 로 재보정.")
    # [foxglove] 원격 프리뷰 스트리밍 / 헤드리스 실행
    ap.add_argument("--foxglove", action="store_true",
                    help="Foxglove 로 카메라 프리뷰 스트리밍(ws://<이 컴퓨터 IP>:port). foxglove_stream 모듈 필요. "
                         "(주의: 라이다 foxglove_bridge 와 포트가 겹치면 하나만 뜸. 통합하려면 --ros-image 사용)")
    ap.add_argument("--foxglove-port", type=int, default=8765)
    ap.add_argument("--ros-image", action="store_true",
                    help="카메라 프리뷰를 ROS2 토픽(sensor_msgs/CompressedImage)으로 발행. "
                         "실행 중인 foxglove_bridge 가 라이다·TF 와 함께 하나의 연결(8765)로 통합 송출(권장). "
                         "ROS 환경 소싱 + ros_stream 모듈 필요.")
    ap.add_argument("--ros-image-topic", default="/camera/image",
                    help="--ros-image 발행 토픽 이름.")
    ap.add_argument("--headless", action="store_true",
                    help="로컬 cv2 창 없이 실행(원격/서버). 창 키 입력 불가하므로 --autostart 권장.")
    ap.add_argument("--autostart", action="store_true",
                    help="SPACE 없이 자동 녹화 시작(headless 용). --duration 으로 자동 종료.")
    ap.add_argument("--frame-timeout-ms", type=int, default=15000,
                    help="RealSense 프레임 대기 타임아웃(ms). 'Frame didn't arrive' 나면 늘리기.")
    args = ap.parse_args()

    MAX_JOINT_RATE = args.maxrate
    # [v5] 머리 파라미터 반영
    HEAD_AXIS = args.head_axis
    HEAD_SIGN = args.head_sign
    HEAD_GAIN = args.head_gain

    if args.mode == "realsense":
        rows = capture_realsense(args.duration, args.fps, args.countdown,
                                 args.filter, args.mincutoff, args.beta,
                                 args.minvis, args.wrist, args.head_calib_sec,
                                 args.foxglove, args.foxglove_port,
                                 args.headless, args.autostart, args.frame_timeout_ms,
                                 args.ros_image, args.ros_image_topic)
    elif args.mode == "demo_wrist":
        dur = args.duration if args.duration and args.duration > 0 else 12.0
        print("[demo_wrist] 구간 1)humeral(3/10)  2)pron(5/12)  3)w_pitch(6/13)  4)w_yaw(7/14)")
        rows = capture_demo_wrist(dur, args.dt)
    else:
        rows = capture_demo(args.duration if args.duration > 0 else 6.0, args.dt, args.wrist)

    write_csv(rows, args.out, args.decimals)
    print("튐이 남으면 --maxrate 를 낮추거나(4~), --mincutoff 를 낮추세요(0.5~).")
    print("부호 반대면 USER_TO_MOVEIT_SIGN 해당 관절만 뒤집기.")
    print("[v5] 머리가 반대로 돌면 --head-sign -1, 축이 다르면 --head-axis pitch 로.")


if __name__ == "__main__":
    main()
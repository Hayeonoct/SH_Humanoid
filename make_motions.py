#!/usr/bin/env python3
"""
make_motion.py  --  모션(각도 CSV) 생성  [SH_Humanoid]   (v4: joint3=상완roll 재정의 + 폐색/튐 대응)

핵심 변경 (v3 대비):
  1) joint3/joint10 재정의 : (v3)전완 twist 위쪽 -> (v4)'상완 축회전(humeral roll)'.
       - 실제 로봇에서 joint3 는 팔꿈치보다 위(상완 맨 아래)에 있고 축이 상완 긴축이다.
         팔꿈치를 굽힌 채 돌리면 전완이 상완축을 중심으로 '호를 그리며' 쓸린다(=인사 웨이브).
       - 그래서 손바닥 법선(pronation) 대신 '전완 f 가 상완축 u 를 도는 각'으로 구동한다.
       - 이 신호는 어깨/팔꿈치/손목 큰 랜드마크만 쓰므로 안정적이고 손 폐색에 강하다.
         => joint3 는 --wrist 없이도(손 없이도) 계산된다.
  2) joint3 <-> joint5 분리 : v3 의 7:3 twist 분배 폐기. 둘은 다른 축(상완roll vs 전완pron).
       - joint5/joint12 = 전완 pronation(손바닥 법선). 손 필요 -> --wrist 로 켬. 노이즈 게이팅.
  3) 폐색/튐 대응(캡처 경로):
       (a) 팔 길이 일관성 홀드 : |상완|,|전완| 이 러닝 중앙값에서 크게 벗어나면 그 팔 홀드.
       (b) 슬루 속도 제한       : 프레임 간 각속도가 상한을 넘으면 잘라냄(비물리적 점프 제거).
       (c) 관측성 게이팅        : 팔꿈치가 너무 펴지면 humeral 불가 -> 홀드,
                                  손가락이 거의 평행이면 pronation 불가 -> 홀드.
  4) joint6/13(손목 굽힘), joint7/14(손목 좌우)는 유지.

관절 배정:
  팔 앞뒤(pitch)        : joint1 / joint8
  팔 좌우 벌림(abd)     : joint2 / joint9
  상완 축회전(humeral)  : joint3 / joint10   <-- 손 없이도 계산(팔꿈치 굽었을 때 관측)
  팔꿈치 굽힘(elbow)    : joint4 / joint11
  전완 pronation(pron)  : joint5 / joint12   <-- --wrist
  손목 굽힘(w_pitch)    : joint6 / joint13   <-- --wrist
  손목 좌우(w_yaw)      : joint7 / joint14   <-- --wrist

모드:
  --mode realsense : RealSense(color) + MediaPipe. SPACE=녹화 시작, q=종료.
  --mode demo      : 카메라 없이 합성 동작(팔꿈치 굽힌 채 상완roll 로 안팎 웨이브 + 손목).
  --mode demo_wrist: 축 확인용(humeral / pron / w_pitch / w_yaw 를 구간별로 분리).

보정: 부호 반대면 USER_TO_MOVEIT_SIGN 의 해당 관절만 뒤집기. 크기는 *_GAIN. 좌우는 MIRROR.
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
#   규칙: 왼팔 = 기준(+),  오른팔 = 반전(-).  (abd 는 ABD_* 보간에서 이미 반전 처리)
#   ※ humeral/pron/손목 '방향'은 로봇에서 확인 후 필요 시 여기서 뒤집기.
USER_TO_MOVEIT_SIGN = {
    'joint1': -1.0, 'joint2': 1.0, 'joint3': 1.0, 'joint4': -1.0,
    'joint5': -1.0, 'joint6': 1.0, 'joint7':  1.0,
    'joint8':  1.0, 'joint9':  1.0, 'joint10': 1.0, 'joint11': 1.0,
    'joint12': 1.0, 'joint13': 1.0, 'joint14': 1.0,
}

# 담당 관절.
#   humeral = 상완 축회전(joint3/10), pron = 전완 pronation(joint5/12),
#   w_pitch = 손목 굽힘(joint6/13), w_yaw = 손목 좌우(joint7/14).
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
MIRROR = False

# --- 관측성 게이팅 임계값 ---
# humeral 은 팔꿈치가 어느 정도 굽어야 관측됨. fp_sin = 전완이 상완축과 벌어진 정도(sin).
FLEX_MIN_SIN = 0.25      # 약 14도 이상 굽어야 humeral 신뢰(이하 -> 홀드)
# pronation 은 검지/새끼가 어느 정도 벌어져야 손바닥 법선이 안정. (손가락 사이각 sin)
PALM_MIN_SIN = 0.20      # 이하(손바닥 정면 등) -> pronation 홀드

# --- 폐색/튐 대응 파라미터(캡처 경로) ---
ARMLEN_TOL   = 0.35      # 상완/전완 길이가 러닝중앙값 대비 이 비율 넘게 튀면 그 팔 홀드
MAX_JOINT_RATE = 6.0     # rad/s. 프레임 간 각속도 상한(슬루 제한). 넘으면 잘라냄.

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
        # 1) 홀드: 관측 불가/폐색 관절은 마지막 값 유지
        if self.last is not None:
            for j in hold_joints:
                out[j] = self.last[j]
        # 2) 슬루 속도 제한
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

    # 상완 축회전 (joint3/10) : 관측 불가면 홀드
    if humeral is None:
        hold.add(jh)
    else:
        mv[jh] = clamp(USER_TO_MOVEIT_SIGN[jh] * HUMERAL_GAIN * humeral, *JOINT_LIMITS[jh])

    # 전완 pronation (joint5/12) : 관측 불가면 홀드
    if pron is None:
        hold.add(jpr)
    else:
        mv[jpr] = clamp(USER_TO_MOVEIT_SIGN[jpr] * PRON_GAIN * pron, *JOINT_LIMITS[jpr])

    # 손목
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
        hold.update(RIGHT_ARM)   # 팔 자체가 안 잡히면 전체 홀드
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


def arm_features(sh, el, wr, outward_sign, hand=None):
    """
    - flex(팔꿈치) : 상완/전완 내적.
    - humeral(joint3): 전완 f 가 상완축 u 를 도는 각. 팔꿈치가 충분히 굽어야 관측(아니면 None).
                       손 랜드마크 불필요 -> 폐색에 강함.
    - pron(joint5)   : 손바닥 법선의 전완축 둘레 회전. 손 필요 + 손가락 벌어져야 관측(아니면 None).
    - w_pitch/w_yaw  : 손목 굽힘/좌우. 손 필요(없으면 0=중립).
    """
    uvec = mp_to_base(el - sh)
    fvec = mp_to_base(wr - el)
    u = _unit(uvec)
    f = _unit(fvec)

    a_fwd  = float(u[0])
    a_side = outward_sign * float(u[1])
    a_up   = float(u[2])

    flex = math.acos(clamp(float(np.dot(u, f)), -1.0, 1.0))

    # ---- 상완 축회전(humeral roll) : 전완이 상완축 u 를 도는 각 ----
    fp = f - float(np.dot(f, u)) * u        # 전완에서 상완축 성분 제거
    fp_sin = float(np.linalg.norm(fp))      # = sin(팔꿈치 벌어진 각). 펴지면 0 근처.
    humeral = None
    if fp_sin >= FLEX_MIN_SIN:
        ref = np.array([0.0, 0.0, 1.0])                 # 기준: 로봇 상단(Z)
        e1 = ref - float(np.dot(ref, u)) * u
        if float(np.linalg.norm(e1)) < 1e-3:            # u 가 수직이면 전방축으로 대체
            ref2 = np.array([1.0, 0.0, 0.0])
            e1 = ref2 - float(np.dot(ref2, u)) * u
        e1 = _unit(e1)
        e2 = np.cross(u, e1)
        humeral = math.atan2(outward_sign * float(np.dot(fp, e2)), float(np.dot(fp, e1)))

    # ---- 손목/전완 pronation (손 필요) ----
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

        # pronation: 손가락이 충분히 벌어졌을 때만(법선 안정) 계산
        iu = _unit(idx); pu = _unit(pky)
        spread = float(np.linalg.norm(np.cross(iu, pu)))   # sin(손가락 사이각)
        if spread >= PALM_MIN_SIN:
            n = _unit(np.cross(idx, pky))
            pron = math.atan2(outward_sign * float(np.dot(n, e_side)), float(np.dot(n, e_up)))

    return {"u": (a_side, a_up, a_fwd), "flex": flex,
            "humeral": humeral, "pron": pron, "w_pitch": w_pitch, "w_yaw": w_yaw,
            "_len_u": float(np.linalg.norm(uvec)), "_len_f": float(np.linalg.norm(fvec))}


# ===================== RealSense(color) + MediaPipe =====================
LM = {"Rsh": 12, "Rel": 14, "Rwr": 16, "Lsh": 11, "Lel": 13, "Lwr": 15,
      "Rindex": 20, "Rpinky": 18, "Lindex": 19, "Lpinky": 17}


class RunningMedian:
    """최근 N개의 중앙값(팔 길이 일관성 체크용)."""
    def __init__(self, n=31):
        self.n = n; self.buf = []
    def push_and_median(self, x):
        self.buf.append(x)
        if len(self.buf) > self.n:
            self.buf.pop(0)
        return float(np.median(self.buf))


def capture_realsense(duration, fps, countdown, filt_kind, min_cutoff, beta,
                      min_vis, use_wrist=False):
    import cv2
    import pyrealsense2 as rs
    import mediapipe as mp
    import time as _t

    mp_pose = mp.solutions.pose
    mp_draw = mp.solutions.drawing_utils

    pipeline = rs.pipeline()
    cfg = rs.config()
    cfg.enable_stream(rs.stream.color, 640, 480, rs.format.bgr8, fps)
    pipeline.start(cfg)

    bank = make_filter_bank(filt_kind, min_cutoff, beta)
    stab = Stabilizer(MAX_JOINT_RATE)
    med = {"Ru": RunningMedian(), "Rf": RunningMedian(),
           "Lu": RunningMedian(), "Lf": RunningMedian()}

    rows = []
    last = None
    state = "wait"; t0 = None; count_start = None; cancelled = False

    arm_keys = ("Rsh", "Rel", "Rwr", "Lsh", "Lel", "Lwr")
    print("프리뷰 중. SPACE=녹화 시작, q/ESC=취소.")

    try:
        with mp_pose.Pose(model_complexity=1, smooth_landmarks=True,
                          min_detection_confidence=0.6, min_tracking_confidence=0.6) as pose:
            while True:
                frames = pipeline.wait_for_frames()
                color_frame = frames.get_color_frame()
                if not color_frame:
                    continue
                img = np.asanyarray(color_frame.get_data())
                res = pose.process(cv2.cvtColor(img, cv2.COLOR_BGR2RGB))

                now = _t.time()
                angles = last
                detected = False

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

                        # (a) 팔 길이 일관성: 중앙값 대비 크게 벗어나면 그 팔 전체 홀드
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

                        # (b) 홀드 + 슬루 제한 -> (c) One Euro
                        stabilized = stab.process(raw, hold, now)
                        angles = apply_filter(bank, stabilized, now)
                        last = angles
                        detected = True

                    mp_draw.draw_landmarks(img, res.pose_landmarks, mp_pose.POSE_CONNECTIONS)

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
                    label = f"PREVIEW ({'DETECT' if detected else 'NO POSE'}) SPACE=start q=cancel"
                    col = (0, 255, 0) if detected else (0, 165, 255)

                cv2.putText(img, label, (10, 25), cv2.FONT_HERSHEY_SIMPLEX, 0.6, col, 2)
                cv2.imshow("make_motion (v4: humeral roll + gating)", img)

                key = cv2.waitKey(1) & 0xFF
                if key in (ord('q'), 27):
                    if state == "rec":
                        break
                    cancelled = True; break
                if key == 32 and state == "wait":
                    if countdown > 0:
                        state = "count"; count_start = _t.time(); print(f"카운트다운 {countdown:.0f}s")
                    else:
                        state = "rec"; t0 = _t.time(); print("녹화 시작!")
    finally:
        pipeline.stop()
        cv2.destroyAllWindows()

    if cancelled:
        raise RuntimeError("사용자가 취소했습니다.")
    if not rows:
        raise RuntimeError("캡처된 유효 프레임 없음.")
    return rows


# ===================== 데모 =====================
def capture_demo(duration, dt, use_wrist=False):
    """
    데모: 팔꿈치를 90°로 굽힌 채 '상완 축회전(humeral)'으로 손을 안팎으로 흔든다(=인사 웨이브).
      - 상완은 옆으로 든 자세로 고정, humeral 만 좌우로 흔들어 전완이 호를 그리게 함.
      - use_wrist 면 손목 굽힘(w_pitch)과 전완 pronation 도 살짝 넣어 확인.
    """
    rows = []
    n = int(round(duration / dt)) + 1
    for i in range(n):
        t = round(i * dt, 3)
        ph = t / duration if duration > 0 else 0.0
        u = (0.5, -0.3, 0.3)                                  # 상완: 옆으로 든 고정 자세
        flex = math.pi / 2.0                                  # 팔꿈치 90도
        humeral = math.radians(45.0) * math.sin(2 * math.pi * 2 * ph)   # 안팎 웨이브 2회
        w_pitch = math.radians(20.0) * math.sin(2 * math.pi * 2 * ph) if use_wrist else 0.0
        pron    = math.radians(25.0) * math.sin(2 * math.pi * 1 * ph) if use_wrist else None
        f = {"u": u, "flex": flex, "humeral": humeral, "pron": pron,
             "w_pitch": w_pitch, "w_yaw": 0.0}
        rows.append((t, map_features_to_joints(f, f)[0]))
    return rows


def capture_demo_wrist(duration, dt, amp=0.8):
    """구간 분리 확인: 1)humeral(3/10)  2)pron(5/12)  3)w_pitch(6/13)  4)w_yaw(7/14)."""
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
        rows.append((t, map_features_to_joints(f, f)[0]))
    return rows


# ===================== 저장 =====================
def write_csv(rows, out, decimals):
    with open(out, "w", newline="") as f:
        w = csv.DictWriter(f, fieldnames=["time"] + JOINTS)
        w.writeheader()
        for t, angles in rows:
            row = {"time": t}
            for j in JOINTS:
                lo, hi = JOINT_LIMITS[j]
                v = round(clamp(float(angles[j]), lo, hi), decimals)
                row[j] = clamp(v, lo, hi)
            w.writerow(row)
    print(f"wrote {len(rows)} rows to {out}")


def main():
    global MAX_JOINT_RATE
    ap = argparse.ArgumentParser(description="SH_Humanoid motion CSV (v4).")
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
                         "(joint3/10 humeral 은 --wrist 없이도 계산됨)")
    ap.add_argument("--maxrate", type=float, default=MAX_JOINT_RATE,
                    help="슬루 속도 상한(rad/s). 튐이 남으면 낮추기.")
    args = ap.parse_args()

    MAX_JOINT_RATE = args.maxrate

    if args.mode == "realsense":
        rows = capture_realsense(args.duration, args.fps, args.countdown,
                                 args.filter, args.mincutoff, args.beta,
                                 args.minvis, args.wrist)
    elif args.mode == "demo_wrist":
        dur = args.duration if args.duration and args.duration > 0 else 12.0
        print("[demo_wrist] 구간 1)humeral(3/10)  2)pron(5/12)  3)w_pitch(6/13)  4)w_yaw(7/14)")
        rows = capture_demo_wrist(dur, args.dt)
    else:
        rows = capture_demo(args.duration if args.duration > 0 else 6.0, args.dt, args.wrist)

    write_csv(rows, args.out, args.decimals)
    print("튐이 남으면 --maxrate 를 낮추거나(4~), --mincutoff 를 낮추세요(0.5~).")
    print("부호 반대면 USER_TO_MOVEIT_SIGN 해당 관절만 뒤집기.")


if __name__ == "__main__":
    main()
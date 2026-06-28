import streamlit as st
import math
import subprocess
import time

st.set_page_config(page_title="ROS2 정밀 모터 제어기", layout="centered")

# ==========================================
# 0. 세션 상태(Session State) 강제 기억 장치
# ==========================================
if 'enabled_axes' not in st.session_state:
    st.session_state.enabled_axes = set()
    
# 🚨 추가된 트릭: 사용자의 선택 리스트가 날아가지 않도록 메모리에 박제합니다.
if 'selected_axes' not in st.session_state:
    st.session_state.selected_axes = []

# ==========================================
# 최신 하드웨어 모터 ID 매핑
# ==========================================
JOINT_MAPPING = {
    1: {"name": "left_shoulder_pitch", "motor_id": 34},
    2: {"name": "left_shoulder_roll", "motor_id": 113},
    3: {"name": "left_shoulder_yaw", "motor_id": 125},
    4: {"name": "left_elbow_pitch", "motor_id": 52},
    5: {"name": "left_wrist_yaw", "motor_id": 105},
    6: {"name": "left_wrist_pitch", "motor_id": 115},
    7: {"name": "left_wrist_roll", "motor_id": 57},
    8: {"name": "right_shoulder_pitch", "motor_id": 51},
    9: {"name": "right_shoulder_roll", "motor_id": 32},
    10: {"name": "right_shoulder_yaw", "motor_id": 33},
    11: {"name": "right_elbow_pitch", "motor_id": 31},
    12: {"name": "right_wrist_yaw", "motor_id": 35},
    13: {"name": "right_wrist_pitch", "motor_id": 36},
    14: {"name": "right_wrist_roll", "motor_id": 37},
    15: {"name": "neck_yaw", "motor_id": 15},
}

all_motor_ids = [info['motor_id'] for info in JOINT_MAPPING.values()]

# ==========================================
# ROS 2 서비스 호출 콜백 함수들
# ==========================================
def enable_all_cb():
    cmd1 = f"""ros2 service call /upper_body/set_run_mode ros2_interfaces/srv/SetRunMode "{{mode: 1, motor_id_list: {all_motor_ids}}}" """
    cmd2 = """ros2 service call /upper_body/enable_motors ros2_interfaces/srv/EnableMotors "{enable_all: true, motor_id_list: []}" """
    subprocess.run(cmd1, shell=True)
    subprocess.run(cmd2, shell=True)
    st.session_state.enabled_axes = set(JOINT_MAPPING.keys())

def disable_all_cb():
    cmd = f"""ros2 service call /upper_body/disable_motors ros2_interfaces/srv/SimpleMotorResult "{{motor_id_list: {all_motor_ids}}}" """
    subprocess.run(cmd, shell=True)
    st.session_state.enabled_axes.clear()

def enable_single_cb(axis_id, motor_id):
    cmd1 = f"""ros2 service call /upper_body/set_run_mode ros2_interfaces/srv/SetRunMode "{{mode: 1, motor_id_list: [{motor_id}]}}" """
    cmd2 = f"""ros2 service call /upper_body/enable_motors ros2_interfaces/srv/EnableMotors "{{enable_all: false, motor_id_list: [{motor_id}]}}" """
    
    res1 = subprocess.run(cmd1, shell=True, capture_output=True, text=True)
    res2 = subprocess.run(cmd2, shell=True, capture_output=True, text=True)
    
    if res1.returncode == 0 and res2.returncode == 0:
        time.sleep(0.7)
        st.session_state.enabled_axes.add(axis_id)
    else:
        st.toast(f"Axis {axis_id} 통신 실패! 가상 로봇이 켜져 있는지 확인하세요.", icon="🚨")

# ==========================================
# 사이드바: 1. 전원 제어 및 글로벌 설정
# ==========================================
st.sidebar.header("🔌 시스템 전원 제어")
col1, col2 = st.sidebar.columns(2)
col1.button("🟢 Enable All", on_click=enable_all_cb, type="primary", use_container_width=True)
col2.button("🔴 Disable All", on_click=disable_all_cb, use_container_width=True)

st.sidebar.divider()

st.sidebar.header("⚙️ 모션 설정")
cmd_mode_str = st.sidebar.selectbox("제어 모드", ["1: POSITION", "2: VELOCITY", "3: EFFORT"], index=0)
cmd_mode = int(cmd_mode_str.split(":")[0])

# global_kp = st.sidebar.number_input("전체 Kp 게인", value=30.0, step=1.0)
# global_kd = st.sidebar.number_input("전체 Kd 게인", value=0.5, step=0.1)

# ==========================================
# 메인 화면: 관절 선택 및 동적 입력 UI
# ==========================================
st.title("🦾 상체 다관절 모터 정밀 제어 패널")
st.header("🎯 타겟 관절 선택 및 제어")

# 🚨 다시 부활한 동적 텍스트 함수
def format_joint_dynamic(axis_id):
    info = JOINT_MAPPING[axis_id]
    state = "🟢" if axis_id in st.session_state.enabled_axes else "🔴"
    return f"{state} Axis {axis_id} : {info['name']} (ID: {info['motor_id']})"

# 🚨 default 값에 메모리(st.session_state.selected_axes)를 할당하여 선택 풀림 완벽 방어!
current_selection = st.multiselect(
    "제어할 관절을 찾아 선택하세요 (여러 개 선택 가능)",
    options=list(JOINT_MAPPING.keys()),
    default=st.session_state.selected_axes,
    format_func=format_joint_dynamic,
    placeholder="여기를 클릭하여 관절을 선택하세요..."
)

# 화면이 그려질 때마다 사용자의 현재 선택 상태를 메모리에 다시 저장합니다.
st.session_state.selected_axes = current_selection

st.divider()

motor_ids = [0] * 15
positions = [0.0] * 15
# velocities = [0.0] * 15
# efforts = [0.0] * 15
# kps = [0.0] * 15
# kds = [0.0] * 15

has_ready_target = False 

if st.session_state.selected_axes:
    cols = st.columns(3)
    
    for i, axis_id in enumerate(st.session_state.selected_axes):
        info = JOINT_MAPPING[axis_id]
        motor_id = info['motor_id']
        col = cols[i % 3]
        
        with col:
            is_enabled = axis_id in st.session_state.enabled_axes
            
            st.markdown(f"**{info['name']}**<br>ID: {motor_id}", unsafe_allow_html=True)
            
            if not is_enabled:
                st.button(f"🔌 Axis {axis_id} Enable", key=f"btn_en_{axis_id}", on_click=enable_single_cb, args=(axis_id, motor_id))
            else:
                has_ready_target = True 
                deg_val = st.number_input(
                    "목표 각도 (Degree)", 
                    value=0.0, 
                    step=1.0, 
                    format="%.2f", 
                    key=f"num_{axis_id}"
                )
                
                rad_val = round(math.radians(deg_val), 4)
                st.caption(f"↳ 라디안 변환: **{rad_val} rad**")
                
                idx = axis_id - 1
                motor_ids[idx] = motor_id
                positions[idx] = rad_val
                # kps[idx] = global_kp
                # kds[idx] = global_kd
            
            st.markdown("<br>", unsafe_allow_html=True)
else:
    st.info("👆 위 드롭다운 상자를 클릭해 제어할 관절을 하나 이상 선택해 주세요.")

# ==========================================
# 사이드바: 2. Publish 버튼
# ==========================================
st.sidebar.divider()
st.sidebar.header("🚀 시스템 전송")

cmd = f"""ros2 topic pub --once /upper_body/command ros2_interfaces/msg/UpperBodyCommand "{{header: {{stamp: {{sec: 0, nanosec: 0}}, frame_id: 'upper_body_link'}}, command_mode: {cmd_mode}, motor_id: {motor_ids}, position: {positions}}}" """
# velocity: {velocities}, effort: {efforts}, kp: {kps}, kd: {kds}, duration: 1.0

if st.sidebar.button("🚀 명령어 발사 (Publish)", type="primary", use_container_width=True, disabled=not has_ready_target):
    with st.sidebar.spinner("로봇으로 명령 전송 중..."):
        result = subprocess.run(cmd, shell=True, capture_output=True, text=True)
        
        if result.returncode == 0:
            st.sidebar.success("✅ 제어 명령 전송 완료!")
        else:
            st.sidebar.error(f"❌ 전송 실패: {result.stderr}")

if not has_ready_target and st.session_state.selected_axes:
    st.sidebar.warning("⚠️ 타겟 관절을 먼저 Enable 하세요.")

st.divider()
with st.expander("생성된 Raw 명령어 확인하기"):
    st.code(cmd, language="bash")
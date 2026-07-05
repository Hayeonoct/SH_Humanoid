#!/usr/bin/env python3
"""
ros_stream.py -- OpenCV BGR 프레임을 ROS2 토픽으로 발행(sensor_msgs/CompressedImage).

FoxgloveStreamer(별도 8765 서버)와 '같은 인터페이스'(publish/close)라서
make_motions.py 에서 그대로 바꿔 끼울 수 있다. 이렇게 하면 카메라 이미지가
일반 ROS 토픽으로 나가고, 이미 실행 중인 foxglove_bridge 가 라이다·TF와 함께
하나의 연결(8765)로 내보낸다 -> Foxglove Studio 한 화면에서 같이 볼 수 있음.

사용법:
    from ros_stream import RosImageStreamer
    fox = RosImageStreamer(topic="/camera/image")   # rclpy 초기화 + 퍼블리셔 생성
    fox.publish(img)                                 # 루프 안에서 BGR 프레임 발행
    fox.close()                                      # 종료 시

Foxglove Studio:
    Open connection -> Foxglove WebSocket -> ws://<이 컴퓨터 IP>:8765   (foxglove_bridge)
    Image 패널 추가 -> topic: /camera/image
"""

import time

import cv2

try:
    import rclpy
    from rclpy.node import Node
    from sensor_msgs.msg import CompressedImage
    _ROS_OK = True
except ImportError:
    _ROS_OK = False


class RosImageStreamer:
    def __init__(self, topic="/camera/image", frame_id="camera",
                 max_fps=15, jpeg_quality=70, qos_depth=10):
        """
        topic        : 발행할 ROS 토픽. foxglove_bridge 가 자동으로 브리징한다.
        frame_id     : 이미지 헤더 frame_id.
        max_fps      : 네트워크 부하 제한용 전송 상한.
        jpeg_quality : 1~100. 낮출수록 대역폭 절약.
        """
        self.enabled = _ROS_OK
        self.min_dt = 1.0 / float(max_fps)
        self.quality = int(jpeg_quality)
        self.frame_id = str(frame_id)
        self._t_last = 0.0
        self.node = None
        self._owns_rclpy = False
        if not _ROS_OK:
            print("[ros] rclpy/sensor_msgs 미설치(또는 ROS 환경 미소싱). "
                  "`source /opt/ros/<distro>/setup.bash` 후 다시 실행. (녹화는 정상 진행)")
            return
        if not rclpy.ok():
            rclpy.init()
            self._owns_rclpy = True
        self.node = rclpy.create_node("make_motion_camera")
        self.pub = self.node.create_publisher(CompressedImage, topic, qos_depth)
        print(f"[ros] 카메라 발행 시작: topic={topic}  "
              f"(foxglove_bridge 가 ws://<이 컴퓨터 IP>:8765 로 브리징)")

    def publish(self, bgr_img):
        """BGR(OpenCV) 프레임을 JPEG으로 압축해 ROS 토픽으로 발행. max_fps로 스로틀링."""
        if not self.enabled or self.node is None:
            return
        now = time.time()
        if now - self._t_last < self.min_dt:
            return
        self._t_last = now
        ok, jpg = cv2.imencode(".jpg", bgr_img,
                               [int(cv2.IMWRITE_JPEG_QUALITY), self.quality])
        if not ok:
            return
        msg = CompressedImage()
        msg.header.stamp = self.node.get_clock().now().to_msg()
        msg.header.frame_id = self.frame_id
        msg.format = "jpeg"
        msg.data = jpg.tobytes()
        self.pub.publish(msg)

    def close(self):
        if not self.enabled:
            return
        if self.node is not None:
            try:
                self.node.destroy_node()
            except Exception:
                pass
            self.node = None
        if self._owns_rclpy:
            try:
                rclpy.shutdown()
            except Exception:
                pass
            self._owns_rclpy = False

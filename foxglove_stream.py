#!/usr/bin/env python3
"""
foxglove_stream.py -- OpenCV BGR 프레임을 Foxglove WebSocket으로 스트리밍.

사용법:
    pip install foxglove-sdk

    from foxglove_stream import FoxgloveStreamer
    fox = FoxgloveStreamer(port=8765)      # 서버 시작
    fox.publish(img)                       # 루프 안에서 BGR 프레임 전송
    fox.close()                           # 종료 시

외부 컴퓨터의 Foxglove 앱에서:
    Open connection -> Foxglove WebSocket -> ws://<이 컴퓨터 IP>:8765
    Image 패널 추가 -> topic: /camera/image
"""

import time

import cv2

try:
    import foxglove
    from foxglove.channels import CompressedImageChannel
    from foxglove.schemas import CompressedImage, Timestamp
    _FOXGLOVE_OK = True
except ImportError:
    _FOXGLOVE_OK = False


class FoxgloveStreamer:
    def __init__(self, port=8765, topic="/camera/image", max_fps=15, jpeg_quality=70):
        """
        max_fps      : 네트워크 부하 제한용 전송 상한(카메라 30fps여도 15면 충분히 부드러움)
        jpeg_quality : 1~100. 낮출수록 대역폭 절약.
        """
        self.enabled = _FOXGLOVE_OK
        self.min_dt = 1.0 / float(max_fps)
        self.quality = int(jpeg_quality)
        self._t_last = 0.0
        self.server = None
        if not _FOXGLOVE_OK:
            print("[foxglove] foxglove-sdk 미설치. `pip install foxglove-sdk` 후 다시 실행하면 스트리밍 켜짐. (녹화는 정상 진행)")
            return
        self.server = foxglove.start_server(host="0.0.0.0", port=port)
        self.chan = CompressedImageChannel(topic=topic)
        print(f"[foxglove] 스트리밍 시작: ws://<이 컴퓨터 IP>:{port}  (topic: {topic})")

    def publish(self, bgr_img):
        """BGR(OpenCV) 프레임을 JPEG으로 압축해 전송. max_fps로 스로틀링."""
        if not self.enabled:
            return
        now = time.time()
        if now - self._t_last < self.min_dt:
            return
        self._t_last = now
        ok, jpg = cv2.imencode(".jpg", bgr_img,
                               [int(cv2.IMWRITE_JPEG_QUALITY), self.quality])
        if not ok:
            return
        self.chan.log(CompressedImage(
            timestamp=Timestamp(sec=int(now), nsec=int((now % 1.0) * 1e9)),
            frame_id="camera",
            format="jpeg",
            data=jpg.tobytes(),
        ))

    def close(self):
        if self.enabled and self.server is not None:
            try:
                self.server.stop()
            except Exception:
                pass
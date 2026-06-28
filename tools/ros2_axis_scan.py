#!/usr/bin/env python3
"""Scan connected axes from ROS2 /upper_body/system_state."""

from __future__ import annotations

import argparse
import socket
import struct
import time

import rclpy
from rclpy.node import Node

from ros2_interfaces.msg import UpperBodySystemState


IPC_SOCKET_PATH = "/tmp/hr_controller_cmd.sock"
IPC_MAGIC = 0x4852434D
IPC_VERSION = 1


class IpcCommandType:
    RESCAN_UID = 13


class AxisScanNode(Node):
    def __init__(self, topic: str) -> None:
        super().__init__("upper_body_axis_scan")
        self._last_msg: UpperBodySystemState | None = None
        self._sub = self.create_subscription(
            UpperBodySystemState,
            topic,
            self._on_system_state,
            10,
        )

    def _on_system_state(self, msg: UpperBodySystemState) -> None:
        self._last_msg = msg

    @property
    def last_msg(self) -> UpperBodySystemState | None:
        return self._last_msg


def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(description="Scan connected axes via ROS2")
    p.add_argument(
        "--topic",
        default="/upper_body/system_state",
        help="UpperBodySystemState topic",
    )
    p.add_argument(
        "--timeout-sec",
        type=float,
        default=3.0,
        help="Wait timeout for first system_state message",
    )
    p.add_argument(
        "--axis-id",
        type=int,
        default=0,
        help="Axis target for re-scan (0=all axes)",
    )
    p.add_argument(
        "--rescan-settle-sec",
        type=float,
        default=0.25,
        help="Wait after sending UID re-scan command",
    )
    return p.parse_args()


def send_uid_rescan(axis_id: int) -> tuple[bool, str]:
    if axis_id < 0 or axis_id > 255:
        return False, f"invalid axis_id: {axis_id}"

    payload = struct.pack(
        "<IHHB3xfffff",
        IPC_MAGIC,
        IPC_VERSION,
        IpcCommandType.RESCAN_UID,
        int(axis_id),
        0.0,
        0.0,
        0.0,
        0.0,
        0.0,
    )

    sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
    try:
        sock.sendto(payload, IPC_SOCKET_PATH)
        return True, "ok"
    except OSError as exc:
        return False, str(exc)
    finally:
        sock.close()


def main() -> int:
    args = parse_args()

    ok, err = send_uid_rescan(args.axis_id)
    if not ok:
        print(f"[axis-scan] failed to send UID re-scan command: {err}")
        return 3
    print(f"[axis-scan] UID re-scan command sent (axis_id={args.axis_id})")
    time.sleep(max(0.0, args.rescan_settle_sec))

    rclpy.init()
    node = AxisScanNode(args.topic)

    try:
        deadline = time.monotonic() + max(0.1, args.timeout_sec)
        while time.monotonic() < deadline and node.last_msg is None:
            rclpy.spin_once(node, timeout_sec=0.1)

        msg = node.last_msg
        if msg is None:
            print(f"[axis-scan] timeout: no message on {args.topic}")
            return 2

        connected_ids = []
        for i, is_conn in enumerate(msg.is_connected):
            if is_conn:
                connected_ids.append(i + 1)

        print(
            "[axis-scan] "
            f"state={int(msg.state)} "
            f"connected={len(connected_ids)}/{len(msg.is_connected)}"
        )
        if connected_ids:
            print("[axis-scan] axes:", " ".join(str(x) for x in connected_ids))
        else:
            print("[axis-scan] axes: none")

        return 0

    finally:
        node.destroy_node()
        rclpy.shutdown()


if __name__ == "__main__":
    raise SystemExit(main())

from time import time
import cv2 as cv
import socket
from loguru import logger
import asyncio
import numpy as np
from asyncio import gather, sleep, Queue


def filter_frame(f: np.ndarray):
    return cv.cvtColor(f, cv.COLOR_RGB2GRAY)


async def capture_video_worker(frame_buf: Queue):
    cam = cv.VideoCapture(0)
    try:
        while True:
            ret, f = cam.read()
            if not ret:
                print("cap err")
                return

            # f:np.ndarray
            # f = cv.resize(f,(180,180))

            await frame_buf.put(f)
            cv.imshow("server_origin", f)
            cv.imshow("server_filtered", filter_frame(f))
            cv.waitKey(1)
            await sleep(1 / 50)
    finally:
        cv.destroyAllWindows()


async def subscriber_manager(s: socket.socket, subscribers: set):
    last_seen = {}
    while True:
        try:
            s.recvfrom(1024, socket.MSG_PEEK | socket.MSG_DONTWAIT)
            data, addr = s.recvfrom(1024)
            if data == b"vid_req":
                logger.info(f"Received stream request from {addr}")
                subscribers.add(addr)
                last_seen[addr] = time()
            elif data == b"stop":
                logger.info(f"Received stop request from {addr}")
                subscribers.discard(addr)
                s.sendto(b"ack_stop", addr)
        except BlockingIOError:
            await sleep(1)
        except Exception as e:
            logger.exception(e)
        for addr, last_t in last_seen.copy().items():
            if time() > last_t + 15:
                last_seen.pop(addr)
                logger.info(f"Remove {addr} from subscriber list")


async def stream_worker(frame_buf: Queue, subscribers: set, s: socket.socket):
    while True:
        f: np.ndarray = await frame_buf.get()
        # compress frame
        _, data = cv.imencode(".jpg", f, [cv.IMWRITE_JPEG_QUALITY, 90])
        # _, data = cv.imencode(".png", f)

        # print(len(data))
        try:
            for sub in subscribers.copy():
                s.sendto(data, sub)
        except Exception as e:
            logger.exception(e)

        await sleep(0)


async def main():
    frame_buf = Queue()
    subscribers = set()

    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("127.1", 2048))

    await gather(
        capture_video_worker(frame_buf),
        subscriber_manager(server, subscribers),
        stream_worker(frame_buf, subscribers, server),
    )


asyncio.run(main())

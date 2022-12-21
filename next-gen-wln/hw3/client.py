from datetime import datetime
import socket
from time import sleep, time
import cv2 as cv
import numpy as np

SERVER_ADDR = ("127.0.0.1", 2048)


client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    t = 0

    # receive & show stream video
    while True:
        if time() > t + 5:
            # send stream request
            client.sendto(b"vid_req", SERVER_ADDR)
            t = time()
        data, addr = client.recvfrom(2**16)
        f = cv.imdecode(np.frombuffer(data, dtype=np.uint8), cv.IMREAD_UNCHANGED)
        ff = cv.cvtColor(f, cv.COLOR_BGR2GRAY)
        cv.imshow("client_filtered", ff)
        k = cv.waitKey(int(1000 / 50))
        if k == ord("q"):
            break
        elif k == ord("s"):
            cv.imwrite(f"screenshot_{datetime.now().isoformat()}.png", f)

finally:
    cv.destroyAllWindows()
    while True:
        client.sendto(b"stop", SERVER_ADDR)
        try:
            ack, addr = client.recvfrom(1024, socket.MSG_DONTWAIT)
            if ack == b"ack_stop" and addr == SERVER_ADDR:
                break
        except BlockingIOError:
            pass
        print("not received ack")
        sleep(5)

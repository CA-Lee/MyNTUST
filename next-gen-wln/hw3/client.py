from datetime import datetime
import socket
import cv2 as cv
import numpy as np

SERVER_ADDR = ("127.1", 2048)


client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

try:
    # send stream request
    client.sendto(b"vid_req", SERVER_ADDR)

    # receive & show stream video
    while True:
        data, addr = client.recvfrom(2**16)
        f = cv.imdecode(np.frombuffer(data, dtype=np.uint8), cv.IMREAD_UNCHANGED)
        ff = cv.cvtColor(f, cv.COLOR_RGB2BGR)
        cv.imshow("client_filtered", ff)
        k = cv.waitKey(int(1000 / 50))
        if k == ord("q"):
            break
        elif k == ord("s"):
            cv.imwrite(f"screenshot_{datetime.now().isoformat()}.jpg", f)

finally:
    cv.destroyAllWindows()
    client.sendto(b"stop", SERVER_ADDR)

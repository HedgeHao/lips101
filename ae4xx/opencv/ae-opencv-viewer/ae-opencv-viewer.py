import pyrealsense2 as rs
import cv2
import numpy as np

pipe = rs.pipeline()
pipe.start()

try:
    while cv2.waitKey(1) != ord('q'):
        frame = pipe.wait_for_frames()
        depth = frame.get_depth_frame()
        colorFrame = frame.get_color_frame()

        width = depth.get_width()
        height = depth.get_height()
        distance = depth.get_distance(int(width / 2), int(height / 2))

        image = np.asanyarray(colorFrame.get_data())
        cv2.cvtColor(image, cv2.COLOR_RGB2BGR, image)

        cv2.line(image, (int(width / 2) - 15, int(height / 2)), (int(width / 2) + 15, int(height / 2)), (0, 0, 255))
        cv2.line(image, (int(width / 2), int(height / 2) - 15), (int(width / 2), int(height / 2) + 15), (0, 0, 255))
        cv2.putText(image, str(distance), (0, height), 2, 2, (0, 0, 255))

        cv2.imshow('Preview', image)

finally:
    pipe.stop()

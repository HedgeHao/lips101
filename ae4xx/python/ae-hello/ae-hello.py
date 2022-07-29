import pyrealsense2 as rs

# Create RealSense API object
pipe = rs.pipeline()
# Start video streaming
pipe.start()

try:
    while True:
        # Wait Until frames are available
        frame = pipe.wait_for_frames()

        # Get a depth frame image.
        depth = frame.get_depth_frame()

        # Get frame size.
        width = depth.get_width()
        height = depth.get_height()

        # Get distance from the camera to the center of this frame
        distance = depth.get_distance(int(width / 2), int(height / 2))

        print(f'''Distance ({int(width/2)}, {int(height/2)}): {distance}''')

finally:
    pipe.stop()

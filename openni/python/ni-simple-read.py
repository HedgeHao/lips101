from openni import openni2

openni2.initialize()
dev = openni2.Device.open_any()

depth_stream = dev.create_depth_stream()
depth_stream.start()

video_mode = depth_stream.get_video_mode()
middleIndex = int((video_mode.resolutionY + 1) * video_mode.resolutionX / 2)

try:
    while(True):
        frame = depth_stream.read_frame()
        pDepth = frame.get_buffer_as_uint16()
        print(f'''Distance is {pDepth[middleIndex]} mm''')
finally:
    dev.close()
    openni2.unload()

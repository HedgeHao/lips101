import cv2
from cv2 import imshow
import numpy as np
from openni import openni2

openni2.initialize()
dev = openni2.Device.open_any()

colorStream = dev.create_color_stream()
colorStream.start()

depthStream = dev.create_depth_stream()
depthStream.start()

irStream = dev.create_ir_stream()
irStream.start()

while(cv2.waitKey(1) != 113):
    colorFrame = colorStream.read_frame()
    depthFrame = depthStream.read_frame()
    irFrame = irStream.read_frame()

    colorMat = np.fromstring(colorFrame.get_buffer_as_uint8(), dtype=np.uint8).reshape(480, 640, 3)
    colorMat = cv2.cvtColor(colorMat, cv2.COLOR_BGR2RGB)

    depthMat = np.fromstring(depthFrame.get_buffer_as_uint16(), dtype=np.uint16).reshape(480, 640)
    depthMat = np.uint8(depthMat.astype(float) * 255 / 1024)
    depthMat = cv2.applyColorMap(depthMat, cv2.COLORMAP_JET)

    irMat = np.fromstring(irFrame.get_buffer_as_uint16(), dtype=np.uint16).reshape(480, 640)
    irMat = np.uint8(irMat.astype(float) * 255 / 1024)

    cv2.imshow('Color', colorMat)
    cv2.imshow('Depth', depthMat)
    cv2.imshow('IR', irMat)

colorStream.stop()
depthStream.stop()
irStream.stop()
dev.close()
openni2.unload()

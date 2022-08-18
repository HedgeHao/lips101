#include <stdio.h>
#include <openni2/OpenNI.h>

using namespace openni;

int main()
{
  if (OpenNI::initialize() != STATUS_OK)
  {
    printf("Initialize failed\n%s\n", OpenNI::getExtendedError());
    return 1;
  }

  Device device;
  if (device.open(ANY_DEVICE) != STATUS_OK)
  {
    printf("Couldn't open device\n%s\n", OpenNI::getExtendedError());
    return 2;
  }

  VideoStream depth;
  if (depth.create(device, SENSOR_DEPTH) != STATUS_OK)
  {
    printf("Couldn't create depth stream\n%s\n", OpenNI::getExtendedError());
    return 3;
  }

  if (depth.start() != STATUS_OK)
  {
    printf("Couldn't start the depth stream\n%s\n", OpenNI::getExtendedError());
    return 4;
  }

  VideoFrameRef frame;
  while (true)
  {
    if (depth.readFrame(&frame) != STATUS_OK)
    {
      printf("Read failed!\n%s\n", OpenNI::getExtendedError());
      continue;
    }

    DepthPixel *pDepth = (DepthPixel *)frame.getData();

    int middleIndex = (frame.getHeight() + 1) * frame.getWidth() / 2;

    printf("Distance is %5d mm\n", pDepth[middleIndex]);
  }

  depth.stop();
  depth.destroy();
  device.close();
  OpenNI::shutdown();

  return 0;
}
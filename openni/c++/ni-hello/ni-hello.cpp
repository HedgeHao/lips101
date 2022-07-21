#include <openni2/OpenNI.h>

int main()
{
	if (openni::OpenNI::initialize() != openni::STATUS_OK)
	{
		printf("Initialize Failed:%s\n", openni::OpenNI::getExtendedError());
		return -1;
	}

	openni::Array<openni::DeviceInfo> deviceList;
	openni::OpenNI::enumerateDevices(&deviceList);

	for (int i = 0; i < deviceList.getSize(); i++)
	{
		openni::DeviceInfo info = deviceList[i];
		printf("Name:%s\n", info.getName());
		printf("Uri:%s\n", info.getUri());
		printf("USB Product ID:%d\n", info.getUsbProductId());
		printf("USB Vendor ID:%d\n", info.getUsbVendorId());
		printf("Vendor:%s\n", info.getVendor());
	}

	openni::Device device;
	if (device.open(deviceList[0].getUri()) != openni::STATUS_OK)
	{
		printf("Cannot open device: %s\n", openni::OpenNI::getExtendedError());
		return -1;
	}

	device.close();
	openni::OpenNI::shutdown();
}

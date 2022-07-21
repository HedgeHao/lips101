from openni import openni2

openni2.initialize()
uris = openni2.Device.enumerate_uris()

dev = openni2.Device.open_file(uris[0])
deviceInfo = dev.get_device_info()
print(f'Name: {deviceInfo.name}')
print(f'Uri: {deviceInfo.uri}')
print(f'USB Product ID: {deviceInfo.usbProductId}')
print(f'USB Vendor ID: {deviceInfo.usbVendorId}')
print(f'Vendor: {deviceInfo.vendor}')

dev.close()
openni2.unload()

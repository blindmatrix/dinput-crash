# dinput-crash
There's an issue in dinput.dll (version 10.0.17763.1) when a specific HID device is connected,
this application simply illustrate that problem. The hardware in question is the SteelSeries H Wireless headset.
dinput.dll will allocate a buffer that's too small for this device.

It also contains a possible fix (change `#define INSTALL_PATCH 0` into `#define INSTALL_PATCH 1`).

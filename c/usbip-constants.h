#ifndef __USBIP_CONSTANTS_H__
#define __USBIP_CONSTANTS_H__

// USB Decriptor Type Constants.
#define USB_DESCRIPTOR_DEVICE           0x01    // Device Descriptor.
#define USB_DESCRIPTOR_CONFIGURATION    0x02    // Configuration Descriptor.
#define USB_DESCRIPTOR_STRING           0x03    // String Descriptor.
#define USB_DESCRIPTOR_INTERFACE        0x04    // Interface Descriptor.
#define USB_DESCRIPTOR_ENDPOINT         0x05    // Endpoint Descriptor.
#define USB_DESCRIPTOR_DEVICE_QUALIFIER 0x06    // Device Qualifier.

// USB "bRequest" Constants.
// These represent the possible values contained within a USB SETUP packet which
// specify the type of request.
#define GET_STATUS 0
#define CLEAR_FEATURE 1
#define SET_FEATURE 3
#define SET_ADDRESS 5
#define GET_DESCRIPTOR 6
#define SET_DESCRIPTOR 7
#define GET_CONFIGURATION 8
#define SET_CONFIGURATION 9
#define GET_INTERFACE 10
#define SET_INTERFACE 11
#define SET_FRAME 12

// OP Commands.
#define OP_REQ_DEVLIST_CMD 0x8005
#define OP_REQ_IMPORT_CMD 0x8003

// Port that the server is bound to.
#define TCP_SERV_PORT 3240

#endif  // __USBIP_CONSTANTS_H__

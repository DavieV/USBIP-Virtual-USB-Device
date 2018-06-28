#ifndef __DEVICE_DESCRIPTORS_H__
#define __DEVICE_DESCRIPTORS_H__

//USB definitions
#define byte unsigned char
#define word unsigned short

// USB Decriptor Type Constants.
#define USB_DESCRIPTOR_DEVICE           0x01    // Device Descriptor.
#define USB_DESCRIPTOR_CONFIGURATION    0x02    // Configuration Descriptor.
#define USB_DESCRIPTOR_STRING           0x03    // String Descriptor.
#define USB_DESCRIPTOR_INTERFACE        0x04    // Interface Descriptor.
#define USB_DESCRIPTOR_ENDPOINT         0x05    // Endpoint Descriptor.
#define USB_DESCRIPTOR_DEVICE_QUALIFIER 0x06    // Device Qualifier.

// USB Device Descriptor
// https://www.keil.com/pack/doc/mw/USB/html/_u_s_b__device__descriptor.html
typedef struct __attribute__((__packed__)) _USB_DEVICE_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;  // Type = 0x01 (USB_DESCRIPTOR_DEVICE).
  word bcdUSB;
  byte bDeviceClass;
  byte bDeviceSubClass;
  byte bDeviceProtocol;
  byte bMaxPacketSize0;
  word idVendor;
  word idProduct;
  word bcdDevice;
  byte iManufacturer;
  byte iProduct;
  byte iSerialNumber;
  byte bNumConfigurations;
} USB_DEVICE_DESCRIPTOR;

// USB Configuration Descriptor
// https://www.keil.com/pack/doc/mw/USB/html/_u_s_b__configuration__descriptor.html
typedef struct __attribute__((__packed__)) _USB_CONFIGURATION_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;  // Type = 0x02 (USB_DESCRIPTOR_CONFIGURATION).
  word wTotalLength;
  byte bNumInterfaces;
  byte bConfigurationValue;
  byte iConfiguration;
  byte bmAttributes;
  byte bMaxPower;
} USB_CONFIGURATION_DESCRIPTOR;

// USB Interface Descriptor
// https://www.keil.com/pack/doc/mw/USB/html/_u_s_b__interface__descriptor.html
typedef struct __attribute__((__packed__)) _USB_INTERFACE_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;  // Type = 0x04 (USB_DESCRIPTOR_INTERFACE).
  byte bInterfaceNumber;
  byte bAlternateSetting;
  byte bNumEndpoints;
  byte bInterfaceClass;
  byte bInterfaceSubClass;
  byte bInterfaceProtocol;
  byte iInterface;
} USB_INTERFACE_DESCRIPTOR;

// USB Endpoint Descriptor
// https://www.keil.com/pack/doc/mw/USB/html/_u_s_b__endpoint__descriptor.html
typedef struct __attribute__((__packed__)) _USB_ENDPOINT_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;   // Type = 0x05 (USB_DESCRIPTOR_ENDPOINT).
  byte bEndpointAddress;  // Bit 7 indicates direction (0=OUT, 1=IN).
  byte bmAttributes;
  word wMaxPacketSize;
  byte bInterval;
} USB_ENDPOINT_DESCRIPTOR;

// USB Device Qualifier Descriptor
// https://www.keil.com/pack/doc/mw/USB/html/_u_s_b__device__qualifier__descriptor.html
typedef struct __attribute__((__packed__)) _USB_DEVICE_QUALIFIER_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;  // Type = 0x06 (USB_DESCRIPTOR_DEVICE_QUALIFIER).
  word bcdUSB;
  byte bDeviceClass;
  byte bDeviceSubClass;
  byte bDeviceProtocol;
  byte bMaxPacketSize0;
  byte bNumConfigurations;
  byte bReserved;  // Always zero (0)
} USB_DEVICE_QUALIFIER_DESCRIPTOR;

// Generic Configuration
typedef struct __attribute__((__packed__)) _CONFIG_GEN {
  USB_CONFIGURATION_DESCRIPTOR dev_conf;
  USB_INTERFACE_DESCRIPTOR dev_int;
} CONFIG_GEN;

// Human Input Device (HID) Descriptor
// For more details refer to http://www.usb.org/developers/hidpage/HID1_11.pdf
typedef struct __attribute__((__packed__)) _USB_HID_DESCRIPTOR {
  byte bLength;
  byte bDescriptorType;
  word bcdHID;
  byte bCountryCode;
  byte bNumDescriptors;
  byte bRPDescriptorType;
  word wRPDescriptorLength;
} USB_HID_DESCRIPTOR;

// Configuration
typedef struct __attribute__((__packed__)) _CONFIG_HID {
  USB_CONFIGURATION_DESCRIPTOR dev_conf;
  USB_INTERFACE_DESCRIPTOR dev_int;
  USB_HID_DESCRIPTOR dev_hid;
  USB_ENDPOINT_DESCRIPTOR dev_ep;
} CONFIG_HID;

/*
 * Functional Descriptor Structure - See CDC Specification 1.1 for details
 */

// For more details refer to section 5.2.3.1 of CDC Specification v1.2
typedef struct __attribute__((__packed__)) _USB_CDC_HEADER_FN_DSC {
  byte bFNLength;
  byte bDscType;
  byte bDscSubType;
  word bcdCDC;
} USB_CDC_HEADER_FN_DSC;

// Abstract Control Management Functional Descriptor
typedef struct __attribute__((__packed__)) _USB_CDC_ACM_FN_DSC {
  byte bFNLength;
  byte bDscType;
  byte bDscSubType;
  byte bmCapabilities;
} USB_CDC_ACM_FN_DSC;

// Union Functional Descriptor
typedef struct __attribute__((__packed__)) _USB_CDC_UNION_FN_DSC {
  byte bFNLength;
  byte bDscType;
  byte bDscSubType;
  byte bMasterIntf;
  byte bSaveIntf0;
} USB_CDC_UNION_FN_DSC;

// Call Management Functional Descriptor
typedef struct __attribute__((__packed__)) _USB_CDC_CALL_MGT_FN_DSC {
  byte bFNLength;
  byte bDscType;
  byte bDscSubType;
  byte bmCapabilities;
  byte bDataInterface;
} USB_CDC_CALL_MGT_FN_DSC;

// Configuration
typedef struct __attribute__((__packed__)) _CONFIG_CDC {
  USB_CONFIGURATION_DESCRIPTOR dev_conf0;
  USB_INTERFACE_DESCRIPTOR dev_int0;
  USB_CDC_HEADER_FN_DSC cdc_header;
  USB_CDC_CALL_MGT_FN_DSC cdc_call_mgt;
  USB_CDC_ACM_FN_DSC cdc_acm;
  USB_CDC_UNION_FN_DSC cdc_union;
  USB_ENDPOINT_DESCRIPTOR dev_ep0;
  USB_INTERFACE_DESCRIPTOR dev_int1;
  USB_ENDPOINT_DESCRIPTOR dev_ep1;
  USB_ENDPOINT_DESCRIPTOR dev_ep2;
} CONFIG_CDC;

#endif  // __DEVICE_DESCRIPTORS_H__

# device manager

## Description

This example demonstrates how to query device count information and enable P2P functionality between devices.

## Supported Product Models

- Atlas A3 Training Series Products/Atlas A3 Inference Series Products
- Atlas A2 Training Series Products/Atlas A2 Inference Series Products
- Ascend 950PR Processor/Ascend 950DT Processor

## Compilation and Running

For environment installation details and running details, refer to the [README](../../README.md) in the examples directory.

## CANN Driver API

In this example, the key features and key interfaces involved are shown below:

- Query device count and ID information
    - Call drvGetDevNum interface to query device count.
    - Call drvGetDevIDs interface to query device ID list.
    - Call drvDeviceGetPhyIdByIndex for logical ID and physical ID conversion.
- P2P enable management
    - Call halDeviceCanAccessPeer interface to query whether data interaction is supported between Devices.
    - Call halDeviceEnableP2P interface to enable data interaction between current Device and specified Device.
    - Call halDeviceDisableP2P interface to disable data interaction functionality between current Device and specified Device.

## Known Issues

   None

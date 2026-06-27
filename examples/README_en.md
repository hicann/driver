# Example Usage Guide

The examples directory provides a series of Driver interface examples, including device management, DCMI, and so on, for developer reference to help developers quickly get started and master Driver key features.

## Example List

|Example Directory|Subdirectory            | Feature Introduction |
|--------|-----------------|--------------------------|
|devmng|[0_device_p2p](./devmng/0_device_p2p/)|This example demonstrates the process of obtaining device count and ID, enabling and disabling P2P functionality, which is a basic device management example.|
|dcmi|[0_configure_manager](./dcmi/dcmi/0_configure_manager/)|This example demonstrates DCMI initialization to user configuration, device sharing status configuration, and so on.|
|dcmi|[1_query_npuinfo](./dcmi/dcmi/1_query_npuinfo/)|This example demonstrates DCMI querying PCIE information, Board information, Flash information, and so on.|
|dcmi|[2_chip_reset](./dcmi/dcmi/2_chip_reset/)|This example demonstrates DCMI reset: resetting Ascend AI processor through PCIE standard hot reset process, including inband and outband reset modes.|

## Environment Preparation

Before compiling and running examples, obtain firmware, driver, and CANN software packages for installation. For detailed steps, refer to the [CANN Software Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware). After selecting the installation scenario, see the "Installing NPU Driver Firmware" section.

If you have customizations to the source code in the driver repository src directory, after installing CANN software, compile the source code and deploy it to the environment. For specific operations, refer to the [README](../README.md) in the driver repository.

## Compilation and Running

  1. Download the example code and upload it to the environment where CANN software is installed. Switch to the example directory.

  ```bash
  # Using 0_device_p2p example as an example
  cd ${git_clone_path}/examples/devmng/0_device_p2p
  ```

  2. Execute the following command to run the example.

  ```bash
  bash run.sh
  ```

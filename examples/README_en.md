# Sample Usage Guide

The examples directory provides a series of Driver interface samples, including DCMI and more, for developer reference to help quickly get started and master Driver key features.

## Sample List

| Sample Directory | Subdirectory | Feature Introduction |
|--------|-----------------|--------------------------|
|dcmi|[0_configure_manager](./dcmi/dcmi/0_configure_manager/)|This sample demonstrates DCMI initialization, user configuration, and device sharing status configuration.|
|dcmi|[1_query_npuinfo](./dcmi/dcmi/1_query_npuinfo/)|This sample demonstrates DCMI queries for PCIE information, Board information, Flash information, and more.|
|dcmi|[2_chip_reset](./dcmi/dcmi/2_chip_reset/)|This sample demonstrates DCMI reset: reset the Ascend AI processor through the PCIE standard hot reset process, including in-band and out-of-band reset modes.|

## Environment Preparation

Before compiling and running samples, you need to obtain and install firmware, driver, and CANN software packages. For detailed steps, refer to the [CANN Software Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware) (after selecting the installation scenario, refer to the "Installing NPU Driver and Firmware" section).

If you have customized the source code in the src directory of the driver repository, after installing CANN software, you also need to compile the source code and deploy it to the environment. For specific operations, refer to the [README](../README_en.md) in the driver repository.

## Compile and Run

1. Set environment variables.

```bash
# Specify the dcmi library path after installing driver and npu-smi tools
export LD_LIBRARY_PATH=~/usr/local/dcmi/:$LD_LIBRARY_PATH
```

2. Download Driver repository code and upload it to the environment where npu-smi tools are installed. Switch to the sample directory.

```bash
# ${git_clone_path} is the path where Driver repository code is uploaded to the environment.
# Using 0_set_user_config sample under 0_configure_manager(user) as an example
# Directory and module correspondence
# 0_configure_manager -- user
# --1)0_set_user_config Set user configuration
# --2)1_set_device_share Set device sharing status
# 1_query_npuinfo     -- query
# --1)0_get_pcie_info Get PCIe information of specified device
# --2)1_get_board_info Get board information of specified device
# --3)2_get_flash_info Get flash information
# 2_chip_reset        -- reset
# --1)0_internal_reset Reset chip
# --2)1_external_reset Out-of-band reset (only supports standard PCIe card environment)
cd ${git_clone_path}/examples/dcmi/dcmi/
```

3. Run the following command to execute the sample.

```bash
# Run command format: bash run.sh corresponding_module sample_subdirectory_number
bash run.sh user 0
```
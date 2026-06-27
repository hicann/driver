# FAQ Frequently Asked Questions

## Question 1

- **Problem**: Failed to install the driver open-source run package, for example, no permission or dependencies not found.
- **Solution**: Refer to the matched version of the [Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware) first. After selecting the installation scenario, see the "Installing NPU Driver and Firmware" section and "Appendix C: Installation Troubleshooting" section.

## Question 2

- **Problem**: Failed to install the run package. The log shows an error "do not have root permission, operation failed, please use root permission".
- **Possible Cause**: A non-root user executed the installation command.
- **Solution**: Switch to the root user and reinstall.

## Question 3

- **Problem**: During the first installation, after downloading the source code and executing `build.sh --pkg --soc=ascend910b`, an error appears indicating that the Linux `/lib/modules/xxx/build` directory does not exist. For example:

```
/lib/modules/5.10.0-60.18.0.50.r865_35.hce2.aarch64/build: No Such file or directory.
```

- **Possible Cause**: The system does not have the `linux-headers` software package that matches the current kernel version installed. Use `uname -r` to query the current kernel version of the environment.
- **Solution**:
<br/>

1. Install the `linux-headers` software package that matches the current kernel version. For example, in an Ubuntu environment, execute `apt install -y linux-headers-$(uname -r)`.
<br/>
2. If the kernel version to be used differs from the current kernel version, add `-k $patch` in the build command to specify the kernel version path. Note that before recompiling, clear the cache first.

```bash
build.sh --make_clean
build.sh --pkg --soc=ascend910b -k $patch
```

## Question 4

- **Problem**: Failed to install the run package with an error "set username and usergroup, HwHiAiUser:HwHiAiUser".
- **Possible Cause**:
<br/>

1. For the first installation, without specifying a user, the system defaults to using the HwHiAiUser group, but the environment does not have the HwHiAiUser group added.
<br/>
2. The user defined a custom group, and the installation requires specifying the user-defined group.

- **Solution**:

```bash
# Method to add HwHiAiUser group
groupadd HwHiAiUser
useradd -g HwHiAiUser -d /home/HwHiAiUser -m HwHiAiUser -s /bin/bash
```

```bash
# Method to specify a user-defined group (using HwHiAiUser as an example)
xxx-driver-xxx.run --full --install-username=HwHiAiUser --install-usergroup=HwHiAiUser
```

Note: Use `--help` to get run package installation commands. Refer to the [Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware) for parameter meanings. See "Appendix A: Reference Information -> Parameter Description" section.

## Question 5

- **Problem**: When the build script compiles the run package, the package name format is `Ascend-hdk-<chip_type>-driver-<version>_<os_version>-<arch>.run`. The compilation environment uname query is not an Ubuntu environment, but the os_version in the compiled package name shows ubuntu.
- **Possible Cause**: The kernel information queried by uname is incomplete.
- **Solution**: When compiling the run package, os_version is obtained from os-release information. Use the following command to query the corresponding os_version.

```bash
cat /etc/os-release
```

## Question 6

- **Problem**: Does the Ascend driver layer expose API interfaces externally?
- **Answer**: The Ascend Driver currently does not directly expose API interfaces externally. It is recommended to use ACL interfaces for AI applications or frameworks based on Ascend.
- **Reference**: [CANN Community Edition](https://www.hiascend.com/document/detail/zh/CANNCommunityEdition). Select the corresponding CANN version and refer to the corresponding API section.

## Question 7

- **Problem**: What product forms does the open-source driver support?
- **Answer**: The community Driver repository supports the 910 series including 910B, 910_93, and 950.
- **Reference**: Refer to the Ascend community for other product forms.

## Question 8

- **Problem**: During the compilation environment preparation stage, `apt install -y linux-headers-$(uname -r)` installation failed. Will this affect driver package source code compilation?
- **Possible Cause**: No linux-headers matching the current kernel.
- **Solution**: If other versions of linux-headers are already installed on the environment, compilation is possible without reinstalling matching linux-headers. Refer to `build.sh --help` for assistance and add the `-k` parameter to specify the kernel header file path, as shown below:

```bash
-k Set kernel source path, default "/lib/modules/$(uname -r)/build"
```

## Question 9

- **Problem**: How to enable the DEBUG macro switch when compiling the CANN driver to enable pr_debug log output?
- **Answer**: pr_debug uses the Linux native `/sys/kernel/debug/dynamic_debug/control` mechanism to dynamically enable or disable function-level or file-level printing. Query the specific enabling method based on the environment type.

## Question 10

- **Problem**: After compiling the driver open-source package, when compiling a new different version driver open-source package, the previously generated driver open-source package files are deleted.
- **Answer**: This is a normal phenomenon of the current compilation framework. Triggering a new compilation actively clears the previous compilation cache. Therefore, when triggering a new compilation, save the files from the previous compilation.

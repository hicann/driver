# FAQ Frequently Asked Questions

## Question 1
- Problem: Failed to install driver open-source run package, such as no permission, dependency not found, and other issues.
- Solution: Please refer to the matching version of the [Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware) first (after selecting the installation scenario, refer to the "Installing NPU Driver and Firmware" section, and the "Appendix C: Installation Fault Handling" section).

## Question 2
- Problem: Failed to install run package, the log shows error "do not have root permission, operation failed, please use root permission".
- Possible cause: Non-root user executed the installation command.
- Solution: Switch to root user and reinstall.

## Question 3
- Problem: First-time environment installation, after downloading source code and executing `build.sh --pkg --soc=ascend910b`, an error occurs, indicating that the linux /lib/modules/xxx/build directory does not exist. For example:
```
/lib/modules/5.10.0-60.18.0.50.r865_35.hce2.aarch64/build: No Such file or directory.
```
- Possible cause: The system has not installed the `linux-headers` software package matching the current kernel version (use `uname -r` to query the current kernel version of the environment).
- Solution:
<br/>
1. Install the `linux-headers` software package matching the current kernel version. For example, in ubuntu environment, execute `apt install -y linux-headers-$(uname -r)`.
<br/>
2. If the kernel version to use differs from the current kernel version, add `-k $patch` in the build command to specify the kernel version path (note: before recompiling, you need to clear the cache first).
```bash
build.sh --make_clean
build.sh --pkg --soc=ascend910b -k $patch
```

## Question 4
- Problem: Failed to install run package, error shows "set username and usergroup, HwHiAiUser:HwHiAiUser".
- Possible cause:
<br/>
1. First-time installation, without specifying user, defaults to using HwHiAiUser group, and the HwHiAiUser group has not been added to the environment.
<br/>
2. User customized the group, installation needs to specify the user-customized group.
- Solution:
```bash
# Method to add HwHiAiUser group as follows
groupadd HwHiAiUser
useradd -g HwHiAiUser -d /home/HwHiAiUser -m HwHiAiUser -s /bin/bash
```
```bash
# Method to specify user-customized group as follows (using HwHiAiUser as example)
xxx-driver-xxx.run --full --install-username=HwHiAiUser --install-usergrough=HwHiAiUser
```
Note: Run package installation command can use --help to get. Parameter meaning can refer to [Installation Guide](https://hiascend.com/document/redirect/CannCommunityInstSoftware) (refer to "Appendix A: Reference Information -> Parameter Description" section).

## Question 5
- Problem: Build script compiles run package, package name format is `Ascend-hdk-<chip_type>-driver-<version>_<os_version>-<arch>.run`, uname query on compile environment shows not ubuntu environment, but the os_version in compiled package name shows ubuntu.
- Possible cause: uname query kernel information is incomplete.
- Solution: When compiling run package, os_version is obtained from os-release information. You can use the following command to query the corresponding os_version.
```bash
cat /etc/os-release
```

## Question 6
- Problem: Does Ascend driver layer expose API interfaces externally?
- Answer: Ascend Driver currently does not directly expose API interfaces externally. We recommend using ACL interfaces for Ascend-based AI applications or frameworks.
- Reference: [CANN Community Edition](https://www.hiascend.com/document/detail/zh/CANNCommunityEdition), select the corresponding CANN version, and refer to the corresponding API chapter.

## Question 7
- Problem: What product types does open-source driver support?
- Answer: Community Driver repository supports 910 series: 910B, 910_93, 950.
- Reference: For other product types, refer to Ascend community.

## Question 8
- Problem: During compile environment preparation, `apt install -y linux-headers-$(uname -r)` installation failed, will it affect driver package source compilation?
- Possible cause: No linux-headers matching the current kernel.
- Solution: If other versions of linux-headers are already installed on the environment, you can compile without reinstalling matching linux-headers. Refer to `build.sh --help` help, add -k parameter to specify kernel header file path, as shown below:
```bash
-k Set kernel source path, default "/lib/modules/$(uname -r)/build"
```

## Question 9
- Problem: How to enable DEBUG macro switch when compiling CANN driver to enable pr_debug log output?
- Answer: pr_debug uses the native Linux /sys/kernel/debug/dynamic_debug/control mechanism to dynamically enable or disable function-level or file-level printing. You can query the specific enabling method based on the environment type.

## Question 10
- Problem: After compiling driver open-source package, when compiling a new different version driver open-source package, the previously generated driver open-source package files are deleted.
- Answer: This is a normal phenomenon of the current compilation framework. Triggering new compilation will actively clear previous compilation cache. Therefore, when triggering new compilation, you need to save the files from the previous compilation.
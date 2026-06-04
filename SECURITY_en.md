# Security Statement

## User Running Recommendations

From a security perspective, DCMI setting-type interfaces require root permission for execution, while HAL-type interfaces should not use root or other administrator accounts. Follow the principle of least privilege.

## File Permission Control

We recommend setting the umask value to 0027 or higher on hosts (including host machines) and containers to ensure new folders have default maximum permissions of 750 and new files have default maximum permissions of 640.

We recommend implementing permission control and security measures for sensitive content such as personal privacy data, business assets, source files, and various files saved during driver development. For example, permission control for this project's installation directory and input public data files. For recommended permission settings, refer to [A-Recommended Maximum File/Folder Permissions for Different Scenarios](#filefolder-permissions-recommendation).

## Build Security Statement

When compiling and installing this project from source, you need to compile it yourself. Some intermediate files will be generated during compilation. We recommend implementing permission control for intermediate files after compilation to ensure file security.

## Runtime Security Statement

When runtime exceptions occur, the process exits and prints error information. We recommend identifying specific error causes based on error prompts.

## Public Network Address Statement

The public network addresses included in this project's code are listed below:

| Type | Open Source Code Address | Filename | Public IP Address/Public URL Address/Domain/Email Address/Compressed File Address | Purpose |
| :------------: |:------------------------------------------------------------------------------------------:|:----------------------------------------------------------| :---------------------------------------------------------- |:-----------------------------------------|
| Dependency | Not applicable | cmake/third_party/makeself-fetch.cmake | https://gitcode.com/cann-src-third-party/makeself/releases/download/release-2.5.0-patch1.0/makeself-release-2.5.0-patch1.tar.gz | Download makeself source code from gitcode, used as build dependency |
| Dependency | Not applicable | cmake/third_party/gtest.cmake | https://gitcode.com/cann-src-third-party/googletest/releases/download/v1.14.0/googletest-1.14.0.tar.gz | Download googletest source code from gitcode, used as build dependency |
---

## Vulnerability Management

[Vulnerability Management](https://gitcode.com/cann/community/blob/master/security/security.md)

## Appendix

### <a name="filefolder-permissions-recommendation"></a> A-Recommended Maximum File/Folder Permissions for Different Scenarios

| Type | Linux Permission Reference Maximum |
| -------------- | ---------------  |
| User home directory | 750 (rwxr-x---) |
| Program files (including script files, library files, etc.) | 550 (r-xr-x---) |
| Program file directory | 550 (r-xr-x---) |
| Configuration files | 640 (rw-r-----) |
| Configuration file directory | 750 (rwxr-x---) |
| Log files (completed recording or archived) | 440 (r--r-----) |
| Log files (currently recording) | 640 (rw-r-----) |
| Log file directory | 750 (rwxr-x---) |
| Debug files | 640 (rw-r-----) |
| Debug file directory | 750 (rwxr-x---) |
| Temporary file directory | 750 (rwxr-x---) |
| Maintenance upgrade file directory | 770 (rwxrwx---) |
| Business data files | 640 (rw-r-----) |
| Business data file directory | 750 (rwxr-x---) |
| Key components, private keys, certificates, ciphertext file directory | 700 (rwx------) |
| Key components, private keys, certificates, encrypted ciphertext | 600 (rw-------) |
| Encryption/decryption interfaces, encryption/decryption scripts | 500 (r-x------) |
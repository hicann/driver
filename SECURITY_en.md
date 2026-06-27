# Security Statement

## Running User Recommendations

From a security perspective, DCMI setting interfaces use root privileges for execution. HAL interfaces are not recommended to use root or administrator accounts for execution, following the principle of least privilege.

# File Permission Control

It is recommended that users set the running system umask value to 0027 or higher on hosts (including host machines) and containers to ensure that the default maximum permission for newly created folders is 750 and for newly created files is 640.

It is recommended that users implement permission control and other security measures for sensitive content such as personal privacy data, commercial assets, source files, and various files saved during driver development. For example, for this project installation directory permission control, input public data file permission control, the recommended permissions refer to [A-File (Folder) Permission Control Recommended Maximum Values for Various Scenarios](#file-folder-permission-recommendations).

# Build Security Statement

When compiling and installing this project from source code, you need to compile it yourself. Some intermediate files are generated during the compilation process. It is recommended that you implement permission control for intermediate files after compilation to ensure file security.

# Running Security Statement

When an exception occurs during runtime, the process exits and prints error information. It is recommended to locate the specific error cause based on the error prompt.

# Public Network Address Statement

The public network addresses included in this project code are shown below:

|      Type      |                                           Open Source Code Address                                           |                            File Name                             |             Public Network IP Address/URL/Domain/Email/Compressed File Address             |                   Purpose Description                    |
| :------------: |:------------------------------------------------------------------------------------------:|:----------------------------------------------------------| :---------------------------------------------------------- |:-----------------------------------------|
|  Dependency  | Not involved  | cmake/third_party/makeself-fetch.cmake | https://gitcode.com/cann-src-third-party/makeself/releases/download/release-2.5.0-patch1.0/makeself-release-2.5.0-patch1.tar.gz | Download makeself source code from gitcode as compilation dependency |
| Dependency |    Not involved    | cmake/third_party/gtest.cmake          | https://gitcode.com/cann-src-third-party/googletest/releases/download/v1.14.0/googletest-1.14.0.tar.gz                          | Download googletest source code from gitcode as compilation dependency |

---

# Vulnerability Mechanism Statement

[Vulnerability Management](https://gitcode.com/cann/community/blob/master/security/security.md)

# Appendix

## <a name="file-folder-permission-recommendations"></a> A-File (Folder) Permission Control Recommended Maximum Values for Various Scenarios

| Type           | Linux Permission Reference Maximum Value |
| -------------- | ---------------  |
| User home directory                        |   750 (rwxr-x---)            |
| Program files (including script files, library files, and so on)       |   550 (r-xr-x---)             |
| Program file directory                      |   550 (r-xr-x---)            |
| Configuration file                          |  640 (rw-r-----)             |
| Configuration file directory                      |   750 (rwxr-x---)            |
| Log file (completed recording or archived)        |  440 (r--r-----)             |
| Log file (currently recording)                |    640 (rw-r-----)           |
| Log file directory                      |   750 (rwxr-x---)            |
| Debug file                         |  640 (rw-r-----)         |
| Debug file directory                     |   750 (rwxr-x---)  |
| Temporary file directory                      |   750 (rwxr-x---)   |
| Maintenance upgrade file directory                  |   770 (rwxrwx---)    |
| Business data file                      |   640 (rw-r-----)    |
| Business data file directory                  |   750 (rwxr-x---)      |
| Key component, private key, certificate, ciphertext file directory    |  700 (rwx------)      |
| Key component, private key, certificate, encrypted ciphertext        | 600 (rw-------)      |
| Encryption/decryption interface, encryption/decryption script            |   500 (r-x------)        |

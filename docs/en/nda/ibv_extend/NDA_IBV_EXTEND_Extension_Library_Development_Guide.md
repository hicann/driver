# Table of Contents

- [Table of Contents](#table-of-contents)
- [Introduction](#introduction)
  - [Component Introduction](#component-introduction)
  - [Application Scenarios](#application-scenarios)
- [Installation](#installation)
  - [Method 1: Install through Source Compilation](#method-1-install-through-source-compilation)
  - [Method 2: Install through HDK Package](#method-2-install-through-hdk-package)
- [Usage](#usage)
- [API Reference](#api-reference)
  - [Common Interfaces](#common-interfaces)
    - [ibv_extend_get_version](#ibv_extend_get_version)
    - [ibv_extend_check_version](#ibv_extend_check_version)
  - [North-bound Interfaces (Application Layer Call)](#north-bound-interfaces-application-layer-call)
    - [ibv_open_extend](#ibv_open_extend)
    - [ibv_close_extend](#ibv_close_extend)
    - [ibv_query_device_extend](#ibv_query_device_extend)
    - [ibv_create_qp_extend](#ibv_create_qp_extend)
    - [ibv_create_cq_extend](#ibv_create_cq_extend)
    - [ibv_create_srq_extend](#ibv_create_srq_extend)
    - [ibv_destroy_qp_extend](#ibv_destroy_qp_extend)
    - [ibv_destroy_cq_extend](#ibv_destroy_cq_extend)
    - [ibv_destroy_srq_extend](#ibv_destroy_srq_extend)
  - [South-bound Interfaces (Driver Call)](#south-bound-interfaces-driver-call)
    - [verbs_register_driver_extend](#verbs_register_driver_extend)
- [Key Structure Description](#key-structure-description)
  - [Enum Type Definition](#enum-type-definition)
    - [queue_buf_dma_mode](#queue_buf_dma_mode)
    - [doorbell_map_mode](#doorbell_map_mode)
    - [memcpy_direction](#memcpy_direction)
    - [ibv_qp_init_cap](#ibv_qp_init_cap)
    - [ibv_extend_device_cap](#ibv_extend_device_cap)
  - [Core Data Structures](#core-data-structures)
    - [doorbell_map_desc](#doorbell_map_desc)
    - [ibv_extend_ops](#ibv_extend_ops)
    - [queue_buf](#queue_buf)
    - [queue_info](#queue_info)
    - [ibv_qp_extend](#ibv_qp_extend)
    - [ibv_cq_extend](#ibv_cq_extend)
    - [ibv_srq_extend](#ibv_srq_extend)
    - [ibv_qp_init_attr_extend](#ibv_qp_init_attr_extend)
    - [ibv_cq_init_attr_extend](#ibv_cq_init_attr_extend)
    - [ibv_srq_init_attr_extend](#ibv_srq_init_attr_extend)
    - [ibv_device_attr_extend](#ibv_device_attr_extend)
    - [ibv_context_extend](#ibv_context_extend)
    - [ibv_context_extend_ops](#ibv_context_extend_ops)
    - [verbs_device_extend_ops](#verbs_device_extend_ops)
- [FAQ](#faq)
  - [Error when calling ibv_open_extend interface to initialize extension library](#error-when-calling-ibv_open_extend-interface-to-initialize-extension-library)

# Introduction

## Component Introduction

ibverbs_extend (hereinafter referred to as ibv_extend) component is an extension of standard RDMA verbs interfaces, specifically designed to support direct-drive RDMA communication in NDA (NPUDirect Async) scenarios.

The ibv_extend component achieves north-south decoupling through unified interfaces, as shown in the following figure:

- North-bound shields underlying network card hardware differences, providing transparent access for HCOMM and other communication transport layers.
- South-bound interfaces with 1825, Yunmai, and other network card extension drivers, enabling them to work without sensing upper-layer computing and memory resource differences.

![ibv_extend Logic Diagram](figures/ibv_extend逻辑框图.png)

The ibv_extend component provides the following core features:

- Dynamic loading and management of extension drivers
- Creation and destruction of extended QP/CQ/SRQ
- Support for north-south custom hardware operations through callback function mechanism

## Application Scenarios

This component mainly applies to the following scenarios:

- Direct data transfer between NPU and RDMA network card.
- Bypassing Host CPU, direct-drive control plane between NPU and RDMA network card.

![Application Scenario Diagram](figures/应用场景.png)

# Installation

## Method 1: Install through Source Compilation

1. Obtain source code and enter the component source directory.

    Method 1: Use git clone to get source code.

    ```bash
    git clone https://gitcode.com/cann/driver.git
    cd driver/src/custom/nda/ibv_extend/
    ```

    Method 2: Web page download source code.

    Browse to [driver repository](https://gitcode.com/cann/driver), click "Download zip" button to get the latest source code. After uploading to the server, execute the following command.

    ```bash
    unzip driver-master.zip
    cd driver-master/src/custom/nda/ibv_extend/
    ```

2. Compilation dependencies.

    For openEuler/CentOS/RHEL:

    ```bash
    yum install gcc gcc-c++ make cmake libnl3-devel libudev-devel pkgconfig python3-devel
    ```

    For Ubuntu/Debian:

    ```bash
    apt install gcc g++ make cmake libnl-3-dev libnl-route-3-dev libudev-dev pkg-config python3-dev
    ```

3. Compile and install.

    ```bash
    bash ./build.sh
    ```

    **Table 1** Compilation Parameter Description

    <table>
    <tr>
        <th valign="top" width="18%"><p>Parameter</p></th>
        <th valign="top" width="18%"><p>Long Parameter</p></th>
        <th valign="top" width="33%"><p>Description</p></th>
        <th valign="top" width="31%"><p>Usage Example</p></th>
    </tr>
    <tr>
        <td><p>-t=TYPE</p></td>
        <td><p>--type=TYPE</p></td>
        <td><p>Compile type:</p>
            <ul>
            <li>release: Default value, automatically downloads rdma-core.</li>
            <li>debug: Debug type.</li>
            </ul>
        </td>
        <td><p>Compile in debug mode.</p><code>bash ./build.sh -t=debug</code></td>
    </tr>
    <tr>
        <td><p>-b=PATH</p></td>
        <td><p>--libibverbs-build-dir=PATH</p></td>
        <td><p>Specify pre-compiled rdma-core build directory. Mutually exclusive with <strong>-s</strong> parameter, cannot be used together.</p></td>
        <td><p>Use pre-compiled rdma-core build library.</p><code>bash ./build.sh -b=/path/to/rdma-core/build</code></td>
    </tr>
    <tr>
        <td><p>-s=PATH</p></td>
        <td><p>--libibverbs-source-dir=PATH</p></td>
        <td><p>Specify rdma-core source directory. Mutually exclusive with <strong>-b</strong> parameter, cannot be used together.</p></td>
        <td><p>Use custom rdma-core source code.</p><code>bash ./build.sh -s=/path/to/rdma-core</code></td>
    </tr>
    <tr>
        <td><p>-x=PATH</p></td>
        <td><p>--libboundscheck-build-dir=PATH</p></td>
        <td><p>Specify pre-compiled libboundscheck build directory. Mutually exclusive with <strong>-e</strong> parameter, cannot be used together.</p></td>
        <td><p>Use pre-compiled libboundscheck build library.</p><code>bash ./build.sh -x=/path/to/libboundscheck</code></td>
    </tr>
    <tr>
        <td><p>-e=PATH</p></td>
        <td><p>--libboundscheck-source-dir=PATH</p></td>
        <td><p>Specify libboundscheck source directory. Mutually exclusive with <strong>-x</strong> parameter, cannot be used together.</p></td>
        <td><p>Use custom libboundscheck source code.</p><code>bash ./build.sh -e=/path/to/libboundscheck</code></td>
    </tr>
    <tr>
        <td><p>-h</p></td>
        <td><p>--help</p></td>
        <td><p>Show help information.</p></td>
        <td><p>View help information.</p><code>bash ./build.sh -h</code></td>
    </tr>
    </table>

4. After compilation, check output files.

    ```text
    output/
    ├── lib/
    │    └── libibv_extend.so    # Shared library
    └── include/
    │    └── ibv_extend.h        # Header file
    ```

5. Dynamically specify environment variables at runtime.

    ```bash
    export LD_LIBRARY_PATH=/path/to/ibv_extend/output/lib:$LD_LIBRARY_PATH
    ```

    > **Note:**
    >
    > - /path/to/ is a variable, replace with actual path.
    > - Users can also copy dynamic libraries under output/lib or header files under output/include to other custom paths or system paths for subsequent use.

6. Compile security function library.

    Go to [libboundscheck release page](https://gitcode.com/cann-src-third-party/libboundscheck/releases) to get the latest source code package, for example download [libboundscheck-v1.1.16.tar.gz](https://gitcode.com/cann-src-third-party/libboundscheck/releases/download/v1.1.16/libboundscheck-v1.1.16.tar.gz).

    Compile libc_sec.so dynamic library.

    ```bash
    # Extract to current directory
    tar zxvf libboundscheck-v1.1.16.tar.gz
    # Enter current directory
    cd libboundscheck-v1.1.16
    # Compile
    make -j
    # After successful compilation, dynamic link library will be generated in lib directory, need to rename to libc_sec.so.
    cp lib/libboundscheck.so lib/libc_sec.so
    ```

    Need to depend on libc_sec.so dynamic library during use.

    ```bash
    export LD_LIBRARY_PATH=/path/to/libboundscheck-v1.1.16/lib:$LD_LIBRARY_PATH
    ```

## Method 2: Install through HDK Package

1. Install HDK software package supporting NDA feature.
    1. Obtain [HDK software package supporting NDA feature](https://support.huawei.com/enterprise/zh/ascend-computing/ascend-hdk-pid-252764743/software/267204993?idAbsPath=fixnode01|23710424|251366513|254884019|261408772|252764743).
    2. Refer to the corresponding hardware product [NPU Driver and Firmware Installation Guide](https://support.huawei.com/enterprise/zh/ascend-computing/ascend-hdk-pid-252764743?category=installation-upgrade) to complete HDK driver package installation.

2. After installation, check output files.
    1. libibv_extend.so is in /usr/local/Ascend/driver/lib64/driver/ directory.
    2. ibv_extend.h is in /usr/local/Ascend/driver/include/ directory.

3. Need to load environment variables at runtime.
    - If cann-toolkit and other development tool packages are already installed, execute the following command to load environment variables (the following command uses root user installation as example, please use actual CANN installation path).

        ```bash
        source /usr/local/Ascend/cann/set_env.sh
        ```

    - If cann-toolkit and other development tool packages are not installed, execute the following command to load environment variables.

        ```bash
        export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64/common:$LD_LIBRARY_PATH
        ```

# Usage

The ibv_extend component allows upper-layer communication libraries to dynamically load extension drivers through **configuring environment variables** or **configuration files**.

Before running, you can configure environment variable `export IBV_EXTEND_SHOW_WARNINGS=1` to let ibv_extend component print Warning level logs to console. Warning level logs are not printed by default.

Before running, ensure that libibverbs.so and libibv_extend.so are correctly installed. For specific operations, refer to the table below.

**Table 1** Pre-run Check

<table>
    <tr>
        <th>System Type</th>
        <th>Check/Install libibverbs.so</th>
        <th>Check/Install libibv_extend.so</th>
    </tr>
    <tr>
        <td>openEuler/CentOS/RHEL</td>
        <td>
            <ol>
                <li>Check if libibverbs.so is installed.<br><code>ldconfig -p | grep libibverbs</code><br>If there is output, libibverbs.so is installed, done.<br>If no output, continue.</li>
                <li>Install libibverbs.<br><code>sudo yum install rdma-core</code></li>
            </ol>
        </td>
        <td rowspan="2">
            <ol>
                <li>Check if libibv_extend.so is installed.<br><code>ll /path/to/ibv_extend/output/lib</code><br><code>ll /usr/local/Ascend/driver/lib64/driver/ | grep libibv_extend.so</code><br>If either has output, libibv_extend is installed, done.<br>If no output, continue.</li>
                <li>Install libibv_extend, refer to <a href="#installation">Installation</a>.</li>
            </ol>
        </td>
    </tr>
    <tr>
        <td>Ubuntu/Debian</td>
        <td>
            <ol>
                <li>Check if libibverbs.so is installed.<br><code>ldconfig -p | grep libibverbs</code><br>If there is output, libibverbs.so is installed, done.<br>If no output, continue.</li>
                <li>Install libibverbs.<br><code>sudo apt update</code><br><code>sudo apt install libibverbs1 ibverbs-utils rdma-core</code></li>
            </ol>
        </td>
    </tr>
</table>

**Configure Environment Variables**

Upper-layer applications can configure **IBV_EXTEND_DRIVERS** environment variable before running to let ibv_extend component find and load specified driver extension libraries (such as 1825, Yunmai, and other network card extension drivers). Multiple drivers are separated by <strong>:</strong> or <strong>;</strong>.

Example: `export IBV_EXTEND_DRIVERS="/path1/my_ext_driver1.so:/path2/my_ext_driver2.so"`

**Configuration File**

1. Create extension driver configuration file directory.

    ```bash
    mkdir -p /etc/libibverbs_extend.d/
    ```

2. Enter extension driver configuration file directory.

    ```bash
    cd /etc/libibverbs_extend.d/
    ```

3. Create extension driver configuration file. Configuration file content format: driver <driver_name>.

    Assume driver extension library is libmy_ext_driver.so, use the following command to generate configuration file.

    ```bash
    echo "driver my_ext_driver" > my_ext_driver.conf
    ```

# API Reference

## Common Interfaces

### ibv_extend_get_version

**Function Prototype**

`const char *ibv_extend_get_version(uint32_t *major, uint32_t *minor, uint32_t *patch)`

**Function**

Get ibv_extend dynamic library version number.

**Parameters**

- major: Major version number. Output parameter. Can be null, null means not getting, interface does not allocate additional memory.
- minor: Minor version number. Output parameter. Can be null, null means not getting, interface does not allocate additional memory.
- patch: Patch version number. Output parameter. Can be null, null means not getting, interface does not allocate additional memory.

**Return Value**

Version string pointer (static string, no need to release).

**Usage Example**

```c
// Call function to get version information
version_str = ibv_extend_get_version(&major, &minor, &patch);
// Print version information
printf("Version string: %s\n", version_str);
printf("Version number: %u.%u.%u\n", major, minor, patch);
```

### ibv_extend_check_version

**Function Prototype**

`int ibv_extend_check_version(uint32_t driver_major, uint32_t driver_minor, uint32_t driver_patch)`

**Function**

Check version compatibility. This function checks at runtime whether the header file version used during driver and upper-layer application compilation is compatible with current library version. We recommend calling this function for version check during driver and upper-layer application initialization.

Compatibility rules:

1. Major version number completely matches, then compatible.
2. Software minor version number <= library minor version number, then compatible.
3. If minor version numbers are the same, and software patch version number <= library patch version number, then compatible.

**Parameters**

- driver_major: Major version number, recommend passing IBV_EXTEND_VERSION_MAJOR.
- driver_minor: Minor version number, recommend passing IBV_EXTEND_VERSION_MINOR.
- driver_patch: Patch version number, recommend passing IBV_EXTEND_VERSION_PATCH.

**Return Value**

- 0: Compatible.
- -1: Incompatible.

**Usage Example**

```c
// Call function to check version compatibility
ret = ibv_extend_check_version(IBV_EXTEND_VERSION_MAJOR, IBV_EXTEND_VERSION_MINOR, IBV_EXTEND_VERSION_PATCH);
// Check return value
if (ret == 0) {
    printf("Version compatible, can use normally\n");
    // Continue subsequent initialization operations
} else {
    printf("Version incompatible, driver compilation version does not match current library version\n");
    // Refuse to run
    return -1;
}
```

## North-bound Interfaces (Application Layer Call)

### ibv_open_extend

**Function Prototype**

`struct ibv_context_extend *ibv_open_extend(struct ibv_context *context)`

**Function**

Call driver registered interface to create extension context. Must call ibv_open_extend to create extension context before calling other interfaces.

**Parameters**

context: Standard ibv context, created using ibv_open_device, non-null.

**Return Value**

- Extension context pointer: Extension context creation successful.
- NULL: Extension context creation failed.

**Usage Example**

```c
// Get device list
int num_devices = 0;
struct ibv_device **dev_list = ibv_get_device_list(&num_devices);
if (!dev_list) {
    fprintf(stderr, "Failed to get device list\n");
    return -1;
}

// Check if there are available devices
if (num_devices <= 0) {
    fprintf(stderr, "No device found\n");
    ibv_free_device_list(dev_list);
    return -1;
}

// Select first device
struct ibv_device *device = dev_list[0];

// Open device
struct ibv_context *ctx = ibv_open_device(device);
if (!ctx) {
    fprintf(stderr, "Failed to open device\n");
    ibv_free_device_list(dev_list);
    return -1;
}

// Open extension context
struct ibv_context_extend *ext_ctx = ibv_open_extend(ctx);
if (!ext_ctx) {
    fprintf(stderr, "Failed to open extend context\n");
    ibv_close_device(ctx);
    ibv_free_device_list(dev_list);
    return -1;
}
```

### ibv_close_extend

**Function Prototype**

`int ibv_close_extend(struct ibv_context_extend *context)`

**Function**

Call driver registered interface to release extension context resources. Cannot use this extension context resource after ibv_close_extend call.

**Parameters**

context: Extension context, must be created using ibv_open_extend, non-null.

**Return Value**

- 0: Success.
- EINVAL: Invalid parameter.
- ENOENT: Matching driver not found.
- Driver abnormal return value.

**Usage Example**

```c
int ret = ibv_close_extend(ext_ctx);
if (ret != 0) {
    fprintf(stderr, "Failed to close extend context: %d\n", ret);
}
```

## South-bound Interfaces (Driver Call)

### verbs_register_driver_extend

**Function Prototype**

`void verbsregister_driver_extend(const struct verbs_device_extend_ops *ops)` or `PROVIDER_EXTEND_DRIVER(drv)`

**Function**

Register driver to extend_driver_list linked list. Can use encapsulated PROVIDER_EXTEND_DRIVER macro.

**Parameters**

- ops: Device extension operation structure pointer, non-null, internally does not allocate additional address, must be global static variable.
- drv: Must be struct verbs_device_extend_ops type.

**Return Value**

None.

**Usage Example**

```c
static const struct verbs_device_extend_ops my_driver_ops = {
    .name = "my_driver",    // Must be consistent with standard driver
    .alloc_context = my_alloc_context,
    .free_context = my_free_context,
};
PROVIDER_EXTEND_DRIVER(my_driver_ops);  // Use macro for automatic registration
```

# Key Structure Description

## Enum Type Definition

### queue_buf_dma_mode

During extended QP/CQ/SRQ resource creation, for these resources, driver needs to establish host address and device address mapping so that device can directly drive network card resources. Currently supports two mapping modes.

| Variable | Value | Description |
| ---- | ---- | ---- |
| QU_BUF_DMA_MODE_DEFAULT | 0 | PCIe mapping mode, this mode supports general hardware form, network card and NPU are both PCIe devices, usually use peerMem mode mapping. |
| QU_BUF_DMA_MODE_INDEP_UB | 1 | UB mapping mode, network card and NPU are PCIe devices, but data path uses independent UB bus addressing, usually use UbShmem mode mapping. |

### doorbell_map_mode

During extended QP/CQ/SRQ resource creation, driver will allocate doorbell address, and needs to map host-side allocated doorbell address to NPU card side. Mapping logic (db_mmap) is implemented by upper layer. Upper layer needs to perform mapping based on mapping type provided by driver.

| Variable | Value | Description |
| ---- | ---- | ---- |
| DB_MAP_MODE_HOST_VA | 0 | Based on Host virtual address mapping, usually third-party network card resource mapping method. |
| DB_MAP_MODE_UB_RES | 1 | Use UB device resource descriptor for mapping, 1825 network card used mapping method. |

### memcpy_direction

When driver uses upper-layer registered memcpy_s to copy memory, need to specify copy direction to allow driver read/write access to device memory.

| Variable | Value | Description |
| ---- | ---- | ---- |
| MEMCPY_DIR_HOST_TO_HOST | 0 | memcpy_s parameter, copy within Host. |
| MEMCPY_DIR_HOST_TO_DEVICE | 1 | memcpy_s parameter, memory copy from Host to Device (NPU). |
| MEMCPY_DIR_DEVICE_TO_HOST | 2 | memcpy_s parameter, memory copy from Device (NPU) to Host. |
| MEMCPY_DIR_DEVICE_TO_DEVICE | 3 | memcpy_s parameter, memory copy within Device (NPU) or between Device (NPU). |

### ibv_qp_init_cap

When creating extended QP, upper-layer communication library can specify additional extension configuration, optional.

| Variable | Value | Description |
| ---- | ---- | ---- |
| QP_ENABLE_DIRECT_WQE | 1 | If network card supports direct_wqe capability, by configuring this field, can enable network card direct_wqe capability when calling ibv_create_qp_extend interface to create sq_info. |

### ibv_extend_device_cap

Device supported extension capabilities, returned by extension query interface. Driver queries whether current device supports NDR/NDA.

| Variable | Value | Description |
| ---- | ---- | ---- |
| IBV_EXTEND_NDR | 1 | Device supports NDR (NPUDirect Rdma) capability. |
| IBV_EXTEND_NDA | 2 | Device supports NDA (NPUDirect Async) capability. |

## Core Data Structures

### doorbell_map_desc

doorbell_map descriptor is used for driver-side mapping of hardware doorbell address. After driver allocates doorbell, maps it to NPU through db_map callback passed by upper layer for NPU direct-drive.

| Variable | Type | Description |
| ---- | ---- | ---- |
| hva | uint64_t | doorbell virtual address on host side, PCIe network card uses, address must be valid. |
| ub_res | struct | UB mapping method uses, uses UB resource descriptor, address must be valid. See structure description below. |
| size | uint64_t | doorbell mapping length. |
| type | uint32_t | doorbell mapping type (doorbell_map_mode type). |
| resv | uint32_t | Reserved. |

```c
struct {
    uint64_t guid_l;   /* GUID low 64 bits */
    uint64_t guid_h;   /* GUID high 64 bits */
    struct {
        uint64_t resource_id : 4; /* Corresponds to res_id in GUID */
        uint64_t offset : 32;  /* Offset within a page id of a certain GUID */
        uint64_t resv : 28;   /* Reserved */
    } bits;
} ub_res;
```

### ibv_extend_ops

This series of functions is used for memory allocation and mapping during QP/CQ/SRQ and other resource creation. Upper-layer application implements, for underlying driver callback use.

| Function Prototype | Function Description | Input Parameter Description | Return Value Description |
| ---- | ---- | ---- | ---- |
| `void *(*alloc)(size_t size)` | Used by underlying driver to request memory resources, can be NPU memory resources or host memory resources. | size: Allocation length, unit bytes, greater than 0. | Allocated memory pointer, returns null on allocation failure. |
| `void (*free)(void *ptr)` | Used by underlying driver for memory release. Memory must be address allocated by alloc callback function. | ptr: Memory pointer allocated using alloc interface. | No return value. |
| `void (*memset_s)(void *dst, int value, size_t count)` | Used by underlying driver for memory initialization operation. Memory must be address allocated by alloc callback function. | <li>dst: Memory pointer allocated using alloc interface, memset_s does not perform boundary check on memory area pointed by pointer ptr, so need to ensure memory area pointed by ptr is large enough when using, avoid out-of-bounds access.</li><li>value: Usually an int type value, but actually only uses low 8 bits of this value. This means values outside range 0 to 255 may produce undefined behavior.</li><li>count: Number of bytes to set, usually calculated through sizeof() or other means. count cannot be greater than size requested during alloc.</li> | No return value. |
| `int (*memcpy_s)(void *dst, size_t dst_max_size, void *src, size_t size, uint32_t direct)` | Used by underlying driver for memory copy operation. Memory must be address allocated by alloc callback function. | <li>dst: Copy destination address, can be host-side allocated address or alloc allocated address.</li><li>dst_max_size: For copy safety, need to pass maximum length of dst destination address.</li><li>src: Copy source address, can be host-side allocated address or alloc allocated address.</li><li>size: Actual copy length in src, unit bytes, cannot exceed src allocated length.</li><li>direct: Copy direction, type is enum memcpy_direction.</li> | Returns 0 on success, returns negative error code on failure. |
| `void *(*db_mmap)(struct doorbell_map_desc *desc)` | Used for doorbell mapping logic, usually implements logic of mapping host doorbell address to NPU memory.<br>Implementation constraint: Must support repeated mapping of same desc, that is, multiple mappings of same desc address must return same mapping address. | desc: doorbell resource mapping descriptor. | Mapped address pointer, returns null on failure. |
| `int (*db_unmap)(void *ptr, struct doorbell_map_desc *desc)` | Used for unmapping logic. | <li>ptr: Address mapped by calling db_mmap interface.</li><li>desc: Input desc during db_mmap.</li> | Returns 0 on success, returns negative error code on failure. |

# FAQ

## Error when calling ibv_open_extend interface to initialize extension library

**Problem Description**

Upper-layer communication component calls ibv_open_extend interface returns null pointer. After configuring **IBV_EXTEND_SHOW_WARNINGS** environment variable, error as follows:

```text
ibv_extend: Warning: no available ops for open extend context
```

**Possible Cause**

ibv_extend extension library cannot find corresponding network card extension driver or dlopen corresponding network card extension driver reports error.

**Solution**

1. Refer to [Usage](#usage), let ibv_extend find corresponding network card extension driver location.
2. If using dlopen method to load libibv_extend.so, need to export symbols to global symbol table through RTLD_GLOBAL. Usage example as follows.

    ```c
    void *handle = dlopen("libibv_extend.so", RTLD_LAZY | RTLD_GLOBAL);
    if (!handle) {
        fprintf(stderr, "dlopen libibv_extend.so error: %s\n", dlerror());
        return;
    }
    ```

3. If still reports error, contact corresponding network card extension driver vendor to confirm whether extension driver package is correct.
# SVM

## Overview

SVM (Shared Virtual Memory) is a memory management module in the Ascend AI processor platform, used to efficiently manage device-side memory. Its main functions include memory initialization, allocation, release, copy, query, and sharing, and it provides HAL interfaces to upper-layer modules (such as Runtime).

<center>
    <img src="../../../docs/en/figures/SVM_module_dependency_en.png" alt="SVM Module Dependencies" width=70%/>
</center>


## SVM Initialization

SVM interface: ```halMemAgentOpen```
<br/>
The APP process calls the upper-layer business initialization interface ```aclrtSetDevice``` during initialization, which includes the SVM module initialization process. This process mainly includes: initializing the SVM module management structure, and completing the interaction between Host-side and Device-side SVM modules.

## Memory Allocation/Release/Set

SVM interfaces: ```halMemAlloc```/```halMemFree```/```drvMemsetD8```
<br/>
Allocate and map (through ```mmap```) a virtual address range from the reserved virtual address range, while entering kernel mode to request physical pages and establish corresponding page table entries. When releasing, unmap page tables, release physical pages, and return virtual addresses to the reserved range. Memory set sets the specified size of device memory to a given value.

Additionally, the driver provides VMM interfaces, allowing developers to separately allocate virtual addresses and physical addresses, and dynamically establish mapping relationships between them as needed.
<br/>

- VMM Virtual Address Allocation/Release
<br/>
SVM interface: ```halMemAddressReserve```/```halMemAddressFree```
<br/>
Allocate and map (through ```mmap```) a virtual address range from the reserved address range. At this point, physical pages have not been actually allocated. When releasing, only the virtual address is reclaimed.

- VMM Physical Address Allocation/Release
<br/>
SVM interface: ```halMemCreate```/```halMemRelease```
<br/>
Allocate physical memory with specified attributes and size on the device side, and return an opaque generic memory allocation handle as the reference identifier for subsequent memory mapping. When releasing, the physical memory corresponding to this handle is released.

- VMM Map/Unmap Virtual Address to Physical Address
<br/>
SVM interface: ```halMemMap```/```halMemUnmap```
<br/>
Establish or remove mapping relationships between the passed virtual address and physical address.

## Memory Query

Memory query supports memory attribute query and memory information query for specified addresses.

- Memory Attribute Query
<br/>
SVM interface: ```drvMemGetAttribute```
<br/>
Get memory attributes, physical page granularity, and other attributes for the passed virtual address.

- Memory Information Query
<br/>
SVM interface: ```halMemGetInfo```
<br/>
Query physical memory information on the device side.

## Memory Copy

SVM interface: ```halMemcpy```
<br/>
Support memory data transfer between host and device, or between different devices. For example, when performing H2D (Host-to-Device) transfer, data is synchronously copied from host memory to device memory. This synchronous copy operation is blocking—the caller waits until all data copying is complete before returning and continuing to execute subsequent code.

## Memory Sharing

Memory sharing supports memory sharing between different devices, as well as memory sharing between Host and Device.

- Inter-Device Memory Sharing
<br/>
SVM interfaces:
```halShmemCreateHandle```/```halShmemDestroyHandle```
<br/>
```halShmemOpenHandleByDevId```/```halShmemCloseHandle```
<br/>
Process 1 creates a handle pointing to shared device memory. Process 2 parses this handle and maps it as a device memory address within its own process, enabling shared access to the same physical memory on the device side. Destroying handles and unmapping perform corresponding reverse operations.

- Host and Device Memory Sharing
<br/>
SVM interface: ```halHostRegister```/```halHostUnregister```
<br/>
Register the peer (Host-side or Device-side) memory to the local side (Device-side or Host-side), enabling the local side to directly access or modify data in the peer memory.

## SVM Usage Process in Business

#### Business Usage Process for Allocation and Copy Features

- Application Scenario
<br/>
Before operator execution, its Host-side process needs to first initialize the SVM module, then call the ```halMemAlloc``` interface to separately allocate Host memory and Device memory, and obtain corresponding memory addresses. Then, transfer the data to be calculated from the Host side to the Device side through the memory copy interface.

- Business Calling SVM Interface Process
1. Call ```halMemAlloc``` interface to allocate Host memory and obtain Host memory address.
2. Call ```halMemAlloc``` interface to allocate Device memory and obtain Device memory address.
3. Call ```halMemcpy``` interface to synchronously copy data from Host memory to Device memory, completing data transfer.

<center>
    <img src="../../../docs/en/figures/SVM_application_copy_process_en.png" alt="SVM Module Allocation and Copy Process" width=70% />
</center>

#### Business Usage Process for Memory Sharing Feature

- Application Scenario
<br/>
The business module starts two application processes on the Host side: host_app process 0 and host_app process 1, corresponding to devices dev0 and dev1 respectively.
<br/>
During operator execution, dev0 writes completed calculation results to its local device memory. If subsequent calculations need to be executed by dev1, dev1 can directly access dev0's calculation results through the above shared memory mechanism, without Host forwarding or explicit data copying, significantly improving operator pipeline execution efficiency.

- Business Calling SVM Interface Process
1. host_app process 0 calls ```halMemAlloc``` to allocate device memory on dev0, and creates a shared handle for this memory through ```halShmemCreateHandle``` interface, then passes this handle to host_app process 1.
2. host_app process 1 calls the driver interface ```halShmemOpenHandleByDevId``` to open this shared handle. The driver returns a pointer pointing to shared memory, completing the mapping of dev0 memory.

<center>
    <img src="../../../docs/en/figures/SVM_memory_sharing_process_en.png" alt="SVM Module Memory Sharing Process" width=70% />
</center>

#### Business Usage Process for VMM Feature

- Application Scenario
<br/>
Based on VMM feature, the business module can allocate required virtual addresses and physical addresses at once, and dynamically establish mapping relationships based on actual needs, reusing the same physical memory, effectively reducing memory fragmentation caused by frequent physical memory splitting.

- Business Calling SVM Interface Process
<br/>

1. Call ```halMemAddressReserve``` to allocate virtual address.
2. Call ```halMemCreate``` to allocate physical address.
3. Call ```halMemMap``` to establish mapping from virtual address to physical address.

<center>
    <img src="../../../docs/en/figures/SVM_VMM_process_en.png" alt="SVM Module VMM Process" width=70% />
</center>
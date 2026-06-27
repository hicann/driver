# Commands List

## Commands for Information Query (info)

- [Querying Help Information](./Ascend_950_npu-smi/querying-help-information.md)
- [Querying the npu-smi Tool Version](./Ascend_950_npu-smi/querying-the-npu-smi-tool-version.md)
- [Printing Information Query Help](./Ascend_950_npu-smi/printing-information-query-help.md)
- [Querying Basic Information](./Ascend_950_npu-smi/querying-basic-information.md)
- [Querying All NPU Devices](./Ascend_950_npu-smi/querying-all-npu-devices.md)
- [Querying NPU Details](./Ascend_950_npu-smi/querying-npu-details.md)
- [Querying the Device Mapping Information](./Ascend_950_npu-smi/querying-the-device-mapping-information.md)
- [Querying the Common Information of a Device](./Ascend_950_npu-smi/querying-the-common-information-of-a-device.md)
- [Querying the Flash Information of a Device](./Ascend_950_npu-smi/querying-the-flash-information-of-a-device.md)
- [Querying the Memory Information of a Device](./Ascend_950_npu-smi/querying-the-memory-information-of-a-device.md)
- [Querying Device Monitoring Data](./Ascend_950_npu-smi/querying-device-monitoring-data.md)
- [Querying Device Statistics](./Ascend_950_npu-smi/querying-device-statistics.md)
- [Querying the Device Temperature](./Ascend_950_npu-smi/querying-the-device-temperature.md)
- [Querying the Device Power](./Ascend_950_npu-smi/querying-the-device-power.md)
- [Querying the Device Voltage](./Ascend_950_npu-smi/querying-the-device-voltage.md)
- [Querying the Device Health Status](./Ascend_950_npu-smi/querying-the-device-health-status.md)
- [Querying the Alarm Information of a Device](./Ascend_950_npu-smi/querying-the-alarm-information-of-a-device.md)
- [Querying the ECC Error Count of a Device](./Ascend_950_npu-smi/querying-the-ecc-error-count-of-a-device.md)
- [Querying the ECC Enabling Status of a Device](./Ascend_950_npu-smi/querying-the-ecc-enabling-status-of-a-device.md)
- [Querying the Sensor Information of a Device](./Ascend_950_npu-smi/querying-the-sensor-information-of-a-device.md)
- [Querying the System Time of a Device](./Ascend_950_npu-smi/querying-the-system-time-of-a-device.md)
- [Querying the Service Status of the KMSAgent Process](./Ascend_950_npu-smi/querying-the-service-status-of-the-kmsagent-process.md)
- [Querying the Memory Usage of Processes on a Device](./Ascend_950_npu-smi/querying-the-memory-usage-of-processes-on-a-device.md)
- [Querying the NPU ID, Slot ID, and Chip ID Corresponding to a Physical ID](./Ascend_950_npu-smi/querying-the-npu-id-slot-id-and-chip-id-corresponding-to-a-physical-id.md)
- [Querying the Topology of Multiple NPUs](./Ascend_950_npu-smi/querying-the-topology-of-multiple-npus.md)
- [Querying the SuperPoD Information of a Device](./Ascend_950_npu-smi/querying-the-superpod-information-of-a-device.md)
- [Querying the SIO Status Between Dies of a Device](./Ascend_950_npu-smi/querying-the-sio-status-between-dies-of-a-device.md)
- [Querying the Log Dumping Configuration](./Ascend_950_npu-smi/querying-the-log-dumping-configuration.md)

## Commands for Settings (set)

- [Printing Settings Help](./Ascend_950_npu-smi/printing-settings-help.md)
- [Resetting an NPU](./Ascend_950_npu-smi/resetting-an-npu.md)
- [Clearing the ECC Error Count of a Device](./Ascend_950_npu-smi/clearing-the-ecc-error-count-of-a-device.md)
- [Setting the Service Status of the KMSAgent Process](./Ascend_950_npu-smi/setting-the-service-status-of-the-kmsagent-process.md)
- [Enabling or Disabling Log Dumping in Persistence Mode](./Ascend_950_npu-smi/enabling-or-disabling-log-dumping-in-persistence-mode.md)
- [Setting Continuous Log Collection for All Devices](./Ascend_950_npu-smi/setting-continuous-log-collection-for-all-devices.md)
- [Terminating the Log Process and Clearing the Configuration](./Ascend_950_npu-smi/terminating-the-log-process-and-clearing-the-configuration.md)

## Commands for Upgrading (upgrade)

- [Printing Upgrade Help](./Ascend_950_npu-smi/printing-upgrade-help.md)
- [Querying the Firmware Version](./Ascend_950_npu-smi/querying-the-firmware-version.md)
- [Upgrading Firmware](./Ascend_950_npu-smi/upgrading-firmware.md)

## Commands for Clearing (clear)

- [Printing Clearing Help](./Ascend_950_npu-smi/printing-clearing-help.md)
- [Clearing the ECC Error Count of a Device](./Ascend_950_npu-smi/clearing-the-ecc-error-count-of-a-device-0.md)

## Certificate Management

- [Obtaining CSR](./Ascend_950_npu-smi/obtaining-csr.md)
- [Preconfiguring or Updating the TLS Certificate](./Ascend_950_npu-smi/preconfiguring-or-updating-the-tls-certificate.md)
- [Querying Certificate Information](./Ascend_950_npu-smi/querying-certificate-information.md)
- [Querying the Certificate Expiration Threshold](./Ascend_950_npu-smi/querying-the-certificate-expiration-threshold.md)
- [Setting the Certificate Expiration Threshold](./Ascend_950_npu-smi/setting-the-certificate-expiration-threshold.md)
- [Restoring the Default Certificate Expiration Threshold](./Ascend_950_npu-smi/restoring-the-default-certificate-expiration-threshold.md)

# npu-smi Description

## Overview

This document details the npu-smi commands for information query, function settings, tool version checking, and help information query, and provides usage instructions.

This document applies to the  Atlas 350 accelerator card.

## Deployment Scenario Description

- If a specific deployment scenario is not mentioned in the command or API description within this document, it indicates that the product does not support that scenario, and no such support is currently planned.
- In the "Support by Deployment Scenario" table in this document,  **Y**  means "supported",  **N**  means "not supported", and  **NA**  means "not applicable", indicating that the scenario is not planned.

**Table  1**  Deployment Scenario Definitions and Descriptions

<a name="en-us_topic_0000002373372809_table931524118119"></a>
<table><thead align="left"><tr id="en-us_topic_0000002373372809_row63157411612"><th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000002373372809_p1531594115110"><a name="en-us_topic_0000002373372809_p1531594115110"></a><a name="en-us_topic_0000002373372809_p1531594115110"></a>Deployment Scenario</p>
</th>
<th class="cellrowborder" valign="top" width="18.751875187518753%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000002373372809_p231514119116"><a name="en-us_topic_0000002373372809_p231514119116"></a><a name="en-us_topic_0000002373372809_p231514119116"></a>Sub-scenario</p>
</th>
<th class="cellrowborder" valign="top" width="62.496249624962495%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000002373372809_p83158416110"><a name="en-us_topic_0000002373372809_p83158416110"></a><a name="en-us_topic_0000002373372809_p83158416110"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002373372809_row631511411411"><td class="cellrowborder" rowspan="3" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p83151741912"><a name="en-us_topic_0000002373372809_p83151741912"></a><a name="en-us_topic_0000002373372809_p83151741912"></a>Physical machine (PM)<sup id="en-us_topic_0000002373372809_sup124511238422"><a name="en-us_topic_0000002373372809_sup124511238422"></a><a name="en-us_topic_0000002373372809_sup124511238422"></a>a</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p1931510414116"><a name="en-us_topic_0000002373372809_p1931510414116"></a><a name="en-us_topic_0000002373372809_p1931510414116"></a>PM (bare metal)</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000002373372809_p203156413117"><a name="en-us_topic_0000002373372809_p203156413117"></a><a name="en-us_topic_0000002373372809_p203156413117"></a>NPUs run directly on PMs (bare metal).</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row33150417118"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p731511419112"><a name="en-us_topic_0000002373372809_p731511419112"></a><a name="en-us_topic_0000002373372809_p731511419112"></a>PM + unprivileged container</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p1731574111112"><a name="en-us_topic_0000002373372809_p1731574111112"></a><a name="en-us_topic_0000002373372809_p1731574111112"></a>Passthrough the physical server's NPU device into an unprivileged container for use.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row531512417117"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p43154414114"><a name="en-us_topic_0000002373372809_p43154414114"></a><a name="en-us_topic_0000002373372809_p43154414114"></a>PM + privileged container</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p1531514411418"><a name="en-us_topic_0000002373372809_p1531514411418"></a><a name="en-us_topic_0000002373372809_p1531514411418"></a>Passthrough the physical server's NPU device into a privileged container for use.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row531516410114"><td class="cellrowborder" rowspan="3" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p1031515411519"><a name="en-us_topic_0000002373372809_p1031515411519"></a><a name="en-us_topic_0000002373372809_p1031515411519"></a>Virtual machine (VM)<sup id="en-us_topic_0000002373372809_sup198089431922"><a name="en-us_topic_0000002373372809_sup198089431922"></a><a name="en-us_topic_0000002373372809_sup198089431922"></a>b</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p0315154114114"><a name="en-us_topic_0000002373372809_p0315154114114"></a><a name="en-us_topic_0000002373372809_p0315154114114"></a>VM passthrough</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000002373372809_p53151741516"><a name="en-us_topic_0000002373372809_p53151741516"></a><a name="en-us_topic_0000002373372809_p53151741516"></a>Dedicate an entire physical NPU for exclusive use by a single virtual machine. Supported passthrough modes include: full-system (all NPUs), partial (a subset of NPUs), and single-device (one NPU)</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row4315104115119"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p93159411314"><a name="en-us_topic_0000002373372809_p93159411314"></a><a name="en-us_topic_0000002373372809_p93159411314"></a>VM passthrough + unprivileged container</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p16315941119"><a name="en-us_topic_0000002373372809_p16315941119"></a><a name="en-us_topic_0000002373372809_p16315941119"></a>Allocate an entire physical NPU to a VM and then pass its resources through to an unprivileged container running inside that VM.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row1131519411511"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p7315164119114"><a name="en-us_topic_0000002373372809_p7315164119114"></a><a name="en-us_topic_0000002373372809_p7315164119114"></a>VM passthrough + privileged container</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p203151841411"><a name="en-us_topic_0000002373372809_p203151841411"></a><a name="en-us_topic_0000002373372809_p203151841411"></a>Allocate an entire physical NPU to a VM and then pass its resources through to a privileged container running inside that VM.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row7315241315"><td class="cellrowborder" rowspan="4" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p4315104113114"><a name="en-us_topic_0000002373372809_p4315104113114"></a><a name="en-us_topic_0000002373372809_p4315104113114"></a>Ascend Virtual Instance (AVI)<sup id="en-us_topic_0000002373372809_sup165410541824"><a name="en-us_topic_0000002373372809_sup165410541824"></a><a name="en-us_topic_0000002373372809_sup165410541824"></a>c</sup></p>
</td>
<td class="cellrowborder" valign="top" width="18.751875187518753%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p5315741612"><a name="en-us_topic_0000002373372809_p5315741612"></a><a name="en-us_topic_0000002373372809_p5315741612"></a>Physical machine + container-based AVI</p>
</td>
<td class="cellrowborder" valign="top" width="62.496249624962495%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000002373372809_p831514411011"><a name="en-us_topic_0000002373372809_p831514411011"></a><a name="en-us_topic_0000002373372809_p831514411011"></a>On a PM, the npu-smi tool or DCMI is used to partition the NPU hardware resources into vNPUs based on user-defined requirements. The created vNPUs are then mounted to containers for use.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row531512416114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p143156411415"><a name="en-us_topic_0000002373372809_p143156411415"></a><a name="en-us_topic_0000002373372809_p143156411415"></a>PM + VM-based AVI</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p43151141111"><a name="en-us_topic_0000002373372809_p43151141111"></a><a name="en-us_topic_0000002373372809_p43151141111"></a>On a PM, the npu-smi tool or DCMI is used to partition the NPU hardware resources into vNPUs based on user-defined requirements. The created vNPUs are then allocated to the VM for use. A single vNPU can be allocated to only one VM, but a single VM can be mounted with multiple vNPUs.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row73152418114"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p1567091519716"><a name="en-us_topic_0000002373372809_p1567091519716"></a><a name="en-us_topic_0000002373372809_p1567091519716"></a>VM + container-based AVI</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p231574116113"><a name="en-us_topic_0000002373372809_p231574116113"></a><a name="en-us_topic_0000002373372809_p231574116113"></a>Partition the NPU hardware resources into vNPUs using the npu-smi tool or DCMI, based on user-defined requirements. Then allocate specified vNPUs to a VM, and mount the vNPUs to containers in the VM for use.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row93151941719"><td class="cellrowborder" valign="top" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002373372809_p11315184110116"><a name="en-us_topic_0000002373372809_p11315184110116"></a><a name="en-us_topic_0000002373372809_p11315184110116"></a>VM passthrough + container-based AVI</p>
</td>
<td class="cellrowborder" valign="top" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002373372809_p10315124112120"><a name="en-us_topic_0000002373372809_p10315124112120"></a><a name="en-us_topic_0000002373372809_p10315124112120"></a>Allocate a single physical NPU entirely to a VM. Then, within that VM, the NPU is partitioned into vNPUs using the npu-smi tool or DCMI based on user-defined requirements. Finally, these vNPUs are passed through to containers for use.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373372809_row122217819219"><td class="cellrowborder" colspan="3" valign="top" headers="mcps1.2.4.1.1 mcps1.2.4.1.2 mcps1.2.4.1.3 "><p id="en-us_topic_0000002373372809_p18261919824"><a name="en-us_topic_0000002373372809_p18261919824"></a><a name="en-us_topic_0000002373372809_p18261919824"></a>a: Operating NPU resources in a PM environment, including two scenarios: PM and PM + container</p>
<p id="en-us_topic_0000002373372809_p9513057319"><a name="en-us_topic_0000002373372809_p9513057319"></a><a name="en-us_topic_0000002373372809_p9513057319"></a>b: Operating NPU resources in a VM environment, including two scenarios: VM passthrough and VM passthrough + containers</p>
<p id="en-us_topic_0000002373372809_p11102132014313"><a name="en-us_topic_0000002373372809_p11102132014313"></a><a name="en-us_topic_0000002373372809_p11102132014313"></a>c: <span id="en-us_topic_0000002373372809_ph42251523171020"><a name="en-us_topic_0000002373372809_ph42251523171020"></a><a name="en-us_topic_0000002373372809_ph42251523171020"></a>Use resource virtualization technology to partition one NPU into several virtual NPUs (vNPUs) for mounting to VMs or containers, allowing one NPU to handle multiple computing tasks simultaneously. AVI implements this through computing power allocation, enabling secure, multi-tenant resource pooling and on-demand management, which greatly reduces costs and complexity.</span></p>
</td>
</tr>
</tbody>
</table>

## Usage Precautions

- The npu-smi command cannot be used concurrently by multiple threads.
- The command outputs in this document are for reference only.
- Unless otherwise specified, containers in this document refer to unprivileged containers.
- Starting from Ascend 950, the npu-smi tool has been reconstructed. The core optimization of the reconstruction is to unify id and chip_id into dev_id (logical ID of the software) to simplify the command parameter structure and enhance the usage efficiency. The details are as follows:
   1. For Ascend 950, the -i dev_id parameter format must be used, and the -i id -c chip_id parameter format is no longer supported.
   2. For generations before Ascend 950, the -i id -c chip_id parameter format is still used without being affected by the reconstruction.

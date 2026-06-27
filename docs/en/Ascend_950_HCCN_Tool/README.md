# Commands List

## Query Commands

- [Querying hccn\_tool Help Information](./Ascend_950_HCCN_Tool/querying-hccn_tool-help-information.md)
- [Querying the NPU Device Information](./Ascend_950_HCCN_Tool/querying-the-npu-device-information.md)
- [Querying the Port Link Status](./Ascend_950_HCCN_Tool/querying-the-port-link-status.md)
- [Querying the Real-Time Bandwidth Information of a Port](./Ascend_950_HCCN_Tool/querying-the-real-time-bandwidth-information-of-a-port.md)
- [Querying Port Statistics](./Ascend_950_HCCN_Tool/querying-port-statistics.md)
- [Querying the Port Status](./Ascend_950_HCCN_Tool/querying-the-port-status.md)
- [Querying the Peak Bandwidth Information of a Port](./Ascend_950_HCCN_Tool/querying-the-peak-bandwidth-information-of-a-port.md)
- [Querying the Number of Port Bit Errors](./Ascend_950_HCCN_Tool/querying-the-number-of-port-bit-errors.md)
- [Querying the Number of Available Port Chip Credits](./Ascend_950_HCCN_Tool/querying-the-number-of-available-port-chip-credits.md)
- [Querying the Port Rate](./Ascend_950_HCCN_Tool/querying-the-port-rate.md)
- [Querying Port SerDes Information](./Ascend_950_HCCN_Tool/querying-port-serdes-information.md)
- [Querying Port FEC Information](./Ascend_950_HCCN_Tool/querying-port-fec-information.md)
- [Querying the Status Information of a Historical Link Establishment Process of a Port](./Ascend_950_HCCN_Tool/querying-the-status-information-of-a-historical-link-establishment-process-of-a-port.md)
- [Querying the Historical Link Up and Down Status of a Port](./Ascend_950_HCCN_Tool/querying-the-historical-link-up-and-down-status-of-a-port.md)
- [Querying Port Link Information When the Link Is Down](./Ascend_950_HCCN_Tool/querying-port-link-information-when-the-link-is-down.md)
- [Querying the SU Bit Error Mode and Bit Error Statistics of a Port](./Ascend_950_HCCN_Tool/querying-the-su-bit-error-mode-and-bit-error-statistics-of-a-port.md)
- [Querying Interconnect or Disconnection Status of NPU Devices](./Ascend_950_HCCN_Tool/querying-interconnect-or-disconnection-status-of-npu-devices.md)
- [Querying the vNIC IP Address and Link Status of an NPU Device](./Ascend_950_HCCN_Tool/querying-the-vnic-ip-address-and-link-status-of-an-npu-device.md)
- [Querying the DRV Driver Package and Firmware Version Information of an NPU Device](./Ascend_950_HCCN_Tool/querying-the-drv-driver-package-and-firmware-version-information-of-an-npu-device.md)
- [Querying the TLS Certificate Information of an NPU Device](./Ascend_950_HCCN_Tool/querying-the-tls-certificate-information-of-an-npu-device.md)
- [Querying Device-Side Process Information of an NPU Device](./Ascend_950_HCCN_Tool/querying-device-side-process-information-of-an-npu-device.md)
- [Querying the Configuration Recovery Status of an NPU Device](./Ascend_950_HCCN_Tool/querying-the-configuration-recovery-status-of-an-npu-device.md)
- [Querying AEQ Context Information of a Network Device](./Ascend_950_HCCN_Tool/querying-aeq-context-information-of-a-network-device.md)
- [Querying the CEQ Context Information of a Network Device](./Ascend_950_HCCN_Tool/querying-the-ceq-context-information-of-a-network-device.md)
- [Querying the Queue Resource List for a Network Device](./Ascend_950_HCCN_Tool/querying-the-queue-resource-list-for-a-network-device.md)
- [Querying Queue Resource Attributes for a Network Device](./Ascend_950_HCCN_Tool/querying-queue-resource-attributes-for-a-network-device.md)

## Setting Commands

- [Clearing Port Statistics](./Ascend_950_HCCN_Tool/clearing-port-statistics.md)
- [Configure Port Lane Expansion](./Ascend_950_HCCN_Tool/configure-port-lane-expansion.md)
- [Clearing Port SU Bit Error Statistics](./Ascend_950_HCCN_Tool/clearing-port-su-bit-error-statistics.md)
- [Replacing the TLS Certificate of an NPU Device](./Ascend_950_HCCN_Tool/replacing-the-tls-certificate-of-an-npu-device.md)
- [Configuring TLS Enable Status of an NPU Device](./Ascend_950_HCCN_Tool/configuring-tls-enable-status-of-an-npu-device.md)
- [Configuring the TLS Expiration Alarm Threshold for an NPU Device](./Ascend_950_HCCN_Tool/configuring-the-tls-expiration-alarm-threshold-for-an-npu-device.md)
- [Clearing the TLS Certificate Information of an NPU Device](./Ascend_950_HCCN_Tool/clearing-the-tls-certificate-information-of-an-npu-device.md)
- [Restoring Configuration of an NPU Device](./Ascend_950_HCCN_Tool/restoring-configuration-of-an-npu-device.md)
- [Restoring Configurations of All NPU Devices](./Ascend_950_HCCN_Tool/restoring-configurations-of-all-npu-devices.md)

## Test Commands

- [Exporting Register Information of a Port](./Ascend_950_HCCN_Tool/exporting-register-information-of-a-port.md)
- [Setting the SU Bit Error Mode of a Port](./Ascend_950_HCCN_Tool/setting-the-su-bit-error-mode-of-a-port.md)
- [Querying the Result of a UB Ping from a Specified NPU Device to a Destination Address](./Ascend_950_HCCN_Tool/querying-the-result-of-a-ub-ping-from-a-specified-npu-device-to-a-destination-address.md)

# hccn_tool Description

## Overview

This document describes the external APIs of the cluster network tool hccn\_tool, including APIs for querying the system NPU device information and port link status.

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

- Before using this tool, ensure that the driver has been installed. hccn\_tool is installed by default during driver installation. After the installation is complete, hccn\_tool is stored in  **/usr/bin/**  symbolic link. The actual path is  **/usr/local/Ascend/driver/tools**.
- If hccn\_tool needs to be used in the container, mount  **/usr/bin/hccn\_tool**  of the host machine to the container. For details, see  "Installation and Uninstallation in a Container" \> "Installation Scenarios" \> "Host Directory Mounted to the Container" in the  _Atlas 350 Accelerator Card 25.7.RC1 NPU Driver and Firmware Installation Guide_  of the corresponding version.
- hccn\_tool does not support Ascend virtual instances.
- Ascend 950 now provides significantly more NPU ports. However, the legacy hccn\_tool can manage only a single port per NPU. It no longer meets the requirements. Therefore, based on network management objects, the next-generation hccn\_tool has been reconstructed and optimized to manage multiple ports and network devices. Network management objects are indexed according to categories, as shown in  [Table 1](#table14479522135510).

    **Table  1**  Categories of network management objects

    <a name="table14479522135510"></a>
    <table><thead align="left"><tr id="row3480122215512"><th class="cellrowborder" valign="top" width="5.71%" id="mcps1.2.5.1.1"><p id="p1459495113556"><a name="p1459495113556"></a><a name="p1459495113556"></a>Category</p>
    </th>
    <th class="cellrowborder" valign="top" width="12.21%" id="mcps1.2.5.1.2"><p id="p164806220558"><a name="p164806220558"></a><a name="p164806220558"></a>Application Scenario</p>
    </th>
    <th class="cellrowborder" valign="top" width="32.82%" id="mcps1.2.5.1.3"><p id="p164451307013"><a name="p164451307013"></a><a name="p164451307013"></a>Syntax</p>
    </th>
    <th class="cellrowborder" valign="top" width="49.26%" id="mcps1.2.5.1.4"><p id="p9936246419"><a name="p9936246419"></a><a name="p9936246419"></a>Example</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="row1655195291816"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="p148032210554"><a name="p148032210554"></a><a name="p148032210554"></a>NPU device</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="p1748072245519"><a name="p1748072245519"></a><a name="p1748072245519"></a>Operations on a single NPU device (ignoring details such as its internal ports or UDie).</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="p68096111620"><a name="p68096111620"></a><a name="p68096111620"></a><span id="ph9793175810161"><a name="ph9793175810161"></a><a name="ph9793175810161"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; [-options]</span></p>
    <a name="ul2057415561126"></a><a name="ul2057415561126"></a><ul id="ul2057415561126"><li><strong id="b35261743181413"><a name="b35261743181413"></a><a name="b35261743181413"></a>-mode</strong> indicates the command mode. The value can be <strong id="b137032556141"><a name="b137032556141"></a><a name="b137032556141"></a>-g</strong> (query command), <strong id="b1349220161515"><a name="b1349220161515"></a><a name="b1349220161515"></a>-s</strong> (setting command), or <strong id="b10973876151"><a name="b10973876151"></a><a name="b10973876151"></a>-t</strong> (test command).</li><li><strong id="b1979920161517"><a name="b1979920161517"></a><a name="b1979920161517"></a>-cmd</strong> indicates a main command word of an available command. For details, see the help information output in the corresponding mode.</li></ul>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="ol5191359175113"></a><a name="ol5191359175113"></a><ol id="ol5191359175113"><li>Run the <strong id="b1416692391613"><a name="b1416692391613"></a><a name="b1416692391613"></a>npu-smi info</strong> command to obtain the NPU ID (that is, <strong id="b549135031612"><a name="b549135031612"></a><a name="b549135031612"></a>dev_id</strong> to be used in the following command).</li><li>Run the <strong id="b12632202514180"><a name="b12632202514180"></a><a name="b12632202514180"></a><span id="ph1176216540169"><a name="ph1176216540169"></a><a name="ph1176216540169"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; [-options]</span></strong> command.<p id="p9521646121615"><a name="p9521646121615"></a><a name="p9521646121615"></a>For example, to query NPU information, run the <strong id="b1577029121811"><a name="b1577029121811"></a><a name="b1577029121811"></a><span id="ph1363312397193"><a name="ph1363312397193"></a><a name="ph1363312397193"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span></strong> command.</p>
    </li></ol>
    </td>
    </tr>
    <tr id="row64802022135517"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="p54807223551"><a name="p54807223551"></a><a name="p54807223551"></a>NPU port</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="p18480422135514"><a name="p18480422135514"></a><a name="p18480422135514"></a>Operations on a single port.</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="p6350123201019"><a name="p6350123201019"></a><a name="p6350123201019"></a><span id="ph148913931811"><a name="ph148913931811"></a><a name="ph148913931811"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -u &lt;udie_id&gt; -p &lt;port_id&gt; [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="ol1067116134516"></a><a name="ol1067116134516"></a><ol id="ol1067116134516"><li>Run the <strong id="en-us_topic_0000002584451446_b1416692391613"><a name="en-us_topic_0000002584451446_b1416692391613"></a><a name="en-us_topic_0000002584451446_b1416692391613"></a>npu-smi info</strong> command to obtain the NPU ID (that is, <strong id="en-us_topic_0000002584451446_b549135031612"><a name="en-us_topic_0000002584451446_b549135031612"></a><a name="en-us_topic_0000002584451446_b549135031612"></a>dev_id</strong> to be used in the following command).</li><li>Run the <strong id="b1674582015191"><a name="b1674582015191"></a><a name="b1674582015191"></a><span id="ph963317495199"><a name="ph963317495199"></a><a name="ph963317495199"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span></strong> command to obtain the UDie ID (<strong id="b182759297199"><a name="b182759297199"></a><a name="b182759297199"></a>udie_id</strong>) and port ID (<strong id="b1335032101915"><a name="b1335032101915"></a><a name="b1335032101915"></a>port_id</strong>).</li><li>Run the <strong id="b87271848101915"><a name="b87271848101915"></a><a name="b87271848101915"></a><span id="ph1848361692115"><a name="ph1848361692115"></a><a name="ph1848361692115"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -u &lt;udie_id&gt; -p &lt;port_id&gt; [-options]</span></strong> command.<p id="p1584461355612"><a name="p1584461355612"></a><a name="p1584461355612"></a>For example, to obtain the port link status, run the <strong id="b57133332813"><a name="b57133332813"></a><a name="b57133332813"></a>hccn_tool -g -link -i 0 -u 0 -p 4</strong> command.</p>
    </li></ol>
    </td>
    </tr>
    <tr id="row1048062210552"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="p1648020224552"><a name="p1648020224552"></a><a name="p1648020224552"></a>Network device</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="p1248020220559"><a name="p1248020220559"></a><a name="p1248020220559"></a>Operations on Ethernet and UB network devices.</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="p201981929184316"><a name="p201981929184316"></a><a name="p201981929184316"></a><span id="ph13807846191811"><a name="ph13807846191811"></a><a name="ph13807846191811"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -d &lt;dev_name&gt; [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="ol174671024487"></a><a name="ol174671024487"></a><ol id="ol174671024487"><li>Run the <strong id="en-us_topic_0000002584451446_b1416692391613_1"><a name="en-us_topic_0000002584451446_b1416692391613_1"></a><a name="en-us_topic_0000002584451446_b1416692391613_1"></a>npu-smi info</strong> command to obtain the NPU ID (that is, <strong id="en-us_topic_0000002584451446_b549135031612_1"><a name="en-us_topic_0000002584451446_b549135031612_1"></a><a name="en-us_topic_0000002584451446_b549135031612_1"></a>dev_id</strong> to be used in the following command).</li><li>Run the <strong id="b311685252810"><a name="b311685252810"></a><a name="b311685252810"></a><span id="ph1110697204"><a name="ph1110697204"></a><a name="ph1110697204"></a>hccn_tool -g -dev_info -i &lt;dev_id&gt;</span></strong> command to obtain the interface name or name (<strong id="b17540155812286"><a name="b17540155812286"></a><a name="b17540155812286"></a>dev_name</strong>). For details about the <strong id="b151691916192912"><a name="b151691916192912"></a><a name="b151691916192912"></a>dev_name</strong> value, see the description of each command.</li><li>Run the <strong id="b15813202916"><a name="b15813202916"></a><a name="b15813202916"></a><span id="ph11886239122111"><a name="ph11886239122111"></a><a name="ph11886239122111"></a>hccn_tool -mode -cmd -i &lt;dev_id&gt; -d &lt;dev_name&gt; [-options]</span></strong> command.<p id="p1972712873217"><a name="p1972712873217"></a><a name="p1972712873217"></a>For example, to query the resource quantity statistics list of a network device, run the <strong id="b11457104416191"><a name="b11457104416191"></a><a name="b11457104416191"></a>hccn_tool -g -show_list -i &lt;dev_id&gt; -d &lt;dev_name&gt;</strong> command.</p>
    </li></ol>
    </td>
    </tr>
    <tr id="row148192215512"><td class="cellrowborder" valign="top" width="5.71%" headers="mcps1.2.5.1.1 "><p id="p14874112518417"><a name="p14874112518417"></a><a name="p14874112518417"></a>All NPU devices</p>
    </td>
    <td class="cellrowborder" valign="top" width="12.21%" headers="mcps1.2.5.1.2 "><p id="p223218411050"><a name="p223218411050"></a><a name="p223218411050"></a>Operations on all NPUs.</p>
    </td>
    <td class="cellrowborder" valign="top" width="32.82%" headers="mcps1.2.5.1.3 "><p id="p424153618441"><a name="p424153618441"></a><a name="p424153618441"></a><span id="ph1725774171918"><a name="ph1725774171918"></a><a name="ph1725774171918"></a>hccn_tool -mode -cmd -all [-options]</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="49.26%" headers="mcps1.2.5.1.4 "><a name="ol128145552538"></a><a name="ol128145552538"></a><ol id="ol128145552538"><li>Run the <strong id="b613083820276"><a name="b613083820276"></a><a name="b613083820276"></a><span id="ph161126182215"><a name="ph161126182215"></a><a name="ph161126182215"></a>hccn_tool -mode -cmd -all [-options]</span></strong> command.<p id="p196581649164818"><a name="p196581649164818"></a><a name="p196581649164818"></a>For example, to restore the configurations of all NPU devices, run the <strong id="b15705191242818"><a name="b15705191242818"></a><a name="b15705191242818"></a>hccn_tool -s -cfg_recovery -all</strong> command.</p>
    </li></ol>
    </td>
    </tr>
    </tbody>
    </table>

# Setting Continuous Log Collection for All Devices<a name="EN-US_TOPIC_0000002554971869"></a>

## Function<a name="section510993322119"></a>

This command is used to continuously collect logs of all devices.

## Syntax<a name="section1461145662117"></a>

`npu-smi set -t sys-log-dump -s level -f path`

## Parameters<a name="section611415295410"></a>

**Table  1**  Parameters

<a name="en-us_topic_0000002269263413_table1915916283217"></a>
<table><thead align="left"><tr id="en-us_topic_0000002269263413_row193063215320"><th class="cellrowborder" valign="top" width="30%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000002269263413_p1330610283217"><a name="en-us_topic_0000002269263413_p1330610283217"></a><a name="en-us_topic_0000002269263413_p1330610283217"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000002269263413_p113061223215"><a name="en-us_topic_0000002269263413_p113061223215"></a><a name="en-us_topic_0000002269263413_p113061223215"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002269263413_row23061825320"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000002269263413_p11306192163213"><a name="en-us_topic_0000002269263413_p11306192163213"></a><a name="en-us_topic_0000002269263413_p11306192163213"></a><em id="en-us_topic_0000002269263413_i73068203215"><a name="en-us_topic_0000002269263413_i73068203215"></a><a name="en-us_topic_0000002269263413_i73068203215"></a>level</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000002269263413_p14724145416554"><a name="en-us_topic_0000002269263413_p14724145416554"></a><a name="en-us_topic_0000002269263413_p14724145416554"></a>Log dumping level. The level must be an integer ranging from 1 to 10.</p>
</td>
</tr>
<tr id="en-us_topic_0000002269263413_row103068218328"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000002269263413_p18306326328"><a name="en-us_topic_0000002269263413_p18306326328"></a><a name="en-us_topic_0000002269263413_p18306326328"></a><em id="en-us_topic_0000002269263413_i0306929320"><a name="en-us_topic_0000002269263413_i0306929320"></a><a name="en-us_topic_0000002269263413_i0306929320"></a>path</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000002269263413_p63891747153214"><a name="en-us_topic_0000002269263413_p63891747153214"></a><a name="en-us_topic_0000002269263413_p63891747153214"></a>Log storage path.</p>
<p id="en-us_topic_0000002269263413_p103061229321"><a name="en-us_topic_0000002269263413_p103061229321"></a><a name="en-us_topic_0000002269263413_p103061229321"></a>Ensure that the path is an existing absolute path and that the current user has read, write, and execute permissions.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="section13144102203217"></a>

- If the log dumping and the continuous log collection for all devices are enabled, logs of all devices are continuously collected and dumped after the system is restarted. For details about how to enable log dumping in persistence mode, see  [Enabling or Disabling Log Dumping in Persistence Mode](enabling-or-disabling-log-dumping-in-persistence-mode.md).
- In the log storage path, each device has a timestamp file for storing logs collected continuously. When the log capacity or log quantity of the current timestamp file reaches the upper limit, new logs will overwrite the earliest logs. When the level is 1, the maximum log capacity of a single NPU's current timestamp file is about 100 MB. Each increment in level increases the capacity by roughly 100 MB.
- Restarting a device or re-executing the command converts the current timestamp file into a historical timestamp file. When either the log capacity or the number of historical timestamp files reaches the configured upper limit, the system deletes the oldest historical file until the usage falls within the allowed threshold. When the level is 1, the maximum log capacity of a single NPU's historical timestamp file is 200 MB. Each increment in level increases the capacity by 200 MB. In addition, the system can store a maximum of 99 historical timestamp files.
- At level 1, each NPU requires 300 MB of log storage space. For each additional level, the required storage increases by 300 MB. To ensure sufficient capacity in the log storage path, calculate the total required space based on the number of devices and the configured log dumping level.
- If continuous log collection is enabled for all devices, the collection task will be temporarily disabled during upgrade or overwrite installation. Once the process is complete, the task will be automatically reactivated.

**Table  2** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row2056819579256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p10568457202515"><a name="en-us_topic_0000002484466758_p10568457202515"></a><a name="en-us_topic_0000002484466758_p10568457202515"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p3568155712520"><a name="en-us_topic_0000002484466758_p3568155712520"></a><a name="en-us_topic_0000002484466758_p3568155712520"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p7568757122511"><a name="en-us_topic_0000002484466758_p7568757122511"></a><a name="en-us_topic_0000002484466758_p7568757122511"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p1556812578254"><a name="en-us_topic_0000002484466758_p1556812578254"></a><a name="en-us_topic_0000002484466758_p1556812578254"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p105681557162517"><a name="en-us_topic_0000002484466758_p105681557162517"></a><a name="en-us_topic_0000002484466758_p105681557162517"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row185688570253"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p175691857172519"><a name="en-us_topic_0000002484466758_p175691857172519"></a><a name="en-us_topic_0000002484466758_p175691857172519"></a><strong id="en-us_topic_0000002484466758_b1884169617"><a name="en-us_topic_0000002484466758_b1884169617"></a><a name="en-us_topic_0000002484466758_b1884169617"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p1056925762517"><a name="en-us_topic_0000002484466758_p1056925762517"></a><a name="en-us_topic_0000002484466758_p1056925762517"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1510091906"><a name="en-us_topic_0000002484466758_b1510091906"></a><a name="en-us_topic_0000002484466758_b1510091906"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p1256975772514"><a name="en-us_topic_0000002484466758_p1256975772514"></a><a name="en-us_topic_0000002484466758_p1256975772514"></a><strong id="en-us_topic_0000002484466758_b722667928"><a name="en-us_topic_0000002484466758_b722667928"></a><a name="en-us_topic_0000002484466758_b722667928"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p2569157132518"><a name="en-us_topic_0000002484466758_p2569157132518"></a><a name="en-us_topic_0000002484466758_p2569157132518"></a><strong id="en-us_topic_0000002484466758_b527740528"><a name="en-us_topic_0000002484466758_b527740528"></a><a name="en-us_topic_0000002484466758_b527740528"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p656975711257"><a name="en-us_topic_0000002484466758_p656975711257"></a><a name="en-us_topic_0000002484466758_p656975711257"></a><strong id="en-us_topic_0000002484466758_b1518861502"><a name="en-us_topic_0000002484466758_b1518861502"></a><a name="en-us_topic_0000002484466758_b1518861502"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row65691257162516"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p1356905716259"><a name="en-us_topic_0000002484466758_p1356905716259"></a><a name="en-us_topic_0000002484466758_p1356905716259"></a><span id="en-us_topic_0000002484466758_ph1569135714257"><a name="en-us_topic_0000002484466758_ph1569135714257"></a><a name="en-us_topic_0000002484466758_ph1569135714257"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_p15569657112515"><a name="en-us_topic_0000002484466758_p15569657112515"></a><a name="en-us_topic_0000002484466758_p15569657112515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_p16569257142516"><a name="en-us_topic_0000002484466758_p16569257142516"></a><a name="en-us_topic_0000002484466758_p16569257142516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p127191613267"><a name="en-us_topic_0000002484466758_p127191613267"></a><a name="en-us_topic_0000002484466758_p127191613267"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p1356945762511"><a name="en-us_topic_0000002484466758_p1356945762511"></a><a name="en-us_topic_0000002484466758_p1356945762511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p7569135772519"><a name="en-us_topic_0000002484466758_p7569135772519"></a><a name="en-us_topic_0000002484466758_p7569135772519"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row55691557132514"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p195699573251"><a name="en-us_topic_0000002484466758_p195699573251"></a><a name="en-us_topic_0000002484466758_p195699573251"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section614617253216"></a>

Set the system to continuously collect logs of all devices to the  **/home/tmp**  directory and set the log capacity level to  **3**.

```bash
npu-smi set -t sys-log-dump -s 3 -f /home/tmp
```

```text
This command will introduce a permanent process in host to collect system logs continuously, Make sure that this path space capacity can save the system logs collected by the current gear setting.
Warning: if the gear you set this time is different from last time, some historical logs will be lost! Make sure that historical logs are backed up!
Are you sure you want to continue this command?(Y/N)
y
2026-01-25 10:12:56.446 Start exporting logs and files to path: /home/tmp/NPU-0/2026-01-25-10-12-56
2026-01-25 10:12:56.448 Start exporting logs and files to path: /home/tmp/NPU-1/2026-01-25-10-12-56
2026-01-25 10:12:56.450 Start exporting logs and files to path: /home/tmp/NPU-2/2026-01-25-10-12-56
2026-01-25 10:12:56.452 Start exporting logs and files to path: /home/tmp/NPU-3/2026-01-25-10-12-56
```

## Output Description<a name="section128611148449"></a>

None

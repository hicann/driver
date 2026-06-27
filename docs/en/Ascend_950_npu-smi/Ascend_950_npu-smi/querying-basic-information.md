# Querying Basic Information<a name="EN-US_TOPIC_0000002484306762"></a>

## Function<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section10160164417116"></a>

This command is used to query basic information about all devices.

## Syntax<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section1516414419110"></a>

`npu-smi info`

## Parameters<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section2106140121613"></a>

- In the idle state, 35 MB to 45 MB on-chip memory is occupied because TaiShan cores are started and loaded, which is normal.
- If no process is running on the device, "No running processes found in NPU  _dev\_id_" is displayed in the command output.
- Information about a maximum of eight on-device SVM processes can be displayed on each chip.
- For host machines and privileged containers, this command queries all processes running in a host machine, in an unprivileged container, and in a privileged container. For unprivileged containers, this command queries only all processes running in an unprivileged container.

    **Table  1** Support in different deployment scenarios

    <a name="table7280184483416"></a>
    <table><thead align="left"><tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p44201360411"></a>Hardware Model/Scenario</p>
    </th>
    <th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p75637171408"></a>PM (Bare Metal)</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p5649445717"><a name="en-us_topic_0000002484466758_p5649445717"></a><a name="en-us_topic_0000002484466758_p5649445717"></a>PM + Privileged Container</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p12563111734020"></a>PM + Unprivileged Container</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564317134011"></a>VM Passthrough</p>
    </th>
    </tr>
    <tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p15564417174012"></a><strong id="en-us_topic_0000002484466758_b16723134216619"><a name="en-us_topic_0000002484466758_b16723134216619"></a><a name="en-us_topic_0000002484466758_b16723134216619"></a>root</strong> User</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p14564617114019"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1944445364"><a name="en-us_topic_0000002484466758_b1944445364"></a><a name="en-us_topic_0000002484466758_b1944445364"></a>root</strong> User)</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p116412411579"><a name="en-us_topic_0000002484466758_p116412411579"></a><a name="en-us_topic_0000002484466758_p116412411579"></a><strong id="en-us_topic_0000002484466758_b19691194714618"><a name="en-us_topic_0000002484466758_b19691194714618"></a><a name="en-us_topic_0000002484466758_b19691194714618"></a>root</strong> User</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7564117174014"></a><strong id="en-us_topic_0000002484466758_b5170174915615"><a name="en-us_topic_0000002484466758_b5170174915615"></a><a name="en-us_topic_0000002484466758_b5170174915615"></a>root</strong> User</p>
    </th>
    <th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p356491714408"></a><strong id="en-us_topic_0000002484466758_b76581504619"><a name="en-us_topic_0000002484466758_b76581504619"></a><a name="en-us_topic_0000002484466758_b76581504619"></a>root</strong> User</p>
    </th>
    </tr>
    </thead>
    <tbody><tr id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_row185641517124016"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p144147361596"><a name="en-us_topic_0000002484466758_p144147361596"></a><a name="en-us_topic_0000002484466758_p144147361596"></a><span id="en-us_topic_0000002484466758_ph12140626193614"><a name="en-us_topic_0000002484466758_ph12140626193614"></a><a name="en-us_topic_0000002484466758_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
    </td>
    <td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p256471710404"></a>Y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p45656172402"></a>Y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p125931265317"><a name="en-us_topic_0000002484466758_p125931265317"></a><a name="en-us_topic_0000002484466758_p125931265317"></a>Y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002027614521_p7566161714013"></a>Y</p>
    </td>
    <td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p158021256175710"><a name="en-us_topic_0000002484466758_p158021256175710"></a><a name="en-us_topic_0000002484466758_p158021256175710"></a>Y</p>
    </td>
    </tr>
    <tr id="en-us_topic_0000002484466758_row651184316559"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p2194113775312"><a name="en-us_topic_0000002484466758_p2194113775312"></a><a name="en-us_topic_0000002484466758_p2194113775312"></a>Note: <strong id="en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
    </td>
    </tr>
    </tbody>
    </table>

## Example<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section15164444410"></a>

Query basic information about all devices.

```bash
 npu-smi info
```

```text
+-------------------------------------------------------------------------------------------------+
| npu-smi x.x.x                           Version: x.x.x                                          |
+---------------------------+---------------+-----------------------------------------------------+
| NPU ID | Name             | Health        | Power(W)    Temp(C)           Hugepages-Usage(page) |
|        |                  | Bus-Id        | NPU Util(%) Memory-Usage(MB)  HBM-Usage(MB)         |
+========+==================+===============+=====================================================+
| 0      | xxx              | OK            | 204.4       56                0     / 0             |
|        |                  | 0000:91:00.0  | 0           0    / 0          4439  / 86016         |
+========+==================+===============+=====================================================+
+---------------------------+---------------+-----------------------------------------------------+
| NPU ID                    | Process id    | Process name             | Process memory(MB)       |
+===========================+===============+=====================================================+
| No running processes found in NPU 0                                                             |
+===========================+===============+=====================================================+
```

## Output Description<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_section184748247112"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p5633745174"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p5633745174"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p5633745174"></a>npu-smi</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p899153843819"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p899153843819"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p899153843819"></a>Version of the npu-smi tool.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1633164514714"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1633164514714"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1633164514714"></a>Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p563313451878"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p563313451878"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p563313451878"></a>Driver version.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p146336451476"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p146336451476"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p146336451476"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p14633144510711"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p14633144510711"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p14633144510711"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p12633134515711"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p12633134515711"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p12633134515711"></a>Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p166331451678"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p166331451678"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p166331451678"></a>Chip name.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row46337451575"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1563314458710"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1563314458710"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1563314458710"></a>Health</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1556115516419"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1556115516419"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1556115516419"></a>Chip health status.</p>
<p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p343615918910"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p343615918910"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p343615918910"></a>The status can be <strong id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b881104882311"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b881104882311"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b881104882311"></a>OK</strong>, <strong id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b8425145012313"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b8425145012313"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b8425145012313"></a>Warning</strong>, <strong id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b11115145322314"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b11115145322314"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b11115145322314"></a>Alarm</strong>, <strong id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1559055182310"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1559055182310"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1559055182310"></a>Critical</strong>, or <strong id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1190385813235"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1190385813235"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_b1190385813235"></a>UNKNOWN</strong>.</p>
<a name="ul510071395519"></a><a name="ul510071395519"></a><ul id="ul510071395519"><li><strong id="b10601112554914"><a name="b10601112554914"></a><a name="b10601112554914"></a>OK</strong>: normal.</li><li><strong id="b196991428124918"><a name="b196991428124918"></a><a name="b196991428124918"></a>Warning</strong>: minor alarm.</li><li><strong id="b252033011493"><a name="b252033011493"></a><a name="b252033011493"></a>Alarm</strong>: major alarm.</li><li><strong id="b19965231144918"><a name="b19965231144918"></a><a name="b19965231144918"></a>Critical</strong>: critical alarm.</li><li><strong id="b1676219335497"><a name="b1676219335497"></a><a name="b1676219335497"></a>UNKNOWN</strong>: The device does not exist or is not started.</li></ul>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row108253391374"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p208259390718"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p208259390718"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p208259390718"></a>Power(W)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p19949121813345"><a name="p19949121813345"></a><a name="p19949121813345"></a>Chip power.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row17354158276"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1355485710"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1355485710"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1355485710"></a>Temp(C)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p2035568379"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p2035568379"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p2035568379"></a>Chip temperature (unit: &deg;C).</p>
<div class="note" id="note10178195185818"><a name="note10178195185818"></a><a name="note10178195185818"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1995313511589"><a name="p1995313511589"></a><a name="p1995313511589"></a>Temperature differences occur between chips due to differences in the chip bodies, TIM material deformation, structure tolerance, and upper-layer applications. If no overtemperature alarm is generated, the functions and performance are not affected.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_row28012145551"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_p8801101411559"><a name="en-us_topic_0000001264656717_p8801101411559"></a><a name="en-us_topic_0000001264656717_p8801101411559"></a>Hugepages-Usage(page)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_p98015143553"><a name="en-us_topic_0000001264656717_p98015143553"></a><a name="en-us_topic_0000001264656717_p98015143553"></a>Number of used huge pages. The size of each page is 2048 KB.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row577818201211"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p577902017210"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p577902017210"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p577902017210"></a>Bus-Id</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p47793201329"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p47793201329"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p47793201329"></a>Bus ID.</p>
</td>
</tr>
<tr id="row19832031102618"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p1683931162614"><a name="p1683931162614"></a><a name="p1683931162614"></a>NPU Util(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1383103118263"><a name="p1383103118263"></a><a name="p1383103118263"></a>Comprehensive NPU utilization.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_row1488213552717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1388205518714"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1388205518714"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p1388205518714"></a>Memory-Usage(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p15882145517712"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p15882145517712"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_en-us_topic_0251720880_p15882145517712"></a>DDR memory usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_row12727142582718"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p772742515271"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p772742515271"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p772742515271"></a>HBM-Usage(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p1172710250271"><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p1172710250271"></a><a name="en-us_topic_0000001264656717_en-us_topic_0000001117597270_p1172710250271"></a>On-chip memory usage. The system occupies some memory even when no service is running.</p>
</td>
</tr>
<tr id="row12841853143614"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p177251111347"><a name="p177251111347"></a><a name="p177251111347"></a>Process id</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576474_p6697901593"><a name="en-us_topic_0000001220576474_p6697901593"></a><a name="en-us_topic_0000001220576474_p6697901593"></a>Process ID.</p>
</td>
</tr>
<tr id="row4549195963620"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p5299131814349"><a name="p5299131814349"></a><a name="p5299131814349"></a>Process name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576474_p419462113431"><a name="en-us_topic_0000001220576474_p419462113431"></a><a name="en-us_topic_0000001220576474_p419462113431"></a>Process name.</p>
</td>
</tr>
<tr id="row1313919293715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p1785562013342"><a name="p1785562013342"></a><a name="p1785562013342"></a>Process memory(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576474_p193751818154310"><a name="en-us_topic_0000001220576474_p193751818154310"></a><a name="en-us_topic_0000001220576474_p193751818154310"></a>Memory occupied by a process (unit: MB).</p>
</td>
</tr>
</tbody>
</table>

> **NOTE:** 
> 
> If the following information is displayed in the last line of the command output after the  **npu-smi info**  command is executed in a non-container scenario, the driver package is not completely installed. In this case, reinstall the driver package.
> The driver package may not be completely installed, which may cause function abnormal. Please reinstall it.

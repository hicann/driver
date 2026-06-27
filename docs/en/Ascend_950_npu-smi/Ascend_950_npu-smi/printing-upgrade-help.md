# Printing Upgrade Help<a name="EN-US_TOPIC_0000002516426705"></a>

## Function<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section18674262006"></a>

This command is used to display the help information about upgrade commands.

## Syntax<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section386902615016"></a>

```bash
npu-smi upgrade -h
npu-smi upgrade --help
```

## Parameters<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section2106140121613"></a>

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

## Example<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section66051714132117"></a>

Display the help information about upgrade commands.

```bash
npu-smi upgrade -h
```

```text
Usage: npu-smi upgrade <-h|-t type|-b type> [Options...]

Commands:
       -h, --help     Show this help text and exit
       -t type        Upgrade device firmware
                      type: vrd
       -b type        Query the firmware version
                      type: vrd vdm

Options:
       -i ID          Upgrade for this device ID
       -f file        The firmware file path
```

## Output Description<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a>-h</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a>Displays the help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a>Displays the help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p564183915134"></a>-t type</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p4410194515562"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p4410194515562"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p4410194515562"></a>Upgrades device firmware.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row8932111419508"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1993221415505"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1993221415505"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1993221415505"></a>-b type</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p9116124917560"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p9116124917560"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p9116124917560"></a>Queries the firmware version.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row268112514506"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p14530421598"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p14530421598"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p14530421598"></a>-i ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p268142510504"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p268142510504"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p268142510504"></a>Displays the logical ID of the software.</p>
</td>
</tr>
<tr id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_row116876412593"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p8687184135912"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p8687184135912"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p8687184135912"></a>-f file</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p6687134113592"><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p6687134113592"></a><a name="en-us_topic_0000001459123601_en-us_topic_0000001457338873_p6687134113592"></a>Displays the firmware file path.</p>
</td>
</tr>
</tbody>
</table>

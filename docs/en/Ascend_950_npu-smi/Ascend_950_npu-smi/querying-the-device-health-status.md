# Querying the Device Health Status<a name="EN-US_TOPIC_0000002484306816"></a>

## Function<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section18674262006"></a>

This command is used to query the overall health status of a device.

## Syntax<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section386902615016"></a>

`npu-smi info -t health -i dev_id`

## Parameters<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section1786919261014"></a>

<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p3985976"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p3985976"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p3985976"></a><strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b16924151019261"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b16924151019261"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b16924151019261"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p54428625"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p54428625"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p54428625"></a><strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b18925510122616"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b18925510122616"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b18925510122616"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p57396781"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p57396781"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p57396781"></a><span id="ph327310104345"><a name="ph327310104345"></a><a name="ph327310104345"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section1526512623318"></a>

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

## Example<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section66051714132117"></a>

Query the health status of device 0.

```bash
npu-smi info -t health -i 0
```

```text
        NPU ID                         : 0
        Health                         : OK
        Error Code                     : NA
        Error Information              : NA
```

## Output Description<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_section184748247112"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_row169579361599"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p99581536592"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p99581536592"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p99581536592"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p193811939740"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p193811939740"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_p193811939740"></a><span id="ph8823113914403"><a name="ph8823113914403"></a><a name="ph8823113914403"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_row945556593"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p34094645"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p34094645"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p34094645"></a>Health</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p102685563124"><a name="p102685563124"></a><a name="p102685563124"></a>Overall health status of a device.</p>
<p id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p1859317139412"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p1859317139412"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_en-us_topic_0200634534_p1859317139412"></a>The status can be <strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b5711150135719"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b5711150135719"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b5711150135719"></a>OK</strong>, <strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1671113019575"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1671113019575"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1671113019575"></a>Warning</strong>, <strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b207111707576"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b207111707576"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b207111707576"></a>Alarm</strong>, <strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1571240195714"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1571240195714"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b1571240195714"></a>Critical</strong>, or <strong id="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b2712906571"><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b2712906571"></a><a name="en-us_topic_0000001264416749_en-us_topic_0000001117437340_b2712906571"></a>UNKNOWN</strong>.</p>
<a name="ul510071395519"></a><a name="ul510071395519"></a><ul id="ul510071395519"><li><strong id="b14723824105316"><a name="b14723824105316"></a><a name="b14723824105316"></a>OK</strong>: normal.</li><li><strong id="b692512302537"><a name="b692512302537"></a><a name="b692512302537"></a>Warning</strong>: minor alarm.</li><li><strong id="b11181103517538"><a name="b11181103517538"></a><a name="b11181103517538"></a>Alarm</strong>: major alarm.</li><li><strong id="b115663818532"><a name="b115663818532"></a><a name="b115663818532"></a>Critical</strong>: critical alarm.</li><li><strong id="b1414115435534"><a name="b1414115435534"></a><a name="b1414115435534"></a>UNKNOWN</strong>: The device does not exist or is not started.</li></ul>
<div class="note" id="note1419645992613"><a name="note1419645992613"></a><a name="note1419645992613"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p15196659172617"><a name="p15196659172617"></a><a name="p15196659172617"></a>If more than one alarm is reported, the most critical alarm applies.</p>
</div></div>
</td>
</tr>
<tr id="row18600131716389"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p860021711389"><a name="p860021711389"></a><a name="p860021711389"></a>Error Code</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p14600121711381"><a name="p14600121711381"></a><a name="p14600121711381"></a>Error code.</p>
<p id="p3239191703914"><a name="p3239191703914"></a><a name="p3239191703914"></a>If the command output contains an error code, refer to the <span id="ph13726154295116"><a name="ph13726154295116"></a><a name="ph13726154295116"></a>Ascend 950 Product Black Box Error Code List</span> or <span id="ph1630384313518"><a name="ph1630384313518"></a><a name="ph1630384313518"></a>Ascend 950 Product Health Management Fault Definitions</span> to check it.</p>
</td>
</tr>
<tr id="row19998151112389"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p0998141173815"><a name="p0998141173815"></a><a name="p0998141173815"></a>Error Information</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1099871143818"><a name="p1099871143818"></a><a name="p1099871143818"></a>Error message.</p>
</td>
</tr>
</tbody>
</table>

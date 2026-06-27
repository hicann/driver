# Querying the Alarm Information of a Device<a name="EN-US_TOPIC_0000002510839454"></a>

## Function<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section18674262006"></a>

This command is used to query the alarm information of a device.

## Syntax<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section386902615016"></a>

`npu-smi info -t current-fault-event -i dev_id`

## Parameters<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section1786919261014"></a>

<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p3985976"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p3985976"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p54428625"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p54428625"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p57396781"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p57396781"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_p57396781"></a><span id="ph1516118208524"><a name="ph1516118208524"></a><a name="ph1516118208524"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section548519815396"></a>

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

## Example<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section66051714132117"></a>

Query the alarm information of device 0.

```bash
npu-smi info -t current-fault-event -i 0
```

```text
Fault Event Count              : 1
Fault Event Information        : event id=0x81AF8000, severity=2, node type ex=215, node id=0, sub node type ex=0, sub node id=0
```

## Output Description<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_section184748247112"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="25.75%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="74.25%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_row55102218"><td class="cellrowborder" valign="top" width="25.75%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p34094645"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p34094645"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p34094645"></a>Fault Event Count</p>
</td>
<td class="cellrowborder" valign="top" width="74.25%" headers="mcps1.2.3.1.2 "><p id="p31311537194514"><a name="p31311537194514"></a><a name="p31311537194514"></a>Number of chip fault events.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_row55913876"><td class="cellrowborder" valign="top" width="25.75%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p543852513417"><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p543852513417"></a><a name="en-us_topic_0000001264416745_en-us_topic_0000001163757097_en-us_topic_0251720847_en-us_topic_0200634534_p543852513417"></a>Fault Event Information</p>
</td>
<td class="cellrowborder" valign="top" width="74.25%" headers="mcps1.2.3.1.2 "><p id="p121297377455"><a name="p121297377455"></a><a name="p121297377455"></a>Fault event information.</p>
<a name="ul4578164195019"></a><a name="ul4578164195019"></a><ul id="ul4578164195019"><li><strong id="b16359134511241"><a name="b16359134511241"></a><a name="b16359134511241"></a>event id</strong>: event ID.</li><li><strong id="b1043395562716"><a name="b1043395562716"></a><a name="b1043395562716"></a>severity</strong>: event severity (<strong id="b54341155102712"><a name="b54341155102712"></a><a name="b54341155102712"></a>0</strong>: warning; <strong id="b18434055182720"><a name="b18434055182720"></a><a name="b18434055182720"></a>1</strong>: minor; <strong id="b13434255102710"><a name="b13434255102710"></a><a name="b13434255102710"></a>2</strong>: major; <strong id="b243410550273"><a name="b243410550273"></a><a name="b243410550273"></a>3</strong>: critical).</li><li><strong id="b13587154272514"><a name="b13587154272514"></a><a name="b13587154272514"></a>node type ex</strong>: chip type.</li><li><strong id="b1479149132517"><a name="b1479149132517"></a><a name="b1479149132517"></a>node id</strong>: hardware serial number of the chip.</li><li><strong id="b243218642614"><a name="b243218642614"></a><a name="b243218642614"></a>sub node type ex</strong>: chip sub-object type.</li><li><strong id="b3206151572613"><a name="b3206151572613"></a><a name="b3206151572613"></a>sub node id</strong>: hardware serial number of the chip sub-object.</li></ul>
<p id="p175311810256"><a name="p175311810256"></a><a name="p175311810256"></a>If the command output contains fault event information, refer to the <span id="ph113511551431"><a name="ph113511551431"></a><a name="ph113511551431"></a>Ascend 950 Product Black Box Error Code List</span> or <span id="ph163516552035"><a name="ph163516552035"></a><a name="ph163516552035"></a>Ascend 950 Product Health Management Fault Definitions</span> to check it.</p>
</td>
</tr>
</tbody>
</table>

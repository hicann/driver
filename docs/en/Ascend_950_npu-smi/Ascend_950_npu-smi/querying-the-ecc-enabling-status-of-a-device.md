# Querying the ECC Enabling Status of a Device<a name="EN-US_TOPIC_0000002484306806"></a>

## Function<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section18674262006"></a>

This command is used to query the ECC enabling status of an NPU.

## Syntax<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section386902615016"></a>

`npu-smi info -t ecc-enable -i dev_id`

## Parameters<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section1786919261014"></a>

<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p3985976"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p3985976"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p3985976"></a><strong id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b717422382610"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b717422382610"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b717422382610"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p54428625"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p54428625"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p54428625"></a><strong id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b6175192362611"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b6175192362611"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b6175192362611"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p57396781"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p57396781"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p57396781"></a><span id="ph1713814085117"><a name="ph1713814085117"></a><a name="ph1713814085117"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section6636145619341"></a>

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

## Example<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section66051714132117"></a>

Query the ECC enabling status of device 0.

```bash
npu-smi info -t ecc-enable -i 0
```

```text
        HBM ECC-Enable Status          : True
```

## Output Description<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p564183915134"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p564183915134"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p564183915134"></a>HBM ECC-Enable Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p14967185415284"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p14967185415284"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p14967185415284"></a>ECC enabling status of on-chip memory.</p>
<p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p2967125452816"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p2967125452816"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p2967125452816"></a>The value can be <strong id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b166141251154016"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b166141251154016"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b166141251154016"></a>False</strong> or <strong id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b1622051164012"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b1622051164012"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b1622051164012"></a>True</strong>.</p>
<p id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p19344144124"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p19344144124"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_p19344144124"></a>The default value is <strong id="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b124651536846"><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b124651536846"></a><a name="en-us_topic_0000001264536737_en-us_topic_0000001163757111_b124651536846"></a>True</strong>.</p>
</td>
</tr>
</tbody>
</table>

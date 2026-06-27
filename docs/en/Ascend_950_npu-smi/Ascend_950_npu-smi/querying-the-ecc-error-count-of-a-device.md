# Querying the ECC Error Count of a Device<a name="EN-US_TOPIC_0000002516546729"></a>

## Function<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section18674262006"></a>

This command is used to query the ECC error count of a device.

## Syntax<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section386902615016"></a>

`npu-smi info -t ecc -i dev_id`

## Parameters<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section1786919261014"></a>

<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p3985976"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p3985976"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p3985976"></a><strong id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b151441316152613"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b151441316152613"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b151441316152613"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p54428625"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p54428625"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p54428625"></a><strong id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b18145916132610"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b18145916132610"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_b18145916132610"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p57396781"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p57396781"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p57396781"></a><span id="ph36701517144513"><a name="ph36701517144513"></a><a name="ph36701517144513"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section0558429173410"></a>

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

## Example<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section66051714132117"></a>

Query the ECC error count of device 0.

```bash
npu-smi info -t ecc -i 0
```

```text
        NPU ID                                   : 0
        HBM Single Bit Error Count               : 0
        HBM Double Bit Error Count               : 0
        HBM Single Bit Aggregate Total Err Cnt   : 0
        HBM Double Bit Aggregate Total Err Cnt   : 0
        HBM Single Bit Isolated Pages Count      : 0
        HBM Double Bit Isolated Pages Count      : 0
        HBM Single Bit Next-Isolated Pages Count : 0
        HBM Double Bit Next-Isolated Pages Count : 0
```

## Output Description<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p36441839191318"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p36441839191318"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1164353918134"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1164353918134"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1164353918134"></a><span id="ph8247618124215"><a name="ph8247618124215"></a><a name="ph8247618124215"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row17267164321119"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p42678437116"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p42678437116"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p42678437116"></a>HBM Single Bit Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p95915518282"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p95915518282"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p95915518282"></a>Number of current single-bit errors in on-chip memory.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row1118085717118"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p61804574113"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p61804574113"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p61804574113"></a>HBM Double Bit Error Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1559145102814"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1559145102814"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1559145102814"></a>Number of current double-bit errors in on-chip memory</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row8203189131213"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p8203998121"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p8203998121"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p8203998121"></a>HBM Single Bit Aggregate Total Err Cnt</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p25919582816"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p25919582816"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p25919582816"></a>Total number of single-bit errors in the lifecycle of on-chip memory.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row1383511217128"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1383513215121"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1383513215121"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1383513215121"></a>HBM Double Bit Aggregate Total Err Cnt</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p06020582810"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p06020582810"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p06020582810"></a>Total number of double-bit errors in the lifecycle of on-chip memory.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row1021515377127"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1321553701218"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1321553701218"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p1321553701218"></a>HBM Single Bit Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p16603582820"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p16603582820"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p16603582820"></a>Number of isolated memory pages with single-bit errors in on-chip memory (reserved; output fixed at <strong id="b018119515337"><a name="b018119515337"></a><a name="b018119515337"></a>0</strong>).</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_row13872493121"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p7387194912128"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p7387194912128"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p7387194912128"></a>HBM Double Bit Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p4605511286"><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p4605511286"></a><a name="en-us_topic_0000001220096542_en-us_topic_0000001117437366_p4605511286"></a>Number of isolated memory pages with multi-bit errors in on-chip memory.</p>
</td>
</tr>
<tr id="row1321063011448"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p3244152018370"><a name="p3244152018370"></a><a name="p3244152018370"></a>HBM Single Bit Next-Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p313252173018"><a name="p313252173018"></a><a name="p313252173018"></a>Number of to-be-isolated memory pages with single-bit errors in on-chip memory (reserved; output fixed at <strong id="b5460152143416"><a name="b5460152143416"></a><a name="b5460152143416"></a>0</strong>).</p>
<div class="note" id="note865282320918"><a name="note865282320918"></a><a name="note865282320918"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002484466782_p1967116168326"><a name="en-us_topic_0000002484466782_p1967116168326"></a><a name="en-us_topic_0000002484466782_p1967116168326"></a>The number of memory pages to be isolated is updated to the number of isolated memory pages after the NPU is reset, the system is restarted, the iBMC NMS is powered on or off, or the AC power supply is powered on or off.</p>
</div></div>
</td>
</tr>
<tr id="row18065326443"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p11630122213375"><a name="p11630122213375"></a><a name="p11630122213375"></a>HBM Double Bit Next-Isolated Pages Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p137361436183014"><a name="p137361436183014"></a><a name="p137361436183014"></a>Number of to-be-isolated memory pages with double-bit errors in on-chip memory, ranging from 0 to 64.</p>
<div class="note" id="note147161010452"><a name="note147161010452"></a><a name="note147161010452"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002484466782_p1967116168326_1"><a name="en-us_topic_0000002484466782_p1967116168326_1"></a><a name="en-us_topic_0000002484466782_p1967116168326_1"></a>The number of memory pages to be isolated is updated to the number of isolated memory pages after the NPU is reset, the system is restarted, the iBMC NMS is powered on or off, or the AC power supply is powered on or off.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

> **NOTE:** 
> The maximum statistical values of the number of current single-bit errors in on-chip memory, number of current double-bit errors in on-chip memory, total number of single-bit errors in the lifetime of on-chip memory, and total number of double-bit errors in the lifetime of on-chip memory are all  **4294967295**.

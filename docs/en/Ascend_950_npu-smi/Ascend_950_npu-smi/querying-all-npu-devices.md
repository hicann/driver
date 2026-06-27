# Querying All NPU Devices<a name="EN-US_TOPIC_0000002484306808"></a>

## Function<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section1271426121315"></a>

This command is used to query all NPU devices.

## Syntax<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section663871213445"></a>

`npu-smi info -l`

## Parameters<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section138501410151716"></a>

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

## Example<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section77423984414"></a>

Query information about all NPUs.

```bash
npu-smi info -l
```

```text
Total Count                    : 1

NPU ID                         : 0
Product Name                   : A5 PCIe Card
Serial Number                  : IT23HMDA0502FAA
```

## Output Description<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.2%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.8%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_row16177103510201"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p1517723542014"></a>Total Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p2017714359203"></a>Total number.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"></a><a name="en-us_topic_0000001220416502_en-us_topic_0000001117437344_p125661953134218"></a><span id="ph3100940163916"><a name="ph3100940163916"></a><a name="ph3100940163916"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="row54553634014"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="p1746736134011"><a name="p1746736134011"></a><a name="p1746736134011"></a>Product Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="p174617360404"><a name="p174617360404"></a><a name="p174617360404"></a>Product name.</p>
</td>
</tr>
<tr id="row20851163716407"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="p785153718404"><a name="p785153718404"></a><a name="p785153718404"></a>Serial Number</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="p1985112378401"><a name="p1985112378401"></a><a name="p1985112378401"></a>Product serial number.</p>
</td>
</tr>
</tbody>
</table>

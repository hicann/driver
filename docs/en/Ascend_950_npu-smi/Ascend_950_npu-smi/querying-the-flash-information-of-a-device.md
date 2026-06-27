# Querying the Flash Information of a Device<a name="EN-US_TOPIC_0000002516426721"></a>

## Function<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section18674262006"></a>

This command is used to query the flash information of a device.

## Syntax<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section386902615016"></a>

`npu-smi info -t flash -i dev_id`

## Parameters<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section1786919261014"></a>

<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3985976"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3985976"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3985976"></a><strong id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b11571654102317"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b11571654102317"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b11571654102317"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p54428625"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p54428625"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p54428625"></a><strong id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b91571754152317"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b91571754152317"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_b91571754152317"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p57396781"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p57396781"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p57396781"></a><span id="ph1572612116312"><a name="ph1572612116312"></a><a name="ph1572612116312"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section18957172772017"></a>

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

## Example<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section66051714132117"></a>

Query the flash information of device 0.

```bash
npu-smi info -t flash -i 0
```

```text
        NPU ID                         : 0
        Flash Count                    : 1

        Flash ID                       : 1730504
        Manufacturer ID                : 0xC2
        Capacity(MB)                   : 64
```

## Output Description<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_row163502109375"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1686482783715"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1686482783715"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1686482783715"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14864142719375"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14864142719375"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14864142719375"></a><span id="ph1487975912395"><a name="ph1487975912395"></a><a name="ph1487975912395"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="row22701871583"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p564183915134"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p564183915134"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p564183915134"></a>Flash Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1764083911312"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1764083911312"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p1764083911312"></a>Flash count.</p>
</td>
</tr>
<tr id="row58591317814"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p16392398134"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p16392398134"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p16392398134"></a>Flash ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p15620139171316"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p15620139171316"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p15620139171316"></a>Flash ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14391104415348"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14391104415348"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p14391104415348"></a>Manufacturer ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3391124419346"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3391124419346"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p3391124419346"></a>Manufacturer ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p724764818343"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p724764818343"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p724764818343"></a>Capacity(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p182479482343"><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p182479482343"></a><a name="en-us_topic_0000001220096534_en-us_topic_0000001117597256_p182479482343"></a>Capacity (unit: MB).</p>
</td>
</tr>
</tbody>
</table>

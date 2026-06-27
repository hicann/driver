# Querying Device Statistics<a name="EN-US_TOPIC_0000002516546677"></a>

## Function<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section18674262006"></a>

This command is used to query the statistics of a device.

## Syntax<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section386902615016"></a>

`npu-smi info -t usages -i dev_id`

## Parameters<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section1786919261014"></a>

<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p3985976"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p3985976"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p3985976"></a><strong id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b1081973292520"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b1081973292520"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b1081973292520"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p54428625"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p54428625"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p54428625"></a><strong id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b3821173252518"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b3821173252518"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_b3821173252518"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p57396781"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p57396781"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p57396781"></a><span id="ph167910252328"><a name="ph167910252328"></a><a name="ph167910252328"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section156171734173016"></a>

This command cannot be used to query  **Aicore Usage Rate\(%\)**  and  **Aivector Usage Rate\(%\)**  when profiling is enabled. The return value is  **0**, which is meaningless.

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

## Example<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section66051714132117"></a>

Query the statistics of device 0.

```bash
npu-smi info -t usages -i 0
```

```text
NPU ID                         : 0
DDR Capacity(MB)               : 0
DDR Usage Rate(%)              : 0
DDR Hugepages Total(page)      : 0
DDR Hugepages Usage Rate(%)    : 0
HBM Capacity(MB)               : 131072
HBM Usage Rate(%)              : 3
Aicore Usage Rate(%)           : 0
Aivector Usage Rate(%)         : 0
Aicpu Usage Rate(%)            : 0
Ctrlcpu Usage Rate(%)          : 40
DDR Bandwidth Usage Rate(%)    : 0
HBM Bandwidth Usage Rate(%)    : 3
NPU Utilization(%)             : 0
Aicube Usage Rate(%)           : 0
```

## Output Description<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p36441839191318"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p36441839191318"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1164353918134"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1164353918134"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1164353918134"></a><span id="ph777181617403"><a name="ph777181617403"></a><a name="ph777181617403"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="row1822594611317"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p570311353472"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p570311353472"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p570311353472"></a>DDR Capacity(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p177036357472"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p177036357472"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p177036357472"></a>DDR capacity (unit: MB).</p>
</td>
</tr>
<tr id="row172252046337"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p16751740164717"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p16751740164717"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p16751740164717"></a>DDR Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p575154012474"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p575154012474"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p575154012474"></a>DDR usage.</p>
</td>
</tr>
<tr id="row162218415319"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_p181131711125720"><a name="en-us_topic_0000001220576442_p181131711125720"></a><a name="en-us_topic_0000001220576442_p181131711125720"></a>DDR Hugepages Total(page)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_p151322484517"><a name="en-us_topic_0000001220576442_p151322484517"></a><a name="en-us_topic_0000001220576442_p151322484517"></a>Total number of DDR huge pages. The size of each page is 2048 KB.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_p511381119570"><a name="en-us_topic_0000001220576442_p511381119570"></a><a name="en-us_topic_0000001220576442_p511381119570"></a>DDR Hugepages Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_p013214486512"><a name="en-us_topic_0000001220576442_p013214486512"></a><a name="en-us_topic_0000001220576442_p013214486512"></a>DDR huge page usage.</p>
</td>
</tr>
<tr id="row97616276413"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p46881138134912"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p46881138134912"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p46881138134912"></a>HBM Capacity(MB)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1868813874915"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1868813874915"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1868813874915"></a>On-chip memory capacity.</p>
</td>
</tr>
<tr id="row318411302411"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p11414544144915"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p11414544144915"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p11414544144915"></a>HBM Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1441484419499"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1441484419499"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1441484419499"></a>On-chip memory usage. The system occupies some memory even when no service is running.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row13320924104618"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p113201424194614"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p113201424194614"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p113201424194614"></a>Aicore Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p332022404614"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p332022404614"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p332022404614"></a>AI Core usage.</p>
</td>
</tr>
<tr id="row1147717301486"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p64771330134811"><a name="p64771330134811"></a><a name="p64771330134811"></a>Aivector Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1947753017487"><a name="p1947753017487"></a><a name="p1947753017487"></a>AI Vector usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row111517375461"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p14151037164614"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p14151037164614"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p14151037164614"></a>Aicpu Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1415113374461"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1415113374461"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1415113374461"></a>AICPU usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row13736115518464"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p87361555164620"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p87361555164620"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p87361555164620"></a>Ctrlcpu Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1673665574613"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1673665574613"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1673665574613"></a>Ctrl CPU usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row18551195874714"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p355285814479"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p355285814479"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p355285814479"></a>DDR Bandwidth Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p2552175824720"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p2552175824720"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p2552175824720"></a>DDR bandwidth usage.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_row77881148104811"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p10789848144812"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p10789848144812"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p10789848144812"></a>HBM Bandwidth Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1078944810482"><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1078944810482"></a><a name="en-us_topic_0000001220576442_en-us_topic_0000001117437352_p1078944810482"></a>On-chip memory bandwidth usage.</p>
</td>
</tr>
<tr id="row767393364610"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p5673333104616"><a name="p5673333104616"></a><a name="p5673333104616"></a>NPU Utilization(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p56736333465"><a name="p56736333465"></a><a name="p56736333465"></a>Comprehensive NPU utilization.</p>
</td>
</tr>
<tr id="row13787950605"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p11195125615147"><a name="p11195125615147"></a><a name="p11195125615147"></a>Aicube Usage Rate(%)</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1158366181420"><a name="p1158366181420"></a><a name="p1158366181420"></a>AI Cube usage.</p>
</td>
</tr>
</tbody>
</table>

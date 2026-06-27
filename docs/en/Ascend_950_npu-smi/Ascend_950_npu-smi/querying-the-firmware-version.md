# Querying the Firmware Version<a name="EN-US_TOPIC_0000002484306758"></a>

## Function<a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_section18674262006"></a>

This command is used to query the firmware version.

## Syntax<a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_section386902615016"></a>

`npu-smi upgrade -b item -i dev_id`

## Parameters<a name="en-us_topic_0000001264536713_en-us_topic_0000001117597260_section1786919261014"></a>

<a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_row57216019"><th class="cellrowborder" valign="top" width="29.970000000000002%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p3985976"><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p3985976"></a><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p3985976"></a><strong id="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b18750288247"><a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b18750288247"></a><a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b18750288247"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70.03%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p54428625"><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p54428625"></a><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p54428625"></a><strong id="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b08761128192420"><a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b08761128192420"></a><a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_b08761128192420"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_row20095581"><td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p57396781"><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p57396781"></a><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p57396781"></a><span id="ph16928162994212"><a name="ph16928162994212"></a><a name="ph16928162994212"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70.03%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
<tr id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_row201038418178"><td class="cellrowborder" valign="top" width="29.970000000000002%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p81048471715"><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p81048471715"></a><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_p81048471715"></a><em id="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_i73221932164217"><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_i73221932164217"></a><a name="en-us_topic_0000001263142362_en-us_topic_0000001220416490_en-us_topic_0000001117437360_i73221932164217"></a>item</em></p>
</td>
<td class="cellrowborder" valign="top" width="70.03%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001263142362_p4431350161216"><a name="en-us_topic_0000001263142362_p4431350161216"></a><a name="en-us_topic_0000001263142362_p4431350161216"></a>Firmware type: <strong id="b8256958562"><a name="b8256958562"></a><a name="b8256958562"></a>vrd</strong> or <strong id="b15660758182817"><a name="b15660758182817"></a><a name="b15660758182817"></a>vdm</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_section195931822154916"></a>

This command can be used to query only the VRD firmware version.

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

## Example<a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_section66051714132117"></a>

Query the VRD firmware version on device 0.

```bash
npu-smi upgrade -b vrd -i 0
```

```text
VRD Count                      : 6
VRD Name                       : AIC_D0
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255

VRD Name                       : BUS_D0
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255

VRD Name                       : 1V2PFM
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255

VRD Name                       : AIC_D1
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255

VRD Name                       : BUS_D1
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255

VRD Name                       : 0V5PFM
Current Version                : 4
Target Version                 : 4
Remaining Upgrade Count        : 255
```

Query the VDM firmware version on device 0.

```bash
npu-smi upgrade -b vdm -i 0
```

```text
This device does not support querying version.
```

## Output Description<a name="en-us_topic_0000001220416518_en-us_topic_0000001163797115_section29761716101314"></a>

**Table  2**  Description of the displayed information \(VRD firmware version\)

<a name="table8166927172113"></a>
<table><thead align="left"><tr id="row121661527122110"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="p1716642716218"><a name="p1716642716218"></a><a name="p1716642716218"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="p1316652714216"><a name="p1316652714216"></a><a name="p1316652714216"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1316692710212"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p12166112712120"><a name="p12166112712120"></a><a name="p12166112712120"></a>VRD Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p20166142712111"><a name="p20166142712111"></a><a name="p20166142712111"></a>Count of VRD firmware.</p>
</td>
</tr>
<tr id="row1727919272210"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p202793220226"><a name="p202793220226"></a><a name="p202793220226"></a>VRD Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p22797216226"><a name="p22797216226"></a><a name="p22797216226"></a>VRD firmware name.</p>
</td>
</tr>
<tr id="row63123260227"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p19312626172210"><a name="p19312626172210"></a><a name="p19312626172210"></a>Current Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p153121426172215"><a name="p153121426172215"></a><a name="p153121426172215"></a>VRD firmware version in use.</p>
</td>
</tr>
<tr id="row6310143282219"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p16310123211222"><a name="p16310123211222"></a><a name="p16310123211222"></a>Target Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1331019326222"><a name="p1331019326222"></a><a name="p1331019326222"></a>Version of the VRD firmware to be upgraded.</p>
</td>
</tr>
<tr id="row2310232152215"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p6310732112211"><a name="p6310732112211"></a><a name="p6310732112211"></a>Remaining Upgrade Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1631183242212"><a name="p1631183242212"></a><a name="p1631183242212"></a>Number of remaining VRD firmware upgrades.</p>
</td>
</tr>
</tbody>
</table>

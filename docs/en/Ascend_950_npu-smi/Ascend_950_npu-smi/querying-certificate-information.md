# Querying Certificate Information<a name="EN-US_TOPIC_0000002516546695"></a>

## Function<a name="en-us_topic_0000001897499160_section03121288234"></a>

This command is used to query certificate information.

## Syntax<a name="en-us_topic_0000001897499160_section1631319284238"></a>

`npu-smi info -t tls-cert -i dev_id`

## Parameters<a name="en-us_topic_0000001897499160_section9313132813234"></a>

<a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><a name="en-us_topic_0000001897499160_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><em id="i163116412284"><a name="i163116412284"></a><a name="i163116412284"></a><span id="ph86311419283"><a name="ph86311419283"></a><a name="ph86311419283"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001897499160_section9323328162312"></a>

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

## Example<a name="en-us_topic_0000001897499160_section2390162812310"></a>

Query the certificate information of device 0.

```bash
npu-smi info -t tls-cert -i 0
```

```text
Alarm status                   : 0
Start time                     : Fri Aug  1 12:09:19 2025
End time                       : Mon Jul 30 12:09:19 2035
Common name                    : CC2CF66480E095F3116BC392A67A7B05144301E3
```

## Output Description<a name="en-us_topic_0000001897499160_section63931428102318"></a>

**Table  2**  Description of the displayed information

<a name="table7431132817231"></a>
<table><thead align="left"><tr id="row165641028112318"><th class="cellrowborder" valign="top" width="49.49%" id="mcps1.2.3.1.1"><p id="p14564172816230"><a name="p14564172816230"></a><a name="p14564172816230"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.2.3.1.2"><p id="p7564132816231"><a name="p7564132816231"></a><a name="p7564132816231"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row756513284233"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p8565728192317"><a name="p8565728192317"></a><a name="p8565728192317"></a>Alarm status</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p4565128152311"><a name="p4565128152311"></a><a name="p4565128152311"></a>Certificate expiration status.</p>
<a name="ul020184215388"></a><a name="ul020184215388"></a><ul id="ul020184215388"><li><strong id="b20973134116411"><a name="b20973134116411"></a><a name="b20973134116411"></a>0</strong>: The certificate has not expired.</li><li><strong id="b3590646745"><a name="b3590646745"></a><a name="b3590646745"></a>1</strong>: The certificate is about to expire.</li><li><strong id="b1665611501448"><a name="b1665611501448"></a><a name="b1665611501448"></a>2</strong>: The certificate has expired.</li><li><strong id="b1983917532043"><a name="b1983917532043"></a><a name="b1983917532043"></a>3</strong>: The certificate is unavailable within the validity period.</li></ul>
</td>
</tr>
<tr id="row105981020154018"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p165981220144014"><a name="p165981220144014"></a><a name="p165981220144014"></a>Start time</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p105980208406"><a name="p105980208406"></a><a name="p105980208406"></a>Time when the certificate takes effect.</p>
</td>
</tr>
<tr id="row96483237405"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p8648123194015"><a name="p8648123194015"></a><a name="p8648123194015"></a>End time</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p13648122317409"><a name="p13648122317409"></a><a name="p13648122317409"></a>Time when the certificate expires.</p>
</td>
</tr>
<tr id="row8565728172314"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p18771553154116"><a name="p18771553154116"></a><a name="p18771553154116"></a>Common name</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p105651428172315"><a name="p105651428172315"></a><a name="p105651428172315"></a>Certificate name.</p>
</td>
</tr>
</tbody>
</table>

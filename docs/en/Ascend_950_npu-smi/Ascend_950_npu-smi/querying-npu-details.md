# Querying NPU Details<a name="EN-US_TOPIC_0000002484466710"></a>

## Function<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section290216321716"></a>

This command is used to query NPU details.

## Syntax<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section93081519505"></a>

`npu-smi info -t board -i dev_id`

## Parameters<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section52928161114"></a>

<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3985976"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3985976"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3985976"></a><strong id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b333539175111"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b333539175111"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b333539175111"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p54428625"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p54428625"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p54428625"></a><strong id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b233559105116"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b233559105116"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_b233559105116"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p57396781"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p57396781"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p57396781"></a><span id="ph1722812471217"><a name="ph1722812471217"></a><a name="ph1722812471217"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="ph861524220464"><a name="ph861524220464"></a><a name="ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="b208978812147"><a name="b208978812147"></a><a name="b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section1259814597188"></a>

Before querying the compatibility, ensure that the installation and upgrade of the NPU firmware and driver have taken effect.

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

## Example<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section18574571449"></a>

Query the details about device 0.

```bash
npu-smi info -t board -i 0
```

```text
              NPU ID                         : 0
              Product Name                   : xxx
              NPU Name                       : xxx
              Chip Name                      : xxx
              Chip Version                   : xxx
              Model                          : xxx
              Manufacturer                   : xxx
              Serial Number                  : xxx
              Software Version               : xxx
              Firmware Version               : xxx
              Compatibility                  : OK
              Board ID                       : 0x1b
              Main Board ID                  : 0x68(1P)
              PCB ID                         : A
              BOM ID                         : 1
              PCIe Bus Info                  : 0000:F1:00.0
              Slot ID                        : 0
              Class ID                       : NA
              PCI Vendor ID                  : 0x19E5
              PCI Device ID                  : 0xD806
              Subsystem Vendor ID            : 0x19E5
              Subsystem Device ID            : 0x4004
              Chip Count                     : 1
              DDie ID                        : 870408E3 2120D518 77936EE6 80B40A0A D4100003
              Chip Position ID               : 0
```

> **NOTE:** 
> 
> _xxx_  is subject to the actual query result.

## Output Description<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p36441839191318"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p36441839191318"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1164353918134"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1164353918134"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1164353918134"></a><span id="ph1893642103915"><a name="ph1893642103915"></a><a name="ph1893642103915"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="row44321116105514"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p12432111695513"><a name="p12432111695513"></a><a name="p12432111695513"></a>Product Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8642123913138"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8642123913138"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8642123913138"></a>Product name.</p>
</td>
</tr>
<tr id="row05871459195915"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p2058825995913"><a name="p2058825995913"></a><a name="p2058825995913"></a>NPU Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1558811596590"><a name="p1558811596590"></a><a name="p1558811596590"></a>Device name.</p>
</td>
</tr>
<tr id="row2101430109"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p171011430804"><a name="p171011430804"></a><a name="p171011430804"></a>Chip Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p21016301600"><a name="p21016301600"></a><a name="p21016301600"></a>Chip name.</p>
</td>
</tr>
<tr id="row94105411011"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p6410194114017"><a name="p6410194114017"></a><a name="p6410194114017"></a>Chip Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1341015411508"><a name="p1341015411508"></a><a name="p1341015411508"></a>Chip version.</p>
</td>
</tr>
<tr id="row11178239175510"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p17178193913554"><a name="p17178193913554"></a><a name="p17178193913554"></a>Model</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p127371954183210"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p127371954183210"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p127371954183210"></a>Product model.</p>
</td>
</tr>
<tr id="row1426204985517"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p13262449145511"><a name="p13262449145511"></a><a name="p13262449145511"></a>Manufacturer</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p15620139171316"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p15620139171316"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p15620139171316"></a>Vendor.</p>
</td>
</tr>
<tr id="row044017018565"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p54401502562"><a name="p54401502562"></a><a name="p54401502562"></a>Serial Number</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105132618"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105132618"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105132618"></a>Product serial number.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row791635132614"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p491635117265"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p491635117265"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p491635117265"></a>Software Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3916155115264"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3916155115264"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p3916155115264"></a>NPU driver version.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row49161951142612"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p14916135114265"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p14916135114265"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p14916135114265"></a>Firmware Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105172620"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105172620"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p8916105172620"></a>NPU firmware version.</p>
<div class="note" id="note141772118231"><a name="note141772118231"></a><a name="note141772118231"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p11177111122311"><a name="p11177111122311"></a><a name="p11177111122311"></a>If you query the NPU firmware version as a non-root user, <strong id="b1894836133015"><a name="b1894836133015"></a><a name="b1894836133015"></a>NA</strong> is displayed in the query result.</p>
</div></div>
</td>
</tr>
<tr id="row2799153764311"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p379983774312"><a name="p379983774312"></a><a name="p379983774312"></a>Compatibility</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p350341320354"><a name="p350341320354"></a><a name="p350341320354"></a>Compatibility between the NPU driver and NPU firmware. The options are as follows:</p>
<a name="ul15825917154512"></a><a name="ul15825917154512"></a><ul id="ul15825917154512"><li><strong id="b98811755145318"><a name="b98811755145318"></a><a name="b98811755145318"></a>OK</strong>: The driver and firmware are compatible.</li><li><strong id="b9251159155320"><a name="b9251159155320"></a><a name="b9251159155320"></a>NOK</strong>: The driver is incompatible with the firmware.</li><li><strong id="b13116115105410"><a name="b13116115105410"></a><a name="b13116115105410"></a>UNKNOWN</strong>: The mapping between the driver and firmware is unknown.</li><li><strong id="b1062364275419"><a name="b1062364275419"></a><a name="b1062364275419"></a>NOT SUPPORT</strong>: The compatibility between the driver and firmware cannot be queried.<div class="note" id="note966518283236"><a name="note966518283236"></a><a name="note966518283236"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p1166562852315"><a name="p1166562852315"></a><a name="p1166562852315"></a>When a non-root user queries the compatibility between the driver and firmware, the query result is <strong id="b144661445143018"><a name="b144661445143018"></a><a name="b144661445143018"></a>NOT SUPPORT</strong>.</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row1820416108585"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p5916175182616"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p5916175182616"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p5916175182616"></a>Board ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p109010202342"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p109010202342"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p109010202342"></a>Board ID.</p>
</td>
</tr>
<tr id="row1894050181018"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p1346003218118"><a name="p1346003218118"></a><a name="p1346003218118"></a>Main Board ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p13958507104"><a name="p13958507104"></a><a name="p13958507104"></a>Mainboard ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row69651918192714"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p209651618132713"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p209651618132713"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p209651618132713"></a>PCB ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965141819273"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965141819273"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965141819273"></a>PCB ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row119652183271"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1726152442820"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1726152442820"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1726152442820"></a>BOM ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965718132711"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965718132711"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18965718132711"></a>BOM ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row19965118112712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p189651018182713"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p189651018182713"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p189651018182713"></a>PCIe Bus Info</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p2965141832710"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p2965141832710"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p2965141832710"></a>PCIe bus information.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row114731921113"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18871915131111"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18871915131111"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p18871915131111"></a>Slot ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p7562181931116"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p7562181931116"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p7562181931116"></a>Slot ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row1965191872714"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196591814278"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196591814278"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196591814278"></a>Class ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396561812276"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396561812276"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396561812276"></a>Class ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row19965111814278"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p19965111802719"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p19965111802719"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p19965111802719"></a>PCI Vendor ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p896641811272"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p896641811272"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p896641811272"></a>PCI vendor ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row7966191811274"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396611188274"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396611188274"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p396611188274"></a>PCI Device ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p10622225183519"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p10622225183519"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p10622225183519"></a>PCI device ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row6966018182710"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196671812270"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196671812270"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p196671812270"></a>Subsystem Vendor ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1375993473513"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1375993473513"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1375993473513"></a>Subsystem vendor ID.</p>
</td>
</tr>
<tr id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_row1747312386326"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1947310381323"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1947310381323"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1947310381323"></a>Subsystem Device ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1747314389329"><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1747314389329"></a><a name="en-us_topic_0000001264656677_en-us_topic_0000001163797135_p1747314389329"></a>Subsystem device ID.</p>
</td>
</tr>
<tr id="row15599134075618"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p659918402564"><a name="p659918402564"></a><a name="p659918402564"></a>Chip Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1959994015610"><a name="p1959994015610"></a><a name="p1959994015610"></a>Number of chips.</p>
</td>
</tr>
<tr id="row23035161620"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p230314161422"><a name="p230314161422"></a><a name="p230314161422"></a>DDie ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p113693110411"><a name="p113693110411"></a><a name="p113693110411"></a>Chip DDie ID.</p>
</td>
</tr>
<tr id="row1413743116216"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p16137103119212"><a name="p16137103119212"></a><a name="p16137103119212"></a>Chip Position ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p141378312022"><a name="p141378312022"></a><a name="p141378312022"></a>Chip position ID.</p>
</td>
</tr>
</tbody>
</table>

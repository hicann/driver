# 查询NPU的详细信息<a name="ZH-CN_TOPIC_0000002613572411"></a>

## 功能说明<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section290216321716"></a>

用于查询NPU的详细信息。

## 命令格式<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section93081519505"></a>

`npu-smi info -t board -i dev_id`

## 参数说明<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section52928161114"></a>

<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_table7208814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3985976"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3985976"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3985976"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p54428625"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p54428625"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p54428625"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p57396781"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p57396781"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p57396781"></a><span id="ph1722812471217"><a name="ph1722812471217"></a><a name="ph1722812471217"></a><em id="zh-cn_topic_0000002552580505_i177511300519_2"><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a><a name="zh-cn_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p45299595"></a><span id="ph861524220464"><a name="ph861524220464"></a><a name="ph861524220464"></a>软件的逻辑ID</span>。通过执行<strong id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0159185044_b380865519132"></a>npu-smi info -l</strong>命令获取的NPU ID即为软件的逻辑ID。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section1259814597188"></a>

查询Compatibility前NPU固件和NPU驱动的安装、升级必须生效。

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p44201360411"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p75637171408"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p5649445717"><a name="zh-cn_topic_0000002583332642_p5649445717"></a><a name="zh-cn_topic_0000002583332642_p5649445717"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p12563111734020"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564317134011"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p15564417174012"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p14564617114019"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p116412411579"><a name="zh-cn_topic_0000002583332642_p116412411579"></a><a name="zh-cn_topic_0000002583332642_p116412411579"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7564117174014"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p356491714408"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_row185641517124016"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p144147361596"><a name="zh-cn_topic_0000002583332642_p144147361596"></a><a name="zh-cn_topic_0000002583332642_p144147361596"></a><span id="zh-cn_topic_0000002583332642_ph12140626193614"><a name="zh-cn_topic_0000002583332642_ph12140626193614"></a><a name="zh-cn_topic_0000002583332642_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p256471710404"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p45656172402"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_p125931265317"><a name="zh-cn_topic_0000002583332642_p125931265317"></a><a name="zh-cn_topic_0000002583332642_p125931265317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"></a><a name="zh-cn_topic_0000002583332642_zh-cn_topic_0000002027614521_p7566161714013"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_p158021256175710"><a name="zh-cn_topic_0000002583332642_p158021256175710"></a><a name="zh-cn_topic_0000002583332642_p158021256175710"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row651184316559"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p2194113775312"><a name="zh-cn_topic_0000002583332642_p2194113775312"></a><a name="zh-cn_topic_0000002583332642_p2194113775312"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section18574571449"></a>

查询设备0的具体信息。

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

> **说明：** 
> 
> _xxx_请以实际查询的回显信息为准。

## 输出说明<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p36441839191318"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p36441839191318"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1164353918134"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1164353918134"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1164353918134"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row44321116105514"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p12432111695513"><a name="p12432111695513"></a><a name="p12432111695513"></a>Product Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8642123913138"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8642123913138"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8642123913138"></a>产品名称。</p>
</td>
</tr>
<tr id="row05871459195915"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p2058825995913"><a name="p2058825995913"></a><a name="p2058825995913"></a>NPU Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1558811596590"><a name="p1558811596590"></a><a name="p1558811596590"></a>设备名称。</p>
</td>
</tr>
<tr id="row2101430109"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p171011430804"><a name="p171011430804"></a><a name="p171011430804"></a>Chip Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p21016301600"><a name="p21016301600"></a><a name="p21016301600"></a>芯片名称。</p>
</td>
</tr>
<tr id="row94105411011"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p6410194114017"><a name="p6410194114017"></a><a name="p6410194114017"></a>Chip Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1341015411508"><a name="p1341015411508"></a><a name="p1341015411508"></a>芯片版本。</p>
</td>
</tr>
<tr id="row11178239175510"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p17178193913554"><a name="p17178193913554"></a><a name="p17178193913554"></a>Model</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p127371954183210"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p127371954183210"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p127371954183210"></a>产品型号。</p>
</td>
</tr>
<tr id="row1426204985517"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p13262449145511"><a name="p13262449145511"></a><a name="p13262449145511"></a>Manufacturer</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p15620139171316"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p15620139171316"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p15620139171316"></a>生产厂家。</p>
</td>
</tr>
<tr id="row044017018565"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p54401502562"><a name="p54401502562"></a><a name="p54401502562"></a>Serial Number</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105132618"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105132618"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105132618"></a>产品序列号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row791635132614"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p491635117265"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p491635117265"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p491635117265"></a>Software Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3916155115264"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3916155115264"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p3916155115264"></a>NPU驱动版本。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row49161951142612"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p14916135114265"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p14916135114265"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p14916135114265"></a>Firmware Version</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105172620"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105172620"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p8916105172620"></a>NPU固件版本。</p>
<div class="note" id="note141772118231"><a name="note141772118231"></a><a name="note141772118231"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p11177111122311"><a name="p11177111122311"></a><a name="p11177111122311"></a>非root用户查询NPU固件版本，查询结果为NA。</p>
</div></div>
</td>
</tr>
<tr id="row2799153764311"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p379983774312"><a name="p379983774312"></a><a name="p379983774312"></a>Compatibility</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p350341320354"><a name="p350341320354"></a><a name="p350341320354"></a>NPU驱动和NPU固件兼容性。</p>
<a name="ul15825917154512"></a><a name="ul15825917154512"></a><ul id="ul15825917154512"><li>OK：驱动和固件兼容。</li><li>NOK：驱动和固件不兼容。</li><li>UNKNOWN：驱动和固件配套关系未知。</li><li>NOT SUPPORT：不支持查询驱动和固件兼容关系。<div class="note" id="note966518283236"><a name="note966518283236"></a><a name="note966518283236"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p1166562852315"><a name="p1166562852315"></a><a name="p1166562852315"></a>非root用户查询驱动和固件兼容关系，查询结果为NOT SUPPORT。</p>
</div></div>
</li></ul>
</td>
</tr>
<tr id="row1820416108585"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p5916175182616"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p5916175182616"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p5916175182616"></a>Board ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p109010202342"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p109010202342"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p109010202342"></a>单板ID。</p>
</td>
</tr>
<tr id="row1894050181018"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p1346003218118"><a name="p1346003218118"></a><a name="p1346003218118"></a>Main Board ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p13958507104"><a name="p13958507104"></a><a name="p13958507104"></a>主板ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row69651918192714"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p209651618132713"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p209651618132713"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p209651618132713"></a>PCB ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965141819273"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965141819273"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965141819273"></a>PCB版本编号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row119652183271"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1726152442820"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1726152442820"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1726152442820"></a>BOM ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965718132711"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965718132711"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18965718132711"></a>BOM版本编号。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row19965118112712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p189651018182713"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p189651018182713"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p189651018182713"></a>PCIe Bus Info</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p2965141832710"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p2965141832710"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p2965141832710"></a>PCIe总线信息。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row114731921113"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18871915131111"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18871915131111"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p18871915131111"></a>Slot ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p7562181931116"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p7562181931116"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p7562181931116"></a>槽位ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row1965191872714"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196591814278"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196591814278"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196591814278"></a>Class ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396561812276"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396561812276"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396561812276"></a>类型ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row19965111814278"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p19965111802719"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p19965111802719"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p19965111802719"></a>PCI Vendor ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p896641811272"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p896641811272"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p896641811272"></a>PCI制造商ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row7966191811274"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396611188274"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396611188274"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p396611188274"></a>PCI Device ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p10622225183519"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p10622225183519"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p10622225183519"></a>PCI设备ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row6966018182710"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196671812270"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196671812270"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p196671812270"></a>Subsystem Vendor ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1375993473513"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1375993473513"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1375993473513"></a>子系统制造商ID。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_row1747312386326"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1947310381323"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1947310381323"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1947310381323"></a>Subsystem Device ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1747314389329"><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1747314389329"></a><a name="zh-cn_topic_0000001264656677_zh-cn_topic_0000001163797135_p1747314389329"></a>子系统设备ID。</p>
</td>
</tr>
<tr id="row15599134075618"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p659918402564"><a name="p659918402564"></a><a name="p659918402564"></a>Chip Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1959994015610"><a name="p1959994015610"></a><a name="p1959994015610"></a>芯片个数。</p>
</td>
</tr>
<tr id="row23035161620"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p230314161422"><a name="p230314161422"></a><a name="p230314161422"></a>DDie ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p113693110411"><a name="p113693110411"></a><a name="p113693110411"></a>芯片DDie编号。</p>
</td>
</tr>
<tr id="row1413743116216"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p16137103119212"><a name="p16137103119212"></a><a name="p16137103119212"></a>Chip Position ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p141378312022"><a name="p141378312022"></a><a name="p141378312022"></a>芯片位置ID。</p>
</td>
</tr>
</tbody>
</table>

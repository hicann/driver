# 查询所有NPU设备<a name="ZH-CN_TOPIC_0000002583332530"></a>

## 功能说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section1271426121315"></a>

用于查询所有NPU设备。

## 命令格式<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section663871213445"></a>

`npu-smi info -l`

## 参数说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section52928161114"></a>

无

## 使用指南<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section138501410151716"></a>

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

## 使用示例<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section77423984414"></a>

查询所有NPU设备的相关信息。

```bash
npu-smi info -l
```

```text
 Total Count                    : 1

 NPU ID                         : 0
 Product Name                   : A5 PCIe Card
 Serial Number                  : IT23HMDA0502FAA
```

## 输出说明<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.2%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.8%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_row16177103510201"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p1517723542014"></a>Total Count</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p2017714359203"></a>总个数。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p36441839191318"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"></a><a name="zh-cn_topic_0000001220416502_zh-cn_topic_0000001117437344_p125661953134218"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row54553634014"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="p1746736134011"><a name="p1746736134011"></a><a name="p1746736134011"></a>Product Name</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="p174617360404"><a name="p174617360404"></a><a name="p174617360404"></a>产品名称。</p>
</td>
</tr>
<tr id="row20851163716407"><td class="cellrowborder" valign="top" width="49.2%" headers="mcps1.2.3.1.1 "><p id="p785153718404"><a name="p785153718404"></a><a name="p785153718404"></a>Serial Number</p>
</td>
<td class="cellrowborder" valign="top" width="50.8%" headers="mcps1.2.3.1.2 "><p id="p1985112378401"><a name="p1985112378401"></a><a name="p1985112378401"></a>产品序列号。</p>
</td>
</tr>
</tbody>
</table>

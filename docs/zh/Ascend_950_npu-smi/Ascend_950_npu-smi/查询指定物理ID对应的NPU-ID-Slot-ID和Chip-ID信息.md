# 查询指定物理ID对应的NPU ID、Slot ID和Chip ID信息<a name="ZH-CN_TOPIC_0000002583332618"></a>

## 功能说明<a name="section4993335112514"></a>

查询指定物理ID对应的NPU ID、Slot ID和Chip ID信息。

## 命令格式<a name="section759322702811"></a>

`npu-smi info -t phyid-remap -p phy_id`

## 参数说明<a name="section18320204772813"></a>

**表 1**  参数说明

<a name="zh-cn_topic_0000001220416514_table398495753919"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220416514_row698465718393"><th class="cellrowborder" valign="top" width="30%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220416514_p09847577395"><a name="zh-cn_topic_0000001220416514_p09847577395"></a><a name="zh-cn_topic_0000001220416514_p09847577395"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220416514_p109842057103914"><a name="zh-cn_topic_0000001220416514_p109842057103914"></a><a name="zh-cn_topic_0000001220416514_p109842057103914"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220416514_row198415578393"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416514_p139842577392"><a name="zh-cn_topic_0000001220416514_p139842577392"></a><a name="zh-cn_topic_0000001220416514_p139842577392"></a><em id="i5109718131414"><a name="i5109718131414"></a><a name="i5109718131414"></a>phy_<em id="i06513945016"><a name="i06513945016"></a><a name="i06513945016"></a>id</em></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.2.3.1.2 "><p id="p731012179496"><a name="p731012179496"></a><a name="p731012179496"></a>芯片物理ID。通过<strong id="zh-cn_topic_0000001264416741_zh-cn_topic_0000001163757109_b16290101475212"><a name="zh-cn_topic_0000001264416741_zh-cn_topic_0000001163757109_b16290101475212"></a><a name="zh-cn_topic_0000001264416741_zh-cn_topic_0000001163757109_b16290101475212"></a>npu-smi info -m</strong>命令查询到的Chip Phy-ID即为芯片物理ID。</p>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="section2090294919299"></a>

**表 2** 不同部署场景下的支持情况

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

## 使用示例<a name="section3374141544210"></a>

根据芯片物理ID为0，查询对应的NPU ID、Slot ID和Chip ID信息。

```bash
npu-smi info -t phyid-remap -p 0
```

```text
Chip Phy-ID                   :0
NPU ID                        :0
Slot ID                       :0
Chip ID                       :0
```

## 输出说明<a name="section437545011483"></a>

**表 3**  打印信息说明

<a name="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001163797119_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p2094234510522"><a name="p2094234510522"></a><a name="p2094234510522"></a>Chip Phy-ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p13942134511525"><a name="p13942134511525"></a><a name="p13942134511525"></a>芯片物理ID。</p>
</td>
</tr>
<tr id="row344081631117"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p149421545115216"><a name="p149421545115216"></a><a name="p149421545115216"></a>NPU ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1394204545213"><a name="p1394204545213"></a><a name="p1394204545213"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row14606175310153"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p7607953111515"><a name="p7607953111515"></a><a name="p7607953111515"></a>Slot ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p560745312151"><a name="p560745312151"></a><a name="p560745312151"></a>槽位ID。</p>
</td>
</tr>
<tr id="row1767152081112"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="p894215452528"><a name="p894215452528"></a><a name="p894215452528"></a>Chip ID</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="p1894214585210"><a name="p1894214585210"></a><a name="p1894214585210"></a>芯片ID。</p>
</td>
</tr>
</tbody>
</table>

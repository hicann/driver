# 恢复NPU设备的配置<a name="ZH-CN_TOPIC_0000002584611362"></a>

## 产品支持情况<a name="section5790730141118"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row14269102720616"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p172695271467"><a name="zh-cn_topic_0000002614931227_p172695271467"></a><a name="zh-cn_topic_0000002614931227_p172695271467"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p52691927763"><a name="zh-cn_topic_0000002614931227_p52691927763"></a><a name="zh-cn_topic_0000002614931227_p52691927763"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p42695271962"><a name="zh-cn_topic_0000002614931227_p42695271962"></a><a name="zh-cn_topic_0000002614931227_p42695271962"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p17269227665"><a name="zh-cn_topic_0000002614931227_p17269227665"></a><a name="zh-cn_topic_0000002614931227_p17269227665"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p182691427865"><a name="zh-cn_topic_0000002614931227_p182691427865"></a><a name="zh-cn_topic_0000002614931227_p182691427865"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p132695278611"><a name="zh-cn_topic_0000002614931227_p132695278611"></a><a name="zh-cn_topic_0000002614931227_p132695278611"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row42691727369"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p72697275618"><a name="zh-cn_topic_0000002614931227_p72697275618"></a><a name="zh-cn_topic_0000002614931227_p72697275618"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p826942711620"><a name="zh-cn_topic_0000002614931227_p826942711620"></a><a name="zh-cn_topic_0000002614931227_p826942711620"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p1126912271564"><a name="zh-cn_topic_0000002614931227_p1126912271564"></a><a name="zh-cn_topic_0000002614931227_p1126912271564"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p122691627568"><a name="zh-cn_topic_0000002614931227_p122691627568"></a><a name="zh-cn_topic_0000002614931227_p122691627568"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p1326917271617"><a name="zh-cn_topic_0000002614931227_p1326917271617"></a><a name="zh-cn_topic_0000002614931227_p1326917271617"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p192691827266"><a name="zh-cn_topic_0000002614931227_p192691827266"></a><a name="zh-cn_topic_0000002614931227_p192691827266"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row32690271462"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p1326922714616"><a name="zh-cn_topic_0000002614931227_p1326922714616"></a><a name="zh-cn_topic_0000002614931227_p1326922714616"></a><span id="zh-cn_topic_0000002614931227_ph026915273616"><a name="zh-cn_topic_0000002614931227_ph026915273616"></a><a name="zh-cn_topic_0000002614931227_ph026915273616"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p1726915271965"><a name="zh-cn_topic_0000002614931227_p1726915271965"></a><a name="zh-cn_topic_0000002614931227_p1726915271965"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.262857142857142%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p162697275617"><a name="zh-cn_topic_0000002614931227_p162697275617"></a><a name="zh-cn_topic_0000002614931227_p162697275617"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.30857142857143%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p1626910276617"><a name="zh-cn_topic_0000002614931227_p1626910276617"></a><a name="zh-cn_topic_0000002614931227_p1626910276617"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p1934621384210"><a name="zh-cn_topic_0000002614931227_p1934621384210"></a><a name="zh-cn_topic_0000002614931227_p1934621384210"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p43651251954"><a name="zh-cn_topic_0000002614931227_p43651251954"></a><a name="zh-cn_topic_0000002614931227_p43651251954"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p166972422119"><a name="zh-cn_topic_0000002614931227_p166972422119"></a><a name="zh-cn_topic_0000002614931227_p166972422119"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row1327082715616"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p202701127863"><a name="zh-cn_topic_0000002614931227_p202701127863"></a><a name="zh-cn_topic_0000002614931227_p202701127863"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section957615561617"></a>

恢复NPU设备的配置。

## 注意事项<a name="section8415102071"></a>

支持持久化命令中的注意事项都需关注。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -s -cfg_recovery -i <dev_id>
```

## 参数说明<a name="section107781620873"></a>

<a name="table77595370346"></a>
<table><thead align="left"><tr id="row2760173716343"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="p9760737153418"><a name="p9760737153418"></a><a name="p9760737153418"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p1076023711348"><a name="p1076023711348"></a><a name="p1076023711348"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="p37601437113413"><a name="p37601437113413"></a><a name="p37601437113413"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row47601373342"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p676003763413"><a name="p676003763413"></a><a name="p676003763413"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

```bash
hccn_tool -s -cfg_recovery -i 0
```

恢复单一NPU设备的配置。

```text
Cmd executed successfully!
```

## 输出说明<a name="section1726420371679"></a>

无。

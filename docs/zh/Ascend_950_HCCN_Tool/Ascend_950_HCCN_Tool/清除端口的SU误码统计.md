# 清除端口的SU误码统计<a name="ZH-CN_TOPIC_0000002584611348"></a>

## 产品支持情况<a name="section5790730141118"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row1659565515239"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p14595855152313"><a name="zh-cn_topic_0000002614931227_p14595855152313"></a><a name="zh-cn_topic_0000002614931227_p14595855152313"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p5595655142320"><a name="zh-cn_topic_0000002614931227_p5595655142320"></a><a name="zh-cn_topic_0000002614931227_p5595655142320"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p1059518557238"><a name="zh-cn_topic_0000002614931227_p1059518557238"></a><a name="zh-cn_topic_0000002614931227_p1059518557238"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p759525511230"><a name="zh-cn_topic_0000002614931227_p759525511230"></a><a name="zh-cn_topic_0000002614931227_p759525511230"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p1559511555239"><a name="zh-cn_topic_0000002614931227_p1559511555239"></a><a name="zh-cn_topic_0000002614931227_p1559511555239"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p1659575592318"><a name="zh-cn_topic_0000002614931227_p1659575592318"></a><a name="zh-cn_topic_0000002614931227_p1659575592318"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row45951557231"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p959595516230"><a name="zh-cn_topic_0000002614931227_p959595516230"></a><a name="zh-cn_topic_0000002614931227_p959595516230"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p1959595592313"><a name="zh-cn_topic_0000002614931227_p1959595592313"></a><a name="zh-cn_topic_0000002614931227_p1959595592313"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p759585542315"><a name="zh-cn_topic_0000002614931227_p759585542315"></a><a name="zh-cn_topic_0000002614931227_p759585542315"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p2595165542313"><a name="zh-cn_topic_0000002614931227_p2595165542313"></a><a name="zh-cn_topic_0000002614931227_p2595165542313"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p18595355102314"><a name="zh-cn_topic_0000002614931227_p18595355102314"></a><a name="zh-cn_topic_0000002614931227_p18595355102314"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p95954552235"><a name="zh-cn_topic_0000002614931227_p95954552235"></a><a name="zh-cn_topic_0000002614931227_p95954552235"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row7595175516238"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p145954555234"><a name="zh-cn_topic_0000002614931227_p145954555234"></a><a name="zh-cn_topic_0000002614931227_p145954555234"></a><span id="zh-cn_topic_0000002614931227_ph2595135512317"><a name="zh-cn_topic_0000002614931227_ph2595135512317"></a><a name="zh-cn_topic_0000002614931227_ph2595135512317"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p1595195511239"><a name="zh-cn_topic_0000002614931227_p1595195511239"></a><a name="zh-cn_topic_0000002614931227_p1595195511239"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p65958557233"><a name="zh-cn_topic_0000002614931227_p65958557233"></a><a name="zh-cn_topic_0000002614931227_p65958557233"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p115959554235"><a name="zh-cn_topic_0000002614931227_p115959554235"></a><a name="zh-cn_topic_0000002614931227_p115959554235"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p125951155182315"><a name="zh-cn_topic_0000002614931227_p125951155182315"></a><a name="zh-cn_topic_0000002614931227_p125951155182315"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p8974212267"><a name="zh-cn_topic_0000002614931227_p8974212267"></a><a name="zh-cn_topic_0000002614931227_p8974212267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p119868121563"><a name="zh-cn_topic_0000002614931227_p119868121563"></a><a name="zh-cn_topic_0000002614931227_p119868121563"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row2597155512312"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p093820171495"><a name="zh-cn_topic_0000002614931227_p093820171495"></a><a name="zh-cn_topic_0000002614931227_p093820171495"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section957615561617"></a>

清除端口SU误码统计。

## 注意事项<a name="section8415102071"></a>

无。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -s -su_ber -i <dev_id> -u <udie_id> -p <port_id> -clear
```

## 参数说明<a name="section107781620873"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="17.560000000000002%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="26.150000000000002%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p16538337122410"><a name="zh-cn_topic_0000002614931223_p16538337122410"></a><a name="zh-cn_topic_0000002614931223_p16538337122410"></a>芯片UDie ID。取值：0。可通过<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令查询。</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p1911115561611"><a name="zh-cn_topic_0000002614931223_p1911115561611"></a><a name="zh-cn_topic_0000002614931223_p1911115561611"></a>芯片端口ID，详见<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令输出说明中的“Port ID”。</p>
</td>
</tr>
<tr id="row1870560201313"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p18709727141319"><a name="p18709727141319"></a><a name="p18709727141319"></a>-clear</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p0709127161316"><a name="p0709127161316"></a><a name="p0709127161316"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1170962791313"><a name="p1170962791313"></a><a name="p1170962791313"></a>清除SU误码统计信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

```bash
hccn_tool -s -su_ber -i 0 -u 0 -p 4 -clear
```

清除逻辑设备ID为0的UDie 0端口4的SU误码统计。

```text
Cmd executed successfully!
```

## 输出说明<a name="section55215490292"></a>

无。

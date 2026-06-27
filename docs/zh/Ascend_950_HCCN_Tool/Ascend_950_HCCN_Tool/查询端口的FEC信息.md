# 查询端口的FEC信息<a name="ZH-CN_TOPIC_0000002614811117"></a>

## 产品支持情况<a name="section5790730141118"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p44201360411"><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p44201360411"></a><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p44201360411"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p75637171408"><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p75637171408"></a><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p75637171408"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p187611624184817"><a name="zh-cn_topic_0000002614931227_p187611624184817"></a><a name="zh-cn_topic_0000002614931227_p187611624184817"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p2761324104819"><a name="zh-cn_topic_0000002614931227_p2761324104819"></a><a name="zh-cn_topic_0000002614931227_p2761324104819"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p1476142414488"><a name="zh-cn_topic_0000002614931227_p1476142414488"></a><a name="zh-cn_topic_0000002614931227_p1476142414488"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p1192142112542"><a name="zh-cn_topic_0000002614931227_p1192142112542"></a><a name="zh-cn_topic_0000002614931227_p1192142112542"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p15564417174012"><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p15564417174012"></a><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p15564417174012"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p14564617114019"><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p14564617114019"></a><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002062844850_p14564617114019"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p576152444819"><a name="zh-cn_topic_0000002614931227_p576152444819"></a><a name="zh-cn_topic_0000002614931227_p576152444819"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p67611424144816"><a name="zh-cn_topic_0000002614931227_p67611424144816"></a><a name="zh-cn_topic_0000002614931227_p67611424144816"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p776152411481"><a name="zh-cn_topic_0000002614931227_p776152411481"></a><a name="zh-cn_topic_0000002614931227_p776152411481"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p1819212135417"><a name="zh-cn_topic_0000002614931227_p1819212135417"></a><a name="zh-cn_topic_0000002614931227_p1819212135417"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row9310018122518"><td class="cellrowborder" valign="top" width="14.354285714285714%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p496503213253"><a name="zh-cn_topic_0000002614931227_p496503213253"></a><a name="zh-cn_topic_0000002614931227_p496503213253"></a><span id="zh-cn_topic_0000002614931227_ph12140626193614"><a name="zh-cn_topic_0000002614931227_ph12140626193614"></a><a name="zh-cn_topic_0000002614931227_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.217142857142855%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p11731721162710"><a name="zh-cn_topic_0000002614931227_p11731721162710"></a><a name="zh-cn_topic_0000002614931227_p11731721162710"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p7731142132711"><a name="zh-cn_topic_0000002614931227_p7731142132711"></a><a name="zh-cn_topic_0000002614931227_p7731142132711"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p18731152115278"><a name="zh-cn_topic_0000002614931227_p18731152115278"></a><a name="zh-cn_topic_0000002614931227_p18731152115278"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p07311821202718"><a name="zh-cn_topic_0000002614931227_p07311821202718"></a><a name="zh-cn_topic_0000002614931227_p07311821202718"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.262857142857142%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p11971556746"><a name="zh-cn_topic_0000002614931227_p11971556746"></a><a name="zh-cn_topic_0000002614931227_p11971556746"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.30857142857143%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p171927217545"><a name="zh-cn_topic_0000002614931227_p171927217545"></a><a name="zh-cn_topic_0000002614931227_p171927217545"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row1090441572511"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_zh-cn_topic_0000002338979954_p12881158154715"><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002338979954_p12881158154715"></a><a name="zh-cn_topic_0000002614931227_zh-cn_topic_0000002338979954_p12881158154715"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section957615561617"></a>

查询端口FEC信息。FEC（Forward Error Correction），前向纠错，是一种无需反向请求重传、通过发送端添加冗余校验信息，让接收端自行检测并纠正传输误码的编码技术，核心是用带宽冗余换传输可靠性与低时延。

## 注意事项<a name="section8415102071"></a>

无。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -g -fec -i <dev_id> -u <udie_id> -p <port_id>
```

## 参数说明<a name="section107781620873"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p16538337122410"><a name="zh-cn_topic_0000002614931223_p16538337122410"></a><a name="zh-cn_topic_0000002614931223_p16538337122410"></a>芯片UDie ID。取值：0。可通过<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令查询。</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p1911115561611"><a name="zh-cn_topic_0000002614931223_p1911115561611"></a><a name="zh-cn_topic_0000002614931223_p1911115561611"></a>芯片端口ID，详见<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令输出说明中的“Port ID”。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

```bash
hccn_tool -g -fec -i 0 -u 0 -p 4
```

查询逻辑设备ID为0的UDie 0端口4的FEC信息。

```text
+-----+------+------+---------+------------------+------------+
| NPU | UDie | Port | rs_mode | auto_change_mode | itlv_mode  |
+-----+------+------+---------+------------------+------------+
| 0   | 0    | 4    | 128 T4  | Static           | Interweave |
+-----+------+------+---------+------------------+------------+
```

## 输出说明<a name="section1726420371679"></a>

<a name="table112166911362"></a>
<table><thead align="left"><tr id="row15216793365"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p162167923615"><a name="p162167923615"></a><a name="p162167923615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p92161911364"><a name="p92161911364"></a><a name="p92161911364"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row321617933612"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p321649163611"><a name="p321649163611"></a><a name="p321649163611"></a>NPU</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p3524175718405"><a name="p3524175718405"></a><a name="p3524175718405"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row921619133615"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1353172710407"><a name="p1353172710407"></a><a name="p1353172710407"></a>UDie</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1152416574404"><a name="p1152416574404"></a><a name="p1152416574404"></a>芯片UDie ID。</p>
</td>
</tr>
<tr id="row4216129193611"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p8216598369"><a name="p8216598369"></a><a name="p8216598369"></a>Port</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1552411573404"><a name="p1552411573404"></a><a name="p1552411573404"></a>芯片端口号。</p>
</td>
</tr>
<tr id="row02166963613"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p14216109133611"><a name="p14216109133611"></a><a name="p14216109133611"></a>rs_mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1552395794015"><a name="p1552395794015"></a><a name="p1552395794015"></a>FEC均衡或去加重模式：</p>
<a name="ul177310111615"></a><a name="ul177310111615"></a><ul id="ul177310111615"><li>Bypass：关闭所有信号补偿算法。</li><li>128 T2：启用T2均衡算法，补偿力度为128档。</li><li>128 T4：启用T4均衡算法，补偿力度为128档。</li></ul>
</td>
</tr>
<tr id="row521610919366"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2216496365"><a name="p2216496365"></a><a name="p2216496365"></a>auto_change_mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11758155519304"><a name="p11758155519304"></a><a name="p11758155519304"></a>FEC 自动切换模式：</p>
<a name="ul4893192531013"></a><a name="ul4893192531013"></a><ul id="ul4893192531013"><li>Static：静态模式，FEC参数（如纠错力度、均衡系数）固定不变。</li><li>Trends：动态模式，芯片会根据链路质量（如误码率、信号信噪比）实时调整FEC参数，适用于链路环境多变的场景。</li></ul>
</td>
</tr>
<tr id="row32169918368"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p3326549174013"><a name="p3326549174013"></a><a name="p3326549174013"></a>itlv_mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p85238574400"><a name="p85238574400"></a><a name="p85238574400"></a>FEC 交织模式：</p>
<a name="ul6798717181018"></a><a name="ul6798717181018"></a><ul id="ul6798717181018"><li>Interweave：启用交织模式。</li><li>Uninterweave：启用非交织模式。</li></ul>
</td>
</tr>
</tbody>
</table>

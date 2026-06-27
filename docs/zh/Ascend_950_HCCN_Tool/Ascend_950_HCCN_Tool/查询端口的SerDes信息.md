# 查询端口的SerDes信息<a name="ZH-CN_TOPIC_0000002614931199"></a>

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

查询端口SerDes信息。

## 注意事项<a name="section8415102071"></a>

无。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -g -serdes -i <dev_id> -u <udie_id> -p <port_id>
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
hccn_tool -g -serdes -i 0 -u 0 -p 4
```

查询逻辑设备ID为0的UDie 0端口4的SerDes信息。

```text
+-----+------+------+------+--------+----------+----------+----------+-----------+-----------+
| NPU | UDie | Port | Lane | snr    | fir pre2 | fir pre1 | fir main | fir post1 | fir post2 |
+-----+------+------+------+--------+----------+----------+----------+-----------+-----------+
| 0   | 0    | 4    | 0    | 459340 | 1        | -10      | 48       | 4         | 0         |
| 0   | 0    | 4    | 1    | 421056 | 1        | -10      | 48       | 4         | 0         |
| 0   | 0    | 4    | 2    | 438960 | 1        | -10      | 48       | 4         | 0         |
| 0   | 0    | 4    | 3    | 432264 | 1        | -10      | 48       | 4         | 0         |
+-----+------+------+------+--------+----------+----------+----------+-----------+-----------+
```

## 输出说明<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720195152110"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1520115513214"><a name="p1520115513214"></a><a name="p1520115513214"></a>NPU</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p192015514212"><a name="p192015514212"></a><a name="p192015514212"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row820135132113"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p18201254210"><a name="p18201254210"></a><a name="p18201254210"></a>UDie</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p17201353219"><a name="p17201353219"></a><a name="p17201353219"></a>芯片UDie ID。</p>
</td>
</tr>
<tr id="row17503122122117"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p11503162132113"><a name="p11503162132113"></a><a name="p11503162132113"></a>Port</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p205034242114"><a name="p205034242114"></a><a name="p205034242114"></a>芯片端口号。</p>
</td>
</tr>
<tr id="row6503142122110"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p7503182162112"><a name="p7503182162112"></a><a name="p7503182162112"></a>Lane</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p750314222116"><a name="p750314222116"></a><a name="p750314222116"></a>数据传输通道。</p>
</td>
</tr>
<tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1976325663911"><a name="p1976325663911"></a><a name="p1976325663911"></a>snr</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p12762145683918"><a name="p12762145683918"></a><a name="p12762145683918"></a>信噪比。</p>
</td>
</tr>
<tr id="row2362651102413"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p7362165102417"><a name="p7362165102417"></a><a name="p7362165102417"></a>fir pre</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p14362175102417"><a name="p14362175102417"></a><a name="p14362175102417"></a>TX有限脉冲响应滤波器均衡参数pre cursor。</p>
</td>
</tr>
<tr id="row172720543241"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p827125452412"><a name="p827125452412"></a><a name="p827125452412"></a>fir main</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p20647711474"><a name="p20647711474"></a><a name="p20647711474"></a>TX有限脉冲响应滤波器均衡参数main cursor。</p>
</td>
</tr>
<tr id="row152785415242"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p172765442414"><a name="p172765442414"></a><a name="p172765442414"></a>fir post</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p23561981479"><a name="p23561981479"></a><a name="p23561981479"></a>TX有限脉冲响应滤波器均衡参数post cursor。</p>
</td>
</tr>
</tbody>
</table>

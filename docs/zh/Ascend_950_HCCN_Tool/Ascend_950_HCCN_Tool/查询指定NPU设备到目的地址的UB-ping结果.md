# 查询指定NPU设备到目的地址的UB ping结果<a name="ZH-CN_TOPIC_0000002584451416"></a>

## 产品支持情况<a name="section8178181118225"></a>

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

查询指定NPU设备到目的地址的UB ping结果。

## 注意事项<a name="section8415102071"></a>

Device侧支持的并发ping操作不大于8个。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -t -ub_ping -i <dev_id> -src_eid <src_eid> -dst_eid <dst_eid> [-pkt <size>] [-cnt <size>] [-interval <size>]
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
<tr id="zh-cn_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p45503264287"><a name="p45503264287"></a><a name="p45503264287"></a>-src_eid &lt;src_eid&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>指定源端EID标准格式，如x:x:x:x:x:x:x:x。可使用<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令查询，返回的字段“ipourma”的“IP Address”为可取的EID。</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p783412581807"><a name="p783412581807"></a><a name="p783412581807"></a>-dst_eid &lt;dst_eid&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p3688154719016"><a name="p3688154719016"></a><a name="p3688154719016"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p268815471808"><a name="p268815471808"></a><a name="p268815471808"></a>指定目的EID标准格式，如x:x:x:x:x:x:x:x。可使用<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令查询，返回的字段“ipourma”的“IP Address”为可取的EID。</p>
</td>
</tr>
<tr id="row172361433123514"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p31823764217"><a name="p31823764217"></a><a name="p31823764217"></a>-pkt &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p91825724213"><a name="p91825724213"></a><a name="p91825724213"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p10182197104216"><a name="p10182197104216"></a><a name="p10182197104216"></a>指定ping的数据包大小。单位为Byte，取值范围为[0, 4046]，默认值为4046。</p>
</td>
</tr>
<tr id="row5236123316356"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p045414171710"><a name="p045414171710"></a><a name="p045414171710"></a>-cnt &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p134545177117"><a name="p134545177117"></a><a name="p134545177117"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p134543171119"><a name="p134543171119"></a><a name="p134543171119"></a>指定要发送的ping包数量。取值范围为[1, 1000]，默认值为3。</p>
</td>
</tr>
<tr id="row8387336193516"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p1833964572814"><a name="p1833964572814"></a><a name="p1833964572814"></a>-interval &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p17387153663516"><a name="p17387153663516"></a><a name="p17387153663516"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1774744514911"><a name="p1774744514911"></a><a name="p1774744514911"></a>指定两次ping包之间的发送时间间隔。单位为毫秒，取值范围为[0, 10000]，默认值为1000。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

```bash
hccn_tool -t -ub_ping -i 0 -src_eid ::40:10:0:dfdf:90 -dst_eid ::60:10:0:dfdf:b0 -pkt 128 -cnt 6 -interval 1
```

查询逻辑设备ID为0的::40:10:0:dfdf:90到目的EID为::60:10:0:dfdf:b0的ping结果。

```text
device 0 dev  EID ::40:10:0:dfdf:90 to ::60:10:0:dfdf:b0
recv seq:0,time:0.286000ms
recv seq:1,time:0.288000ms
recv seq:2,time:0.278000ms
recv seq:3,time:0.282000ms
recv seq:4,time:0.289000ms
recv seq:5,time:0.295000ms
6 packets transmitted, 6 received, 0.00% packet loss
max time 0.295000ms
min time 0.278000ms
average time 0.286000ms
TP95 time 0.295000ms
Cmd executed successfully!
```

## 输出说明<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1522419311266"><a name="p1522419311266"></a><a name="p1522419311266"></a>recv seq</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p159371238267"><a name="p159371238267"></a><a name="p159371238267"></a>接收的序列号。</p>
</td>
</tr>
<tr id="row891712572230"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1991745712232"><a name="p1991745712232"></a><a name="p1991745712232"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p11917257192318"><a name="p11917257192318"></a><a name="p11917257192318"></a>发送和接收的间隔时间。</p>
</td>
</tr>
<tr id="row4337111320368"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1718216442065"><a name="p1718216442065"></a><a name="p1718216442065"></a>max time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p132931729115219"><a name="p132931729115219"></a><a name="p132931729115219"></a>接收回复报文中最大时延。</p>
</td>
</tr>
<tr id="row16665415163615"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p179332743619"><a name="p179332743619"></a><a name="p179332743619"></a>min time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p7293172955219"><a name="p7293172955219"></a><a name="p7293172955219"></a>接收回复报文中最小时延。</p>
</td>
</tr>
<tr id="row17665161512367"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p5208103323618"><a name="p5208103323618"></a><a name="p5208103323618"></a>average time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p132934298522"><a name="p132934298522"></a><a name="p132934298522"></a>接收回复报文中平均时延。</p>
</td>
</tr>
<tr id="row69731248173614"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p7307195118368"><a name="p7307195118368"></a><a name="p7307195118368"></a>TP95 time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p729310294529"><a name="p729310294529"></a><a name="p729310294529"></a>接收回复报文中95分位数时延。</p>
</td>
</tr>
</tbody>
</table>

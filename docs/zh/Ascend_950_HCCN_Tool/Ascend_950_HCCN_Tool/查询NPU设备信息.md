# 查询NPU设备信息<a name="ZH-CN_TOPIC_0000002584451440"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table38301303189"></a>
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

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

查询系统中NPU设备信息。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

无。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -dev_info -i <dev_id>
```

## 参数说明<a name="zh-cn_topic_0184799386_section10465854096"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p1371520181525"><a name="p1371520181525"></a><a name="p1371520181525"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0184799386_section1684018331898"></a>

```bash
hccn_tool -g -dev_info -i 0
```

查询逻辑ID为0的NPU设备信息。

```text
+---------+---------+---------------------+-----------+-------------+------------+
| UDie ID | Port ID | Speed Ability(Gbps) | Port Type | Link Status | Media Type |
+---------+---------+---------------------+-----------+-------------+------------+
| 0       | 4       | 400                 | UB        | UP          | Electrical |
| 0       | 5       | 400                 | UB        | UP          | Electrical |
| 0       | 6       | 400                 | UB        | UP          | Electrical |
+---------+---------+---------------------+-----------+-------------+------------+
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| Interface Name  | IP Address                                 | Netmask                                    | Bond Mode | Slaves          |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| end0v0          | *.*.*.*                              | 255.255.255.0                              | NA        | NA              |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| ipourma0        | ::10:0:dfdf:51                             | ffff:ffff:ffff:ffff::                      | NA        | NA              |
|                 | ::10:0:dfdf:30                             | ffff:ffff:ffff:ffff::                      |           |                 |
|                 | ::10:0:dfdf:28                             | ffff:ffff:ffff:ffff::                      |           |                 |
|                 | ::10:0:dfdf:20                             | ffff:ffff:ffff:ffff::                      |           |                 |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
+-----------------+-----------+-----------------------------------------+
| Name            | EID Index | EID                                     |
+-----------------+-----------+-----------------------------------------+
| udmac0d1e1           | 0         | 0000:0000:0000:0000:0010:0000:dfdf:0020 |
|                 | 1         | 0000:0000:0000:0000:0010:0000:dfdf:0028 |
|                 | 2         | 0000:0000:0000:0000:0010:0000:dfdf:0030 |
|                 | 3         | 0000:0000:0000:0000:0010:0000:dfdf:0051 |
+-----------------+-----------+-----------------------------------------+
```

## 输出说明<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row1545515094515"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p18662427144511"><a name="p18662427144511"></a><a name="p18662427144511"></a>UDie ID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p566132719457"><a name="p566132719457"></a><a name="p566132719457"></a>芯片的Die编号。</p>
</td>
</tr>
<tr id="row7307105584610"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p6307135511462"><a name="p6307135511462"></a><a name="p6307135511462"></a>Port ID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p43072055204611"><a name="p43072055204611"></a><a name="p43072055204611"></a>UDie上的端口ID。</p>
<p id="p1736992013222"><a name="p1736992013222"></a><a name="p1736992013222"></a>对于<span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span>，单卡时无有效端口；多卡时分为2卡或4卡通过UB总线互连，2卡互连时每一张卡的端口取值为4、5、6、8，4卡互连时每一张卡的端口取值为4、5、6。</p>
</td>
</tr>
<tr id="row84681138478"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p846893114715"><a name="p846893114715"></a><a name="p846893114715"></a>Speed Ability(Gbps)</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1846810374720"><a name="p1846810374720"></a><a name="p1846810374720"></a>端口速率（Gbps）。</p>
</td>
</tr>
<tr id="row113615143472"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p153614146479"><a name="p153614146479"></a><a name="p153614146479"></a>Port Type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p123671412474"><a name="p123671412474"></a><a name="p123671412474"></a>端口类型，UB表示UB口。</p>
<a name="ul28871846158"></a><a name="ul28871846158"></a><ul id="ul28871846158"><li>UB：UnifiedBus，灵衢总线协议。</li></ul>
</td>
</tr>
<tr id="row526012207470"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1926062019479"><a name="p1926062019479"></a><a name="p1926062019479"></a>Link Status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p426082094713"><a name="p426082094713"></a><a name="p426082094713"></a>link状态，DOWN或UP。</p>
</td>
</tr>
<tr id="row9792172514719"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p579211253472"><a name="p579211253472"></a><a name="p579211253472"></a>Media Type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p8792112514713"><a name="p8792112514713"></a><a name="p8792112514713"></a>介质类型，Electrical表示电口。</p>
</td>
</tr>
<tr id="row2663020204815"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p15663920114813"><a name="p15663920114813"></a><a name="p15663920114813"></a>Interface Name</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1766322034813"><a name="p1766322034813"></a><a name="p1766322034813"></a>网络设备名称。</p>
</td>
</tr>
<tr id="row0218192404819"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p13218624194817"><a name="p13218624194817"></a><a name="p13218624194817"></a>IP Address</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p12189246483"><a name="p12189246483"></a><a name="p12189246483"></a>IP地址。</p>
</td>
</tr>
<tr id="row717433212484"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p41741732194817"><a name="p41741732194817"></a><a name="p41741732194817"></a>Netmask</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p117493214814"><a name="p117493214814"></a><a name="p117493214814"></a>IP掩码。</p>
</td>
</tr>
<tr id="row245653574814"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p8456035154811"><a name="p8456035154811"></a><a name="p8456035154811"></a>Bond Mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p66172032445"><a name="p66172032445"></a><a name="p66172032445"></a>bond模式：</p>
<a name="ul1954392304416"></a><a name="ul1954392304416"></a><ul id="ul1954392304416"><li>802.3ad：当前仅支持此种模式。</li><li>Unknown：未知。</li><li>NA：非bond模式。</li></ul>
</td>
</tr>
<tr id="row761143812481"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p261183814481"><a name="p261183814481"></a><a name="p261183814481"></a>Slaves</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p156111738204811"><a name="p156111738204811"></a><a name="p156111738204811"></a>bond设备对应的子设备名称，非bond模式显示NA。</p>
</td>
</tr>
<tr id="row87012479484"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p117194784813"><a name="p117194784813"></a><a name="p117194784813"></a>Name</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p071947114815"><a name="p071947114815"></a><a name="p071947114815"></a>UDMA设备名称。</p>
</td>
</tr>
<tr id="row1850411501488"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1050435094812"><a name="p1050435094812"></a><a name="p1050435094812"></a>EID Index</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1504350184810"><a name="p1504350184810"></a><a name="p1504350184810"></a>UDMA设备EID Index。</p>
</td>
</tr>
<tr id="row13913652134811"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2913145218485"><a name="p2913145218485"></a><a name="p2913145218485"></a>EID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p39134525483"><a name="p39134525483"></a><a name="p39134525483"></a>UDMA设备EID。</p>
</td>
</tr>
</tbody>
</table>

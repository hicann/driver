# 查询端口的link down时链路相关信息<a name="ZH-CN_TOPIC_0000002584451438"></a>

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

查询端口link down时链路相关信息。

## 注意事项<a name="section8415102071"></a>

当link down触发了5次及以上时，执行该命令会显示5条链路相关信息，少于5次时按实际link down次数显示，回显按时间由近到远呈现。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -g -down_data -i <dev_id> -u <udie_id> -p <port_id>
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
hccn_tool -g -down_data -i 0 -u 0 -p 4
```

查询逻辑设备ID为0的UDie 0端口4的link down时链路相关信息。

```text
down data of udie 0 port 4 - log row 0:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 498960     | 0              | 0       | 770        | 81      | 93         | 3          |
| 1    | 473616     | 0              | 0       | 759        | 78      | 93         | 1          |
| 2    | 484720     | 0              | 0       | 730        | 83      | 93         | 3          |
| 3    | 467552     | 0              | 0       | 769        | 76      | 91         | 127        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 1:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 465152     | 0              | 0       | 736        | 79      | 93         | 2          |
| 1    | 469576     | 0              | 0       | 743        | 79      | 93         | 1          |
| 2    | 489888     | 0              | 0       | 756        | 81      | 93         | 3          |
| 3    | 478016     | 0              | 0       | 776        | 77      | 91         | 0          |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 2:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 477792     | 0              | 0       | 756        | 79      | 93         | 2          |
| 1    | 443032     | 0              | 0       | 701        | 79      | 91         | 2          |
| 2    | 484056     | 0              | 0       | 729        | 83      | 93         | 4          |
| 3    | 496128     | 0              | 0       | 816        | 76      | 91         | 127        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 3:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 468120     | 0              | 0       | 705        | 83      | 93         | 5          |
| 1    | 474000     | 0              | 0       | 750        | 79      | 94         | 1          |
| 2    | 495456     | 0              | 0       | 794        | 78      | 93         | 3          |
| 3    | 485888     | 0              | 0       | 832        | 73      | 90         | 126        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 4:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 478224     | 0              | 0       | 729        | 82      | 92         | 3          |
| 1    | 492608     | 0              | 0       | 716        | 86      | 93         | 4          |
| 2    | 497904     | 0              | 0       | 759        | 82      | 93         | 2          |
| 3    | 477744     | 0              | 0       | 807        | 74      | 91         | 0          |
+------+------------+----------------+---------+------------+---------+------------+------------+
```

说明：查询结果为芯片相关信息，具体的参数说明请联系工程师获取。

## 输出说明<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="29.959999999999997%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70.04%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row449219401435"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p1349212401437"><a name="p1349212401437"></a><a name="p1349212401437"></a>lane</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p1649216401234"><a name="p1649216401234"></a><a name="p1649216401234"></a>数据传输通道。</p>
</td>
</tr>
<tr id="row4340844835"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p1340344431"><a name="p1340344431"></a><a name="p1340344431"></a>snr_metric</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p834020441319"><a name="p834020441319"></a><a name="p834020441319"></a>信噪比度量指标。</p>
</td>
</tr>
<tr id="row1449592171419"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p1549511251416"><a name="p1549511251416"></a><a name="p1549511251416"></a>metric_his_min</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p1749519281418"><a name="p1749519281418"></a><a name="p1749519281418"></a>历史最小值的度量。</p>
</td>
</tr>
<tr id="row18495222144"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p749515210145"><a name="p749515210145"></a><a name="p749515210145"></a>err_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p184951720147"><a name="p184951720147"></a><a name="p184951720147"></a>错误率。</p>
</td>
</tr>
<tr id="row178331094146"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p15833594140"><a name="p15833594140"></a><a name="p15833594140"></a>cycles_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p58331992148"><a name="p58331992148"></a><a name="p58331992148"></a>周期平均值。</p>
</td>
</tr>
<tr id="row783318961411"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p38331291146"><a name="p38331291146"></a><a name="p38331291146"></a>heh_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p1483316913147"><a name="p1483316913147"></a><a name="p1483316913147"></a>硬件错误历史平均值。</p>
</td>
</tr>
<tr id="row55597130142"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p185597134148"><a name="p185597134148"></a><a name="p185597134148"></a>c3_ud_2csr</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p8559101310149"><a name="p8559101310149"></a><a name="p8559101310149"></a>C3寄存器更新到配置状态寄存器。</p>
</td>
</tr>
<tr id="row655901316146"><td class="cellrowborder" valign="top" width="29.959999999999997%" headers="mcps1.1.3.1.1 "><p id="p25594137142"><a name="p25594137142"></a><a name="p25594137142"></a>c5_ud_2csr</p>
</td>
<td class="cellrowborder" valign="top" width="70.04%" headers="mcps1.1.3.1.2 "><p id="p20559111316149"><a name="p20559111316149"></a><a name="p20559111316149"></a>C5寄存器更新到配置状态寄存器。</p>
</td>
</tr>
</tbody>
</table>

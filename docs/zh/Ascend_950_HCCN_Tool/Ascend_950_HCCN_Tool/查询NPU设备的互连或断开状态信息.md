# 查询NPU设备的互连或断开状态信息<a name="ZH-CN_TOPIC_0000002584451434"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row47351716152418"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p673514162240"><a name="zh-cn_topic_0000002614931227_p673514162240"></a><a name="zh-cn_topic_0000002614931227_p673514162240"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p16735101652415"><a name="zh-cn_topic_0000002614931227_p16735101652415"></a><a name="zh-cn_topic_0000002614931227_p16735101652415"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p573591614247"><a name="zh-cn_topic_0000002614931227_p573591614247"></a><a name="zh-cn_topic_0000002614931227_p573591614247"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p1773531692413"><a name="zh-cn_topic_0000002614931227_p1773531692413"></a><a name="zh-cn_topic_0000002614931227_p1773531692413"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p18735316192410"><a name="zh-cn_topic_0000002614931227_p18735316192410"></a><a name="zh-cn_topic_0000002614931227_p18735316192410"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p197351716162414"><a name="zh-cn_topic_0000002614931227_p197351716162414"></a><a name="zh-cn_topic_0000002614931227_p197351716162414"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row207354164243"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p157359169247"><a name="zh-cn_topic_0000002614931227_p157359169247"></a><a name="zh-cn_topic_0000002614931227_p157359169247"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p2073551618243"><a name="zh-cn_topic_0000002614931227_p2073551618243"></a><a name="zh-cn_topic_0000002614931227_p2073551618243"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p173531617242"><a name="zh-cn_topic_0000002614931227_p173531617242"></a><a name="zh-cn_topic_0000002614931227_p173531617242"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p1735191611244"><a name="zh-cn_topic_0000002614931227_p1735191611244"></a><a name="zh-cn_topic_0000002614931227_p1735191611244"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p173531662414"><a name="zh-cn_topic_0000002614931227_p173531662414"></a><a name="zh-cn_topic_0000002614931227_p173531662414"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p0735516172410"><a name="zh-cn_topic_0000002614931227_p0735516172410"></a><a name="zh-cn_topic_0000002614931227_p0735516172410"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row9735101672415"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p1735171610245"><a name="zh-cn_topic_0000002614931227_p1735171610245"></a><a name="zh-cn_topic_0000002614931227_p1735171610245"></a><span id="zh-cn_topic_0000002614931227_ph18735616162416"><a name="zh-cn_topic_0000002614931227_ph18735616162416"></a><a name="zh-cn_topic_0000002614931227_ph18735616162416"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p19735121618246"><a name="zh-cn_topic_0000002614931227_p19735121618246"></a><a name="zh-cn_topic_0000002614931227_p19735121618246"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p2735816172417"><a name="zh-cn_topic_0000002614931227_p2735816172417"></a><a name="zh-cn_topic_0000002614931227_p2735816172417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p14735116152415"><a name="zh-cn_topic_0000002614931227_p14735116152415"></a><a name="zh-cn_topic_0000002614931227_p14735116152415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p1973515163248"><a name="zh-cn_topic_0000002614931227_p1973515163248"></a><a name="zh-cn_topic_0000002614931227_p1973515163248"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p932658869"><a name="zh-cn_topic_0000002614931227_p932658869"></a><a name="zh-cn_topic_0000002614931227_p932658869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p1034512820618"><a name="zh-cn_topic_0000002614931227_p1034512820618"></a><a name="zh-cn_topic_0000002614931227_p1034512820618"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row173741602416"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p157551311498"><a name="zh-cn_topic_0000002614931227_p157551311498"></a><a name="zh-cn_topic_0000002614931227_p157551311498"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section957615561617"></a>

查询NPU设备互连、断开状态信息。

## 注意事项<a name="section8415102071"></a>

单卡无有效端口，2卡和4卡互连系统形态激活的端口不一样，该命令会打印出当前有效端口的状态信息。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -g -ub_connect -i <dev_id>
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
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p542332615419"><a name="p542332615419"></a><a name="p542332615419"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

```bash
hccn_tool -g -ub_connect -i 0
```

查询逻辑设备ID为0的互连、断开状态信息。

```text
link status : PARTIAL LINK
port 4 : UP
port 5 : DOWN
port 6 : PARTIAL UP
```

## 输出说明<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p81731506144"><a name="p81731506144"></a><a name="p81731506144"></a>link status</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p19688151811220"><a name="p19688151811220"></a><a name="p19688151811220"></a>整体连接状态：</p>
<a name="ul0628115134316"></a><a name="ul0628115134316"></a><ul id="ul0628115134316"><li>UP：所有有效端口均UP。</li><li>DOWN：所有有效端口均DOWN（或者无有效端口）。</li><li>PARTIAL LINK：部分有效端口UP。</li></ul>
</td>
</tr>
<tr id="row86641169146"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p666416631411"><a name="p666416631411"></a><a name="p666416631411"></a>port X</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p136647614142"><a name="p136647614142"></a><a name="p136647614142"></a>端口连接状态，也有UP/DOWN/PARTIAL UP三种情况，仅在降lane时为PARTIAL UP。</p>
</td>
</tr>
</tbody>
</table>

# 查询NPU设备的vNIC IP及link状态<a name="ZH-CN_TOPIC_0000002614931201"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row695219913269"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p795213913268"><a name="zh-cn_topic_0000002614931227_p795213913268"></a><a name="zh-cn_topic_0000002614931227_p795213913268"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p59525913261"><a name="zh-cn_topic_0000002614931227_p59525913261"></a><a name="zh-cn_topic_0000002614931227_p59525913261"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p195279152619"><a name="zh-cn_topic_0000002614931227_p195279152619"></a><a name="zh-cn_topic_0000002614931227_p195279152619"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p895217917264"><a name="zh-cn_topic_0000002614931227_p895217917264"></a><a name="zh-cn_topic_0000002614931227_p895217917264"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p795217919267"><a name="zh-cn_topic_0000002614931227_p795217919267"></a><a name="zh-cn_topic_0000002614931227_p795217919267"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p2952096260"><a name="zh-cn_topic_0000002614931227_p2952096260"></a><a name="zh-cn_topic_0000002614931227_p2952096260"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row139522916266"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p295239192612"><a name="zh-cn_topic_0000002614931227_p295239192612"></a><a name="zh-cn_topic_0000002614931227_p295239192612"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p2095213910260"><a name="zh-cn_topic_0000002614931227_p2095213910260"></a><a name="zh-cn_topic_0000002614931227_p2095213910260"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p17952594269"><a name="zh-cn_topic_0000002614931227_p17952594269"></a><a name="zh-cn_topic_0000002614931227_p17952594269"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p39521996263"><a name="zh-cn_topic_0000002614931227_p39521996263"></a><a name="zh-cn_topic_0000002614931227_p39521996263"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p15952995268"><a name="zh-cn_topic_0000002614931227_p15952995268"></a><a name="zh-cn_topic_0000002614931227_p15952995268"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p159521899265"><a name="zh-cn_topic_0000002614931227_p159521899265"></a><a name="zh-cn_topic_0000002614931227_p159521899265"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row10952129192612"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p119521993261"><a name="zh-cn_topic_0000002614931227_p119521993261"></a><a name="zh-cn_topic_0000002614931227_p119521993261"></a><span id="zh-cn_topic_0000002614931227_ph395216912616"><a name="zh-cn_topic_0000002614931227_ph395216912616"></a><a name="zh-cn_topic_0000002614931227_ph395216912616"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p1895269152612"><a name="zh-cn_topic_0000002614931227_p1895269152612"></a><a name="zh-cn_topic_0000002614931227_p1895269152612"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p1451181622719"><a name="zh-cn_topic_0000002614931227_p1451181622719"></a><a name="zh-cn_topic_0000002614931227_p1451181622719"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p19521992265"><a name="zh-cn_topic_0000002614931227_p19521992265"></a><a name="zh-cn_topic_0000002614931227_p19521992265"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p10780102012278"><a name="zh-cn_topic_0000002614931227_p10780102012278"></a><a name="zh-cn_topic_0000002614931227_p10780102012278"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p148361822862"><a name="zh-cn_topic_0000002614931227_p148361822862"></a><a name="zh-cn_topic_0000002614931227_p148361822862"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p1985413221567"><a name="zh-cn_topic_0000002614931227_p1985413221567"></a><a name="zh-cn_topic_0000002614931227_p1985413221567"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row1795413914266"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p137972361496"><a name="zh-cn_topic_0000002614931227_p137972361496"></a><a name="zh-cn_topic_0000002614931227_p137972361496"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

查询NPU设备的vNIC IP地址及link状态。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

无。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -vnic -i <dev_id>
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
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
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
hccn_tool -g -vnic -i 0
```

查询逻辑设备ID为0的vNIC IP地址及link状态。

```text
vnic link status: UP
vnic ipaddr: *.*.*.*
vnic netmask: 255.255.255.0
```

## 输出说明<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p28561618125718"><a name="p28561618125718"></a><a name="p28561618125718"></a>vnic link status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1851287153011"><a name="p1851287153011"></a><a name="p1851287153011"></a>虚拟网口的连接状态：</p>
<a name="ul1838483733017"></a><a name="ul1838483733017"></a><ul id="ul1838483733017"><li>UP：连接正常。</li><li>DOWN：连接中断。</li></ul>
</td>
</tr>
<tr id="row9947344415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1794820443117"><a name="p1794820443117"></a><a name="p1794820443117"></a>vnic ipaddr</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p15430140536"><a name="p15430140536"></a><a name="p15430140536"></a>虚拟网口的IP地址。</p>
</td>
</tr>
<tr id="row1946053614"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p11946195319120"><a name="p11946195319120"></a><a name="p11946195319120"></a>vnic netmask</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p14747181634"><a name="p14747181634"></a><a name="p14747181634"></a>虚拟网口的掩码。</p>
</td>
</tr>
</tbody>
</table>

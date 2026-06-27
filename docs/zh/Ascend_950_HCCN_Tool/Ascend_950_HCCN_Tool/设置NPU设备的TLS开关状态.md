# 设置NPU设备的TLS开关状态<a name="ZH-CN_TOPIC_0000002614931217"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002508152086_row1152516361961"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002508152086_p65251336569"><a name="zh-cn_topic_0000002508152086_p65251336569"></a><a name="zh-cn_topic_0000002508152086_p65251336569"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002508152086_p1452518361269"><a name="zh-cn_topic_0000002508152086_p1452518361269"></a><a name="zh-cn_topic_0000002508152086_p1452518361269"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002508152086_p12525133617618"><a name="zh-cn_topic_0000002508152086_p12525133617618"></a><a name="zh-cn_topic_0000002508152086_p12525133617618"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002508152086_p175251236867"><a name="zh-cn_topic_0000002508152086_p175251236867"></a><a name="zh-cn_topic_0000002508152086_p175251236867"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002508152086_p135256361566"><a name="zh-cn_topic_0000002508152086_p135256361566"></a><a name="zh-cn_topic_0000002508152086_p135256361566"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002508152086_p9525173614613"><a name="zh-cn_topic_0000002508152086_p9525173614613"></a><a name="zh-cn_topic_0000002508152086_p9525173614613"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002508152086_row175255361369"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002508152086_p175257363614"><a name="zh-cn_topic_0000002508152086_p175257363614"></a><a name="zh-cn_topic_0000002508152086_p175257363614"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002508152086_p175255361567"><a name="zh-cn_topic_0000002508152086_p175255361567"></a><a name="zh-cn_topic_0000002508152086_p175255361567"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002508152086_p052519366616"><a name="zh-cn_topic_0000002508152086_p052519366616"></a><a name="zh-cn_topic_0000002508152086_p052519366616"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002508152086_p1152593617617"><a name="zh-cn_topic_0000002508152086_p1152593617617"></a><a name="zh-cn_topic_0000002508152086_p1152593617617"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002508152086_p175251236967"><a name="zh-cn_topic_0000002508152086_p175251236967"></a><a name="zh-cn_topic_0000002508152086_p175251236967"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002508152086_p175252363616"><a name="zh-cn_topic_0000002508152086_p175252363616"></a><a name="zh-cn_topic_0000002508152086_p175252363616"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002508152086_row18525103618619"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002508152086_p7525736665"><a name="zh-cn_topic_0000002508152086_p7525736665"></a><a name="zh-cn_topic_0000002508152086_p7525736665"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002508152086_p29591819165216"><a name="zh-cn_topic_0000002508152086_p29591819165216"></a><a name="zh-cn_topic_0000002508152086_p29591819165216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="p165214437531"><a name="p165214437531"></a><a name="p165214437531"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002508152086_p4905122915216"><a name="zh-cn_topic_0000002508152086_p4905122915216"></a><a name="zh-cn_topic_0000002508152086_p4905122915216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="p8491161514521"><a name="p8491161514521"></a><a name="p8491161514521"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="p1247513092013"><a name="p1247513092013"></a><a name="p1247513092013"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="p179751228202115"><a name="p179751228202115"></a><a name="p179751228202115"></a>Y（Host侧证书）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002508152086_row55261736962"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="p202701127863"><a name="p202701127863"></a><a name="p202701127863"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

设置Host或Device的TLS开关状态。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

- 依赖TLS通信的业务需要通信双方保持TLS开关状态一致，否则可能影响业务正常运行。
- 该命令支持持久化。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -s -tls -i <dev_id> -enable <0/1> [-host]
```

## 参数说明<a name="zh-cn_topic_0184799386_section10465854096"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="29.95%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.76%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
<tr id="row14535125123912"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p1134164015249"><a name="p1134164015249"></a><a name="p1134164015249"></a>-enable &lt;0/1&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p18535105153916"><a name="p18535105153916"></a><a name="p18535105153916"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p88891211133217"><a name="p88891211133217"></a><a name="p88891211133217"></a>TLS开关状态值。</p>
<a name="ul146911122193219"></a><a name="ul146911122193219"></a><ul id="ul146911122193219"><li>0：关闭。</li><li>1：开启。Device侧未配置时，默认为1。</li></ul>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>指定设置Host侧TLS信息。无该项时默认设置Device侧信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section82714204319"></a>

- 示例1：

    ```bash
    hccn_tool -s -tls -i 0 -enable 1
    ```

    开启逻辑设备ID为0的Device侧的TLS开关。

    ```text
    Cmd executed successfully!
    ```

- 示例2：

    ```bash
    hccn_tool -s -tls -i 0 -enable 0 -host
    ```

    关闭逻辑设备ID为0的Host侧的TLS开关。

    ```text
    Cmd executed successfully!
    ```

## 输出说明<a name="section55215490292"></a>

无。

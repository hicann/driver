# 清除NPU设备的TLS证书信息<a name="ZH-CN_TOPIC_0000002584611358"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row1152516361961"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p65251336569"><a name="zh-cn_topic_0000002614931227_p65251336569"></a><a name="zh-cn_topic_0000002614931227_p65251336569"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p1452518361269"><a name="zh-cn_topic_0000002614931227_p1452518361269"></a><a name="zh-cn_topic_0000002614931227_p1452518361269"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p12525133617618"><a name="zh-cn_topic_0000002614931227_p12525133617618"></a><a name="zh-cn_topic_0000002614931227_p12525133617618"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p175251236867"><a name="zh-cn_topic_0000002614931227_p175251236867"></a><a name="zh-cn_topic_0000002614931227_p175251236867"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p135256361566"><a name="zh-cn_topic_0000002614931227_p135256361566"></a><a name="zh-cn_topic_0000002614931227_p135256361566"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p9525173614613"><a name="zh-cn_topic_0000002614931227_p9525173614613"></a><a name="zh-cn_topic_0000002614931227_p9525173614613"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row175255361369"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p175257363614"><a name="zh-cn_topic_0000002614931227_p175257363614"></a><a name="zh-cn_topic_0000002614931227_p175257363614"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p175255361567"><a name="zh-cn_topic_0000002614931227_p175255361567"></a><a name="zh-cn_topic_0000002614931227_p175255361567"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p052519366616"><a name="zh-cn_topic_0000002614931227_p052519366616"></a><a name="zh-cn_topic_0000002614931227_p052519366616"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p1152593617617"><a name="zh-cn_topic_0000002614931227_p1152593617617"></a><a name="zh-cn_topic_0000002614931227_p1152593617617"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p175251236967"><a name="zh-cn_topic_0000002614931227_p175251236967"></a><a name="zh-cn_topic_0000002614931227_p175251236967"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p175252363616"><a name="zh-cn_topic_0000002614931227_p175252363616"></a><a name="zh-cn_topic_0000002614931227_p175252363616"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row18525103618619"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p7525736665"><a name="zh-cn_topic_0000002614931227_p7525736665"></a><a name="zh-cn_topic_0000002614931227_p7525736665"></a><span id="zh-cn_topic_0000002614931227_ph115250361460"><a name="zh-cn_topic_0000002614931227_ph115250361460"></a><a name="zh-cn_topic_0000002614931227_ph115250361460"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p29591819165216"><a name="zh-cn_topic_0000002614931227_p29591819165216"></a><a name="zh-cn_topic_0000002614931227_p29591819165216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p19525143135318"><a name="zh-cn_topic_0000002614931227_p19525143135318"></a><a name="zh-cn_topic_0000002614931227_p19525143135318"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p4905122915216"><a name="zh-cn_topic_0000002614931227_p4905122915216"></a><a name="zh-cn_topic_0000002614931227_p4905122915216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p10942162645212"><a name="zh-cn_topic_0000002614931227_p10942162645212"></a><a name="zh-cn_topic_0000002614931227_p10942162645212"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p1247513092013"><a name="zh-cn_topic_0000002614931227_p1247513092013"></a><a name="zh-cn_topic_0000002614931227_p1247513092013"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p179751228202115"><a name="zh-cn_topic_0000002614931227_p179751228202115"></a><a name="zh-cn_topic_0000002614931227_p179751228202115"></a>Y（Host侧证书）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row55261736962"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p0526133614614"><a name="zh-cn_topic_0000002614931227_p0526133614614"></a><a name="zh-cn_topic_0000002614931227_p0526133614614"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

清除Host或Device的TLS证书信息。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

- 不支持单独清除Host侧的TLS证书吊销列表。
- 清除操作会清除设备的TLS证书信息，可能会影响依赖TLS通信的业务正常运行，请谨慎使用。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -s -tls -i <dev_id> -clear [-crl] [-host]
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
<tr id="row14535125123912"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7127429162613"><a name="p7127429162613"></a><a name="p7127429162613"></a>-clear</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p18535105153916"><a name="p18535105153916"></a><a name="p18535105153916"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1153516518398"><a name="p1153516518398"></a><a name="p1153516518398"></a>清除TLS证书信息。</p>
</td>
</tr>
<tr id="row174071213153714"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p8416192610446"><a name="p8416192610446"></a><a name="p8416192610446"></a>-crl</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1341672604411"><a name="p1341672604411"></a><a name="p1341672604411"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1341614260445"><a name="p1341614260445"></a><a name="p1341614260445"></a>指定清除Device侧TLS证书吊销列表，与-host互斥。</p>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>指定清除Host侧TLS信息。无该项时默认清除Device侧TLS信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section82714204319"></a>

- 示例1：

    ```bash
    hccn_tool -s -tls -i 0 -clear
    ```

    清除逻辑设备ID为0的Device侧的TLS证书信息。

    ```text
    Cmd executed successfully!
    ```

- 示例2：

    ```bash
    hccn_tool -s -tls -i 0 -clear -host
    ```

    清除逻辑设备ID为0的Host侧TLS证书信息。

    ```text
    Cmd executed successfully!
    ```

- 示例3：

    ```bash
    hccn_tool -s -tls -i 0 -clear -crl
    ```

    清除逻辑设备ID为0的Device侧的TLS证书吊销列表信息。

    ```text
    Cmd executed successfully!
    ```

## 输出说明<a name="section55215490292"></a>

无。

# 查询NPU设备的TLS证书信息<a name="ZH-CN_TOPIC_0000002584611342"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002062844850_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002062844850_p44201360411"><a name="zh-cn_topic_0000002062844850_p44201360411"></a><a name="zh-cn_topic_0000002062844850_p44201360411"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002062844850_p75637171408"><a name="zh-cn_topic_0000002062844850_p75637171408"></a><a name="zh-cn_topic_0000002062844850_p75637171408"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="p187611624184817"><a name="p187611624184817"></a><a name="p187611624184817"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="p2761324104819"><a name="p2761324104819"></a><a name="p2761324104819"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="p1476142414488"><a name="p1476142414488"></a><a name="p1476142414488"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="p7761524164817"><a name="p7761524164817"></a><a name="p7761524164817"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002062844850_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002062844850_p15564417174012"><a name="zh-cn_topic_0000002062844850_p15564417174012"></a><a name="zh-cn_topic_0000002062844850_p15564417174012"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002062844850_p14564617114019"><a name="zh-cn_topic_0000002062844850_p14564617114019"></a><a name="zh-cn_topic_0000002062844850_p14564617114019"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="p576152444819"><a name="p576152444819"></a><a name="p576152444819"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="p67611424144816"><a name="p67611424144816"></a><a name="p67611424144816"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="p776152411481"><a name="p776152411481"></a><a name="p776152411481"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="p1376142411481"><a name="p1376142411481"></a><a name="p1376142411481"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="row9310018122518"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="p496503213253"><a name="p496503213253"></a><a name="p496503213253"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="p10676134104320"><a name="p10676134104320"></a><a name="p10676134104320"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="p467693412433"><a name="p467693412433"></a><a name="p467693412433"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="p1567616346430"><a name="p1567616346430"></a><a name="p1567616346430"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="p44591743488"><a name="p44591743488"></a><a name="p44591743488"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="p78841858195018"><a name="p78841858195018"></a><a name="p78841858195018"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="p1778922248"><a name="p1778922248"></a><a name="p1778922248"></a>Y（Host侧证书）</p>
</td>
</tr>
<tr id="row1090441572511"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="p202701127863"><a name="p202701127863"></a><a name="p202701127863"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

查询Host侧或Device侧的TLS证书信息。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

无。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -tls -i <dev_id> [-host]
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
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>指定查询Host侧TLS信息。无该项时默认查询Device侧信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0184799386_section1684018331898"></a>

```bash
hccn_tool -g -tls -i 0
```

查询Device0的TLS证书信息。

```text
dev_id:0, tls switch[0](0:disable, 1:enable), tls preconfigured[0](0:non-preset, 1:preset), tls alarm time threshold[60]days
dev_id:0, [pub cert] info:
         subject[/C=CN/O=xxx/CN=www.xxx.com]
         issuer[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Wed Jun 18 03:10:27 2053 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [ca1 cert] info:
         subject[/C=CN/O=xxx/CN=xxx RSA CA]
         issuer[/C=CN/O=xxx/CN=xxx RSA CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Thu Feb  3 03:10:27 2056 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [ca2 cert] info:
         subject[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         issuer[/C=CN/O=xxx/CN=Test RSA CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Thu Mar 22 03:10:27 2108 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [crl] info:
         subject[]
         issuer[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Mon Mar  2 03:10:27 2026 GMT]
         tls expiration status[1](0:normal, 1:near expiration, 2:has expired)
```

## 输出说明<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p149462212379"><a name="p149462212379"></a><a name="p149462212379"></a>tls switch</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p12176156183113"><a name="p12176156183113"></a><a name="p12176156183113"></a><span>TLS</span>开关启用状态：</p>
<a name="ul76102363212"></a><a name="ul76102363212"></a><ul id="ul76102363212"><li>0：关闭。</li><li>1：开启。</li></ul>
</td>
</tr>
<tr id="row9947344415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p78214963818"><a name="p78214963818"></a><a name="p78214963818"></a>tls preconfigured</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p949287113210"><a name="p949287113210"></a><a name="p949287113210"></a><span>TLS</span>预置证书情况：</p>
<a name="ul04101314113217"></a><a name="ul04101314113217"></a><ul id="ul04101314113217"><li>0：非预置证书。</li><li>1：预置证书。</li></ul>
</td>
</tr>
<tr id="row1946053614"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p11514297399"><a name="p11514297399"></a><a name="p11514297399"></a>tls alarm time threshold</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p155751159171813"><a name="p155751159171813"></a><a name="p155751159171813"></a><span>TLS</span>过期告警阈值。</p>
</td>
</tr>
<tr id="row10242029533"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p026421412325"><a name="p026421412325"></a><a name="p026421412325"></a>subject</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p7264814113216"><a name="p7264814113216"></a><a name="p7264814113216"></a>TLS证书持有者的身份信息。</p>
</td>
</tr>
<tr id="row19132121513299"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p42319554399"><a name="p42319554399"></a><a name="p42319554399"></a>issuer</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p141331215152914"><a name="p141331215152914"></a><a name="p141331215152914"></a><span>TLS证书颁发机构。</span></p>
</td>
</tr>
<tr id="row766421693318"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p5665716153317"><a name="p5665716153317"></a><a name="p5665716153317"></a>start_time</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p26657161333"><a name="p26657161333"></a><a name="p26657161333"></a><span>TLS证书开始时间。</span></p>
</td>
</tr>
<tr id="row5813191853319"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p981311833312"><a name="p981311833312"></a><a name="p981311833312"></a>end_time</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p188133183333"><a name="p188133183333"></a><a name="p188133183333"></a><span>TLS证书结束时间。</span></p>
</td>
</tr>
<tr id="row10692129153312"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1069212913314"><a name="p1069212913314"></a><a name="p1069212913314"></a>tls expiration status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p18635151703213"><a name="p18635151703213"></a><a name="p18635151703213"></a><span>TLS证书过期状态：</span></p>
<a name="ul6419132713326"></a><a name="ul6419132713326"></a><ul id="ul6419132713326"><li><span>0：正常。</span></li><li><span>1：即将过期。</span></li><li><span>2：已经过期。</span></li></ul>
</td>
</tr>
</tbody>
</table>

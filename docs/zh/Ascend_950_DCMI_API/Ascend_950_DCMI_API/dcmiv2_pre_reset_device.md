# dcmiv2\_pre\_reset\_device<a name="ZH-CN_TOPIC_0000002314045174"></a>

## 函数原型<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_toc533412077"></a>

**int dcmiv2\_pre\_reset\_device\(int dev\_id\)**

## 功能说明<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_toc533412078"></a>

设备预复位，发起设备预复位接口，预复位目的是解除上层驱动及软件对此设备的依赖。必须在预复位接口返回成功后，才能对此芯片进行隔离或实际复位操作。

## 参数说明<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_toc533412079"></a>

<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p10021890"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p10021890"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p6466753"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p6466753"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p54045009"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p54045009"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p15569626"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p15569626"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p7711145152918"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p7711145152918"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p671116522914"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p671116522914"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p1771116572910"><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p1771116572910"></a><a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row1896512434515"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p6965943158"><a name="zh-cn_topic_0000002347924121_p6965943158"></a><a name="zh-cn_topic_0000002347924121_p6965943158"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p11965184315514"><a name="zh-cn_topic_0000002347924121_p11965184315514"></a><a name="zh-cn_topic_0000002347924121_p11965184315514"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p69657431958"><a name="zh-cn_topic_0000002347924121_p69657431958"></a><a name="zh-cn_topic_0000002347924121_p69657431958"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p129651243752"><a name="zh-cn_topic_0000002347924121_p129651243752"></a><a name="zh-cn_topic_0000002347924121_p129651243752"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p096511431456"><a name="zh-cn_topic_0000002347924121_p096511431456"></a><a name="zh-cn_topic_0000002347924121_p096511431456"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row596544317511"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p19965343955"><a name="zh-cn_topic_0000002347924121_p19965343955"></a><a name="zh-cn_topic_0000002347924121_p19965343955"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p1196534313515"><a name="zh-cn_topic_0000002347924121_p1196534313515"></a><a name="zh-cn_topic_0000002347924121_p1196534313515"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p1396510439515"><a name="zh-cn_topic_0000002347924121_p1396510439515"></a><a name="zh-cn_topic_0000002347924121_p1396510439515"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p396564310511"><a name="zh-cn_topic_0000002347924121_p396564310511"></a><a name="zh-cn_topic_0000002347924121_p396564310511"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1496519431356"><a name="zh-cn_topic_0000002347924121_p1496519431356"></a><a name="zh-cn_topic_0000002347924121_p1496519431356"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row096512432519"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="p144147361596"><a name="p144147361596"></a><a name="p144147361596"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p1023112549511"><a name="zh-cn_topic_0000002347924121_p1023112549511"></a><a name="zh-cn_topic_0000002347924121_p1023112549511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p92436547518"><a name="zh-cn_topic_0000002347924121_p92436547518"></a><a name="zh-cn_topic_0000002347924121_p92436547518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p725495412518"><a name="zh-cn_topic_0000002347924121_p725495412518"></a><a name="zh-cn_topic_0000002347924121_p725495412518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p5277115413515"><a name="zh-cn_topic_0000002347924121_p5277115413515"></a><a name="zh-cn_topic_0000002347924121_p5277115413515"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p82958547519"><a name="zh-cn_topic_0000002347924121_p82958547519"></a><a name="zh-cn_topic_0000002347924121_p82958547519"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row296612436519"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p8966943858"><a name="zh-cn_topic_0000002347924121_p8966943858"></a><a name="zh-cn_topic_0000002347924121_p8966943858"></a><span id="zh-cn_topic_0000002347924121_ph1296615432517"><a name="zh-cn_topic_0000002347924121_ph1296615432517"></a><a name="zh-cn_topic_0000002347924121_ph1296615432517"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001251227177_zh-cn_topic_0000001223172957_zh-cn_topic_0000001147850809_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
ret = dcmiv2_pre_reset_device(dev_id);
if (ret != 0) {
    //todo：记录日志
    return ret;
}
…
```

# dcmiv2\_reset\_device<a name="ZH-CN_TOPIC_0000002348043977"></a>

## 函数原型<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_toc533412077"></a>

**int dcmiv2\_reset\_device\(int dev\_id, enum dcmi\_reset\_channel channel\_type\)**

## 功能说明<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_toc533412078"></a>

复位芯片。

## 参数说明<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_toc533412079"></a>

<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p10021890"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p10021890"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p6466753"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p6466753"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p54045009"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p54045009"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p15569626"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p15569626"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p7711145152918"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p7711145152918"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p671116522914"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p671116522914"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1771116572910"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1771116572910"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001148530297_p11747451997"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001148530297_p11747451997"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001148530297_p11747451997"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
<div class="note" id="note9881134113272"><a name="note9881134113272"></a><a name="note9881134113272"></a><span class="notetitle"> 说明： </span><div class="notebody"><a name="ul6966185610185"></a><a name="ul6966185610185"></a><ul id="ul6966185610185"><li>使用该接口进行芯片带内复位时，物理机场景（裸机）root用户和物理机+特权容器场景支持dev_id传入0xFF，进行全卡复位。</li><li>使用该接口进行芯片带外复位时，不支持dev_id传入0xFF。</li></ul>
</div></div>
</td>
</tr>
<tr id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_row137415397316"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1622474112317"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1622474112317"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p1622474112317"></a>channel_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p19225441193116"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p19225441193116"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p19225441193116"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p102251441133110"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p102251441133110"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p102251441133110"></a>enum dcmi_reset_channel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p3511101013286"><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p3511101013286"></a><a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_p3511101013286"></a>复位通道。</p>
<pre class="codeblock" id="codeblock74511251101313"><a name="codeblock74511251101313"></a><a name="codeblock74511251101313"></a>enum dcmi_reset_channel {
OUTBAND_CHANNEL = 0, //带外复位
INBAND_CHANNEL = 1 //带内复位
}</pre>
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

## 约束说明<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row9596171719419"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p1059661716417"><a name="zh-cn_topic_0000002347924121_p1059661716417"></a><a name="zh-cn_topic_0000002347924121_p1059661716417"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p115964174411"><a name="zh-cn_topic_0000002347924121_p115964174411"></a><a name="zh-cn_topic_0000002347924121_p115964174411"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p3663614615"><a name="zh-cn_topic_0000002347924121_p3663614615"></a><a name="zh-cn_topic_0000002347924121_p3663614615"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p1559620177411"><a name="zh-cn_topic_0000002347924121_p1559620177411"></a><a name="zh-cn_topic_0000002347924121_p1559620177411"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p10613162423514"><a name="zh-cn_topic_0000002347924121_p10613162423514"></a><a name="zh-cn_topic_0000002347924121_p10613162423514"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row959614172418"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p15596151714414"><a name="zh-cn_topic_0000002347924121_p15596151714414"></a><a name="zh-cn_topic_0000002347924121_p15596151714414"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p559611171344"><a name="zh-cn_topic_0000002347924121_p559611171344"></a><a name="zh-cn_topic_0000002347924121_p559611171344"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p866318118620"><a name="zh-cn_topic_0000002347924121_p866318118620"></a><a name="zh-cn_topic_0000002347924121_p866318118620"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p1959614171345"><a name="zh-cn_topic_0000002347924121_p1959614171345"></a><a name="zh-cn_topic_0000002347924121_p1959614171345"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p82264478360"><a name="zh-cn_topic_0000002347924121_p82264478360"></a><a name="zh-cn_topic_0000002347924121_p82264478360"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row135967178414"><td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p2596121712410"><a name="zh-cn_topic_0000002347924121_p2596121712410"></a><a name="zh-cn_topic_0000002347924121_p2596121712410"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p6596111711414"><a name="zh-cn_topic_0000002347924121_p6596111711414"></a><a name="zh-cn_topic_0000002347924121_p6596111711414"></a>Y（仅支持带内）</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p25961017947"><a name="zh-cn_topic_0000002347924121_p25961017947"></a><a name="zh-cn_topic_0000002347924121_p25961017947"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p1086932715317"><a name="zh-cn_topic_0000002347924121_p1086932715317"></a><a name="zh-cn_topic_0000002347924121_p1086932715317"></a>Y（仅支持带内）</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1529918247412"><a name="zh-cn_topic_0000002347924121_p1529918247412"></a><a name="zh-cn_topic_0000002347924121_p1529918247412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="p18972125513302"><a name="p18972125513302"></a><a name="p18972125513302"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row155971917944"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p18597217849"><a name="zh-cn_topic_0000002347924121_p18597217849"></a><a name="zh-cn_topic_0000002347924121_p18597217849"></a><span id="zh-cn_topic_0000002347924121_ph3597217240"><a name="zh-cn_topic_0000002347924121_ph3597217240"></a><a name="zh-cn_topic_0000002347924121_ph3597217240"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206467196_zh-cn_topic_0000001177894694_zh-cn_topic_0000001099300038_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
enum dcmi_reset_channel channel_type = INBAND_CHANNEL;
ret = dcmiv2_reset_device(dev_id, channel_type);
if (ret != 0) {
    //todo：记录日志
    return ret;
}
…
```

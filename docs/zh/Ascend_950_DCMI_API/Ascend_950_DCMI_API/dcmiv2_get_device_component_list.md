# dcmiv2\_get\_device\_component\_list<a name="ZH-CN_TOPIC_0000002314045046"></a>

## 函数原型<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_toc533412077"></a>

**int dcmiv2\_get\_device\_component\_list\(int dev\_id, enum dcmi\_component\_type \*component\_table, unsigned int component\_count\)**

## 功能说明<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_toc533412078"></a>

获取可升级组件列表，不包含recovery组件。

## 参数说明<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_toc533412079"></a>

<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p10021890"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p10021890"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="17.130000000000003%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6466753"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6466753"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p54045009"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p54045009"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p15569626"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p15569626"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p7711145152918"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p7711145152918"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p671116522914"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p671116522914"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p1771116572910"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p1771116572910"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p5522164215178"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p5522164215178"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p5522164215178"></a>component_table</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p8522242101715"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p8522242101715"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p8522242101715"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p17522114220174"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p17522114220174"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p17522114220174"></a>enum dcmi_component_type *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p0522164231718"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p0522164231718"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p0522164231718"></a>返回可升级组件列表，具体值如下：</p>
<p id="p1462094752517"><a name="p1462094752517"></a><a name="p1462094752517"></a>enum dcmi_component_type {</p>
<p id="p1562119476256"><a name="p1562119476256"></a><a name="p1562119476256"></a>DCMI_COMPONENT_TYPE_NVE,</p>
<p id="p126211247102515"><a name="p126211247102515"></a><a name="p126211247102515"></a>DCMI_COMPONENT_TYPE_XLOADER,</p>
<p id="p9621647112520"><a name="p9621647112520"></a><a name="p9621647112520"></a>DCMI_COMPONENT_TYPE_M3FW,</p>
<p id="p1562134772520"><a name="p1562134772520"></a><a name="p1562134772520"></a>DCMI_COMPONENT_TYPE_UEFI,</p>
<p id="p16621164742519"><a name="p16621164742519"></a><a name="p16621164742519"></a>DCMI_COMPONENT_TYPE_TEE,</p>
<p id="p18621124712515"><a name="p18621124712515"></a><a name="p18621124712515"></a>DCMI_COMPONENT_TYPE_KERNEL,</p>
<p id="p26211147192517"><a name="p26211147192517"></a><a name="p26211147192517"></a>DCMI_COMPONENT_TYPE_DTB,</p>
<p id="p12621144718257"><a name="p12621144718257"></a><a name="p12621144718257"></a>DCMI_COMPONENT_TYPE_ROOTFS,</p>
<p id="p1462184720251"><a name="p1462184720251"></a><a name="p1462184720251"></a>DCMI_COMPONENT_TYPE_IMU,</p>
<p id="p0621164712257"><a name="p0621164712257"></a><a name="p0621164712257"></a>DCMI_COMPONENT_TYPE_IMP,</p>
<p id="p1762115479251"><a name="p1762115479251"></a><a name="p1762115479251"></a>DCMI_COMPONENT_TYPE_AICPU,</p>
<p id="p18621104762519"><a name="p18621104762519"></a><a name="p18621104762519"></a>DCMI_COMPONENT_TYPE_HBOOT1_A,</p>
<p id="p1621124772518"><a name="p1621124772518"></a><a name="p1621124772518"></a>DCMI_COMPONENT_TYPE_HBOOT1_B,</p>
<p id="p1962124742516"><a name="p1962124742516"></a><a name="p1962124742516"></a>DCMI_COMPONENT_TYPE_HBOOT2,</p>
<p id="p862112477254"><a name="p862112477254"></a><a name="p862112477254"></a>DCMI_COMPONENT_TYPE_DDR,</p>
<p id="p17621747152514"><a name="p17621747152514"></a><a name="p17621747152514"></a>DCMI_COMPONENT_TYPE_LP,</p>
<p id="p17621104702511"><a name="p17621104702511"></a><a name="p17621104702511"></a>DCMI_COMPONENT_TYPE_HSM,</p>
<p id="p662112479252"><a name="p662112479252"></a><a name="p662112479252"></a>DCMI_COMPONENT_TYPE_SAFETY_ISLAND,</p>
<p id="p11621347112510"><a name="p11621347112510"></a><a name="p11621347112510"></a>DCMI_COMPONENT_TYPE_HILINK,</p>
<p id="p156219475255"><a name="p156219475255"></a><a name="p156219475255"></a>DCMI_COMPONENT_TYPE_RAWDATA,</p>
<p id="p10621164719256"><a name="p10621164719256"></a><a name="p10621164719256"></a>DCMI_COMPONENT_TYPE_SYSDRV,</p>
<p id="p156211547172519"><a name="p156211547172519"></a><a name="p156211547172519"></a>DCMI_COMPONENT_TYPE_ADSAPP,</p>
<p id="p18621847112518"><a name="p18621847112518"></a><a name="p18621847112518"></a>DCMI_COMPONENT_TYPE_COMISOLATOR,</p>
<p id="p66211247122511"><a name="p66211247122511"></a><a name="p66211247122511"></a>DCMI_COMPONENT_TYPE_CLUSTER,</p>
<p id="p1462117475259"><a name="p1462117475259"></a><a name="p1462117475259"></a>DCMI_COMPONENT_TYPE_CUSTOMIZED,</p>
<p id="p26216475253"><a name="p26216475253"></a><a name="p26216475253"></a>DCMI_COMPONENT_TYPE_SYS_BASE_CONFIG,</p>
<p id="p36211047122514"><a name="p36211047122514"></a><a name="p36211047122514"></a>DCMI_COMPONENT_TYPE_RECOVERY,</p>
<p id="p962194732515"><a name="p962194732515"></a><a name="p962194732515"></a>DCMI_COMPONENT_TYPE_HILINK2,</p>
<p id="p196211447142518"><a name="p196211447142518"></a><a name="p196211447142518"></a>DCMI_COMPONENT_TYPE_LOGIC_BIST,</p>
<p id="p186219475253"><a name="p186219475253"></a><a name="p186219475253"></a>DCMI_COMPONENT_TYPE_MEMORY_BIST,</p>
<p id="p36211347192511"><a name="p36211347192511"></a><a name="p36211347192511"></a>DCMI_COMPONENT_TYPE_ATF,</p>
<p id="p66211647132518"><a name="p66211647132518"></a><a name="p66211647132518"></a>DCMI_COMPONENT_TYPE_USER_BASE_CONFIG,</p>
<p id="p14621184752513"><a name="p14621184752513"></a><a name="p14621184752513"></a>DCMI_COMPONENT_TYPE_BOOTROM,</p>
<p id="p11621194711259"><a name="p11621194711259"></a><a name="p11621194711259"></a>DCMI_COMPONENT_TYPE_MAX,</p>
<p id="p3621104752520"><a name="p3621104752520"></a><a name="p3621104752520"></a>DCMI_UPGRADE_AND_RESET_ALL_COMPONENT = 0xFFFFFFF7,</p>
<p id="p1862115472258"><a name="p1862115472258"></a><a name="p1862115472258"></a>DCMI_UPGRADE_ALL_IMAGE_COMPONENT = 0xFFFFFFFD,</p>
<p id="p136211476254"><a name="p136211476254"></a><a name="p136211476254"></a>DCMI_UPGRADE_ALL_FIRMWARE_COMPONENT = 0xFFFFFFFE,</p>
<p id="p15621747102519"><a name="p15621747102519"></a><a name="p15621747102519"></a>DCMI_UPGRADE_ALL_COMPONENT = 0xFFFFFFFF</p>
<p id="p162194716251"><a name="p162194716251"></a><a name="p162194716251"></a>};</p>
<p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p4384142910594"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p4384142910594"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p4384142910594"></a>当前支持DCMI_COMPONENT_TYPE_HBOOT1_A、DCMI_COMPONENT_TYPE_HBOOT1_B、DCMI_COMPONENT_TYPE_HILINK、DCMI_COMPONENT_TYPE_HILINK2。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_row1056131515384"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6574157389"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6574157389"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p6574157389"></a>component_count</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p75711152388"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p75711152388"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p75711152388"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p457111543818"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p457111543818"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p457111543818"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p145771510381"><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p145771510381"></a><a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_p145771510381"></a>“component_table”数组的长度，表示获取的组件个数。</p>
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

## 约束说明<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table18698834121214"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row448192315595"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p16487237599"><a name="zh-cn_topic_0000002347924121_p16487237599"></a><a name="zh-cn_topic_0000002347924121_p16487237599"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_p16315103817414"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p13109938611"><a name="zh-cn_topic_0000002347924121_p13109938611"></a><a name="zh-cn_topic_0000002347924121_p13109938611"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002481547074_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p992084633012"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p415458133719"><a name="zh-cn_topic_0000002347924121_p415458133719"></a><a name="zh-cn_topic_0000002347924121_p415458133719"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1048823175917"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p1248192317591"><a name="zh-cn_topic_0000002347924121_p1248192317591"></a><a name="zh-cn_topic_0000002347924121_p1248192317591"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p1248323175919"><a name="zh-cn_topic_0000002347924121_p1248323175919"></a><a name="zh-cn_topic_0000002347924121_p1248323175919"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p310918317614"><a name="zh-cn_topic_0000002347924121_p310918317614"></a><a name="zh-cn_topic_0000002347924121_p310918317614"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p11481223195912"><a name="zh-cn_topic_0000002347924121_p11481223195912"></a><a name="zh-cn_topic_0000002347924121_p11481223195912"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1154788375"><a name="zh-cn_topic_0000002347924121_p1154788375"></a><a name="zh-cn_topic_0000002347924121_p1154788375"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row9482231597"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p1848423155919"><a name="zh-cn_topic_0000002347924121_p1848423155919"></a><a name="zh-cn_topic_0000002347924121_p1848423155919"></a><span id="zh-cn_topic_0000002347924121_ph134862385916"><a name="zh-cn_topic_0000002347924121_ph134862385916"></a><a name="zh-cn_topic_0000002347924121_ph134862385916"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13805429105911"><a name="zh-cn_topic_0000002347924121_p13805429105911"></a><a name="zh-cn_topic_0000002347924121_p13805429105911"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p648122375913"><a name="zh-cn_topic_0000002347924121_p648122375913"></a><a name="zh-cn_topic_0000002347924121_p648122375913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p196292595205"><a name="zh-cn_topic_0000002347924121_p196292595205"></a><a name="zh-cn_topic_0000002347924121_p196292595205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p68652310590"><a name="zh-cn_topic_0000002347924121_p68652310590"></a><a name="zh-cn_topic_0000002347924121_p68652310590"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p199521530104817"><a name="zh-cn_topic_0000002347924121_p199521530104817"></a><a name="zh-cn_topic_0000002347924121_p199521530104817"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row26831629307"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p12838193417015"><a name="zh-cn_topic_0000002347924121_p12838193417015"></a><a name="zh-cn_topic_0000002347924121_p12838193417015"></a><span id="zh-cn_topic_0000002347924121_ph1574975517015"><a name="zh-cn_topic_0000002347924121_ph1574975517015"></a><a name="zh-cn_topic_0000002347924121_ph1574975517015"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001251307179_zh-cn_topic_0000001223172965_zh-cn_topic_0000001101337144_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
unsigned int component_num = 0;
enum dcmi_component_type *component_table = NULL;

ret = dcmiv2_get_device_component_cnt(dev_id, &component_num);
if (ret != 0) {
    // todo：记录日志
    return ret;
}

component_table = (enum dcmi_component_type *)malloc(sizeof(enum dcmi_component_type) * component_num);
if (component_table == NULL) {
    // todo：记录日志
    return false;
}

ret = dcmiv2_get_device_component_list(dev_id, component_table, component_num);
if (ret != 0) {
    // todo：记录日志
    free(component_table);
    return ret;
}
…
```

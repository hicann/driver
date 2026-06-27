# dcmiv2\_get\_device\_component\_list<a name="EN-US_TOPIC_0000002314045046"></a>

## Prototype<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412077"></a>

**int dcmiv2\_get\_device\_component\_list\(int dev\_id, enum dcmi\_component\_type \*component\_table, unsigned int component\_count\)**

## Description<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412078"></a>

Obtains the list of upgradable components, excluding the recovery component.

## Parameter Description<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412079"></a>

<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p10021890"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p10021890"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17.130000000000003%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6466753"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6466753"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="15.870000000000001%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p54045009"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p54045009"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p15569626"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p15569626"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p5522164215178"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p5522164215178"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p5522164215178"></a>component_table</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p8522242101715"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p8522242101715"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p8522242101715"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p17522114220174"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p17522114220174"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p17522114220174"></a>enum dcmi_component_type *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p0522164231718"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p0522164231718"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p0522164231718"></a>Upgradable component list.</p>
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
<p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"></a>Currently, <strong id="b162681021263"><a name="b162681021263"></a><a name="b162681021263"></a>DCMI_COMPONENT_TYPE_HBOOT1_A</strong>, <strong id="b11925132318611"><a name="b11925132318611"></a><a name="b11925132318611"></a>DCMI_COMPONENT_TYPE_HBOOT1_B</strong>, <strong id="b14961427965"><a name="b14961427965"></a><a name="b14961427965"></a>DCMI_COMPONENT_TYPE_HILINK</strong>, and <strong id="b1529820302616"><a name="b1529820302616"></a><a name="b1529820302616"></a>DCMI_COMPONENT_TYPE_HILINK2</strong> are supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row1056131515384"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"></a>component_count</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"></a>Length of <strong id="b0694654123116"><a name="b0694654123116"></a><a name="b0694654123116"></a>component_table</strong>, indicating the number of obtained components.</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table18698834121214"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row448192315595"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p16487237599"><a name="en-us_topic_0000002347924121_p16487237599"></a><a name="en-us_topic_0000002347924121_p16487237599"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002481547074_p16315103817414"><a name="en-us_topic_0000002347924121_en-us_topic_0000002481547074_p16315103817414"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002481547074_p16315103817414"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p13109938611"><a name="en-us_topic_0000002347924121_p13109938611"></a><a name="en-us_topic_0000002347924121_p13109938611"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002481547074_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002347924121_en-us_topic_0000002481547074_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002481547074_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p415458133719"><a name="en-us_topic_0000002347924121_p415458133719"></a><a name="en-us_topic_0000002347924121_p415458133719"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row1048823175917"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p1248192317591"><a name="en-us_topic_0000002347924121_p1248192317591"></a><a name="en-us_topic_0000002347924121_p1248192317591"></a><strong id="en-us_topic_0000002347924121_b1858175410557"><a name="en-us_topic_0000002347924121_b1858175410557"></a><a name="en-us_topic_0000002347924121_b1858175410557"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p1248323175919"><a name="en-us_topic_0000002347924121_p1248323175919"></a><a name="en-us_topic_0000002347924121_p1248323175919"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b1318885513556"><a name="en-us_topic_0000002347924121_b1318885513556"></a><a name="en-us_topic_0000002347924121_b1318885513556"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p310918317614"><a name="en-us_topic_0000002347924121_p310918317614"></a><a name="en-us_topic_0000002347924121_p310918317614"></a><strong id="en-us_topic_0000002347924121_b6989175575519"><a name="en-us_topic_0000002347924121_b6989175575519"></a><a name="en-us_topic_0000002347924121_b6989175575519"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p11481223195912"><a name="en-us_topic_0000002347924121_p11481223195912"></a><a name="en-us_topic_0000002347924121_p11481223195912"></a><strong id="en-us_topic_0000002347924121_b198211556115514"><a name="en-us_topic_0000002347924121_b198211556115514"></a><a name="en-us_topic_0000002347924121_b198211556115514"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1154788375"><a name="en-us_topic_0000002347924121_p1154788375"></a><a name="en-us_topic_0000002347924121_p1154788375"></a><strong id="en-us_topic_0000002347924121_b7632157195510"><a name="en-us_topic_0000002347924121_b7632157195510"></a><a name="en-us_topic_0000002347924121_b7632157195510"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row9482231597"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1848423155919"><a name="en-us_topic_0000002347924121_p1848423155919"></a><a name="en-us_topic_0000002347924121_p1848423155919"></a><span id="en-us_topic_0000002347924121_ph134862385916"><a name="en-us_topic_0000002347924121_ph134862385916"></a><a name="en-us_topic_0000002347924121_ph134862385916"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13805429105911"><a name="en-us_topic_0000002347924121_p13805429105911"></a><a name="en-us_topic_0000002347924121_p13805429105911"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p648122375913"><a name="en-us_topic_0000002347924121_p648122375913"></a><a name="en-us_topic_0000002347924121_p648122375913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p196292595205"><a name="en-us_topic_0000002347924121_p196292595205"></a><a name="en-us_topic_0000002347924121_p196292595205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p68652310590"><a name="en-us_topic_0000002347924121_p68652310590"></a><a name="en-us_topic_0000002347924121_p68652310590"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p199521530104817"><a name="en-us_topic_0000002347924121_p199521530104817"></a><a name="en-us_topic_0000002347924121_p199521530104817"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row26831629307"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p12838193417015"><a name="en-us_topic_0000002347924121_p12838193417015"></a><a name="en-us_topic_0000002347924121_p12838193417015"></a><span id="en-us_topic_0000002347924121_ph1574975517015"><a name="en-us_topic_0000002347924121_ph1574975517015"></a><a name="en-us_topic_0000002347924121_ph1574975517015"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
unsigned int component_num = 0;
enum dcmi_component_type *component_table = NULL;

ret = dcmiv2_get_device_component_cnt(dev_id, &component_num);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}

component_table = (enum dcmi_component_type *)malloc(sizeof(enum dcmi_component_type) * component_num);
if (component_table == NULL) {
    // TODO: Record logs.
    return false;
}

ret = dcmiv2_get_device_component_list(dev_id, component_table, component_num);
if (ret != 0) {
    // TODO: Record logs.
    free(component_table);
    return ret;
}
...
```

# dcmi\_get\_device\_component\_list<a name="EN-US_TOPIC_0000002515350562"></a>

**Prototype<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412077"></a>**

**int dcmi\_get\_device\_component\_list\(int card\_id, int device\_id, enum dcmi\_component\_type \*component\_table, unsigned int component\_count\)**

**Description<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412078"></a>**

Obtains the list of upgradable components, excluding the recovery component.

**Parameter Description<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412079"></a>**

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
<tbody><tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p36741947142813"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p36741947142813"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p96741747122818"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p96741747122818"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p46747472287"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p46747472287"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b29299933132951"><a name="b29299933132951"></a><a name="b29299933132951"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b120241086432927"><a name="b120241086432927"></a><a name="b120241086432927"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b16847046755920"><a name="b16847046755920"></a><a name="b16847046755920"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b100371603585654"><a name="b100371603585654"></a><a name="b100371603585654"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table18698834121214"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row18113171210"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1881934126"><a name="en-us_topic_0000002515350556_p1881934126"></a><a name="en-us_topic_0000002515350556_p1881934126"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p168143181218"><a name="en-us_topic_0000002515350556_p168143181218"></a><a name="en-us_topic_0000002515350556_p168143181218"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p88110314129"><a name="en-us_topic_0000002515350556_p88110314129"></a><a name="en-us_topic_0000002515350556_p88110314129"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row681203121213"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p11812310123"><a name="en-us_topic_0000002515350556_p11812310123"></a><a name="en-us_topic_0000002515350556_p11812310123"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p188215311122"><a name="en-us_topic_0000002515350556_p188215311122"></a><a name="en-us_topic_0000002515350556_p188215311122"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p58213311210"><a name="en-us_topic_0000002515350556_p58213311210"></a><a name="en-us_topic_0000002515350556_p58213311210"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row38243131214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p48210361212"><a name="en-us_topic_0000002515350556_p48210361212"></a><a name="en-us_topic_0000002515350556_p48210361212"></a><span id="en-us_topic_0000002515350556_text16821238124"><a name="en-us_topic_0000002515350556_text16821238124"></a><a name="en-us_topic_0000002515350556_text16821238124"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1990911717125"><a name="en-us_topic_0000002515350556_p1990911717125"></a><a name="en-us_topic_0000002515350556_p1990911717125"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1590914714124"><a name="en-us_topic_0000002515350556_p1590914714124"></a><a name="en-us_topic_0000002515350556_p1590914714124"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p9909273125"><a name="en-us_topic_0000002515350556_p9909273125"></a><a name="en-us_topic_0000002515350556_p9909273125"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row982437122"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p4829381220"><a name="en-us_topic_0000002515350556_p4829381220"></a><a name="en-us_topic_0000002515350556_p4829381220"></a><span id="en-us_topic_0000002515350556_text582173201218"><a name="en-us_topic_0000002515350556_text582173201218"></a><a name="en-us_topic_0000002515350556_text582173201218"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p59098719121"><a name="en-us_topic_0000002515350556_p59098719121"></a><a name="en-us_topic_0000002515350556_p59098719121"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p20909197161211"><a name="en-us_topic_0000002515350556_p20909197161211"></a><a name="en-us_topic_0000002515350556_p20909197161211"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p199091074123"><a name="en-us_topic_0000002515350556_p199091074123"></a><a name="en-us_topic_0000002515350556_p199091074123"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1782915383548"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p988163171613"><a name="en-us_topic_0000002515350556_p988163171613"></a><a name="en-us_topic_0000002515350556_p988163171613"></a><span id="en-us_topic_0000002515350556_text28812351611"><a name="en-us_topic_0000002515350556_text28812351611"></a><a name="en-us_topic_0000002515350556_text28812351611"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p107731653135415"><a name="en-us_topic_0000002515350556_p107731653135415"></a><a name="en-us_topic_0000002515350556_p107731653135415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p77730531545"><a name="en-us_topic_0000002515350556_p77730531545"></a><a name="en-us_topic_0000002515350556_p77730531545"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8773153175410"><a name="en-us_topic_0000002515350556_p8773153175410"></a><a name="en-us_topic_0000002515350556_p8773153175410"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19683944122816"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p19717154811286"><a name="en-us_topic_0000002515350556_p19717154811286"></a><a name="en-us_topic_0000002515350556_p19717154811286"></a><span id="en-us_topic_0000002515350556_text5717204812817"><a name="en-us_topic_0000002515350556_text5717204812817"></a><a name="en-us_topic_0000002515350556_text5717204812817"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p13998205142815"><a name="en-us_topic_0000002515350556_p13998205142815"></a><a name="en-us_topic_0000002515350556_p13998205142815"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p49983512287"><a name="en-us_topic_0000002515350556_p49983512287"></a><a name="en-us_topic_0000002515350556_p49983512287"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p89988518280"><a name="en-us_topic_0000002515350556_p89988518280"></a><a name="en-us_topic_0000002515350556_p89988518280"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row06711416544"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1765294655411"><a name="en-us_topic_0000002515350556_p1765294655411"></a><a name="en-us_topic_0000002515350556_p1765294655411"></a><span id="en-us_topic_0000002515350556_text19652946185414"><a name="en-us_topic_0000002515350556_text19652946185414"></a><a name="en-us_topic_0000002515350556_text19652946185414"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p428811549547"><a name="en-us_topic_0000002515350556_p428811549547"></a><a name="en-us_topic_0000002515350556_p428811549547"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p15288954155420"><a name="en-us_topic_0000002515350556_p15288954155420"></a><a name="en-us_topic_0000002515350556_p15288954155420"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p192881754115412"><a name="en-us_topic_0000002515350556_p192881754115412"></a><a name="en-us_topic_0000002515350556_p192881754115412"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row13182101810819"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p104761521386"><a name="en-us_topic_0000002515350556_p104761521386"></a><a name="en-us_topic_0000002515350556_p104761521386"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
unsigned int component_num = 0;
enum dcmi_component_type *component_table = NULL;

ret = dcmi_get_device_component_count(card_id, device_id, &component_num);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}

component_table = (enum dcmi_component_type *)malloc(sizeof(enum dcmi_component_type) * component_num);
if (component_table == NULL) {
    // todo: Record logs.
    return ret;
}

ret = dcmi_get_device_component_list(card_id, device_id, component_table, component_num);
if (ret != 0) {
    // todo: Record logs.
    free(component_table);
    return ret;
}
...
```

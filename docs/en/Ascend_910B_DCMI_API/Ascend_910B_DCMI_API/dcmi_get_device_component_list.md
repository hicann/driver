# dcmi\_get\_device\_component\_list<a name="EN-US_TOPIC_0000002515503858"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b520257565102757"><a name="b520257565102757"></a><a name="b520257565102757"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1878228938102419"><a name="b1878228938102419"></a><a name="b1878228938102419"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b967274529105314"><a name="b967274529105314"></a><a name="b967274529105314"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p4384142910594"></a>Currently, <strong id="b128697512123"><a name="b128697512123"></a><a name="b128697512123"></a>DCMI_COMPONENT_TYPE_HBOOT1_A</strong>, <strong id="b1869135111219"><a name="b1869135111219"></a><a name="b1869135111219"></a>DCMI_COMPONENT_TYPE_HBOOT1_B</strong>, <strong id="b11869175112120"><a name="b11869175112120"></a><a name="b11869175112120"></a>DCMI_COMPONENT_TYPE_HILINK</strong>, and <strong id="b3869155111217"><a name="b3869155111217"></a><a name="b3869155111217"></a>DCMI_COMPONENT_TYPE_HILINK2</strong> are supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_row1056131515384"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p6574157389"></a>component_count</p>
</td>
<td class="cellrowborder" valign="top" width="17.130000000000003%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p75711152388"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.870000000000001%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p457111543818"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"></a><a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_p145771510381"></a>Length of <strong id="b28701253310"><a name="b28701253310"></a><a name="b28701253310"></a>component_table</strong>, indicating the number of obtained components.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b135862185085534"><a name="b135862185085534"></a><a name="b135862185085534"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table36641225112113"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row11448141417420"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p1713218513317"><a name="en-us_topic_0000002515503852_p1713218513317"></a><a name="en-us_topic_0000002515503852_p1713218513317"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p213245123114"><a name="en-us_topic_0000002515503852_p213245123114"></a><a name="en-us_topic_0000002515503852_p213245123114"></a><strong id="en-us_topic_0000002515503852_b10699121316416"><a name="en-us_topic_0000002515503852_b10699121316416"></a><a name="en-us_topic_0000002515503852_b10699121316416"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="24.97%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p13132115113113"><a name="en-us_topic_0000002515503852_p13132115113113"></a><a name="en-us_topic_0000002515503852_p13132115113113"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b20722171412415"><a name="en-us_topic_0000002515503852_b20722171412415"></a><a name="en-us_topic_0000002515503852_b20722171412415"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25.03%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p8132185173115"><a name="en-us_topic_0000002515503852_p8132185173115"></a><a name="en-us_topic_0000002515503852_p8132185173115"></a><strong id="en-us_topic_0000002515503852_b1617141511413"><a name="en-us_topic_0000002515503852_b1617141511413"></a><a name="en-us_topic_0000002515503852_b1617141511413"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row728313421182"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13757328759"><a name="en-us_topic_0000002515503852_p13757328759"></a><a name="en-us_topic_0000002515503852_p13757328759"></a><span id="en-us_topic_0000002515503852_ph375715283511"><a name="en-us_topic_0000002515503852_ph375715283511"></a><a name="en-us_topic_0000002515503852_ph375715283511"></a><span id="en-us_topic_0000002515503852_text147574281354"><a name="en-us_topic_0000002515503852_text147574281354"></a><a name="en-us_topic_0000002515503852_text147574281354"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row12848477419"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p47571728152"><a name="en-us_topic_0000002515503852_p47571728152"></a><a name="en-us_topic_0000002515503852_p47571728152"></a><span id="en-us_topic_0000002515503852_text57571728359"><a name="en-us_topic_0000002515503852_text57571728359"></a><a name="en-us_topic_0000002515503852_text57571728359"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p28504223417"><a name="en-us_topic_0000002515503852_p28504223417"></a><a name="en-us_topic_0000002515503852_p28504223417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p17850172220413"><a name="en-us_topic_0000002515503852_p17850172220413"></a><a name="en-us_topic_0000002515503852_p17850172220413"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1385072213414"><a name="en-us_topic_0000002515503852_p1385072213414"></a><a name="en-us_topic_0000002515503852_p1385072213414"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row118411919445"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p177571128653"><a name="en-us_topic_0000002515503852_p177571128653"></a><a name="en-us_topic_0000002515503852_p177571128653"></a><span id="en-us_topic_0000002515503852_text15757628450"><a name="en-us_topic_0000002515503852_text15757628450"></a><a name="en-us_topic_0000002515503852_text15757628450"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15469122314417"><a name="en-us_topic_0000002515503852_p15469122314417"></a><a name="en-us_topic_0000002515503852_p15469122314417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p74698234414"><a name="en-us_topic_0000002515503852_p74698234414"></a><a name="en-us_topic_0000002515503852_p74698234414"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p346911236418"><a name="en-us_topic_0000002515503852_p346911236418"></a><a name="en-us_topic_0000002515503852_p346911236418"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1888071710410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p375752819516"><a name="en-us_topic_0000002515503852_p375752819516"></a><a name="en-us_topic_0000002515503852_p375752819516"></a><span id="en-us_topic_0000002515503852_text157571128457"><a name="en-us_topic_0000002515503852_text157571128457"></a><a name="en-us_topic_0000002515503852_text157571128457"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1211817247419"><a name="en-us_topic_0000002515503852_p1211817247419"></a><a name="en-us_topic_0000002515503852_p1211817247419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15118112412418"><a name="en-us_topic_0000002515503852_p15118112412418"></a><a name="en-us_topic_0000002515503852_p15118112412418"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p71183241449"><a name="en-us_topic_0000002515503852_p71183241449"></a><a name="en-us_topic_0000002515503852_p71183241449"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1276811111414"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p107581228856"><a name="en-us_topic_0000002515503852_p107581228856"></a><a name="en-us_topic_0000002515503852_p107581228856"></a><span id="en-us_topic_0000002515503852_text37581282519"><a name="en-us_topic_0000002515503852_text37581282519"></a><a name="en-us_topic_0000002515503852_text37581282519"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p120113251649"><a name="en-us_topic_0000002515503852_p120113251649"></a><a name="en-us_topic_0000002515503852_p120113251649"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p620114251847"><a name="en-us_topic_0000002515503852_p620114251847"></a><a name="en-us_topic_0000002515503852_p620114251847"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1120117251241"><a name="en-us_topic_0000002515503852_p1120117251241"></a><a name="en-us_topic_0000002515503852_p1120117251241"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row262419543"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19758182817512"><a name="en-us_topic_0000002515503852_p19758182817512"></a><a name="en-us_topic_0000002515503852_p19758182817512"></a><span id="en-us_topic_0000002515503852_text191152014162710"><a name="en-us_topic_0000002515503852_text191152014162710"></a><a name="en-us_topic_0000002515503852_text191152014162710"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p59851728544"><a name="en-us_topic_0000002515503852_p59851728544"></a><a name="en-us_topic_0000002515503852_p59851728544"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p11985828244"><a name="en-us_topic_0000002515503852_p11985828244"></a><a name="en-us_topic_0000002515503852_p11985828244"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p169851228148"><a name="en-us_topic_0000002515503852_p169851228148"></a><a name="en-us_topic_0000002515503852_p169851228148"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1994411513415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p97581828659"><a name="en-us_topic_0000002515503852_p97581828659"></a><a name="en-us_topic_0000002515503852_p97581828659"></a><span id="en-us_topic_0000002515503852_text20758132816511"><a name="en-us_topic_0000002515503852_text20758132816511"></a><a name="en-us_topic_0000002515503852_text20758132816511"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16036297418"><a name="en-us_topic_0000002515503852_p16036297418"></a><a name="en-us_topic_0000002515503852_p16036297418"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p8603182911412"><a name="en-us_topic_0000002515503852_p8603182911412"></a><a name="en-us_topic_0000002515503852_p8603182911412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96032298411"><a name="en-us_topic_0000002515503852_p96032298411"></a><a name="en-us_topic_0000002515503852_p96032298411"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row9870431183314"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p242563973319"><a name="en-us_topic_0000002515503852_p242563973319"></a><a name="en-us_topic_0000002515503852_p242563973319"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251307179_en-us_topic_0000001223172965_en-us_topic_0000001101337144_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
unsigned int component_num = 0;
enum dcmi_component_type *component_table = NULL;

ret = dcmi_get_device_component_count(card_id, device_id, &component_num);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}

component_table = (enum dcmi_component_type *)malloc(sizeof(enum dcmi_component_type) * component_num);
if (component_table == NULL) {
    //todo: Record logs.
    return ret;
}

ret = dcmi_get_device_component_list(card_id, device_id, component_table, component_num);
if (ret != 0) {
    //todo: Record logs.
    free(component_table);
    return ret;
}
...
```

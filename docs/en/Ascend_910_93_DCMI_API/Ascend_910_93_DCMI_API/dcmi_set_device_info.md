# dcmi\_set\_device\_info<a name="EN-US_TOPIC_0000002546990391"></a>

**Prototype<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412077"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412078"></a>**

Sets device information, including the information about each module.

**Parameter Description<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412079"></a>**

<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.28%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.7%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p36741947142813"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p36741947142813"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p96741747122818"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p96741747122818"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p46747472287"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p46747472287"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b37450860932953"><a name="b37450860932953"></a><a name="b37450860932953"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b912519032931"><a name="b912519032931"></a><a name="b912519032931"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b20155173716137"><a name="b20155173716137"></a><a name="b20155173716137"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"></a>CMD information, which is used to obtain the information about the corresponding module.</p>
<p id="p18641935123215"><a name="p18641935123215"></a><a name="p18641935123215"></a>enum dcmi_main_cmd {</p>
<p id="p6641635183210"><a name="p6641635183210"></a><a name="p6641635183210"></a>DCMI_MAIN_CMD_DVPP = 0,</p>
<p id="p11641835113217"><a name="p11641835113217"></a><a name="p11641835113217"></a>DCMI_MAIN_CMD_ISP,</p>
<p id="p126453510320"><a name="p126453510320"></a><a name="p126453510320"></a>DCMI_MAIN_CMD_TS_GROUP_NUM,</p>
<p id="p86453573215"><a name="p86453573215"></a><a name="p86453573215"></a>DCMI_MAIN_CMD_CAN,</p>
<p id="p364163533220"><a name="p364163533220"></a><a name="p364163533220"></a>DCMI_MAIN_CMD_UART,</p>
<p id="p66473583218"><a name="p66473583218"></a><a name="p66473583218"></a>DCMI_MAIN_CMD_UPGRADE = 5,</p>
<p id="p166483523216"><a name="p166483523216"></a><a name="p166483523216"></a>DCMI_MAIN_CMD_UFS,</p>
<p id="p26433563214"><a name="p26433563214"></a><a name="p26433563214"></a>DCMI_MAIN_CMD_OS_POWER,</p>
<p id="p136493519325"><a name="p136493519325"></a><a name="p136493519325"></a>DCMI_MAIN_CMD_LP,</p>
<p id="p36443520320"><a name="p36443520320"></a><a name="p36443520320"></a>DCMI_MAIN_CMD_MEMORY,</p>
<p id="p106463512321"><a name="p106463512321"></a><a name="p106463512321"></a>DCMI_MAIN_CMD_RECOVERY,</p>
<p id="p1464435203212"><a name="p1464435203212"></a><a name="p1464435203212"></a>DCMI_MAIN_CMD_TS,</p>
<p id="p16433563212"><a name="p16433563212"></a><a name="p16433563212"></a>DCMI_MAIN_CMD_CHIP_INF,</p>
<p id="p064173517327"><a name="p064173517327"></a><a name="p064173517327"></a>DCMI_MAIN_CMD_QOS,</p>
<p id="p106463515320"><a name="p106463515320"></a><a name="p106463515320"></a>DCMI_MAIN_CMD_SOC_INFO,</p>
<p id="p46493593220"><a name="p46493593220"></a><a name="p46493593220"></a>DCMI_MAIN_CMD_SILS,</p>
<p id="p9641735183212"><a name="p9641735183212"></a><a name="p9641735183212"></a>DCMI_MAIN_CMD_HCCS,</p>
<p id="p1656073942014"><a name="p1656073942014"></a><a name="p1656073942014"></a>DCMI_MAIN_CMD_HOST_AICPU,</p>
<p id="p1864173593210"><a name="p1864173593210"></a><a name="p1864173593210"></a>DCMI_MAIN_CMD_TEMP = 50,</p>
<p id="p18641835203218"><a name="p18641835203218"></a><a name="p18641835203218"></a>DCMI_MAIN_CMD_SVM,</p>
<p id="p1864135193214"><a name="p1864135193214"></a><a name="p1864135193214"></a>DCMI_MAIN_CMD_VDEV_MNG,</p>
<p id="p56473573215"><a name="p56473573215"></a><a name="p56473573215"></a>DCMI_MAIN_CMD_SEC,</p>
<p id="p141374616226"><a name="p141374616226"></a><a name="p141374616226"></a>DCMI_MAIN_CMD_PCIE = 55,</p>
<p id="p113869303566"><a name="p113869303566"></a><a name="p113869303566"></a>DCMI_MAIN_CMD_SIO = 56,</p>
<p id="p186413351321"><a name="p186413351321"></a><a name="p186413351321"></a>DCMI_MAIN_CMD_EX_COMPUTING = 0x8000,</p>
<p id="p116417356329"><a name="p116417356329"></a><a name="p116417356329"></a>DCMI_MAIN_CMD_DEVICE_SHARE = 0x8001,</p>
<p id="p1567402912213"><a name="p1567402912213"></a><a name="p1567402912213"></a>DCMI_MAIN_CMD_EX_CERT = 0x8003,</p>
<p id="p86483533216"><a name="p86483533216"></a><a name="p86483533216"></a>DCMI_MAIN_CMD_MAX</p>
<p id="p19641735163210"><a name="p19641735163210"></a><a name="p19641735163210"></a>};</p>
<p id="p1252703941712"><a name="p1252703941712"></a><a name="p1252703941712"></a>Only the main command words of the following modules are supported:</p>
<p id="p1319213425177"><a name="p1319213425177"></a><a name="p1319213425177"></a>DCMI_MAIN_CMD_LP // Main command word of the low power module</p>
<p id="p630816245918"><a name="p630816245918"></a><a name="p630816245918"></a>DCMI_MAIN_CMD_TS // Main command word of the task scheduling module</p>
<p id="p1647944161713"><a name="p1647944161713"></a><a name="p1647944161713"></a>DCMI_MAIN_CMD_QOS // Main command word of the QoS module</p>
<p id="en-us_topic_0000001206307236_p1516935634520"><a name="en-us_topic_0000001206307236_p1516935634520"></a><a name="en-us_topic_0000001206307236_p1516935634520"></a>DCMI_MAIN_CMD_VDEV_MNG // Main command word of the <span id="ph11173195663615"><a name="ph11173195663615"></a><a name="ph11173195663615"></a>Ascend virtual instance (AVI)</span> module DCMI_MAIN_CMD_SOC_INFO // Main command word of the SoC module</p>
<p id="p961754817269"><a name="p961754817269"></a><a name="p961754817269"></a>DCMI_MAIN_CMD_DEVICE_SHARE // Main command word for container sharing</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row131655372019"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="p96461212173514"><a name="p96461212173514"></a><a name="p96461212173514"></a>For details, see the function description in the subsections.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row9864105062010"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"></a>Device information buffer.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row177483489204"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"></a>Length of the <strong id="en-us_topic_0000001206307236_b0402131112418"><a name="en-us_topic_0000001206307236_b0402131112418"></a><a name="en-us_topic_0000001206307236_b0402131112418"></a>buf</strong> array.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b32427607272158"><a name="b32427607272158"></a><a name="b32427607272158"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int buf = 0;
unsigned int size = sizeof(int);
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_DVPP, 0, &buf, size);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_LP Command<a name="EN-US_TOPIC_0000002515350588"></a>

**Prototype<a name="section152647575211"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section172644579210"></a>**

Sets LP-related configurations.

**Parameter Description<a name="section1626515570213"></a>**

<a name="table22732571629"></a>
<table><thead align="left"><tr id="row530855719214"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p143081457622"><a name="p143081457622"></a><a name="p143081457622"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p113081579216"><a name="p113081579216"></a><a name="p113081579216"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.16%" id="mcps1.1.5.1.3"><p id="p1309357222"><a name="p1309357222"></a><a name="p1309357222"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.519999999999996%" id="mcps1.1.5.1.4"><p id="p1230925714210"><a name="p1230925714210"></a><a name="p1230925714210"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row11309175718219"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p173091571528"><a name="p173091571528"></a><a name="p173091571528"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p23091157422"><a name="p23091157422"></a><a name="p23091157422"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p6309145718212"><a name="p6309145718212"></a><a name="p6309145718212"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p43098579215"><a name="p43098579215"></a><a name="p43098579215"></a>Device ID. The supported IDs can be obtained by calling <strong id="b172574654132954"><a name="b172574654132954"></a><a name="b172574654132954"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row183091657724"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p430910572213"><a name="p430910572213"></a><a name="p430910572213"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p83092571127"><a name="p83092571127"></a><a name="p83092571127"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p93093571822"><a name="p93093571822"></a><a name="p93093571822"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p15309157129"><a name="p15309157129"></a><a name="p15309157129"></a>Chip ID, which can be obtained by calling <strong id="b111344339532932"><a name="b111344339532932"></a><a name="b111344339532932"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p20309757127"><a name="p20309757127"></a><a name="p20309757127"></a>NPU: [0, <strong id="b4072596668621"><a name="b4072596668621"></a><a name="b4072596668621"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1530917576214"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1830975719210"><a name="p1830975719210"></a><a name="p1830975719210"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p03091257720"><a name="p03091257720"></a><a name="p03091257720"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1630911571521"><a name="p1630911571521"></a><a name="p1630911571521"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p163094574212"><a name="p163094574212"></a><a name="p163094574212"></a>DCMI_MAIN_CMD_LP</p>
</td>
</tr>
<tr id="row19309757129"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p143091657124"><a name="p143091657124"></a><a name="p143091657124"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1030912570211"><a name="p1030912570211"></a><a name="p1030912570211"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1930965713212"><a name="p1930965713212"></a><a name="p1930965713212"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock866420763315"><a name="codeblock866420763315"></a><a name="codeblock866420763315"></a>typedef enum {
    // Obtain the register values indicating the voltage and current of the AI Core.
    DCMI_LP_SUB_CMD_AICORE_VOLTAGE_CURRENT = 0,
    // Obtain the register values indicating the voltage and current of the Hybird.
    DCMI_LP_SUB_CMD_HYBIRD_VOLTAGE_CURRENT,
    // Obtain the register values indicating the voltage and current of the CPU.
    DCMI_LP_SUB_CMD_TAISHAN_VOLTAGE_CURRENT,
    // Obtain the register values indicating the voltage and current of the DDR.
    DCMI_LP_SUB_CMD_DDR_VOLTAGE_CURRENT,
    // Obtain the count of ACG frequency modulations.
    DCMI_LP_SUB_CMD_ACG,
    // Obtain the overall low-power status.
    DCMI_LP_SUB_CMD_STATUS,
    // Obtain all working levels.
    DCMI_LP_SUB_CMD_TOPS_DETAILS,
    // Set the working level.
    DCMI_LP_SUB_CMD_SET_WORK_TOPS,
    // Obtain the current working level.
    DCMI_LP_SUB_CMD_GET_WORK_TOPS,
    // Obtain the reason of the current frequency reduction.
    DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE,
    // Obtain the power consumption information.
    DCMI_LP_SUB_CMD_GET_POWER_INFO,
    // Set the idle mode switch.
    DCMI_LP_SUB_CMD_SET_IDLE_SWITCH,
    DCMI_LP_SUB_CMD_MAX,
} DCMI_LP_SUB_CMD;</pre>
<p id="p9830153811229"><a name="p9830153811229"></a><a name="p9830153811229"></a>Currently, only the <strong id="b252519426210"><a name="b252519426210"></a><a name="b252519426210"></a>DCMI_LP_SUB_CMD_SET_IDLE_SWITCH</strong> command is supported.</p>
</td>
</tr>
<tr id="row1030917571727"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row83101557124"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1231019570213"><a name="p1231019570213"></a><a name="p1231019570213"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12310115715213"><a name="p12310115715213"></a><a name="p12310115715213"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1531045710217"><a name="p1531045710217"></a><a name="p1531045710217"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p13107576214"><a name="p13107576214"></a><a name="p13107576214"></a>Length of the <strong id="b13361328478621"><a name="b13361328478621"></a><a name="b13361328478621"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section2014284413016"></a>**

<a name="table85163468101"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b1975237667730"><a name="b1975237667730"></a><a name="b1975237667730"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section135813338518"></a>**

None

**Restrictions<a name="section13120154195114"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table152227367311"></a>
<table><thead align="left"><tr id="row102361036833"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p142361636536"><a name="p142361636536"></a><a name="p142361636536"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p172364361439"><a name="p172364361439"></a><a name="p172364361439"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p22369362034"><a name="p22369362034"></a><a name="p22369362034"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p102362362037"><a name="p102362362037"></a><a name="p102362362037"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row923653618312"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p02366360313"><a name="p02366360313"></a><a name="p02366360313"></a>DCMI_LP_SUB_CMD_SET_IDLE_SWITCH</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p132368365313"><a name="p132368365313"></a><a name="p132368365313"></a>unsigned char</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p202374363319"><a name="p202374363319"></a><a name="p202374363319"></a>Length: sizeof(unsigned char)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p1023715361335"><a name="p1023715361335"></a><a name="p1023715361335"></a><strong id="b10017262768621"><a name="b10017262768621"></a><a name="b10017262768621"></a>0</strong>: The idle mode is disabled.</p>
<p id="p32371364310"><a name="p32371364310"></a><a name="p32371364310"></a><strong id="b14359144508621"><a name="b14359144508621"></a><a name="b14359144508621"></a>1</strong>: The idle mode is enabled.</p>
<p id="p823733620312"><a name="p823733620312"></a><a name="p823733620312"></a>Other values indicate invalid effect.</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section168848176545"></a>**

```c
...
int ret;
int card_id = 0;
int device_id = 0;
DCMI_MAIN_CMD main_cmd = DCMI_MAIN_CMD_LP;
unsigned int sub_cmd = DCMI_LP_SUB_CMD_SET_WORK_TOPS;
DCMI_LP_WORK_TOPS_STRU set_works_tops_lv = {0};
set_works_tops_lv.work_tops = 1;
set_works_tops_lv.is_in_flash = 0;
unsigned int size = sizeof(DCMI_LP_WORK_TOPS_STRU);
ret = dcmi_set_device_info(card_id, device_id, main_cmd, sub_cmd, (void *)&set_works_tops_lv, size);
if (ret) {
// todo
}
// todo
...
```

## DCMI\_MAIN\_CMD\_QOS Command<a name="EN-US_TOPIC_0000002546990417"></a>

**Prototype<a name="section1042115192610"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section204318582611"></a>**

Configures QoS information, including mpamid and master QoS information and bandwidth statistics.

**Parameter Description<a name="section204395112610"></a>**

<a name="table14836522617"></a>
<table><thead align="left"><tr id="row81941750263"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p101942582619"><a name="p101942582619"></a><a name="p101942582619"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p1819414572612"><a name="p1819414572612"></a><a name="p1819414572612"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.16%" id="mcps1.1.5.1.3"><p id="p9194205132614"><a name="p9194205132614"></a><a name="p9194205132614"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.519999999999996%" id="mcps1.1.5.1.4"><p id="p1119511592612"><a name="p1119511592612"></a><a name="p1119511592612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row21958532610"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p121951513267"><a name="p121951513267"></a><a name="p121951513267"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p11956515261"><a name="p11956515261"></a><a name="p11956515261"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1919510562619"><a name="p1919510562619"></a><a name="p1919510562619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b108537566832955"><a name="b108537566832955"></a><a name="b108537566832955"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row4195175152616"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b183480198132933"><a name="b183480198132933"></a><a name="b183480198132933"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU: [0, <strong id="b16431328478527"><a name="b16431328478527"></a><a name="b16431328478527"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row1419520512612"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p7195135182617"><a name="p7195135182617"></a><a name="p7195135182617"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p2019515513267"><a name="p2019515513267"></a><a name="p2019515513267"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1519518513263"><a name="p1519518513263"></a><a name="p1519518513263"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p619605112614"><a name="p619605112614"></a><a name="p619605112614"></a>DCMI_MAIN_CMD_QOS</p>
</td>
</tr>
<tr id="row17196195102619"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p519619517267"><a name="p519619517267"></a><a name="p519619517267"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p819611592612"><a name="p819611592612"></a><a name="p819611592612"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p17196155202616"><a name="p17196155202616"></a><a name="p17196155202616"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock147418363249"><a name="codeblock147418363249"></a><a name="codeblock147418363249"></a>typedef enum {
// Specify the configuration about mpamid.
DCMI_QOS_SUB_MATA_CONFIG,
// Specify the configuration about master.
DCMI_QOS_SUB_MASTER_CONFIG,
// Configure bandwidth statistics.
 DCMI_QOS_SUB_BW_DATA,
// Configure general information.
DCMI_QOS_SUB_GLOBAL_CONFIG,
} DCMI_QOS_SUB_INFO;</pre>
</td>
</tr>
<tr id="row201979522617"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p191972511267"><a name="p191972511267"></a><a name="p191972511267"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p31971150262"><a name="p31971150262"></a><a name="p31971150262"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p61971451268"><a name="p61971451268"></a><a name="p61971451268"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p141972512616"><a name="p141972512616"></a><a name="p141972512616"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row31971555262"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p18197158261"><a name="p18197158261"></a><a name="p18197158261"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1419719510263"><a name="p1419719510263"></a><a name="p1419719510263"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p1019725162615"><a name="p1019725162615"></a><a name="p1019725162615"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619712516264"><a name="p1619712516264"></a><a name="p1619712516264"></a>Length of the <strong id="b7284380898527"><a name="b7284380898527"></a><a name="b7284380898527"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section2014284413016"></a>**

<a name="table85163468101"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b21041639217220"><a name="b21041639217220"></a><a name="b21041639217220"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section122651535145210"></a>**

None

**Restrictions<a name="section72205384522"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table590205182617"></a>
<table><thead align="left"><tr id="row919713512265"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p619712522612"><a name="p619712522612"></a><a name="p619712522612"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p1819814542619"><a name="p1819814542619"></a><a name="p1819814542619"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1119815515263"><a name="p1119815515263"></a><a name="p1119815515263"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p31981351265"><a name="p31981351265"></a><a name="p31981351265"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row819805122613"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p7198115112610"><a name="p7198115112610"></a><a name="p7198115112610"></a>DCMI_QOS_SUB_MATA_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p14198155262"><a name="p14198155262"></a><a name="p14198155262"></a>struct dcmi_qos_mata_config {</p>
<p id="p10198350263"><a name="p10198350263"></a><a name="p10198350263"></a>int mpamid;</p>
<p id="p11985511263"><a name="p11985511263"></a><a name="p11985511263"></a>unsigned int bw_high;</p>
<p id="p16198165162618"><a name="p16198165162618"></a><a name="p16198165162618"></a>unsigned int bw_low;</p>
<p id="p171988510267"><a name="p171988510267"></a><a name="p171988510267"></a>int hardlimit;</p>
<p id="p181982532614"><a name="p181982532614"></a><a name="p181982532614"></a>int reserved[DCMI_QOS_CFG_RESERVED_LEN];</p>
<p id="p0198155142616"><a name="p0198155142616"></a><a name="p0198155142616"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p1419814519266"><a name="p1419814519266"></a><a name="p1419814519266"></a>sizeof(dcmi_qos_mata_config)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul101981155262"></a><a name="ul101981155262"></a><ul id="ul101981155262"><li><strong id="b331812132412"><a name="b331812132412"></a><a name="b331812132412"></a>mpamid</strong>: The value range is [0, 127].</li><li><strong id="b564020088527"><a name="b564020088527"></a><a name="b564020088527"></a>bw_high</strong>: high waterline (GB/s). The value range is [0, 1638]. Note: The upper limit of the value range varies with the DDR frequency. The formula is <strong id="b10935033164213"><a name="b10935033164213"></a><a name="b10935033164213"></a>bw_high_max</strong> = <strong id="b1493543313429"><a name="b1493543313429"></a><a name="b1493543313429"></a>ddr_freq</strong> x 2 x <strong id="b159357333421"><a name="b159357333421"></a><a name="b159357333421"></a>max_chn</strong> x 8/1000. The actual dominant frequency and number of channels vary.</li><li><strong id="b64948432619"><a name="b64948432619"></a><a name="b64948432619"></a>bw_low</strong>: low waterline (GB/s). The value range is [0, <strong id="b4494343564"><a name="b4494343564"></a><a name="b4494343564"></a>bw_high</strong>].</li><li><strong id="b18043488858527"><a name="b18043488858527"></a><a name="b18043488858527"></a>hardlimit</strong>:<a name="ul1282591431120"></a><a name="ul1282591431120"></a><ul id="ul1282591431120"><li><strong id="b20806785238527"><a name="b20806785238527"></a><a name="b20806785238527"></a>1</strong>: The function is enabled.</li><li><strong id="b16367494638527"><a name="b16367494638527"></a><a name="b16367494638527"></a>0</strong>: The function is disabled.</li></ul>
</li></ul>
<p id="p8557317102714"><a name="p8557317102714"></a><a name="p8557317102714"></a>The waterlines you read by using this subcommand may be different from those you set. Difference = Maximum processor bandwidth/<strong id="b1988946122620"><a name="b1988946122620"></a><a name="b1988946122620"></a>MAX_REG_VALUE</strong>. The value of <strong id="b9830696178527"><a name="b9830696178527"></a><a name="b9830696178527"></a>MAX_REG_VALUE</strong> is 1024.</p>
</td>
</tr>
<tr id="row51993532614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p15199950269"><a name="p15199950269"></a><a name="p15199950269"></a>DCMI_QOS_SUB_MASTER_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1219910515263"><a name="p1219910515263"></a><a name="p1219910515263"></a>struct dcmi_qos_master_config {</p>
<p id="p121991756266"><a name="p121991756266"></a><a name="p121991756266"></a>int master;</p>
<p id="p219915162618"><a name="p219915162618"></a><a name="p219915162618"></a>int mpamid;</p>
<p id="p0199155142610"><a name="p0199155142610"></a><a name="p0199155142610"></a>int qos;</p>
<p id="p219913517269"><a name="p219913517269"></a><a name="p219913517269"></a>int pmg;</p>
<p id="p7199159265"><a name="p7199159265"></a><a name="p7199159265"></a>unsigned long long bitmap[4]; /* max support 64 * 4  */</p>
<p id="p21991651268"><a name="p21991651268"></a><a name="p21991651268"></a>int reserved[DCMI_QOS_CFG_RESERVED_LEN];</p>
<p id="p31991553269"><a name="p31991553269"></a><a name="p31991553269"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p191999513267"><a name="p191999513267"></a><a name="p191999513267"></a>sizeof(dcmi_qos_master_config)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1519965122612"></a><a name="ul1519965122612"></a><ul id="ul1519965122612"><li><strong id="b1520132584310"><a name="b1520132584310"></a><a name="b1520132584310"></a>master</strong>: master ID. The supported configuration items are <strong id="b852052514436"><a name="b852052514436"></a><a name="b852052514436"></a>vdec=1</strong>, <strong id="b10520142534311"><a name="b10520142534311"></a><a name="b10520142534311"></a>vpc=2</strong>, <strong id="b18520025184314"><a name="b18520025184314"></a><a name="b18520025184314"></a>jpge=3</strong>, <strong id="b9520725204315"><a name="b9520725204315"></a><a name="b9520725204315"></a>jpgd=4</strong>, <strong id="b1552042516436"><a name="b1552042516436"></a><a name="b1552042516436"></a>pcie=7</strong>, and <strong id="b20520192584316"><a name="b20520192584316"></a><a name="b20520192584316"></a>sdma=13</strong>.</li><li><strong id="b1965488612"><a name="b1965488612"></a><a name="b1965488612"></a>mpamid</strong>: The value range is [0, 127].</li><li><strong id="b10581380078527"><a name="b10581380078527"></a><a name="b10581380078527"></a>qos</strong>: bandwidth scheduling priority. The value range is [0, 7]. The value 0 indicates hardlimit QoS, and the value 7 indicates green channel QoS.</li><li><strong id="b1852629152712"><a name="b1852629152712"></a><a name="b1852629152712"></a>pmg</strong>: <strong id="b885314298276"><a name="b885314298276"></a><a name="b885314298276"></a>mpamid</strong> group. The value range is [0, 3].</li><li><strong id="b1220243312717"><a name="b1220243312717"></a><a name="b1220243312717"></a>bitmap</strong>: not supported due to framework restrictions.</li></ul>
</td>
</tr>
<tr id="row132000512266"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p320020518263"><a name="p320020518263"></a><a name="p320020518263"></a>DCMI_QOS_SUB_BW_DATA</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p12812438112"><a name="p12812438112"></a><a name="p12812438112"></a>struct dcmi_qos_bw_config</p>
<p id="p14281743121113"><a name="p14281743121113"></a><a name="p14281743121113"></a>{</p>
<p id="p628124319115"><a name="p628124319115"></a><a name="p628124319115"></a>u8 mode;</p>
<p id="p16282643161119"><a name="p16282643161119"></a><a name="p16282643161119"></a>u8 state;</p>
<p id="p1928254312115"><a name="p1928254312115"></a><a name="p1928254312115"></a>u8 cnt;</p>
<p id="p1528264311112"><a name="p1528264311112"></a><a name="p1528264311112"></a>u8 method;</p>
<p id="p6282164361119"><a name="p6282164361119"></a><a name="p6282164361119"></a>u32 interval;</p>
<p id="p1282943101118"><a name="p1282943101118"></a><a name="p1282943101118"></a>u32 target_set[16];</p>
<p id="p15282154351114"><a name="p15282154351114"></a><a name="p15282154351114"></a>int reserved_1[8];</p>
<p id="p1228294316114"><a name="p1228294316114"></a><a name="p1228294316114"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p16795420161114"><a name="p16795420161114"></a><a name="p16795420161114"></a>sizeof(dcmi_qos_bw_config)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p72381261113"><a name="p72381261113"></a><a name="p72381261113"></a><strong id="b1799493011433"><a name="b1799493011433"></a><a name="b1799493011433"></a>interval</strong>: bandwidth sampling interval, in &micro;s.</p>
<p id="p10231712131119"><a name="p10231712131119"></a><a name="p10231712131119"></a>The value must be greater than 1000.</p>
<a name="ul14758119151018"></a><a name="ul14758119151018"></a><ul id="ul14758119151018"><li><strong id="b348685017613"><a name="b348685017613"></a><a name="b348685017613"></a>mode</strong>: bandwidth statistics mode. <strong id="b1148615501767"><a name="b1148615501767"></a><a name="b1148615501767"></a>0</strong>: automatic mode; <strong id="b948616502612"><a name="b948616502612"></a><a name="b948616502612"></a>1</strong>: manual mode. The configuration takes effect only on the MATA/DHA side instead of the DDRC side. Only the manual mode is supported.</li><li><strong id="b1380323594315"><a name="b1380323594315"></a><a name="b1380323594315"></a>method</strong>: node for bandwidth statistics collection. <strong id="b7803173519437"><a name="b7803173519437"></a><a name="b7803173519437"></a>0</strong>: MATA/DHA.</li><li><strong id="b16652179878527"><a name="b16652179878527"></a><a name="b16652179878527"></a>state</strong>: bandwidth sampling command<a name="ul19778747111012"></a><a name="ul19778747111012"></a><ul id="ul19778747111012"><li><strong id="b2086909288527"><a name="b2086909288527"></a><a name="b2086909288527"></a>2</strong>: bandwidth sampling enabled</li><li><strong id="b8382751958527"><a name="b8382751958527"></a><a name="b8382751958527"></a>1</strong>: initialization</li><li><strong id="b19016052318527"><a name="b19016052318527"></a><a name="b19016052318527"></a>0</strong>: bandwidth sampling disabled</li></ul>
</li><li><strong id="b81391633102916"><a name="b81391633102916"></a><a name="b81391633102916"></a>target_set</strong>: sampling object mpamid. The maximum number varies with the Ascend AI Processor and is up to 16.</li><li><strong id="b25651543122916"><a name="b25651543122916"></a><a name="b25651543122916"></a>cnt</strong>: number of valid bandwidth statistics objects. The maximum number is 16.</li></ul>
</td>
</tr>
<tr id="row152004512610"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p3200558269"><a name="p3200558269"></a><a name="p3200558269"></a>DCMI_QOS_SUB_GLOBAL_CONFIG</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p122007517269"><a name="p122007517269"></a><a name="p122007517269"></a>struct dcmi_qos_gbl_config {</p>
<p id="p820012512616"><a name="p820012512616"></a><a name="p820012512616"></a>unsigned int enable;</p>
<p id="p820055122617"><a name="p820055122617"></a><a name="p820055122617"></a>unsigned int autoqos_fuse_en;         /* 0--enable, 1--disable */</p>
<p id="p720018502617"><a name="p720018502617"></a><a name="p720018502617"></a>unsigned int mpamqos_fuse_mode;       /* 0--average, 1--max, 2--replace */</p>
<p id="p620119511260"><a name="p620119511260"></a><a name="p620119511260"></a>unsigned int mpam_subtype;            /* 0--all, 1--wr, 2--rd, 3--none */</p>
<p id="p16201353266"><a name="p16201353266"></a><a name="p16201353266"></a>int reserved[DCMI_QOS_CFG_RESERVED_LEN];</p>
<p id="p172015562613"><a name="p172015562613"></a><a name="p172015562613"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p72011655263"><a name="p72011655263"></a><a name="p72011655263"></a>sizeof(dcmi_qos_gbl_config)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1520114516263"></a><a name="ul1520114516263"></a><ul id="ul1520114516263"><li><strong id="b20805597148527"><a name="b20805597148527"></a><a name="b20805597148527"></a>enable</strong>: indicates whether to enable the QoS function.<a name="ul9734199111712"></a><a name="ul9734199111712"></a><ul id="ul9734199111712"><li><strong id="b17009486108527"><a name="b17009486108527"></a><a name="b17009486108527"></a>0</strong>: disabled</li><li><strong id="b20000229768527"><a name="b20000229768527"></a><a name="b20000229768527"></a>1</strong>: enabled</li></ul>
</li><li><strong id="b21243501228527"><a name="b21243501228527"></a><a name="b21243501228527"></a>autoqos_fuse_en</strong>: indicates whether to enable QoS fusion. Currently, <strong id="b14121423418527"><a name="b14121423418527"></a><a name="b14121423418527"></a>autoqos_fuse_en</strong> cannot be set. The default value is 1.<a name="ul483832316173"></a><a name="ul483832316173"></a><ul id="ul483832316173"><li><strong id="b2512216178527"><a name="b2512216178527"></a><a name="b2512216178527"></a>0</strong>: QoS fusion is disabled.</li><li><strong id="b19279675568527"><a name="b19279675568527"></a><a name="b19279675568527"></a>1</strong>: QoS fusion starts.</li></ul>
</li><li><strong id="b7756132215306"><a name="b7756132215306"></a><a name="b7756132215306"></a>mpamqos_fuse_mode</strong>: QoS fusion mode. This parameter takes effect when <strong id="b77563221301"><a name="b77563221301"></a><a name="b77563221301"></a>autoqos_fuse_en</strong> is enabled.<a name="ul469217432179"></a><a name="ul469217432179"></a><ul id="ul469217432179"><li><strong id="b20358553478527"><a name="b20358553478527"></a><a name="b20358553478527"></a>0</strong>: average fusion</li><li><strong id="b1342143412381"><a name="b1342143412381"></a><a name="b1342143412381"></a>1</strong>: maximum value between the associated QoS and MPAM QoS</li><li><strong id="b2609244598527"><a name="b2609244598527"></a><a name="b2609244598527"></a>2</strong>: associated QoS as mpamqos</li></ul>
</li><li><strong id="b11077536788527"><a name="b11077536788527"></a><a name="b11077536788527"></a>mpam_subtype</strong>: bandwidth statistics mode<a name="ul1691317543171"></a><a name="ul1691317543171"></a><ul id="ul1691317543171"><li><strong id="b16881253778527"><a name="b16881253778527"></a><a name="b16881253778527"></a>0</strong>: read and write bandwidth statistics</li><li><strong id="b9574734638527"><a name="b9574734638527"></a><a name="b9574734638527"></a>1</strong>: write bandwidth statistics</li><li><strong id="b15017171588527"><a name="b15017171588527"></a><a name="b15017171588527"></a>2</strong>: read bandwidth statistics</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section854716251547"></a>**

```c
...
int32_t ret;
int card_id = 0;
int device_id = 0;
// Configure the mpamid high and low waterlines to limit the bandwidth.
struct qos_mata_config mataCfg = {0};
mataCfg.mpamid = 0; // For example, set mpamid to 0.
mataCfg.bw_high = 20;
mataCfg.bw_low = 10;
mataCfg.hardlimit = 1;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS,static_cast<uint32_t>(DCMI_QOS_SUB_MATA_CONFIG),
static_cast<void *>(&mataCfg), sizeof(struct qos_mata_config));
if (ret != 0) {
printf("[dev:%d]set mata qos config failed, ret = %d\n", devId, ret);
return ret;
}
// Configure mpamid, qos, and pmg corresponding to the master.
struct qos_master_config masterCfg = {0};
masterCfg.master = 0;
masterCfg.mpamid = 1; // For example, set mpamid to 1.
masterCfg.qos = 3;
masterCfg.pmg = 0;
masterCfg.bitmap[0] = 0xffff0000;
masterCfg.bitmap[1] = 0xffff;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, static_cast<uint32_t>(DCMI_QOS_SUB_MASTER_CONFIG),
static_cast<void *>(&cfg), sizeof(struct qos_master_config));
if (ret != 0) {
printf("[dev:%d]set master qos config failed, ret = %d\n", devId, ret);
return ret;
}
// Enable manual bandwidth monitoring and specify target objects.
struct qos_bw_config bwCfg = {0};
bwCfg.mode = 1;
bwCfg.state = 2;
bwCfg.target_set[0] = 1; // For example, set target object [0] to 1.
bwCfg.target_set[1] = 2; // For example, set target object [1] to 2.
bwCfg.cnt = 2;
bwCfg.interval = 1000;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(struct qos_bw_config));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", devId, ret);
return ret;
}
// Stop bandwidth monitoring.
bwCfg.state = 0;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", devId, ret);
return ret;
}
// Enable automatic bandwidth monitoring. You do not need to specify target objects. The program automatically reads the configured objects.
bwCfg.mode = 0;
bwCfg.interval = 1000;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", devId, ret);
return ret;
}
// Stop bandwidth monitoring.
bwCfg.state = 0;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", devId, ret);
return ret;
}
// Enable the QoS function globally.
struct qos_gbl_config gblCfg = {0};
gblCfg.enable = 1;
ret = dcmi_set_device_info(card_id, device_id, DCMI_MAIN_CMD_QOS, static_cast<uint32_t>(DCMI_QOS_SUB_GLOBAL_CONFIG),
static_cast<void *>(&gblCfg), sizeof(struct qos_gbl_config));
if (ret != 0) {
QOS_LOG_ERROR("[dev:%d]set gbl qos config failed, ret = %d\n", devId, ret);
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_VDEV\_MNG Command<a name="EN-US_TOPIC_0000002546990437"></a>

**Prototype<a name="en-us_topic_0257495783_section204121018181415"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="en-us_topic_0257495783_section10486629111410"></a>**

Configures the SR-IOV function.

**Parameter Description<a name="section9178940103517"></a>**

<a name="en-us_topic_0257495783_table45028263"></a>
<table><thead align="left"><tr id="en-us_topic_0257495783_row60695621"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0257495783_p17398306"><a name="en-us_topic_0257495783_p17398306"></a><a name="en-us_topic_0257495783_p17398306"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.41%" id="mcps1.1.5.1.2"><p id="en-us_topic_0257495783_p67085535"><a name="en-us_topic_0257495783_p67085535"></a><a name="en-us_topic_0257495783_p67085535"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.3"><p id="p153645385214"><a name="p153645385214"></a><a name="p153645385214"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0257495783_p48266778"><a name="en-us_topic_0257495783_p48266778"></a><a name="en-us_topic_0257495783_p48266778"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row884163595218"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p121951513267"><a name="p121951513267"></a><a name="p121951513267"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p11956515261"><a name="p11956515261"></a><a name="p11956515261"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1919510562619"><a name="p1919510562619"></a><a name="p1919510562619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b5472562432956"><a name="b5472562432956"></a><a name="b5472562432956"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row31747823"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b8624566532935"><a name="b8624566532935"></a><a name="b8624566532935"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU: [0, <strong id="b16705086358541"><a name="b16705086358541"></a><a name="b16705086358541"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row7743426585"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p15756282814"><a name="en-us_topic_0257495783_p15756282814"></a><a name="en-us_topic_0257495783_p15756282814"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p1574417263816"><a name="en-us_topic_0257495783_p1574417263816"></a><a name="en-us_topic_0257495783_p1574417263816"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1519518513263"><a name="p1519518513263"></a><a name="p1519518513263"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0257495783_p511112248254"><a name="en-us_topic_0257495783_p511112248254"></a><a name="en-us_topic_0257495783_p511112248254"></a>DCMI_MAIN_CMD_VDEV_MNG</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row42644663"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p851813475811"><a name="en-us_topic_0257495783_p851813475811"></a><a name="en-us_topic_0257495783_p851813475811"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p133891038900"><a name="en-us_topic_0257495783_p133891038900"></a><a name="en-us_topic_0257495783_p133891038900"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p17196155202616"><a name="p17196155202616"></a><a name="p17196155202616"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p27906562124"><a name="p27906562124"></a><a name="p27906562124"></a>typedef enum {</p>
<p id="p6790145615128"><a name="p6790145615128"></a><a name="p6790145615128"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE,</p>
<p id="p7790175612129"><a name="p7790175612129"></a><a name="p7790175612129"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE,</p>
<p id="p8790256131212"><a name="p8790256131212"></a><a name="p8790256131212"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE,</p>
<p id="p379065613127"><a name="p379065613127"></a><a name="p379065613127"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH,</p>
<p id="p779075617120"><a name="p779075617120"></a><a name="p779075617120"></a>DCMI_VMNG_SUB_CMD_GET_TOPS_PERCENTAGE,</p>
<p id="p1921391591419"><a name="p1921391591419"></a><a name="p1921391591419"></a>DCMI_VMNG_SUB_CMD_MAX,}</p>
<p id="p197902569126"><a name="p197902569126"></a><a name="p197902569126"></a>DCMI_VDEV_MNG_SUB_CMD;</p>
<div class="note" id="note690717511525"><a name="note690717511525"></a><a name="note690717511525"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul16211939171513"></a><a name="ul16211939171513"></a><ul id="ul16211939171513"><li>The current API supports only the <strong id="b1926134273612"><a name="b1926134273612"></a><a name="b1926134273612"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH</strong> command.</li><li><strong id="b19665049498541"><a name="b19665049498541"></a><a name="b19665049498541"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH</strong> indicates whether to enable the SR-IOV function.</li></ul>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row17526454687"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row19825197914"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p1231019570213"><a name="p1231019570213"></a><a name="p1231019570213"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p12310115715213"><a name="p12310115715213"></a><a name="p12310115715213"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1531045710217"><a name="p1531045710217"></a><a name="p1531045710217"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p13107576214"><a name="p13107576214"></a><a name="p13107576214"></a>Length of the <strong id="b7009940028541"><a name="b7009940028541"></a><a name="b7009940028541"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table192633010224"></a>
<table><thead align="left"><tr id="row3271230142220"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p13271130172213"><a name="p13271130172213"></a><a name="p13271130172213"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p72793011221"><a name="p72793011221"></a><a name="p72793011221"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p152673404312"><a name="p152673404312"></a><a name="p152673404312"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p17643133310315"><a name="p17643133310315"></a><a name="p17643133310315"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row92715303227"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p142710306225"><a name="p142710306225"></a><a name="p142710306225"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p1618115016210"><a name="p1618115016210"></a><a name="p1618115016210"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p364642917314"><a name="p364642917314"></a><a name="p364642917314"></a>Length: sizeof(unsigned int)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p06431333153111"><a name="p06431333153111"></a><a name="p06431333153111"></a><strong id="b7208057258541"><a name="b7208057258541"></a><a name="b7208057258541"></a>0</strong>: disables the SR-IOV function.</p>
<p id="p1313285923110"><a name="p1313285923110"></a><a name="p1313285923110"></a><strong id="b3915336098541"><a name="b3915336098541"></a><a name="b3915336098541"></a>1</strong>: enables the SR-IOV function.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section2014284413016"></a>**

<a name="table85163468101"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b1334639199725"><a name="b1334639199725"></a><a name="b1334639199725"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0257495783_section951814701613"></a>**

None

**Restrictions<a name="en-us_topic_0257495783_section11490105451612"></a>**

Before enabling SR-IOV, stop all services in this scenario.

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0257495783_section1130783912517"></a>**

```c
    ...
    int ret;
    int card_id = 0;
    int device_id = 0;
    DCMI_MAIN_CMD main_cmd = DCMI_MAIN_CMD_VDEV_MNG;
    unsigned int sub_cmd = DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH;
    unsigned int switch = 1;
    unsigned int size = sizeof(unsigned int);

    ret = dcmi_set_device_info(card_id, device_id, main_cmd, sub_cmd, (void *)&switch , size);
    if (ret) {
        // todo
    }
    // todo
    …
```

## DCMI\_MAIN\_CMD\_CHIP\_INF Command<a name="EN-US_TOPIC_0000002515350574"></a>

**Prototype<a name="section18718487128"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section16871048141214"></a>**

Configures the supernode status.

**Parameter Description<a name="section2087119482124"></a>**

<a name="table17888184841219"></a>
<table><thead align="left"><tr id="row1392511485122"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="p11925848111219"><a name="p11925848111219"></a><a name="p11925848111219"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.2"><p id="p1925134811127"><a name="p1925134811127"></a><a name="p1925134811127"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.189999999999998%" id="mcps1.1.5.1.3"><p id="p1092574831210"><a name="p1092574831210"></a><a name="p1092574831210"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.629999999999995%" id="mcps1.1.5.1.4"><p id="p1092511485122"><a name="p1092511485122"></a><a name="p1092511485122"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1492519481126"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p149251548131213"><a name="p149251548131213"></a><a name="p149251548131213"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p792554841218"><a name="p792554841218"></a><a name="p792554841218"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p392534881213"><a name="p392534881213"></a><a name="p392534881213"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1992517484120"><a name="p1992517484120"></a><a name="p1992517484120"></a>Device ID. The supported IDs can be obtained by calling <strong id="b61850725332958"><a name="b61850725332958"></a><a name="b61850725332958"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row19925114811215"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p992594871215"><a name="p992594871215"></a><a name="p992594871215"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p199251480124"><a name="p199251480124"></a><a name="p199251480124"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p17925104891219"><a name="p17925104891219"></a><a name="p17925104891219"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p4925194817127"><a name="p4925194817127"></a><a name="p4925194817127"></a>Chip ID, which can be obtained by calling <strong id="b97017483532937"><a name="b97017483532937"></a><a name="b97017483532937"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p492524811216"><a name="p492524811216"></a><a name="p492524811216"></a>NPU: [0, <strong id="b1891935015118"><a name="b1891935015118"></a><a name="b1891935015118"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row12925114814127"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p199251348131220"><a name="p199251348131220"></a><a name="p199251348131220"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p9925148171215"><a name="p9925148171215"></a><a name="p9925148171215"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p1392534815129"><a name="p1392534815129"></a><a name="p1392534815129"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p492564820121"><a name="p492564820121"></a><a name="p492564820121"></a>DCMI_MAIN_CMD_CHIP_INF</p>
</td>
</tr>
<tr id="row692584831214"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p2925848171213"><a name="p2925848171213"></a><a name="p2925848171213"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p492517485129"><a name="p492517485129"></a><a name="p492517485129"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p592544891211"><a name="p592544891211"></a><a name="p592544891211"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p9925184851217"><a name="p9925184851217"></a><a name="p9925184851217"></a>typedef enum {</p>
<p id="p1925748121217"><a name="p1925748121217"></a><a name="p1925748121217"></a>DCMI_CHIP_INF_SUB_CMD_CHIP_ID,</p>
<p id="p99255480121"><a name="p99255480121"></a><a name="p99255480121"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_INFO,</p>
<p id="p1892534831215"><a name="p1892534831215"></a><a name="p1892534831215"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS,</p>
<p id="p19925134813121"><a name="p19925134813121"></a><a name="p19925134813121"></a>DCMI_CHIP_INF_SUB_CMD_MAX = 0xFF,</p>
<p id="p69252488123"><a name="p69252488123"></a><a name="p69252488123"></a>} DCMI_CHIP_INFO_SUB_CMD;</p>
<div class="note" id="note12876144831210"><a name="note12876144831210"></a><a name="note12876144831210"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p189251648191210"><a name="p189251648191210"></a><a name="p189251648191210"></a>The current API supports only the <strong id="b739613217120"><a name="b739613217120"></a><a name="b739613217120"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS</strong> command.</p>
</div></div>
</td>
</tr>
<tr id="row692554821210"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p992511487125"><a name="p992511487125"></a><a name="p992511487125"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p15925184811215"><a name="p15925184811215"></a><a name="p15925184811215"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p10925124815127"><a name="p10925124815127"></a><a name="p10925124815127"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p99257484122"><a name="p99257484122"></a><a name="p99257484122"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row4925104881212"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p3925134810120"><a name="p3925134810120"></a><a name="p3925134810120"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p392519484123"><a name="p392519484123"></a><a name="p392519484123"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p292694891217"><a name="p292694891217"></a><a name="p292694891217"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p4926184861216"><a name="p4926184861216"></a><a name="p4926184861216"></a>Length of the <strong id="b178913911218"><a name="b178913911218"></a><a name="b178913911218"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section187813488124"></a>**

<a name="table98911848151211"></a>
<table><thead align="left"><tr id="row12926124814128"><th class="cellrowborder" valign="top" width="24.240000000000002%" id="mcps1.1.3.1.1"><p id="p15926144861211"><a name="p15926144861211"></a><a name="p15926144861211"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.76%" id="mcps1.1.3.1.2"><p id="p39261482123"><a name="p39261482123"></a><a name="p39261482123"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row20926748171210"><td class="cellrowborder" valign="top" width="24.240000000000002%" headers="mcps1.1.3.1.1 "><p id="p192654841213"><a name="p192654841213"></a><a name="p192654841213"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.76%" headers="mcps1.1.3.1.2 "><p id="p992674801217"><a name="p992674801217"></a><a name="p992674801217"></a>Results:</p>
<a name="ul1692620485126"></a><a name="ul1692620485126"></a><ul id="ul1692620485126"><li>Success: The value <strong id="b33755171125"><a name="b33755171125"></a><a name="b33755171125"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section188044812129"></a>**

None

**Restrictions<a name="section20880104819128"></a>**

SDID validity description: SDID is a 32-bit value divided into four ID fields, where bits 22 to 31 represent the  **server\_index**  \(range 0 to 47\), bits 18 to 21 represent the chip ID \(range 0 to 7\), bits 16 to 17 represent the die ID \(range 0 to 2\), and bits 0 to 15 represent the device ID, calculated as chip ID × 2 + die ID.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table20892174881210"></a>
<table><thead align="left"><tr id="row199261348151217"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p10926144814126"><a name="p10926144814126"></a><a name="p10926144814126"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p17926114891216"><a name="p17926114891216"></a><a name="p17926114891216"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p9926174817129"><a name="p9926174817129"></a><a name="p9926174817129"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p8926194871215"><a name="p8926194871215"></a><a name="p8926194871215"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row189269484126"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p149261948141214"><a name="p149261948141214"></a><a name="p149261948141214"></a>DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="p69261484121"><a name="p69261484121"></a><a name="p69261484121"></a>struct dcmi_spod_node_status {</p>
<p id="p1192619484126"><a name="p1192619484126"></a><a name="p1192619484126"></a>unsigned int sdid;</p>
<p id="p392624861215"><a name="p392624861215"></a><a name="p392624861215"></a>DCMI_SPOD_NODE_STATUS status;</p>
<p id="p59266484121"><a name="p59266484121"></a><a name="p59266484121"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p69261848121218"><a name="p69261848121218"></a><a name="p69261848121218"></a>sizeof(struct dcmi_spod_node_status)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul10926248151211"></a><a name="ul10926248151211"></a><ul id="ul10926248151211"><li>An SDID is the unique ID of an NPU within the SuperPoD system. The SDID of a target NPU should be provided.</li><li><strong id="b18777841113920"><a name="b18777841113920"></a><a name="b18777841113920"></a>status</strong> indicates the state record of an NPU identified by <strong id="b1390419109436"><a name="b1390419109436"></a><a name="b1390419109436"></a>SDID</strong>, using an NPU identified by <strong id="b114011147134314"><a name="b114011147134314"></a><a name="b114011147134314"></a>card_id</strong> and <strong id="b10204850144310"><a name="b10204850144310"></a><a name="b10204850144310"></a>device_id</strong>. After the NPU identified by <strong id="b87031102491"><a name="b87031102491"></a><a name="b87031102491"></a>card_id</strong> and <strong id="b1179271315496"><a name="b1179271315496"></a><a name="b1179271315496"></a>device_id</strong> is reset, <strong id="b16524132044920"><a name="b16524132044920"></a><a name="b16524132044920"></a>status</strong> is restored to its default value (<strong id="b19502163320496"><a name="b19502163320496"></a><a name="b19502163320496"></a>0</strong>).<a name="ul1518995073513"></a><a name="ul1518995073513"></a><ul id="ul1518995073513"><li>The value <strong id="en-us_topic_0000002546990395_b104343255717"><a name="en-us_topic_0000002546990395_b104343255717"></a><a name="en-us_topic_0000002546990395_b104343255717"></a>1</strong> indicates that the target NPU is abnormal. In this case, the local NPU forcibly releases the resources shared with the target NPU.</li><li>The value <strong id="en-us_topic_0000002546990395_b535714575714"><a name="en-us_topic_0000002546990395_b535714575714"></a><a name="en-us_topic_0000002546990395_b535714575714"></a>0</strong> indicates that the target NPU is normal. In this case, the local NPU negotiates the release of resources shared with the target NPU.</li></ul>
<div class="note" id="note109341427362"><a name="note109341427362"></a><a name="note109341427362"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p14934824362"><a name="p14934824362"></a><a name="p14934824362"></a>When the target NPU recovers from an abnormal state, call this API to change the status of this NPU to <strong id="b1481105734916"><a name="b1481105734916"></a><a name="b1481105734916"></a>0</strong> (normal).</p>
</div></div>
</li></ul>
</td>
</tr>
</tbody>
</table>

This API can be used in the PM + privileged container scenario.

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section188876488125"></a>**

```c
...
int ret;
int card_id = 0;
int device_id = 0;
enum dcmi_main_cmd  main_cmd = DCMI_MAIN_CMD_CHIP_INF;
unsigned int sub_cmd = DCMI_CHIP_INF_SUB_CMD_SPOD_NODE_STATUS;
struct dcmi_spod_node_status para = {0};
   
ret = dcmi_set_device_info(card_id, device_id, main_cmd, sub_cmd, (void *)&para, sizeof(struct dcmi_spod_node_status));
if (ret != DCMI_OK){
    // todo: Record logs.
     return ret;
}
...
```

## DCMI\_MAIN\_CMD\_TS Command<a name="EN-US_TOPIC_0000002515350610"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section19822105710305"></a>**

Configures system TS information.

**Parameter Description<a name="section188227576305"></a>**

<a name="table584175773016"></a>
<table><thead align="left"><tr id="row158991057133012"><th class="cellrowborder" valign="top" width="17.17171717171717%" id="mcps1.1.5.1.1"><p id="p1189945783015"><a name="p1189945783015"></a><a name="p1189945783015"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.151515151515152%" id="mcps1.1.5.1.2"><p id="p13899165713012"><a name="p13899165713012"></a><a name="p13899165713012"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.19191919191919%" id="mcps1.1.5.1.3"><p id="p789919571306"><a name="p789919571306"></a><a name="p789919571306"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.484848484848484%" id="mcps1.1.5.1.4"><p id="p38991757123015"><a name="p38991757123015"></a><a name="p38991757123015"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row14899115710307"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p289935717300"><a name="p289935717300"></a><a name="p289935717300"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p158990579308"><a name="p158990579308"></a><a name="p158990579308"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p890025715306"><a name="p890025715306"></a><a name="p890025715306"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1290095773011"><a name="p1290095773011"></a><a name="p1290095773011"></a>Device ID. The supported IDs can be obtained by calling <strong id="b199259332314"><a name="b199259332314"></a><a name="b199259332314"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1990019577303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p109001457133015"><a name="p109001457133015"></a><a name="p109001457133015"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1900175783013"><a name="p1900175783013"></a><a name="p1900175783013"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13900185710307"><a name="p13900185710307"></a><a name="p13900185710307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18900957193015"><a name="p18900957193015"></a><a name="p18900957193015"></a>Chip ID, which can be obtained by calling <strong id="b151851938534"><a name="b151851938534"></a><a name="b151851938534"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p390015577304"><a name="p390015577304"></a><a name="p390015577304"></a>NPU: [0, <strong id="b514874917314"><a name="b514874917314"></a><a name="b514874917314"></a>device_id_max</strong> – 1]</p>
<p id="p7337517715"><a name="p7337517715"></a><a name="p7337517715"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row19900125763017"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p18900657173012"><a name="p18900657173012"></a><a name="p18900657173012"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p5900155783016"><a name="p5900155783016"></a><a name="p5900155783016"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p89002574308"><a name="p89002574308"></a><a name="p89002574308"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p590010578307"><a name="p590010578307"></a><a name="p590010578307"></a>DCMI_MAIN_CMD_TS</p>
</td>
</tr>
<tr id="row0900155743018"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p139001157183018"><a name="p139001157183018"></a><a name="p139001157183018"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p18900165743017"><a name="p18900165743017"></a><a name="p18900165743017"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p1690018576308"><a name="p1690018576308"></a><a name="p1690018576308"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock84586272352"><a name="codeblock84586272352"></a><a name="codeblock84586272352"></a>typedef enum {
// Obtain the single-core utilization of the AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE = 0,
// Obtain the single-core utilization of the Vector Core/Obtain the utilization of the Vector unit in the single AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE,
// Obtain the FFTS or FFTS+ type. The value <strong id="b147441154946"><a name="b147441154946"></a><a name="b147441154946"></a>0</strong> indicates FFTS, and the value <strong id="b107441854343"><a name="b107441854343"></a><a name="b107441854343"></a>1</strong> indicates FFTS+.
DCMI_TS_SUB_CMD_FFTS_TYPE,
// Set the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_SET_FAULT_MASK,
// Obtain the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_GET_FAULT_MASK,
// Set the operator timeout scale, with a valid range of [20, 32].
DCMI_TS_SUB_CMD_COMMON_MSG = 11,
DCMI_TS_SUB_CMD_MAX,
} DCMI_TS_SUB_CMD;</pre>
<p id="p7900115703014"><a name="p7900115703014"></a><a name="p7900115703014"></a>Only <strong id="b15836216618"><a name="b15836216618"></a><a name="b15836216618"></a>DCMI_TS_SUB_CMD_COMMON_MSG</strong> is supported.</p>
</td>
</tr>
<tr id="row1190010575303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1190018574307"><a name="p1190018574307"></a><a name="p1190018574307"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19007577307"><a name="p19007577307"></a><a name="p19007577307"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p17900175711302"><a name="p17900175711302"></a><a name="p17900175711302"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p390012575308"><a name="p390012575308"></a><a name="p390012575308"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row16900145719304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p9900155716309"><a name="p9900155716309"></a><a name="p9900155716309"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p0900185719304"><a name="p0900185719304"></a><a name="p0900185719304"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6901257173010"><a name="p6901257173010"></a><a name="p6901257173010"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p090113577301"><a name="p090113577301"></a><a name="p090113577301"></a>Length of the <strong id="b470641579"><a name="b470641579"></a><a name="b470641579"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section283355715302"></a>**

<a name="table1985018574309"></a>
<table><thead align="left"><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002546910411_b16147213413"><a name="en-us_topic_0000002546910411_b16147213413"></a><a name="en-us_topic_0000002546910411_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None.

**Restrictions<a name="section22489571936"></a>**

This API can be used in the PM + privileged container scenario.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table08529574303"></a>
<table><thead align="left"><tr id="row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="p59011457173015"><a name="p59011457173015"></a><a name="p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="p159011357193019"><a name="p159011357193019"></a><a name="p159011357193019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="p1990165743011"><a name="p1990165743011"></a><a name="p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row16617143112276"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p1047117132015"><a name="p1047117132015"></a><a name="p1047117132015"></a>DCMI_TS_SUB_CMD_COMMON_MSG</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p19469111244813"><a name="p19469111244813"></a><a name="p19469111244813"></a>struct ts_dcmi_ctrl_msg_body_t {</p>
<p id="p1246961219488"><a name="p1246961219488"></a><a name="p1246961219488"></a>unsigned int msg_type;</p>
<p id="p246915123487"><a name="p246915123487"></a><a name="p246915123487"></a>union {</p>
<p id="p1746901219481"><a name="p1746901219481"></a><a name="p1746901219481"></a>ts_dcmi_task_timeout_t set_task_timeout_info;</p>
<p id="p64691512154816"><a name="p64691512154816"></a><a name="p64691512154816"></a>ts_dcmi_task_timeout_t get_task_timeout_info;</p>
<p id="p13469131244812"><a name="p13469131244812"></a><a name="p13469131244812"></a>} u;</p>
<p id="p134691512204817"><a name="p134691512204817"></a><a name="p134691512204817"></a>};</p>
<p id="p1719316326501"><a name="p1719316326501"></a><a name="p1719316326501"></a>The ts_dcmi_task_timeout_t structure is as follows:</p>
<p id="p522516213502"><a name="p522516213502"></a><a name="p522516213502"></a>typedef struct {</p>
<p id="p32251323501"><a name="p32251323501"></a><a name="p32251323501"></a>unsigned int timeout_limit_exp; // Value range: [20, 32]</p>
<p id="p222512155013"><a name="p222512155013"></a><a name="p222512155013"></a>unsigned char rsev[TS_RSEV_MAX_LENTH]; // <strong id="b1695075781"><a name="b1695075781"></a><a name="b1695075781"></a>TS_RSEV_MAX_LENTH</strong> is <strong id="b995012515810"><a name="b995012515810"></a><a name="b995012515810"></a>36</strong>.</p>
<p id="p10225725506"><a name="p10225725506"></a><a name="p10225725506"></a>} ts_dcmi_task_timeout_t;</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p19359252485"><a name="p19359252485"></a><a name="p19359252485"></a>As an input, it indicates the <strong id="b621181415817"><a name="b621181415817"></a><a name="b621181415817"></a>buf</strong> size. The <strong id="b192119145814"><a name="b192119145814"></a><a name="b192119145814"></a>buf</strong> must be at least 44 bytes.</p>
<p id="p19218195310"><a name="p19218195310"></a><a name="p19218195310"></a><strong id="b14172722081"><a name="b14172722081"></a><a name="b14172722081"></a>msg_type</strong> is <strong id="b1717312218819"><a name="b1717312218819"></a><a name="b1717312218819"></a>0</strong> or <strong id="b31731322781"><a name="b31731322781"></a><a name="b31731322781"></a>1</strong>.</p>
<a name="ul16848433145315"></a><a name="ul16848433145315"></a><ul id="ul16848433145315"><li>The value <strong id="b19721112612813"><a name="b19721112612813"></a><a name="b19721112612813"></a>1</strong> indicates setting the AICPU operator timeout value.</li><li>The value <strong id="b1689714016811"><a name="b1689714016811"></a><a name="b1689714016811"></a>0</strong> indicates querying the AICPU operator timeout value.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section49611431655"></a>**

```c
...
int ret;
int card_id = 0;
int dev_id = 0;
void *buf = NULL;
int buf_size = 10;
buf = calloc(buf_size, sizeof(char));
if (buf == NULL) {
printf("calloc buf failed.\n");
return -1;
}
ret = dcmi_set_device_info(card_id,dev_id,DCMI_MAIN_CMD_TS, DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE, buf, &buf_size);
if (ret != 0) {
printf("dcmi_set_device_info failed, ret = %d.\n", ret);
return -1;
}
return 0;
...
```

## DCMI\_MAIN\_CMD\_DEVICE\_SHARE Command<a name="EN-US_TOPIC_0000002546910443"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section19822105710305"></a>**

Enables or disables container sharing of a chip.

**Parameter Description<a name="section5671124612912"></a>**

<a name="en-us_topic_0257495783_table45028263"></a>
<table><thead align="left"><tr id="en-us_topic_0257495783_row60695621"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="en-us_topic_0257495783_p17398306"><a name="en-us_topic_0257495783_p17398306"></a><a name="en-us_topic_0257495783_p17398306"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.41%" id="mcps1.1.5.1.2"><p id="en-us_topic_0257495783_p67085535"><a name="en-us_topic_0257495783_p67085535"></a><a name="en-us_topic_0257495783_p67085535"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.470000000000002%" id="mcps1.1.5.1.3"><p id="p153645385214"><a name="p153645385214"></a><a name="p153645385214"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0257495783_p48266778"><a name="en-us_topic_0257495783_p48266778"></a><a name="en-us_topic_0257495783_p48266778"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row884163595218"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p121951513267"><a name="p121951513267"></a><a name="p121951513267"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p11956515261"><a name="p11956515261"></a><a name="p11956515261"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1919510562619"><a name="p1919510562619"></a><a name="p1919510562619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b28891528181619"><a name="b28891528181619"></a><a name="b28891528181619"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row31747823"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b111507124132939"><a name="b111507124132939"></a><a name="b111507124132939"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU: [0, <strong id="b122213491615"><a name="b122213491615"></a><a name="b122213491615"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row7743426585"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p15756282814"><a name="en-us_topic_0257495783_p15756282814"></a><a name="en-us_topic_0257495783_p15756282814"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p1574417263816"><a name="en-us_topic_0257495783_p1574417263816"></a><a name="en-us_topic_0257495783_p1574417263816"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1519518513263"><a name="p1519518513263"></a><a name="p1519518513263"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p466445534710"><a name="p466445534710"></a><a name="p466445534710"></a>DCMI_MAIN_CMD_DEVICE_SHARE</p>
<div class="note" id="note1218455521019"><a name="note1218455521019"></a><a name="note1218455521019"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p14728105710819"><a name="p14728105710819"></a><a name="p14728105710819"></a>For details about how to configure the container sharing function, see <a href="dcmi_set_device_share_enable.md">dcmi_set_device_share_enable Prototype</a>.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row42644663"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0257495783_p851813475811"><a name="en-us_topic_0257495783_p851813475811"></a><a name="en-us_topic_0257495783_p851813475811"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0257495783_p133891038900"><a name="en-us_topic_0257495783_p133891038900"></a><a name="en-us_topic_0257495783_p133891038900"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p17196155202616"><a name="p17196155202616"></a><a name="p17196155202616"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1528419185118"><a name="p1528419185118"></a><a name="p1528419185118"></a>typedef enum {</p>
<p id="p1228415916510"><a name="p1228415916510"></a><a name="p1228415916510"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON = 0,</p>
<p id="p1028409165114"><a name="p1028409165114"></a><a name="p1028409165114"></a>DCMI_DEVICE_SHARE_SUB_CMD_MAX,</p>
<p id="p328411917514"><a name="p328411917514"></a><a name="p328411917514"></a>} DCMI_DEVICE_SHARE_SUB_CMD;</p>
<div class="note" id="note690717511525"><a name="note690717511525"></a><a name="note690717511525"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p12648821111120"><a name="p12648821111120"></a><a name="p12648821111120"></a>Currently, this API supports only the <strong id="b166181651131610"><a name="b166181651131610"></a><a name="b166181651131610"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON</strong> command.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0257495783_row17526454687"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row19825197914"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p1231019570213"><a name="p1231019570213"></a><a name="p1231019570213"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p12310115715213"><a name="p12310115715213"></a><a name="p12310115715213"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p1531045710217"><a name="p1531045710217"></a><a name="p1531045710217"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p13107576214"><a name="p13107576214"></a><a name="p13107576214"></a>Length of the <strong id="b144178311179"><a name="b144178311179"></a><a name="b144178311179"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section283355715302"></a>**

<a name="table1985018574309"></a>
<table><thead align="left"><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b13649169101713"><a name="b13649169101713"></a><a name="b13649169101713"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None

**Restrictions<a name="section13645113118442"></a>**

- In the container sharing mode, the container is disabled by default after the system is restarted.
- If  **device\_id**  is set to  **0**  or  **1**, the container sharing enable flag is configured for both chips within the device.
- This API can be used in the PM + privileged container scenario.

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table08529574303"></a>
<table><thead align="left"><tr id="row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="p59011457173015"><a name="p59011457173015"></a><a name="p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="p159011357193019"><a name="p159011357193019"></a><a name="p159011357193019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="p1990165743011"><a name="p1990165743011"></a><a name="p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="row15743174685218"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="p17744144675215"><a name="p17744144675215"></a><a name="p17744144675215"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="p6898117165315"><a name="p6898117165315"></a><a name="p6898117165315"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="p789841705311"><a name="p789841705311"></a><a name="p789841705311"></a>unsigned int</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section49611431655"></a>**

```c
    ...
    int ret;
    int card_id = 0;
    int device_id = 0;
    enum dcmi_main_cmd  main_cmd = DCMI_MAIN_CMD_DEVICE_SHARE;
    unsigned int sub_cmd = DCMI_DEVICE_SHARE_SUB_CMD_COMMON;
    unsigned int enable_flag = 1;
    unsigned int size = sizeof(unsigned int);

    ret = dcmi_set_device_info(card_id, device_id, main_cmd, sub_cmd, (void *)&enable_flag, size);
    if (ret != DCMI_OK){
        // todo: Record logs.
        return ret;
    }
    ...
```

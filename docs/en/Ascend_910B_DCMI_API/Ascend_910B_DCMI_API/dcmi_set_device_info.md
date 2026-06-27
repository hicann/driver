# dcmi\_set\_device\_info<a name="EN-US_TOPIC_0000002515503882"></a>

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
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b57579094910281"><a name="b57579094910281"></a><a name="b57579094910281"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.28%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.7%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b438375595102424"><a name="b438375595102424"></a><a name="b438375595102424"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b922240948105317"><a name="b922240948105317"></a><a name="b922240948105317"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<p id="p12529132435912"><a name="p12529132435912"></a><a name="p12529132435912"></a>DCMI_MAIN_CMD_EX_CERT = 0x8003,</p>
<p id="p86483533216"><a name="p86483533216"></a><a name="p86483533216"></a>DCMI_MAIN_CMD_MAX</p>
<p id="p19641735163210"><a name="p19641735163210"></a><a name="p19641735163210"></a>};</p>
<p id="p12961111210401"><a name="p12961111210401"></a><a name="p12961111210401"></a>Only the main command words of the following modules are supported:</p>
<p id="p11730164003910"><a name="p11730164003910"></a><a name="p11730164003910"></a>DCMI_MAIN_CMD_LP // Main command word of the low power consumption module</p>
<p id="p630816245918"><a name="p630816245918"></a><a name="p630816245918"></a>DCMI_MAIN_CMD_TS // Main command word of the task scheduling module</p>
<p id="p5295114993915"><a name="p5295114993915"></a><a name="p5295114993915"></a>DCMI_MAIN_CMD_QOS // Main command word of the QoS module</p>
<p id="p10587195583910"><a name="p10587195583910"></a><a name="p10587195583910"></a></p>
<p id="en-us_topic_0000001206307236_p1516935634520"><a name="en-us_topic_0000001206307236_p1516935634520"></a><a name="en-us_topic_0000001206307236_p1516935634520"></a>DCMI_MAIN_CMD_EX_CERT // Main command word of the certificate management module</p>
<p id="p1923195813395"><a name="p1923195813395"></a><a name="p1923195813395"></a>DCMI_MAIN_CMD_DEVICE_SHARE // Main command word for container sharing</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b41527074785538"><a name="b41527074785538"></a><a name="b41527074785538"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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
    //todo: Record logs.
    return ret;
}
...
```

## DCMI\_MAIN\_CMD\_LP Command<a name="EN-US_TOPIC_0000002515503756"></a>

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
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p43098579215"><a name="p43098579215"></a><a name="p43098579215"></a>Device ID. The supported IDs can be obtained by calling <strong id="b17497390910282"><a name="b17497390910282"></a><a name="b17497390910282"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row183091657724"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p430910572213"><a name="p430910572213"></a><a name="p430910572213"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p83092571127"><a name="p83092571127"></a><a name="p83092571127"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p93093571822"><a name="p93093571822"></a><a name="p93093571822"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p15309157129"><a name="p15309157129"></a><a name="p15309157129"></a>Chip ID, which can be obtained by calling <strong id="b1074858027102425"><a name="b1074858027102425"></a><a name="b1074858027102425"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p20309757127"><a name="p20309757127"></a><a name="p20309757127"></a>NPU: [0, <strong id="b1096238212105318"><a name="b1096238212105318"></a><a name="b1096238212105318"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
    // Obtain the reason for the current frequency reduction.
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
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b161492325385539"><a name="b161492325385539"></a><a name="b161492325385539"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section135813338518"></a>**

None.

**Restrictions<a name="section13120154195114"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table152227367311"></a>
<table><thead align="left"><tr id="row102361036833"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p142361636536"><a name="p142361636536"></a><a name="p142361636536"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p172364361439"><a name="p172364361439"></a><a name="p172364361439"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p22369362034"><a name="p22369362034"></a><a name="p22369362034"></a>Size</p>
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

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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

## DCMI\_MAIN\_CMD\_QOS Command<a name="EN-US_TOPIC_0000002546983767"></a>

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
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b145072917410283"><a name="b145072917410283"></a><a name="b145072917410283"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row4195175152616"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b1717365424102426"><a name="b1717365424102426"></a><a name="b1717365424102426"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU: [0, <strong id="b644105338105319"><a name="b644105338105319"></a><a name="b644105338105319"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b149779600785540"><a name="b149779600785540"></a><a name="b149779600785540"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section122651535145210"></a>**

None.

**Restrictions<a name="section72205384522"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table590205182617"></a>
<table><thead align="left"><tr id="row919713512265"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p619712522612"><a name="p619712522612"></a><a name="p619712522612"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="p1819814542619"><a name="p1819814542619"></a><a name="p1819814542619"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="p1119815515263"><a name="p1119815515263"></a><a name="p1119815515263"></a>Size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p31981351265"><a name="p31981351265"></a><a name="p31981351265"></a>Description</p>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul101981155262"></a><a name="ul101981155262"></a><ul id="ul101981155262"><li><strong id="b9201082939598"><a name="b9201082939598"></a><a name="b9201082939598"></a>mpamid</strong>: The value range is [0, 127].</li><li><strong id="b564020088527"><a name="b564020088527"></a><a name="b564020088527"></a>bw_high</strong>: high waterline (GB/s). The value range is [0, 1638]. Note: The upper limit of the value range varies with the DDR frequency. The formula is <strong id="b9742812241"><a name="b9742812241"></a><a name="b9742812241"></a>bw_high_max</strong> = <strong id="b13852822415"><a name="b13852822415"></a><a name="b13852822415"></a>ddr_freq</strong> x 2 x <strong id="b17811289246"><a name="b17811289246"></a><a name="b17811289246"></a>max_chn</strong> x 8/1000. The actual dominant frequency and number of channels prevail.</li><li><strong id="b162328848895921"><a name="b162328848895921"></a><a name="b162328848895921"></a>bw_low</strong>: low waterline (GB/s). The value range is [0, <strong id="b183737135695921"><a name="b183737135695921"></a><a name="b183737135695921"></a>bw_high</strong>].</li><li><strong id="b18043488858527"><a name="b18043488858527"></a><a name="b18043488858527"></a>hardlimit</strong>:<a name="ul1282591431120"></a><a name="ul1282591431120"></a><ul id="ul1282591431120"><li><strong id="b20806785238527"><a name="b20806785238527"></a><a name="b20806785238527"></a>1</strong>: The function is enabled.</li><li><strong id="b16367494638527"><a name="b16367494638527"></a><a name="b16367494638527"></a>0</strong>: The function is disabled.</li></ul>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1519965122612"></a><a name="ul1519965122612"></a><ul id="ul1519965122612"><li><strong id="b144052111124"><a name="b144052111124"></a><a name="b144052111124"></a>master</strong>: master ID. The supported configuration items are <strong id="b340517119122"><a name="b340517119122"></a><a name="b340517119122"></a>vdec=1</strong>, <strong id="b04051211201218"><a name="b04051211201218"></a><a name="b04051211201218"></a>vpc=2</strong>, <strong id="b640511118122"><a name="b640511118122"></a><a name="b640511118122"></a>jpge=3</strong>, <strong id="b1640571111210"><a name="b1640571111210"></a><a name="b1640571111210"></a>jpgd=4</strong>, <strong id="b19405121141210"><a name="b19405121141210"></a><a name="b19405121141210"></a>pcie=7</strong>, and <strong id="b4405211191211"><a name="b4405211191211"></a><a name="b4405211191211"></a>sdma=13</strong>.</li><li><strong id="b13513375629598"><a name="b13513375629598"></a><a name="b13513375629598"></a>mpamid</strong>: The value range is [0, 127].</li><li><strong id="b10581380078527"><a name="b10581380078527"></a><a name="b10581380078527"></a>qos</strong>: bandwidth scheduling priority. The value range is [0, 7]. The value 0 indicates hardlimit QoS, and the value 7 indicates green channel QoS.</li><li><strong id="b1852629152712"><a name="b1852629152712"></a><a name="b1852629152712"></a>pmg</strong>: <strong id="b885314298276"><a name="b885314298276"></a><a name="b885314298276"></a>mpamid</strong> group. The value range is [0, 3].</li><li><strong id="b1220243312717"><a name="b1220243312717"></a><a name="b1220243312717"></a>bitmap</strong>: not supported due to framework restrictions.</li></ul>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="p72381261113"><a name="p72381261113"></a><a name="p72381261113"></a><strong id="b8349162131220"><a name="b8349162131220"></a><a name="b8349162131220"></a>interval</strong>: bandwidth sampling interval (unit: μs). The value must be greater than 1000.</p>
<a name="ul14758119151018"></a><a name="ul14758119151018"></a><ul id="ul14758119151018"><li><strong id="b461183812284"><a name="b461183812284"></a><a name="b461183812284"></a>mode</strong>: bandwidth statistics mode. <strong id="b561112386288"><a name="b561112386288"></a><a name="b561112386288"></a>0</strong>: automatic mode; <strong id="b1961173802817"><a name="b1961173802817"></a><a name="b1961173802817"></a>1</strong>: manual mode. The configuration takes effect only on the MATA/DHA side instead of the DDRC side. Only the manual mode is supported.</li><li><strong id="b464082716124"><a name="b464082716124"></a><a name="b464082716124"></a>method</strong>: node for bandwidth statistics collection. <strong id="b1464142791217"><a name="b1464142791217"></a><a name="b1464142791217"></a>0</strong>: MATA/DHA.</li><li><strong id="b16652179878527"><a name="b16652179878527"></a><a name="b16652179878527"></a>state</strong>: bandwidth sampling command<a name="ul19778747111012"></a><a name="ul19778747111012"></a><ul id="ul19778747111012"><li><strong id="b2086909288527"><a name="b2086909288527"></a><a name="b2086909288527"></a>2</strong>: bandwidth sampling enabled</li><li><strong id="b8382751958527"><a name="b8382751958527"></a><a name="b8382751958527"></a>1</strong>: initialization</li><li><strong id="b19016052318527"><a name="b19016052318527"></a><a name="b19016052318527"></a>0</strong>: bandwidth sampling disabled</li></ul>
</li><li><strong id="b153654021315"><a name="b153654021315"></a><a name="b153654021315"></a>target_set</strong>: sampling object mpamid. The maximum number varies with the Ascend AI Processor and is up to 16.</li><li><strong id="b25651543122916"><a name="b25651543122916"></a><a name="b25651543122916"></a>cnt</strong>: number of valid bandwidth statistics objects. The maximum number is 16.</li></ul>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1520114516263"></a><a name="ul1520114516263"></a><ul id="ul1520114516263"><li><strong id="b13419158121319"><a name="b13419158121319"></a><a name="b13419158121319"></a>enable</strong>: whether to enable the QoS function.<a name="ul9734199111712"></a><a name="ul9734199111712"></a><ul id="ul9734199111712"><li><strong id="b17009486108527"><a name="b17009486108527"></a><a name="b17009486108527"></a>0</strong>: disabled</li><li><strong id="b20000229768527"><a name="b20000229768527"></a><a name="b20000229768527"></a>1</strong>: enabled</li></ul>
</li><li><strong id="b21243501228527"><a name="b21243501228527"></a><a name="b21243501228527"></a>autoqos_fuse_en</strong>: whether to enable QoS fusion. Currently, <strong id="b14121423418527"><a name="b14121423418527"></a><a name="b14121423418527"></a>autoqos_fuse_en</strong> cannot be set. The default value is 1.<a name="ul483832316173"></a><a name="ul483832316173"></a><ul id="ul483832316173"><li><strong id="b2512216178527"><a name="b2512216178527"></a><a name="b2512216178527"></a>0</strong>: QoS fusion is disabled.</li><li><strong id="b19279675568527"><a name="b19279675568527"></a><a name="b19279675568527"></a>1</strong>: QoS fusion starts.</li></ul>
</li><li><strong id="b7756132215306"><a name="b7756132215306"></a><a name="b7756132215306"></a>mpamqos_fuse_mode</strong>: QoS fusion mode. This parameter takes effect when <strong id="b77563221301"><a name="b77563221301"></a><a name="b77563221301"></a>autoqos_fuse_en</strong> is enabled.<a name="ul469217432179"></a><a name="ul469217432179"></a><ul id="ul469217432179"><li><strong id="b20358553478527"><a name="b20358553478527"></a><a name="b20358553478527"></a>0</strong>: average fusion</li><li><strong id="b10880113985317"><a name="b10880113985317"></a><a name="b10880113985317"></a>1</strong>: maximum value between the associated QoS and MPAM QoS</li><li><strong id="b2609244598527"><a name="b2609244598527"></a><a name="b2609244598527"></a>2</strong>: associated QoS as MPAM QoS</li></ul>
</li><li><strong id="b11077536788527"><a name="b11077536788527"></a><a name="b11077536788527"></a>mpam_subtype</strong>: bandwidth statistics mode<a name="ul1691317543171"></a><a name="ul1691317543171"></a><ul id="ul1691317543171"><li><strong id="b16881253778527"><a name="b16881253778527"></a><a name="b16881253778527"></a>0</strong>: read and write bandwidth statistics</li><li><strong id="b9574734638527"><a name="b9574734638527"></a><a name="b9574734638527"></a>1</strong>: write bandwidth statistics</li><li><strong id="b15017171588527"><a name="b15017171588527"></a><a name="b15017171588527"></a>2</strong>: read bandwidth statistics</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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

## DCMI\_MAIN\_CMD\_EX\_CERT Command<a name="EN-US_TOPIC_0000002546903749"></a>

**Prototype<a name="section280203719273"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section7351204942711"></a>**

Configures the TLS certificate.

**Parameter Description<a name="section13117595271"></a>**

<a name="table1212611922719"></a>
<table><thead align="left"><tr id="row1725841910272"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="p6258151914271"><a name="p6258151914271"></a><a name="p6258151914271"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.2"><p id="p325881915274"><a name="p325881915274"></a><a name="p325881915274"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.189999999999998%" id="mcps1.1.5.1.3"><p id="p825881922713"><a name="p825881922713"></a><a name="p825881922713"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="62.629999999999995%" id="mcps1.1.5.1.4"><p id="p1925851972714"><a name="p1925851972714"></a><a name="p1925851972714"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row2259131912277"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p10259121972712"><a name="p10259121972712"></a><a name="p10259121972712"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p425991914275"><a name="p425991914275"></a><a name="p425991914275"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p20259111918272"><a name="p20259111918272"></a><a name="p20259111918272"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p7259101910272"><a name="p7259101910272"></a><a name="p7259101910272"></a>Device ID. The supported IDs can be obtained by calling <strong id="b3380640163515"><a name="b3380640163515"></a><a name="b3380640163515"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row425911918273"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p17259111992716"><a name="p17259111992716"></a><a name="p17259111992716"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p122590195273"><a name="p122590195273"></a><a name="p122590195273"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p725912195278"><a name="p725912195278"></a><a name="p725912195278"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p4259141982712"><a name="p4259141982712"></a><a name="p4259141982712"></a>Chip ID, which can be obtained by calling <strong id="b19294104323513"><a name="b19294104323513"></a><a name="b19294104323513"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p19259121912278"><a name="p19259121912278"></a><a name="p19259121912278"></a>NPU: [0, <strong id="b113973992105321"><a name="b113973992105321"></a><a name="b113973992105321"></a>device_id_max</strong> – 1]</p>
<p id="p4865204631719"><a name="p4865204631719"></a><a name="p4865204631719"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row1225918191279"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p13259131972713"><a name="p13259131972713"></a><a name="p13259131972713"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p14259161942711"><a name="p14259161942711"></a><a name="p14259161942711"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p182599197275"><a name="p182599197275"></a><a name="p182599197275"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p112592191279"><a name="p112592191279"></a><a name="p112592191279"></a>DCMI_MAIN_CMD_EX_CERT</p>
</td>
</tr>
<tr id="row15259319182712"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p162602195273"><a name="p162602195273"></a><a name="p162602195273"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p4260161911275"><a name="p4260161911275"></a><a name="p4260161911275"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p526081962717"><a name="p526081962717"></a><a name="p526081962717"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p860220171714"><a name="p860220171714"></a><a name="p860220171714"></a>typedef enum {</p>
<p id="p86022010177"><a name="p86022010177"></a><a name="p86022010177"></a>DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY = 0, // Initialization of the TLS certificate (used to obtain the CSR)</p>
<p id="p360172071712"><a name="p360172071712"></a><a name="p360172071712"></a>DCMI_CERT_SUB_CMD_INIT_RESERVE, // Reserved field for initialization</p>
<p id="p060172071719"><a name="p060172071719"></a><a name="p060172071719"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO, // Preconfiguration, update, or obtaining of the TLS certificate information</p>
<p id="p186062061716"><a name="p186062061716"></a><a name="p186062061716"></a>DCMI_CERT_SUB_CMD_MAX,</p>
<p id="p66012200175"><a name="p66012200175"></a><a name="p66012200175"></a>} DCMI_EX_CERT_SUB_CMD;</p>
<p id="p102606193279"><a name="p102606193279"></a><a name="p102606193279"></a>Only <strong id="b20108162954818"><a name="b20108162954818"></a><a name="b20108162954818"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO</strong> is supported.</p>
</td>
</tr>
<tr id="row14260919172712"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p5260719122714"><a name="p5260719122714"></a><a name="p5260719122714"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p826014191272"><a name="p826014191272"></a><a name="p826014191272"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p10260181942719"><a name="p10260181942719"></a><a name="p10260181942719"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p1226013197274"><a name="p1226013197274"></a><a name="p1226013197274"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row92604199273"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p112604198273"><a name="p112604198273"></a><a name="p112604198273"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p112608196276"><a name="p112608196276"></a><a name="p112608196276"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p22605196271"><a name="p22605196271"></a><a name="p22605196271"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p12260719112716"><a name="p12260719112716"></a><a name="p12260719112716"></a>Length of the <strong id="b751535155214"><a name="b751535155214"></a><a name="b751535155214"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table20149119132713"></a>
<table><thead align="left"><tr id="row62609194278"><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.2.5.1.1"><p id="p02603193273"><a name="p02603193273"></a><a name="p02603193273"></a><strong id="b426091952718"><a name="b426091952718"></a><a name="b426091952718"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="42.11%" id="mcps1.2.5.1.2"><p id="p92617193277"><a name="p92617193277"></a><a name="p92617193277"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="22.900000000000002%" id="mcps1.2.5.1.3"><p id="p2026117191273"><a name="p2026117191273"></a><a name="p2026117191273"></a>Size</p>
</th>
<th class="cellrowborder" valign="top" width="8.97%" id="mcps1.2.5.1.4"><p id="p1226114195270"><a name="p1226114195270"></a><a name="p1226114195270"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1126110195279"><td class="cellrowborder" valign="top" width="26.02%" headers="mcps1.2.5.1.1 "><p id="p202611619122710"><a name="p202611619122710"></a><a name="p202611619122710"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO</p>
</td>
<td class="cellrowborder" valign="top" width="42.11%" headers="mcps1.2.5.1.2 "><p id="p5261619102711"><a name="p5261619102711"></a><a name="p5261619102711"></a>struct dcmi_certs_chain_data {</p>
<p id="p16261171910275"><a name="p16261171910275"></a><a name="p16261171910275"></a>unsigned int count; // Number of certificates</p>
<p id="p132611196275"><a name="p132611196275"></a><a name="p132611196275"></a>unsigned int data_len[MAX_CERT_COUNT]; // Certificate length</p>
<p id="p2026191912717"><a name="p2026191912717"></a><a name="p2026191912717"></a>unsigned char data[0]; // Certificate content</p>
<p id="p1526115198272"><a name="p1526115198272"></a><a name="p1526115198272"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="22.900000000000002%" headers="mcps1.2.5.1.3 "><p id="p1261319192718"><a name="p1261319192718"></a><a name="p1261319192718"></a>sizeof(struct dcmi_certs_chain_data) + cert_count * NPU_CERT_MAX_SIZE</p>
</td>
<td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.2.5.1.4 "><p id="p14261181922711"><a name="p14261181922711"></a><a name="p14261181922711"></a>None.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section5782161012308"></a>**

<a name="table201555196276"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002515343916_b154714878985455"><a name="en-us_topic_0000002515343916_b154714878985455"></a><a name="en-us_topic_0000002515343916_b154714878985455"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section191916302309"></a>**

None.

**Restrictions<a name="section598124210309"></a>**

**Table  2** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section14483105193112"></a>**

```c
...
int ret;
int card_id = 0;
int device_id = 0;
struct dcmi_certs_chain_data certs_chain_data ={0};
DCMI_MAIN_CMD main_cmd = DCMI_MAIN_CMD_EX_CERT;
unsigned int sub_cmd = DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY;
unsigned int size = sizeof(struct dcmi_certs_chain_data) + cert_count * NPU_CERT_MAX_SIZE;
ret = dcmi_set_device_info(card_id, device_id, main_cmd, sub_cmd, (void *)&certs_chain_data, size);
if (ret) {
    // TODO
}
// TODO
...
```

## DCMI\_MAIN\_CMD\_TS Command<a name="EN-US_TOPIC_0000002546983729"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section1181162344514"></a>**

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
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p1290095773011"><a name="p1290095773011"></a><a name="p1290095773011"></a>Device ID. The supported IDs can be obtained by calling <strong id="b80134456310286"><a name="b80134456310286"></a><a name="b80134456310286"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1990019577303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p109001457133015"><a name="p109001457133015"></a><a name="p109001457133015"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p1900175783013"><a name="p1900175783013"></a><a name="p1900175783013"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p13900185710307"><a name="p13900185710307"></a><a name="p13900185710307"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p18900957193015"><a name="p18900957193015"></a><a name="p18900957193015"></a>Chip ID, which can be obtained by calling <strong id="b1807372906102430"><a name="b1807372906102430"></a><a name="b1807372906102430"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p390015577304"><a name="p390015577304"></a><a name="p390015577304"></a>NPU chip: [0, <strong id="b119251317191"><a name="b119251317191"></a><a name="b119251317191"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="en-us_topic_0000002481387068_codeblock84586272352"><a name="en-us_topic_0000002481387068_codeblock84586272352"></a><a name="en-us_topic_0000002481387068_codeblock84586272352"></a>typedef enum {
// Obtain the single-core utilization of the AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_AICORE_UTILIZATION_RATE = 0,
// Obtain the single-core utilization of the Vector Core/Obtain the utilization of the Vector unit in the single AI Core. The normal value ranges from 0 to 100.
DCMI_TS_SUB_CMD_VECTORCORE_UTILIZATION_RATE,
// Specify the FFTS or FFTS+ type. The value <strong id="en-us_topic_0000002481387068_b45091614175311"><a name="en-us_topic_0000002481387068_b45091614175311"></a><a name="en-us_topic_0000002481387068_b45091614175311"></a>0</strong> indicates FFTS, and the value <strong id="en-us_topic_0000002481387068_b6337192212536"><a name="en-us_topic_0000002481387068_b6337192212536"></a><a name="en-us_topic_0000002481387068_b6337192212536"></a>1</strong> indicates FFTS+.
DCMI_TS_SUB_CMD_FFTS_TYPE,
// Set the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_SET_FAULT_MASK,
// Obtain the hardware-level mask to block AI Core errors.
DCMI_TS_SUB_CMD_GET_FAULT_MASK,
// Set the operator timeout scale, with a valid range of [20, 32].
DCMI_TS_SUB_CMD_COMMON_MSG,
DCMI_TS_SUB_CMD_MAX,
} DCMI_TS_SUB_CMD;</pre>
<p id="en-us_topic_0000002481387068_p7900115703014"><a name="en-us_topic_0000002481387068_p7900115703014"></a><a name="en-us_topic_0000002481387068_p7900115703014"></a>Only <strong id="en-us_topic_0000002481387068_b247914324196"><a name="en-us_topic_0000002481387068_b247914324196"></a><a name="en-us_topic_0000002481387068_b247914324196"></a>DCMI_TS_SUB_CMD_COMMON_MSG</strong> is supported.</p>
</td>
</tr>
<tr id="row1190010575303"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p1190018574307"><a name="p1190018574307"></a><a name="p1190018574307"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p19007577307"><a name="p19007577307"></a><a name="p19007577307"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p17900175711302"><a name="p17900175711302"></a><a name="p17900175711302"></a>void *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p390012575308"><a name="p390012575308"></a><a name="p390012575308"></a>For details, see the restrictions.</p>
</td>
</tr>
<tr id="row16900145719304"><td class="cellrowborder" valign="top" width="17.17171717171717%" headers="mcps1.1.5.1.1 "><p id="p9900155716309"><a name="p9900155716309"></a><a name="p9900155716309"></a>size</p>
</td>
<td class="cellrowborder" valign="top" width="15.151515151515152%" headers="mcps1.1.5.1.2 "><p id="p0900185719304"><a name="p0900185719304"></a><a name="p0900185719304"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="19.19191919191919%" headers="mcps1.1.5.1.3 "><p id="p6901257173010"><a name="p6901257173010"></a><a name="p6901257173010"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.484848484848484%" headers="mcps1.1.5.1.4 "><p id="p090113577301"><a name="p090113577301"></a><a name="p090113577301"></a>Length of the <strong id="b9994134116194"><a name="b9994134116194"></a><a name="b9994134116194"></a>buf</strong> array/Length of the returned result.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section5782161012308"></a>**

<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002515343916_b154714878985455"><a name="en-us_topic_0000002515343916_b154714878985455"></a><a name="en-us_topic_0000002515343916_b154714878985455"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None.

**Restrictions<a name="section5948183954914"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table08529574303"></a>
<table><thead align="left"><tr id="en-us_topic_0000002481387068_row19012578309"><th class="cellrowborder" valign="top" width="39.269999999999996%" id="mcps1.2.4.1.1"><p id="en-us_topic_0000002481387068_p59011457173015"><a name="en-us_topic_0000002481387068_p59011457173015"></a><a name="en-us_topic_0000002481387068_p59011457173015"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="36.96%" id="mcps1.2.4.1.2"><p id="en-us_topic_0000002481387068_p159011357193019"><a name="en-us_topic_0000002481387068_p159011357193019"></a><a name="en-us_topic_0000002481387068_p159011357193019"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="23.77%" id="mcps1.2.4.1.3"><p id="en-us_topic_0000002481387068_p1990165743011"><a name="en-us_topic_0000002481387068_p1990165743011"></a><a name="en-us_topic_0000002481387068_p1990165743011"></a>size</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002481387068_row16617143112276"><td class="cellrowborder" valign="top" width="39.269999999999996%" headers="mcps1.2.4.1.1 "><p id="en-us_topic_0000002481387068_p1047117132015"><a name="en-us_topic_0000002481387068_p1047117132015"></a><a name="en-us_topic_0000002481387068_p1047117132015"></a>DCMI_TS_SUB_CMD_COMMON_MSG</p>
</td>
<td class="cellrowborder" valign="top" width="36.96%" headers="mcps1.2.4.1.2 "><p id="en-us_topic_0000002481387068_p19469111244813"><a name="en-us_topic_0000002481387068_p19469111244813"></a><a name="en-us_topic_0000002481387068_p19469111244813"></a>struct ts_dcmi_ctrl_msg_body_t {</p>
<p id="en-us_topic_0000002481387068_p1246961219488"><a name="en-us_topic_0000002481387068_p1246961219488"></a><a name="en-us_topic_0000002481387068_p1246961219488"></a>unsigned int msg_type;</p>
<p id="en-us_topic_0000002481387068_p246915123487"><a name="en-us_topic_0000002481387068_p246915123487"></a><a name="en-us_topic_0000002481387068_p246915123487"></a>union {</p>
<p id="en-us_topic_0000002481387068_p1746901219481"><a name="en-us_topic_0000002481387068_p1746901219481"></a><a name="en-us_topic_0000002481387068_p1746901219481"></a>ts_dcmi_task_timeout_t set_task_timeout_info;</p>
<p id="en-us_topic_0000002481387068_p64691512154816"><a name="en-us_topic_0000002481387068_p64691512154816"></a><a name="en-us_topic_0000002481387068_p64691512154816"></a>ts_dcmi_task_timeout_t get_task_timeout_info;</p>
<p id="en-us_topic_0000002481387068_p13469131244812"><a name="en-us_topic_0000002481387068_p13469131244812"></a><a name="en-us_topic_0000002481387068_p13469131244812"></a>} u;</p>
<p id="en-us_topic_0000002481387068_p134691512204817"><a name="en-us_topic_0000002481387068_p134691512204817"></a><a name="en-us_topic_0000002481387068_p134691512204817"></a>};</p>
<p id="en-us_topic_0000002481387068_p1719316326501"><a name="en-us_topic_0000002481387068_p1719316326501"></a><a name="en-us_topic_0000002481387068_p1719316326501"></a>The ts_dcmi_task_timeout_t structure is as follows:</p>
<p id="en-us_topic_0000002481387068_p522516213502"><a name="en-us_topic_0000002481387068_p522516213502"></a><a name="en-us_topic_0000002481387068_p522516213502"></a>typedef struct {</p>
<p id="en-us_topic_0000002481387068_p32251323501"><a name="en-us_topic_0000002481387068_p32251323501"></a><a name="en-us_topic_0000002481387068_p32251323501"></a>unsigned int timeout_limit_exp; // Value range: [20, 32]</p>
<p id="en-us_topic_0000002481387068_p222512155013"><a name="en-us_topic_0000002481387068_p222512155013"></a><a name="en-us_topic_0000002481387068_p222512155013"></a>unsigned char rsev[TS_RSEV_MAX_LENTH]; // <strong id="en-us_topic_0000002481387068_b370172521218"><a name="en-us_topic_0000002481387068_b370172521218"></a><a name="en-us_topic_0000002481387068_b370172521218"></a>TS_RSEV_MAX_LENTH</strong> is <strong id="en-us_topic_0000002481387068_b3341207123"><a name="en-us_topic_0000002481387068_b3341207123"></a><a name="en-us_topic_0000002481387068_b3341207123"></a>36</strong>.</p>
<p id="en-us_topic_0000002481387068_p10225725506"><a name="en-us_topic_0000002481387068_p10225725506"></a><a name="en-us_topic_0000002481387068_p10225725506"></a>} ts_dcmi_task_timeout_t;</p>
</td>
<td class="cellrowborder" valign="top" width="23.77%" headers="mcps1.2.4.1.3 "><p id="en-us_topic_0000002481387068_p19359252485"><a name="en-us_topic_0000002481387068_p19359252485"></a><a name="en-us_topic_0000002481387068_p19359252485"></a>As an input, it indicates the <strong id="en-us_topic_0000002481387068_b3071473511"><a name="en-us_topic_0000002481387068_b3071473511"></a><a name="en-us_topic_0000002481387068_b3071473511"></a>buf</strong> size. The <strong id="en-us_topic_0000002481387068_b121294196358"><a name="en-us_topic_0000002481387068_b121294196358"></a><a name="en-us_topic_0000002481387068_b121294196358"></a>buf</strong> must be at least 44 bytes.</p>
<p id="en-us_topic_0000002481387068_p19218195310"><a name="en-us_topic_0000002481387068_p19218195310"></a><a name="en-us_topic_0000002481387068_p19218195310"></a><strong id="en-us_topic_0000002481387068_b0381172911351"><a name="en-us_topic_0000002481387068_b0381172911351"></a><a name="en-us_topic_0000002481387068_b0381172911351"></a>msg_type</strong> is <strong id="en-us_topic_0000002481387068_b19545193519351"><a name="en-us_topic_0000002481387068_b19545193519351"></a><a name="en-us_topic_0000002481387068_b19545193519351"></a>0</strong> or <strong id="en-us_topic_0000002481387068_b6752123793511"><a name="en-us_topic_0000002481387068_b6752123793511"></a><a name="en-us_topic_0000002481387068_b6752123793511"></a>1</strong>.</p>
<a name="en-us_topic_0000002481387068_ul16848433145315"></a><a name="en-us_topic_0000002481387068_ul16848433145315"></a><ul id="en-us_topic_0000002481387068_ul16848433145315"><li>The value <strong id="en-us_topic_0000002481387068_b131321947183514"><a name="en-us_topic_0000002481387068_b131321947183514"></a><a name="en-us_topic_0000002481387068_b131321947183514"></a>1</strong> indicates setting the AICPU operator timeout value.</li><li>The value <strong id="en-us_topic_0000002481387068_b121079310011"><a name="en-us_topic_0000002481387068_b121079310011"></a><a name="en-us_topic_0000002481387068_b121079310011"></a>0</strong> indicates querying the AICPU operator timeout value.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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

## DCMI\_MAIN\_CMD\_DEVICE\_SHARE Command<a name="EN-US_TOPIC_0000002546903729"></a>

**Prototype<a name="section782265716308"></a>**

**int dcmi\_set\_device\_info\(int card\_id, int device\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section156751813192414"></a>**

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
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p1619510511265"><a name="p1619510511265"></a><a name="p1619510511265"></a>Device ID. The supported IDs can be obtained by calling <strong id="b179509820210287"><a name="b179509820210287"></a><a name="b179509820210287"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row31747823"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p161951552616"><a name="p161951552616"></a><a name="p161951552616"></a>Chip ID, which can be obtained by calling <strong id="b964726573102431"><a name="b964726573102431"></a><a name="b964726573102431"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p8195155132618"><a name="p8195155132618"></a><a name="p8195155132618"></a>NPU chip: [0, <strong id="b1452797047111936"><a name="b1452797047111936"></a><a name="b1452797047111936"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<div class="note" id="note690717511525"><a name="note690717511525"></a><a name="note690717511525"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p12648821111120"><a name="p12648821111120"></a><a name="p12648821111120"></a>Currently, this API supports only the <strong id="b010103817216"><a name="b010103817216"></a><a name="b010103817216"></a>DCMI_DEVICE_SHARE_SUB_CMD_COMMON</strong> command.</p>
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
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p13107576214"><a name="p13107576214"></a><a name="p13107576214"></a>Length of the <strong id="b176572043152117"><a name="b176572043152117"></a><a name="b176572043152117"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section283355715302"></a>**

<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002515343916_b154714878985455"><a name="en-us_topic_0000002515343916_b154714878985455"></a><a name="en-us_topic_0000002515343916_b154714878985455"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section6438163417415"></a>**

None.

**Restrictions<a name="section13645113118442"></a>**

- After the container sharing mode is set, the container is disabled by default after system restart.
- This API can be used in PM + privileged containers.

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

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section593717142277"></a>**

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

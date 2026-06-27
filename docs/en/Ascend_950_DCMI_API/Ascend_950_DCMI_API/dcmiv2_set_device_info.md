# dcmiv2\_set\_device\_info<a name="EN-US_TOPIC_0000002314204966"></a>

**Prototype<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412077"></a>**

**int dcmiv2\_set\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412078"></a>**

Sets device information, including the information about each module.

**Parameter Description<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412079"></a>**

<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="11.81%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="56.169999999999995%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="11.81%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p5522164215178"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="11.81%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p17522114220174"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p179311148415"></a>CMD information, which is used to obtain the information about the corresponding module.</p>
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
<p id="p1417711130499"><a name="p1417711130499"></a><a name="p1417711130499"></a>Only the following main command words are supported:</p>
<p id="p415610390439"><a name="p415610390439"></a><a name="p415610390439"></a>DCMI_MAIN_CMD_LP // Main command word of the low power consumption module</p>
<p id="p8290114219438"><a name="p8290114219438"></a><a name="p8290114219438"></a>DCMI_MAIN_CMD_QOS // Main command word of the QoS module</p>
<p id="en-us_topic_0000001206307236_p1516935634520"><a name="en-us_topic_0000001206307236_p1516935634520"></a><a name="en-us_topic_0000001206307236_p1516935634520"></a>DCMI_MAIN_CMD_VDEV_MNG // Main command word of the <span id="ph178169236327"><a name="ph178169236327"></a><a name="ph178169236327"></a>Ascend  Virtual Instance (AVI)</span> module</p>
<p id="p133381945154312"><a name="p133381945154312"></a><a name="p133381945154312"></a>DCMI_MAIN_CMD_EX_CERT // Main command word of the certificate management module</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row131655372019"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p19161539205"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1816115315209"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="11.81%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1216853142018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="p96461212173514"><a name="p96461212173514"></a><a name="p96461212173514"></a>For details, see the function description in the subsections.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row9864105062010"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p8864185062018"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p886417500202"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="11.81%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1386445092020"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p15864145012200"></a>Device information buffer.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_row177483489204"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p7749184816202"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p0749104811207"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="11.81%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p1374944862018"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="56.169999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"></a><a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_p074915488209"></a>Length of the <strong id="en-us_topic_0000001206307236_b0402131112418"><a name="en-us_topic_0000001206307236_b0402131112418"></a><a name="en-us_topic_0000001206307236_b0402131112418"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206307236_en-us_topic_0000001178054672_en-us_topic_0000001147964365_toc533412083"></a>**

```c
...
int ret = 0;
int dev_id = 0;
int buf = 0;
unsigned int size = sizeof(int);
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_LP, 0, (const void *)&buf, size);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

- **[DCMI\_MAIN\_CMD\_LP](#EN-US_TOPIC_0000002348043981)**  
- **[DCMI\_MAIN\_CMD\_QOS](#EN-US_TOPIC_0000002314204790)**  
- **[DCMI\_MAIN\_CMD\_VDEV\_MNG](#EN-US_TOPIC_0000002314045190)**  
- **[DCMI\_MAIN\_CMD\_EX\_CERT](#EN-US_TOPIC_0000002541188795)**  

## DCMI\_MAIN\_CMD\_LP<a id="EN-US_TOPIC_0000002348043981"></a>

**Prototype<a name="section152647575211"></a>**

**int dcmiv2\_set\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

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
<tbody><tr id="row183091657724"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p430910572213"><a name="p430910572213"></a><a name="p430910572213"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p83092571127"><a name="p83092571127"></a><a name="p83092571127"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p93093571822"><a name="p93093571822"></a><a name="p93093571822"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
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
DCMI_LP_SUB_CMD_AICORE_VOLTAGE_CURRENT = 0, // Obtain the register values indicating the voltage and current of the AI Core.
DCMI_LP_SUB_CMD_HYBIRD_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the Hybird.
DCMI_LP_SUB_CMD_TAISHAN_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the CPU.
DCMI_LP_SUB_CMD_DDR_VOLTAGE_CURRENT, // Obtain the register values indicating the voltage and current of the DDR.
DCMI_LP_SUB_CMD_ACG, // Obtain the count of ACG frequency modulations.
DCMI_LP_SUB_CMD_STATUS, // Obtain the overall low-power status.
DCMI_LP_SUB_CMD_TOPS_DETAILS, // Obtain all working levels.
DCMI_LP_SUB_CMD_SET_WORK_TOPS, // Set the working level.
DCMI_LP_SUB_CMD_GET_WORK_TOPS, // Obtain the current working level.
DCMI_LP_SUB_CMD_AICORE_FREQREDUC_CAUSE, // Obtain the reason for the current frequency reduction.
DCMI_LP_SUB_CMD_GET_POWER_INFO,// Obtain the power consumption information.
DCMI_LP_SUB_CMD_SET_IDLE_SWITCH, // Set the idle mode switch.
DCMI_LP_SUB_CMD_MAX, // Upper limit flag of enumerated values.
} DCMI_LP_SUB_CMD;</pre>
<p id="p9830153811229"><a name="p9830153811229"></a><a name="p9830153811229"></a>Currently, only <strong id="b252519426210"><a name="b252519426210"></a><a name="b252519426210"></a>DCMI_LP_SUB_CMD_SET_IDLE_SWITCH</strong> is supported.</p>
</td>
</tr>
<tr id="row1030917571727"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.16%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="51.519999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions in this section.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section13120154195114"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table152227367311"></a>
<table><thead align="left"><tr id="row102361036833"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="p142361636536"><a name="p142361636536"></a><a name="p142361636536"></a>sub_cmd</p>
</th>
<th class="cellrowborder" valign="top" width="24.98%" id="mcps1.2.5.1.2"><p id="p172364361439"><a name="p172364361439"></a><a name="p172364361439"></a>buf Data Type</p>
</th>
<th class="cellrowborder" valign="top" width="25.019999999999996%" id="mcps1.2.5.1.3"><p id="p22369362034"><a name="p22369362034"></a><a name="p22369362034"></a>size</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="p102362362037"><a name="p102362362037"></a><a name="p102362362037"></a>Parameter Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row923653618312"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="p02366360313"><a name="p02366360313"></a><a name="p02366360313"></a>DCMI_LP_SUB_CMD_SET_IDLE_SWITCH</p>
</td>
<td class="cellrowborder" valign="top" width="24.98%" headers="mcps1.2.5.1.2 "><p id="p132368365313"><a name="p132368365313"></a><a name="p132368365313"></a>unsigned char</p>
</td>
<td class="cellrowborder" valign="top" width="25.019999999999996%" headers="mcps1.2.5.1.3 "><p id="p202374363319"><a name="p202374363319"></a><a name="p202374363319"></a>Length: sizeof(unsigned char)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1087181418599"></a><a name="ul1087181418599"></a><ul id="ul1087181418599"><li><strong id="b10017262768621"><a name="b10017262768621"></a><a name="b10017262768621"></a>0</strong>: The idle mode is disabled.</li><li><strong id="b14359144508621"><a name="b14359144508621"></a><a name="b14359144508621"></a>1</strong>: The idle mode is enabled.</li><li>Other values indicate invalid effect.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section168848176545"></a>**

```c
...
int ret;
int dev_id = 0;
enum dcmi_main_cmd main_cmd = DCMI_MAIN_CMD_LP;
unsigned int sub_cmd = DCMI_LP_SUB_CMD_SET_IDLE_SWITCH;
unsigned char buf1 = '1';
unsigned int char_size = sizeof(unsigned char);
ret = dcmiv2_set_device_info(dev_id, main_cmd, sub_cmd, (void *)&buf1, char_size);
if (ret) {
// TODO
}
// TODO
...
```

## DCMI\_MAIN\_CMD\_QOS<a id="EN-US_TOPIC_0000002314204790"></a>

**Prototype<a name="section1042115192610"></a>**

**int dcmiv2\_set\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section204318582611"></a>**

Configures QoS information, including mpamid and master QoS information and bandwidth statistics.

**Parameter Description<a name="section204395112610"></a>**

<a name="table14836522617"></a>
<table><thead align="left"><tr id="row81941750263"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p101942582619"><a name="p101942582619"></a><a name="p101942582619"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p1819414572612"><a name="p1819414572612"></a><a name="p1819414572612"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.150000000000002%" id="mcps1.1.5.1.3"><p id="p9194205132614"><a name="p9194205132614"></a><a name="p9194205132614"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.53%" id="mcps1.1.5.1.4"><p id="p1119511592612"><a name="p1119511592612"></a><a name="p1119511592612"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4195175152616"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.53%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="row1419520512612"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p7195135182617"><a name="p7195135182617"></a><a name="p7195135182617"></a>main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p2019515513267"><a name="p2019515513267"></a><a name="p2019515513267"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p1519518513263"><a name="p1519518513263"></a><a name="p1519518513263"></a>enum dcmi_main_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="51.53%" headers="mcps1.1.5.1.4 "><p id="p619605112614"><a name="p619605112614"></a><a name="p619605112614"></a>DCMI_MAIN_CMD_QOS</p>
</td>
</tr>
<tr id="row17196195102619"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p519619517267"><a name="p519619517267"></a><a name="p519619517267"></a>sub_cmd</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p819611592612"><a name="p819611592612"></a><a name="p819611592612"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p17196155202616"><a name="p17196155202616"></a><a name="p17196155202616"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.53%" headers="mcps1.1.5.1.4 "><pre class="codeblock" id="codeblock147418363249"><a name="codeblock147418363249"></a><a name="codeblock147418363249"></a>typedef enum {
DCMI_QOS_SUB_MATA_CONFIG, // Specify the configuration about mpamid.
DCMI_QOS_SUB_MASTER_CONFIG, // Specify the configuration about master.
DCMI_QOS_SUB_BW_DATA, // Configure bandwidth statistics.
DCMI_QOS_SUB_GLOBAL_CONFIG, // Configure general information.
} DCMI_QOS_SUB_INFO;</pre>
</td>
</tr>
<tr id="row201979522617"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p191972511267"><a name="p191972511267"></a><a name="p191972511267"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p31971150262"><a name="p31971150262"></a><a name="p31971150262"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p61971451268"><a name="p61971451268"></a><a name="p61971451268"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="51.53%" headers="mcps1.1.5.1.4 "><p id="p141972512616"><a name="p141972512616"></a><a name="p141972512616"></a>For details, see the restrictions in this section.</p>
</td>
</tr>
<tr id="row31971555262"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p18197158261"><a name="p18197158261"></a><a name="p18197158261"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1419719510263"><a name="p1419719510263"></a><a name="p1419719510263"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.150000000000002%" headers="mcps1.1.5.1.3 "><p id="p1019725162615"><a name="p1019725162615"></a><a name="p1019725162615"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="51.53%" headers="mcps1.1.5.1.4 "><p id="p1619712516264"><a name="p1619712516264"></a><a name="p1619712516264"></a>Length of the <strong id="b7284380898527"><a name="b7284380898527"></a><a name="b7284380898527"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

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
<p id="p21991651268"><a name="p21991651268"></a><a name="p21991651268"></a>int reserved[DCMI_QOS_CFG_RESERVED_LEN - 1];</p>
<p id="p31991553269"><a name="p31991553269"></a><a name="p31991553269"></a>};</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p191999513267"><a name="p191999513267"></a><a name="p191999513267"></a>sizeof(dcmi_qos_master_config)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1519965122612"></a><a name="ul1519965122612"></a><ul id="ul1519965122612"><li><strong id="b1147421016319"><a name="b1147421016319"></a><a name="b1147421016319"></a>master</strong>: master ID, indicating the enumerated value of the chip accelerator. The supported configuration items include <strong id="b102561145203615"><a name="b102561145203615"></a><a name="b102561145203615"></a>vpc=2</strong>, <strong id="b53065016367"><a name="b53065016367"></a><a name="b53065016367"></a>jpge=3</strong>, <strong id="b394314597368"><a name="b394314597368"></a><a name="b394314597368"></a>jpgd=4</strong>, <strong id="b5271370375"><a name="b5271370375"></a><a name="b5271370375"></a>pcie=7</strong>, <strong id="b624419132373"><a name="b624419132373"></a><a name="b624419132373"></a>aic_data=9</strong>, <strong id="b133601883719"><a name="b133601883719"></a><a name="b133601883719"></a>aic_ins=10</strong>, <strong id="b18841922123718"><a name="b18841922123718"></a><a name="b18841922123718"></a>aiv_data=11</strong>, <strong id="b75561226153716"><a name="b75561226153716"></a><a name="b75561226153716"></a>aiv_ins=12</strong>, <strong id="b377215324377"><a name="b377215324377"></a><a name="b377215324377"></a>sdma=13</strong>, <strong id="b81181737123713"><a name="b81181737123713"></a><a name="b81181737123713"></a>stars=14</strong>, <strong id="b1140613444371"><a name="b1140613444371"></a><a name="b1140613444371"></a>ub_mem=33</strong>, <strong id="b13214854123711"><a name="b13214854123711"></a><a name="b13214854123711"></a>pcie_ibr=40</strong>, and <strong id="b05521704387"><a name="b05521704387"></a><a name="b05521704387"></a>pcie_ibw=41</strong>.</li><li><strong id="b1864832914383"><a name="b1864832914383"></a><a name="b1864832914383"></a>mpamid</strong>: label for identifying the data flow of the chip accelerator. The value range is [0, 127].<div class="note" id="note19682131512477"><a name="note19682131512477"></a><a name="note19682131512477"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p6682191518479"><a name="p6682191518479"></a><a name="p6682191518479"></a>When the value of <strong id="b734351903915"><a name="b734351903915"></a><a name="b734351903915"></a>master</strong> is <strong id="b295123103913"><a name="b295123103913"></a><a name="b295123103913"></a>pcie</strong>, <strong id="b126648250395"><a name="b126648250395"></a><a name="b126648250395"></a>pcie_ibr</strong>, or <strong id="b7716328173918"><a name="b7716328173918"></a><a name="b7716328173918"></a>pcie_ibw</strong>, the value range of <strong id="b1742173293914"><a name="b1742173293914"></a><a name="b1742173293914"></a>mpamid</strong> is [0, 31].</p>
</div></div>
</li><li><strong id="b10581380078527"><a name="b10581380078527"></a><a name="b10581380078527"></a>qos</strong>: bandwidth scheduling priority. The value range is [0, 7]. The value <strong id="b10251114235311"><a name="b10251114235311"></a><a name="b10251114235311"></a>0</strong> indicates hardlimit QoS, and the value <strong id="b73581244165310"><a name="b73581244165310"></a><a name="b73581244165310"></a>7</strong> indicates green channel QoS.</li><li><strong id="b1852629152712"><a name="b1852629152712"></a><a name="b1852629152712"></a>pmg</strong>: <strong id="b885314298276"><a name="b885314298276"></a><a name="b885314298276"></a>mpamid</strong> group. The value range is [0, 3].</li><li><strong id="b94150023511"><a name="b94150023511"></a><a name="b94150023511"></a>bitmap</strong>: bitmap of the target core. This parameter is not supported due to framework restrictions.</li></ul>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul12141669015"></a><a name="ul12141669015"></a><ul id="ul12141669015"><li><strong id="b184982412303"><a name="b184982412303"></a><a name="b184982412303"></a>interval</strong>: bandwidth sampling interval (unit: μs). The value must be greater than 1000.</li></ul>
<a name="ul14758119151018"></a><a name="ul14758119151018"></a><ul id="ul14758119151018"><li><strong id="b348685017613"><a name="b348685017613"></a><a name="b348685017613"></a>mode</strong>: bandwidth statistics mode. <strong id="b1148615501767"><a name="b1148615501767"></a><a name="b1148615501767"></a>0</strong>: automatic mode; <strong id="b948616502612"><a name="b948616502612"></a><a name="b948616502612"></a>1</strong>: manual mode. The configuration takes effect only on the MATA/DHA side instead of the DDRC side. Only the manual mode is supported.</li><li><strong id="b18955194614285"><a name="b18955194614285"></a><a name="b18955194614285"></a>method</strong>: method of collecting bandwidth statistics. <strong id="b179551746172810"><a name="b179551746172810"></a><a name="b179551746172810"></a>0</strong>: Bandwidth statistics are collected on the MATA/DHA side. <strong id="b209561246102817"><a name="b209561246102817"></a><a name="b209561246102817"></a>1</strong>: Bandwidth statistics are collected on the DDRC side.</li><li><strong id="b16652179878527"><a name="b16652179878527"></a><a name="b16652179878527"></a>state</strong>: bandwidth sampling command<a name="ul19778747111012"></a><a name="ul19778747111012"></a><ul id="ul19778747111012"><li><strong id="b2086909288527"><a name="b2086909288527"></a><a name="b2086909288527"></a>2</strong>: bandwidth sampling enabled</li><li><strong id="b8382751958527"><a name="b8382751958527"></a><a name="b8382751958527"></a>1</strong>: initialization</li><li><strong id="b19016052318527"><a name="b19016052318527"></a><a name="b19016052318527"></a>0</strong>: bandwidth sampling disabled</li></ul>
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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1520114516263"></a><a name="ul1520114516263"></a><ul id="ul1520114516263"><li><strong id="b20805597148527"><a name="b20805597148527"></a><a name="b20805597148527"></a>enable</strong>: whether to enable the QoS function.<a name="ul9734199111712"></a><a name="ul9734199111712"></a><ul id="ul9734199111712"><li><strong id="b17009486108527"><a name="b17009486108527"></a><a name="b17009486108527"></a>0</strong>: disabled</li><li><strong id="b20000229768527"><a name="b20000229768527"></a><a name="b20000229768527"></a>1</strong>: enabled</li></ul>
</li><li><strong id="b21243501228527"><a name="b21243501228527"></a><a name="b21243501228527"></a>autoqos_fuse_en</strong>: whether to enable QoS fusion. Currently, <strong id="b14121423418527"><a name="b14121423418527"></a><a name="b14121423418527"></a>autoqos_fuse_en</strong> cannot be set. The default value is 1.<a name="ul483832316173"></a><a name="ul483832316173"></a><ul id="ul483832316173"><li><strong id="b2512216178527"><a name="b2512216178527"></a><a name="b2512216178527"></a>0</strong>: QoS fusion is disabled.</li><li><strong id="b19279675568527"><a name="b19279675568527"></a><a name="b19279675568527"></a>1</strong>: QoS fusion starts.</li></ul>
</li><li><strong id="b7756132215306"><a name="b7756132215306"></a><a name="b7756132215306"></a>mpamqos_fuse_mode</strong>: QoS fusion mode. This parameter takes effect when <strong id="b77563221301"><a name="b77563221301"></a><a name="b77563221301"></a>autoqos_fuse_en</strong> is enabled.<a name="ul469217432179"></a><a name="ul469217432179"></a><ul id="ul469217432179"><li><strong id="b20358553478527"><a name="b20358553478527"></a><a name="b20358553478527"></a>0</strong>: average fusion</li><li><strong id="b1342143412381"><a name="b1342143412381"></a><a name="b1342143412381"></a>1</strong>: maximum value between the associated QoS and MPAM QoS</li><li><strong id="b51851256125912"><a name="b51851256125912"></a><a name="b51851256125912"></a>2</strong>: associated QoS as MPAM QoS</li></ul>
</li><li><strong id="b11077536788527"><a name="b11077536788527"></a><a name="b11077536788527"></a>mpam_subtype</strong>: bandwidth statistics mode<a name="ul1691317543171"></a><a name="ul1691317543171"></a><ul id="ul1691317543171"><li><strong id="b16881253778527"><a name="b16881253778527"></a><a name="b16881253778527"></a>0</strong>: read and write bandwidth statistics</li><li><strong id="b9574734638527"><a name="b9574734638527"></a><a name="b9574734638527"></a>1</strong>: write bandwidth statistics</li><li><strong id="b15017171588527"><a name="b15017171588527"></a><a name="b15017171588527"></a>2</strong>: read bandwidth statistics</li></ul>
</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section854716251547"></a>**

```c
...
int32_t ret;
int dev_id = 0;
// Configure the mpamid high and low waterlines to limit the bandwidth.
struct dcmi_qos_mata_config mataCfg = {0};
mataCfg.mpamid = 0; // For example, set mpamid to 0.
mataCfg.bw_high = 20;
mataCfg.bw_low = 10;
mataCfg.hardlimit = 1;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS,static_cast<uint32_t>(DCMI_QOS_SUB_MATA_CONFIG),
static_cast<void *>(&mataCfg), sizeof(struct dcmi_qos_mata_config));
if (ret != 0) {
printf("[dev:%d]set mata qos config failed, ret = %d\n", dev_id, ret);
return ret;
}
// Configure mpamid, qos, and pmg corresponding to the master.
struct dcmi_qos_master_config masterCfg = {0};
masterCfg.master = 0;
masterCfg.mpamid = 1; // For example, set mpamid to 1.
masterCfg.qos = 3;
masterCfg.pmg = 0;
masterCfg.bitmap[0] = 0xffff0000;
masterCfg.bitmap[1] = 0xffff;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, static_cast<uint32_t>(DCMI_QOS_SUB_MASTER_CONFIG),
static_cast<void *>(&cfg), sizeof(struct dcmi_qos_master_config));
if (ret != 0) {
printf("[dev:%d]set master qos config failed, ret = %d\n", dev_id, ret);
return ret;
}
// Enable manual bandwidth monitoring and specify target objects.
struct dcmi_qos_bw_config bwCfg = {0};
bwCfg.mode = 1;
bwCfg.state = 2;
bwCfg.target_set[0] = 1; // For example, set target object [0] to 1.
bwCfg.target_set[1] = 2; // For example, set target object [1] to 2.
bwCfg.cnt = 2;
bwCfg.interval = 1000;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(struct dcmi_qos_bw_config));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", dev_id, ret);
return ret;
}
// Stop bandwidth monitoring.
bwCfg.state = 0;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", dev_id, ret);
return ret;
}
// Enable automatic bandwidth monitoring. You do not need to specify target objects. The program automatically reads the configured objects.
bwCfg.mode = 0;
bwCfg.interval = 1000;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", dev_id, ret);
return ret;
}
// Stop bandwidth monitoring.
bwCfg.state = 0;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, DCMI_QOS_SUB_BW_DATA, \
static_cast<void *>(&(bwCfg)), sizeof(bwCfg));
if (ret != 0) {
printf("[dev:%d]set mbwu failed, ret = %d\n", dev_id, ret);
return ret;
}
// Enable the QoS function globally.
struct dcmi_qos_gbl_config gblCfg = {0};
gblCfg.enable = 1;
ret = dcmiv2_set_device_info(dev_id, DCMI_MAIN_CMD_QOS, static_cast<uint32_t>(DCMI_QOS_SUB_GLOBAL_CONFIG),
static_cast<void *>(&gblCfg), sizeof(struct dcmi_qos_gbl_config));
if (ret != 0) {
QOS_LOG_ERROR("[dev:%d]set gbl qos config failed, ret = %d\n", dev_id, ret);
return ret;
}
...
```

## DCMI\_MAIN\_CMD\_VDEV\_MNG<a id="EN-US_TOPIC_0000002314045190"></a>

**Prototype<a name="en-us_topic_0257495783_section204121018181415"></a>**

**int dcmiv2\_set\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

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
<tbody><tr id="en-us_topic_0257495783_row31747823"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p191957519266"><a name="p191957519266"></a><a name="p191957519266"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p1319517522613"><a name="p1319517522613"></a><a name="p1319517522613"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p419514512261"><a name="p419514512261"></a><a name="p419514512261"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
<p id="p6790145615128"><a name="p6790145615128"></a><a name="p6790145615128"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_RESOURCE, // Obtain resource information of a single virtual device.</p>
<p id="p7790175612129"><a name="p7790175612129"></a><a name="p7790175612129"></a>DCMI_VMNG_SUB_CMD_GET_TOTAL_RESOURCE, // Obtain the total resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p8790256131212"><a name="p8790256131212"></a><a name="p8790256131212"></a>DCMI_VMNG_SUB_CMD_GET_FREE_RESOURCE, // Obtain the unused resource information of an SoC device, for reference during virtual device creation.</p>
<p id="p379065613127"><a name="p379065613127"></a><a name="p379065613127"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH, // Set the SR-IOV function.</p>
<p id="p779075617120"><a name="p779075617120"></a><a name="p779075617120"></a>DCMI_VMNG_SUB_CMD_GET_VDEV_ACTIVITY = 5, // Obtain the AI Core usage of a virtual SoC device.</p>
<p id="p142142513211"><a name="p142142513211"></a><a name="p142142513211"></a>DCMI_VMNG_SUB_CMD_MAX, // Upper limit flag of enumerated values.</p>
<p id="p1921391591419"><a name="p1921391591419"></a><a name="p1921391591419"></a>}DCMI_VDEV_MNG_SUB_CMD;</p>
<p id="p15665153515459"><a name="p15665153515459"></a><a name="p15665153515459"></a>Currently, only <strong id="b11248175214217"><a name="b11248175214217"></a><a name="b11248175214217"></a>DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH</strong> is supported.</p>
</td>
</tr>
<tr id="en-us_topic_0257495783_row17526454687"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p123108571525"><a name="p123108571525"></a><a name="p123108571525"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="8.41%" headers="mcps1.1.5.1.2 "><p id="p13102579214"><a name="p13102579214"></a><a name="p13102579214"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.470000000000002%" headers="mcps1.1.5.1.3 "><p id="p331005717211"><a name="p331005717211"></a><a name="p331005717211"></a>const void *</p>
</td>
<td class="cellrowborder" valign="top" width="62.019999999999996%" headers="mcps1.1.5.1.4 "><p id="p12310115715214"><a name="p12310115715214"></a><a name="p12310115715214"></a>For details, see the restrictions in this section.</p>
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

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="en-us_topic_0257495783_section11490105451612"></a>**

Before enabling SR-IOV, stop all services in this scenario.

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
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><a name="ul1622213561019"></a><a name="ul1622213561019"></a><ul id="ul1622213561019"><li><strong id="b7208057258541"><a name="b7208057258541"></a><a name="b7208057258541"></a>0</strong>: disables the SR-IOV function.</li><li><strong id="b3915336098541"><a name="b3915336098541"></a><a name="b3915336098541"></a>1</strong>: enables the SR-IOV function.</li></ul>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

```c
...
int ret;
int dev_id = 0;
DCMI_MAIN_CMD main_cmd = DCMI_MAIN_CMD_VDEV_MNG;
unsigned int sub_cmd = DCMI_VMNG_SUB_CMD_SET_SRIOV_SWITCH;
unsigned int sriov_switch = 1;
unsigned int size = sizeof(unsigned int);

ret = dcmiv2_set_device_info(dev_id, main_cmd, sub_cmd, (void *)&sriov_switch , size);
if (ret) {
        // TODO
}
...
```

## DCMI\_MAIN\_CMD\_EX\_CERT<a id="EN-US_TOPIC_0000002541188795"></a>

**Prototype<a name="section280203719273"></a>**

**int dcmiv2\_set\_device\_info\(int dev\_id, enum dcmi\_main\_cmd main\_cmd, unsigned int sub\_cmd, const void \*buf, unsigned int buf\_size\)**

**Description<a name="section7351204942711"></a>**

Configures the TLS certificate.

**Parameter Description<a name="section13117595271"></a>**

<a name="table1212611922719"></a>
<table><thead align="left"><tr id="row1725841910272"><th class="cellrowborder" valign="top" width="10.100000000000001%" id="mcps1.1.5.1.1"><p id="p6258151914271"><a name="p6258151914271"></a><a name="p6258151914271"></a><strong id="b18214215544"><a name="b18214215544"></a><a name="b18214215544"></a>Parameter</strong></p>
</th>
<th class="cellrowborder" valign="top" width="8.08%" id="mcps1.1.5.1.2"><p id="p325881915274"><a name="p325881915274"></a><a name="p325881915274"></a><strong id="b149064025411"><a name="b149064025411"></a><a name="b149064025411"></a>Input/Output</strong></p>
</th>
<th class="cellrowborder" valign="top" width="19.189999999999998%" id="mcps1.1.5.1.3"><p id="p825881922713"><a name="p825881922713"></a><a name="p825881922713"></a><strong id="b1699564613540"><a name="b1699564613540"></a><a name="b1699564613540"></a>Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="62.629999999999995%" id="mcps1.1.5.1.4"><p id="p1925851972714"><a name="p1925851972714"></a><a name="p1925851972714"></a><strong id="b733174845415"><a name="b733174845415"></a><a name="b733174845415"></a>Description</strong></p>
</th>
</tr>
</thead>
<tbody><tr id="row425911918273"><td class="cellrowborder" valign="top" width="10.100000000000001%" headers="mcps1.1.5.1.1 "><p id="p17259111992716"><a name="p17259111992716"></a><a name="p17259111992716"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.08%" headers="mcps1.1.5.1.2 "><p id="p122590195273"><a name="p122590195273"></a><a name="p122590195273"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.189999999999998%" headers="mcps1.1.5.1.3 "><p id="p725912195278"><a name="p725912195278"></a><a name="p725912195278"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295">device_cnt</strong> – 1]</p>
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
<p id="p060172071719"><a name="p060172071719"></a><a name="p060172071719"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO, // Preconfiguration/Update of the TLS certificate information</p>
<p id="p186062061716"><a name="p186062061716"></a><a name="p186062061716"></a>DCMI_CERT_SUB_CMD_MAX, // Upper limit flag of enumerated values</p>
<p id="p66012200175"><a name="p66012200175"></a><a name="p66012200175"></a>} DCMI_EX_CERT_SUB_CMD;</p>
<p id="p102606193279"><a name="p102606193279"></a><a name="p102606193279"></a>Currently, only <strong id="b57181561549"><a name="b57181561549"></a><a name="b57181561549"></a>DCMI_CERT_SUB_CMD_TLS_CERT_INFO</strong> is supported.</p>
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
<td class="cellrowborder" valign="top" width="62.629999999999995%" headers="mcps1.1.5.1.4 "><p id="p12260719112716"><a name="p12260719112716"></a><a name="p12260719112716"></a>Length of the <strong id="b6433820105715"><a name="b6433820105715"></a><a name="b6433820105715"></a>buf</strong> array.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">return_codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Restrictions<a name="section16717528114013"></a>**

**Table  1**  buf formats corresponding to sub\_cmd

<a name="table20149119132713"></a>
<table><thead align="left"><tr id="row62609194278"><th class="cellrowborder" valign="top" width="26.02%" id="mcps1.2.5.1.1"><p id="p02603193273"><a name="p02603193273"></a><a name="p02603193273"></a><strong id="b426091952718"><a name="b426091952718"></a><a name="b426091952718"></a>sub_cmd</strong></p>
</th>
<th class="cellrowborder" valign="top" width="42.11%" id="mcps1.2.5.1.2"><p id="p92617193277"><a name="p92617193277"></a><a name="p92617193277"></a><strong id="b1791674755716"><a name="b1791674755716"></a><a name="b1791674755716"></a>buf Data Type</strong></p>
</th>
<th class="cellrowborder" valign="top" width="22.900000000000002%" id="mcps1.2.5.1.3"><p id="p2026117191273"><a name="p2026117191273"></a><a name="p2026117191273"></a><strong id="b1059315765716"><a name="b1059315765716"></a><a name="b1059315765716"></a>Size</strong></p>
</th>
<th class="cellrowborder" valign="top" width="8.97%" id="mcps1.2.5.1.4"><p id="p1226114195270"><a name="p1226114195270"></a><a name="p1226114195270"></a><strong id="b6458132185815"><a name="b6458132185815"></a><a name="b6458132185815"></a>Description</strong></p>
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
<td class="cellrowborder" valign="top" width="8.97%" headers="mcps1.2.5.1.4 "><p id="p14261181922711"><a name="p14261181922711"></a><a name="p14261181922711"></a>None</p>
</td>
</tr>
</tbody>
</table>

**Table  2** Support in different deployment scenarios

<a name="table698781019167"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row10935111803916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p2935151833910"><a name="en-us_topic_0000002347924121_p2935151833910"></a><a name="en-us_topic_0000002347924121_p2935151833910"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p4935151817398"><a name="en-us_topic_0000002347924121_p4935151817398"></a><a name="en-us_topic_0000002347924121_p4935151817398"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1293611188391"><a name="en-us_topic_0000002347924121_p1293611188391"></a><a name="en-us_topic_0000002347924121_p1293611188391"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p293616189396"><a name="en-us_topic_0000002347924121_p293616189396"></a><a name="en-us_topic_0000002347924121_p293616189396"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p8936121813397"><a name="en-us_topic_0000002347924121_p8936121813397"></a><a name="en-us_topic_0000002347924121_p8936121813397"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16936111843916"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p6936318183917"><a name="en-us_topic_0000002347924121_p6936318183917"></a><a name="en-us_topic_0000002347924121_p6936318183917"></a><strong id="en-us_topic_0000002347924121_b1851421247"><a name="en-us_topic_0000002347924121_b1851421247"></a><a name="en-us_topic_0000002347924121_b1851421247"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p79361718193918"><a name="en-us_topic_0000002347924121_p79361718193918"></a><a name="en-us_topic_0000002347924121_p79361718193918"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b745529021"><a name="en-us_topic_0000002347924121_b745529021"></a><a name="en-us_topic_0000002347924121_b745529021"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p593617183393"><a name="en-us_topic_0000002347924121_p593617183393"></a><a name="en-us_topic_0000002347924121_p593617183393"></a><strong id="en-us_topic_0000002347924121_b762099767"><a name="en-us_topic_0000002347924121_b762099767"></a><a name="en-us_topic_0000002347924121_b762099767"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p2936171814397"><a name="en-us_topic_0000002347924121_p2936171814397"></a><a name="en-us_topic_0000002347924121_p2936171814397"></a><strong id="en-us_topic_0000002347924121_b1701864068"><a name="en-us_topic_0000002347924121_b1701864068"></a><a name="en-us_topic_0000002347924121_b1701864068"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1693671803910"><a name="en-us_topic_0000002347924121_p1693671803910"></a><a name="en-us_topic_0000002347924121_p1693671803910"></a><strong id="en-us_topic_0000002347924121_b1731271965"><a name="en-us_topic_0000002347924121_b1731271965"></a><a name="en-us_topic_0000002347924121_b1731271965"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row11936131893917"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p1593651816390"><a name="en-us_topic_0000002347924121_p1593651816390"></a><a name="en-us_topic_0000002347924121_p1593651816390"></a><span id="en-us_topic_0000002347924121_ph2936121814391"><a name="en-us_topic_0000002347924121_ph2936121814391"></a><a name="en-us_topic_0000002347924121_ph2936121814391"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p189361818183914"><a name="en-us_topic_0000002347924121_p189361818183914"></a><a name="en-us_topic_0000002347924121_p189361818183914"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p87162683916"><a name="en-us_topic_0000002347924121_p87162683916"></a><a name="en-us_topic_0000002347924121_p87162683916"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p57342614392"><a name="en-us_topic_0000002347924121_p57342614392"></a><a name="en-us_topic_0000002347924121_p57342614392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1775132653914"><a name="en-us_topic_0000002347924121_p1775132653914"></a><a name="en-us_topic_0000002347924121_p1775132653914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p377112603919"><a name="en-us_topic_0000002347924121_p377112603919"></a><a name="en-us_topic_0000002347924121_p377112603919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row149367184392"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p9936131853915"><a name="en-us_topic_0000002347924121_p9936131853915"></a><a name="en-us_topic_0000002347924121_p9936131853915"></a><span id="en-us_topic_0000002347924121_ph13947112515556"><a name="en-us_topic_0000002347924121_ph13947112515556"></a><a name="en-us_topic_0000002347924121_ph13947112515556"></a>Note: <strong id="en-us_topic_0000002347924121_b15946172512558"><a name="en-us_topic_0000002347924121_b15946172512558"></a><a name="en-us_topic_0000002347924121_b15946172512558"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b6947152535516"><a name="en-us_topic_0000002347924121_b6947152535516"></a><a name="en-us_topic_0000002347924121_b6947152535516"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b14947112515555"><a name="en-us_topic_0000002347924121_b14947112515555"></a><a name="en-us_topic_0000002347924121_b14947112515555"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section14483105193112"></a>**

```c
...
int ret;
int dev_id = 0;
struct dcmi_certs_chain_data certs_chain_data ={0};
DCMI_MAIN_CMD main_cmd = DCMI_MAIN_CMD_EX_CERT;
unsigned int sub_cmd = DCMI_CERT_SUB_CMD_INIT_TLS_PUB_KEY;
unsigned int size = sizeof(struct dcmi_certs_chain_data) + cert_count * NPU_CERT_MAX_SIZE;
ret = dcmiv2_set_device_info(dev_id, main_cmd, sub_cmd, (void *)&certs_chain_data, size);
if (ret) {
    // TODO
}
// TODO
...
```

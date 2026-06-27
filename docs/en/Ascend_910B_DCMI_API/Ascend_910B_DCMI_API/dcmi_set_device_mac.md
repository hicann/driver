# dcmi\_set\_device\_mac<a name="EN-US_TOPIC_0000002515503762"></a>

**Prototype<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412077"></a>**

**int dcmi\_set\_device\_mac\(int card\_id, int device\_id, int mac\_id, const char \*mac\_addr, unsigned int len\)**

**Description<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412078"></a>**

Sets the MAC address of a device.

**Parameter Description<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412079"></a>**

<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p10021890"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p10021890"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6466753"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6466753"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p54045009"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p54045009"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p15569626"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p15569626"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p36741947142813"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p36741947142813"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p96741747122818"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p96741747122818"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p46747472287"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p46747472287"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b180908273710291"><a name="b180908273710291"></a><a name="b180908273710291"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1889151331102538"><a name="b1889151331102538"></a><a name="b1889151331102538"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b200844374310541"><a name="b200844374310541"></a><a name="b200844374310541"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p204764516614"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p204764516614"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p204764516614"></a>mac_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p2471645764"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p2471645764"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p2471645764"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p114784516618"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p114784516618"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p114784516618"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p62541647414"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p62541647414"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p62541647414"></a>MAC ID, which ranges from <strong id="b94681115172"><a name="b94681115172"></a><a name="b94681115172"></a>0</strong> to <strong id="b1146915151378"><a name="b1146915151378"></a><a name="b1146915151378"></a>3</strong>.</p>
<p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6254741247"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6254741247"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p6254741247"></a>The current version does not support this parameter. The default value <strong id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b3667983703912"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b3667983703912"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b3667983703912"></a>0</strong> is used.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row61992013131112"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p520011315116"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p520011315116"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p520011315116"></a>mac_addr</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1820016131118"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1820016131118"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1820016131118"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p11200121321115"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p11200121321115"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p11200121321115"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p5314104918611"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p5314104918611"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p5314104918611"></a>6-byte MAC address.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row18139522671"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p0139022673"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p0139022673"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p0139022673"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p4140182218713"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p4140182218713"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p4140182218713"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p81401822173"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p81401822173"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p81401822173"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"></a>Length of the MAC address, in bytes, fixed at <strong id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"></a>6</strong>.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b169488793985646"><a name="b169488793985646"></a><a name="b169488793985646"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row169301746431"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p455965912315"><a name="en-us_topic_0000002515503852_p455965912315"></a><a name="en-us_topic_0000002515503852_p455965912315"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p1855915599312"><a name="en-us_topic_0000002515503852_p1855915599312"></a><a name="en-us_topic_0000002515503852_p1855915599312"></a><strong id="en-us_topic_0000002515503852_b59121333747"><a name="en-us_topic_0000002515503852_b59121333747"></a><a name="en-us_topic_0000002515503852_b59121333747"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p1155945933111"><a name="en-us_topic_0000002515503852_p1155945933111"></a><a name="en-us_topic_0000002515503852_p1155945933111"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b16139123517413"><a name="en-us_topic_0000002515503852_b16139123517413"></a><a name="en-us_topic_0000002515503852_b16139123517413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p145593594316"><a name="en-us_topic_0000002515503852_p145593594316"></a><a name="en-us_topic_0000002515503852_p145593594316"></a><strong id="en-us_topic_0000002515503852_b153722369412"><a name="en-us_topic_0000002515503852_b153722369412"></a><a name="en-us_topic_0000002515503852_b153722369412"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row1393017444310"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p793119413433"><a name="en-us_topic_0000002515503852_p793119413433"></a><a name="en-us_topic_0000002515503852_p793119413433"></a><span id="en-us_topic_0000002515503852_ph1893115424314"><a name="en-us_topic_0000002515503852_ph1893115424314"></a><a name="en-us_topic_0000002515503852_ph1893115424314"></a><span id="en-us_topic_0000002515503852_text99311140437"><a name="en-us_topic_0000002515503852_text99311140437"></a><a name="en-us_topic_0000002515503852_text99311140437"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p99311442430"><a name="en-us_topic_0000002515503852_p99311442430"></a><a name="en-us_topic_0000002515503852_p99311442430"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1093114411431"><a name="en-us_topic_0000002515503852_p1093114411431"></a><a name="en-us_topic_0000002515503852_p1093114411431"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p39315418437"><a name="en-us_topic_0000002515503852_p39315418437"></a><a name="en-us_topic_0000002515503852_p39315418437"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row79316404316"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p3931545437"><a name="en-us_topic_0000002515503852_p3931545437"></a><a name="en-us_topic_0000002515503852_p3931545437"></a><span id="en-us_topic_0000002515503852_text893113494316"><a name="en-us_topic_0000002515503852_text893113494316"></a><a name="en-us_topic_0000002515503852_text893113494316"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p49310454319"><a name="en-us_topic_0000002515503852_p49310454319"></a><a name="en-us_topic_0000002515503852_p49310454319"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p993111464319"><a name="en-us_topic_0000002515503852_p993111464319"></a><a name="en-us_topic_0000002515503852_p993111464319"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p893111419431"><a name="en-us_topic_0000002515503852_p893111419431"></a><a name="en-us_topic_0000002515503852_p893111419431"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row39314494319"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1893154144315"><a name="en-us_topic_0000002515503852_p1893154144315"></a><a name="en-us_topic_0000002515503852_p1893154144315"></a><span id="en-us_topic_0000002515503852_text69317417433"><a name="en-us_topic_0000002515503852_text69317417433"></a><a name="en-us_topic_0000002515503852_text69317417433"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p159312418432"><a name="en-us_topic_0000002515503852_p159312418432"></a><a name="en-us_topic_0000002515503852_p159312418432"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p11931046437"><a name="en-us_topic_0000002515503852_p11931046437"></a><a name="en-us_topic_0000002515503852_p11931046437"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1093117412433"><a name="en-us_topic_0000002515503852_p1093117412433"></a><a name="en-us_topic_0000002515503852_p1093117412433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row129312414310"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p793114424311"><a name="en-us_topic_0000002515503852_p793114424311"></a><a name="en-us_topic_0000002515503852_p793114424311"></a><span id="en-us_topic_0000002515503852_text393110464310"><a name="en-us_topic_0000002515503852_text393110464310"></a><a name="en-us_topic_0000002515503852_text393110464310"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1893114154312"><a name="en-us_topic_0000002515503852_p1893114154312"></a><a name="en-us_topic_0000002515503852_p1893114154312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p59316474318"><a name="en-us_topic_0000002515503852_p59316474318"></a><a name="en-us_topic_0000002515503852_p59316474318"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1693115417437"><a name="en-us_topic_0000002515503852_p1693115417437"></a><a name="en-us_topic_0000002515503852_p1693115417437"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row89311147437"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1893194154319"><a name="en-us_topic_0000002515503852_p1893194154319"></a><a name="en-us_topic_0000002515503852_p1893194154319"></a><span id="en-us_topic_0000002515503852_text2093119410435"><a name="en-us_topic_0000002515503852_text2093119410435"></a><a name="en-us_topic_0000002515503852_text2093119410435"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p10931104184313"><a name="en-us_topic_0000002515503852_p10931104184313"></a><a name="en-us_topic_0000002515503852_p10931104184313"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1593174124311"><a name="en-us_topic_0000002515503852_p1593174124311"></a><a name="en-us_topic_0000002515503852_p1593174124311"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1193110410433"><a name="en-us_topic_0000002515503852_p1193110410433"></a><a name="en-us_topic_0000002515503852_p1193110410433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1593110424311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p169318417439"><a name="en-us_topic_0000002515503852_p169318417439"></a><a name="en-us_topic_0000002515503852_p169318417439"></a><span id="en-us_topic_0000002515503852_text190313342286"><a name="en-us_topic_0000002515503852_text190313342286"></a><a name="en-us_topic_0000002515503852_text190313342286"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p813010149432"><a name="en-us_topic_0000002515503852_p813010149432"></a><a name="en-us_topic_0000002515503852_p813010149432"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p4931174104310"><a name="en-us_topic_0000002515503852_p4931174104310"></a><a name="en-us_topic_0000002515503852_p4931174104310"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p29311647436"><a name="en-us_topic_0000002515503852_p29311647436"></a><a name="en-us_topic_0000002515503852_p29311647436"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row109312418438"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p159327434319"><a name="en-us_topic_0000002515503852_p159327434319"></a><a name="en-us_topic_0000002515503852_p159327434319"></a><span id="en-us_topic_0000002515503852_text179321145437"><a name="en-us_topic_0000002515503852_text179321145437"></a><a name="en-us_topic_0000002515503852_text179321145437"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p714181416435"><a name="en-us_topic_0000002515503852_p714181416435"></a><a name="en-us_topic_0000002515503852_p714181416435"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p7932114174312"><a name="en-us_topic_0000002515503852_p7932114174312"></a><a name="en-us_topic_0000002515503852_p7932114174312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19323418433"><a name="en-us_topic_0000002515503852_p19323418433"></a><a name="en-us_topic_0000002515503852_p19323418433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1993264174312"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1693212411435"><a name="en-us_topic_0000002515503852_p1693212411435"></a><a name="en-us_topic_0000002515503852_p1693212411435"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
char mac_addr[6] = {0xXX,0xXX,0xXX,0xXX,0xXX,0xXX};  // XX indicates the data of each segment of the MAC address. Use the actual value.
ret = dcmi_set_device_mac(card_id, dev_id, 0, mac_addr, 6);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

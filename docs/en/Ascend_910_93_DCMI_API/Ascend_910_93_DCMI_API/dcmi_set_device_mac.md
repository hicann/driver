# dcmi\_set\_device\_mac<a name="EN-US_TOPIC_0000002515350570"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b15695390981439"><a name="b15695390981439"></a><a name="b15695390981439"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b19560182263319"><a name="b19560182263319"></a><a name="b19560182263319"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b18817613076530"><a name="b18817613076530"></a><a name="b18817613076530"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_p214082212717"></a>Length of the MAC address, in bytes, set to <strong id="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"></a><a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_b19687541723912"></a>6</strong>.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b10393566217929"><a name="b10393566217929"></a><a name="b10393566217929"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
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

**Example<a name="en-us_topic_0000001206307232_en-us_topic_0000001223414433_en-us_topic_0000001148284427_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int dev_id = 0;
char mac_addr[6] = {0xXX,0xXX,0xXX,0xXX,0xXX,0xXX};  // XX indicates the data of each segment of the MAC address. Use the actual value.
ret = dcmi_set_device_mac(card_id, dev_id, 0, mac_addr, 6);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
...
```

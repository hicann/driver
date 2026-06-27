# dcmi\_get\_device\_mac<a name="EN-US_TOPIC_0000002546910357"></a>

**Prototype<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412077"></a>**

**int dcmi\_get\_device\_mac\(int card\_id, int device\_id, int mac\_id, char \*mac\_addr, unsigned int len\)**

**Description<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412078"></a>**

Obtains the MAC address of a device.

**Parameter Description<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412079"></a>**

<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p10021890"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p10021890"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6466753"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6466753"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p54045009"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p54045009"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p15569626"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p15569626"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p36741947142813"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p36741947142813"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p96741747122818"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p96741747122818"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p46747472287"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p46747472287"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b16565347781334"><a name="b16565347781334"></a><a name="b16565347781334"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b123186814033110"><a name="b123186814033110"></a><a name="b123186814033110"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b1453617524609"><a name="b1453617524609"></a><a name="b1453617524609"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p204764516614"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p204764516614"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p204764516614"></a>mac_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p2471645764"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p2471645764"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p2471645764"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p114784516618"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p114784516618"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p114784516618"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p62541647414"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p62541647414"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p62541647414"></a>MAC ID, which ranges from <strong id="b819911332610"><a name="b819911332610"></a><a name="b819911332610"></a>0</strong> to <strong id="b1499213341168"><a name="b1499213341168"></a><a name="b1499213341168"></a>3</strong>.</p>
<p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6254741247"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6254741247"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p6254741247"></a>The current version does not support this parameter. The default value <strong id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b5031662633630"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b5031662633630"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b5031662633630"></a>0</strong> is used.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row592615412120"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p520011315116"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p520011315116"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p520011315116"></a>mac_addr</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1820016131118"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1820016131118"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1820016131118"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p11200121321115"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p11200121321115"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p11200121321115"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p5314104918611"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p5314104918611"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p5314104918611"></a>6-byte MAC address.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row94185112109"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p0139022673"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p0139022673"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p0139022673"></a>len</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p4140182218713"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p4140182218713"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p4140182218713"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p81401822173"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p81401822173"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p81401822173"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"></a>Length of the MAC address, in bytes, set to <strong id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"></a>6</strong>.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b16792794167930"><a name="b16792794167930"></a><a name="b16792794167930"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row913516862011"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1913568182013"><a name="en-us_topic_0000002515350556_p1913568182013"></a><a name="en-us_topic_0000002515350556_p1913568182013"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p1713588142014"><a name="en-us_topic_0000002515350556_p1713588142014"></a><a name="en-us_topic_0000002515350556_p1713588142014"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p161354852013"><a name="en-us_topic_0000002515350556_p161354852013"></a><a name="en-us_topic_0000002515350556_p161354852013"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row17135168192014"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p16135128182017"><a name="en-us_topic_0000002515350556_p16135128182017"></a><a name="en-us_topic_0000002515350556_p16135128182017"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1713528202015"><a name="en-us_topic_0000002515350556_p1713528202015"></a><a name="en-us_topic_0000002515350556_p1713528202015"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p181351087205"><a name="en-us_topic_0000002515350556_p181351087205"></a><a name="en-us_topic_0000002515350556_p181351087205"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row31351488206"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p6135185208"><a name="en-us_topic_0000002515350556_p6135185208"></a><a name="en-us_topic_0000002515350556_p6135185208"></a><span id="en-us_topic_0000002515350556_text1213528172016"><a name="en-us_topic_0000002515350556_text1213528172016"></a><a name="en-us_topic_0000002515350556_text1213528172016"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1213511813205"><a name="en-us_topic_0000002515350556_p1213511813205"></a><a name="en-us_topic_0000002515350556_p1213511813205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p613528102020"><a name="en-us_topic_0000002515350556_p613528102020"></a><a name="en-us_topic_0000002515350556_p613528102020"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p713512862013"><a name="en-us_topic_0000002515350556_p713512862013"></a><a name="en-us_topic_0000002515350556_p713512862013"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1813515811208"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p71354810207"><a name="en-us_topic_0000002515350556_p71354810207"></a><a name="en-us_topic_0000002515350556_p71354810207"></a><span id="en-us_topic_0000002515350556_text51358812207"><a name="en-us_topic_0000002515350556_text51358812207"></a><a name="en-us_topic_0000002515350556_text51358812207"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p213568152019"><a name="en-us_topic_0000002515350556_p213568152019"></a><a name="en-us_topic_0000002515350556_p213568152019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1613548142019"><a name="en-us_topic_0000002515350556_p1613548142019"></a><a name="en-us_topic_0000002515350556_p1613548142019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11351087209"><a name="en-us_topic_0000002515350556_p11351087209"></a><a name="en-us_topic_0000002515350556_p11351087209"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row87611016195410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p8296259161515"><a name="en-us_topic_0000002515350556_p8296259161515"></a><a name="en-us_topic_0000002515350556_p8296259161515"></a><span id="en-us_topic_0000002515350556_text14296259131514"><a name="en-us_topic_0000002515350556_text14296259131514"></a><a name="en-us_topic_0000002515350556_text14296259131514"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1451920314542"><a name="en-us_topic_0000002515350556_p1451920314542"></a><a name="en-us_topic_0000002515350556_p1451920314542"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p2519133155413"><a name="en-us_topic_0000002515350556_p2519133155413"></a><a name="en-us_topic_0000002515350556_p2519133155413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11519153110545"><a name="en-us_topic_0000002515350556_p11519153110545"></a><a name="en-us_topic_0000002515350556_p11519153110545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row0323633152810"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p064011372281"><a name="en-us_topic_0000002515350556_p064011372281"></a><a name="en-us_topic_0000002515350556_p064011372281"></a><span id="en-us_topic_0000002515350556_text18640537162811"><a name="en-us_topic_0000002515350556_text18640537162811"></a><a name="en-us_topic_0000002515350556_text18640537162811"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p279104012287"><a name="en-us_topic_0000002515350556_p279104012287"></a><a name="en-us_topic_0000002515350556_p279104012287"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p779112409289"><a name="en-us_topic_0000002515350556_p779112409289"></a><a name="en-us_topic_0000002515350556_p779112409289"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1791140112816"><a name="en-us_topic_0000002515350556_p1791140112816"></a><a name="en-us_topic_0000002515350556_p1791140112816"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row49081418125411"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p512952510545"><a name="en-us_topic_0000002515350556_p512952510545"></a><a name="en-us_topic_0000002515350556_p512952510545"></a><span id="en-us_topic_0000002515350556_text012942512545"><a name="en-us_topic_0000002515350556_text012942512545"></a><a name="en-us_topic_0000002515350556_text012942512545"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1260932135413"><a name="en-us_topic_0000002515350556_p1260932135413"></a><a name="en-us_topic_0000002515350556_p1260932135413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1660133285419"><a name="en-us_topic_0000002515350556_p1660133285419"></a><a name="en-us_topic_0000002515350556_p1660133285419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p46017321545"><a name="en-us_topic_0000002515350556_p46017321545"></a><a name="en-us_topic_0000002515350556_p46017321545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1625111184"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1386118141085"><a name="en-us_topic_0000002515350556_p1386118141085"></a><a name="en-us_topic_0000002515350556_p1386118141085"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
char mac_addr[6] = {0};
ret = dcmi_get_device_mac(card_id, device_id, 0, mac_addr, 6);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
...
```

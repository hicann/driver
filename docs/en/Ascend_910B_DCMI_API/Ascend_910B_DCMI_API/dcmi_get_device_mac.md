# dcmi\_get\_device\_mac<a name="EN-US_TOPIC_0000002515343876"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b197919412410292"><a name="b197919412410292"></a><a name="b197919412410292"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b621628051102539"><a name="b621628051102539"></a><a name="b621628051102539"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b98387026910542"><a name="b98387026910542"></a><a name="b98387026910542"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_p214082212717"></a>Length of the MAC address, in bytes, fixed at <strong id="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"></a><a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_b8623022398"></a>6</strong>.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b37777270385647"><a name="b37777270385647"></a><a name="b37777270385647"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1831828113412"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row581562894416"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p43357515328"><a name="en-us_topic_0000002515503852_p43357515328"></a><a name="en-us_topic_0000002515503852_p43357515328"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p173353517328"><a name="en-us_topic_0000002515503852_p173353517328"></a><a name="en-us_topic_0000002515503852_p173353517328"></a><strong id="en-us_topic_0000002515503852_b1380412385418"><a name="en-us_topic_0000002515503852_b1380412385418"></a><a name="en-us_topic_0000002515503852_b1380412385418"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p133520514323"><a name="en-us_topic_0000002515503852_p133520514323"></a><a name="en-us_topic_0000002515503852_p133520514323"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b18990139743"><a name="en-us_topic_0000002515503852_b18990139743"></a><a name="en-us_topic_0000002515503852_b18990139743"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p143351858329"><a name="en-us_topic_0000002515503852_p143351858329"></a><a name="en-us_topic_0000002515503852_p143351858329"></a><strong id="en-us_topic_0000002515503852_b057164112415"><a name="en-us_topic_0000002515503852_b057164112415"></a><a name="en-us_topic_0000002515503852_b057164112415"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row1281542810440"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1981562874416"><a name="en-us_topic_0000002515503852_p1981562874416"></a><a name="en-us_topic_0000002515503852_p1981562874416"></a><span id="en-us_topic_0000002515503852_ph7815172854410"><a name="en-us_topic_0000002515503852_ph7815172854410"></a><a name="en-us_topic_0000002515503852_ph7815172854410"></a><span id="en-us_topic_0000002515503852_text381517281442"><a name="en-us_topic_0000002515503852_text381517281442"></a><a name="en-us_topic_0000002515503852_text381517281442"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p14815152864419"><a name="en-us_topic_0000002515503852_p14815152864419"></a><a name="en-us_topic_0000002515503852_p14815152864419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1196518341444"><a name="en-us_topic_0000002515503852_p1196518341444"></a><a name="en-us_topic_0000002515503852_p1196518341444"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p198154284446"><a name="en-us_topic_0000002515503852_p198154284446"></a><a name="en-us_topic_0000002515503852_p198154284446"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row981512284443"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p108151728124417"><a name="en-us_topic_0000002515503852_p108151728124417"></a><a name="en-us_topic_0000002515503852_p108151728124417"></a><span id="en-us_topic_0000002515503852_text581511282442"><a name="en-us_topic_0000002515503852_text581511282442"></a><a name="en-us_topic_0000002515503852_text581511282442"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1981512814410"><a name="en-us_topic_0000002515503852_p1981512814410"></a><a name="en-us_topic_0000002515503852_p1981512814410"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1598712344449"><a name="en-us_topic_0000002515503852_p1598712344449"></a><a name="en-us_topic_0000002515503852_p1598712344449"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1581572810447"><a name="en-us_topic_0000002515503852_p1581572810447"></a><a name="en-us_topic_0000002515503852_p1581572810447"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row881511286446"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p68151028164411"><a name="en-us_topic_0000002515503852_p68151028164411"></a><a name="en-us_topic_0000002515503852_p68151028164411"></a><span id="en-us_topic_0000002515503852_text198151428124419"><a name="en-us_topic_0000002515503852_text198151428124419"></a><a name="en-us_topic_0000002515503852_text198151428124419"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p881562844411"><a name="en-us_topic_0000002515503852_p881562844411"></a><a name="en-us_topic_0000002515503852_p881562844411"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p771735154414"><a name="en-us_topic_0000002515503852_p771735154414"></a><a name="en-us_topic_0000002515503852_p771735154414"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1881510282441"><a name="en-us_topic_0000002515503852_p1881510282441"></a><a name="en-us_topic_0000002515503852_p1881510282441"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18815192834416"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p28154282441"><a name="en-us_topic_0000002515503852_p28154282441"></a><a name="en-us_topic_0000002515503852_p28154282441"></a><span id="en-us_topic_0000002515503852_text1781542854412"><a name="en-us_topic_0000002515503852_text1781542854412"></a><a name="en-us_topic_0000002515503852_text1781542854412"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p78155282448"><a name="en-us_topic_0000002515503852_p78155282448"></a><a name="en-us_topic_0000002515503852_p78155282448"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p181953519441"><a name="en-us_topic_0000002515503852_p181953519441"></a><a name="en-us_topic_0000002515503852_p181953519441"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1481512818445"><a name="en-us_topic_0000002515503852_p1481512818445"></a><a name="en-us_topic_0000002515503852_p1481512818445"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row158158282441"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p7815528194418"><a name="en-us_topic_0000002515503852_p7815528194418"></a><a name="en-us_topic_0000002515503852_p7815528194418"></a><span id="en-us_topic_0000002515503852_text1181518281441"><a name="en-us_topic_0000002515503852_text1181518281441"></a><a name="en-us_topic_0000002515503852_text1181518281441"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p8815102874415"><a name="en-us_topic_0000002515503852_p8815102874415"></a><a name="en-us_topic_0000002515503852_p8815102874415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p17311135144414"><a name="en-us_topic_0000002515503852_p17311135144414"></a><a name="en-us_topic_0000002515503852_p17311135144414"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p208167280445"><a name="en-us_topic_0000002515503852_p208167280445"></a><a name="en-us_topic_0000002515503852_p208167280445"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1181616287447"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p5816828194415"><a name="en-us_topic_0000002515503852_p5816828194415"></a><a name="en-us_topic_0000002515503852_p5816828194415"></a><span id="en-us_topic_0000002515503852_text1852519469285"><a name="en-us_topic_0000002515503852_text1852519469285"></a><a name="en-us_topic_0000002515503852_text1852519469285"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p181614288442"><a name="en-us_topic_0000002515503852_p181614288442"></a><a name="en-us_topic_0000002515503852_p181614288442"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p68161128114412"><a name="en-us_topic_0000002515503852_p68161128114412"></a><a name="en-us_topic_0000002515503852_p68161128114412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p118161828134410"><a name="en-us_topic_0000002515503852_p118161828134410"></a><a name="en-us_topic_0000002515503852_p118161828134410"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row3816122816442"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1781612894419"><a name="en-us_topic_0000002515503852_p1781612894419"></a><a name="en-us_topic_0000002515503852_p1781612894419"></a><span id="en-us_topic_0000002515503852_text68161128184411"><a name="en-us_topic_0000002515503852_text68161128184411"></a><a name="en-us_topic_0000002515503852_text68161128184411"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p7816152864417"><a name="en-us_topic_0000002515503852_p7816152864417"></a><a name="en-us_topic_0000002515503852_p7816152864417"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p481612854411"><a name="en-us_topic_0000002515503852_p481612854411"></a><a name="en-us_topic_0000002515503852_p481612854411"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p681632812446"><a name="en-us_topic_0000002515503852_p681632812446"></a><a name="en-us_topic_0000002515503852_p681632812446"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row08161028144418"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p481612810440"><a name="en-us_topic_0000002515503852_p481612810440"></a><a name="en-us_topic_0000002515503852_p481612810440"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206147254_en-us_topic_0000001223292885_en-us_topic_0000001101364542_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
char mac_addr[6] = {0};
ret = dcmi_get_device_mac(card_id, device_id, 0, mac_addr, 6);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

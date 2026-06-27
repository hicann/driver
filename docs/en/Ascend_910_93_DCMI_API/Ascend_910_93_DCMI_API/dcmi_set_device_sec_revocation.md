# dcmi\_set\_device\_sec\_revocation<a name="EN-US_TOPIC_0000002515510524"></a>

**Prototype<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412077"></a>**

**int dcmi\_set\_device\_sec\_revocation\(int card\_id, int device\_id, enum dcmi\_revo\_type input\_type, const unsigned char \*file\_data, unsigned int file\_size\)**

**Description<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412078"></a>**

Revokes the key.

**Parameter Description<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412079"></a>**

<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="19.02%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.96%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p36741947142813"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p36741947142813"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p96741747122818"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p96741747122818"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p46747472287"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p46747472287"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b185343300033018"><a name="b185343300033018"></a><a name="b185343300033018"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="p75164043915"><a name="p75164043915"></a><a name="p75164043915"></a>Chip ID, which can be obtained by calling <strong id="b49239449281814"><a name="b49239449281814"></a><a name="b49239449281814"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p19717114013409"><a name="p19717114013409"></a><a name="p19717114013409"></a>NPU: [0, <strong id="b152500729781814"><a name="b152500729781814"></a><a name="b152500729781814"></a>device_id_max</strong> – 1] <strong id="b16210121143512"><a name="b16210121143512"></a><a name="b16210121143512"></a>device_id</strong> must be set to <strong id="b49192663410"><a name="b49192663410"></a><a name="b49192663410"></a>0</strong>.</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p5522164215178"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p17522114220174"></a>enum dcmi_revo_type</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p0522164231718"></a>Revocation type.</p>
<p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1014115454529"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1014115454529"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1014115454529"></a>enum dcmi_revo_type {</p>
<p id="p212016451686"><a name="p212016451686"></a><a name="p212016451686"></a>DCMI_REVOCATION_TYPE_SOC = 0, // Revoke the SoC key.</p>
<p id="p181202459812"><a name="p181202459812"></a><a name="p181202459812"></a>DCMI_REVOCATION_TYPE_CMS_CRL = 1,  // Upgrade the MDC CMS CRL file.</p>
<p id="p2120104517816"><a name="p2120104517816"></a><a name="p2120104517816"></a>DCMI_REVOCATION_TYPE_CMS_CRL_EXT = 2, // Upgrade the extended CRL file.</p>
<p id="p75053511085"><a name="p75053511085"></a><a name="p75053511085"></a>DCMI_REVOCATION_TYPE_MAX</p>
<p id="p1227717173228"><a name="p1227717173228"></a><a name="p1227717173228"></a>};</p>
<p id="p171201345786"><a name="p171201345786"></a><a name="p171201345786"></a>Currently, only <strong id="b979561194713"><a name="b979561194713"></a><a name="b979561194713"></a>DCMI_REVOCATION_TYPE_SOC</strong> is supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row46671240105418"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p14667114012547"></a>file_data</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7668154095417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p566818401548"></a>const unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1366819403540"></a>Data address of the revocation file.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row1306946165516"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307146105520"></a>file_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p830764614555"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p16307746155515"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a>Data length of the revocation file. For SoC secondary key revocation, the file length must be 544 bytes.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b209042128072218"><a name="b209042128072218"></a><a name="b209042128072218"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412082"></a>**

- Call this API if you want to perform revocation. Correct revocation files are required. Otherwise, the API call may fail.
- The device count must be obtained before key revocation of all devices.
- This API invokes execution in TEEOS, which may take a long time. Sleep or wake-up operations are not supported during the API call. If sleep is triggered while the call is in progress, the operation is likely to fail.
- Key revocation is irreversible. Exercise caution when performing this operation.
- The device is no longer available after key revocation.
- **Table  1** Support in different deployment scenarios

    <a name="table155158516230"></a>
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

**Example<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412083"></a>**

```c
...
#define REVOCATION_FILE_LEN  544
int card_id = 0;
int dev_id = 0;
int ret = 0;
int dev_count = 0;
unsigned char revocation_file_buf[REVOCATION_FILE_LEN] = {0};
unsigned int buf_size = REVOCATION_FILE_LEN;
ret = dcmi_set_device_sec_revocation(card_id, dev_id, DCMI_REVOCATION_TYPE_SOC, (const unsigned char *)revocation_file_buf, buf_size);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

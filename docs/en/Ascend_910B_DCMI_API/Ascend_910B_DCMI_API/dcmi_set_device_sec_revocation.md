# dcmi\_set\_device\_sec\_revocation<a name="EN-US_TOPIC_0000002515503854"></a>

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
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1364157826102821"><a name="b1364157826102821"></a><a name="b1364157826102821"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="19.02%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1390671671102445"><a name="b1390671671102445"></a><a name="b1390671671102445"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b891011636105333"><a name="b891011636105333"></a><a name="b891011636105333"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<p id="p181202459812"><a name="p181202459812"></a><a name="p181202459812"></a>DCMI_REVOCATION_TYPE_CMS_CRL = 1, // Upgrade the MDC CMS CRL file.</p>
<p id="p339720234533"><a name="p339720234533"></a><a name="p339720234533"></a>DCMI_REVOCATION_TYPE_CMS_CRL_EXT = 2, // Upgrade the extended CRL file.</p>
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
<td class="cellrowborder" valign="top" width="48.96%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a><a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_p630704645512"></a>Data length of the revocation file. The file length for SoC level-2 key revocation is fixed at 544 bytes.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b89141402985554"><a name="b89141402985554"></a><a name="b89141402985554"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251307177_en-us_topic_0000001178373148_en-us_topic_0000001101604520_toc533412082"></a>**

- Key revocation is irreversible. Exercise caution when performing this operation.
- API needs to call TEEOS, which may take a long time. It does not support triggering hibernation/wake-up during the call. If hibernation is triggered, there is a high likelihood of hibernation failure.
- For a Symmetric Multi-Processing \(SMP\) system, the device count must be obtained before key revocation of all devices.
- Call this API if you want to perform revocation. Correct revocation files are required. Otherwise, the API call may fail.
- The device is no longer available after key revocation.

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
    //todo: Record logs.
    return ret;
}
...
```

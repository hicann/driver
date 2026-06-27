# dcmi\_get\_device\_frequency<a name="EN-US_TOPIC_0000002515503794"></a>

**Prototype<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_toc533412077"></a>**

**int dcmi\_get\_device\_frequency\(int card\_id, int device\_id, enum dcmi\_freq\_type input\_type, unsigned int \*frequency\)**

**Description<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_toc533412078"></a>**

Obtains the device frequency.

**Parameter Description<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_toc533412079"></a>**

<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p10021890"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p10021890"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p6466753"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p6466753"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p54045009"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p54045009"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15569626"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15569626"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p36741947142813"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p36741947142813"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p96741747122818"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p96741747122818"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p46747472287"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p46747472287"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1467413474281"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1467413474281"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1642419267293"><a name="b1642419267293"></a><a name="b1642419267293"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p7711145152918"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p7711145152918"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p671116522914"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p671116522914"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1771116572910"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1771116572910"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1061753382912"><a name="b1061753382912"></a><a name="b1061753382912"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b155826848010535"><a name="b155826848010535"></a><a name="b155826848010535"></a>device_id_max</strong> – 1]</p>
<p id="p1430490101517"><a name="p1430490101517"></a><a name="p1430490101517"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p632862814364"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p632862814364"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p632862814364"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1332814289360"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1332814289360"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1332814289360"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p832811289363"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p832811289363"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p832811289363"></a>enum dcmi_freq_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325099_p12367502"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325099_p12367502"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325099_p12367502"></a>Device type.</p>
<p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328591_en-us_topic_0146325092_p46831115"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328591_en-us_topic_0146325092_p46831115"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328591_en-us_topic_0146325092_p46831115"></a>The value can be <strong id="b1183831881218"><a name="b1183831881218"></a><a name="b1183831881218"></a>2</strong>, <strong id="b11838918111216"><a name="b11838918111216"></a><a name="b11838918111216"></a>6</strong>, <strong id="b9838018191216"><a name="b9838018191216"></a><a name="b9838018191216"></a>7</strong>, or <strong id="b18381818111212"><a name="b18381818111212"></a><a name="b18381818111212"></a>9</strong>.</p>
<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325092_ul5794145112018"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325092_ul5794145112018"></a><ul id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_en-us_topic_0204328565_en-us_topic_0146325092_ul5794145112018"><li><strong id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1249412487154"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1249412487154"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1249412487154"></a>1</strong>: memory</li><li><strong id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b419915533152"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b419915533152"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b419915533152"></a>2</strong>: Ctrl CPU</li><li><strong id="b5922103612583"><a name="b5922103612583"></a><a name="b5922103612583"></a>6</strong>: on-chip memory</li><li><strong id="b78151613115117"><a name="b78151613115117"></a><a name="b78151613115117"></a>7</strong>: current frequency of the AI Core</li><li><strong id="b3344121895118"><a name="b3344121895118"></a><a name="b3344121895118"></a>9</strong>: rated frequency of the AI Core</li><li><strong id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1866581811615"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1866581811615"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_b1866581811615"></a>12</strong>: current frequency of the Vector Core</li></ul>
<p id="p1154715611512"><a name="p1154715611512"></a><a name="p1154715611512"></a></p>
<div class="note" id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_note5275125722319"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_note5275125722319"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_note5275125722319"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_p116439914494"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_p116439914494"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_en-us_topic_0293880883_p116439914494"></a>The rated frequency of the AI Core refers to the frequency at which the AI Core can run properly under the TDP.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_row18822524133610"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15328182812362"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15328182812362"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p15328182812362"></a>frequency</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p23287285364"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p23287285364"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p23287285364"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p4328328193614"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p4328328193614"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p4328328193614"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1432812815363"><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1432812815363"></a><a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_p1432812815363"></a>Frequency (MHz).</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
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

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_toc533412082"></a>**

The on-chip memory of A300I A2 inference card, Atlas 300T A2 training card, Atlas 900 A2 PoD cluster basic unit, A200I A2 Box heterogeneous component, and Atlas 800I A2 inference server is 32 GB, and the system occupies 3 GB when no service is running. The on-chip memory of Atlas 800T A2 training server, Atlas 900 A2 PoD cluster basic unit,  Atlas 200T A2 Box16 heterogeneous subrack, A200I A2 Box heterogeneous component, and Atlas 800I A2 inference server is 64 GB, and the system occupies 4 GB when no service is running.

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1548132517501"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p16154843125019"><a name="en-us_topic_0000002515503852_p16154843125019"></a><a name="en-us_topic_0000002515503852_p16154843125019"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p3123182915595"><a name="en-us_topic_0000002515503852_p3123182915595"></a><a name="en-us_topic_0000002515503852_p3123182915595"></a><strong id="en-us_topic_0000002515503852_b181336402033"><a name="en-us_topic_0000002515503852_b181336402033"></a><a name="en-us_topic_0000002515503852_b181336402033"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p6271950600"><a name="en-us_topic_0000002515503852_p6271950600"></a><a name="en-us_topic_0000002515503852_p6271950600"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b56571847339"><a name="en-us_topic_0000002515503852_b56571847339"></a><a name="en-us_topic_0000002515503852_b56571847339"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p41541743195013"><a name="en-us_topic_0000002515503852_p41541743195013"></a><a name="en-us_topic_0000002515503852_p41541743195013"></a><strong id="en-us_topic_0000002515503852_b6856448332"><a name="en-us_topic_0000002515503852_b6856448332"></a><a name="en-us_topic_0000002515503852_b6856448332"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19444162914516"><a name="en-us_topic_0000002515503852_p19444162914516"></a><a name="en-us_topic_0000002515503852_p19444162914516"></a><span id="en-us_topic_0000002515503852_ph1944412296514"><a name="en-us_topic_0000002515503852_ph1944412296514"></a><a name="en-us_topic_0000002515503852_ph1944412296514"></a><span id="en-us_topic_0000002515503852_text944432913516"><a name="en-us_topic_0000002515503852_text944432913516"></a><a name="en-us_topic_0000002515503852_text944432913516"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p194441629165117"><a name="en-us_topic_0000002515503852_p194441629165117"></a><a name="en-us_topic_0000002515503852_p194441629165117"></a><span id="en-us_topic_0000002515503852_text124449291511"><a name="en-us_topic_0000002515503852_text124449291511"></a><a name="en-us_topic_0000002515503852_text124449291511"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p461320458219"><a name="en-us_topic_0000002515503852_p461320458219"></a><a name="en-us_topic_0000002515503852_p461320458219"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13613134519220"><a name="en-us_topic_0000002515503852_p13613134519220"></a><a name="en-us_topic_0000002515503852_p13613134519220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96133454211"><a name="en-us_topic_0000002515503852_p96133454211"></a><a name="en-us_topic_0000002515503852_p96133454211"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row14873174604910"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10444329155118"><a name="en-us_topic_0000002515503852_p10444329155118"></a><a name="en-us_topic_0000002515503852_p10444329155118"></a><span id="en-us_topic_0000002515503852_text1044482925119"><a name="en-us_topic_0000002515503852_text1044482925119"></a><a name="en-us_topic_0000002515503852_text1044482925119"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p896391111511"><a name="en-us_topic_0000002515503852_p896391111511"></a><a name="en-us_topic_0000002515503852_p896391111511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p119682011105113"><a name="en-us_topic_0000002515503852_p119682011105113"></a><a name="en-us_topic_0000002515503852_p119682011105113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11975911195114"><a name="en-us_topic_0000002515503852_p11975911195114"></a><a name="en-us_topic_0000002515503852_p11975911195114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row23051923114915"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p174441129175117"><a name="en-us_topic_0000002515503852_p174441129175117"></a><a name="en-us_topic_0000002515503852_p174441129175117"></a><span id="en-us_topic_0000002515503852_text34441729175119"><a name="en-us_topic_0000002515503852_text34441729175119"></a><a name="en-us_topic_0000002515503852_text34441729175119"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1298231135114"><a name="en-us_topic_0000002515503852_p1298231135114"></a><a name="en-us_topic_0000002515503852_p1298231135114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1298921117511"><a name="en-us_topic_0000002515503852_p1298921117511"></a><a name="en-us_topic_0000002515503852_p1298921117511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1799561165114"><a name="en-us_topic_0000002515503852_p1799561165114"></a><a name="en-us_topic_0000002515503852_p1799561165114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row44814564912"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1044414295516"><a name="en-us_topic_0000002515503852_p1044414295516"></a><a name="en-us_topic_0000002515503852_p1044414295516"></a><span id="en-us_topic_0000002515503852_text44441829105114"><a name="en-us_topic_0000002515503852_text44441829105114"></a><a name="en-us_topic_0000002515503852_text44441829105114"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p17181285116"><a name="en-us_topic_0000002515503852_p17181285116"></a><a name="en-us_topic_0000002515503852_p17181285116"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15131255114"><a name="en-us_topic_0000002515503852_p15131255114"></a><a name="en-us_topic_0000002515503852_p15131255114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15917127513"><a name="en-us_topic_0000002515503852_p15917127513"></a><a name="en-us_topic_0000002515503852_p15917127513"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row11171321114917"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p94441829165113"><a name="en-us_topic_0000002515503852_p94441829165113"></a><a name="en-us_topic_0000002515503852_p94441829165113"></a><span id="en-us_topic_0000002515503852_text16445122985112"><a name="en-us_topic_0000002515503852_text16445122985112"></a><a name="en-us_topic_0000002515503852_text16445122985112"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p01211275113"><a name="en-us_topic_0000002515503852_p01211275113"></a><a name="en-us_topic_0000002515503852_p01211275113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p916161212512"><a name="en-us_topic_0000002515503852_p916161212512"></a><a name="en-us_topic_0000002515503852_p916161212512"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p191911211511"><a name="en-us_topic_0000002515503852_p191911211511"></a><a name="en-us_topic_0000002515503852_p191911211511"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18385115320492"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1644572918513"><a name="en-us_topic_0000002515503852_p1644572918513"></a><a name="en-us_topic_0000002515503852_p1644572918513"></a><span id="en-us_topic_0000002515503852_text1744532925112"><a name="en-us_topic_0000002515503852_text1744532925112"></a><a name="en-us_topic_0000002515503852_text1744532925112"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1923112115119"><a name="en-us_topic_0000002515503852_p1923112115119"></a><a name="en-us_topic_0000002515503852_p1923112115119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1269122515"><a name="en-us_topic_0000002515503852_p1269122515"></a><a name="en-us_topic_0000002515503852_p1269122515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p43014126516"><a name="en-us_topic_0000002515503852_p43014126516"></a><a name="en-us_topic_0000002515503852_p43014126516"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row557915117191"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2042757191916"><a name="en-us_topic_0000002515503852_p2042757191916"></a><a name="en-us_topic_0000002515503852_p2042757191916"></a><span id="en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206627172_en-us_topic_0000001178054658_en-us_topic_0000001101324724_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
unsigned int frequency = 0;
ret = dcmi_get_device_frequency(card_id, device_id, DCMI_FREQ_DDR, &frequency);
...
```

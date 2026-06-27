# dcmi\_get\_device\_boot\_status<a name="EN-US_TOPIC_0000002546983689"></a>

**Prototype<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412077"></a>**

**int dcmi\_get\_device\_boot\_status\(int card\_id, int device\_id, enum dcmi\_boot\_status \*boot\_status\)**

**Description<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412078"></a>**

Obtains the startup status of a device.

**Parameter Description<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412079"></a>**

<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1951310333102826"><a name="b1951310333102826"></a><a name="b1951310333102826"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b540693881102458"><a name="b540693881102458"></a><a name="b540693881102458"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b842124866105345"><a name="b842124866105345"></a><a name="b842124866105345"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p8175616161117"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p8175616161117"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p8175616161117"></a>boot_status</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1817571618112"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p20175191611119"></a>enum dcmi_boot_status *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1317541616112"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1317541616112"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1317541616112"></a>enum dcmi_boot_status</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1917515160111"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1917515160111"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1917515160111"></a>{</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751216151114"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751216151114"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751216151114"></a>DCMI_BOOT_STATUS_UNINIT = 0, // Uninitialized</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751816101118"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751816101118"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p51751816101118"></a>DCMI_BOOT_STATUS_BIOS, // The BIOS is booting.</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p161757162117"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p161757162117"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p161757162117"></a>DCMI_BOOT_STATUS_OS, // The OS is booting.</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1175131618114"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1175131618114"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1175131618114"></a>DCMI_BOOT_STATUS_FINISH // Boot finished.</p>
<p id="p383616372382"><a name="p383616372382"></a><a name="p383616372382"></a>DCMI_SYSTEM_START_FINISH = 16, // The DCMI service process is started.</p>
<p id="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1217571621117"><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1217571621117"></a><a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_p1217571621117"></a>}</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b160150492785616"><a name="b160150492785616"></a><a name="b160150492785616"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_table79191646143019"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row112361107329"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p830835414314"><a name="en-us_topic_0000002515503852_p830835414314"></a><a name="en-us_topic_0000002515503852_p830835414314"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p83081544318"><a name="en-us_topic_0000002515503852_p83081544318"></a><a name="en-us_topic_0000002515503852_p83081544318"></a><strong id="en-us_topic_0000002515503852_b16446221541"><a name="en-us_topic_0000002515503852_b16446221541"></a><a name="en-us_topic_0000002515503852_b16446221541"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="24.97%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p193083549315"><a name="en-us_topic_0000002515503852_p193083549315"></a><a name="en-us_topic_0000002515503852_p193083549315"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b8976422746"><a name="en-us_topic_0000002515503852_b8976422746"></a><a name="en-us_topic_0000002515503852_b8976422746"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25.03%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p730815541319"><a name="en-us_topic_0000002515503852_p730815541319"></a><a name="en-us_topic_0000002515503852_p730815541319"></a><strong id="en-us_topic_0000002515503852_b11421124149"><a name="en-us_topic_0000002515503852_b11421124149"></a><a name="en-us_topic_0000002515503852_b11421124149"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row7236101023217"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p623641016329"><a name="en-us_topic_0000002515503852_p623641016329"></a><a name="en-us_topic_0000002515503852_p623641016329"></a><span id="en-us_topic_0000002515503852_ph8236121063219"><a name="en-us_topic_0000002515503852_ph8236121063219"></a><a name="en-us_topic_0000002515503852_ph8236121063219"></a><span id="en-us_topic_0000002515503852_text102364103324"><a name="en-us_topic_0000002515503852_text102364103324"></a><a name="en-us_topic_0000002515503852_text102364103324"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16236141013216"><a name="en-us_topic_0000002515503852_p16236141013216"></a><a name="en-us_topic_0000002515503852_p16236141013216"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p323621073219"><a name="en-us_topic_0000002515503852_p323621073219"></a><a name="en-us_topic_0000002515503852_p323621073219"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1124714309329"><a name="en-us_topic_0000002515503852_p1124714309329"></a><a name="en-us_topic_0000002515503852_p1124714309329"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row9236191063213"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p132367107328"><a name="en-us_topic_0000002515503852_p132367107328"></a><a name="en-us_topic_0000002515503852_p132367107328"></a><span id="en-us_topic_0000002515503852_text182361710173214"><a name="en-us_topic_0000002515503852_text182361710173214"></a><a name="en-us_topic_0000002515503852_text182361710173214"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1223651073215"><a name="en-us_topic_0000002515503852_p1223651073215"></a><a name="en-us_topic_0000002515503852_p1223651073215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p4236131093211"><a name="en-us_topic_0000002515503852_p4236131093211"></a><a name="en-us_topic_0000002515503852_p4236131093211"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1025623073219"><a name="en-us_topic_0000002515503852_p1025623073219"></a><a name="en-us_topic_0000002515503852_p1025623073219"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row13236121010328"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p323716106322"><a name="en-us_topic_0000002515503852_p323716106322"></a><a name="en-us_topic_0000002515503852_p323716106322"></a><span id="en-us_topic_0000002515503852_text823771020320"><a name="en-us_topic_0000002515503852_text823771020320"></a><a name="en-us_topic_0000002515503852_text823771020320"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p192371108322"><a name="en-us_topic_0000002515503852_p192371108322"></a><a name="en-us_topic_0000002515503852_p192371108322"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p192371510173210"><a name="en-us_topic_0000002515503852_p192371510173210"></a><a name="en-us_topic_0000002515503852_p192371510173210"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1026963083210"><a name="en-us_topic_0000002515503852_p1026963083210"></a><a name="en-us_topic_0000002515503852_p1026963083210"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row423781043218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p9237110133213"><a name="en-us_topic_0000002515503852_p9237110133213"></a><a name="en-us_topic_0000002515503852_p9237110133213"></a><span id="en-us_topic_0000002515503852_text723791011326"><a name="en-us_topic_0000002515503852_text723791011326"></a><a name="en-us_topic_0000002515503852_text723791011326"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p623719101321"><a name="en-us_topic_0000002515503852_p623719101321"></a><a name="en-us_topic_0000002515503852_p623719101321"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p623717104322"><a name="en-us_topic_0000002515503852_p623717104322"></a><a name="en-us_topic_0000002515503852_p623717104322"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p182841630173218"><a name="en-us_topic_0000002515503852_p182841630173218"></a><a name="en-us_topic_0000002515503852_p182841630173218"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row52377108326"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p92371110103215"><a name="en-us_topic_0000002515503852_p92371110103215"></a><a name="en-us_topic_0000002515503852_p92371110103215"></a><span id="en-us_topic_0000002515503852_text823710106326"><a name="en-us_topic_0000002515503852_text823710106326"></a><a name="en-us_topic_0000002515503852_text823710106326"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p32372010143214"><a name="en-us_topic_0000002515503852_p32372010143214"></a><a name="en-us_topic_0000002515503852_p32372010143214"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p423717106328"><a name="en-us_topic_0000002515503852_p423717106328"></a><a name="en-us_topic_0000002515503852_p423717106328"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p6300830133214"><a name="en-us_topic_0000002515503852_p6300830133214"></a><a name="en-us_topic_0000002515503852_p6300830133214"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1023761053212"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p523761093214"><a name="en-us_topic_0000002515503852_p523761093214"></a><a name="en-us_topic_0000002515503852_p523761093214"></a><span id="en-us_topic_0000002515503852_text1030320262278"><a name="en-us_topic_0000002515503852_text1030320262278"></a><a name="en-us_topic_0000002515503852_text1030320262278"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p523715105325"><a name="en-us_topic_0000002515503852_p523715105325"></a><a name="en-us_topic_0000002515503852_p523715105325"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5237110133220"><a name="en-us_topic_0000002515503852_p5237110133220"></a><a name="en-us_topic_0000002515503852_p5237110133220"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1901195083313"><a name="en-us_topic_0000002515503852_p1901195083313"></a><a name="en-us_topic_0000002515503852_p1901195083313"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1237151073213"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p32371810163213"><a name="en-us_topic_0000002515503852_p32371810163213"></a><a name="en-us_topic_0000002515503852_p32371810163213"></a><span id="en-us_topic_0000002515503852_text423716102326"><a name="en-us_topic_0000002515503852_text423716102326"></a><a name="en-us_topic_0000002515503852_text423716102326"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p20237161012323"><a name="en-us_topic_0000002515503852_p20237161012323"></a><a name="en-us_topic_0000002515503852_p20237161012323"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2023791019328"><a name="en-us_topic_0000002515503852_p2023791019328"></a><a name="en-us_topic_0000002515503852_p2023791019328"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19105505335"><a name="en-us_topic_0000002515503852_p19105505335"></a><a name="en-us_topic_0000002515503852_p19105505335"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row623791012325"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1237131016321"><a name="en-us_topic_0000002515503852_p1237131016321"></a><a name="en-us_topic_0000002515503852_p1237131016321"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251427211_en-us_topic_0000001178373160_en-us_topic_0000001101290912_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
enum dcmi_boot_status boot_status = 0;
ret = dcmi_get_device_boot_status(card_id, device_id, &boot_status);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

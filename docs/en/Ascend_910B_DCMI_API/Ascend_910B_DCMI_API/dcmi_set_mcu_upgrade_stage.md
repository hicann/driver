# dcmi\_set\_mcu\_upgrade\_stage<a name="EN-US_TOPIC_0000002546903695"></a>

**Prototype<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_toc533412077"></a>**

**int dcmi\_set\_mcu\_upgrade\_stage\(int card\_id, enum dcmi\_upgrade\_type input\_type\)**

**Description<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_toc533412078"></a>**

Controls the MCU upgrade.

**Parameter Description<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_toc533412079"></a>**

<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p10021890"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p10021890"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="12.27%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p6466753"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p6466753"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p54045009"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p54045009"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="51.790000000000006%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p15569626"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p15569626"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p36741947142813"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p36741947142813"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="12.27%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p96741747122818"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p96741747122818"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p46747472287"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p46747472287"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="51.790000000000006%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1467413474281"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1467413474281"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b389632358102915"><a name="b389632358102915"></a><a name="b389632358102915"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p147610415503"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p147610415503"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p147610415503"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="12.27%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1747620412509"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1747620412509"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1747620412509"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610435012"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610435012"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610435012"></a>enum dcmi_upgrade_type</p>
</td>
<td class="cellrowborder" valign="top" width="51.790000000000006%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610465016"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610465016"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1647610465016"></a>Upgrade phase.</p>
<p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p13726331145613"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p13726331145613"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p13726331145613"></a>enum dcmi_upgrade_type {</p>
<p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1472633115615"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1472633115615"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p1472633115615"></a>MCU_UPGRADE_START = 1,// Start the MCU upgrade.</p>
<p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p167261931195618"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p167261931195618"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p167261931195618"></a>MCU_UPGRADE_VALIDETE = 3,// Validate the MCU upgrade.</p>
<p id="p943318715425"><a name="p943318715425"></a><a name="p943318715425"></a>VRD_UPGRADE_START = 11,</p>
<p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p972673111564"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p972673111564"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p972673111564"></a>MCU_UPGRADE_NONE // Invalid value</p>
<p id="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p7726103145617"><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p7726103145617"></a><a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_p7726103145617"></a>};</p>
<p id="p1820493410573"><a name="p1820493410573"></a><a name="p1820493410573"></a>Only <strong id="b1430941076883"><a name="b1430941076883"></a><a name="b1430941076883"></a>MCU_UPGRADE_START</strong> and <strong id="b179291196883"><a name="b179291196883"></a><a name="b179291196883"></a>MCU_UPGRADE_VALIDETE</strong> are supported.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b14646989608574"><a name="b14646989608574"></a><a name="b14646989608574"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001206627198_en-us_topic_0000001178213192_en-us_topic_0000001101561454_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 1;
enum dcmi_upgrade_type input_type = MCU_UPGRADE_START;
ret = dcmi_set_mcu_upgrade_stage(card_id,input_type);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

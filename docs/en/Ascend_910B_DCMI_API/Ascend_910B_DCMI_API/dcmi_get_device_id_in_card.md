# dcmi\_get\_device\_id\_in\_card<a name="EN-US_TOPIC_0000002515343882"></a>

**Prototype<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412077"></a>**

**int dcmi\_get\_device\_id\_in\_card\(int card\_id, int \*device\_id\_max, int \*mcu\_id, int \*cpu\_id\)**

**Description<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412078"></a>**

Queries the number of chips, MCU ID, and CPU ID on a device.

**Parameter Description<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412079"></a>**

<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_row7580267"><th class="cellrowborder" valign="top" width="17.07%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p10021890"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p10021890"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.919999999999998%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p6466753"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p6466753"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p54045009"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p54045009"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p15569626"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p15569626"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_row10560021192510"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p20163113651013"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p20163113651013"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p20163113651013"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.919999999999998%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5163173611017"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5163173611017"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5163173611017"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14163153619104"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14163153619104"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14163153619104"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"></a>Device ID. The supported IDs can be obtained by calling <strong id="b16378734102732"><a name="b16378734102732"></a><a name="b16378734102732"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_row1155711494235"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p2163113616105"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p2163113616105"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p2163113616105"></a>device_id_max</p>
</td>
<td class="cellrowborder" valign="top" width="16.919999999999998%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p17163136171012"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p17163136171012"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p17163136171012"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p016343613104"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p016343613104"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p016343613104"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p7163173613102"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p7163173613102"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p7163173613102"></a>Maximum number of NPU chips on the device.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_row18153156101319"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p18154456201313"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p18154456201313"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p18154456201313"></a>mcu_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.919999999999998%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5154125611133"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5154125611133"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p5154125611133"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1815415621310"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1815415621310"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1815415621310"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p81545562136"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p81545562136"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p81545562136"></a>ID of the MCU on the device. The value <strong id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_b1460612541134"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_b1460612541134"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_b1460612541134"></a>-1</strong> indicates that there is no MCU.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_row16457959111316"><td class="cellrowborder" valign="top" width="17.07%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1345775911312"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1345775911312"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p1345775911312"></a>cpu_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.919999999999998%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14457125941313"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14457125941313"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14457125941313"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p9457059141320"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p9457059141320"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p9457059141320"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"></a>ID of the Ctrl CPU on the device. The default value is <strong id="b1867915122361"><a name="b1867915122361"></a><a name="b1867915122361"></a>-1</strong>, which has no specific meaning.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b117139412985459"><a name="b117139412985459"></a><a name="b117139412985459"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412083"></a>**

```C
...
int ret;
int device_id_max = 0;
int mcu_id = 0;
int cpu_id = 0;
int card_id = 0;
ret = dcmi_get_device_id_in_card(card_id, &device_id_max, &mcu_id, &cpu_id);
...
```

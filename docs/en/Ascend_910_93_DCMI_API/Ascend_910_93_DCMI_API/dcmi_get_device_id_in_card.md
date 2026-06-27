# dcmi\_get\_device\_id\_in\_card<a name="EN-US_TOPIC_0000002515510504"></a>

**Prototype<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412077"></a>**

**int dcmi\_get\_device\_id\_in\_card\(int card\_id, int \*device\_id\_max, int \*mcu\_id, int \*cpu\_id\)**

**Description<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412078"></a>**

Queries the number of chips, MCU ID, and CPU ID on an NPU module.

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p19163336161013"></a>Device ID. The supported IDs can be obtained by calling <strong id="b15759342194814"><a name="b15759342194814"></a><a name="b15759342194814"></a>dcmi_get_card_list</strong>.</p>
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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"></a><a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_p14626131251519"></a>ID of the Ctrl CPU on the device. The default value is <strong id="b1021210400236"><a name="b1021210400236"></a><a name="b1021210400236"></a>-1</strong>, which has no specific meaning.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b2500298257612"><a name="b2500298257612"></a><a name="b2500298257612"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p67828402447"><a name="en-us_topic_0000002515350556_p67828402447"></a><a name="en-us_topic_0000002515350556_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p16315103817414"><a name="en-us_topic_0000002515350556_p16315103817414"></a><a name="en-us_topic_0000002515350556_p16315103817414"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row125012052104311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1378374019445"><a name="en-us_topic_0000002515350556_p1378374019445"></a><a name="en-us_topic_0000002515350556_p1378374019445"></a><span id="en-us_topic_0000002515350556_text262011415447"><a name="en-us_topic_0000002515350556_text262011415447"></a><a name="en-us_topic_0000002515350556_text262011415447"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p3696134919457"><a name="en-us_topic_0000002515350556_p3696134919457"></a><a name="en-us_topic_0000002515350556_p3696134919457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1069610491457"><a name="en-us_topic_0000002515350556_p1069610491457"></a><a name="en-us_topic_0000002515350556_p1069610491457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14744104011463"><a name="en-us_topic_0000002515350556_p14744104011463"></a><a name="en-us_topic_0000002515350556_p14744104011463"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p137832403444"><a name="en-us_topic_0000002515350556_p137832403444"></a><a name="en-us_topic_0000002515350556_p137832403444"></a><span id="en-us_topic_0000002515350556_text1480012462513"><a name="en-us_topic_0000002515350556_text1480012462513"></a><a name="en-us_topic_0000002515350556_text1480012462513"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17744194024612"><a name="en-us_topic_0000002515350556_p17744194024612"></a><a name="en-us_topic_0000002515350556_p17744194024612"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row195142220363"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p19150201815714"><a name="en-us_topic_0000002515350556_p19150201815714"></a><a name="en-us_topic_0000002515350556_p19150201815714"></a><span id="en-us_topic_0000002515350556_text1615010187716"><a name="en-us_topic_0000002515350556_text1615010187716"></a><a name="en-us_topic_0000002515350556_text1615010187716"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1831093744715"><a name="en-us_topic_0000002515350556_p1831093744715"></a><a name="en-us_topic_0000002515350556_p1831093744715"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9310337164720"><a name="en-us_topic_0000002515350556_p9310337164720"></a><a name="en-us_topic_0000002515350556_p9310337164720"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p10310113714473"><a name="en-us_topic_0000002515350556_p10310113714473"></a><a name="en-us_topic_0000002515350556_p10310113714473"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1024616413271"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1824612411277"><a name="en-us_topic_0000002515350556_p1824612411277"></a><a name="en-us_topic_0000002515350556_p1824612411277"></a><span id="en-us_topic_0000002515350556_text712252182813"><a name="en-us_topic_0000002515350556_text712252182813"></a><a name="en-us_topic_0000002515350556_text712252182813"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p436771642813"><a name="en-us_topic_0000002515350556_p436771642813"></a><a name="en-us_topic_0000002515350556_p436771642813"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p436710164281"><a name="en-us_topic_0000002515350556_p436710164281"></a><a name="en-us_topic_0000002515350556_p436710164281"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p193671116172816"><a name="en-us_topic_0000002515350556_p193671116172816"></a><a name="en-us_topic_0000002515350556_p193671116172816"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row11011140184711"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1010254064715"><a name="en-us_topic_0000002515350556_p1010254064715"></a><a name="en-us_topic_0000002515350556_p1010254064715"></a><span id="en-us_topic_0000002515350556_text15548246175319"><a name="en-us_topic_0000002515350556_text15548246175319"></a><a name="en-us_topic_0000002515350556_text15548246175319"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p0636155115534"><a name="en-us_topic_0000002515350556_p0636155115534"></a><a name="en-us_topic_0000002515350556_p0636155115534"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p16636951125317"><a name="en-us_topic_0000002515350556_p16636951125317"></a><a name="en-us_topic_0000002515350556_p16636951125317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p163685125315"><a name="en-us_topic_0000002515350556_p163685125315"></a><a name="en-us_topic_0000002515350556_p163685125315"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row7398193211715"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12881158154715"><a name="en-us_topic_0000002515350556_p12881158154715"></a><a name="en-us_topic_0000002515350556_p12881158154715"></a>Note: <strong id="en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251227183_en-us_topic_0000001177894702_en-us_topic_0000001170697495_toc533412083"></a>**

```c
...
int ret;
int device_id_max = 0;
int mcu_id = 0;
int cpu_id = 0;
int card_id = 0;
ret = dcmi_get_device_id_in_card(card_id, &device_id_max, &mcu_id, &cpu_id);
...
```

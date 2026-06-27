# dcmi\_get\_device\_component\_count<a name="EN-US_TOPIC_0000002546990453"></a>

**Prototype<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_toc533412077"></a>**

**int dcmi\_get\_device\_component\_count\(int card\_id, int device\_id, unsigned int \*component\_count\)**

**Description<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_toc533412078"></a>**

Obtains the upgradable component count.

**Parameter Description<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_toc533412079"></a>**

<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row7580267"><th class="cellrowborder" valign="top" width="19.62%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p10021890"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p10021890"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="14.48%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p6466753"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p6466753"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="15.9%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p54045009"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p54045009"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p15569626"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p15569626"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row10560021192510"><td class="cellrowborder" valign="top" width="19.62%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p36741947142813"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p36741947142813"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.48%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p96741747122818"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p96741747122818"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p46747472287"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p46747472287"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1467413474281"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1467413474281"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b40754753332950"><a name="b40754753332950"></a><a name="b40754753332950"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row1155711494235"><td class="cellrowborder" valign="top" width="19.62%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p7711145152918"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p7711145152918"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.48%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p671116522914"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p671116522914"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1771116572910"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1771116572910"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b185675637232926"><a name="b185675637232926"></a><a name="b185675637232926"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b107152294055858"><a name="b107152294055858"></a><a name="b107152294055858"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row15462171542913"><td class="cellrowborder" valign="top" width="19.62%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p5522164215178"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p5522164215178"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p5522164215178"></a>component_count</p>
</td>
<td class="cellrowborder" valign="top" width="14.48%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8522242101715"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8522242101715"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8522242101715"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p17522114220174"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p17522114220174"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p17522114220174"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1682695217315"><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1682695217315"></a><a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p1682695217315"></a>Component count.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b13480044985653"><a name="b13480044985653"></a><a name="b13480044985653"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table18698834121214"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row18113171210"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1881934126"><a name="en-us_topic_0000002515350556_p1881934126"></a><a name="en-us_topic_0000002515350556_p1881934126"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p168143181218"><a name="en-us_topic_0000002515350556_p168143181218"></a><a name="en-us_topic_0000002515350556_p168143181218"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p88110314129"><a name="en-us_topic_0000002515350556_p88110314129"></a><a name="en-us_topic_0000002515350556_p88110314129"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row681203121213"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p11812310123"><a name="en-us_topic_0000002515350556_p11812310123"></a><a name="en-us_topic_0000002515350556_p11812310123"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p188215311122"><a name="en-us_topic_0000002515350556_p188215311122"></a><a name="en-us_topic_0000002515350556_p188215311122"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p58213311210"><a name="en-us_topic_0000002515350556_p58213311210"></a><a name="en-us_topic_0000002515350556_p58213311210"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row38243131214"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p48210361212"><a name="en-us_topic_0000002515350556_p48210361212"></a><a name="en-us_topic_0000002515350556_p48210361212"></a><span id="en-us_topic_0000002515350556_text16821238124"><a name="en-us_topic_0000002515350556_text16821238124"></a><a name="en-us_topic_0000002515350556_text16821238124"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1990911717125"><a name="en-us_topic_0000002515350556_p1990911717125"></a><a name="en-us_topic_0000002515350556_p1990911717125"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1590914714124"><a name="en-us_topic_0000002515350556_p1590914714124"></a><a name="en-us_topic_0000002515350556_p1590914714124"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p9909273125"><a name="en-us_topic_0000002515350556_p9909273125"></a><a name="en-us_topic_0000002515350556_p9909273125"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row982437122"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p4829381220"><a name="en-us_topic_0000002515350556_p4829381220"></a><a name="en-us_topic_0000002515350556_p4829381220"></a><span id="en-us_topic_0000002515350556_text582173201218"><a name="en-us_topic_0000002515350556_text582173201218"></a><a name="en-us_topic_0000002515350556_text582173201218"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p59098719121"><a name="en-us_topic_0000002515350556_p59098719121"></a><a name="en-us_topic_0000002515350556_p59098719121"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p20909197161211"><a name="en-us_topic_0000002515350556_p20909197161211"></a><a name="en-us_topic_0000002515350556_p20909197161211"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p199091074123"><a name="en-us_topic_0000002515350556_p199091074123"></a><a name="en-us_topic_0000002515350556_p199091074123"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1782915383548"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p988163171613"><a name="en-us_topic_0000002515350556_p988163171613"></a><a name="en-us_topic_0000002515350556_p988163171613"></a><span id="en-us_topic_0000002515350556_text28812351611"><a name="en-us_topic_0000002515350556_text28812351611"></a><a name="en-us_topic_0000002515350556_text28812351611"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p107731653135415"><a name="en-us_topic_0000002515350556_p107731653135415"></a><a name="en-us_topic_0000002515350556_p107731653135415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p77730531545"><a name="en-us_topic_0000002515350556_p77730531545"></a><a name="en-us_topic_0000002515350556_p77730531545"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8773153175410"><a name="en-us_topic_0000002515350556_p8773153175410"></a><a name="en-us_topic_0000002515350556_p8773153175410"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19683944122816"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p19717154811286"><a name="en-us_topic_0000002515350556_p19717154811286"></a><a name="en-us_topic_0000002515350556_p19717154811286"></a><span id="en-us_topic_0000002515350556_text5717204812817"><a name="en-us_topic_0000002515350556_text5717204812817"></a><a name="en-us_topic_0000002515350556_text5717204812817"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p13998205142815"><a name="en-us_topic_0000002515350556_p13998205142815"></a><a name="en-us_topic_0000002515350556_p13998205142815"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p49983512287"><a name="en-us_topic_0000002515350556_p49983512287"></a><a name="en-us_topic_0000002515350556_p49983512287"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p89988518280"><a name="en-us_topic_0000002515350556_p89988518280"></a><a name="en-us_topic_0000002515350556_p89988518280"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row06711416544"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1765294655411"><a name="en-us_topic_0000002515350556_p1765294655411"></a><a name="en-us_topic_0000002515350556_p1765294655411"></a><span id="en-us_topic_0000002515350556_text19652946185414"><a name="en-us_topic_0000002515350556_text19652946185414"></a><a name="en-us_topic_0000002515350556_text19652946185414"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p428811549547"><a name="en-us_topic_0000002515350556_p428811549547"></a><a name="en-us_topic_0000002515350556_p428811549547"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p15288954155420"><a name="en-us_topic_0000002515350556_p15288954155420"></a><a name="en-us_topic_0000002515350556_p15288954155420"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p192881754115412"><a name="en-us_topic_0000002515350556_p192881754115412"></a><a name="en-us_topic_0000002515350556_p192881754115412"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row13182101810819"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p104761521386"><a name="en-us_topic_0000002515350556_p104761521386"></a><a name="en-us_topic_0000002515350556_p104761521386"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
unsigned int component_num = 0;
ret =dcmi_get_device_component_count(card_id, device_id, &component_num);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

# dcmi\_clear\_pfc\_duration<a name="EN-US_TOPIC_0000002546910339"></a>

**Prototype<a name="section12365583546"></a>**

**int dcmi\_clear\_pfc\_duration\(int card\_id, int device\_id\)**

**Description<a name="section142361658175418"></a>**

Clears statistics of the PFC backpressure frame duration on a specified device.

**Parameter Description<a name="section32371758125411"></a>**

<a name="table2274145813545"></a>
<table><thead align="left"><tr id="row106575945418"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p665759125418"><a name="p665759125418"></a><a name="p665759125418"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p10659593544"><a name="p10659593544"></a><a name="p10659593544"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p1265259155414"><a name="p1265259155414"></a><a name="p1265259155414"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p196611598540"><a name="p196611598540"></a><a name="p196611598540"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row106685915545"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p76613598548"><a name="p76613598548"></a><a name="p76613598548"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p196625985410"><a name="p196625985410"></a><a name="p196625985410"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p4661459185416"><a name="p4661459185416"></a><a name="p4661459185416"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p8662594544"><a name="p8662594544"></a><a name="p8662594544"></a>Device ID. The supported IDs can be obtained by calling <strong id="b15993999081716"><a name="b15993999081716"></a><a name="b15993999081716"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1662595540"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p16610593540"><a name="p16610593540"></a><a name="p16610593540"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p06675913543"><a name="p06675913543"></a><a name="p06675913543"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1666159175411"><a name="p1666159175411"></a><a name="p1666159175411"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p176616594547"><a name="p176616594547"></a><a name="p176616594547"></a>Chip ID, which can be obtained by calling <strong id="b112202894033044"><a name="b112202894033044"></a><a name="b112202894033044"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p2066359185415"><a name="p2066359185415"></a><a name="p2066359185415"></a>NPU: [0, <strong id="b66874189425451"><a name="b66874189425451"></a><a name="b66874189425451"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section124813589544"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b3431442967234"><a name="b3431442967234"></a><a name="b3431442967234"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1225565895419"></a>**

None

**Restrictions<a name="section1625614581546"></a>**

This API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="table4146152515545"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row2051415544912"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p20514155144920"><a name="en-us_topic_0000002515350556_p20514155144920"></a><a name="en-us_topic_0000002515350556_p20514155144920"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p10514165204915"><a name="en-us_topic_0000002515350556_p10514165204915"></a><a name="en-us_topic_0000002515350556_p10514165204915"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p4514956491"><a name="en-us_topic_0000002515350556_p4514956491"></a><a name="en-us_topic_0000002515350556_p4514956491"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row145145524918"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p85141551498"><a name="en-us_topic_0000002515350556_p85141551498"></a><a name="en-us_topic_0000002515350556_p85141551498"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p10514185134916"><a name="en-us_topic_0000002515350556_p10514185134916"></a><a name="en-us_topic_0000002515350556_p10514185134916"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p7514656494"><a name="en-us_topic_0000002515350556_p7514656494"></a><a name="en-us_topic_0000002515350556_p7514656494"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row135148510490"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p11514155490"><a name="en-us_topic_0000002515350556_p11514155490"></a><a name="en-us_topic_0000002515350556_p11514155490"></a><span id="en-us_topic_0000002515350556_text551465114917"><a name="en-us_topic_0000002515350556_text551465114917"></a><a name="en-us_topic_0000002515350556_text551465114917"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p185143564913"><a name="en-us_topic_0000002515350556_p185143564913"></a><a name="en-us_topic_0000002515350556_p185143564913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p185145519497"><a name="en-us_topic_0000002515350556_p185145519497"></a><a name="en-us_topic_0000002515350556_p185145519497"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1751413513498"><a name="en-us_topic_0000002515350556_p1751413513498"></a><a name="en-us_topic_0000002515350556_p1751413513498"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row135141553491"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1351411524913"><a name="en-us_topic_0000002515350556_p1351411524913"></a><a name="en-us_topic_0000002515350556_p1351411524913"></a><span id="en-us_topic_0000002515350556_text175141751499"><a name="en-us_topic_0000002515350556_text175141751499"></a><a name="en-us_topic_0000002515350556_text175141751499"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1034521615495"><a name="en-us_topic_0000002515350556_p1034521615495"></a><a name="en-us_topic_0000002515350556_p1034521615495"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6514145154913"><a name="en-us_topic_0000002515350556_p6514145154913"></a><a name="en-us_topic_0000002515350556_p6514145154913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17514145184914"><a name="en-us_topic_0000002515350556_p17514145184914"></a><a name="en-us_topic_0000002515350556_p17514145184914"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row183721515155518"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p923812139165"><a name="en-us_topic_0000002515350556_p923812139165"></a><a name="en-us_topic_0000002515350556_p923812139165"></a><span id="en-us_topic_0000002515350556_text8238111381610"><a name="en-us_topic_0000002515350556_text8238111381610"></a><a name="en-us_topic_0000002515350556_text8238111381610"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1858019263555"><a name="en-us_topic_0000002515350556_p1858019263555"></a><a name="en-us_topic_0000002515350556_p1858019263555"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p125801926195517"><a name="en-us_topic_0000002515350556_p125801926195517"></a><a name="en-us_topic_0000002515350556_p125801926195517"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p125808265554"><a name="en-us_topic_0000002515350556_p125808265554"></a><a name="en-us_topic_0000002515350556_p125808265554"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1828812107299"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p4288010192914"><a name="en-us_topic_0000002515350556_p4288010192914"></a><a name="en-us_topic_0000002515350556_p4288010192914"></a><span id="en-us_topic_0000002515350556_text17252201592911"><a name="en-us_topic_0000002515350556_text17252201592911"></a><a name="en-us_topic_0000002515350556_text17252201592911"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p14729171810297"><a name="en-us_topic_0000002515350556_p14729171810297"></a><a name="en-us_topic_0000002515350556_p14729171810297"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p187294185296"><a name="en-us_topic_0000002515350556_p187294185296"></a><a name="en-us_topic_0000002515350556_p187294185296"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p12729918182916"><a name="en-us_topic_0000002515350556_p12729918182916"></a><a name="en-us_topic_0000002515350556_p12729918182916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row8768181557"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1563212213554"><a name="en-us_topic_0000002515350556_p1563212213554"></a><a name="en-us_topic_0000002515350556_p1563212213554"></a><span id="en-us_topic_0000002515350556_text1963217219554"><a name="en-us_topic_0000002515350556_text1963217219554"></a><a name="en-us_topic_0000002515350556_text1963217219554"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p18671727165520"><a name="en-us_topic_0000002515350556_p18671727165520"></a><a name="en-us_topic_0000002515350556_p18671727165520"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p967152775514"><a name="en-us_topic_0000002515350556_p967152775514"></a><a name="en-us_topic_0000002515350556_p967152775514"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p667192712555"><a name="en-us_topic_0000002515350556_p667192712555"></a><a name="en-us_topic_0000002515350556_p667192712555"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row207580351817"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1339643920818"><a name="en-us_topic_0000002515350556_p1339643920818"></a><a name="en-us_topic_0000002515350556_p1339643920818"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section192671558125418"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
ret = dcmi_clear_pfc_duration(card_id, device_id);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

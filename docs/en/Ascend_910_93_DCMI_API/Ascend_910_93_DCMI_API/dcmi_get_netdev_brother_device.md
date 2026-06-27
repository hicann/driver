# dcmi\_get\_netdev\_brother\_device<a name="EN-US_TOPIC_0000002546910351"></a>

**Prototype<a name="section1270910248495"></a>**

**int dcmi\_get\_netdev\_brother\_device\(int card\_id, int device\_id, int \*brother\_card\_id\)**

**Description<a name="section270992444920"></a>**

Obtains the NPU modules that have network port cooperation relationships.

**Parameter Description<a name="section2071012242493"></a>**

<a name="table3721102412494"></a>
<table><thead align="left"><tr id="row127491124114913"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p67494249498"><a name="p67494249498"></a><a name="p67494249498"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p37491124164919"><a name="p37491124164919"></a><a name="p37491124164919"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p117491224194917"><a name="p117491224194917"></a><a name="p117491224194917"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p127491124144914"><a name="p127491124144914"></a><a name="p127491124144914"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row12749132418498"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p107491624154917"><a name="p107491624154917"></a><a name="p107491624154917"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12749122414916"><a name="p12749122414916"></a><a name="p12749122414916"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p6749162494917"><a name="p6749162494917"></a><a name="p6749162494917"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p57498247497"><a name="p57498247497"></a><a name="p57498247497"></a>Device ID. The supported IDs can be obtained by calling <strong id="b159747261433054"><a name="b159747261433054"></a><a name="b159747261433054"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row87494247496"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p10749142424913"><a name="p10749142424913"></a><a name="p10749142424913"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p117498243494"><a name="p117498243494"></a><a name="p117498243494"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p974912245493"><a name="p974912245493"></a><a name="p974912245493"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1974915243493"><a name="p1974915243493"></a><a name="p1974915243493"></a>Chip ID, which can be obtained by calling <strong id="b69740092581412"><a name="b69740092581412"></a><a name="b69740092581412"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p5749132411491"><a name="p5749132411491"></a><a name="p5749132411491"></a>NPU: [0, <strong id="b5523175692554"><a name="b5523175692554"></a><a name="b5523175692554"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row2749024144914"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p574912247499"><a name="p574912247499"></a><a name="p574912247499"></a>brother_card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p17749182413495"><a name="p17749182413495"></a><a name="p17749182413495"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1874952414920"><a name="p1874952414920"></a><a name="p1874952414920"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p574992424916"><a name="p574992424916"></a><a name="p574992424916"></a>Obtains the NPU modules that have network port cooperation relationships with a specified NPU module.</p>
<div class="note" id="note1112231016819"><a name="note1112231016819"></a><a name="note1112231016819"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p137832403444"><a name="p137832403444"></a><a name="p137832403444"></a>For the <span id="text1480012462513"><a name="text1480012462513"></a><a name="text1480012462513"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span>, <strong id="b43390928781412"><a name="b43390928781412"></a><a name="b43390928781412"></a>-1</strong> is returned because no NPU module with network port cooperation relationships exists.</p>
</div></div>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section2071417249494"></a>**

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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b1741291517922"><a name="b1741291517922"></a><a name="b1741291517922"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section67171124154919"></a>**

None

**Restrictions<a name="section771717243498"></a>**

This API cannot be used when all NPU modules are lost or do not exist.

This API is supported in privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table7724192414490"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row913516862011"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1913568182013"><a name="en-us_topic_0000002515350556_p1913568182013"></a><a name="en-us_topic_0000002515350556_p1913568182013"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p1713588142014"><a name="en-us_topic_0000002515350556_p1713588142014"></a><a name="en-us_topic_0000002515350556_p1713588142014"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p161354852013"><a name="en-us_topic_0000002515350556_p161354852013"></a><a name="en-us_topic_0000002515350556_p161354852013"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row17135168192014"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p16135128182017"><a name="en-us_topic_0000002515350556_p16135128182017"></a><a name="en-us_topic_0000002515350556_p16135128182017"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1713528202015"><a name="en-us_topic_0000002515350556_p1713528202015"></a><a name="en-us_topic_0000002515350556_p1713528202015"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p181351087205"><a name="en-us_topic_0000002515350556_p181351087205"></a><a name="en-us_topic_0000002515350556_p181351087205"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row31351488206"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p6135185208"><a name="en-us_topic_0000002515350556_p6135185208"></a><a name="en-us_topic_0000002515350556_p6135185208"></a><span id="en-us_topic_0000002515350556_text1213528172016"><a name="en-us_topic_0000002515350556_text1213528172016"></a><a name="en-us_topic_0000002515350556_text1213528172016"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1213511813205"><a name="en-us_topic_0000002515350556_p1213511813205"></a><a name="en-us_topic_0000002515350556_p1213511813205"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p613528102020"><a name="en-us_topic_0000002515350556_p613528102020"></a><a name="en-us_topic_0000002515350556_p613528102020"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p713512862013"><a name="en-us_topic_0000002515350556_p713512862013"></a><a name="en-us_topic_0000002515350556_p713512862013"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1813515811208"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p71354810207"><a name="en-us_topic_0000002515350556_p71354810207"></a><a name="en-us_topic_0000002515350556_p71354810207"></a><span id="en-us_topic_0000002515350556_text51358812207"><a name="en-us_topic_0000002515350556_text51358812207"></a><a name="en-us_topic_0000002515350556_text51358812207"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p213568152019"><a name="en-us_topic_0000002515350556_p213568152019"></a><a name="en-us_topic_0000002515350556_p213568152019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1613548142019"><a name="en-us_topic_0000002515350556_p1613548142019"></a><a name="en-us_topic_0000002515350556_p1613548142019"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11351087209"><a name="en-us_topic_0000002515350556_p11351087209"></a><a name="en-us_topic_0000002515350556_p11351087209"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row87611016195410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p8296259161515"><a name="en-us_topic_0000002515350556_p8296259161515"></a><a name="en-us_topic_0000002515350556_p8296259161515"></a><span id="en-us_topic_0000002515350556_text14296259131514"><a name="en-us_topic_0000002515350556_text14296259131514"></a><a name="en-us_topic_0000002515350556_text14296259131514"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1451920314542"><a name="en-us_topic_0000002515350556_p1451920314542"></a><a name="en-us_topic_0000002515350556_p1451920314542"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p2519133155413"><a name="en-us_topic_0000002515350556_p2519133155413"></a><a name="en-us_topic_0000002515350556_p2519133155413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p11519153110545"><a name="en-us_topic_0000002515350556_p11519153110545"></a><a name="en-us_topic_0000002515350556_p11519153110545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row0323633152810"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p064011372281"><a name="en-us_topic_0000002515350556_p064011372281"></a><a name="en-us_topic_0000002515350556_p064011372281"></a><span id="en-us_topic_0000002515350556_text18640537162811"><a name="en-us_topic_0000002515350556_text18640537162811"></a><a name="en-us_topic_0000002515350556_text18640537162811"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p279104012287"><a name="en-us_topic_0000002515350556_p279104012287"></a><a name="en-us_topic_0000002515350556_p279104012287"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p779112409289"><a name="en-us_topic_0000002515350556_p779112409289"></a><a name="en-us_topic_0000002515350556_p779112409289"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1791140112816"><a name="en-us_topic_0000002515350556_p1791140112816"></a><a name="en-us_topic_0000002515350556_p1791140112816"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row49081418125411"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p512952510545"><a name="en-us_topic_0000002515350556_p512952510545"></a><a name="en-us_topic_0000002515350556_p512952510545"></a><span id="en-us_topic_0000002515350556_text012942512545"><a name="en-us_topic_0000002515350556_text012942512545"></a><a name="en-us_topic_0000002515350556_text012942512545"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1260932135413"><a name="en-us_topic_0000002515350556_p1260932135413"></a><a name="en-us_topic_0000002515350556_p1260932135413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1660133285419"><a name="en-us_topic_0000002515350556_p1660133285419"></a><a name="en-us_topic_0000002515350556_p1660133285419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p46017321545"><a name="en-us_topic_0000002515350556_p46017321545"></a><a name="en-us_topic_0000002515350556_p46017321545"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1625111184"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1386118141085"><a name="en-us_topic_0000002515350556_p1386118141085"></a><a name="en-us_topic_0000002515350556_p1386118141085"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section9721024124910"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int brother_card_id = 0;
ret= dcmi_init();
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
ret = dcmi_get_netdev_brother_device (card_id, device_id, &brother_card_id);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
...
```

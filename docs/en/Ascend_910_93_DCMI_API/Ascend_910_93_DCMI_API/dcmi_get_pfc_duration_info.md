# dcmi\_get\_pfc\_duration\_info<a name="EN-US_TOPIC_0000002515350566"></a>

**Prototype<a name="section1873810317462"></a>**

**int dcmi\_get\_pfc\_duration\_info\(int card\_id, int device\_id, struct dcmi\_pfc\_duration\_info \*pfc\_duration\_info\)**

**Description<a name="section474073164613"></a>**

Obtains statistics of the PFC backpressure frame duration on a specified device.

**Parameter Description<a name="section167411314464"></a>**

<a name="table87791434466"></a>
<table><thead align="left"><tr id="row285620314611"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p118569324610"><a name="p118569324610"></a><a name="p118569324610"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p6856113174610"><a name="p6856113174610"></a><a name="p6856113174610"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p38568320467"><a name="p38568320467"></a><a name="p38568320467"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p1885620311466"><a name="p1885620311466"></a><a name="p1885620311466"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row78563334615"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1085613312465"><a name="p1085613312465"></a><a name="p1085613312465"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p685614313466"><a name="p685614313466"></a><a name="p685614313466"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p485612319469"><a name="p485612319469"></a><a name="p485612319469"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p285611384617"><a name="p285611384617"></a><a name="p285611384617"></a>Device ID. The supported IDs can be obtained by calling <strong id="b14021737128159"><a name="b14021737128159"></a><a name="b14021737128159"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row485615313467"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p198565334613"><a name="p198565334613"></a><a name="p198565334613"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16856183104614"><a name="p16856183104614"></a><a name="p16856183104614"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p138563311469"><a name="p138563311469"></a><a name="p138563311469"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p885719354617"><a name="p885719354617"></a><a name="p885719354617"></a>Chip ID, which can be obtained by calling <strong id="b139775821833044"><a name="b139775821833044"></a><a name="b139775821833044"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p9857837462"><a name="p9857837462"></a><a name="p9857837462"></a>NPU: [0, <strong id="b70164735725450"><a name="b70164735725450"></a><a name="b70164735725450"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row085714312464"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p128571338465"><a name="p128571338465"></a><a name="p128571338465"></a>pfc_duration_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p18857634463"><a name="p18857634463"></a><a name="p18857634463"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p485712364616"><a name="p485712364616"></a><a name="p485712364616"></a>struct dcmi_pfc_duration_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p168570364612"><a name="p168570364612"></a><a name="p168570364612"></a>PFC pause duration value. The structure is as follows:</p>
<p id="p08573364614"><a name="p08573364614"></a><a name="p08573364614"></a>unsigned long long tx[PRI_NUM];// Duration of the sent backpressure frames</p>
<p id="p98572334615"><a name="p98572334615"></a><a name="p98572334615"></a>unsigned long long rx[PRI_NUM];// Duration of the received backpressure frames</p>
<p id="p158581136465"><a name="p158581136465"></a><a name="p158581136465"></a>PRI_NUM=8;// Eight priority queues</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section197595384611"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b7784361887233"><a name="b7784361887233"></a><a name="b7784361887233"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section11766193124614"></a>**

None

**Restrictions<a name="section14766153174617"></a>**

This API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="table4259182819534"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row167572745119"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1475827105114"><a name="en-us_topic_0000002515350556_p1475827105114"></a><a name="en-us_topic_0000002515350556_p1475827105114"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p10758276511"><a name="en-us_topic_0000002515350556_p10758276511"></a><a name="en-us_topic_0000002515350556_p10758276511"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p1375727105110"><a name="en-us_topic_0000002515350556_p1375727105110"></a><a name="en-us_topic_0000002515350556_p1375727105110"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row107511272514"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p77512795111"><a name="en-us_topic_0000002515350556_p77512795111"></a><a name="en-us_topic_0000002515350556_p77512795111"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p167519276516"><a name="en-us_topic_0000002515350556_p167519276516"></a><a name="en-us_topic_0000002515350556_p167519276516"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p197562765117"><a name="en-us_topic_0000002515350556_p197562765117"></a><a name="en-us_topic_0000002515350556_p197562765117"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row375192710515"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p875927195114"><a name="en-us_topic_0000002515350556_p875927195114"></a><a name="en-us_topic_0000002515350556_p875927195114"></a><span id="en-us_topic_0000002515350556_text1675627145111"><a name="en-us_topic_0000002515350556_text1675627145111"></a><a name="en-us_topic_0000002515350556_text1675627145111"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p6407361513"><a name="en-us_topic_0000002515350556_p6407361513"></a><a name="en-us_topic_0000002515350556_p6407361513"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p940636125119"><a name="en-us_topic_0000002515350556_p940636125119"></a><a name="en-us_topic_0000002515350556_p940636125119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p9696114984512"><a name="en-us_topic_0000002515350556_p9696114984512"></a><a name="en-us_topic_0000002515350556_p9696114984512"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row275102717519"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p2075132716516"><a name="en-us_topic_0000002515350556_p2075132716516"></a><a name="en-us_topic_0000002515350556_p2075132716516"></a><span id="en-us_topic_0000002515350556_text13751027165113"><a name="en-us_topic_0000002515350556_text13751027165113"></a><a name="en-us_topic_0000002515350556_text13751027165113"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1940103619515"><a name="en-us_topic_0000002515350556_p1940103619515"></a><a name="en-us_topic_0000002515350556_p1940103619515"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p540163695113"><a name="en-us_topic_0000002515350556_p540163695113"></a><a name="en-us_topic_0000002515350556_p540163695113"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row187731356165317"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p117351854181512"><a name="en-us_topic_0000002515350556_p117351854181512"></a><a name="en-us_topic_0000002515350556_p117351854181512"></a><span id="en-us_topic_0000002515350556_text2735195461519"><a name="en-us_topic_0000002515350556_text2735195461519"></a><a name="en-us_topic_0000002515350556_text2735195461519"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p634151145413"><a name="en-us_topic_0000002515350556_p634151145413"></a><a name="en-us_topic_0000002515350556_p634151145413"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p23451112546"><a name="en-us_topic_0000002515350556_p23451112546"></a><a name="en-us_topic_0000002515350556_p23451112546"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17341711125412"><a name="en-us_topic_0000002515350556_p17341711125412"></a><a name="en-us_topic_0000002515350556_p17341711125412"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row8563102502812"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p652216261281"><a name="en-us_topic_0000002515350556_p652216261281"></a><a name="en-us_topic_0000002515350556_p652216261281"></a><span id="en-us_topic_0000002515350556_text1052312672813"><a name="en-us_topic_0000002515350556_text1052312672813"></a><a name="en-us_topic_0000002515350556_text1052312672813"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1831493072811"><a name="en-us_topic_0000002515350556_p1831493072811"></a><a name="en-us_topic_0000002515350556_p1831493072811"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9314630112816"><a name="en-us_topic_0000002515350556_p9314630112816"></a><a name="en-us_topic_0000002515350556_p9314630112816"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p143141630152813"><a name="en-us_topic_0000002515350556_p143141630152813"></a><a name="en-us_topic_0000002515350556_p143141630152813"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14552134547"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p743211475410"><a name="en-us_topic_0000002515350556_p743211475410"></a><a name="en-us_topic_0000002515350556_p743211475410"></a><span id="en-us_topic_0000002515350556_text243216485414"><a name="en-us_topic_0000002515350556_text243216485414"></a><a name="en-us_topic_0000002515350556_text243216485414"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p16629121175419"><a name="en-us_topic_0000002515350556_p16629121175419"></a><a name="en-us_topic_0000002515350556_p16629121175419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1162991125418"><a name="en-us_topic_0000002515350556_p1162991125418"></a><a name="en-us_topic_0000002515350556_p1162991125418"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8629121114549"><a name="en-us_topic_0000002515350556_p8629121114549"></a><a name="en-us_topic_0000002515350556_p8629121114549"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14550155011712"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1550115418718"><a name="en-us_topic_0000002515350556_p1550115418718"></a><a name="en-us_topic_0000002515350556_p1550115418718"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section12776336460"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
struct dcmi_pfc_duration_info pfc_duration_info = {0};
ret = dcmi_get_pfc_duration_info(card_id, device_id, &pfc_duration_info);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

# dcmi\_get\_affinity\_cpu\_info\_by\_device\_id<a name="EN-US_TOPIC_0000002546910377"></a>

**Prototype<a name="section0487181861417"></a>**

**int dcmi\_get\_affinity\_cpu\_info\_by\_device\_id\(int card\_id, int device\_id, char \*affinity\_cpu, int \*length\)**

**Description<a name="section248711861419"></a>**

Queries the CPU affinity of an NPU.

**Parameter Description<a name="section448711891417"></a>**

<a name="table348771812142"></a>
<table><thead align="left"><tr id="row1487918101413"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p1048720181148"><a name="p1048720181148"></a><a name="p1048720181148"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p11487151841419"><a name="p11487151841419"></a><a name="p11487151841419"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p184876188146"><a name="p184876188146"></a><a name="p184876188146"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p34881318151413"><a name="p34881318151413"></a><a name="p34881318151413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row34882018191416"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p14488918161410"><a name="p14488918161410"></a><a name="p14488918161410"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p164889188148"><a name="p164889188148"></a><a name="p164889188148"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p10488151821418"><a name="p10488151821418"></a><a name="p10488151821418"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1148821831412"><a name="p1148821831412"></a><a name="p1148821831412"></a>Device ID. The supported IDs can be obtained by calling <strong id="b147416368333024"><a name="b147416368333024"></a><a name="b147416368333024"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1748881815146"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p74884186146"><a name="p74884186146"></a><a name="p74884186146"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p54881818151413"><a name="p54881818151413"></a><a name="p54881818151413"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p2488131815149"><a name="p2488131815149"></a><a name="p2488131815149"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p0488191813149"><a name="p0488191813149"></a><a name="p0488191813149"></a>Chip ID, which can be obtained by calling <strong id="b125148595581435"><a name="b125148595581435"></a><a name="b125148595581435"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p450968185915"><a name="p450968185915"></a><a name="p450968185915"></a>NPU: [0, <strong id="b53322558481435"><a name="b53322558481435"></a><a name="b53322558481435"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row048812180148"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p18489131814145"><a name="p18489131814145"></a><a name="p18489131814145"></a>affinity_cpu</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p16489141813146"><a name="p16489141813146"></a><a name="p16489141813146"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1148912180142"><a name="p1148912180142"></a><a name="p1148912180142"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1048951841415"><a name="p1048951841415"></a><a name="p1048951841415"></a>CPU affinity of a specified NPU.</p>
</td>
</tr>
<tr id="row10489318191418"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p16489718161414"><a name="p16489718161414"></a><a name="p16489718161414"></a>length</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p0489818161416"><a name="p0489818161416"></a><a name="p0489818161416"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p14489111811420"><a name="p14489111811420"></a><a name="p14489111811420"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1848911801411"><a name="p1848911801411"></a><a name="p1848911801411"></a>Length of the affinity string.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b59816776272257"><a name="b59816776272257"></a><a name="b59816776272257"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="section18490181816141"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row20271184815710"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p327144895713"><a name="en-us_topic_0000002515350556_p327144895713"></a><a name="en-us_topic_0000002515350556_p327144895713"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p527116484571"><a name="en-us_topic_0000002515350556_p527116484571"></a><a name="en-us_topic_0000002515350556_p527116484571"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p122714488577"><a name="en-us_topic_0000002515350556_p122714488577"></a><a name="en-us_topic_0000002515350556_p122714488577"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row927164816576"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p14271148145715"><a name="en-us_topic_0000002515350556_p14271148145715"></a><a name="en-us_topic_0000002515350556_p14271148145715"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p427154812577"><a name="en-us_topic_0000002515350556_p427154812577"></a><a name="en-us_topic_0000002515350556_p427154812577"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p142713489570"><a name="en-us_topic_0000002515350556_p142713489570"></a><a name="en-us_topic_0000002515350556_p142713489570"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1527104875720"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p13271248185720"><a name="en-us_topic_0000002515350556_p13271248185720"></a><a name="en-us_topic_0000002515350556_p13271248185720"></a><span id="en-us_topic_0000002515350556_text1527154812578"><a name="en-us_topic_0000002515350556_text1527154812578"></a><a name="en-us_topic_0000002515350556_text1527154812578"></a><span id="en-us_topic_0000002515350556_text2271148205710"><a name="en-us_topic_0000002515350556_text2271148205710"></a><a name="en-us_topic_0000002515350556_text2271148205710"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p10271248165717"><a name="en-us_topic_0000002515350556_p10271248165717"></a><a name="en-us_topic_0000002515350556_p10271248165717"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p11271348175719"><a name="en-us_topic_0000002515350556_p11271348175719"></a><a name="en-us_topic_0000002515350556_p11271348175719"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p6271144865712"><a name="en-us_topic_0000002515350556_p6271144865712"></a><a name="en-us_topic_0000002515350556_p6271144865712"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row527124819571"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p42711448205716"><a name="en-us_topic_0000002515350556_p42711448205716"></a><a name="en-us_topic_0000002515350556_p42711448205716"></a><span id="en-us_topic_0000002515350556_text8271134845715"><a name="en-us_topic_0000002515350556_text8271134845715"></a><a name="en-us_topic_0000002515350556_text8271134845715"></a><span id="en-us_topic_0000002515350556_text527164811575"><a name="en-us_topic_0000002515350556_text527164811575"></a><a name="en-us_topic_0000002515350556_text527164811575"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p12271164818576"><a name="en-us_topic_0000002515350556_p12271164818576"></a><a name="en-us_topic_0000002515350556_p12271164818576"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p427134816570"><a name="en-us_topic_0000002515350556_p427134816570"></a><a name="en-us_topic_0000002515350556_p427134816570"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p627114835717"><a name="en-us_topic_0000002515350556_p627114835717"></a><a name="en-us_topic_0000002515350556_p627114835717"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row18271184811578"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p79671124131618"><a name="en-us_topic_0000002515350556_p79671124131618"></a><a name="en-us_topic_0000002515350556_p79671124131618"></a><span id="en-us_topic_0000002515350556_text49671624141613"><a name="en-us_topic_0000002515350556_text49671624141613"></a><a name="en-us_topic_0000002515350556_text49671624141613"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p9271134885710"><a name="en-us_topic_0000002515350556_p9271134885710"></a><a name="en-us_topic_0000002515350556_p9271134885710"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p7271104814571"><a name="en-us_topic_0000002515350556_p7271104814571"></a><a name="en-us_topic_0000002515350556_p7271104814571"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p8271048185714"><a name="en-us_topic_0000002515350556_p8271048185714"></a><a name="en-us_topic_0000002515350556_p8271048185714"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row285204910295"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p15986185513296"><a name="en-us_topic_0000002515350556_p15986185513296"></a><a name="en-us_topic_0000002515350556_p15986185513296"></a><span id="en-us_topic_0000002515350556_text098685572912"><a name="en-us_topic_0000002515350556_text098685572912"></a><a name="en-us_topic_0000002515350556_text098685572912"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p105251859192911"><a name="en-us_topic_0000002515350556_p105251859192911"></a><a name="en-us_topic_0000002515350556_p105251859192911"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p7525145902913"><a name="en-us_topic_0000002515350556_p7525145902913"></a><a name="en-us_topic_0000002515350556_p7525145902913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p0525165962917"><a name="en-us_topic_0000002515350556_p0525165962917"></a><a name="en-us_topic_0000002515350556_p0525165962917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14271848145719"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p527118483579"><a name="en-us_topic_0000002515350556_p527118483579"></a><a name="en-us_topic_0000002515350556_p527118483579"></a><span id="en-us_topic_0000002515350556_text15271174815713"><a name="en-us_topic_0000002515350556_text15271174815713"></a><a name="en-us_topic_0000002515350556_text15271174815713"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p16271194813571"><a name="en-us_topic_0000002515350556_p16271194813571"></a><a name="en-us_topic_0000002515350556_p16271194813571"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1827154818570"><a name="en-us_topic_0000002515350556_p1827154818570"></a><a name="en-us_topic_0000002515350556_p1827154818570"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p72711448185716"><a name="en-us_topic_0000002515350556_p72711448185716"></a><a name="en-us_topic_0000002515350556_p72711448185716"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row886601693"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p17525251914"><a name="en-us_topic_0000002515350556_p17525251914"></a><a name="en-us_topic_0000002515350556_p17525251914"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section5491121812143"></a>**

```c
...
int ret;
int card_id = 0;
int device_id = 0;
char affinity_cpu[TOPO_INFO_MAX_LENTH] ={0};
int length;
ret = dcmi_get_affinity_cpu_info_by_device_id(card_id, device_id, affinity_cpu, &length);
...
```

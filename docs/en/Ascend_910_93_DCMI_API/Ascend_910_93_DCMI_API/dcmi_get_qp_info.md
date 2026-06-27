# dcmi\_get\_qp\_info<a name="EN-US_TOPIC_0000002546910451"></a>

**Prototype<a name="section1478319523594"></a>**

**int dcmi\_get\_qp\_info \(int card\_id, int device\_id, int port\_id, unsigned int qpn, struct dcmi\_qp\_info \*qp\_info\)**

**Description<a name="section1784175216599"></a>**

Obtains the QP context information based on the QPN.

**Parameter Description<a name="section12785135213593"></a>**

<a name="table1782512522592"></a>
<table><thead align="left"><tr id="row18777115310597"><th class="cellrowborder" valign="top" width="21.04210421042104%" id="mcps1.1.5.1.1"><p id="p1277720536595"><a name="p1277720536595"></a><a name="p1277720536595"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="13.701370137013702%" id="mcps1.1.5.1.2"><p id="p97773536593"><a name="p97773536593"></a><a name="p97773536593"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="26.772677267726774%" id="mcps1.1.5.1.3"><p id="p107778533599"><a name="p107778533599"></a><a name="p107778533599"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="38.48384838483848%" id="mcps1.1.5.1.4"><p id="p7777185345918"><a name="p7777185345918"></a><a name="p7777185345918"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row191479201919"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p831314310448"><a name="p831314310448"></a><a name="p831314310448"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p7313183184415"><a name="p7313183184415"></a><a name="p7313183184415"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p20313333443"><a name="p20313333443"></a><a name="p20313333443"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p63137316446"><a name="p63137316446"></a><a name="p63137316446"></a>Device ID. The supported IDs can be obtained by calling <strong id="b4688945078182"><a name="b4688945078182"></a><a name="b4688945078182"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1277725315914"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p15777135325912"><a name="p15777135325912"></a><a name="p15777135325912"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p14777135375917"><a name="p14777135375917"></a><a name="p14777135375917"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p4777153135914"><a name="p4777153135914"></a><a name="p4777153135914"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p167774534592"><a name="p167774534592"></a><a name="p167774534592"></a>Chip ID, which can be obtained by calling <strong id="b211030224133048"><a name="b211030224133048"></a><a name="b211030224133048"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p15777353135919"><a name="p15777353135919"></a><a name="p15777353135919"></a>NPU: [0, <strong id="b108806673625455"><a name="b108806673625455"></a><a name="b108806673625455"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row16777145355910"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p377719536592"><a name="p377719536592"></a><a name="p377719536592"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p777745375915"><a name="p777745375915"></a><a name="p777745375915"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p6778115313599"><a name="p6778115313599"></a><a name="p6778115313599"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p67471340155912"><a name="p67471340155912"></a><a name="p67471340155912"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b7602808652489"><a name="b7602808652489"></a><a name="b7602808652489"></a>0</strong>.</p>
</td>
</tr>
<tr id="row977805317595"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p9397624205320"><a name="p9397624205320"></a><a name="p9397624205320"></a>qpn</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p16398102495311"><a name="p16398102495311"></a><a name="p16398102495311"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p103981242531"><a name="p103981242531"></a><a name="p103981242531"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p53985249531"><a name="p53985249531"></a><a name="p53985249531"></a>qp number</p>
</td>
</tr>
<tr id="row277885355910"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p14398162445314"><a name="p14398162445314"></a><a name="p14398162445314"></a>qp_info</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p15398624115315"><a name="p15398624115315"></a><a name="p15398624115315"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p173983244533"><a name="p173983244533"></a><a name="p173983244533"></a>struct dcmi_qp_info*</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p33981024185315"><a name="p33981024185315"></a><a name="p33981024185315"></a>Returned QP information.</p>
<p id="p13985242533"><a name="p13985242533"></a><a name="p13985242533"></a>#define IP_ADDRESS_LEN   40</p>
<p id="p1639862410533"><a name="p1639862410533"></a><a name="p1639862410533"></a>struct dcmi_qp_info {</p>
<p id="p7398624185310"><a name="p7398624185310"></a><a name="p7398624185310"></a>unsigned char status;  // QP status</p>
<p id="p1739872412536"><a name="p1739872412536"></a><a name="p1739872412536"></a>unsigned char type; // QP type</p>
<p id="p1339817247535"><a name="p1339817247535"></a><a name="p1339817247535"></a>char ip[IP_ADDRESS_LEN];// Destination IP address</p>
<p id="p939872405317"><a name="p939872405317"></a><a name="p939872405317"></a>unsigned short src_port; // Source port</p>
<p id="p239882475318"><a name="p239882475318"></a><a name="p239882475318"></a>unsigned int src_qpn; // Source QPN</p>
<p id="p7398192418533"><a name="p7398192418533"></a><a name="p7398192418533"></a>unsigned int dst_qpn; // Destination QPN</p>
<p id="p539812241533"><a name="p539812241533"></a><a name="p539812241533"></a>unsigned int send_psn;  // Sent PSN</p>
<p id="p639812414531"><a name="p639812414531"></a><a name="p639812414531"></a>unsigned int recv_psn; // Received PSN</p>
<p id="p3398112419537"><a name="p3398112419537"></a><a name="p3398112419537"></a>char reserved[32]; // Reserved field</p>
<p id="p1839815243538"><a name="p1839815243538"></a><a name="p1839815243538"></a>};</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section11804352115915"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b18983659857237"><a name="b18983659857237"></a><a name="b18983659857237"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1381515275916"></a>**

None

**Restrictions<a name="section4816185215596"></a>**

This API can be used in the PM + privileged container scenario.

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

**Example<a name="section78173521596"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
unsigned int qpn = 0;
struct dcmi_qp_info qp_info = {0};
ret = dcmi_get_qp_info(card_id, device_id, port_id, qpn, &qp_info);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

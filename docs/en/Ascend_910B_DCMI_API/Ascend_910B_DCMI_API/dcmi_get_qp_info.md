# dcmi\_get\_qp\_info<a name="EN-US_TOPIC_0000002546983703"></a>

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
<tbody><tr id="row1682637193412"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p831314310448"><a name="p831314310448"></a><a name="p831314310448"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p7313183184415"><a name="p7313183184415"></a><a name="p7313183184415"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p20313333443"><a name="p20313333443"></a><a name="p20313333443"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p63137316446"><a name="p63137316446"></a><a name="p63137316446"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1238157818102850"><a name="b1238157818102850"></a><a name="b1238157818102850"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1277725315914"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p15777135325912"><a name="p15777135325912"></a><a name="p15777135325912"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p14777135375917"><a name="p14777135375917"></a><a name="p14777135375917"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p4777153135914"><a name="p4777153135914"></a><a name="p4777153135914"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p167774534592"><a name="p167774534592"></a><a name="p167774534592"></a>Chip ID, which can be obtained by calling <strong id="b982198493102520"><a name="b982198493102520"></a><a name="b982198493102520"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p15777353135919"><a name="p15777353135919"></a><a name="p15777353135919"></a>NPU: [0, <strong id="b756158382105354"><a name="b756158382105354"></a><a name="b756158382105354"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row16777145355910"><td class="cellrowborder" valign="top" width="21.04210421042104%" headers="mcps1.1.5.1.1 "><p id="p377719536592"><a name="p377719536592"></a><a name="p377719536592"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.701370137013702%" headers="mcps1.1.5.1.2 "><p id="p777745375915"><a name="p777745375915"></a><a name="p777745375915"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="26.772677267726774%" headers="mcps1.1.5.1.3 "><p id="p6778115313599"><a name="p6778115313599"></a><a name="p6778115313599"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p5778155345914"><a name="p5778155345914"></a><a name="p5778155345914"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b40351400935053"><a name="b40351400935053"></a><a name="b40351400935053"></a>0</strong>.</p>
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
<td class="cellrowborder" valign="top" width="38.48384838483848%" headers="mcps1.1.5.1.4 "><p id="p33981024185315"><a name="p33981024185315"></a><a name="p33981024185315"></a>Returned QP information</p>
<p id="p13985242533"><a name="p13985242533"></a><a name="p13985242533"></a>#define IP_ADDRESS_LEN   40</p>
<p id="p1639862410533"><a name="p1639862410533"></a><a name="p1639862410533"></a>struct dcmi_qp_info {</p>
<p id="p7398624185310"><a name="p7398624185310"></a><a name="p7398624185310"></a>unsigned char status; // QP status</p>
<p id="p1739872412536"><a name="p1739872412536"></a><a name="p1739872412536"></a>unsigned char type; // QP type</p>
<p id="p1339817247535"><a name="p1339817247535"></a><a name="p1339817247535"></a>char ip[IP_ADDRESS_LEN]; // Destination IP address</p>
<p id="p939872405317"><a name="p939872405317"></a><a name="p939872405317"></a>unsigned short src_port; // Source port</p>
<p id="p239882475318"><a name="p239882475318"></a><a name="p239882475318"></a>unsigned int src_qpn; // Source QPN</p>
<p id="p7398192418533"><a name="p7398192418533"></a><a name="p7398192418533"></a>unsigned int dst_qpn; // Destination QPN</p>
<p id="p539812241533"><a name="p539812241533"></a><a name="p539812241533"></a>unsigned int send_psn; // Sent PSN</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b172171619985635"><a name="b172171619985635"></a><a name="b172171619985635"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1381515275916"></a>**

None.

**Restrictions<a name="section4816185215596"></a>**

Atlas 200T A2 Box16 heterogeneous subrack, Atlas 800T A2 training server, Atlas 800I A2 inference server,  Atlas 900 A2 PoD cluster basic unit, and A200I A2 Box heterogeneous component: This API can be used in PM + privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1514515016392"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p15286130203213"><a name="en-us_topic_0000002515503852_p15286130203213"></a><a name="en-us_topic_0000002515503852_p15286130203213"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p132861730113218"><a name="en-us_topic_0000002515503852_p132861730113218"></a><a name="en-us_topic_0000002515503852_p132861730113218"></a><strong id="en-us_topic_0000002515503852_b065416910513"><a name="en-us_topic_0000002515503852_b065416910513"></a><a name="en-us_topic_0000002515503852_b065416910513"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p22861530183212"><a name="en-us_topic_0000002515503852_p22861530183212"></a><a name="en-us_topic_0000002515503852_p22861530183212"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b4800131019511"><a name="en-us_topic_0000002515503852_b4800131019511"></a><a name="en-us_topic_0000002515503852_b4800131019511"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p1928683003217"><a name="en-us_topic_0000002515503852_p1928683003217"></a><a name="en-us_topic_0000002515503852_p1928683003217"></a><strong id="en-us_topic_0000002515503852_b79191511557"><a name="en-us_topic_0000002515503852_b79191511557"></a><a name="en-us_topic_0000002515503852_b79191511557"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row514512014397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14145100183919"><a name="en-us_topic_0000002515503852_p14145100183919"></a><a name="en-us_topic_0000002515503852_p14145100183919"></a><span id="en-us_topic_0000002515503852_ph15145206394"><a name="en-us_topic_0000002515503852_ph15145206394"></a><a name="en-us_topic_0000002515503852_ph15145206394"></a><span id="en-us_topic_0000002515503852_text141451204393"><a name="en-us_topic_0000002515503852_text141451204393"></a><a name="en-us_topic_0000002515503852_text141451204393"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p114519073913"><a name="en-us_topic_0000002515503852_p114519073913"></a><a name="en-us_topic_0000002515503852_p114519073913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p672045395"><a name="en-us_topic_0000002515503852_p672045395"></a><a name="en-us_topic_0000002515503852_p672045395"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p14102046396"><a name="en-us_topic_0000002515503852_p14102046396"></a><a name="en-us_topic_0000002515503852_p14102046396"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1314590133918"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p914590143915"><a name="en-us_topic_0000002515503852_p914590143915"></a><a name="en-us_topic_0000002515503852_p914590143915"></a><span id="en-us_topic_0000002515503852_text151456017398"><a name="en-us_topic_0000002515503852_text151456017398"></a><a name="en-us_topic_0000002515503852_text151456017398"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p114512012392"><a name="en-us_topic_0000002515503852_p114512012392"></a><a name="en-us_topic_0000002515503852_p114512012392"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p161319419393"><a name="en-us_topic_0000002515503852_p161319419393"></a><a name="en-us_topic_0000002515503852_p161319419393"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1019184143917"><a name="en-us_topic_0000002515503852_p1019184143917"></a><a name="en-us_topic_0000002515503852_p1019184143917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1814514011392"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p414590193920"><a name="en-us_topic_0000002515503852_p414590193920"></a><a name="en-us_topic_0000002515503852_p414590193920"></a><span id="en-us_topic_0000002515503852_text161451704394"><a name="en-us_topic_0000002515503852_text161451704394"></a><a name="en-us_topic_0000002515503852_text161451704394"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1514516018392"><a name="en-us_topic_0000002515503852_p1514516018392"></a><a name="en-us_topic_0000002515503852_p1514516018392"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18242403910"><a name="en-us_topic_0000002515503852_p18242403910"></a><a name="en-us_topic_0000002515503852_p18242403910"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18307415390"><a name="en-us_topic_0000002515503852_p18307415390"></a><a name="en-us_topic_0000002515503852_p18307415390"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1114514093913"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1145407399"><a name="en-us_topic_0000002515503852_p1145407399"></a><a name="en-us_topic_0000002515503852_p1145407399"></a><span id="en-us_topic_0000002515503852_text161451007395"><a name="en-us_topic_0000002515503852_text161451007395"></a><a name="en-us_topic_0000002515503852_text161451007395"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p314518015391"><a name="en-us_topic_0000002515503852_p314518015391"></a><a name="en-us_topic_0000002515503852_p314518015391"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13378413911"><a name="en-us_topic_0000002515503852_p13378413911"></a><a name="en-us_topic_0000002515503852_p13378413911"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p8431344398"><a name="en-us_topic_0000002515503852_p8431344398"></a><a name="en-us_topic_0000002515503852_p8431344398"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1114514017397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1114510163910"><a name="en-us_topic_0000002515503852_p1114510163910"></a><a name="en-us_topic_0000002515503852_p1114510163910"></a><span id="en-us_topic_0000002515503852_text01466093919"><a name="en-us_topic_0000002515503852_text01466093919"></a><a name="en-us_topic_0000002515503852_text01466093919"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p214613010391"><a name="en-us_topic_0000002515503852_p214613010391"></a><a name="en-us_topic_0000002515503852_p214613010391"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15471840391"><a name="en-us_topic_0000002515503852_p15471840391"></a><a name="en-us_topic_0000002515503852_p15471840391"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p45014483920"><a name="en-us_topic_0000002515503852_p45014483920"></a><a name="en-us_topic_0000002515503852_p45014483920"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row3146140203913"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p0146160143914"><a name="en-us_topic_0000002515503852_p0146160143914"></a><a name="en-us_topic_0000002515503852_p0146160143914"></a><span id="en-us_topic_0000002515503852_text181621218183218"><a name="en-us_topic_0000002515503852_text181621218183218"></a><a name="en-us_topic_0000002515503852_text181621218183218"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p141461506394"><a name="en-us_topic_0000002515503852_p141461506394"></a><a name="en-us_topic_0000002515503852_p141461506394"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p353114123912"><a name="en-us_topic_0000002515503852_p353114123912"></a><a name="en-us_topic_0000002515503852_p353114123912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p135715415392"><a name="en-us_topic_0000002515503852_p135715415392"></a><a name="en-us_topic_0000002515503852_p135715415392"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row31461604397"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p714619015395"><a name="en-us_topic_0000002515503852_p714619015395"></a><a name="en-us_topic_0000002515503852_p714619015395"></a><span id="en-us_topic_0000002515503852_text111462014399"><a name="en-us_topic_0000002515503852_text111462014399"></a><a name="en-us_topic_0000002515503852_text111462014399"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1314610043913"><a name="en-us_topic_0000002515503852_p1314610043913"></a><a name="en-us_topic_0000002515503852_p1314610043913"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p8602483913"><a name="en-us_topic_0000002515503852_p8602483913"></a><a name="en-us_topic_0000002515503852_p8602483913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11635413398"><a name="en-us_topic_0000002515503852_p11635413398"></a><a name="en-us_topic_0000002515503852_p11635413398"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row31464013910"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p5146120153917"><a name="en-us_topic_0000002515503852_p5146120153917"></a><a name="en-us_topic_0000002515503852_p5146120153917"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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
    //todo: Record logs.
    return ret;
}
...
```

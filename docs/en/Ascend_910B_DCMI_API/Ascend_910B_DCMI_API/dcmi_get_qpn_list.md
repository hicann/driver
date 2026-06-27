# dcmi\_get\_qpn\_list<a name="EN-US_TOPIC_0000002515503776"></a>

**Prototype<a name="section10646124018595"></a>**

**int dcmi\_get\_qpn\_list \(int card\_id, int device\_id, int port\_id, struct dcmi\_qpn\_list \*list\)**

**Description<a name="section26471040155919"></a>**

Obtains the number of QPs and the corresponding  **qpn\_list**.

**Parameter Description<a name="section264894085911"></a>**

<a name="table56741840185919"></a>
<table><thead align="left"><tr id="row1874519409598"><th class="cellrowborder" valign="top" width="16.328367163283673%" id="mcps1.1.5.1.1"><p id="p13745154019597"><a name="p13745154019597"></a><a name="p13745154019597"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="14.288571142885711%" id="mcps1.1.5.1.2"><p id="p137451740175917"><a name="p137451740175917"></a><a name="p137451740175917"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="25.507449255074494%" id="mcps1.1.5.1.3"><p id="p27451140125911"><a name="p27451140125911"></a><a name="p27451140125911"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="43.87561243875613%" id="mcps1.1.5.1.4"><p id="p127453403594"><a name="p127453403594"></a><a name="p127453403594"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row4650194615265"><td class="cellrowborder" valign="top" width="16.328367163283673%" headers="mcps1.1.5.1.1 "><p id="p39310217444"><a name="p39310217444"></a><a name="p39310217444"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.288571142885711%" headers="mcps1.1.5.1.2 "><p id="p129314219448"><a name="p129314219448"></a><a name="p129314219448"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="25.507449255074494%" headers="mcps1.1.5.1.3 "><p id="p11933217448"><a name="p11933217448"></a><a name="p11933217448"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="43.87561243875613%" headers="mcps1.1.5.1.4 "><p id="p109362184410"><a name="p109362184410"></a><a name="p109362184410"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1417314633102850"><a name="b1417314633102850"></a><a name="b1417314633102850"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row14745640195914"><td class="cellrowborder" valign="top" width="16.328367163283673%" headers="mcps1.1.5.1.1 "><p id="p147452404592"><a name="p147452404592"></a><a name="p147452404592"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.288571142885711%" headers="mcps1.1.5.1.2 "><p id="p7746114055918"><a name="p7746114055918"></a><a name="p7746114055918"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="25.507449255074494%" headers="mcps1.1.5.1.3 "><p id="p177461240195910"><a name="p177461240195910"></a><a name="p177461240195910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="43.87561243875613%" headers="mcps1.1.5.1.4 "><p id="p117460409592"><a name="p117460409592"></a><a name="p117460409592"></a>Chip ID, which can be obtained by calling <strong id="b2049103448102519"><a name="b2049103448102519"></a><a name="b2049103448102519"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p5746144035914"><a name="p5746144035914"></a><a name="p5746144035914"></a>NPU: [0, <strong id="b1495561803105353"><a name="b1495561803105353"></a><a name="b1495561803105353"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row1574718405595"><td class="cellrowborder" valign="top" width="16.328367163283673%" headers="mcps1.1.5.1.1 "><p id="p16747204015594"><a name="p16747204015594"></a><a name="p16747204015594"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="14.288571142885711%" headers="mcps1.1.5.1.2 "><p id="p147471640115914"><a name="p147471640115914"></a><a name="p147471640115914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="25.507449255074494%" headers="mcps1.1.5.1.3 "><p id="p07477402591"><a name="p07477402591"></a><a name="p07477402591"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="43.87561243875613%" headers="mcps1.1.5.1.4 "><p id="p67471340155912"><a name="p67471340155912"></a><a name="p67471340155912"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b85302540135052"><a name="b85302540135052"></a><a name="b85302540135052"></a>0</strong>.</p>
</td>
</tr>
<tr id="row12747204020598"><td class="cellrowborder" valign="top" width="16.328367163283673%" headers="mcps1.1.5.1.1 "><p id="p1974714010598"><a name="p1974714010598"></a><a name="p1974714010598"></a>list</p>
</td>
<td class="cellrowborder" valign="top" width="14.288571142885711%" headers="mcps1.1.5.1.2 "><p id="p127471740145913"><a name="p127471740145913"></a><a name="p127471740145913"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="25.507449255074494%" headers="mcps1.1.5.1.3 "><p id="p174718403599"><a name="p174718403599"></a><a name="p174718403599"></a>struct dcmi_qpn_list*</p>
</td>
<td class="cellrowborder" valign="top" width="43.87561243875613%" headers="mcps1.1.5.1.4 "><p id="p1679332921613"><a name="p1679332921613"></a><a name="p1679332921613"></a>#define MAX_QPN_NUM 8192 // Maximum number of records supported by the QPN list</p>
<p id="p17471440105919"><a name="p17471440105919"></a><a name="p17471440105919"></a>struct dcmi_qpn_list {</p>
<p id="p11747174017595"><a name="p11747174017595"></a><a name="p11747174017595"></a>unsigned int qp_num; // Number of obtained QPs in the active state</p>
<p id="p77474407599"><a name="p77474407599"></a><a name="p77474407599"></a>unsigned int qpn_list[MAX_QPN_NUM]; // QPN list corresponding to <strong id="b2586135910300"><a name="b2586135910300"></a><a name="b2586135910300"></a>qp_num</strong></p>
<p id="p074715409590"><a name="p074715409590"></a><a name="p074715409590"></a>};</p>
<p id="p1095331622510"><a name="p1095331622510"></a><a name="p1095331622510"></a><strong id="b328211313314"><a name="b328211313314"></a><a name="b328211313314"></a>qpn</strong>: QP number</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section18661174035919"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b172036079685635"><a name="b172036079685635"></a><a name="b172036079685635"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section14668104014594"></a>**

None.

**Restrictions<a name="section966910400597"></a>**

This API can be used in PM + privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row3169171463617"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p8558112793214"><a name="en-us_topic_0000002515503852_p8558112793214"></a><a name="en-us_topic_0000002515503852_p8558112793214"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p655852717326"><a name="en-us_topic_0000002515503852_p655852717326"></a><a name="en-us_topic_0000002515503852_p655852717326"></a><strong id="en-us_topic_0000002515503852_b2084215313512"><a name="en-us_topic_0000002515503852_b2084215313512"></a><a name="en-us_topic_0000002515503852_b2084215313512"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p10558122715327"><a name="en-us_topic_0000002515503852_p10558122715327"></a><a name="en-us_topic_0000002515503852_p10558122715327"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b14917518517"><a name="en-us_topic_0000002515503852_b14917518517"></a><a name="en-us_topic_0000002515503852_b14917518517"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p15581927103214"><a name="en-us_topic_0000002515503852_p15581927103214"></a><a name="en-us_topic_0000002515503852_p15581927103214"></a><strong id="en-us_topic_0000002515503852_b193961161854"><a name="en-us_topic_0000002515503852_b193961161854"></a><a name="en-us_topic_0000002515503852_b193961161854"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row1816915147366"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p6169151423619"><a name="en-us_topic_0000002515503852_p6169151423619"></a><a name="en-us_topic_0000002515503852_p6169151423619"></a><span id="en-us_topic_0000002515503852_ph116911144369"><a name="en-us_topic_0000002515503852_ph116911144369"></a><a name="en-us_topic_0000002515503852_ph116911144369"></a><span id="en-us_topic_0000002515503852_text71694149366"><a name="en-us_topic_0000002515503852_text71694149366"></a><a name="en-us_topic_0000002515503852_text71694149366"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p316911142362"><a name="en-us_topic_0000002515503852_p316911142362"></a><a name="en-us_topic_0000002515503852_p316911142362"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p816918145361"><a name="en-us_topic_0000002515503852_p816918145361"></a><a name="en-us_topic_0000002515503852_p816918145361"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p9472202011368"><a name="en-us_topic_0000002515503852_p9472202011368"></a><a name="en-us_topic_0000002515503852_p9472202011368"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row01692149364"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10169141412361"><a name="en-us_topic_0000002515503852_p10169141412361"></a><a name="en-us_topic_0000002515503852_p10169141412361"></a><span id="en-us_topic_0000002515503852_text1516951453611"><a name="en-us_topic_0000002515503852_text1516951453611"></a><a name="en-us_topic_0000002515503852_text1516951453611"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16169121403617"><a name="en-us_topic_0000002515503852_p16169121403617"></a><a name="en-us_topic_0000002515503852_p16169121403617"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p171698141361"><a name="en-us_topic_0000002515503852_p171698141361"></a><a name="en-us_topic_0000002515503852_p171698141361"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1348119209364"><a name="en-us_topic_0000002515503852_p1348119209364"></a><a name="en-us_topic_0000002515503852_p1348119209364"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row17169814163612"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p2169414113616"><a name="en-us_topic_0000002515503852_p2169414113616"></a><a name="en-us_topic_0000002515503852_p2169414113616"></a><span id="en-us_topic_0000002515503852_text2169111443615"><a name="en-us_topic_0000002515503852_text2169111443615"></a><a name="en-us_topic_0000002515503852_text2169111443615"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p141696146366"><a name="en-us_topic_0000002515503852_p141696146366"></a><a name="en-us_topic_0000002515503852_p141696146366"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3169114113611"><a name="en-us_topic_0000002515503852_p3169114113611"></a><a name="en-us_topic_0000002515503852_p3169114113611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p13489162017366"><a name="en-us_topic_0000002515503852_p13489162017366"></a><a name="en-us_topic_0000002515503852_p13489162017366"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row01691314183618"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1616951453614"><a name="en-us_topic_0000002515503852_p1616951453614"></a><a name="en-us_topic_0000002515503852_p1616951453614"></a><span id="en-us_topic_0000002515503852_text17169141413610"><a name="en-us_topic_0000002515503852_text17169141413610"></a><a name="en-us_topic_0000002515503852_text17169141413610"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p316911419369"><a name="en-us_topic_0000002515503852_p316911419369"></a><a name="en-us_topic_0000002515503852_p316911419369"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p141697141368"><a name="en-us_topic_0000002515503852_p141697141368"></a><a name="en-us_topic_0000002515503852_p141697141368"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1949213202364"><a name="en-us_topic_0000002515503852_p1949213202364"></a><a name="en-us_topic_0000002515503852_p1949213202364"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1169151413367"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1716931483615"><a name="en-us_topic_0000002515503852_p1716931483615"></a><a name="en-us_topic_0000002515503852_p1716931483615"></a><span id="en-us_topic_0000002515503852_text81691114103617"><a name="en-us_topic_0000002515503852_text81691114103617"></a><a name="en-us_topic_0000002515503852_text81691114103617"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p816912141365"><a name="en-us_topic_0000002515503852_p816912141365"></a><a name="en-us_topic_0000002515503852_p816912141365"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15169191411369"><a name="en-us_topic_0000002515503852_p15169191411369"></a><a name="en-us_topic_0000002515503852_p15169191411369"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1497112043619"><a name="en-us_topic_0000002515503852_p1497112043619"></a><a name="en-us_topic_0000002515503852_p1497112043619"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row111691014173614"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19169514103610"><a name="en-us_topic_0000002515503852_p19169514103610"></a><a name="en-us_topic_0000002515503852_p19169514103610"></a><span id="en-us_topic_0000002515503852_text01406115324"><a name="en-us_topic_0000002515503852_text01406115324"></a><a name="en-us_topic_0000002515503852_text01406115324"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p181691314163611"><a name="en-us_topic_0000002515503852_p181691314163611"></a><a name="en-us_topic_0000002515503852_p181691314163611"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p516961453612"><a name="en-us_topic_0000002515503852_p516961453612"></a><a name="en-us_topic_0000002515503852_p516961453612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p25021520143613"><a name="en-us_topic_0000002515503852_p25021520143613"></a><a name="en-us_topic_0000002515503852_p25021520143613"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1816912147365"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1916941423613"><a name="en-us_topic_0000002515503852_p1916941423613"></a><a name="en-us_topic_0000002515503852_p1916941423613"></a><span id="en-us_topic_0000002515503852_text121691149365"><a name="en-us_topic_0000002515503852_text121691149365"></a><a name="en-us_topic_0000002515503852_text121691149365"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p14169101413366"><a name="en-us_topic_0000002515503852_p14169101413366"></a><a name="en-us_topic_0000002515503852_p14169101413366"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10169614163611"><a name="en-us_topic_0000002515503852_p10169614163611"></a><a name="en-us_topic_0000002515503852_p10169614163611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12507102016363"><a name="en-us_topic_0000002515503852_p12507102016363"></a><a name="en-us_topic_0000002515503852_p12507102016363"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1317019147361"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2170191493613"><a name="en-us_topic_0000002515503852_p2170191493613"></a><a name="en-us_topic_0000002515503852_p2170191493613"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section156701340105918"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
struct dcmi_qpn_list list = {0}; 
ret = dcmi_get_qpn_list(card_id, device_id, port_id, &list);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

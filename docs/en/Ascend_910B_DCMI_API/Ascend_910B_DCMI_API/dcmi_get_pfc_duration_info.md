# dcmi\_get\_pfc\_duration\_info<a name="EN-US_TOPIC_0000002515503878"></a>

**Prototype<a name="section1873810317462"></a>**

**int dcmi\_get\_pfc\_duration\_info\(int card\_id, int device\_id, struct dcmi\_pfc\_duration\_info \*pfc\_duration\_info\)**

**Description<a name="section474073164613"></a>**

Obtains statistics of the PFC backpressure frame duration of a specified device.

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
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p285611384617"><a name="p285611384617"></a><a name="p285611384617"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1652088302102846"><a name="b1652088302102846"></a><a name="b1652088302102846"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row485615313467"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p198565334613"><a name="p198565334613"></a><a name="p198565334613"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16856183104614"><a name="p16856183104614"></a><a name="p16856183104614"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p138563311469"><a name="p138563311469"></a><a name="p138563311469"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p885719354617"><a name="p885719354617"></a><a name="p885719354617"></a>Chip ID, which can be obtained by calling <strong id="b624919153102516"><a name="b624919153102516"></a><a name="b624919153102516"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p9857837462"><a name="p9857837462"></a><a name="p9857837462"></a>NPU: [0, <strong id="b1529937168105351"><a name="b1529937168105351"></a><a name="b1529937168105351"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<p id="p08573364614"><a name="p08573364614"></a><a name="p08573364614"></a>unsigned long long tx[PRI_NUM]; // Duration of the sent backpressure frames</p>
<p id="p98572334615"><a name="p98572334615"></a><a name="p98572334615"></a>unsigned long long rx[PRI_NUM]; // Duration of the received backpressure frames</p>
<p id="p158581136465"><a name="p158581136465"></a><a name="p158581136465"></a>PRI_NUM=8; // Eight priority queues</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b57235171385632"><a name="b57235171385632"></a><a name="b57235171385632"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section11766193124614"></a>**

None.

**Restrictions<a name="section14766153174617"></a>**

Atlas 200T A2 Box16 heterogeneous subrack, Atlas 800T A2 training server, Atlas 800I A2 inference server,  Atlas 900 A2 PoD cluster basic unit, and A200I A2 Box heterogeneous component: This API can be used in PM + privileged container scenarios.

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

**Example<a name="section12776336460"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
struct dcmi_pfc_duration_info pfc_duration_info = {0};
ret = dcmi_get_pfc_duration_info(card_id, device_id, &pfc_duration_info);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

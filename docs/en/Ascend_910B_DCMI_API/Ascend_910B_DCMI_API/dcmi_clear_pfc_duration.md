# dcmi\_clear\_pfc\_duration<a name="EN-US_TOPIC_0000002515503810"></a>

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
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p8662594544"><a name="p8662594544"></a><a name="p8662594544"></a>Device ID. The supported IDs can be obtained by calling <strong id="b896272507102847"><a name="b896272507102847"></a><a name="b896272507102847"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1662595540"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p16610593540"><a name="p16610593540"></a><a name="p16610593540"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p06675913543"><a name="p06675913543"></a><a name="p06675913543"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1666159175411"><a name="p1666159175411"></a><a name="p1666159175411"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p176616594547"><a name="p176616594547"></a><a name="p176616594547"></a>Chip ID, which can be obtained by calling <strong id="b1556957411102517"><a name="b1556957411102517"></a><a name="b1556957411102517"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p2066359185415"><a name="p2066359185415"></a><a name="p2066359185415"></a>NPU: [0, <strong id="b665177470105352"><a name="b665177470105352"></a><a name="b665177470105352"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b23434603285633"><a name="b23434603285633"></a><a name="b23434603285633"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1225565895419"></a>**

None.

**Restrictions<a name="section1625614581546"></a>**

Atlas 200T A2 Box16 heterogeneous subrack, Atlas 800T A2 training server, Atlas 800I A2 inference server,  Atlas 900 A2 PoD cluster basic unit, and A200I A2 Box heterogeneous component: This API can be used in PM + privileged container scenarios.

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

**Example<a name="section192671558125418"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
ret = dcmi_clear_pfc_duration(card_id, device_id);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

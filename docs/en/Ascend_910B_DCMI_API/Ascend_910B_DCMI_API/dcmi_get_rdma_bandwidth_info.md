# dcmi\_get\_rdma\_bandwidth\_info<a name="EN-US_TOPIC_0000002515503792"></a>

**Prototype<a name="section196251231145019"></a>**

**int dcmi\_get\_rdma\_bandwidth\_info\(int card\_id, int device\_id, int port\_id,** **unsigned int prof\_time, struct dcmi\_network\_rdma\_bandwidth\_info \*network\_rdma\_bandwidth\_info\)**

**Description<a name="section116271631195017"></a>**

Queries the RDMA bandwidth of an NPU network port in a specified profiling period.

**Parameter Description<a name="section11627103114506"></a>**

<a name="table196551731155016"></a>
<table><thead align="left"><tr id="row6708031165017"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p17708123120507"><a name="p17708123120507"></a><a name="p17708123120507"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p13708143185017"><a name="p13708143185017"></a><a name="p13708143185017"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p67081031185017"><a name="p67081031185017"></a><a name="p67081031185017"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p3708131145014"><a name="p3708131145014"></a><a name="p3708131145014"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row270819311506"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p3708193115501"><a name="p3708193115501"></a><a name="p3708193115501"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1170863112507"><a name="p1170863112507"></a><a name="p1170863112507"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p17081231205013"><a name="p17081231205013"></a><a name="p17081231205013"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p27082313505"><a name="p27082313505"></a><a name="p27082313505"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1212139487102839"><a name="b1212139487102839"></a><a name="b1212139487102839"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b86983507610258"><a name="b86983507610258"></a><a name="b86983507610258"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU chip: [0, <strong id="b1261899929111943"><a name="b1261899929111943"></a><a name="b1261899929111943"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row89976111742"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1824103514419"><a name="p1824103514419"></a><a name="p1824103514419"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p424143514417"><a name="p424143514417"></a><a name="p424143514417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1424112357410"><a name="p1424112357410"></a><a name="p1424112357410"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1224183544119"><a name="p1224183544119"></a><a name="p1224183544119"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b73405027233146"><a name="b73405027233146"></a><a name="b73405027233146"></a>0</strong>.</p>
</td>
</tr>
<tr id="row2498185195919"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p145961171904"><a name="p145961171904"></a><a name="p145961171904"></a>prof_time</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p55965171505"><a name="p55965171505"></a><a name="p55965171505"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p145963175011"><a name="p145963175011"></a><a name="p145963175011"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p11596317609"><a name="p11596317609"></a><a name="p11596317609"></a>Profiling time. Value range: 100 ms to 10000 ms.</p>
</td>
</tr>
<tr id="row15998411242"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p6597191716014"><a name="p6597191716014"></a><a name="p6597191716014"></a>network_rdma_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p10597717308"><a name="p10597717308"></a><a name="p10597717308"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p4597101712011"><a name="p4597101712011"></a><a name="p4597101712011"></a>dcmi_network_rdma_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p195971017809"><a name="p195971017809"></a><a name="p195971017809"></a>struct dcmi_network_rdma_bandwidth_info {</p>
<p id="p165801422016"><a name="p165801422016"></a><a name="p165801422016"></a>unsigned int tx_bandwidth; // TX bandwidth</p>
<p id="p1559718170017"><a name="p1559718170017"></a><a name="p1559718170017"></a>unsigned int rx_bandwidth; // RX bandwidth</p>
<p id="p35970176020"><a name="p35970176020"></a><a name="p35970176020"></a>};</p>
<p id="p1597111719014"><a name="p1597111719014"></a><a name="p1597111719014"></a>The unit is MB/s.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section3642631135017"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b26168018885627"><a name="b26168018885627"></a><a name="b26168018885627"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None.

**Restrictions<a name="section364683165017"></a>**

**Table  1** Support in different deployment scenarios

<a name="table629810360529"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row979954933113"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p259621143212"><a name="en-us_topic_0000002515503852_p259621143212"></a><a name="en-us_topic_0000002515503852_p259621143212"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p185961211133216"><a name="en-us_topic_0000002515503852_p185961211133216"></a><a name="en-us_topic_0000002515503852_p185961211133216"></a><strong id="en-us_topic_0000002515503852_b112423581349"><a name="en-us_topic_0000002515503852_b112423581349"></a><a name="en-us_topic_0000002515503852_b112423581349"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p3596161118320"><a name="en-us_topic_0000002515503852_p3596161118320"></a><a name="en-us_topic_0000002515503852_p3596161118320"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b1646915916412"><a name="en-us_topic_0000002515503852_b1646915916412"></a><a name="en-us_topic_0000002515503852_b1646915916412"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p13596101193211"><a name="en-us_topic_0000002515503852_p13596101193211"></a><a name="en-us_topic_0000002515503852_p13596101193211"></a><strong id="en-us_topic_0000002515503852_b1264430856"><a name="en-us_topic_0000002515503852_b1264430856"></a><a name="en-us_topic_0000002515503852_b1264430856"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row279917498314"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p879924993116"><a name="en-us_topic_0000002515503852_p879924993116"></a><a name="en-us_topic_0000002515503852_p879924993116"></a><span id="en-us_topic_0000002515503852_ph3799204963110"><a name="en-us_topic_0000002515503852_ph3799204963110"></a><a name="en-us_topic_0000002515503852_ph3799204963110"></a><span id="en-us_topic_0000002515503852_text579974910315"><a name="en-us_topic_0000002515503852_text579974910315"></a><a name="en-us_topic_0000002515503852_text579974910315"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18370822173217"><a name="en-us_topic_0000002515503852_p18370822173217"></a><a name="en-us_topic_0000002515503852_p18370822173217"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1737914223329"><a name="en-us_topic_0000002515503852_p1737914223329"></a><a name="en-us_topic_0000002515503852_p1737914223329"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p78004497311"><a name="en-us_topic_0000002515503852_p78004497311"></a><a name="en-us_topic_0000002515503852_p78004497311"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row10800749163116"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p11800114913117"><a name="en-us_topic_0000002515503852_p11800114913117"></a><a name="en-us_topic_0000002515503852_p11800114913117"></a><span id="en-us_topic_0000002515503852_text8800164911319"><a name="en-us_topic_0000002515503852_text8800164911319"></a><a name="en-us_topic_0000002515503852_text8800164911319"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1638911222323"><a name="en-us_topic_0000002515503852_p1638911222323"></a><a name="en-us_topic_0000002515503852_p1638911222323"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p17392222113213"><a name="en-us_topic_0000002515503852_p17392222113213"></a><a name="en-us_topic_0000002515503852_p17392222113213"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p168008496318"><a name="en-us_topic_0000002515503852_p168008496318"></a><a name="en-us_topic_0000002515503852_p168008496318"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row5800184916315"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p9800164914316"><a name="en-us_topic_0000002515503852_p9800164914316"></a><a name="en-us_topic_0000002515503852_p9800164914316"></a><span id="en-us_topic_0000002515503852_text980012496318"><a name="en-us_topic_0000002515503852_text980012496318"></a><a name="en-us_topic_0000002515503852_text980012496318"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p7397222133210"><a name="en-us_topic_0000002515503852_p7397222133210"></a><a name="en-us_topic_0000002515503852_p7397222133210"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p194011622143211"><a name="en-us_topic_0000002515503852_p194011622143211"></a><a name="en-us_topic_0000002515503852_p194011622143211"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p178001449123113"><a name="en-us_topic_0000002515503852_p178001449123113"></a><a name="en-us_topic_0000002515503852_p178001449123113"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7800104915312"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1580044933111"><a name="en-us_topic_0000002515503852_p1580044933111"></a><a name="en-us_topic_0000002515503852_p1580044933111"></a><span id="en-us_topic_0000002515503852_text9800184912315"><a name="en-us_topic_0000002515503852_text9800184912315"></a><a name="en-us_topic_0000002515503852_text9800184912315"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p104051222163215"><a name="en-us_topic_0000002515503852_p104051222163215"></a><a name="en-us_topic_0000002515503852_p104051222163215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p440822211325"><a name="en-us_topic_0000002515503852_p440822211325"></a><a name="en-us_topic_0000002515503852_p440822211325"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p38001949193113"><a name="en-us_topic_0000002515503852_p38001949193113"></a><a name="en-us_topic_0000002515503852_p38001949193113"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18800194983115"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1180013499315"><a name="en-us_topic_0000002515503852_p1180013499315"></a><a name="en-us_topic_0000002515503852_p1180013499315"></a><span id="en-us_topic_0000002515503852_text10800649183116"><a name="en-us_topic_0000002515503852_text10800649183116"></a><a name="en-us_topic_0000002515503852_text10800649183116"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18410722203220"><a name="en-us_topic_0000002515503852_p18410722203220"></a><a name="en-us_topic_0000002515503852_p18410722203220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3413182217322"><a name="en-us_topic_0000002515503852_p3413182217322"></a><a name="en-us_topic_0000002515503852_p3413182217322"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1880012499317"><a name="en-us_topic_0000002515503852_p1880012499317"></a><a name="en-us_topic_0000002515503852_p1880012499317"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row13800174918315"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p7800124914316"><a name="en-us_topic_0000002515503852_p7800124914316"></a><a name="en-us_topic_0000002515503852_p7800124914316"></a><span id="en-us_topic_0000002515503852_text868610118325"><a name="en-us_topic_0000002515503852_text868610118325"></a><a name="en-us_topic_0000002515503852_text868610118325"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18415112223217"><a name="en-us_topic_0000002515503852_p18415112223217"></a><a name="en-us_topic_0000002515503852_p18415112223217"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10417422113216"><a name="en-us_topic_0000002515503852_p10417422113216"></a><a name="en-us_topic_0000002515503852_p10417422113216"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p14800449103115"><a name="en-us_topic_0000002515503852_p14800449103115"></a><a name="en-us_topic_0000002515503852_p14800449103115"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1680016498317"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p8800124920315"><a name="en-us_topic_0000002515503852_p8800124920315"></a><a name="en-us_topic_0000002515503852_p8800124920315"></a><span id="en-us_topic_0000002515503852_text2800174910316"><a name="en-us_topic_0000002515503852_text2800174910316"></a><a name="en-us_topic_0000002515503852_text2800174910316"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134191622183215"><a name="en-us_topic_0000002515503852_p134191622183215"></a><a name="en-us_topic_0000002515503852_p134191622183215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p0422822103214"><a name="en-us_topic_0000002515503852_p0422822103214"></a><a name="en-us_topic_0000002515503852_p0422822103214"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19800144917310"><a name="en-us_topic_0000002515503852_p19800144917310"></a><a name="en-us_topic_0000002515503852_p19800144917310"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row2800104920311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p4800194933110"><a name="en-us_topic_0000002515503852_p4800194933110"></a><a name="en-us_topic_0000002515503852_p4800194933110"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section13653173113509"></a>**

```c
...
int ret = 0;
int card_id=0;
int device_id=0;
int port_id=0;
unsigned int prof_time = 1000;
struct dcmi_network_rdma_bandwidth_info bandwidth_info = {0};
ret = dcmi_get_rdma_bandwidth_info (card_id, device_id, port_id, prof_time, &bandwidth_info);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

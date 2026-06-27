# dcmi\_get\_rdma\_bandwidth\_info<a name="EN-US_TOPIC_0000002515510466"></a>

**Prototype<a name="section196251231145019"></a>**

**int dcmi\_get\_rdma\_bandwidth\_info\(int card\_id, int device\_id, int port\_id,** **unsigned int prof\_time, struct dcmi\_network\_rdma\_bandwidth\_info \*network\_rdma\_bandwidth\_info\)**

**Description<a name="section116271631195017"></a>**

Queries the RDMA bandwidth of an NPU network port in a specified profiling time.

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p27082313505"><a name="p27082313505"></a><a name="p27082313505"></a>Device ID. The supported IDs can be obtained by calling <strong id="b2683628933026"><a name="b2683628933026"></a><a name="b2683628933026"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b123442176981337"><a name="b123442176981337"></a><a name="b123442176981337"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p450968185915"><a name="p450968185915"></a><a name="p450968185915"></a>NPU: [0, <strong id="b37654707481337"><a name="b37654707481337"></a><a name="b37654707481337"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row89976111742"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1824103514419"><a name="p1824103514419"></a><a name="p1824103514419"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p424143514417"><a name="p424143514417"></a><a name="p424143514417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1424112357410"><a name="p1424112357410"></a><a name="p1424112357410"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1224183544119"><a name="p1224183544119"></a><a name="p1224183544119"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b1197909082486"><a name="b1197909082486"></a><a name="b1197909082486"></a>0</strong>.</p>
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
<p id="p165801422016"><a name="p165801422016"></a><a name="p165801422016"></a>unsigned int tx_bandwidth; TX bandwidth</p>
<p id="p1559718170017"><a name="p1559718170017"></a><a name="p1559718170017"></a>unsigned int rx_bandwidth; RX bandwidth</p>
<p id="p35970176020"><a name="p35970176020"></a><a name="p35970176020"></a>};</p>
<p id="p1597111719014"><a name="p1597111719014"></a><a name="p1597111719014"></a>The unit is MB/s.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b2016267397856"><a name="b2016267397856"></a><a name="b2016267397856"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="section364683165017"></a>**

**Table  1** Support in different deployment scenarios

<a name="table095520915213"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row12818154935117"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p19818144905117"><a name="en-us_topic_0000002515350556_p19818144905117"></a><a name="en-us_topic_0000002515350556_p19818144905117"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p72920111423"><a name="en-us_topic_0000002515350556_p72920111423"></a><a name="en-us_topic_0000002515350556_p72920111423"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p188183490515"><a name="en-us_topic_0000002515350556_p188183490515"></a><a name="en-us_topic_0000002515350556_p188183490515"></a>PM + Unprivileged Container</p>
<p id="en-us_topic_0000002515350556_p161514571225"><a name="en-us_topic_0000002515350556_p161514571225"></a><a name="en-us_topic_0000002515350556_p161514571225"></a></p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1981815491516"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p58183495516"><a name="en-us_topic_0000002515350556_p58183495516"></a><a name="en-us_topic_0000002515350556_p58183495516"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p081884945119"><a name="en-us_topic_0000002515350556_p081884945119"></a><a name="en-us_topic_0000002515350556_p081884945119"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p98185495511"><a name="en-us_topic_0000002515350556_p98185495511"></a><a name="en-us_topic_0000002515350556_p98185495511"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1781874915512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1681824913518"><a name="en-us_topic_0000002515350556_p1681824913518"></a><a name="en-us_topic_0000002515350556_p1681824913518"></a><span id="en-us_topic_0000002515350556_text1381814492513"><a name="en-us_topic_0000002515350556_text1381814492513"></a><a name="en-us_topic_0000002515350556_text1381814492513"></a><span id="en-us_topic_0000002515350556_text1781824975120"><a name="en-us_topic_0000002515350556_text1781824975120"></a><a name="en-us_topic_0000002515350556_text1781824975120"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p788675755111"><a name="en-us_topic_0000002515350556_p788675755111"></a><a name="en-us_topic_0000002515350556_p788675755111"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p088675795113"><a name="en-us_topic_0000002515350556_p088675795113"></a><a name="en-us_topic_0000002515350556_p088675795113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p688614575515"><a name="en-us_topic_0000002515350556_p688614575515"></a><a name="en-us_topic_0000002515350556_p688614575515"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row4818124912514"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p681824985116"><a name="en-us_topic_0000002515350556_p681824985116"></a><a name="en-us_topic_0000002515350556_p681824985116"></a><span id="en-us_topic_0000002515350556_text158181149145113"><a name="en-us_topic_0000002515350556_text158181149145113"></a><a name="en-us_topic_0000002515350556_text158181149145113"></a><span id="en-us_topic_0000002515350556_text081844985117"><a name="en-us_topic_0000002515350556_text081844985117"></a><a name="en-us_topic_0000002515350556_text081844985117"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p168861157145118"><a name="en-us_topic_0000002515350556_p168861157145118"></a><a name="en-us_topic_0000002515350556_p168861157145118"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p188861657125114"><a name="en-us_topic_0000002515350556_p188861657125114"></a><a name="en-us_topic_0000002515350556_p188861657125114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p688645745119"><a name="en-us_topic_0000002515350556_p688645745119"></a><a name="en-us_topic_0000002515350556_p688645745119"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row2202847205512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12706213161"><a name="en-us_topic_0000002515350556_p12706213161"></a><a name="en-us_topic_0000002515350556_p12706213161"></a><span id="en-us_topic_0000002515350556_text42718211164"><a name="en-us_topic_0000002515350556_text42718211164"></a><a name="en-us_topic_0000002515350556_text42718211164"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p55253416563"><a name="en-us_topic_0000002515350556_p55253416563"></a><a name="en-us_topic_0000002515350556_p55253416563"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p05251540564"><a name="en-us_topic_0000002515350556_p05251540564"></a><a name="en-us_topic_0000002515350556_p05251540564"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p175250435618"><a name="en-us_topic_0000002515350556_p175250435618"></a><a name="en-us_topic_0000002515350556_p175250435618"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1659123792914"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p365923772919"><a name="en-us_topic_0000002515350556_p365923772919"></a><a name="en-us_topic_0000002515350556_p365923772919"></a><span id="en-us_topic_0000002515350556_text7609428297"><a name="en-us_topic_0000002515350556_text7609428297"></a><a name="en-us_topic_0000002515350556_text7609428297"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p0342154513291"><a name="en-us_topic_0000002515350556_p0342154513291"></a><a name="en-us_topic_0000002515350556_p0342154513291"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p11342134582916"><a name="en-us_topic_0000002515350556_p11342134582916"></a><a name="en-us_topic_0000002515350556_p11342134582916"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p10342345102917"><a name="en-us_topic_0000002515350556_p10342345102917"></a><a name="en-us_topic_0000002515350556_p10342345102917"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row179571851165511"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p87312035620"><a name="en-us_topic_0000002515350556_p87312035620"></a><a name="en-us_topic_0000002515350556_p87312035620"></a><span id="en-us_topic_0000002515350556_text187313016562"><a name="en-us_topic_0000002515350556_text187313016562"></a><a name="en-us_topic_0000002515350556_text187313016562"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1667457567"><a name="en-us_topic_0000002515350556_p1667457567"></a><a name="en-us_topic_0000002515350556_p1667457567"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p36715575611"><a name="en-us_topic_0000002515350556_p36715575611"></a><a name="en-us_topic_0000002515350556_p36715575611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p4671505616"><a name="en-us_topic_0000002515350556_p4671505616"></a><a name="en-us_topic_0000002515350556_p4671505616"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row5430115215816"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p84951356389"><a name="en-us_topic_0000002515350556_p84951356389"></a><a name="en-us_topic_0000002515350556_p84951356389"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
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
    // todo: Record logs.
    return ret;
}
...
```

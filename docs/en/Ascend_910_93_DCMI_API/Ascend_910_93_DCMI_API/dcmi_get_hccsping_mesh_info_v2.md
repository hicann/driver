# dcmi\_get\_hccsping\_mesh\_info\_v2<a name="EN-US_TOPIC_0000002546910417"></a>

**Prototype<a name="section12766142411492"></a>**

**int dcmi\_get\_hccsping\_mesh\_info\_v2 \(int card\_id, int device\_id, int port\_id, unsigned int task\_id, struct dcmi\_hccsping\_mesh\_info\_v2 \*hccsping\_mesh\_reply\)**

**Description<a name="section6767424194915"></a>**

Queries pingmesh statistics.

**Parameter Description<a name="section13767132484917"></a>**

<a name="table187981424174912"></a>
<table><thead align="left"><tr id="row987812404919"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p11878132484912"><a name="p11878132484912"></a><a name="p11878132484912"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p13878124174912"><a name="p13878124174912"></a><a name="p13878124174912"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.39%" id="mcps1.1.5.1.3"><p id="p17878182444918"><a name="p17878182444918"></a><a name="p17878182444918"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.29%" id="mcps1.1.5.1.4"><p id="p2087882410494"><a name="p2087882410494"></a><a name="p2087882410494"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row587822454918"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p18781243499"><a name="p18781243499"></a><a name="p18781243499"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p18878224164919"><a name="p18878224164919"></a><a name="p18878224164919"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="p787862411495"><a name="p787862411495"></a><a name="p787862411495"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="p128787249495"><a name="p128787249495"></a><a name="p128787249495"></a>Device ID. The supported IDs can be obtained by calling <strong id="b84744856933049"><a name="b84744856933049"></a><a name="b84744856933049"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row687852416499"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p158781924154917"><a name="p158781924154917"></a><a name="p158781924154917"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p14878124114920"><a name="p14878124114920"></a><a name="p14878124114920"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="p118786247493"><a name="p118786247493"></a><a name="p118786247493"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="p187872444910"><a name="p187872444910"></a><a name="p187872444910"></a>Chip ID, which can be obtained by calling <strong id="b122992829933056"><a name="b122992829933056"></a><a name="b122992829933056"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p687882424914"><a name="p687882424914"></a><a name="p687882424914"></a>NPU: [0, <strong id="b165741376581457"><a name="b165741376581457"></a><a name="b165741376581457"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row10878132414910"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p68781424134910"><a name="p68781424134910"></a><a name="p68781424134910"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p387812242498"><a name="p387812242498"></a><a name="p387812242498"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="p6878424104910"><a name="p6878424104910"></a><a name="p6878424104910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="p18879624114919"><a name="p18879624114919"></a><a name="p18879624114919"></a>(Reserved) Network port number of the NPU device. Currently, the value can only be set to <strong id="b88104893281457"><a name="b88104893281457"></a><a name="b88104893281457"></a>0</strong>.</p>
</td>
</tr>
<tr id="row58791324154910"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p4879172444919"><a name="p4879172444919"></a><a name="p4879172444919"></a>task_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p887916240499"><a name="p887916240499"></a><a name="p887916240499"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="p287972414494"><a name="p287972414494"></a><a name="p287972414494"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="p18791524154916"><a name="p18791524154916"></a><a name="p18791524154916"></a>Task ID. The value range is [0, 1]. The value is the same as the task ID specified by <strong id="b68366091981457"><a name="b68366091981457"></a><a name="b68366091981457"></a>dcmi_start_hccsping_mesh</strong>.</p>
</td>
</tr>
<tr id="row58791424194912"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p787952434918"><a name="p787952434918"></a><a name="p787952434918"></a>hccsping_mesh_reply</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p08791624124911"><a name="p08791624124911"></a><a name="p08791624124911"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="p15879152413494"><a name="p15879152413494"></a><a name="p15879152413494"></a>struct dcmi_hccsping_mesh_info <strong id="b4722927152411"><a name="b4722927152411"></a><a name="b4722927152411"></a>_</strong>v2*</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="p1687918249497"><a name="p1687918249497"></a><a name="p1687918249497"></a>Statistics of a specified resident ping mesh task, including dst_addr, suc_pkt_num, fail_pkt_num, max_time, min_time, avg_time, tp95_time, reply_stat_num, ping_total_num and dest_num.</p>
<p id="p135692064411"><a name="p135692064411"></a><a name="p135692064411"></a>struct dcmi_hccsping_mesh_info {</p>
<p id="p135691613412"><a name="p135691613412"></a><a name="p135691613412"></a>char dst_addr[HCCS_PING_MESH_MAX_NUM][ADDR_MAX_LEN];// List of destination IP addresses</p>
<p id="p20569762045"><a name="p20569762045"></a><a name="p20569762045"></a>unsigned int suc_pkt_num[HCCS_PING_MESH_MAX_NUM];// Number of successful ping operations.</p>
<p id="p25691962048"><a name="p25691962048"></a><a name="p25691962048"></a>unsigned int fail_pkt_num[HCCS_PING_MESH_MAX_NUM];// Number of ping failures.</p>
<p id="p156912615417"><a name="p156912615417"></a><a name="p156912615417"></a>long max_time[HCCS_PING_MESH_MAX_NUM];// Maximum ping delay</p>
<p id="p145691665420"><a name="p145691665420"></a><a name="p145691665420"></a>long min_time[HCCS_PING_MESH_MAX_NUM];// Minimum latency</p>
<p id="p556996744"><a name="p556996744"></a><a name="p556996744"></a>long avg_time[HCCS_PING_MESH_MAX_NUM];// Average ping delay</p>
<p id="p1156910618417"><a name="p1156910618417"></a><a name="p1156910618417"></a>long tp95_time[HCCS_PING_MESH_MAX_NUM];// 95th percentile ping delay.</p>
<p id="p15569463417"><a name="p15569463417"></a><a name="p15569463417"></a>int reply_stat_num[HCCS_PING_MESH_MAX_NUM]; // Number of sample rounds used for statistics</p>
<p id="p8569262417"><a name="p8569262417"></a><a name="p8569262417"></a>unsigned long long ping_total_num[HCCS_PING_MESH_MAX_NUM];// Total number of ping rounds since the resident task is started</p>
<p id="p1656946246"><a name="p1656946246"></a><a name="p1656946246"></a>int dest_num;// Number of destination addresses</p>
<p id="p135697614416"><a name="p135697614416"></a><a name="p135697614416"></a>};</p>
<p id="en-us_topic_0000002338976614_p0170135110169"><a name="en-us_topic_0000002338976614_p0170135110169"></a><a name="en-us_topic_0000002338976614_p0170135110169"></a>struct dcmi_hccsping_mesh_info_v2 {</p>
<p id="en-us_topic_0000002338976614_p1317014517162"><a name="en-us_topic_0000002338976614_p1317014517162"></a><a name="en-us_topic_0000002338976614_p1317014517162"></a>struct dcmi_hccsping_mesh_info info;</p>
<p id="en-us_topic_0000002338976614_p131707517164"><a name="en-us_topic_0000002338976614_p131707517164"></a><a name="en-us_topic_0000002338976614_p131707517164"></a>unsigned char L1_plane_check_res[HCCS_PING_MESH_MAX_NUM]; // L1 planes where HCCS links to each destination address are faulty</p>
<p id="en-us_topic_0000002338976614_p141701851121613"><a name="en-us_topic_0000002338976614_p141701851121613"></a><a name="en-us_topic_0000002338976614_p141701851121613"></a>unsigned char reserved[HCCS_PING_MESH_MAX_NUM];// Reserved</p>
<p id="en-us_topic_0000002338976614_p16170185113169"><a name="en-us_topic_0000002338976614_p16170185113169"></a><a name="en-us_topic_0000002338976614_p16170185113169"></a>};</p>
<div class="note" id="note8393718184"><a name="note8393718184"></a><a name="note8393718184"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul97018984016"></a><a name="ul97018984016"></a><ul id="ul97018984016"><li>In the output structure, the index in <strong id="b111011419481457"><a name="b111011419481457"></a><a name="b111011419481457"></a>dst_addr</strong> for a destination address is the same as the index in each result of pinging that address in each array. For example, for the destination address <strong id="b2544068281457"><a name="b2544068281457"></a><a name="b2544068281457"></a>dst_addr[0]</strong>, the number of successful ping operations is <strong id="b160244515481457"><a name="b160244515481457"></a><a name="b160244515481457"></a>suc_pkt_num[0]</strong>, the number of ping failures is <strong id="b23068036081457"><a name="b23068036081457"></a><a name="b23068036081457"></a>fail_pkt_num[0]</strong>, and so on.</li><li>If the values of <strong id="b5277172881457"><a name="b5277172881457"></a><a name="b5277172881457"></a>max_time</strong>, <strong id="b146048615781457"><a name="b146048615781457"></a><a name="b146048615781457"></a>min_time</strong>, <strong id="b16606172781457"><a name="b16606172781457"></a><a name="b16606172781457"></a>avg_time</strong> and <strong id="b105281753081457"><a name="b105281753081457"></a><a name="b105281753081457"></a>tp95_time</strong> are -1, the corresponding destination address is not pinged.</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section117841124144913"></a>**

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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b34738031281457"><a name="b34738031281457"></a><a name="b34738031281457"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1079016243498"></a>**

None

**Restrictions<a name="section137900244496"></a>**

The specified device and the destination device must use the same NPU driver version.

After the resident task is enabled, wait for one task\_interval \(polling interval of the resident task\) and one ping packet sending period \(at least pkt\_send\_num × pkt\_interval ms\) before you can query the data.

This API retrieves the most recent statistical data.

This API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="table1997161105818"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section27965246494"></a>**

```c
... 
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
unsigned int task_id = 0;
struct dcmi_hccsping_mesh_info_v2 hccsping_mesh_reply = {0};
ret = dcmi_get_hccsping_mesh_info_v2 (card_id, device_id, port_id, task_id, &hccsping_mesh_reply);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

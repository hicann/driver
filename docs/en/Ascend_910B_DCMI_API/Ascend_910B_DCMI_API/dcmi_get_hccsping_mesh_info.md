# dcmi\_get\_hccsping\_mesh\_info<a name="EN-US_TOPIC_0000002546903779"></a>

**Prototype<a name="section1153185215497"></a>**

**int dcmi\_get\_hccsping\_mesh\_info \(int card\_id, int device\_id, int port\_id, unsigned int task\_id, struct dcmi\_hccsping\_mesh\_info \*hccsping\_mesh\_reply\)**

**Description<a name="section7120135716498"></a>**

Queries pingmesh statistics.

**Parameter Description<a name="section76611617501"></a>**

<a name="table1439912501572"></a>
<table><thead align="left"><tr id="en-us_topic_0000002338976614_row987812404919"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002338976614_p11878132484912"><a name="en-us_topic_0000002338976614_p11878132484912"></a><a name="en-us_topic_0000002338976614_p11878132484912"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002338976614_p13878124174912"><a name="en-us_topic_0000002338976614_p13878124174912"></a><a name="en-us_topic_0000002338976614_p13878124174912"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.39%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002338976614_p17878182444918"><a name="en-us_topic_0000002338976614_p17878182444918"></a><a name="en-us_topic_0000002338976614_p17878182444918"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.29%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002338976614_p2087882410494"><a name="en-us_topic_0000002338976614_p2087882410494"></a><a name="en-us_topic_0000002338976614_p2087882410494"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002338976614_row587822454918"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976614_p18781243499"><a name="en-us_topic_0000002338976614_p18781243499"></a><a name="en-us_topic_0000002338976614_p18781243499"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976614_p18878224164919"><a name="en-us_topic_0000002338976614_p18878224164919"></a><a name="en-us_topic_0000002338976614_p18878224164919"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976614_p787862411495"><a name="en-us_topic_0000002338976614_p787862411495"></a><a name="en-us_topic_0000002338976614_p787862411495"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976614_p128787249495"><a name="en-us_topic_0000002338976614_p128787249495"></a><a name="en-us_topic_0000002338976614_p128787249495"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1010187151102854"><a name="b1010187151102854"></a><a name="b1010187151102854"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976614_row687852416499"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976614_p158781924154917"><a name="en-us_topic_0000002338976614_p158781924154917"></a><a name="en-us_topic_0000002338976614_p158781924154917"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976614_p14878124114920"><a name="en-us_topic_0000002338976614_p14878124114920"></a><a name="en-us_topic_0000002338976614_p14878124114920"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976614_p118786247493"><a name="en-us_topic_0000002338976614_p118786247493"></a><a name="en-us_topic_0000002338976614_p118786247493"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976614_p187872444910"><a name="en-us_topic_0000002338976614_p187872444910"></a><a name="en-us_topic_0000002338976614_p187872444910"></a>Chip ID, which can be obtained by calling <strong id="b159496153102525"><a name="b159496153102525"></a><a name="b159496153102525"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002338976614_p687882424914"><a name="en-us_topic_0000002338976614_p687882424914"></a><a name="en-us_topic_0000002338976614_p687882424914"></a>NPU chip: [0, <strong id="b1291863403111950"><a name="b1291863403111950"></a><a name="b1291863403111950"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002338976614_row10878132414910"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976614_p68781424134910"><a name="en-us_topic_0000002338976614_p68781424134910"></a><a name="en-us_topic_0000002338976614_p68781424134910"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976614_p387812242498"><a name="en-us_topic_0000002338976614_p387812242498"></a><a name="en-us_topic_0000002338976614_p387812242498"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976614_p6878424104910"><a name="en-us_topic_0000002338976614_p6878424104910"></a><a name="en-us_topic_0000002338976614_p6878424104910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976614_p18879624114919"><a name="en-us_topic_0000002338976614_p18879624114919"></a><a name="en-us_topic_0000002338976614_p18879624114919"></a>(Reserved) Network port number of the NPU device. Currently, the value can only be set to <strong id="b2651356603219"><a name="b2651356603219"></a><a name="b2651356603219"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976614_row58791324154910"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976614_p4879172444919"><a name="en-us_topic_0000002338976614_p4879172444919"></a><a name="en-us_topic_0000002338976614_p4879172444919"></a>task_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976614_p887916240499"><a name="en-us_topic_0000002338976614_p887916240499"></a><a name="en-us_topic_0000002338976614_p887916240499"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976614_p287972414494"><a name="en-us_topic_0000002338976614_p287972414494"></a><a name="en-us_topic_0000002338976614_p287972414494"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976614_p18791524154916"><a name="en-us_topic_0000002338976614_p18791524154916"></a><a name="en-us_topic_0000002338976614_p18791524154916"></a>Task ID. The value range is [0, 1]. The value is the same as the task ID specified by <strong id="b5321411830"><a name="b5321411830"></a><a name="b5321411830"></a>dcmi_start_hccsping_mesh</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976614_row58791424194912"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976614_p787952434918"><a name="en-us_topic_0000002338976614_p787952434918"></a><a name="en-us_topic_0000002338976614_p787952434918"></a>hccsping_mesh_reply</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976614_p08791624124911"><a name="en-us_topic_0000002338976614_p08791624124911"></a><a name="en-us_topic_0000002338976614_p08791624124911"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.39%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976614_p15879152413494"><a name="en-us_topic_0000002338976614_p15879152413494"></a><a name="en-us_topic_0000002338976614_p15879152413494"></a>struct dcmi_hccsping_mesh_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.29%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976614_p1687918249497"><a name="en-us_topic_0000002338976614_p1687918249497"></a><a name="en-us_topic_0000002338976614_p1687918249497"></a>Statistics of a specified resident ping mesh task, including dst_addr, suc_pkt_num, fail_pkt_num, max_time, min_time, avg_time, tp95_time, reply_stat_num, ping_total_num and dest_num.</p>
<p id="en-us_topic_0000002338976614_p135692064411"><a name="en-us_topic_0000002338976614_p135692064411"></a><a name="en-us_topic_0000002338976614_p135692064411"></a>struct dcmi_hccsping_mesh_info {</p>
<p id="en-us_topic_0000002338976614_p135691613412"><a name="en-us_topic_0000002338976614_p135691613412"></a><a name="en-us_topic_0000002338976614_p135691613412"></a>char dst_addr[HCCS_PING_MESH_MAX_NUM][ADDR_MAX_LEN];// List of destination IP addresses</p>
<p id="en-us_topic_0000002338976614_p20569762045"><a name="en-us_topic_0000002338976614_p20569762045"></a><a name="en-us_topic_0000002338976614_p20569762045"></a>unsigned int suc_pkt_num[HCCS_PING_MESH_MAX_NUM];// Number of successful ping operations.</p>
<p id="en-us_topic_0000002338976614_p25691962048"><a name="en-us_topic_0000002338976614_p25691962048"></a><a name="en-us_topic_0000002338976614_p25691962048"></a>unsigned int fail_pkt_num[HCCS_PING_MESH_MAX_NUM];// Number of ping failures.</p>
<p id="en-us_topic_0000002338976614_p156912615417"><a name="en-us_topic_0000002338976614_p156912615417"></a><a name="en-us_topic_0000002338976614_p156912615417"></a>long max_time[HCCS_PING_MESH_MAX_NUM];// Maximum ping delay</p>
<p id="en-us_topic_0000002338976614_p145691665420"><a name="en-us_topic_0000002338976614_p145691665420"></a><a name="en-us_topic_0000002338976614_p145691665420"></a>long min_time[HCCS_PING_MESH_MAX_NUM];// Minimum latency</p>
<p id="en-us_topic_0000002338976614_p556996744"><a name="en-us_topic_0000002338976614_p556996744"></a><a name="en-us_topic_0000002338976614_p556996744"></a>long avg_time[HCCS_PING_MESH_MAX_NUM];// Average ping delay</p>
<p id="en-us_topic_0000002338976614_p1156910618417"><a name="en-us_topic_0000002338976614_p1156910618417"></a><a name="en-us_topic_0000002338976614_p1156910618417"></a>long tp95_time[HCCS_PING_MESH_MAX_NUM];// 95th percentile ping delay.</p>
<p id="en-us_topic_0000002338976614_p15569463417"><a name="en-us_topic_0000002338976614_p15569463417"></a><a name="en-us_topic_0000002338976614_p15569463417"></a>int reply_stat_num[HCCS_PING_MESH_MAX_NUM]; // Number of sample rounds used for statistics</p>
<p id="en-us_topic_0000002338976614_p8569262417"><a name="en-us_topic_0000002338976614_p8569262417"></a><a name="en-us_topic_0000002338976614_p8569262417"></a>unsigned long long ping_total_num[HCCS_PING_MESH_MAX_NUM];// Total number of ping rounds since the resident task is started</p>
<p id="en-us_topic_0000002338976614_p1656946246"><a name="en-us_topic_0000002338976614_p1656946246"></a><a name="en-us_topic_0000002338976614_p1656946246"></a>int dest_num;// Number of destination addresses</p>
<p id="en-us_topic_0000002338976614_p135697614416"><a name="en-us_topic_0000002338976614_p135697614416"></a><a name="en-us_topic_0000002338976614_p135697614416"></a>};</p>
<div class="note" id="en-us_topic_0000002338976614_note8393718184"><a name="en-us_topic_0000002338976614_note8393718184"></a><a name="en-us_topic_0000002338976614_note8393718184"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="en-us_topic_0000002338976614_ul97018984016"></a><a name="en-us_topic_0000002338976614_ul97018984016"></a><ul id="en-us_topic_0000002338976614_ul97018984016"><li>In the output structure, the index in <strong id="b116321233937"><a name="b116321233937"></a><a name="b116321233937"></a>dst_addr</strong> for a destination address is the same as the index in each result of pinging that address in each array. For example, for the destination address <strong id="b187279369313"><a name="b187279369313"></a><a name="b187279369313"></a>dst_addr[0]</strong>, the number of successful ping operations is <strong id="b272713361636"><a name="b272713361636"></a><a name="b272713361636"></a>suc_pkt_num[0]</strong>, the number of ping failures is <strong id="b372773615311"><a name="b372773615311"></a><a name="b372773615311"></a>fail_pkt_num[0]</strong>, and so on.</li><li>If the values of <strong id="b194337441838"><a name="b194337441838"></a><a name="b194337441838"></a>max_time</strong>, <strong id="b743311448310"><a name="b743311448310"></a><a name="b743311448310"></a>min_time</strong>, <strong id="b164334449314"><a name="b164334449314"></a><a name="b164334449314"></a>avg_time</strong> and <strong id="b1143316448312"><a name="b1143316448312"></a><a name="b1143316448312"></a>tp95_time</strong> are -1, the corresponding destination address is not pinged.</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section1440445105018"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b166538667385640"><a name="b166538667385640"></a><a name="b166538667385640"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section175612813502"></a>**

None.

**Restrictions<a name="section124361912185014"></a>**

**Table  1** Support in different deployment scenarios

<a name="table75388578524"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1210513304816"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p558011817325"><a name="en-us_topic_0000002515503852_p558011817325"></a><a name="en-us_topic_0000002515503852_p558011817325"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p25806812321"><a name="en-us_topic_0000002515503852_p25806812321"></a><a name="en-us_topic_0000002515503852_p25806812321"></a><strong id="en-us_topic_0000002515503852_b156561347844"><a name="en-us_topic_0000002515503852_b156561347844"></a><a name="en-us_topic_0000002515503852_b156561347844"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p558018833211"><a name="en-us_topic_0000002515503852_p558018833211"></a><a name="en-us_topic_0000002515503852_p558018833211"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b686519481414"><a name="en-us_topic_0000002515503852_b686519481414"></a><a name="en-us_topic_0000002515503852_b686519481414"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p35801189326"><a name="en-us_topic_0000002515503852_p35801189326"></a><a name="en-us_topic_0000002515503852_p35801189326"></a><strong id="en-us_topic_0000002515503852_b398912494411"><a name="en-us_topic_0000002515503852_b398912494411"></a><a name="en-us_topic_0000002515503852_b398912494411"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row14576182015105"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13661881916"><a name="en-us_topic_0000002515503852_p13661881916"></a><a name="en-us_topic_0000002515503852_p13661881916"></a><span id="en-us_topic_0000002515503852_ph116612081298"><a name="en-us_topic_0000002515503852_ph116612081298"></a><a name="en-us_topic_0000002515503852_ph116612081298"></a><span id="en-us_topic_0000002515503852_text26611487916"><a name="en-us_topic_0000002515503852_text26611487916"></a><a name="en-us_topic_0000002515503852_text26611487916"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p057642081019"><a name="en-us_topic_0000002515503852_p057642081019"></a><a name="en-us_topic_0000002515503852_p057642081019"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p65761200102"><a name="en-us_topic_0000002515503852_p65761200102"></a><a name="en-us_topic_0000002515503852_p65761200102"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1357610206101"><a name="en-us_topic_0000002515503852_p1357610206101"></a><a name="en-us_topic_0000002515503852_p1357610206101"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row318512127818"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611581596"><a name="en-us_topic_0000002515503852_p86611581596"></a><a name="en-us_topic_0000002515503852_p86611581596"></a><span id="en-us_topic_0000002515503852_text66619818911"><a name="en-us_topic_0000002515503852_text66619818911"></a><a name="en-us_topic_0000002515503852_text66619818911"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1441443298"><a name="en-us_topic_0000002515503852_p1441443298"></a><a name="en-us_topic_0000002515503852_p1441443298"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2420631892"><a name="en-us_topic_0000002515503852_p2420631892"></a><a name="en-us_topic_0000002515503852_p2420631892"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18425123899"><a name="en-us_topic_0000002515503852_p18425123899"></a><a name="en-us_topic_0000002515503852_p18425123899"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1273713241084"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p56611781094"><a name="en-us_topic_0000002515503852_p56611781094"></a><a name="en-us_topic_0000002515503852_p56611781094"></a><span id="en-us_topic_0000002515503852_text56611281693"><a name="en-us_topic_0000002515503852_text56611281693"></a><a name="en-us_topic_0000002515503852_text56611281693"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p64311736915"><a name="en-us_topic_0000002515503852_p64311736915"></a><a name="en-us_topic_0000002515503852_p64311736915"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p04391434914"><a name="en-us_topic_0000002515503852_p04391434914"></a><a name="en-us_topic_0000002515503852_p04391434914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p244917315919"><a name="en-us_topic_0000002515503852_p244917315919"></a><a name="en-us_topic_0000002515503852_p244917315919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7672192219815"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p166611689914"><a name="en-us_topic_0000002515503852_p166611689914"></a><a name="en-us_topic_0000002515503852_p166611689914"></a><span id="en-us_topic_0000002515503852_text126611581798"><a name="en-us_topic_0000002515503852_text126611581798"></a><a name="en-us_topic_0000002515503852_text126611581798"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p12459143996"><a name="en-us_topic_0000002515503852_p12459143996"></a><a name="en-us_topic_0000002515503852_p12459143996"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10470531895"><a name="en-us_topic_0000002515503852_p10470531895"></a><a name="en-us_topic_0000002515503852_p10470531895"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12476033912"><a name="en-us_topic_0000002515503852_p12476033912"></a><a name="en-us_topic_0000002515503852_p12476033912"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row153452020881"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611181098"><a name="en-us_topic_0000002515503852_p86611181098"></a><a name="en-us_topic_0000002515503852_p86611181098"></a><span id="en-us_topic_0000002515503852_text16611819911"><a name="en-us_topic_0000002515503852_text16611819911"></a><a name="en-us_topic_0000002515503852_text16611819911"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134813311917"><a name="en-us_topic_0000002515503852_p134813311917"></a><a name="en-us_topic_0000002515503852_p134813311917"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3486231596"><a name="en-us_topic_0000002515503852_p3486231596"></a><a name="en-us_topic_0000002515503852_p3486231596"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p44911135913"><a name="en-us_topic_0000002515503852_p44911135913"></a><a name="en-us_topic_0000002515503852_p44911135913"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row20496217988"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611689916"><a name="en-us_topic_0000002515503852_p86611689916"></a><a name="en-us_topic_0000002515503852_p86611689916"></a><span id="en-us_topic_0000002515503852_text105131140182910"><a name="en-us_topic_0000002515503852_text105131140182910"></a><a name="en-us_topic_0000002515503852_text105131140182910"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p649613392"><a name="en-us_topic_0000002515503852_p649613392"></a><a name="en-us_topic_0000002515503852_p649613392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2050114313914"><a name="en-us_topic_0000002515503852_p2050114313914"></a><a name="en-us_topic_0000002515503852_p2050114313914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p175075312918"><a name="en-us_topic_0000002515503852_p175075312918"></a><a name="en-us_topic_0000002515503852_p175075312918"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1775216157819"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p766118812915"><a name="en-us_topic_0000002515503852_p766118812915"></a><a name="en-us_topic_0000002515503852_p766118812915"></a><span id="en-us_topic_0000002515503852_text136611481596"><a name="en-us_topic_0000002515503852_text136611481596"></a><a name="en-us_topic_0000002515503852_text136611481596"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p205121037920"><a name="en-us_topic_0000002515503852_p205121037920"></a><a name="en-us_topic_0000002515503852_p205121037920"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5517131993"><a name="en-us_topic_0000002515503852_p5517131993"></a><a name="en-us_topic_0000002515503852_p5517131993"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p115221437916"><a name="en-us_topic_0000002515503852_p115221437916"></a><a name="en-us_topic_0000002515503852_p115221437916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1499855417336"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p48161158173310"><a name="en-us_topic_0000002515503852_p48161158173310"></a><a name="en-us_topic_0000002515503852_p48161158173310"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section2099017164502"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
unsigned int task_id = 0;
struct dcmi_hccsping_mesh_info hccsping_mesh_reply = {0};
ret = dcmi_get_hccsping_mesh_info (card_id, device_id, port_id, task_id, &hccsping_mesh_reply);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

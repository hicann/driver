# dcmi\_start\_hccsping\_mesh<a name="EN-US_TOPIC_0000002546983811"></a>

**Prototype<a name="section1153185215497"></a>**

**int dcmi\_start\_hccsping\_mesh \(int card\_id, int device\_id, int port\_id, struct dcmi\_hccsping\_mesh\_operate \*hccsping\_mesh\)**

**Description<a name="section7120135716498"></a>**

Starts a resident pingmesh task.

**Parameter Description<a name="section76611617501"></a>**

<a name="table10744732125212"></a>
<table><thead align="left"><tr id="en-us_topic_0000002373014845_row10250156104917"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002373014845_p525013624918"><a name="en-us_topic_0000002373014845_p525013624918"></a><a name="en-us_topic_0000002373014845_p525013624918"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002373014845_p1225011617491"><a name="en-us_topic_0000002373014845_p1225011617491"></a><a name="en-us_topic_0000002373014845_p1225011617491"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002373014845_p52501614493"><a name="en-us_topic_0000002373014845_p52501614493"></a><a name="en-us_topic_0000002373014845_p52501614493"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002373014845_p82504616492"><a name="en-us_topic_0000002373014845_p82504616492"></a><a name="en-us_topic_0000002373014845_p82504616492"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002373014845_row125017610497"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002373014845_p122501661492"><a name="en-us_topic_0000002373014845_p122501661492"></a><a name="en-us_topic_0000002373014845_p122501661492"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002373014845_p825020674912"><a name="en-us_topic_0000002373014845_p825020674912"></a><a name="en-us_topic_0000002373014845_p825020674912"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002373014845_p625019613493"><a name="en-us_topic_0000002373014845_p625019613493"></a><a name="en-us_topic_0000002373014845_p625019613493"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002373014845_p92501269490"><a name="en-us_topic_0000002373014845_p92501269490"></a><a name="en-us_topic_0000002373014845_p92501269490"></a>Device ID. The supported IDs can be obtained by calling <strong id="b575818646102853"><a name="b575818646102853"></a><a name="b575818646102853"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373014845_row1325026204911"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002373014845_p425056184914"><a name="en-us_topic_0000002373014845_p425056184914"></a><a name="en-us_topic_0000002373014845_p425056184914"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002373014845_p1125115634916"><a name="en-us_topic_0000002373014845_p1125115634916"></a><a name="en-us_topic_0000002373014845_p1125115634916"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002373014845_p1025126134914"><a name="en-us_topic_0000002373014845_p1025126134914"></a><a name="en-us_topic_0000002373014845_p1025126134914"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002373014845_p12511669493"><a name="en-us_topic_0000002373014845_p12511669493"></a><a name="en-us_topic_0000002373014845_p12511669493"></a>Chip ID, which can be obtained by calling <strong id="b142070283102524"><a name="b142070283102524"></a><a name="b142070283102524"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002373014845_p12251176204918"><a name="en-us_topic_0000002373014845_p12251176204918"></a><a name="en-us_topic_0000002373014845_p12251176204918"></a>NPU chip: [0, <strong id="b1527608713111949"><a name="b1527608713111949"></a><a name="b1527608713111949"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002373014845_row132516624913"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002373014845_p52518654916"><a name="en-us_topic_0000002373014845_p52518654916"></a><a name="en-us_topic_0000002373014845_p52518654916"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002373014845_p162512694916"><a name="en-us_topic_0000002373014845_p162512694916"></a><a name="en-us_topic_0000002373014845_p162512694916"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002373014845_p32513613495"><a name="en-us_topic_0000002373014845_p32513613495"></a><a name="en-us_topic_0000002373014845_p32513613495"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002373014845_p1025116614913"><a name="en-us_topic_0000002373014845_p1025116614913"></a><a name="en-us_topic_0000002373014845_p1025116614913"></a>(Reserved) Network port number of the NPU device. Currently, the value can only be set to <strong id="b98604149219"><a name="b98604149219"></a><a name="b98604149219"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002373014845_row112529634916"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002373014845_p125216154914"><a name="en-us_topic_0000002373014845_p125216154914"></a><a name="en-us_topic_0000002373014845_p125216154914"></a>hccsping_mesh</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002373014845_p14252116164919"><a name="en-us_topic_0000002373014845_p14252116164919"></a><a name="en-us_topic_0000002373014845_p14252116164919"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002373014845_p1525218618492"><a name="en-us_topic_0000002373014845_p1525218618492"></a><a name="en-us_topic_0000002373014845_p1525218618492"></a>struct dcmi_hccsping_mesh_operate *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002373014845_p152531065495"><a name="en-us_topic_0000002373014845_p152531065495"></a><a name="en-us_topic_0000002373014845_p152531065495"></a>Information about the resident pingmesh task, including dst_addr_list, pkt_size, pkt_send_num, pkt_interval, task_interval, task_id, and timeout.</p>
<p id="en-us_topic_0000002373014845_p4152722001"><a name="en-us_topic_0000002373014845_p4152722001"></a><a name="en-us_topic_0000002373014845_p4152722001"></a>struct dcmi_hccsping_mesh_operate {</p>
<p id="en-us_topic_0000002373014845_p61525210010"><a name="en-us_topic_0000002373014845_p61525210010"></a><a name="en-us_topic_0000002373014845_p61525210010"></a>char dst_addr_list[IP_ADDR_LIST_LEN];// IPv4 address or SDID list. Use commas (,) to separate the addresses.</p>
<p id="en-us_topic_0000002373014845_p615242601"><a name="en-us_topic_0000002373014845_p615242601"></a><a name="en-us_topic_0000002373014845_p615242601"></a>int pkt_size;// Ping packet size, in bytes. The value range is [1792, 3000].</p>
<p id="en-us_topic_0000002373014845_p18231655203917"><a name="en-us_topic_0000002373014845_p18231655203917"></a><a name="en-us_topic_0000002373014845_p18231655203917"></a>The packet header size is 1024 bytes. The correctness of the subsequent 1025 bytes to the <strong id="b1591122617215"><a name="b1591122617215"></a><a name="b1591122617215"></a>pkt_size</strong> field is verified. The field type distribution of every 1024 bytes is as follows: 0xFF (256 bytes), 0x00 (256 bytes), 0xAA (256 bytes), and 0x55 (256 bytes).</p>
<p id="en-us_topic_0000002373014845_p141521021400"><a name="en-us_topic_0000002373014845_p141521021400"></a><a name="en-us_topic_0000002373014845_p141521021400"></a>int pkt_send_num;// Number of sent ping packets. The value range is [1, 1000].</p>
<p id="en-us_topic_0000002373014845_p1215211211019"><a name="en-us_topic_0000002373014845_p1215211211019"></a><a name="en-us_topic_0000002373014845_p1215211211019"></a>int pkt_interval;// Interval between ping packets. The value range is [0, 1000], in ms.</p>
<p id="en-us_topic_0000002373014845_p69366361678"><a name="en-us_topic_0000002373014845_p69366361678"></a><a name="en-us_topic_0000002373014845_p69366361678"></a>int timeout;// Reserved, packet timeout interval, timeout &gt;= 0</p>
<p id="en-us_topic_0000002373014845_p11152621109"><a name="en-us_topic_0000002373014845_p11152621109"></a><a name="en-us_topic_0000002373014845_p11152621109"></a>int task_interval;// Polling interval of the resident task. The value range is [1, 60], in seconds.</p>
<p id="en-us_topic_0000002373014845_p915216211016"><a name="en-us_topic_0000002373014845_p915216211016"></a><a name="en-us_topic_0000002373014845_p915216211016"></a>int task_id;// Task ID. The value range is [0, 1].</p>
<p id="en-us_topic_0000002373014845_p10152521109"><a name="en-us_topic_0000002373014845_p10152521109"></a><a name="en-us_topic_0000002373014845_p10152521109"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b58967285585639"><a name="b58967285585639"></a><a name="b58967285585639"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section14428562225"></a>**

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
struct dcmi_hccsping_mesh_operate hccsping_mesh = {
        .dst_addr_list = "192.xx.xx.1,192.xx.xx.2,192.xx.xx.3",
        .pkt_size = 1792,
        .pkt_send_num = 4,
        .pkt_interval = 1,
        .timeout = 1,
        .task_interval = 1,
        .task_id = 0
    };
ret = dcmi_start_hccsping_mesh (card_id, device_id, port_id, &hccsping_mesh);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

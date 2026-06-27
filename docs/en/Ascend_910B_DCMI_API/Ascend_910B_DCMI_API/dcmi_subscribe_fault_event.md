# dcmi\_subscribe\_fault\_event<a name="EN-US_TOPIC_0000002546903735"></a>

**Prototype<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412077"></a>**

**int dcmi\_subscribe\_fault\_event\(int card\_id, int device\_id, struct dcmi\_event\_filter filter, dcmi\_fault\_event\_callback handler\)**

**Description<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412078"></a>**

Subscribes to the device fault or recovery events.

**Parameter Description<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412079"></a>**

<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row7580267"><th class="cellrowborder" valign="top" width="15.72%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p10021890"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p10021890"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="13.850000000000001%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p6466753"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p6466753"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.05%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p54045009"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p54045009"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="54.379999999999995%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p15569626"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p15569626"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row10560021192510"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p7782194112263"><a name="p7782194112263"></a><a name="p7782194112263"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p11782124113268"><a name="p11782124113268"></a><a name="p11782124113268"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="p678254192617"><a name="p678254192617"></a><a name="p678254192617"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="p117821641162613"><a name="p117821641162613"></a><a name="p117821641162613"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1509900291102831"><a name="b1509900291102831"></a><a name="b1509900291102831"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row15462171542913"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p1378274110266"><a name="p1378274110266"></a><a name="p1378274110266"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p107831541162615"><a name="p107831541162615"></a><a name="p107831541162615"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="p197831141162619"><a name="p197831141162619"></a><a name="p197831141162619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="p4783641142619"><a name="p4783641142619"></a><a name="p4783641142619"></a>Chip ID, which can be obtained by calling <strong id="b41847739310251"><a name="b41847739310251"></a><a name="b41847739310251"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p18783124122616"><a name="p18783124122616"></a><a name="p18783124122616"></a>NPU: [0, <strong id="b537768941105348"><a name="b537768941105348"></a><a name="b537768941105348"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_row029010598584"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p177831941142620"><a name="p177831941142620"></a><a name="p177831941142620"></a>filter</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p67839413264"><a name="p67839413264"></a><a name="p67839413264"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="p6783441172611"><a name="p6783441172611"></a><a name="p6783441172611"></a>struct dcmi_event_filter</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="p107837415267"><a name="p107837415267"></a><a name="p107837415267"></a>You can subscribe to only the events that meet the following filter criteria.</p>
<p id="p478324114261"><a name="p478324114261"></a><a name="p478324114261"></a>#define DCMI_EVENT_FILTER_FLAG_EVENT_ID (1UL &lt;&lt; 0)</p>
<p id="p07830411263"><a name="p07830411263"></a><a name="p07830411263"></a>#define DCMI_EVENT_FILTER_FLAG_SERVERITY (1UL &lt;&lt; 1)</p>
<p id="p18783144192618"><a name="p18783144192618"></a><a name="p18783144192618"></a>#define DCMI_EVENT_FILTER_FLAG_NODE_TYPE (1UL &lt;&lt; 2)</p>
<p id="p15783641152618"><a name="p15783641152618"></a><a name="p15783641152618"></a>#define DCMI_MAX_EVENT_RESV_LENGTH 32</p>
<p id="p7783164122618"><a name="p7783164122618"></a><a name="p7783164122618"></a>struct dcmi_event_filter {</p>
<p id="p10783941102611"><a name="p10783941102611"></a><a name="p10783941102611"></a>unsigned long long filter_flag; // It can be used to enable one or all filter criteria. The filter criteria are as follows:</p>
<p id="p147834411264"><a name="p147834411264"></a><a name="p147834411264"></a><strong id="b1434414491242"><a name="b1434414491242"></a><a name="b1434414491242"></a>0</strong>: disables the filter criteria.</p>
<p id="p10783114114268"><a name="p10783114114268"></a><a name="p10783114114268"></a><strong id="b186885501143"><a name="b186885501143"></a><a name="b186885501143"></a>DCMI_EVENT_FILTER_FLAG_EVENT_ID</strong>: receives only specified events.</p>
<p id="p27831841172610"><a name="p27831841172610"></a><a name="p27831841172610"></a><strong id="b10869145218420"><a name="b10869145218420"></a><a name="b10869145218420"></a>DCMI_EVENT_FILTER_FLAG_SERVERITY</strong>: receives only the events of a specified level and higher levels.</p>
<p id="p1078314142613"><a name="p1078314142613"></a><a name="p1078314142613"></a><strong id="b352985413418"><a name="b352985413418"></a><a name="b352985413418"></a>DCMI_EVENT_FILTER_FLAG_NODE_TYPE</strong>: receives only events of a specified node type.</p>
<p id="en-us_topic_0000001549080826_p478314142614"><a name="en-us_topic_0000001549080826_p478314142614"></a><a name="en-us_topic_0000001549080826_p478314142614"></a>unsigned int event_id;  // Receives specified events.</p>
<p id="en-us_topic_0000001549080826_p1078313417269"><a name="en-us_topic_0000001549080826_p1078313417269"></a><a name="en-us_topic_0000001549080826_p1078313417269"></a>unsigned char severity; // Receives events of a specified severity and higher. For details, see the severity definition in the <strong id="b7136722147"><a name="b7136722147"></a><a name="b7136722147"></a>struct dcmi_dms_fault_event</strong>.</p>
<p id="en-us_topic_0000001549080826_p12783174114261"><a name="en-us_topic_0000001549080826_p12783174114261"></a><a name="en-us_topic_0000001549080826_p12783174114261"></a>unsigned char node_type;  // Receives events of a specified node type.</p>
<p id="en-us_topic_0000001549080826_p6783184122615"><a name="en-us_topic_0000001549080826_p6783184122615"></a><a name="en-us_topic_0000001549080826_p6783184122615"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH];// Reserved</p>
<p id="p6783184122615"><a name="p6783184122615"></a><a name="p6783184122615"></a></p>
<p id="p20783541132610"><a name="p20783541132610"></a><a name="p20783541132610"></a>};</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_row1813413245919"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p8783141102611"><a name="p8783141102611"></a><a name="p8783141102611"></a>handler</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p378364152617"><a name="p378364152617"></a><a name="p378364152617"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="p187831641182612"><a name="p187831641182612"></a><a name="p187831641182612"></a>dcmi_fault_event_callback</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="p16783641182611"><a name="p16783641182611"></a><a name="p16783641182611"></a>typedef void (*dcmi_fault_event_callback)(struct dcmi_event *event);</p>
<p id="p12783174113266"><a name="p12783174113266"></a><a name="p12783174113266"></a>The output event structure is defined as follows:</p>
<p id="p15783114122620"><a name="p15783114122620"></a><a name="p15783114122620"></a>struct dcmi_event {</p>
<p id="p478394112263"><a name="p478394112263"></a><a name="p478394112263"></a>enum dcmi_event_type type; // Event type</p>
<p id="p0783194115263"><a name="p0783194115263"></a><a name="p0783194115263"></a>union {</p>
<p id="p37836415262"><a name="p37836415262"></a><a name="p37836415262"></a>struct dcmi_dms_fault_event dms_event; // Event content</p>
<p id="p20783144119263"><a name="p20783144119263"></a><a name="p20783144119263"></a>} event_t;</p>
<p id="p19783134192614"><a name="p19783134192614"></a><a name="p19783134192614"></a>};</p>
<p id="p778334111264"><a name="p778334111264"></a><a name="p778334111264"></a><strong id="b3291837598759"><a name="b3291837598759"></a><a name="b3291837598759"></a>Type</strong>:</p>
<p id="p1778318416263"><a name="p1778318416263"></a><a name="p1778318416263"></a>Currently, the <strong id="b1869311081419"><a name="b1869311081419"></a><a name="b1869311081419"></a>DCMI_DMS_FAULT_EVENT</strong> type is supported. The enumeration definition is as follows:</p>
<p id="p137831641202617"><a name="p137831641202617"></a><a name="p137831641202617"></a>enum dcmi_event_type {</p>
<p id="p10783541132612"><a name="p10783541132612"></a><a name="p10783541132612"></a>DCMI_DMS_FAULT_EVENT = 0,</p>
<p id="p1783041102617"><a name="p1783041102617"></a><a name="p1783041102617"></a>DCMI_EVENT_TYPE_MAX</p>
<p id="p1278364152611"><a name="p1278364152611"></a><a name="p1278364152611"></a>};</p>
<p id="p1578354172618"><a name="p1578354172618"></a><a name="p1578354172618"></a><strong id="b15875160428759"><a name="b15875160428759"></a><a name="b15875160428759"></a>dms_event</strong>:</p>
<p id="p13784641192613"><a name="p13784641192613"></a><a name="p13784641192613"></a>The event content corresponding to the <strong id="b166511310101417"><a name="b166511310101417"></a><a name="b166511310101417"></a>DCMI_DMS_FAULT_EVENT</strong> type is defined as follows:</p>
<p id="p207841241192618"><a name="p207841241192618"></a><a name="p207841241192618"></a>#define DCMI_MAX_EVENT_NAME_LENGTH 256</p>
<p id="p157841141112617"><a name="p157841141112617"></a><a name="p157841141112617"></a>#define DCMI_MAX_EVENT_DATA_LENGTH 32</p>
<p id="p8784341132612"><a name="p8784341132612"></a><a name="p8784341132612"></a>#define DCMI_MAX_EVENT_RESV_LENGTH 32</p>
<p id="p978474113269"><a name="p978474113269"></a><a name="p978474113269"></a>struct dcmi_dms_fault_event {</p>
<p id="en-us_topic_0000001549080826_p97841641112619"><a name="en-us_topic_0000001549080826_p97841641112619"></a><a name="en-us_topic_0000001549080826_p97841641112619"></a>unsigned int event_id; // Event ID</p>
<p id="en-us_topic_0000001549080826_p778464122611"><a name="en-us_topic_0000001549080826_p778464122611"></a><a name="en-us_topic_0000001549080826_p778464122611"></a>unsigned short deviceid; // Device ID</p>
<p id="en-us_topic_0000001549080826_p117841641152615"><a name="en-us_topic_0000001549080826_p117841641152615"></a><a name="en-us_topic_0000001549080826_p117841641152615"></a>unsigned char node_type; // Node type</p>
<p id="en-us_topic_0000001549080826_p19784144119266"><a name="en-us_topic_0000001549080826_p19784144119266"></a><a name="en-us_topic_0000001549080826_p19784144119266"></a>unsigned char node_id;  // Node ID</p>
<p id="en-us_topic_0000001549080826_p14784104111269"><a name="en-us_topic_0000001549080826_p14784104111269"></a><a name="en-us_topic_0000001549080826_p14784104111269"></a>unsigned char sub_node_type; // Subnode type</p>
<p id="en-us_topic_0000001549080826_p1578444117262"><a name="en-us_topic_0000001549080826_p1578444117262"></a><a name="en-us_topic_0000001549080826_p1578444117262"></a>unsigned char sub_node_id; // Subnode ID</p>
<p id="en-us_topic_0000001549080826_p19784154182614"><a name="en-us_topic_0000001549080826_p19784154182614"></a><a name="en-us_topic_0000001549080826_p19784154182614"></a>unsigned char severity; // Event severity. <strong id="b1690492511148"><a name="b1690492511148"></a><a name="b1690492511148"></a>0</strong>: warning; <strong id="b15904925191413"><a name="b15904925191413"></a><a name="b15904925191413"></a>1</strong>: minor; <strong id="b7904152531420"><a name="b7904152531420"></a><a name="b7904152531420"></a>2</strong>: major; <strong id="b169056259149"><a name="b169056259149"></a><a name="b169056259149"></a>3</strong>: critical</p>
<p id="en-us_topic_0000001549080826_p978494122619"><a name="en-us_topic_0000001549080826_p978494122619"></a><a name="en-us_topic_0000001549080826_p978494122619"></a>unsigned char assertion; // Event type. <strong id="b133361758541"><a name="b133361758541"></a><a name="b133361758541"></a>0</strong>: fault recovery; <strong id="b11336258948"><a name="b11336258948"></a><a name="b11336258948"></a>1</strong>: fault generation; <strong id="b1633645810418"><a name="b1633645810418"></a><a name="b1633645810418"></a>2</strong>: one-off event</p>
<p id="en-us_topic_0000001549080826_p1278494113268"><a name="en-us_topic_0000001549080826_p1278494113268"></a><a name="en-us_topic_0000001549080826_p1278494113268"></a>int event_serial_num; // Alarm serial number</p>
<p id="en-us_topic_0000001549080826_p16784204172616"><a name="en-us_topic_0000001549080826_p16784204172616"></a><a name="en-us_topic_0000001549080826_p16784204172616"></a>int notify_serial_num; // Notification serial number</p>
<p id="en-us_topic_0000001549080826_p19784204132613"><a name="en-us_topic_0000001549080826_p19784204132613"></a><a name="en-us_topic_0000001549080826_p19784204132613"></a>unsigned long long alarm_raised_time; // Event creation time, which starts from 00:00:00 on January 1, 1970, in milliseconds</p>
<p id="en-us_topic_0000001549080826_p177841641122616"><a name="en-us_topic_0000001549080826_p177841641122616"></a><a name="en-us_topic_0000001549080826_p177841641122616"></a>char event_name[DCMI_MAX_EVENT_NAME_LENGTH]; // Event description</p>
<p id="en-us_topic_0000001549080826_p2078474112612"><a name="en-us_topic_0000001549080826_p2078474112612"></a><a name="en-us_topic_0000001549080826_p2078474112612"></a>char additional_info[DCMI_MAX_EVENT_DATA_LENGTH]; // Additional event information</p>
<p id="en-us_topic_0000001549080826_p47841641172620"><a name="en-us_topic_0000001549080826_p47841641172620"></a><a name="en-us_topic_0000001549080826_p47841641172620"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH]; // Reserved</p>
<p id="p157849419265"><a name="p157849419265"></a><a name="p157849419265"></a>};</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b146616679885620"><a name="b146616679885620"></a><a name="b146616679885620"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412082"></a>**

- When the values of  **card\_id**  and  **device\_id**  are both  **-1**, subscription of fault events on all devices in the current environment is supported.
- This API can be used to obtain the fault or recovery event that is being reported when a fault occurs, but cannot obtain historical events.
- This API supports a maximum of 64 processes instead of multiple threads. Those processes can be called at the same time. This API cannot be called together with the  **dcmi\_get\_fault\_event**  API in the same process.
- This API can only be called once in a process, and the PM and privileged container share 64 process resources. These resources will only be released when the process exits.
- For OS faults in SMP mode, you can only subscribe to the faults based on  **device\_id**  of the SMP head node.

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1548132517501"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p16154843125019"><a name="en-us_topic_0000002515503852_p16154843125019"></a><a name="en-us_topic_0000002515503852_p16154843125019"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p3123182915595"><a name="en-us_topic_0000002515503852_p3123182915595"></a><a name="en-us_topic_0000002515503852_p3123182915595"></a><strong id="en-us_topic_0000002515503852_b181336402033"><a name="en-us_topic_0000002515503852_b181336402033"></a><a name="en-us_topic_0000002515503852_b181336402033"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p6271950600"><a name="en-us_topic_0000002515503852_p6271950600"></a><a name="en-us_topic_0000002515503852_p6271950600"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b56571847339"><a name="en-us_topic_0000002515503852_b56571847339"></a><a name="en-us_topic_0000002515503852_b56571847339"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p41541743195013"><a name="en-us_topic_0000002515503852_p41541743195013"></a><a name="en-us_topic_0000002515503852_p41541743195013"></a><strong id="en-us_topic_0000002515503852_b6856448332"><a name="en-us_topic_0000002515503852_b6856448332"></a><a name="en-us_topic_0000002515503852_b6856448332"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19444162914516"><a name="en-us_topic_0000002515503852_p19444162914516"></a><a name="en-us_topic_0000002515503852_p19444162914516"></a><span id="en-us_topic_0000002515503852_ph1944412296514"><a name="en-us_topic_0000002515503852_ph1944412296514"></a><a name="en-us_topic_0000002515503852_ph1944412296514"></a><span id="en-us_topic_0000002515503852_text944432913516"><a name="en-us_topic_0000002515503852_text944432913516"></a><a name="en-us_topic_0000002515503852_text944432913516"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p194441629165117"><a name="en-us_topic_0000002515503852_p194441629165117"></a><a name="en-us_topic_0000002515503852_p194441629165117"></a><span id="en-us_topic_0000002515503852_text124449291511"><a name="en-us_topic_0000002515503852_text124449291511"></a><a name="en-us_topic_0000002515503852_text124449291511"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p461320458219"><a name="en-us_topic_0000002515503852_p461320458219"></a><a name="en-us_topic_0000002515503852_p461320458219"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13613134519220"><a name="en-us_topic_0000002515503852_p13613134519220"></a><a name="en-us_topic_0000002515503852_p13613134519220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96133454211"><a name="en-us_topic_0000002515503852_p96133454211"></a><a name="en-us_topic_0000002515503852_p96133454211"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row14873174604910"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10444329155118"><a name="en-us_topic_0000002515503852_p10444329155118"></a><a name="en-us_topic_0000002515503852_p10444329155118"></a><span id="en-us_topic_0000002515503852_text1044482925119"><a name="en-us_topic_0000002515503852_text1044482925119"></a><a name="en-us_topic_0000002515503852_text1044482925119"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p896391111511"><a name="en-us_topic_0000002515503852_p896391111511"></a><a name="en-us_topic_0000002515503852_p896391111511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p119682011105113"><a name="en-us_topic_0000002515503852_p119682011105113"></a><a name="en-us_topic_0000002515503852_p119682011105113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11975911195114"><a name="en-us_topic_0000002515503852_p11975911195114"></a><a name="en-us_topic_0000002515503852_p11975911195114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row23051923114915"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p174441129175117"><a name="en-us_topic_0000002515503852_p174441129175117"></a><a name="en-us_topic_0000002515503852_p174441129175117"></a><span id="en-us_topic_0000002515503852_text34441729175119"><a name="en-us_topic_0000002515503852_text34441729175119"></a><a name="en-us_topic_0000002515503852_text34441729175119"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1298231135114"><a name="en-us_topic_0000002515503852_p1298231135114"></a><a name="en-us_topic_0000002515503852_p1298231135114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1298921117511"><a name="en-us_topic_0000002515503852_p1298921117511"></a><a name="en-us_topic_0000002515503852_p1298921117511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1799561165114"><a name="en-us_topic_0000002515503852_p1799561165114"></a><a name="en-us_topic_0000002515503852_p1799561165114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row44814564912"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1044414295516"><a name="en-us_topic_0000002515503852_p1044414295516"></a><a name="en-us_topic_0000002515503852_p1044414295516"></a><span id="en-us_topic_0000002515503852_text44441829105114"><a name="en-us_topic_0000002515503852_text44441829105114"></a><a name="en-us_topic_0000002515503852_text44441829105114"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p17181285116"><a name="en-us_topic_0000002515503852_p17181285116"></a><a name="en-us_topic_0000002515503852_p17181285116"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15131255114"><a name="en-us_topic_0000002515503852_p15131255114"></a><a name="en-us_topic_0000002515503852_p15131255114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15917127513"><a name="en-us_topic_0000002515503852_p15917127513"></a><a name="en-us_topic_0000002515503852_p15917127513"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row11171321114917"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p94441829165113"><a name="en-us_topic_0000002515503852_p94441829165113"></a><a name="en-us_topic_0000002515503852_p94441829165113"></a><span id="en-us_topic_0000002515503852_text16445122985112"><a name="en-us_topic_0000002515503852_text16445122985112"></a><a name="en-us_topic_0000002515503852_text16445122985112"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p01211275113"><a name="en-us_topic_0000002515503852_p01211275113"></a><a name="en-us_topic_0000002515503852_p01211275113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p916161212512"><a name="en-us_topic_0000002515503852_p916161212512"></a><a name="en-us_topic_0000002515503852_p916161212512"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p191911211511"><a name="en-us_topic_0000002515503852_p191911211511"></a><a name="en-us_topic_0000002515503852_p191911211511"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18385115320492"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1644572918513"><a name="en-us_topic_0000002515503852_p1644572918513"></a><a name="en-us_topic_0000002515503852_p1644572918513"></a><span id="en-us_topic_0000002515503852_text1744532925112"><a name="en-us_topic_0000002515503852_text1744532925112"></a><a name="en-us_topic_0000002515503852_text1744532925112"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1923112115119"><a name="en-us_topic_0000002515503852_p1923112115119"></a><a name="en-us_topic_0000002515503852_p1923112115119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1269122515"><a name="en-us_topic_0000002515503852_p1269122515"></a><a name="en-us_topic_0000002515503852_p1269122515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p43014126516"><a name="en-us_topic_0000002515503852_p43014126516"></a><a name="en-us_topic_0000002515503852_p43014126516"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row557915117191"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2042757191916"><a name="en-us_topic_0000002515503852_p2042757191916"></a><a name="en-us_topic_0000002515503852_p2042757191916"></a><span id="en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412083"></a>**

```c
void event_handler(struct dcmi_event *event){
    // todo
}
struct dcmi_event_filter filter;
filter.filter_flag = DCMI_EVENT_FILTER_FLAG_SERVERITY | DCMI_EVENT_FILTER_FLAG_NODE_TYPE;
filter.severity = 1; /* Subscribes to only events of levels 2 and 3. */
filter.node_type = 112;
struct dcmi_event event = {0};
int dev_id, ret;
...
ret = dcmi_subscribe_fault_event(card_id_list[card_id], device_id, filter, event_handler);
if (ret != 0) {
} else {
}
```

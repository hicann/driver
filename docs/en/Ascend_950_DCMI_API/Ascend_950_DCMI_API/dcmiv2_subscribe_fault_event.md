# dcmiv2\_subscribe\_fault\_event<a name="EN-US_TOPIC_0000002314045126"></a>

## Prototype<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412077"></a>

**int dcmiv2\_subscribe\_fault\_event\(int dev\_id, struct dcmi\_event\_filter filter, dcmi\_fault\_event\_callback handler\)**

## Description<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412078"></a>

Subscribes to the device fault or recovery events.

## Parameter Description<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412079"></a>

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
<tbody><tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row15462171542913"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="p1378274110266"><a name="p1378274110266"></a><a name="p1378274110266"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="p107831541162615"><a name="p107831541162615"></a><a name="p107831541162615"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="p197831141162619"><a name="p197831141162619"></a><a name="p197831141162619"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
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
<p id="p147834411264"><a name="p147834411264"></a><a name="p147834411264"></a><strong id="b73949581113"><a name="b73949581113"></a><a name="b73949581113"></a>0</strong>: disables the filter criteria.</p>
<p id="p10783114114268"><a name="p10783114114268"></a><a name="p10783114114268"></a><strong id="b4861195917111"><a name="b4861195917111"></a><a name="b4861195917111"></a>DCMI_EVENT_FILTER_FLAG_EVENT_ID</strong>: receives only specified events.</p>
<p id="p27831841172610"><a name="p27831841172610"></a><a name="p27831841172610"></a><strong id="b13551715121"><a name="b13551715121"></a><a name="b13551715121"></a>DCMI_EVENT_FILTER_FLAG_SERVERITY</strong>: receives only the events of a specified level and higher levels.</p>
<p id="p1078314142613"><a name="p1078314142613"></a><a name="p1078314142613"></a><strong id="b1996614212120"><a name="b1996614212120"></a><a name="b1996614212120"></a>DCMI_EVENT_FILTER_FLAG_NODE_TYPE</strong>: receives only events of a specified node type.</p>
<p id="p478314142614"><a name="p478314142614"></a><a name="p478314142614"></a>unsigned int event_id; // Receives specified events. For details, see the <em id="i1265287534112757"><a name="i1265287534112757"></a><a name="i1265287534112757"></a>Health Management Error Definition</em>.</p>
<p id="p1078313417269"><a name="p1078313417269"></a><a name="p1078313417269"></a>unsigned char severity; // Receives events of a specified severity and higher. For details, see the severity definition in the <strong id="b632471188112758"><a name="b632471188112758"></a><a name="b632471188112758"></a>struct dcmi_dms_fault_event</strong>.</p>
<p id="p12783174114261"><a name="p12783174114261"></a><a name="p12783174114261"></a>unsigned char node_type; // Receives events of a specified node type. For details, see the <em id="i08110012210"><a name="i08110012210"></a><a name="i08110012210"></a>Health Management Error Definition</em>.</p>
<p id="p6783184122615"><a name="p6783184122615"></a><a name="p6783184122615"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH];  // Reserved</p>
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
<p id="p97841641112619"><a name="p97841641112619"></a><a name="p97841641112619"></a>unsigned int event_id; // Event ID</p>
<p id="p778464122611"><a name="p778464122611"></a><a name="p778464122611"></a>unsigned short deviceid; // Device ID</p>
<p id="p117841641152615"><a name="p117841641152615"></a><a name="p117841641152615"></a>unsigned char node_type; // Node type</p>
<p id="p19784144119266"><a name="p19784144119266"></a><a name="p19784144119266"></a>unsigned char node_id; // Node ID</p>
<p id="p14784104111269"><a name="p14784104111269"></a><a name="p14784104111269"></a>unsigned char sub_node_type; // Subnode type</p>
<p id="p1578444117262"><a name="p1578444117262"></a><a name="p1578444117262"></a>unsigned char sub_node_id; // Subnode ID</p>
<p id="p19784154182614"><a name="p19784154182614"></a><a name="p19784154182614"></a>unsigned char severity; // Event severity. <strong id="b9398101491218"><a name="b9398101491218"></a><a name="b9398101491218"></a>0</strong>: warning; <strong id="b23981714181214"><a name="b23981714181214"></a><a name="b23981714181214"></a>1</strong>: minor; <strong id="b1139818146120"><a name="b1139818146120"></a><a name="b1139818146120"></a>2</strong>: major; <strong id="b2398141471210"><a name="b2398141471210"></a><a name="b2398141471210"></a>3</strong>: critical</p>
<p id="p978494122619"><a name="p978494122619"></a><a name="p978494122619"></a>unsigned char assertion; // Event type. <strong id="b1649013143221"><a name="b1649013143221"></a><a name="b1649013143221"></a>0</strong>: fault recovery; <strong id="b19490201414223"><a name="b19490201414223"></a><a name="b19490201414223"></a>1</strong>: fault generation; <strong id="b114901914182211"><a name="b114901914182211"></a><a name="b114901914182211"></a>2</strong>: one-off event</p>
<p id="p1278494113268"><a name="p1278494113268"></a><a name="p1278494113268"></a>int event_serial_num; // Alarm serial number</p>
<p id="p16784204172616"><a name="p16784204172616"></a><a name="p16784204172616"></a>int notify_serial_num; // Notification sequence number</p>
<p id="p19784204132613"><a name="p19784204132613"></a><a name="p19784204132613"></a>unsigned long long alarm_raised_time; // Event creation time: the period starts from 00:00:00 on January 1, 1970, in milliseconds.</p>
<p id="p177841641122616"><a name="p177841641122616"></a><a name="p177841641122616"></a>char event_name[DCMI_MAX_EVENT_NAME_LENGTH]; // Event description</p>
<p id="p2078474112612"><a name="p2078474112612"></a><a name="p2078474112612"></a>char additional_info[DCMI_MAX_EVENT_DATA_LENGTH]; // Additional event information</p>
<p id="p13286163563717"><a name="p13286163563717"></a><a name="p13286163563717"></a>unsigned char os_id;</p>
<p id="p12286193563714"><a name="p12286193563714"></a><a name="p12286193563714"></a>unsigned char resv_1[1];</p>
<p id="p11286935173711"><a name="p11286935173711"></a><a name="p11286935173711"></a>unsigned short node_type_ex;</p>
<p id="p1528653510376"><a name="p1528653510376"></a><a name="p1528653510376"></a>unsigned short sub_node_type_ex;</p>
<p id="p8286123512373"><a name="p8286123512373"></a><a name="p8286123512373"></a>unsigned char resv_2[2];</p>
<p id="p47841641172620"><a name="p47841641172620"></a><a name="p47841641172620"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH - 8]; // Reserved</p>
<p id="p157849419265"><a name="p157849419265"></a><a name="p157849419265"></a>};</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412082"></a>

- When the value of  **dev\_id**  is  **-1**, subscription of fault events on all devices in the current environment is supported.
- This API can be used to obtain the fault or recovery event that is being reported when a fault occurs, but cannot obtain historical events.
- This API supports a maximum of 64 processes instead of multiple threads. Those processes can be called at the same time. This API cannot be called together with  [dcmiv2\_get\_fault\_event](dcmiv2_get_fault_event.md)  in the same process.
- This API can only be called once in a process, and the PM and privileged container share 64 process resources. These resources will only be released when the process exits.
- For OS faults in SMP mode, you can only subscribe to the faults based on  **dev\_id**  of the SMP head node.

**Table  1** Support in different deployment scenarios

<a name="table116394134134"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p65514914017"><a name="en-us_topic_0000002347924121_p65514914017"></a><a name="en-us_topic_0000002347924121_p65514914017"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p56108061"><a name="en-us_topic_0000002347924121_p56108061"></a><a name="en-us_topic_0000002347924121_p56108061"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1855189908"><a name="en-us_topic_0000002347924121_p1855189908"></a><a name="en-us_topic_0000002347924121_p1855189908"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10771327123917"><a name="en-us_topic_0000002347924121_p10771327123917"></a><a name="en-us_topic_0000002347924121_p10771327123917"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><strong id="en-us_topic_0000002347924121_b5395653155415"><a name="en-us_topic_0000002347924121_b5395653155415"></a><a name="en-us_topic_0000002347924121_b5395653155415"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b16340205411546"><a name="en-us_topic_0000002347924121_b16340205411546"></a><a name="en-us_topic_0000002347924121_b16340205411546"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p56110815619"><a name="en-us_topic_0000002347924121_p56110815619"></a><a name="en-us_topic_0000002347924121_p56110815619"></a><strong id="en-us_topic_0000002347924121_b1325919551546"><a name="en-us_topic_0000002347924121_b1325919551546"></a><a name="en-us_topic_0000002347924121_b1325919551546"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><strong id="en-us_topic_0000002347924121_b7873135516543"><a name="en-us_topic_0000002347924121_b7873135516543"></a><a name="en-us_topic_0000002347924121_b7873135516543"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p977116273398"><a name="en-us_topic_0000002347924121_p977116273398"></a><a name="en-us_topic_0000002347924121_p977116273398"></a><strong id="en-us_topic_0000002347924121_b868415562549"><a name="en-us_topic_0000002347924121_b868415562549"></a><a name="en-us_topic_0000002347924121_b868415562549"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p144147361596"><a name="en-us_topic_0000002347924121_p144147361596"></a><a name="en-us_topic_0000002347924121_p144147361596"></a><span id="en-us_topic_0000002347924121_ph12140626193614"><a name="en-us_topic_0000002347924121_ph12140626193614"></a><a name="en-us_topic_0000002347924121_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13356146465"><a name="en-us_topic_0000002347924121_p13356146465"></a><a name="en-us_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p19351314124620"><a name="en-us_topic_0000002347924121_p19351314124620"></a><a name="en-us_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p1577514751713"><a name="en-us_topic_0000002347924121_p1577514751713"></a><a name="en-us_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1435121434611"><a name="en-us_topic_0000002347924121_p1435121434611"></a><a name="en-us_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p8318151920427"><a name="en-us_topic_0000002347924121_p8318151920427"></a><a name="en-us_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p56258171305"><a name="en-us_topic_0000002347924121_p56258171305"></a><a name="en-us_topic_0000002347924121_p56258171305"></a><span id="en-us_topic_0000002347924121_ph15391145912019"><a name="en-us_topic_0000002347924121_ph15391145912019"></a><a name="en-us_topic_0000002347924121_ph15391145912019"></a>Note: <strong id="en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412083"></a>

```c
void event_handler(struct dcmi_event *event){
    // TODO
}
struct dcmi_event_filter filter;
filter.filter_flag = DCMI_EVENT_FILTER_FLAG_SERVERITY | DCMI_EVENT_FILTER_FLAG_NODE_TYPE;
filter.severity = 1; 
filter.node_type = 112;
struct dcmi_event event = {0};
int dev_id, ret;
...
ret = dcmiv2_subscribe_fault_event(dev_id, filter, event_handler);
if (ret != 0) {
} else {
}
```

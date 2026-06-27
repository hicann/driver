# dcmi\_get\_fault\_event<a name="EN-US_TOPIC_0000002546983749"></a>

**Prototype<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412077"></a>**

**int dcmi\_get\_fault\_event\(int card\_id, int device\_id, int timeout, struct dcmi\_event\_filter filter, struct dcmi\_event \*event\)**

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
<tbody><tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row10560021192510"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p36741947142813"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p36741947142813"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p96741747122818"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p96741747122818"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p46747472287"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p46747472287"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1467413474281"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1467413474281"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <a href="dcmi_get_card_num_list.md">dcmi_get_card_num_list</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row15462171542913"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p445315176517"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p445315176517"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p445315176517"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1926232982914"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1926232982914"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p1926232982914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p826217292293"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p826217292293"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_p826217292293"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b2116946924102455"><a name="b2116946924102455"></a><a name="b2116946924102455"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b763378640105342"><a name="b763378640105342"></a><a name="b763378640105342"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_row029010598584"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1845492116012"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1845492116012"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1845492116012"></a>timeout</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p54545211409"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p54545211409"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p54545211409"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p17454182115010"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p17454182115010"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p17454182115010"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13454821402"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13454821402"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13454821402"></a>If the value is greater than or equal to <strong id="b141711326467"><a name="b141711326467"></a><a name="b141711326467"></a>0</strong>, the block duration times out (the maximum value is 30,000 ms). If it is equal to <strong id="b171843212461"><a name="b171843212461"></a><a name="b171843212461"></a>–1</strong>, the block duration never times out.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_row1813413245919"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3223737605"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3223737605"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3223737605"></a>filter</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p132231637306"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p132231637306"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p132231637306"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p92231037703"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p92231037703"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p92231037703"></a>struct dcmi_event_filter</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p677479218"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p677479218"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p677479218"></a>You can subscribe to only the events that meet the following filter criteria. </p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p67749916113"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p67749916113"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p67749916113"></a>#define DCMI_EVENT_FILTER_FLAG_EVENT_ID (1UL &lt;&lt; 0)</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p577419916110"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p577419916110"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p577419916110"></a>#define DCMI_EVENT_FILTER_FLAG_SERVERITY (1UL &lt;&lt; 1)</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774198112"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774198112"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774198112"></a>#define DCMI_EVENT_FILTER_FLAG_NODE_TYPE (1UL &lt;&lt; 2)</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p877419912118"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p877419912118"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p877419912118"></a>#define DCMI_MAX_EVENT_RESV_LENGTH 32</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p107744919118"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p107744919118"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p107744919118"></a>struct dcmi_event_filter {</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p11774692116"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p11774692116"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p11774692116"></a>unsigned long long filter_flag; // It can be used to enable one or all filter criteria. The filter criteria are as follows:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774497114"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774497114"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15774497114"></a><strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b208413279413"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b208413279413"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b208413279413"></a>0</strong>: disables the filter criteria.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p207741891614"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p207741891614"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p207741891614"></a><strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b994183614114"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b994183614114"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b994183614114"></a>DCMI_EVENT_FILTER_FLAG_EVENT_ID</strong>: receives only specified events.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741392011"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741392011"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741392011"></a><strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b3246140121218"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b3246140121218"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b3246140121218"></a>DCMI_EVENT_FILTER_FLAG_SERVERITY</strong>: receives only the events of a specified level and higher levels.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p6774169517"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p6774169517"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p6774169517"></a><strong id="b9907311194517"><a name="b9907311194517"></a><a name="b9907311194517"></a>DCMI_EVENT_FILTER_FLAG_NODE_TYPE</strong>: receives only events of a specified node type.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741596114"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741596114"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p127741596114"></a>unsigned int event_id;  // Receives specified events.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p077479911"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p077479911"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p077479911"></a>unsigned char severity; // Receives events that are at and above a specified level. For details, see the severity definition in the <strong id="b179302754513"><a name="b179302754513"></a><a name="b179302754513"></a>struct dcmi_dms_fault_event</strong>.</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13774591615"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13774591615"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p13774591615"></a>unsigned char node_type;  // Receives events of a specified node type.</p>
<p id="p154231949105413"><a name="p154231949105413"></a><a name="p154231949105413"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH]; // Reserved</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1276152117115"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1276152117115"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1276152117115"></a>};</p>
</td>
</tr>
<tr id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_row122061951597"><td class="cellrowborder" valign="top" width="15.72%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984413468115"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984413468115"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984413468115"></a>event</p>
</td>
<td class="cellrowborder" valign="top" width="13.850000000000001%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984415461712"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984415461712"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p984415461712"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.05%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p584444618112"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p584444618112"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p584444618112"></a>struct dcmi_event *</p>
</td>
<td class="cellrowborder" valign="top" width="54.379999999999995%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294095716117"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294095716117"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294095716117"></a>The output event structure is defined as follows:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694014571715"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694014571715"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694014571715"></a>struct dcmi_event {</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1994013571112"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1994013571112"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1994013571112"></a>enum dcmi_event_type type; // Event type</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1494018571111"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1494018571111"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1494018571111"></a>union {</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p199401657312"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p199401657312"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p199401657312"></a>struct dcmi_dms_fault_event dms_event; // Event content</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1194017571918"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1194017571918"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1194017571918"></a>} event_t;</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p494017571618"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p494017571618"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p494017571618"></a>};</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p29403577112"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p29403577112"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p29403577112"></a><strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b11371155117555"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b11371155117555"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b11371155117555"></a>Type</strong>:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p129401157216"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p129401157216"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p129401157216"></a>Currently, the <strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b165841135105217"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b165841135105217"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b165841135105217"></a>DCMI_DMS_FAULT_EVENT</strong> type is supported. The enumeration definition is as follows:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p99401957313"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p99401957313"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p99401957313"></a>enum dcmi_event_type {</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p12940857414"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p12940857414"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p12940857414"></a>DCMI_DMS_FAULT_EVENT = 0,</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p159407571517"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p159407571517"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p159407571517"></a>DCMI_EVENT_TYPE_MAX</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p09408571311"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p09408571311"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p09408571311"></a>};</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p119402571215"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p119402571215"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p119402571215"></a><strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b188631442205513"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b188631442205513"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b188631442205513"></a>dms_event</strong>:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p79405571618"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p79405571618"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p79405571618"></a>The event content corresponding to the <strong id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b0577172318557"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b0577172318557"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_b0577172318557"></a>DCMI_DMS_FAULT_EVENT</strong> type is defined as follows:</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940457614"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940457614"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940457614"></a>#define DCMI_MAX_EVENT_NAME_LENGTH 256</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p7940165716118"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p7940165716118"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p7940165716118"></a>#define DCMI_MAX_EVENT_DATA_LENGTH 32</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940115720118"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940115720118"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p8940115720118"></a>#define DCMI_MAX_EVENT_RESV_LENGTH 32</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15940057419"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15940057419"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p15940057419"></a>struct dcmi_dms_fault_event {</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294035720115"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294035720115"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1294035720115"></a>unsigned int event_id; // Event ID</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1094010574111"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1094010574111"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1094010574111"></a>unsigned short deviceid; // Device ID</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p59408579120"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p59408579120"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p59408579120"></a>unsigned char node_type; // Node type</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p794015710110"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p794015710110"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p794015710110"></a>unsigned char node_id; // Node ID</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694011575118"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694011575118"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p694011575118"></a>unsigned char sub_node_type; // Subnode type</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1694017579119"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1694017579119"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1694017579119"></a>unsigned char sub_node_id; // Subnode ID</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1794014571416"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1794014571416"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1794014571416"></a>unsigned char severity; // Event severity. <strong id="b121318276469"><a name="b121318276469"></a><a name="b121318276469"></a>0</strong>: warning; <strong id="b1321312724616"><a name="b1321312724616"></a><a name="b1321312724616"></a>1</strong>: minor; <strong id="b021319279465"><a name="b021319279465"></a><a name="b021319279465"></a>2</strong>: major; <strong id="b122131927174611"><a name="b122131927174611"></a><a name="b122131927174611"></a>3</strong>: critical</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p10940857219"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p10940857219"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p10940857219"></a>unsigned char assertion; // Event type. <strong id="b118679433412"><a name="b118679433412"></a><a name="b118679433412"></a>0</strong>: fault recovery; <strong id="b686719433413"><a name="b686719433413"></a><a name="b686719433413"></a>1</strong>: fault generation; <strong id="b14867343541"><a name="b14867343541"></a><a name="b14867343541"></a>2</strong>: one-off event</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p2094019571318"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p2094019571318"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p2094019571318"></a>int event_serial_num; // Alarm serial number</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3940957718"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3940957718"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p3940957718"></a>int notify_serial_num; // Notification serial number</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p69407571318"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p69407571318"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p69407571318"></a>unsigned long long alarm_raised_time; // Event generation time, which starts from 00:00:00 on January 1, 1970, in milliseconds</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1594010574111"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1594010574111"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1594010574111"></a>char event_name[DCMI_MAX_EVENT_NAME_LENGTH]; // Event description</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p18940145715116"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p18940145715116"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p18940145715116"></a>char additional_info[DCMI_MAX_EVENT_DATA_LENGTH]; // Additional event information</p>
<p id="p1783110233554"><a name="p1783110233554"></a><a name="p1783110233554"></a>unsigned char resv[DCMI_MAX_EVENT_RESV_LENGTH]; // Reserved</p>
<p id="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p294010573116"><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p294010573116"></a><a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_p294010573116"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b81994622685611"><a name="b81994622685611"></a><a name="b81994622685611"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_toc533412082"></a>**

- This API can be used to obtain the fault or recovery event that is being reported when a fault occurs, but cannot obtain historical events.
- This API supports a maximum of 64 processes instead of multiple threads. Those processes can be called at the same time.

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
... 
int ret = 0; 
int card_id = 0; 
int device_id = 0;
int timeout = 1000;
struct dcmi_event_filter filter = {0};
struct dcmi_event event = {0};
filter.filter_flag = DCMI_EVENT_FILTER_FLAG_SERVERITY | DCMI_EVENT_FILTER_FLAG_NODE_TYPE; 
filter.severity = 2; /* Subscribes to only events of levels 2 and 3. */
filter.node_type = 0x40; /* Subscribes to only SoC events. */
ret = dcmi_get_fault_event(card_id, device_id, timeout, filter, &event); 
if (ret != DCMI_OK) {
    printf("dcmi_get_fault_event failed. err is %d\n", ret);
}
// todo
...
```

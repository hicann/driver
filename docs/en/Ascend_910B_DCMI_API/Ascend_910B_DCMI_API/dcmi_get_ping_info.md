# dcmi\_get\_ping\_info<a name="EN-US_TOPIC_0000002515343928"></a>

**Prototype<a name="section1950145543919"></a>**

**int dcmi\_get\_ping\_info \(int card\_id, int device\_id, int port\_id, struct dcmi\_ping\_operate\_info \*dcmi\_ping, struct dcmi\_ping\_reply\_info \*dcmi\_reply\)**

**Description<a name="section651195511395"></a>**

Obtains the connectivity information of a link from a specified device to the destination address.

**Parameter Description<a name="section2521655113914"></a>**

<a name="table410945503914"></a>
<table><thead align="left"><tr id="en-us_topic_0000002338976566_row822915516396"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002338976566_p14230355203914"><a name="en-us_topic_0000002338976566_p14230355203914"></a><a name="en-us_topic_0000002338976566_p14230355203914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002338976566_p1223075553912"><a name="en-us_topic_0000002338976566_p1223075553912"></a><a name="en-us_topic_0000002338976566_p1223075553912"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002338976566_p72301355133916"><a name="en-us_topic_0000002338976566_p72301355133916"></a><a name="en-us_topic_0000002338976566_p72301355133916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002338976566_p723055516397"><a name="en-us_topic_0000002338976566_p723055516397"></a><a name="en-us_topic_0000002338976566_p723055516397"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002338976566_row102301855133919"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976566_p16230185510391"><a name="en-us_topic_0000002338976566_p16230185510391"></a><a name="en-us_topic_0000002338976566_p16230185510391"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976566_p1723045513391"><a name="en-us_topic_0000002338976566_p1723045513391"></a><a name="en-us_topic_0000002338976566_p1723045513391"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976566_p1230185573915"><a name="en-us_topic_0000002338976566_p1230185573915"></a><a name="en-us_topic_0000002338976566_p1230185573915"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976566_p192301855143912"><a name="en-us_topic_0000002338976566_p192301855143912"></a><a name="en-us_topic_0000002338976566_p192301855143912"></a>Device ID. The supported IDs can be obtained by calling <strong id="b2108253215102844"><a name="b2108253215102844"></a><a name="b2108253215102844"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976566_row15230175510398"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976566_p523017556393"><a name="en-us_topic_0000002338976566_p523017556393"></a><a name="en-us_topic_0000002338976566_p523017556393"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976566_p19230125518397"><a name="en-us_topic_0000002338976566_p19230125518397"></a><a name="en-us_topic_0000002338976566_p19230125518397"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976566_p0230205553916"><a name="en-us_topic_0000002338976566_p0230205553916"></a><a name="en-us_topic_0000002338976566_p0230205553916"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976566_p1423015555395"><a name="en-us_topic_0000002338976566_p1423015555395"></a><a name="en-us_topic_0000002338976566_p1423015555395"></a>Chip ID, which can be obtained by calling <strong id="b794190377102513"><a name="b794190377102513"></a><a name="b794190377102513"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002338976566_p11230125511398"><a name="en-us_topic_0000002338976566_p11230125511398"></a><a name="en-us_topic_0000002338976566_p11230125511398"></a>NPU chip: [0, <strong id="b1025235079111946"><a name="b1025235079111946"></a><a name="b1025235079111946"></a>device_id_max</strong> - 1]</p>
<p id="en-us_topic_0000002338976566_p723015512391"><a name="en-us_topic_0000002338976566_p723015512391"></a><a name="en-us_topic_0000002338976566_p723015512391"></a>MCU chip: <strong id="b531172043015"><a name="b531172043015"></a><a name="b531172043015"></a>mcu_id</strong></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002338976566_row22309557394"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976566_p02301655203910"><a name="en-us_topic_0000002338976566_p02301655203910"></a><a name="en-us_topic_0000002338976566_p02301655203910"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976566_p22301655193914"><a name="en-us_topic_0000002338976566_p22301655193914"></a><a name="en-us_topic_0000002338976566_p22301655193914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976566_p12301455113918"><a name="en-us_topic_0000002338976566_p12301455113918"></a><a name="en-us_topic_0000002338976566_p12301455113918"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976566_p82316551391"><a name="en-us_topic_0000002338976566_p82316551391"></a><a name="en-us_topic_0000002338976566_p82316551391"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b16516231153011"><a name="b16516231153011"></a><a name="b16516231153011"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976566_row1223110556396"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976566_p15231155163916"><a name="en-us_topic_0000002338976566_p15231155163916"></a><a name="en-us_topic_0000002338976566_p15231155163916"></a>dcmi_ping</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976566_p823111559399"><a name="en-us_topic_0000002338976566_p823111559399"></a><a name="en-us_topic_0000002338976566_p823111559399"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976566_p15231105512392"><a name="en-us_topic_0000002338976566_p15231105512392"></a><a name="en-us_topic_0000002338976566_p15231105512392"></a>struct dcmi_ping_operate_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976566_p12313554399"><a name="en-us_topic_0000002338976566_p12313554399"></a><a name="en-us_topic_0000002338976566_p12313554399"></a>Ping operation information.</p>
<p id="en-us_topic_0000002338976566_p132311755153910"><a name="en-us_topic_0000002338976566_p132311755153910"></a><a name="en-us_topic_0000002338976566_p132311755153910"></a>struct dcmi_ping_operate_info {</p>
<p id="en-us_topic_0000002338976566_p182311355123911"><a name="en-us_topic_0000002338976566_p182311355123911"></a><a name="en-us_topic_0000002338976566_p182311355123911"></a>char dst_addr[IP_ADDR_LEN];// Destination IPv4 address of the device to be pinged. The value of <strong id="b207391339103018"><a name="b207391339103018"></a><a name="b207391339103018"></a>IP_ADDR_LEN</strong> is <strong id="b1473910396300"><a name="b1473910396300"></a><a name="b1473910396300"></a>16</strong>.</p>
<p id="en-us_topic_0000002338976566_p1123112551393"><a name="en-us_topic_0000002338976566_p1123112551393"></a><a name="en-us_topic_0000002338976566_p1123112551393"></a>unsigned int sdid;// SDID of the device to be pinged. Either <strong id="b054165312305"><a name="b054165312305"></a><a name="b054165312305"></a>sdid</strong> or <strong id="b854285313017"><a name="b854285313017"></a><a name="b854285313017"></a>dst_addr</strong> is used to configure the destination address. If both of them are configured, <strong id="b9223556123016"><a name="b9223556123016"></a><a name="b9223556123016"></a>dst_addr</strong> is used.</p>
<p id="en-us_topic_0000002338976566_p18231655203917"><a name="en-us_topic_0000002338976566_p18231655203917"></a><a name="en-us_topic_0000002338976566_p18231655203917"></a>unsigned int packet_size;// Size of a ping packet. The value range is 1792 to 3000 bytes. The packet header size is 1024 bytes. The correctness of the subsequent 1025 bytes to the <strong id="b718715383119"><a name="b718715383119"></a><a name="b718715383119"></a>packet_size</strong> field is verified. The field type distribution of every 1024 bytes is as follows: 0xFF (256 bytes), 0x00 (256 bytes), 0xAA (256 bytes), and 0x55 (256 bytes).</p>
<p id="en-us_topic_0000002338976566_p923114557399"><a name="en-us_topic_0000002338976566_p923114557399"></a><a name="en-us_topic_0000002338976566_p923114557399"></a>unsigned int packet_send_num; // Number of ping packets. The value ranges from 1 to 1000.</p>
<p id="en-us_topic_0000002338976566_p1223185553919"><a name="en-us_topic_0000002338976566_p1223185553919"></a><a name="en-us_topic_0000002338976566_p1223185553919"></a>unsigned int packet_interval;// Delay interval for sending ping packets. The value ranges from 0 to 10 ms. The value <strong id="b118404154312"><a name="b118404154312"></a><a name="b118404154312"></a>0</strong> indicates that a packet is sent immediately after a response is received.</p>
<p id="en-us_topic_0000002338976566_p72311556394"><a name="en-us_topic_0000002338976566_p72311556394"></a><a name="en-us_topic_0000002338976566_p72311556394"></a>unsigned int timeout;// Timeout wait time of each ping packet. The value ranges from 1 to 20000 ms. The configuration item does not take effect.</p>
<p id="en-us_topic_0000002338976566_p19231455173915"><a name="en-us_topic_0000002338976566_p19231455173915"></a><a name="en-us_topic_0000002338976566_p19231455173915"></a>unsigned char reserved[32];// Reserved field, which is not used currently.</p>
<p id="en-us_topic_0000002338976566_p5231255153917"><a name="en-us_topic_0000002338976566_p5231255153917"></a><a name="en-us_topic_0000002338976566_p5231255153917"></a>};</p>
<p id="en-us_topic_0000002338976566_p143091626124318"><a name="en-us_topic_0000002338976566_p143091626124318"></a><a name="en-us_topic_0000002338976566_p143091626124318"></a>Note:</p>
<p id="en-us_topic_0000002338976566_p167933314147"><a name="en-us_topic_0000002338976566_p167933314147"></a><a name="en-us_topic_0000002338976566_p167933314147"></a>In versions earlier than 25.0.RC1, the restrictions on using the preceding parameters are as follows:</p>
<p id="en-us_topic_0000002338976566_p1126692311438"><a name="en-us_topic_0000002338976566_p1126692311438"></a><a name="en-us_topic_0000002338976566_p1126692311438"></a>packet_send_num* (packet_interval+timeout)&lt;=20000ms</p>
</td>
</tr>
<tr id="en-us_topic_0000002338976566_row823111553398"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338976566_p1523195523910"><a name="en-us_topic_0000002338976566_p1523195523910"></a><a name="en-us_topic_0000002338976566_p1523195523910"></a>dcmi_reply</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338976566_p11231455143911"><a name="en-us_topic_0000002338976566_p11231455143911"></a><a name="en-us_topic_0000002338976566_p11231455143911"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338976566_p623125510397"><a name="en-us_topic_0000002338976566_p623125510397"></a><a name="en-us_topic_0000002338976566_p623125510397"></a>struct dcmi_ping_reply_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338976566_p72325553399"><a name="en-us_topic_0000002338976566_p72325553399"></a><a name="en-us_topic_0000002338976566_p72325553399"></a>Ping result information.</p>
<p id="en-us_topic_0000002338976566_p17232115533920"><a name="en-us_topic_0000002338976566_p17232115533920"></a><a name="en-us_topic_0000002338976566_p17232115533920"></a>struct dcmi_ping_reply_info {</p>
<p id="en-us_topic_0000002338976566_p20232175573916"><a name="en-us_topic_0000002338976566_p20232175573916"></a><a name="en-us_topic_0000002338976566_p20232175573916"></a>char dst_addr[IP_ADDR_LEN];// Destination IPv4 address of the device to be pinged.</p>
<p id="en-us_topic_0000002338976566_p42321755193919"><a name="en-us_topic_0000002338976566_p42321755193919"></a><a name="en-us_topic_0000002338976566_p42321755193919"></a>enum dcmi_ping_result ret[DCMI_PING_PACKET_NUM_MAX];// Ping result of each data packet. The enumerated values of <strong id="b11810418311"><a name="b11810418311"></a><a name="b11810418311"></a>dcmi_ping_result</strong> include <strong id="b8181144123111"><a name="b8181144123111"></a><a name="b8181144123111"></a>0</strong> (ping operation not initiated), <strong id="b18181164119316"><a name="b18181164119316"></a><a name="b18181164119316"></a>1</strong> (ping packet successfully sent and received), <strong id="b20181174118317"><a name="b20181174118317"></a><a name="b20181174118317"></a>2</strong> (packet sending failure), and <strong id="b191813416317"><a name="b191813416317"></a><a name="b191813416317"></a>3</strong> (packet reception failure). The value of <strong id="b61731747143114"><a name="b61731747143114"></a><a name="b61731747143114"></a>DCMI_PING_PACKET_NUM_MAX</strong> is <strong id="b12173194713113"><a name="b12173194713113"></a><a name="b12173194713113"></a>1000</strong>.</p>
<p id="en-us_topic_0000002338976566_p192321955123919"><a name="en-us_topic_0000002338976566_p192321955123919"></a><a name="en-us_topic_0000002338976566_p192321955123919"></a>unsigned int total_packet_send_num;// Send count</p>
<p id="en-us_topic_0000002338976566_p223220555392"><a name="en-us_topic_0000002338976566_p223220555392"></a><a name="en-us_topic_0000002338976566_p223220555392"></a>unsigned int total_packet_recv_num;// Receive count</p>
<p id="en-us_topic_0000002338976566_p023215550392"><a name="en-us_topic_0000002338976566_p023215550392"></a><a name="en-us_topic_0000002338976566_p023215550392"></a>long start_tv_sec[DCMI_PING_PACKET_NUM_MAX];// Start time of the ping operation for each packet (unit: s)</p>
<p id="en-us_topic_0000002338976566_p122321055153912"><a name="en-us_topic_0000002338976566_p122321055153912"></a><a name="en-us_topic_0000002338976566_p122321055153912"></a>long start_tv_usec[DCMI_PING_PACKET_NUM_MAX];// Start time of the ping operation for each packet (unit: μs) The time is calculated based on the values in the unit of s and μs.</p>
<p id="en-us_topic_0000002338976566_p8232655153920"><a name="en-us_topic_0000002338976566_p8232655153920"></a><a name="en-us_topic_0000002338976566_p8232655153920"></a>long end_tv_sec[DCMI_PING_PACKET_NUM_MAX];// End time of the ping operation for each packet (unit: s)</p>
<p id="en-us_topic_0000002338976566_p02325553390"><a name="en-us_topic_0000002338976566_p02325553390"></a><a name="en-us_topic_0000002338976566_p02325553390"></a>long end_tv_usec[DCMI_PING_PACKET_NUM_MAX];// End time of the ping operation for each packet (unit: μs) The time is calculated based on the values in the unit of s and μs.</p>
<p id="en-us_topic_0000002338976566_p18232155514391"><a name="en-us_topic_0000002338976566_p18232155514391"></a><a name="en-us_topic_0000002338976566_p18232155514391"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b175904691285631"><a name="b175904691285631"></a><a name="b175904691285631"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None.

**Restrictions<a name="section1100155515399"></a>**

**Table  1** Support in different deployment scenarios

<a name="table18534941103615"></a>
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

**Example<a name="section51051555133912"></a>**

```c
...
int ret;
int card_id = 0;
int device_id = 0;
int port_id = 0;
struct dcmi_ping_operate_info ping_operate_info = {0};
struct dcmi_ping_reply_info ping_reply_info = {0};
ping_operate_info.sdid = 262146;
ping_operate_info.packet_size = 1792;
ping_operate_info.packet_send_num = 1000;
ping_operate_info.packet_interval = 0;
ping_operate_info.timeout = 20;
ret = dcmi_get_ping_info(card_id, device_id, port_id, &ping_operate_info, &ping_reply_info);
...
```

# dcmi\_get\_ping\_info<a name="EN-US_TOPIC_0000002515350544"></a>

**Prototype<a name="section1950145543919"></a>**

**int dcmi\_get\_ping\_info \(int card\_id, int device\_id, int port\_id, struct dcmi\_ping\_operate\_info \*dcmi\_ping, struct dcmi\_ping\_reply\_info \*dcmi\_reply\)**

**Description<a name="section651195511395"></a>**

Obtains the connectivity information of a link from a specified device to the destination address.

**Parameter Description<a name="section2521655113914"></a>**

<a name="table410945503914"></a>
<table><thead align="left"><tr id="row822915516396"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p14230355203914"><a name="p14230355203914"></a><a name="p14230355203914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p1223075553912"><a name="p1223075553912"></a><a name="p1223075553912"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p72301355133916"><a name="p72301355133916"></a><a name="p72301355133916"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p723055516397"><a name="p723055516397"></a><a name="p723055516397"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row102301855133919"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p16230185510391"><a name="p16230185510391"></a><a name="p16230185510391"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1723045513391"><a name="p1723045513391"></a><a name="p1723045513391"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1230185573915"><a name="p1230185573915"></a><a name="p1230185573915"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p192301855143912"><a name="p192301855143912"></a><a name="p192301855143912"></a>Device ID. The supported IDs can be obtained by calling <strong id="b155037041181341"><a name="b155037041181341"></a><a name="b155037041181341"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row15230175510398"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p523017556393"><a name="p523017556393"></a><a name="p523017556393"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p19230125518397"><a name="p19230125518397"></a><a name="p19230125518397"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p0230205553916"><a name="p0230205553916"></a><a name="p0230205553916"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1423015555395"><a name="p1423015555395"></a><a name="p1423015555395"></a>Chip ID, which can be obtained by calling <strong id="b89419995633041"><a name="b89419995633041"></a><a name="b89419995633041"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p11230125511398"><a name="p11230125511398"></a><a name="p11230125511398"></a>NPU: [0, <strong id="b165845052725448"><a name="b165845052725448"></a><a name="b165845052725448"></a>device_id_max</strong> – 1]</p>
<p id="p723015512391"><a name="p723015512391"></a><a name="p723015512391"></a>MCU: <strong id="b1714144614710"><a name="b1714144614710"></a><a name="b1714144614710"></a>mcu_id</strong></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row22309557394"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p02301655203910"><a name="p02301655203910"></a><a name="p02301655203910"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p22301655193914"><a name="p22301655193914"></a><a name="p22301655193914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p12301455113918"><a name="p12301455113918"></a><a name="p12301455113918"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p82316551391"><a name="p82316551391"></a><a name="p82316551391"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b5834112642487"><a name="b5834112642487"></a><a name="b5834112642487"></a>0</strong>.</p>
</td>
</tr>
<tr id="row1223110556396"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p15231155163916"><a name="p15231155163916"></a><a name="p15231155163916"></a>dcmi_ping</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p823111559399"><a name="p823111559399"></a><a name="p823111559399"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p15231105512392"><a name="p15231105512392"></a><a name="p15231105512392"></a>struct dcmi_ping_operate_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p12313554399"><a name="p12313554399"></a><a name="p12313554399"></a>Ping operation information.</p>
<p id="p132311755153910"><a name="p132311755153910"></a><a name="p132311755153910"></a>struct dcmi_ping_operate_info {</p>
<p id="p182311355123911"><a name="p182311355123911"></a><a name="p182311355123911"></a>char dst_addr[IP_ADDR_LEN];// Destination IPv4 address of the device to be pinged. The value of <strong id="b17458102413259"><a name="b17458102413259"></a><a name="b17458102413259"></a>IP_ADDR_LEN</strong> is <strong id="b1045818247257"><a name="b1045818247257"></a><a name="b1045818247257"></a>16</strong>.</p>
<p id="p1123112551393"><a name="p1123112551393"></a><a name="p1123112551393"></a>unsigned int sdid;// SDID of the device to be pinged. Either <strong id="b195371910992"><a name="b195371910992"></a><a name="b195371910992"></a>sdid</strong> or <strong id="b55373101595"><a name="b55373101595"></a><a name="b55373101595"></a>dst_addr</strong> is used to configure the destination address. If both of them are configured, <strong id="b35235123920"><a name="b35235123920"></a><a name="b35235123920"></a>dst_addr</strong> is used.</p>
<p id="p18231655203917"><a name="p18231655203917"></a><a name="p18231655203917"></a>unsigned int packet_size;// Size of a ping packet. The value range is 1792 to 3000 bytes. The packet header size is 1024 bytes. The correctness of the subsequent 1025 bytes to the <strong id="b1523867161014"><a name="b1523867161014"></a><a name="b1523867161014"></a>packet_size</strong> field is verified. The field type distribution of every 1024 bytes is as follows: 0xFF (256 bytes), 0x00 (256 bytes), 0xAA (256 bytes), and 0x55 (256 bytes).</p>
<p id="p923114557399"><a name="p923114557399"></a><a name="p923114557399"></a>unsigned int packet_send_num; // Number of ping packets. The value ranges from 1 to 1000.</p>
<p id="p1223185553919"><a name="p1223185553919"></a><a name="p1223185553919"></a>unsigned int packet_interval;// Delay interval for sending ping packets. The value ranges from 0 to 10 ms. The value <strong id="b1334014191312"><a name="b1334014191312"></a><a name="b1334014191312"></a>0</strong> indicates that a packet is sent immediately after a response is received.</p>
<p id="p72311556394"><a name="p72311556394"></a><a name="p72311556394"></a>unsigned int timeout;// Timeout wait time of each ping packet. The value ranges from 1 to 20000 ms. The configuration item does not take effect.</p>
<p id="p19231455173915"><a name="p19231455173915"></a><a name="p19231455173915"></a>unsigned char reserved[32];// Reserved field, which is not used currently.</p>
<p id="p5231255153917"><a name="p5231255153917"></a><a name="p5231255153917"></a>};</p>
<p id="p143091626124318"><a name="p143091626124318"></a><a name="p143091626124318"></a>Note:</p>
<p id="p167933314147"><a name="p167933314147"></a><a name="p167933314147"></a>In versions earlier than 25.0.RC1, the restrictions on using the preceding parameters are as follows:</p>
<p id="p1126692311438"><a name="p1126692311438"></a><a name="p1126692311438"></a>packet_send_num* (packet_interval+timeout)&lt;=20000 ms</p>
</td>
</tr>
<tr id="row823111553398"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1523195523910"><a name="p1523195523910"></a><a name="p1523195523910"></a>dcmi_reply</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p11231455143911"><a name="p11231455143911"></a><a name="p11231455143911"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p623125510397"><a name="p623125510397"></a><a name="p623125510397"></a>struct dcmi_ping_reply_info*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p72325553399"><a name="p72325553399"></a><a name="p72325553399"></a>Ping result information</p>
<p id="p17232115533920"><a name="p17232115533920"></a><a name="p17232115533920"></a>struct dcmi_ping_reply_info {</p>
<p id="p20232175573916"><a name="p20232175573916"></a><a name="p20232175573916"></a>char dst_addr[IP_ADDR_LEN];// Destination IPv4 address of the device to be pinged.</p>
<p id="p42321755193919"><a name="p42321755193919"></a><a name="p42321755193919"></a>enum dcmi_ping_result ret[DCMI_PING_PACKET_NUM_MAX];// Ping result of each data packet. The enumerated values of <strong id="b392122817144"><a name="b392122817144"></a><a name="b392122817144"></a>dcmi_ping_result</strong> include <strong id="b692528151418"><a name="b692528151418"></a><a name="b692528151418"></a>0</strong> (ping operation not initiated), <strong id="b5921287146"><a name="b5921287146"></a><a name="b5921287146"></a>1</strong> (ping packet successfully sent and received), <strong id="b3931328141418"><a name="b3931328141418"></a><a name="b3931328141418"></a>2</strong> (packet sending failure), and <strong id="b139315289140"><a name="b139315289140"></a><a name="b139315289140"></a>3</strong> (packet reception failure). The value of <strong id="b1744463913146"><a name="b1744463913146"></a><a name="b1744463913146"></a>DCMI_PING_PACKET_NUM_MAX</strong> is <strong id="b1244563951413"><a name="b1244563951413"></a><a name="b1244563951413"></a>1000</strong>.</p>
<p id="p192321955123919"><a name="p192321955123919"></a><a name="p192321955123919"></a>unsigned int total_packet_send_num;// Send count</p>
<p id="p223220555392"><a name="p223220555392"></a><a name="p223220555392"></a>unsigned int total_packet_recv_num;// Receive count</p>
<p id="p023215550392"><a name="p023215550392"></a><a name="p023215550392"></a>long start_tv_sec[DCMI_PING_PACKET_NUM_MAX];// Start time of the ping operation for each packet (unit: s)</p>
<p id="p122321055153912"><a name="p122321055153912"></a><a name="p122321055153912"></a>long start_tv_usec[DCMI_PING_PACKET_NUM_MAX];// Start time of the ping operation for each packet (unit: μs) The time is calculated based on the values in the unit of s and μs.</p>
<p id="p8232655153920"><a name="p8232655153920"></a><a name="p8232655153920"></a>long end_tv_sec[DCMI_PING_PACKET_NUM_MAX]; // End time of the ping operation for each packet (unit: s)</p>
<p id="p02325553390"><a name="p02325553390"></a><a name="p02325553390"></a>long end_tv_usec[DCMI_PING_PACKET_NUM_MAX];// End time of the ping operation for each packet (unit: μs) The time is calculated based on the values in the unit of s and μs.</p>
<p id="p18232155514391"><a name="p18232155514391"></a><a name="p18232155514391"></a>};</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section3642631135017"></a>**

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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b7147320127230"><a name="b7147320127230"></a><a name="b7147320127230"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None

**Restrictions<a name="section1100155515399"></a>**

The specified device and the destination device must use the same NPU driver version.

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
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

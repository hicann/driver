# dcmi\_get\_netdev\_pkt\_stats\_info<a name="EN-US_TOPIC_0000002546910403"></a>

**Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>**

**int dcmi\_get\_netdev\_pkt\_stats\_info\(int card\_id, int device\_id, int port\_id, struct dcmi\_network\_pkt\_stats\_info \*network\_pkt\_stats\_info\)**

**Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>**

Queries the statistics of packets sent and received by an NPU network port.

**Parameter Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412079"></a>**

<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1290353951711"><a name="p1290353951711"></a><a name="p1290353951711"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p13903193920176"><a name="p13903193920176"></a><a name="p13903193920176"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p09048390172"><a name="p09048390172"></a><a name="p09048390172"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p119041539161713"><a name="p119041539161713"></a><a name="p119041539161713"></a>Device ID. The supported IDs can be obtained by calling <strong id="b95142562833025"><a name="b95142562833025"></a><a name="b95142562833025"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1684271132614"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b1316903448173"><a name="b1316903448173"></a><a name="b1316903448173"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p450968185915"><a name="p450968185915"></a><a name="p450968185915"></a>NPU: [0, <strong id="b7077803758173"><a name="b7077803758173"></a><a name="b7077803758173"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="row5354192415172"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1824103514419"><a name="p1824103514419"></a><a name="p1824103514419"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p424143514417"><a name="p424143514417"></a><a name="p424143514417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p1424112357410"><a name="p1424112357410"></a><a name="p1424112357410"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1224183544119"><a name="p1224183544119"></a><a name="p1224183544119"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b94342216481"><a name="b94342216481"></a><a name="b94342216481"></a>0</strong>.</p>
</td>
</tr>
<tr id="row1459681913429"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p4908193110424"><a name="p4908193110424"></a><a name="p4908193110424"></a>network_pkt_stats_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p7908931124212"><a name="p7908931124212"></a><a name="p7908931124212"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p3908831194215"><a name="p3908831194215"></a><a name="p3908831194215"></a>dcmi_network_pkt_stats_info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1290823174218"><a name="p1290823174218"></a><a name="p1290823174218"></a>struct dcmi_network_pkt_stats_info {</p>
<p id="p17908133111429"><a name="p17908133111429"></a><a name="p17908133111429"></a>unsigned long long mac_tx_mac_pause_num;</p>
<p id="p8908163184219"><a name="p8908163184219"></a><a name="p8908163184219"></a>Total number of pause frame packets sent by the MAC</p>
<p id="p11908183144213"><a name="p11908183144213"></a><a name="p11908183144213"></a>unsigned long long mac_rx_mac_pause_num;</p>
<p id="p18908931114213"><a name="p18908931114213"></a><a name="p18908931114213"></a>Total number of pause frame packets received by the MAC</p>
<p id="p99081531154210"><a name="p99081531154210"></a><a name="p99081531154210"></a>unsigned long long mac_tx_pfc_pkt_num;</p>
<p id="p19087311426"><a name="p19087311426"></a><a name="p19087311426"></a>Total number of PFC frame packets sent by the MAC</p>
<p id="p29081731114212"><a name="p29081731114212"></a><a name="p29081731114212"></a>unsigned long long mac_tx_pfc_pri0_pkt_num;</p>
<p id="p1590863194214"><a name="p1590863194214"></a><a name="p1590863194214"></a>Total number of PFC frame packets sent by MAC queue 0</p>
<p id="p1890810315427"><a name="p1890810315427"></a><a name="p1890810315427"></a>unsigned long long mac_tx_pfc_pri1_pkt_num;</p>
<p id="p17908193194218"><a name="p17908193194218"></a><a name="p17908193194218"></a>Total number of PFC frame packets sent by MAC queue 1</p>
<p id="p20908173117422"><a name="p20908173117422"></a><a name="p20908173117422"></a>unsigned long long mac_tx_pfc_pri2_pkt_num;</p>
<p id="p18908203144210"><a name="p18908203144210"></a><a name="p18908203144210"></a>Total number of PFC frame packets sent by MAC queue 2</p>
<p id="p1090819318427"><a name="p1090819318427"></a><a name="p1090819318427"></a>unsigned long long mac_tx_pfc_pri3_pkt_num;</p>
<p id="p990893174219"><a name="p990893174219"></a><a name="p990893174219"></a>Total number of PFC frame packets sent by MAC queue 3</p>
<p id="p9908143117423"><a name="p9908143117423"></a><a name="p9908143117423"></a>unsigned long long mac_tx_pfc_pri4_pkt_num;</p>
<p id="p79081231194217"><a name="p79081231194217"></a><a name="p79081231194217"></a>Total number of PFC frame packets sent by MAC queue 4</p>
<p id="p1190833119426"><a name="p1190833119426"></a><a name="p1190833119426"></a>unsigned long long mac_tx_pfc_pri5_pkt_num;</p>
<p id="p1490893113421"><a name="p1490893113421"></a><a name="p1490893113421"></a>Total number of PFC frame packets sent by MAC queue 5</p>
<p id="p1490833117422"><a name="p1490833117422"></a><a name="p1490833117422"></a>unsigned long long mac_tx_pfc_pri6_pkt_num;</p>
<p id="p14908103104214"><a name="p14908103104214"></a><a name="p14908103104214"></a>Total number of PFC frame packets sent by MAC queue 6</p>
<p id="p1790893117420"><a name="p1790893117420"></a><a name="p1790893117420"></a>unsigned long long mac_tx_pfc_pri7_pkt_num;</p>
<p id="p169081731144210"><a name="p169081731144210"></a><a name="p169081731144210"></a>Total number of PFC frame packets sent by MAC queue 7</p>
<p id="p20908123154211"><a name="p20908123154211"></a><a name="p20908123154211"></a>unsigned long long mac_rx_pfc_pkt_num;</p>
<p id="p290843184213"><a name="p290843184213"></a><a name="p290843184213"></a>Total number of PFC frame packets received by the MAC</p>
<p id="p109081631104212"><a name="p109081631104212"></a><a name="p109081631104212"></a>unsigned long long mac_rx_pfc_pri0_pkt_num;</p>
<p id="p189082310429"><a name="p189082310429"></a><a name="p189082310429"></a>Total number of PFC frame packets received by MAC queue 0</p>
<p id="p7908631154220"><a name="p7908631154220"></a><a name="p7908631154220"></a>unsigned long long mac_rx_pfc_pri1_pkt_num;</p>
<p id="p590912317424"><a name="p590912317424"></a><a name="p590912317424"></a>Total number of PFC frame packets received by MAC queue 1</p>
<p id="p2909143116429"><a name="p2909143116429"></a><a name="p2909143116429"></a>unsigned long long mac_rx_pfc_pri2_pkt_num;</p>
<p id="p2090963164213"><a name="p2090963164213"></a><a name="p2090963164213"></a>Total number of PFC frame packets received by MAC queue 2</p>
<p id="p0909173112427"><a name="p0909173112427"></a><a name="p0909173112427"></a>unsigned long long mac_rx_pfc_pri3_pkt_num;</p>
<p id="p9909231204216"><a name="p9909231204216"></a><a name="p9909231204216"></a>Total number of PFC frame packets received by MAC queue 3</p>
<p id="p159091431144215"><a name="p159091431144215"></a><a name="p159091431144215"></a>unsigned long long mac_rx_pfc_pri4_pkt_num;</p>
<p id="p190933120421"><a name="p190933120421"></a><a name="p190933120421"></a>Total number of PFC frame packets received by MAC queue 4</p>
<p id="p1790917316421"><a name="p1790917316421"></a><a name="p1790917316421"></a>unsigned long long mac_rx_pfc_pri5_pkt_num;</p>
<p id="p8909431184217"><a name="p8909431184217"></a><a name="p8909431184217"></a>Total number of PFC frame packets received by MAC queue 5</p>
<p id="p690973124215"><a name="p690973124215"></a><a name="p690973124215"></a>unsigned long long mac_rx_pfc_pri6_pkt_num;</p>
<p id="p17909193104216"><a name="p17909193104216"></a><a name="p17909193104216"></a>Total number of PFC frame packets received by MAC queue 6</p>
<p id="p49097315422"><a name="p49097315422"></a><a name="p49097315422"></a>unsigned long long mac_rx_pfc_pri7_pkt_num;</p>
<p id="p69093313420"><a name="p69093313420"></a><a name="p69093313420"></a>Total number of PFC frame packets received by MAC queue 7</p>
<p id="p4909331174211"><a name="p4909331174211"></a><a name="p4909331174211"></a>unsigned long long mac_tx_total_pkt_num;</p>
<p id="p29095313426"><a name="p29095313426"></a><a name="p29095313426"></a>Total number of packets sent by the MAC</p>
<p id="p1490933194218"><a name="p1490933194218"></a><a name="p1490933194218"></a>unsigned long long mac_tx_total_oct_num;</p>
<p id="p79091631184211"><a name="p79091631184211"></a><a name="p79091631184211"></a>Total bytes of packets sent by the MAC</p>
<p id="p179094314425"><a name="p179094314425"></a><a name="p179094314425"></a>unsigned long long mac_tx_bad_pkt_num;</p>
<p id="p1590973124211"><a name="p1590973124211"></a><a name="p1590973124211"></a>Total number of bad packets sent by the MAC</p>
<p id="p8909231104214"><a name="p8909231104214"></a><a name="p8909231104214"></a>unsigned long long mac_tx_bad_oct_num;</p>
<p id="p69091231134219"><a name="p69091231134219"></a><a name="p69091231134219"></a>Total bytes of bad packets sent by the MAC</p>
<p id="p13909731154215"><a name="p13909731154215"></a><a name="p13909731154215"></a>unsigned long long mac_rx_total_pkt_num;</p>
<p id="p590943119423"><a name="p590943119423"></a><a name="p590943119423"></a>Total number of packets received by the MAC</p>
<p id="p5909331114215"><a name="p5909331114215"></a><a name="p5909331114215"></a>unsigned long long mac_rx_total_oct_num;</p>
<p id="p59091531104217"><a name="p59091531104217"></a><a name="p59091531104217"></a>Total bytes of packets received by the MAC</p>
<p id="p490973104214"><a name="p490973104214"></a><a name="p490973104214"></a>unsigned long long mac_rx_bad_pkt_num;</p>
<p id="p19909731104211"><a name="p19909731104211"></a><a name="p19909731104211"></a>Total number of bad packets received by the MAC</p>
<p id="p990963110427"><a name="p990963110427"></a><a name="p990963110427"></a>unsigned long long mac_rx_bad_oct_num;</p>
<p id="p13909113124211"><a name="p13909113124211"></a><a name="p13909113124211"></a>Total bytes of bad packets received by the MAC</p>
<p id="p18909193118427"><a name="p18909193118427"></a><a name="p18909193118427"></a>unsigned long long mac_rx_fcs_err_pkt_num;</p>
<p id="p7909113194210"><a name="p7909113194210"></a><a name="p7909113194210"></a>Number of FCS error packets received by the MAC</p>
<p id="p14909183114213"><a name="p14909183114213"></a><a name="p14909183114213"></a>unsigned long long roce_rx_rc_pkt_num;</p>
<p id="p19909103116423"><a name="p19909103116423"></a><a name="p19909103116423"></a>Number of RC packets received by the RoCEE</p>
<p id="p5909931174218"><a name="p5909931174218"></a><a name="p5909931174218"></a>unsigned long long roce_rx_all_pkt_num;</p>
<p id="p1690963194213"><a name="p1690963194213"></a><a name="p1690963194213"></a>Total number of packets received by the RoCEE</p>
<p id="p4909123113423"><a name="p4909123113423"></a><a name="p4909123113423"></a>unsigned long long roce_rx_err_pkt_num;</p>
<p id="p99091231184211"><a name="p99091231184211"></a><a name="p99091231184211"></a>Total number of bad packets received by the RoCEE</p>
<p id="p490914317429"><a name="p490914317429"></a><a name="p490914317429"></a>unsigned long long roce_tx_rc_pkt_num;</p>
<p id="p2909531184212"><a name="p2909531184212"></a><a name="p2909531184212"></a>Number of RC packets sent by the RoCEE</p>
<p id="p189099312429"><a name="p189099312429"></a><a name="p189099312429"></a>unsigned long long roce_tx_all_pkt_num;</p>
<p id="p6909531174211"><a name="p6909531174211"></a><a name="p6909531174211"></a>Total number of packets sent by the RoCEE</p>
<p id="p4909103119426"><a name="p4909103119426"></a><a name="p4909103119426"></a>unsigned long long roce_tx_err_pkt_num;</p>
<p id="p7909103116422"><a name="p7909103116422"></a><a name="p7909103116422"></a>Total number of bad packets sent by the RoCEE</p>
<p id="p190983110426"><a name="p190983110426"></a><a name="p190983110426"></a>unsigned long long roce_cqe_num;</p>
<p id="p190943134215"><a name="p190943134215"></a><a name="p190943134215"></a>Total number of elements completed in a RoCEE task</p>
<p id="p149093310426"><a name="p149093310426"></a><a name="p149093310426"></a>unsigned long long roce_rx_cnp_pkt_num;</p>
<p id="p18909531194213"><a name="p18909531194213"></a><a name="p18909531194213"></a>Number of CNP packets received by the RoCEE</p>
<p id="p8909153112428"><a name="p8909153112428"></a><a name="p8909153112428"></a>unsigned long long roce_tx_cnp_pkt_num;</p>
<p id="p3909143118429"><a name="p3909143118429"></a><a name="p3909143118429"></a>Number of CNP packets sent by the RoCEE</p>
<p id="p49091131114215"><a name="p49091131114215"></a><a name="p49091131114215"></a>unsigned long long roce_err_ack_num;</p>
<p id="p0909173164220"><a name="p0909173164220"></a><a name="p0909173164220"></a>Number of unexpected ACK packets received by the RoCEE. These packets are discarded by the NPU, without affecting services.</p>
<p id="p3909143114213"><a name="p3909143114213"></a><a name="p3909143114213"></a>unsigned long long roce_err_psn_num;</p>
<p id="p6909231124210"><a name="p6909231124210"></a><a name="p6909231124210"></a>Number of PSN packets received by the RoCEE &gt; Expected PSN packets or duplicate PSN packets. If packets are out of order or lost, transmission retry is triggered.</p>
<p id="p19091831134218"><a name="p19091831134218"></a><a name="p19091831134218"></a>unsigned long long roce_verification_err_num;</p>
<p id="p1090912314422"><a name="p1090912314422"></a><a name="p1090912314422"></a>Number of packets with field check errors received by the RoCEE. The errors include verification failures on ICRC, packet length, or destination port number.</p>
<p id="p1290973144219"><a name="p1290973144219"></a><a name="p1290973144219"></a>unsigned long long roce_err_qp_status_num;</p>
<p id="p189092314421"><a name="p189092314421"></a><a name="p189092314421"></a>Number of packets received by the RoCEE during abnormal QP connection</p>
<p id="p49091031124213"><a name="p49091031124213"></a><a name="p49091031124213"></a>unsigned long long roce_new_pkt_rty_num;</p>
<p id="p15909731114217"><a name="p15909731114217"></a><a name="p15909731114217"></a>Number of packet transmission retries by the RoCEE</p>
<p id="p1890916310424"><a name="p1890916310424"></a><a name="p1890916310424"></a>unsigned long long roce_ecn_db_num;</p>
<p id="p490933117428"><a name="p490933117428"></a><a name="p490933117428"></a>Number of ECN-marked packets received by the RoCEE</p>
<p id="p190973144218"><a name="p190973144218"></a><a name="p190973144218"></a>unsigned long long nic_tx_all_pkg_num;</p>
<p id="p10909631134212"><a name="p10909631134212"></a><a name="p10909631134212"></a>Total number of packets sent by the NIC</p>
<p id="p590913311424"><a name="p590913311424"></a><a name="p590913311424"></a>unsigned long long nic_tx_all_oct_num;</p>
<p id="p890920316422"><a name="p890920316422"></a><a name="p890920316422"></a>Total bytes of packets sent by the NIC</p>
<p id="p1990919315428"><a name="p1990919315428"></a><a name="p1990919315428"></a>unsigned long long nic_rx_all_pkg_num;</p>
<p id="p6910131114220"><a name="p6910131114220"></a><a name="p6910131114220"></a>Total number of packets received by the NIC</p>
<p id="p199101131114218"><a name="p199101131114218"></a><a name="p199101131114218"></a>unsigned long long nic_rx_all_oct_num;</p>
<p id="p891003119424"><a name="p891003119424"></a><a name="p891003119424"></a>Total bytes of packets received by the NIC</p>
<p id="p391093104213"><a name="p391093104213"></a><a name="p391093104213"></a>long tv_sec;</p>
<p id="p7910031144216"><a name="p7910031144216"></a><a name="p7910031144216"></a>Current system time when the query occurs (unit: s)</p>
<p id="p18910103110426"><a name="p18910103110426"></a><a name="p18910103110426"></a>long tv_usec;</p>
<p id="p091023118421"><a name="p091023118421"></a><a name="p091023118421"></a>Current system time when the query occurs (unit: μs)</p>
<p id="p79104317427"><a name="p79104317427"></a><a name="p79104317427"></a>unsigned char reserved[64];</p>
<p id="p3910183194216"><a name="p3910183194216"></a><a name="p3910183194216"></a>};</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b4836663857854"><a name="b4836663857854"></a><a name="b4836663857854"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>**

```c
...
int ret = 0;
int card_id=0;
int device_id=0;
int port_id=0;
struct dcmi_network_pkt_stats_info network_pkt_stats_info = {0};
ret = dcmi_get_netdev_pkt_stats_info (card_id, device_id, port_id, &network_pkt_stats_info);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

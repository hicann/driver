# dcmi\_get\_netdev\_pkt\_stats\_info<a name="EN-US_TOPIC_0000002515343872"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p119041539161713"><a name="p119041539161713"></a><a name="p119041539161713"></a>Device ID. The supported IDs can be obtained by calling <strong id="b567138784102837"><a name="b567138784102837"></a><a name="b567138784102837"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1684271132614"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b59758398110257"><a name="b59758398110257"></a><a name="b59758398110257"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU chip: [0, <strong id="b2035109471111942"><a name="b2035109471111942"></a><a name="b2035109471111942"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row5354192415172"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1824103514419"><a name="p1824103514419"></a><a name="p1824103514419"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p424143514417"><a name="p424143514417"></a><a name="p424143514417"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p1424112357410"><a name="p1424112357410"></a><a name="p1424112357410"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1224183544119"><a name="p1224183544119"></a><a name="p1224183544119"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b132397338235051"><a name="b132397338235051"></a><a name="b132397338235051"></a>0</strong>.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b62719917385626"><a name="b62719917385626"></a><a name="b62719917385626"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table13875158355"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row979954933113"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p259621143212"><a name="en-us_topic_0000002515503852_p259621143212"></a><a name="en-us_topic_0000002515503852_p259621143212"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p185961211133216"><a name="en-us_topic_0000002515503852_p185961211133216"></a><a name="en-us_topic_0000002515503852_p185961211133216"></a><strong id="en-us_topic_0000002515503852_b112423581349"><a name="en-us_topic_0000002515503852_b112423581349"></a><a name="en-us_topic_0000002515503852_b112423581349"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p3596161118320"><a name="en-us_topic_0000002515503852_p3596161118320"></a><a name="en-us_topic_0000002515503852_p3596161118320"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b1646915916412"><a name="en-us_topic_0000002515503852_b1646915916412"></a><a name="en-us_topic_0000002515503852_b1646915916412"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p13596101193211"><a name="en-us_topic_0000002515503852_p13596101193211"></a><a name="en-us_topic_0000002515503852_p13596101193211"></a><strong id="en-us_topic_0000002515503852_b1264430856"><a name="en-us_topic_0000002515503852_b1264430856"></a><a name="en-us_topic_0000002515503852_b1264430856"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row279917498314"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p879924993116"><a name="en-us_topic_0000002515503852_p879924993116"></a><a name="en-us_topic_0000002515503852_p879924993116"></a><span id="en-us_topic_0000002515503852_ph3799204963110"><a name="en-us_topic_0000002515503852_ph3799204963110"></a><a name="en-us_topic_0000002515503852_ph3799204963110"></a><span id="en-us_topic_0000002515503852_text579974910315"><a name="en-us_topic_0000002515503852_text579974910315"></a><a name="en-us_topic_0000002515503852_text579974910315"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18370822173217"><a name="en-us_topic_0000002515503852_p18370822173217"></a><a name="en-us_topic_0000002515503852_p18370822173217"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1737914223329"><a name="en-us_topic_0000002515503852_p1737914223329"></a><a name="en-us_topic_0000002515503852_p1737914223329"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p78004497311"><a name="en-us_topic_0000002515503852_p78004497311"></a><a name="en-us_topic_0000002515503852_p78004497311"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row10800749163116"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p11800114913117"><a name="en-us_topic_0000002515503852_p11800114913117"></a><a name="en-us_topic_0000002515503852_p11800114913117"></a><span id="en-us_topic_0000002515503852_text8800164911319"><a name="en-us_topic_0000002515503852_text8800164911319"></a><a name="en-us_topic_0000002515503852_text8800164911319"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1638911222323"><a name="en-us_topic_0000002515503852_p1638911222323"></a><a name="en-us_topic_0000002515503852_p1638911222323"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p17392222113213"><a name="en-us_topic_0000002515503852_p17392222113213"></a><a name="en-us_topic_0000002515503852_p17392222113213"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p168008496318"><a name="en-us_topic_0000002515503852_p168008496318"></a><a name="en-us_topic_0000002515503852_p168008496318"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row5800184916315"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p9800164914316"><a name="en-us_topic_0000002515503852_p9800164914316"></a><a name="en-us_topic_0000002515503852_p9800164914316"></a><span id="en-us_topic_0000002515503852_text980012496318"><a name="en-us_topic_0000002515503852_text980012496318"></a><a name="en-us_topic_0000002515503852_text980012496318"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p7397222133210"><a name="en-us_topic_0000002515503852_p7397222133210"></a><a name="en-us_topic_0000002515503852_p7397222133210"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p194011622143211"><a name="en-us_topic_0000002515503852_p194011622143211"></a><a name="en-us_topic_0000002515503852_p194011622143211"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p178001449123113"><a name="en-us_topic_0000002515503852_p178001449123113"></a><a name="en-us_topic_0000002515503852_p178001449123113"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7800104915312"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1580044933111"><a name="en-us_topic_0000002515503852_p1580044933111"></a><a name="en-us_topic_0000002515503852_p1580044933111"></a><span id="en-us_topic_0000002515503852_text9800184912315"><a name="en-us_topic_0000002515503852_text9800184912315"></a><a name="en-us_topic_0000002515503852_text9800184912315"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p104051222163215"><a name="en-us_topic_0000002515503852_p104051222163215"></a><a name="en-us_topic_0000002515503852_p104051222163215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p440822211325"><a name="en-us_topic_0000002515503852_p440822211325"></a><a name="en-us_topic_0000002515503852_p440822211325"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p38001949193113"><a name="en-us_topic_0000002515503852_p38001949193113"></a><a name="en-us_topic_0000002515503852_p38001949193113"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18800194983115"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1180013499315"><a name="en-us_topic_0000002515503852_p1180013499315"></a><a name="en-us_topic_0000002515503852_p1180013499315"></a><span id="en-us_topic_0000002515503852_text10800649183116"><a name="en-us_topic_0000002515503852_text10800649183116"></a><a name="en-us_topic_0000002515503852_text10800649183116"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18410722203220"><a name="en-us_topic_0000002515503852_p18410722203220"></a><a name="en-us_topic_0000002515503852_p18410722203220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3413182217322"><a name="en-us_topic_0000002515503852_p3413182217322"></a><a name="en-us_topic_0000002515503852_p3413182217322"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1880012499317"><a name="en-us_topic_0000002515503852_p1880012499317"></a><a name="en-us_topic_0000002515503852_p1880012499317"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row13800174918315"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p7800124914316"><a name="en-us_topic_0000002515503852_p7800124914316"></a><a name="en-us_topic_0000002515503852_p7800124914316"></a><span id="en-us_topic_0000002515503852_text868610118325"><a name="en-us_topic_0000002515503852_text868610118325"></a><a name="en-us_topic_0000002515503852_text868610118325"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18415112223217"><a name="en-us_topic_0000002515503852_p18415112223217"></a><a name="en-us_topic_0000002515503852_p18415112223217"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10417422113216"><a name="en-us_topic_0000002515503852_p10417422113216"></a><a name="en-us_topic_0000002515503852_p10417422113216"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p14800449103115"><a name="en-us_topic_0000002515503852_p14800449103115"></a><a name="en-us_topic_0000002515503852_p14800449103115"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1680016498317"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p8800124920315"><a name="en-us_topic_0000002515503852_p8800124920315"></a><a name="en-us_topic_0000002515503852_p8800124920315"></a><span id="en-us_topic_0000002515503852_text2800174910316"><a name="en-us_topic_0000002515503852_text2800174910316"></a><a name="en-us_topic_0000002515503852_text2800174910316"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134191622183215"><a name="en-us_topic_0000002515503852_p134191622183215"></a><a name="en-us_topic_0000002515503852_p134191622183215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p0422822103214"><a name="en-us_topic_0000002515503852_p0422822103214"></a><a name="en-us_topic_0000002515503852_p0422822103214"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19800144917310"><a name="en-us_topic_0000002515503852_p19800144917310"></a><a name="en-us_topic_0000002515503852_p19800144917310"></a>NA</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row2800104920311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p4800194933110"><a name="en-us_topic_0000002515503852_p4800194933110"></a><a name="en-us_topic_0000002515503852_p4800194933110"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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
    //todo: Record logs.
    return ret;
}
...
```

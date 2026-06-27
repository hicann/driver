# dcmi\_get\_extra\_statistics\_info<a name="EN-US_TOPIC_0000002515343850"></a>

**Prototype<a name="section52891528074"></a>**

**int dcmi\_get\_extra\_statistics\_info\(int card\_id, int device\_id, int port\_id, struct dcmi\_extra\_statistics\_info \*info\)**

**Description<a name="section1882718362712"></a>**

Queries the extended statistics of a network port. The following link status statistics can be queried: pcs errs, pre-FEC bit errors, post-FEC bit errors, and uncorrected bit errors.

**Parameter Description<a name="section1961744213719"></a>**

<a name="table1730213792411"></a>
<table><thead align="left"><tr id="en-us_topic_0000002338977294_row1134310167588"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002338977294_p143431616195810"><a name="en-us_topic_0000002338977294_p143431616195810"></a><a name="en-us_topic_0000002338977294_p143431616195810"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002338977294_p134391615810"><a name="en-us_topic_0000002338977294_p134391615810"></a><a name="en-us_topic_0000002338977294_p134391615810"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002338977294_p13343101635816"><a name="en-us_topic_0000002338977294_p13343101635816"></a><a name="en-us_topic_0000002338977294_p13343101635816"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002338977294_p7343111612584"><a name="en-us_topic_0000002338977294_p7343111612584"></a><a name="en-us_topic_0000002338977294_p7343111612584"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002338977294_row183431816175818"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977294_p14343111675811"><a name="en-us_topic_0000002338977294_p14343111675811"></a><a name="en-us_topic_0000002338977294_p14343111675811"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977294_p934317169586"><a name="en-us_topic_0000002338977294_p934317169586"></a><a name="en-us_topic_0000002338977294_p934317169586"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977294_p43435167585"><a name="en-us_topic_0000002338977294_p43435167585"></a><a name="en-us_topic_0000002338977294_p43435167585"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977294_p33431716105818"><a name="en-us_topic_0000002338977294_p33431716105818"></a><a name="en-us_topic_0000002338977294_p33431716105818"></a>Device ID. The supported IDs can be obtained by calling <strong id="b149216137102852"><a name="b149216137102852"></a><a name="b149216137102852"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338977294_row4343131613584"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977294_p14343216145818"><a name="en-us_topic_0000002338977294_p14343216145818"></a><a name="en-us_topic_0000002338977294_p14343216145818"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977294_p0343161610582"><a name="en-us_topic_0000002338977294_p0343161610582"></a><a name="en-us_topic_0000002338977294_p0343161610582"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977294_p73432016195812"><a name="en-us_topic_0000002338977294_p73432016195812"></a><a name="en-us_topic_0000002338977294_p73432016195812"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977294_p173432016105817"><a name="en-us_topic_0000002338977294_p173432016105817"></a><a name="en-us_topic_0000002338977294_p173432016105817"></a>Chip ID, which can be obtained by calling <strong id="b954297994102523"><a name="b954297994102523"></a><a name="b954297994102523"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002338977294_p1534331611582"><a name="en-us_topic_0000002338977294_p1534331611582"></a><a name="en-us_topic_0000002338977294_p1534331611582"></a>NPU chip: [0, <strong id="b57446980111948"><a name="b57446980111948"></a><a name="b57446980111948"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002338977294_row7344151655814"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977294_p1434471614585"><a name="en-us_topic_0000002338977294_p1434471614585"></a><a name="en-us_topic_0000002338977294_p1434471614585"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977294_p13444161584"><a name="en-us_topic_0000002338977294_p13444161584"></a><a name="en-us_topic_0000002338977294_p13444161584"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977294_p234431619587"><a name="en-us_topic_0000002338977294_p234431619587"></a><a name="en-us_topic_0000002338977294_p234431619587"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977294_p9359145314538"><a name="en-us_topic_0000002338977294_p9359145314538"></a><a name="en-us_topic_0000002338977294_p9359145314538"></a>Network port number of the NPU device. Currently, the value can only be set to <strong id="b129922759123040"><a name="b129922759123040"></a><a name="b129922759123040"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338977294_row1234451655813"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977294_p534419161587"><a name="en-us_topic_0000002338977294_p534419161587"></a><a name="en-us_topic_0000002338977294_p534419161587"></a>info</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977294_p934481611585"><a name="en-us_topic_0000002338977294_p934481611585"></a><a name="en-us_topic_0000002338977294_p934481611585"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977294_p1934401695815"><a name="en-us_topic_0000002338977294_p1934401695815"></a><a name="en-us_topic_0000002338977294_p1934401695815"></a>struct dcmi_extra_statistics_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977294_p1791511213156"><a name="en-us_topic_0000002338977294_p1791511213156"></a><a name="en-us_topic_0000002338977294_p1791511213156"></a>struct dcmi_extra_statistics_info {</p>
<p id="en-us_topic_0000002338977294_p1691522111155"><a name="en-us_topic_0000002338977294_p1691522111155"></a><a name="en-us_topic_0000002338977294_p1691522111155"></a>unsigned long long cw_total_cnt; // Total number of codewords</p>
<p id="en-us_topic_0000002338977294_p3915172171510"><a name="en-us_topic_0000002338977294_p3915172171510"></a><a name="en-us_topic_0000002338977294_p3915172171510"></a>unsigned long long cw_before_correct_cnt; // Forward error correction codewords</p>
<p id="en-us_topic_0000002338977294_p9915122181510"><a name="en-us_topic_0000002338977294_p9915122181510"></a><a name="en-us_topic_0000002338977294_p9915122181510"></a>unsigned long long cw_correct_cnt; // Correctable codeword errors</p>
<p id="en-us_topic_0000002338977294_p119151621151518"><a name="en-us_topic_0000002338977294_p119151621151518"></a><a name="en-us_topic_0000002338977294_p119151621151518"></a>unsigned long long cw_uncorrect_cnt; // Uncorrectable codeword errors</p>
<p id="en-us_topic_0000002338977294_p191592116158"><a name="en-us_topic_0000002338977294_p191592116158"></a><a name="en-us_topic_0000002338977294_p191592116158"></a>unsigned long long cw_bad_cnt; // Number of cw_bad events</p>
<p id="en-us_topic_0000002338977294_p1791562113150"><a name="en-us_topic_0000002338977294_p1791562113150"></a><a name="en-us_topic_0000002338977294_p1791562113150"></a>unsigned long long trans_total_bit; // Total number of transmitted bits</p>
<p id="en-us_topic_0000002338977294_p391582171510"><a name="en-us_topic_0000002338977294_p391582171510"></a><a name="en-us_topic_0000002338977294_p391582171510"></a>unsigned long long cw_total_correct_bit; // Total number of correctable bits in codewords</p>
<p id="en-us_topic_0000002338977294_p291512191519"><a name="en-us_topic_0000002338977294_p291512191519"></a><a name="en-us_topic_0000002338977294_p291512191519"></a>unsigned long long rx_full_drop_cnt; // Number of discarded packets after buffer in the RX direction is full</p>
<p id="en-us_topic_0000002338977294_p17916122113159"><a name="en-us_topic_0000002338977294_p17916122113159"></a><a name="en-us_topic_0000002338977294_p17916122113159"></a>unsigned long long pcs_err_cnt; // Number of error blocks at the PCS layer</p>
<p id="en-us_topic_0000002338977294_p149165218158"><a name="en-us_topic_0000002338977294_p149165218158"></a><a name="en-us_topic_0000002338977294_p149165218158"></a>unsigned long long rx_send_app_good_pkts; // Total number of good frames sent to the application side, excluding <strong id="b1592515166115"><a name="b1592515166115"></a><a name="b1592515166115"></a>fc-consumed-error</strong> frames. <strong id="b1549241913"><a name="b1549241913"></a><a name="b1549241913"></a>fc-consumed-error</strong> indicates flow control frames flagged as <strong id="b54112411113"><a name="b54112411113"></a><a name="b54112411113"></a>abort</strong> by the MAC layer</p>
<p id="en-us_topic_0000002338977294_p5916821121518"><a name="en-us_topic_0000002338977294_p5916821121518"></a><a name="en-us_topic_0000002338977294_p5916821121518"></a>unsigned long long rx_send_app_bad_pkts; // Total number of bad frames or <strong id="b534818287113"><a name="b534818287113"></a><a name="b534818287113"></a>fc-consumed-error</strong> frames sent to the application side</p>
<p id="en-us_topic_0000002338977294_p18916122141519"><a name="en-us_topic_0000002338977294_p18916122141519"></a><a name="en-us_topic_0000002338977294_p18916122141519"></a>double correcting_bit_rate; // Correctable bit error rate</p>
<p id="en-us_topic_0000002338977294_p169161921181511"><a name="en-us_topic_0000002338977294_p169161921181511"></a><a name="en-us_topic_0000002338977294_p169161921181511"></a>};</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section132614482713"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b121828135085639"><a name="b121828135085639"></a><a name="b121828135085639"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section19537911783"></a>**

None.

**Restrictions<a name="section16624106086"></a>**

Atlas 200T A2 Box16 heterogeneous subrack, Atlas 800T A2 training server, Atlas 800I A2 inference server,  Atlas 900 A2 PoD cluster basic unit, and A200I A2 Box heterogeneous component: This API can be used in PM + privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table167103125114"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row3169171463617"><th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p8558112793214"><a name="en-us_topic_0000002515503852_p8558112793214"></a><a name="en-us_topic_0000002515503852_p8558112793214"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="18.94%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p655852717326"><a name="en-us_topic_0000002515503852_p655852717326"></a><a name="en-us_topic_0000002515503852_p655852717326"></a><strong id="en-us_topic_0000002515503852_b2084215313512"><a name="en-us_topic_0000002515503852_b2084215313512"></a><a name="en-us_topic_0000002515503852_b2084215313512"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p10558122715327"><a name="en-us_topic_0000002515503852_p10558122715327"></a><a name="en-us_topic_0000002515503852_p10558122715327"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b14917518517"><a name="en-us_topic_0000002515503852_b14917518517"></a><a name="en-us_topic_0000002515503852_b14917518517"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="27.02%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p15581927103214"><a name="en-us_topic_0000002515503852_p15581927103214"></a><a name="en-us_topic_0000002515503852_p15581927103214"></a><strong id="en-us_topic_0000002515503852_b193961161854"><a name="en-us_topic_0000002515503852_b193961161854"></a><a name="en-us_topic_0000002515503852_b193961161854"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row1816915147366"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p6169151423619"><a name="en-us_topic_0000002515503852_p6169151423619"></a><a name="en-us_topic_0000002515503852_p6169151423619"></a><span id="en-us_topic_0000002515503852_ph116911144369"><a name="en-us_topic_0000002515503852_ph116911144369"></a><a name="en-us_topic_0000002515503852_ph116911144369"></a><span id="en-us_topic_0000002515503852_text71694149366"><a name="en-us_topic_0000002515503852_text71694149366"></a><a name="en-us_topic_0000002515503852_text71694149366"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p316911142362"><a name="en-us_topic_0000002515503852_p316911142362"></a><a name="en-us_topic_0000002515503852_p316911142362"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p816918145361"><a name="en-us_topic_0000002515503852_p816918145361"></a><a name="en-us_topic_0000002515503852_p816918145361"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p9472202011368"><a name="en-us_topic_0000002515503852_p9472202011368"></a><a name="en-us_topic_0000002515503852_p9472202011368"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row01692149364"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10169141412361"><a name="en-us_topic_0000002515503852_p10169141412361"></a><a name="en-us_topic_0000002515503852_p10169141412361"></a><span id="en-us_topic_0000002515503852_text1516951453611"><a name="en-us_topic_0000002515503852_text1516951453611"></a><a name="en-us_topic_0000002515503852_text1516951453611"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16169121403617"><a name="en-us_topic_0000002515503852_p16169121403617"></a><a name="en-us_topic_0000002515503852_p16169121403617"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p171698141361"><a name="en-us_topic_0000002515503852_p171698141361"></a><a name="en-us_topic_0000002515503852_p171698141361"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1348119209364"><a name="en-us_topic_0000002515503852_p1348119209364"></a><a name="en-us_topic_0000002515503852_p1348119209364"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row17169814163612"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p2169414113616"><a name="en-us_topic_0000002515503852_p2169414113616"></a><a name="en-us_topic_0000002515503852_p2169414113616"></a><span id="en-us_topic_0000002515503852_text2169111443615"><a name="en-us_topic_0000002515503852_text2169111443615"></a><a name="en-us_topic_0000002515503852_text2169111443615"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p141696146366"><a name="en-us_topic_0000002515503852_p141696146366"></a><a name="en-us_topic_0000002515503852_p141696146366"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3169114113611"><a name="en-us_topic_0000002515503852_p3169114113611"></a><a name="en-us_topic_0000002515503852_p3169114113611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p13489162017366"><a name="en-us_topic_0000002515503852_p13489162017366"></a><a name="en-us_topic_0000002515503852_p13489162017366"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row01691314183618"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1616951453614"><a name="en-us_topic_0000002515503852_p1616951453614"></a><a name="en-us_topic_0000002515503852_p1616951453614"></a><span id="en-us_topic_0000002515503852_text17169141413610"><a name="en-us_topic_0000002515503852_text17169141413610"></a><a name="en-us_topic_0000002515503852_text17169141413610"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p316911419369"><a name="en-us_topic_0000002515503852_p316911419369"></a><a name="en-us_topic_0000002515503852_p316911419369"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p141697141368"><a name="en-us_topic_0000002515503852_p141697141368"></a><a name="en-us_topic_0000002515503852_p141697141368"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1949213202364"><a name="en-us_topic_0000002515503852_p1949213202364"></a><a name="en-us_topic_0000002515503852_p1949213202364"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1169151413367"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1716931483615"><a name="en-us_topic_0000002515503852_p1716931483615"></a><a name="en-us_topic_0000002515503852_p1716931483615"></a><span id="en-us_topic_0000002515503852_text81691114103617"><a name="en-us_topic_0000002515503852_text81691114103617"></a><a name="en-us_topic_0000002515503852_text81691114103617"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p816912141365"><a name="en-us_topic_0000002515503852_p816912141365"></a><a name="en-us_topic_0000002515503852_p816912141365"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15169191411369"><a name="en-us_topic_0000002515503852_p15169191411369"></a><a name="en-us_topic_0000002515503852_p15169191411369"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1497112043619"><a name="en-us_topic_0000002515503852_p1497112043619"></a><a name="en-us_topic_0000002515503852_p1497112043619"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row111691014173614"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19169514103610"><a name="en-us_topic_0000002515503852_p19169514103610"></a><a name="en-us_topic_0000002515503852_p19169514103610"></a><span id="en-us_topic_0000002515503852_text01406115324"><a name="en-us_topic_0000002515503852_text01406115324"></a><a name="en-us_topic_0000002515503852_text01406115324"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p181691314163611"><a name="en-us_topic_0000002515503852_p181691314163611"></a><a name="en-us_topic_0000002515503852_p181691314163611"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p516961453612"><a name="en-us_topic_0000002515503852_p516961453612"></a><a name="en-us_topic_0000002515503852_p516961453612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p25021520143613"><a name="en-us_topic_0000002515503852_p25021520143613"></a><a name="en-us_topic_0000002515503852_p25021520143613"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1816912147365"><td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1916941423613"><a name="en-us_topic_0000002515503852_p1916941423613"></a><a name="en-us_topic_0000002515503852_p1916941423613"></a><span id="en-us_topic_0000002515503852_text121691149365"><a name="en-us_topic_0000002515503852_text121691149365"></a><a name="en-us_topic_0000002515503852_text121691149365"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="18.94%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p14169101413366"><a name="en-us_topic_0000002515503852_p14169101413366"></a><a name="en-us_topic_0000002515503852_p14169101413366"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10169614163611"><a name="en-us_topic_0000002515503852_p10169614163611"></a><a name="en-us_topic_0000002515503852_p10169614163611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="27.02%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12507102016363"><a name="en-us_topic_0000002515503852_p12507102016363"></a><a name="en-us_topic_0000002515503852_p12507102016363"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1317019147361"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2170191493613"><a name="en-us_topic_0000002515503852_p2170191493613"></a><a name="en-us_topic_0000002515503852_p2170191493613"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section121365111485"></a>**

```c
...
int ret = 0; 
int card_id = 0; 
int device_id = 0; 
int port_id = 0;
struct dcmi_extra_statistics_info info = {0}; 
ret = dcmi_get_extra_statistics_info (card_id, device_id, port_id, &info); 
if (ret != 0){
     // todo: Record logs.
     return ret;
} 
...
```

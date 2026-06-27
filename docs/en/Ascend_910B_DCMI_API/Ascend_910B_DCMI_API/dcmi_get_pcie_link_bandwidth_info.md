# dcmi\_get\_pcie\_link\_bandwidth\_info<a name="EN-US_TOPIC_0000002546903793"></a>

**Prototype<a name="section196251231145019"></a>**

**int dcmi\_get\_pcie\_link\_bandwidth\_info \(int card\_id, int device\_id, struct dcmi\_pcie\_link\_bandwidth\_info \*pcie\_link\_bandwidth\_info\)**

**Description<a name="section116271631195017"></a>**

Queries the PCIe bandwidth between the NPU and host OS in a specified sampling time.

**Parameter Description<a name="section11627103114506"></a>**

<a name="table196551731155016"></a>
<table><thead align="left"><tr id="row6708031165017"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p17708123120507"><a name="p17708123120507"></a><a name="p17708123120507"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p13708143185017"><a name="p13708143185017"></a><a name="p13708143185017"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p67081031185017"><a name="p67081031185017"></a><a name="p67081031185017"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p3708131145014"><a name="p3708131145014"></a><a name="p3708131145014"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row270819311506"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p3708193115501"><a name="p3708193115501"></a><a name="p3708193115501"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1170863112507"><a name="p1170863112507"></a><a name="p1170863112507"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p17081231205013"><a name="p17081231205013"></a><a name="p17081231205013"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p27082313505"><a name="p27082313505"></a><a name="p27082313505"></a>Device ID. The supported IDs can be obtained by calling <strong id="b387194178102834"><a name="b387194178102834"></a><a name="b387194178102834"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b76673498910254"><a name="b76673498910254"></a><a name="b76673498910254"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU chip: [0, <strong id="b1269379018111939"><a name="b1269379018111939"></a><a name="b1269379018111939"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row1170919312507"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p2709331125015"><a name="p2709331125015"></a><a name="p2709331125015"></a>pcie_link_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p5709153165015"><a name="p5709153165015"></a><a name="p5709153165015"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p270923119508"><a name="p270923119508"></a><a name="p270923119508"></a>dcmi_pcie_link_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p147094314502"><a name="p147094314502"></a><a name="p147094314502"></a>struct dcmi_pcie_link_bandwidth_info {</p>
<p id="p15709103111504"><a name="p15709103111504"></a><a name="p15709103111504"></a>int profiling_time; // Control the profiling time, which is input.</p>
<p id="p8709731105013"><a name="p8709731105013"></a><a name="p8709731105013"></a>unsigned int tx_p_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to write data to the remote end, which is output</p>
<p id="p5709431135014"><a name="p5709431135014"></a><a name="p5709431135014"></a>unsigned int tx_np_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to read data from the remote end, which is output</p>
<p id="p770913120509"><a name="p770913120509"></a><a name="p770913120509"></a>unsigned int tx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; // CPL bandwidth for the device to respond to the remote read operation, which is output</p>
<p id="p67096319500"><a name="p67096319500"></a><a name="p67096319500"></a>unsigned int tx_np_lantency[AGENTDRV_PROF_DATA_NUM];</p>
<p id="p18709631165013"><a name="p18709631165013"></a><a name="p18709631165013"></a>// Latency (ns) for the device to read data from the remote end, which is output</p>
<p id="p19709173185010"><a name="p19709173185010"></a><a name="p19709173185010"></a>unsigned int rx_p_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to receive remote write requests, which is output</p>
<p id="p15709631135012"><a name="p15709631135012"></a><a name="p15709631135012"></a>unsigned int rx_np_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to receive remote read requests, which is output</p>
<p id="p27091312507"><a name="p27091312507"></a><a name="p27091312507"></a>unsigned int rx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; // Bandwidth for the device to read the CPL response from the remote end, which is output</p>
<p id="p5709173115012"><a name="p5709173115012"></a><a name="p5709173115012"></a>};</p>
<p id="p157098315509"><a name="p157098315509"></a><a name="p157098315509"></a>Value range of <strong id="b295952482411"><a name="b295952482411"></a><a name="b295952482411"></a>profiling_time</strong>: 0 ms to 2000 ms</p>
<p id="p207091631185018"><a name="p207091631185018"></a><a name="p207091631185018"></a>Bandwidth unit: MB/ms</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b195129978285623"><a name="b195129978285623"></a><a name="b195129978285623"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section1464620315507"></a>**

None.

**Restrictions<a name="section364683165017"></a>**

- The data of this API is meaningless when profiling is enabled.
- This API can be used in PM + privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table1831828113412"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row19901425175211"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p1555917570362"><a name="en-us_topic_0000002515503852_p1555917570362"></a><a name="en-us_topic_0000002515503852_p1555917570362"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p201384912311"><a name="en-us_topic_0000002515503852_p201384912311"></a><a name="en-us_topic_0000002515503852_p201384912311"></a><strong id="en-us_topic_0000002515503852_b446915610411"><a name="en-us_topic_0000002515503852_b446915610411"></a><a name="en-us_topic_0000002515503852_b446915610411"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p513124915316"><a name="en-us_topic_0000002515503852_p513124915316"></a><a name="en-us_topic_0000002515503852_p513124915316"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b18560720419"><a name="en-us_topic_0000002515503852_b18560720419"></a><a name="en-us_topic_0000002515503852_b18560720419"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p1131549173112"><a name="en-us_topic_0000002515503852_p1131549173112"></a><a name="en-us_topic_0000002515503852_p1131549173112"></a><strong id="en-us_topic_0000002515503852_b14967981844"><a name="en-us_topic_0000002515503852_b14967981844"></a><a name="en-us_topic_0000002515503852_b14967981844"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p232525365317"><a name="en-us_topic_0000002515503852_p232525365317"></a><a name="en-us_topic_0000002515503852_p232525365317"></a><span id="en-us_topic_0000002515503852_ph3325165314533"><a name="en-us_topic_0000002515503852_ph3325165314533"></a><a name="en-us_topic_0000002515503852_ph3325165314533"></a><span id="en-us_topic_0000002515503852_text2032565316533"><a name="en-us_topic_0000002515503852_text2032565316533"></a><a name="en-us_topic_0000002515503852_text2032565316533"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001777715122_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p33251753135313"><a name="en-us_topic_0000002515503852_p33251753135313"></a><a name="en-us_topic_0000002515503852_p33251753135313"></a><span id="en-us_topic_0000002515503852_text232555315538"><a name="en-us_topic_0000002515503852_text232555315538"></a><a name="en-us_topic_0000002515503852_text232555315538"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p862174514211"><a name="en-us_topic_0000002515503852_p862174514211"></a><a name="en-us_topic_0000002515503852_p862174514211"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p12621104519215"><a name="en-us_topic_0000002515503852_p12621104519215"></a><a name="en-us_topic_0000002515503852_p12621104519215"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p6621204519220"><a name="en-us_topic_0000002515503852_p6621204519220"></a><a name="en-us_topic_0000002515503852_p6621204519220"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row293019912529"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p532515315535"><a name="en-us_topic_0000002515503852_p532515315535"></a><a name="en-us_topic_0000002515503852_p532515315535"></a><span id="en-us_topic_0000002515503852_text732545315315"><a name="en-us_topic_0000002515503852_text732545315315"></a><a name="en-us_topic_0000002515503852_text732545315315"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p386884075314"><a name="en-us_topic_0000002515503852_p386884075314"></a><a name="en-us_topic_0000002515503852_p386884075314"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p12868184075310"><a name="en-us_topic_0000002515503852_p12868184075310"></a><a name="en-us_topic_0000002515503852_p12868184075310"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p986814025319"><a name="en-us_topic_0000002515503852_p986814025319"></a><a name="en-us_topic_0000002515503852_p986814025319"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row29531122175210"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1832516539533"><a name="en-us_topic_0000002515503852_p1832516539533"></a><a name="en-us_topic_0000002515503852_p1832516539533"></a><span id="en-us_topic_0000002515503852_text143251353185313"><a name="en-us_topic_0000002515503852_text143251353185313"></a><a name="en-us_topic_0000002515503852_text143251353185313"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16576467538"><a name="en-us_topic_0000002515503852_p16576467538"></a><a name="en-us_topic_0000002515503852_p16576467538"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13657346135315"><a name="en-us_topic_0000002515503852_p13657346135315"></a><a name="en-us_topic_0000002515503852_p13657346135315"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p10657164695315"><a name="en-us_topic_0000002515503852_p10657164695315"></a><a name="en-us_topic_0000002515503852_p10657164695315"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row2737141919528"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1632695317538"><a name="en-us_topic_0000002515503852_p1632695317538"></a><a name="en-us_topic_0000002515503852_p1632695317538"></a><span id="en-us_topic_0000002515503852_text532612537537"><a name="en-us_topic_0000002515503852_text532612537537"></a><a name="en-us_topic_0000002515503852_text532612537537"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1844654714531"><a name="en-us_topic_0000002515503852_p1844654714531"></a><a name="en-us_topic_0000002515503852_p1844654714531"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p64461747205318"><a name="en-us_topic_0000002515503852_p64461747205318"></a><a name="en-us_topic_0000002515503852_p64461747205318"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1446184725320"><a name="en-us_topic_0000002515503852_p1446184725320"></a><a name="en-us_topic_0000002515503852_p1446184725320"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row78171617135218"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p3326853195318"><a name="en-us_topic_0000002515503852_p3326853195318"></a><a name="en-us_topic_0000002515503852_p3326853195318"></a><span id="en-us_topic_0000002515503852_text912513032714"><a name="en-us_topic_0000002515503852_text912513032714"></a><a name="en-us_topic_0000002515503852_text912513032714"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p2967114725312"><a name="en-us_topic_0000002515503852_p2967114725312"></a><a name="en-us_topic_0000002515503852_p2967114725312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1396754795312"><a name="en-us_topic_0000002515503852_p1396754795312"></a><a name="en-us_topic_0000002515503852_p1396754795312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p596734725316"><a name="en-us_topic_0000002515503852_p596734725316"></a><a name="en-us_topic_0000002515503852_p596734725316"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1913121595213"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p532613533533"><a name="en-us_topic_0000002515503852_p532613533533"></a><a name="en-us_topic_0000002515503852_p532613533533"></a><span id="en-us_topic_0000002515503852_text332611538530"><a name="en-us_topic_0000002515503852_text332611538530"></a><a name="en-us_topic_0000002515503852_text332611538530"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1452484814533"><a name="en-us_topic_0000002515503852_p1452484814533"></a><a name="en-us_topic_0000002515503852_p1452484814533"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p19524174835320"><a name="en-us_topic_0000002515503852_p19524174835320"></a><a name="en-us_topic_0000002515503852_p19524174835320"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652419482532"><a name="en-us_topic_0000002515503852_p652419482532"></a><a name="en-us_topic_0000002515503852_p652419482532"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row71831758163218"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p28486114331"><a name="en-us_topic_0000002515503852_p28486114331"></a><a name="en-us_topic_0000002515503852_p28486114331"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section13653173113509"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
struct dcmi_pcie_link_bandwidth_info bandwidth_info = {0};
bandwidth_info.profiling_time = 1000;
ret = dcmi_get_pcie_link_bandwidth_info(card_id, device_id, &bandwidth_info);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

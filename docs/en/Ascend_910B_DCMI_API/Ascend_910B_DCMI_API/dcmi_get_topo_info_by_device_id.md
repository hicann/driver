# dcmi\_get\_topo\_info\_by\_device\_id<a name="EN-US_TOPIC_0000002546983787"></a>

**Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>**

**int dcmi\_get\_topo\_info\_by\_device\_id \(int card\_id1, int device\_id1, int card\_id2, int device\_id2, int \* topo\_type\)**

**Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>**

Queries the topology between two specified devices.

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
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1290353951711"><a name="p1290353951711"></a><a name="p1290353951711"></a>card_id1/card_id2</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p13903193920176"><a name="p13903193920176"></a><a name="p13903193920176"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p09048390172"><a name="p09048390172"></a><a name="p09048390172"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p119041539161713"><a name="p119041539161713"></a><a name="p119041539161713"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1268116654102835"><a name="b1268116654102835"></a><a name="b1268116654102835"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row1684271132614"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>device_id1/device_id2</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p870915316504"><a name="p870915316504"></a><a name="p870915316504"></a>Chip ID, which can be obtained by calling <strong id="b168929320710255"><a name="b168929320710255"></a><a name="b168929320710255"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU chip: [0, <strong id="b238515383111940"><a name="b238515383111940"></a><a name="b238515383111940"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row5354192415172"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p39441927132615"><a name="p39441927132615"></a><a name="p39441927132615"></a>topo_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p199442273269"><a name="p199442273269"></a><a name="p199442273269"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p538713432265"><a name="p538713432265"></a><a name="p538713432265"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p294414276267"><a name="p294414276267"></a><a name="p294414276267"></a>Topology relationship between devices. The mapping is as follows:</p>
<p id="p25631025124616"><a name="p25631025124616"></a><a name="p25631025124616"></a>typedef enum {</p>
<p id="p2511174233616"><a name="p2511174233616"></a><a name="p2511174233616"></a>DCMI_TOPO_TYPE_SELF = 0, // Chip</p>
<p id="p195111142113610"><a name="p195111142113610"></a><a name="p195111142113610"></a>DCMI_TOPO_TYPE_SYS, // Indicates the path traversing PCIe and NUMA nodes. The nodes are connected through SMP, such as QPI and UPI.</p>
<p id="p19511114293612"><a name="p19511114293612"></a><a name="p19511114293612"></a>DCMI_TOPO_TYPE_PHB, // Indicates the path traversing PCIe and the PCIe host bridge of the same CPU.</p>
<p id="p9511124233615"><a name="p9511124233615"></a><a name="p9511124233615"></a>DCMI_TOPO_TYPE_HCCS, // Indicates connection through HCCS.</p>
<p id="p1351164218365"><a name="p1351164218365"></a><a name="p1351164218365"></a>DCMI_TOPO_TYPE_PXB, // Indicates the path traversing PCIe and multiple PCIe switches.</p>
<p id="p1851114243611"><a name="p1851114243611"></a><a name="p1851114243611"></a>DCMI_TOPO_TYPE_PIX, // Indicates the path traversing PCIe and a PCIe switch.</p>
<p id="p212771911216"><a name="p212771911216"></a><a name="p212771911216"></a>DCMI_TOPO_TYPE_BUTT = 6, // The mapping is unknown.</p>
<p id="p976131345320"><a name="p976131345320"></a><a name="p976131345320"></a>DCMI_TOPO_TYOE_MAX,</p>
<p id="p1959153111466"><a name="p1959153111466"></a><a name="p1959153111466"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b118120587085624"><a name="b118120587085624"></a><a name="b118120587085624"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>**

```c
...
int ret = 0;
int card_id1 = 0;
int card_id2 = 1;
int device_id1 = 0;
int device_id2 = 1;
int result;
ret = dcmi_get_topo_info_by_device_id(card_id1, device_id1, card_id2, device_id2, &result); 
...
```

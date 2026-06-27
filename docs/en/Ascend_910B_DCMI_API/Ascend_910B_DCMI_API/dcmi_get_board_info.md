# dcmi\_get\_board\_info<a name="EN-US_TOPIC_0000002515503826"></a>

**Prototype<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_toc533412077"></a>**

**int dcmi\_get\_board\_info\(int card\_id, int device\_id, struct dcmi\_board\_info\_stru \*board\_info\)**

**Description<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_toc533412078"></a>**

Obtains the board information of a device.

**Parameter Description<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_toc533412079"></a>**

<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p10021890"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p10021890"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p6466753"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p6466753"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p54045009"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p54045009"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p15569626"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p15569626"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p36741947142813"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p36741947142813"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p96741747122818"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p96741747122818"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p46747472287"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p46747472287"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1467413474281"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1467413474281"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1890838431102339"><a name="b1890838431102339"></a><a name="b1890838431102339"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p7711145152918"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p7711145152918"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p671116522914"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p671116522914"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1771116572910"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1771116572910"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"></a>Chip ID, which can be obtained by calling <strong id="b1634905898102345"><a name="b1634905898102345"></a><a name="b1634905898102345"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"></a>NPU: [0, <strong id="b1286086720105246"><a name="b1286086720105246"></a><a name="b1286086720105246"></a>device_id_max</strong> – 1]</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_p46986266814"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_p46986266814"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_en-us_topic_0000001147723703_p46986266814"></a>MCU: <strong id="b14248810586042"><a name="b14248810586042"></a><a name="b14248810586042"></a>mcu_id</strong></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p5262129152913"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p5262129152913"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p5262129152913"></a>board_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1926232982914"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1926232982914"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1926232982914"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p826217292293"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p826217292293"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p826217292293"></a>struct dcmi_board_info_stru*</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1018413955820"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1018413955820"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p1018413955820"></a>Board information.</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p13341121818310"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p13341121818310"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p13341121818310"></a>struct dcmi_board_info_stru {</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p2034115185312"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p2034115185312"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p2034115185312"></a>unsigned int board_id; // Board ID</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p23411718135"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p23411718135"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p23411718135"></a>unsigned int pcb_id; // PCB ID</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p73418187312"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p73418187312"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p73418187312"></a>unsigned int bom_id; // BOM ID</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p18341111820311"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p18341111820311"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p18341111820311"></a>unsigned int slot_id; // Slot ID</p>
<p id="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p113415181316"><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p113415181316"></a><a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_p113415181316"></a>};</p>
<div class="p" id="p238984920105"><a name="p238984920105"></a><a name="p238984920105"></a>PM scenarios:<a name="ul52841650114714"></a><a name="ul52841650114714"></a><ul id="ul52841650114714"><li>If <strong id="b3932525049835"><a name="b3932525049835"></a><a name="b3932525049835"></a>device_id</strong> is the chip ID of an NPU, only <strong id="b422692639835"><a name="b422692639835"></a><a name="b422692639835"></a>board_id</strong> and <strong id="b8475820129835"><a name="b8475820129835"></a><a name="b8475820129835"></a>slot_id</strong> are valid, between which <strong id="b1397240979835"><a name="b1397240979835"></a><a name="b1397240979835"></a>slot_id</strong> indicates the PCIe slot where the chip is located.</li><li>If <strong id="b843011307917"><a name="b843011307917"></a><a name="b843011307917"></a>device_id</strong> is the MCU chip ID, <strong id="b04301730493"><a name="b04301730493"></a><a name="b04301730493"></a>board_id</strong>, <strong id="b54303301597"><a name="b54303301597"></a><a name="b54303301597"></a>pcb_id</strong>, <strong id="b1443017300916"><a name="b1443017300916"></a><a name="b1443017300916"></a>bom_id</strong>, and <strong id="b64301730599"><a name="b64301730599"></a><a name="b64301730599"></a>slot_id</strong> are valid, among which <strong id="b143013309918"><a name="b143013309918"></a><a name="b143013309918"></a>slot_id</strong> indicates the position of the chip on the card.</li></ul>
</div>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b18928382098554"><a name="b18928382098554"></a><a name="b18928382098554"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_toc533412082"></a>**

This API will be deleted from later versions. You are advised to use  [dcmi\_get\_device\_board\_info](dcmi_get_device_board_info.md).

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

**Example<a name="en-us_topic_0000001251107215_en-us_topic_0000001223292869_en-us_topic_0000001114167494_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
struct dcmi_board_info_stru board_info = {0};
ret = dcmi_get_board_info(card_id, device_id, &board_info);
...
```

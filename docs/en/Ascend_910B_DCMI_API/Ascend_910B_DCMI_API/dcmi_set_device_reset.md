# dcmi\_set\_device\_reset<a name="EN-US_TOPIC_0000002515343958"></a>

**Prototype<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412077"></a>**

**int dcmi\_set\_device\_reset\(int card\_id, int device\_id, enum dcmi\_reset\_channel channel\_type\)**

**Description<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412078"></a>**

Resets a chip.

**Parameter Description<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412079"></a>**

<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p36741947142813"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p36741947142813"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p96741747122818"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p96741747122818"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p46747472287"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p46747472287"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1918045644117"><a name="b1918045644117"></a><a name="b1918045644117"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b225115824110"><a name="b225115824110"></a><a name="b225115824110"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p10757141201716"><a name="p10757141201716"></a><a name="p10757141201716"></a>NPU: [0, <strong id="b95822112105419"><a name="b95822112105419"></a><a name="b95822112105419"></a>device_id_max</strong> – 1]</p>
<p id="p1662044105817"><a name="p1662044105817"></a><a name="p1662044105817"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row137415397316"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"></a>channel_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"></a>enum dcmi_reset_channel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"></a>Reset channel.</p>
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p136522222313"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p136522222313"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p136522222313"></a>enum dcmi_reset_channel {</p>
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p365822172318"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p365822172318"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p365822172318"></a>OUTBAND_CHANNEL = 0, // Out-of-band reset</p>
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"></a>INBAND_CHANNEL // In-band reset</p>
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"></a>}</p>
<p id="p421168115817"><a name="p421168115817"></a><a name="p421168115817"></a></p>
<div class="note" id="note20188544163013"><a name="note20188544163013"></a><a name="note20188544163013"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul19530122133511"></a><a name="ul19530122133511"></a><ul id="ul19530122133511"><li>The <span id="text18400119121915"><a name="text18400119121915"></a><a name="text18400119121915"></a>Atlas 200T A2 Box16 heterogeneous subrackA200T A2 Box16 heterogeneous subrack</span> and <span id="ph1400179151912"><a name="ph1400179151912"></a><a name="ph1400179151912"></a><span id="text204001491198"><a name="text204001491198"></a><a name="text204001491198"></a>Atlas 900 A2 PoD cluster basic unitA900 A2 PoD cluster basic unit</span></span> support <strong id="b194016912190"><a name="b194016912190"></a><a name="b194016912190"></a>INBAND_CHANNEL</strong>.</li><li>The <span id="text1415604354018"><a name="text1415604354018"></a><a name="text1415604354018"></a>A300I A2 inference card</span> and <span id="text1627131293511"><a name="text1627131293511"></a><a name="text1627131293511"></a>Atlas 300T A2 training cardA300T A2 training card</span> support <strong id="b48088421911"><a name="b48088421911"></a><a name="b48088421911"></a>OUTBAND_CHANNEL</strong>.</li></ul>
</div></div>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002515343916_b154714878985455"><a name="en-us_topic_0000002515343916_b154714878985455"></a><a name="en-us_topic_0000002515343916_b154714878985455"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="./return-codes.md">en-us_topic_0000002515343924.md</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412082"></a>**

- The standard PCIe card reset function in out-of-band mode depends on IPMItool. Download the tool and load the driver in advance. For details, see [Preparing IPMItool](faqs.md).

- For the A300I A2 inference card and Atlas 300T A2 training cardA300T A2 training card, this API can be called to perform an out-of-band reset only after  [dcmi\_set\_device\_pre\_reset](dcmi_set_device_pre_reset.md)  is called to pre-reset the chip and a success message is returned.
- For the  Atlas 900 A2 PoD cluster basic unitA900 A2 PoD cluster basic unit  and Atlas 200T A2 Box16 heterogeneous subrackA200T A2 Box16 heterogeneous subrack, the NPU that is started normally does not support single NPU reset. If some NPUs on the same device are isolated and some are started normally, the isolated NPUs support single NPU reset, while the NPUs that are started normally do not support it. That is, when the reset command for a single NPU is executed, all NPUs, including the isolated NPUs, are reset.
- This API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row192401338610"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p6884135713319"><a name="en-us_topic_0000002515503852_p6884135713319"></a><a name="en-us_topic_0000002515503852_p6884135713319"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p188841657113119"><a name="en-us_topic_0000002515503852_p188841657113119"></a><a name="en-us_topic_0000002515503852_p188841657113119"></a><strong id="en-us_topic_0000002515503852_b1680418281142"><a name="en-us_topic_0000002515503852_b1680418281142"></a><a name="en-us_topic_0000002515503852_b1680418281142"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p198849575317"><a name="en-us_topic_0000002515503852_p198849575317"></a><a name="en-us_topic_0000002515503852_p198849575317"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b9295305413"><a name="en-us_topic_0000002515503852_b9295305413"></a><a name="en-us_topic_0000002515503852_b9295305413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p288445716317"><a name="en-us_topic_0000002515503852_p288445716317"></a><a name="en-us_topic_0000002515503852_p288445716317"></a><strong id="en-us_topic_0000002515503852_b17190133113410"><a name="en-us_topic_0000002515503852_b17190133113410"></a><a name="en-us_topic_0000002515503852_b17190133113410"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unitA900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training serverA800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference serverA800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrackA200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18619541161"><a name="en-us_topic_0000002515503852_p18619541161"></a><a name="en-us_topic_0000002515503852_p18619541161"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2864541766"><a name="en-us_topic_0000002515503852_p2864541766"></a><a name="en-us_topic_0000002515503852_p2864541766"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1186854962"><a name="en-us_topic_0000002515503852_p1186854962"></a><a name="en-us_topic_0000002515503852_p1186854962"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row283215811614"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p12591202014711"><a name="en-us_topic_0000002515503852_p12591202014711"></a><a name="en-us_topic_0000002515503852_p12591202014711"></a><span id="en-us_topic_0000002515503852_text65911120871"><a name="en-us_topic_0000002515503852_text65911120871"></a><a name="en-us_topic_0000002515503852_text65911120871"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15638154267"><a name="en-us_topic_0000002515503852_p15638154267"></a><a name="en-us_topic_0000002515503852_p15638154267"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18638354369"><a name="en-us_topic_0000002515503852_p18638354369"></a><a name="en-us_topic_0000002515503852_p18638354369"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p16638154060"><a name="en-us_topic_0000002515503852_p16638154060"></a><a name="en-us_topic_0000002515503852_p16638154060"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1057696667"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p959110201477"><a name="en-us_topic_0000002515503852_p959110201477"></a><a name="en-us_topic_0000002515503852_p959110201477"></a><span id="en-us_topic_0000002515503852_text7981112472810"><a name="en-us_topic_0000002515503852_text7981112472810"></a><a name="en-us_topic_0000002515503852_text7981112472810"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p18230255869"><a name="en-us_topic_0000002515503852_p18230255869"></a><a name="en-us_topic_0000002515503852_p18230255869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123055512620"><a name="en-us_topic_0000002515503852_p123055512620"></a><a name="en-us_topic_0000002515503852_p123055512620"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p623011552618"><a name="en-us_topic_0000002515503852_p623011552618"></a><a name="en-us_topic_0000002515503852_p623011552618"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training cardA300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p38158552616"><a name="en-us_topic_0000002515503852_p38158552616"></a><a name="en-us_topic_0000002515503852_p38158552616"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p18158552613"><a name="en-us_topic_0000002515503852_p18158552613"></a><a name="en-us_topic_0000002515503852_p18158552613"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19815255367"><a name="en-us_topic_0000002515503852_p19815255367"></a><a name="en-us_topic_0000002515503852_p19815255367"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row67064433311"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15712048183315"><a name="en-us_topic_0000002515503852_p15712048183315"></a><a name="en-us_topic_0000002515503852_p15712048183315"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
enum dcmi_reset_channel channel_type = INBAND_CHANNEL;
ret = dcmi_set_device_reset(card_id, device_id, channel_type);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}
…
```

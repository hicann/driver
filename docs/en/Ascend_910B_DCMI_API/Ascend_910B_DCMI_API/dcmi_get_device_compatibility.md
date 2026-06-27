# dcmi\_get\_device\_compatibility<a name="EN-US_TOPIC_0000002546903701"></a>

**Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>**

**int dcmi\_get\_device\_compatibility \(int card\_id, int device\_id, enum dcmi\_device\_compat \*compatibility\)**

**Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>**

Queries the compatibility between the NPU driver and firmware.

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
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p36741947142813"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p36741947142813"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p96741747122818"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p96741747122818"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p46747472287"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p46747472287"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1467413474281"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1467413474281"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b586140507102832"><a name="b586140507102832"></a><a name="b586140507102832"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p7711145152918"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p7711145152918"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p671116522914"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p671116522914"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1771116572910"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1771116572910"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b108731692310252"><a name="b108731692310252"></a><a name="b108731692310252"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b1410579271105349"><a name="b1410579271105349"></a><a name="b1410579271105349"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="row427910719196"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p753616536191"><a name="p753616536191"></a><a name="p753616536191"></a>compatibility</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p45363532194"><a name="p45363532194"></a><a name="p45363532194"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p453695381911"><a name="p453695381911"></a><a name="p453695381911"></a>enum dcmi_device_compat *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p14536195311912"><a name="p14536195311912"></a><a name="p14536195311912"></a>enum dcmi_device_compat{</p>
<p id="p115365533199"><a name="p115365533199"></a><a name="p115365533199"></a>DCMI_COMPAT_OK = 1,</p>
<p id="p453625319193"><a name="p453625319193"></a><a name="p453625319193"></a>DCMI_COMPAT_NOK = 2,</p>
<p id="p145361553101913"><a name="p145361553101913"></a><a name="p145361553101913"></a>DCMI_COMPAT_UNKNOWN = 3</p>
<p id="p195366537192"><a name="p195366537192"></a><a name="p195366537192"></a>};</p>
<p id="p5536195314195"><a name="p5536195314195"></a><a name="p5536195314195"></a>The returned information is described as follows:</p>
<a name="ul1694121910205"></a><a name="ul1694121910205"></a><ul id="ul1694121910205"><li><strong id="b304167322877"><a name="b304167322877"></a><a name="b304167322877"></a>DCMI_COMPAT_OK (1)</strong>: The NPU driver is compatible with the NPU firmware.</li><li><strong id="b1808637908877"><a name="b1808637908877"></a><a name="b1808637908877"></a>DCMI_COMPAT_NOK (2)</strong>: The NPU driver is incompatible with the NPU firmware.</li><li><strong id="b1097172833877"><a name="b1097172833877"></a><a name="b1097172833877"></a>DCMI_COMPAT_UNKNOWN (3)</strong>: The mapping between the NPU driver and NPU firmware is unknown.</li></ul>
<div class="note" id="note65601038132011"><a name="note65601038132011"></a><a name="note65601038132011"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p18560103802012"><a name="p18560103802012"></a><a name="p18560103802012"></a>When an exception occurs during the installation or upgrade of the firmware RUN package, or when the firmware RUN package of a version earlier than NPU 23.0.RC2 is used, <strong id="b745410118197"><a name="b745410118197"></a><a name="b745410118197"></a>DCMI_COMPAT_UNKNOWN</strong> occurs.</p>
</div></div>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b146260136485621"><a name="b146260136485621"></a><a name="b146260136485621"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

The installation and upgrade of the NPU firmware and driver must take effect before this API is called.

**Table  1** Support in different deployment scenarios

<a name="table36641225112113"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row11448141417420"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p1713218513317"><a name="en-us_topic_0000002515503852_p1713218513317"></a><a name="en-us_topic_0000002515503852_p1713218513317"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p213245123114"><a name="en-us_topic_0000002515503852_p213245123114"></a><a name="en-us_topic_0000002515503852_p213245123114"></a><strong id="en-us_topic_0000002515503852_b10699121316416"><a name="en-us_topic_0000002515503852_b10699121316416"></a><a name="en-us_topic_0000002515503852_b10699121316416"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="24.97%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p13132115113113"><a name="en-us_topic_0000002515503852_p13132115113113"></a><a name="en-us_topic_0000002515503852_p13132115113113"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b20722171412415"><a name="en-us_topic_0000002515503852_b20722171412415"></a><a name="en-us_topic_0000002515503852_b20722171412415"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25.03%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p8132185173115"><a name="en-us_topic_0000002515503852_p8132185173115"></a><a name="en-us_topic_0000002515503852_p8132185173115"></a><strong id="en-us_topic_0000002515503852_b1617141511413"><a name="en-us_topic_0000002515503852_b1617141511413"></a><a name="en-us_topic_0000002515503852_b1617141511413"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_row728313421182"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13757328759"><a name="en-us_topic_0000002515503852_p13757328759"></a><a name="en-us_topic_0000002515503852_p13757328759"></a><span id="en-us_topic_0000002515503852_ph375715283511"><a name="en-us_topic_0000002515503852_ph375715283511"></a><a name="en-us_topic_0000002515503852_ph375715283511"></a><span id="en-us_topic_0000002515503852_text147574281354"><a name="en-us_topic_0000002515503852_text147574281354"></a><a name="en-us_topic_0000002515503852_text147574281354"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p11366163913135"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p14366113915138"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001206467216_en-us_topic_0000001178373140_en-us_topic_0000001101617122_p8366173991316"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row12848477419"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p47571728152"><a name="en-us_topic_0000002515503852_p47571728152"></a><a name="en-us_topic_0000002515503852_p47571728152"></a><span id="en-us_topic_0000002515503852_text57571728359"><a name="en-us_topic_0000002515503852_text57571728359"></a><a name="en-us_topic_0000002515503852_text57571728359"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p28504223417"><a name="en-us_topic_0000002515503852_p28504223417"></a><a name="en-us_topic_0000002515503852_p28504223417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p17850172220413"><a name="en-us_topic_0000002515503852_p17850172220413"></a><a name="en-us_topic_0000002515503852_p17850172220413"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1385072213414"><a name="en-us_topic_0000002515503852_p1385072213414"></a><a name="en-us_topic_0000002515503852_p1385072213414"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row118411919445"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p177571128653"><a name="en-us_topic_0000002515503852_p177571128653"></a><a name="en-us_topic_0000002515503852_p177571128653"></a><span id="en-us_topic_0000002515503852_text15757628450"><a name="en-us_topic_0000002515503852_text15757628450"></a><a name="en-us_topic_0000002515503852_text15757628450"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p15469122314417"><a name="en-us_topic_0000002515503852_p15469122314417"></a><a name="en-us_topic_0000002515503852_p15469122314417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p74698234414"><a name="en-us_topic_0000002515503852_p74698234414"></a><a name="en-us_topic_0000002515503852_p74698234414"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p346911236418"><a name="en-us_topic_0000002515503852_p346911236418"></a><a name="en-us_topic_0000002515503852_p346911236418"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1888071710410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p375752819516"><a name="en-us_topic_0000002515503852_p375752819516"></a><a name="en-us_topic_0000002515503852_p375752819516"></a><span id="en-us_topic_0000002515503852_text157571128457"><a name="en-us_topic_0000002515503852_text157571128457"></a><a name="en-us_topic_0000002515503852_text157571128457"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1211817247419"><a name="en-us_topic_0000002515503852_p1211817247419"></a><a name="en-us_topic_0000002515503852_p1211817247419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15118112412418"><a name="en-us_topic_0000002515503852_p15118112412418"></a><a name="en-us_topic_0000002515503852_p15118112412418"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p71183241449"><a name="en-us_topic_0000002515503852_p71183241449"></a><a name="en-us_topic_0000002515503852_p71183241449"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1276811111414"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p107581228856"><a name="en-us_topic_0000002515503852_p107581228856"></a><a name="en-us_topic_0000002515503852_p107581228856"></a><span id="en-us_topic_0000002515503852_text37581282519"><a name="en-us_topic_0000002515503852_text37581282519"></a><a name="en-us_topic_0000002515503852_text37581282519"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p120113251649"><a name="en-us_topic_0000002515503852_p120113251649"></a><a name="en-us_topic_0000002515503852_p120113251649"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p620114251847"><a name="en-us_topic_0000002515503852_p620114251847"></a><a name="en-us_topic_0000002515503852_p620114251847"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1120117251241"><a name="en-us_topic_0000002515503852_p1120117251241"></a><a name="en-us_topic_0000002515503852_p1120117251241"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row262419543"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19758182817512"><a name="en-us_topic_0000002515503852_p19758182817512"></a><a name="en-us_topic_0000002515503852_p19758182817512"></a><span id="en-us_topic_0000002515503852_text191152014162710"><a name="en-us_topic_0000002515503852_text191152014162710"></a><a name="en-us_topic_0000002515503852_text191152014162710"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p59851728544"><a name="en-us_topic_0000002515503852_p59851728544"></a><a name="en-us_topic_0000002515503852_p59851728544"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p11985828244"><a name="en-us_topic_0000002515503852_p11985828244"></a><a name="en-us_topic_0000002515503852_p11985828244"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p169851228148"><a name="en-us_topic_0000002515503852_p169851228148"></a><a name="en-us_topic_0000002515503852_p169851228148"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1994411513415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p97581828659"><a name="en-us_topic_0000002515503852_p97581828659"></a><a name="en-us_topic_0000002515503852_p97581828659"></a><span id="en-us_topic_0000002515503852_text20758132816511"><a name="en-us_topic_0000002515503852_text20758132816511"></a><a name="en-us_topic_0000002515503852_text20758132816511"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p16036297418"><a name="en-us_topic_0000002515503852_p16036297418"></a><a name="en-us_topic_0000002515503852_p16036297418"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="24.97%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p8603182911412"><a name="en-us_topic_0000002515503852_p8603182911412"></a><a name="en-us_topic_0000002515503852_p8603182911412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25.03%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96032298411"><a name="en-us_topic_0000002515503852_p96032298411"></a><a name="en-us_topic_0000002515503852_p96032298411"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row9870431183314"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p242563973319"><a name="en-us_topic_0000002515503852_p242563973319"></a><a name="en-us_topic_0000002515503852_p242563973319"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>**

```C
int ret = 0;
int card_id = 0;
int device_id = 0;
enum dcmi_device_compat compatibility = DCMI_COMPAT_UNKNOWN;
ret = dcmi_get_device_compatibility (card_id, device_id, & compatibility);
...
```

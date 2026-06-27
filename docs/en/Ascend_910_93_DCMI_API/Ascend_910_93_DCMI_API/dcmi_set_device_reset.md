# dcmi\_set\_device\_reset<a name="EN-US_TOPIC_0000002546910365"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b34009695181658"><a name="b34009695181658"></a><a name="b34009695181658"></a>dcmi_get_card_list</strong>.</p>
<div class="note" id="note9881134113272"><a name="note9881134113272"></a><a name="note9881134113272"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul6966185610185"></a><a name="ul6966185610185"></a><ul id="ul6966185610185"><li>When this API is used for an in-band chip reset, <strong id="b3583548115410"><a name="b3583548115410"></a><a name="b3583548115410"></a>card_id</strong> can be set to <strong id="b197541551165415"><a name="b197541551165415"></a><a name="b197541551165415"></a>0xFF</strong> to initiate a full-card reset. This functionality is supported in the PM, i.e., the bare-metal scenario (running as <strong id="b108161110175518"><a name="b108161110175518"></a><a name="b108161110175518"></a>root</strong>) and in the PM + privileged container scenario.</li><li>When this API is used for an out-of-band chip reset, <strong id="b201218290781658"><a name="b201218290781658"></a><a name="b201218290781658"></a>card_id</strong> cannot be set to <strong id="b12495002981658"><a name="b12495002981658"></a><a name="b12495002981658"></a>0xFF</strong>.</li></ul>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b42390961533139"><a name="b42390961533139"></a><a name="b42390961533139"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="p10757141201716"><a name="p10757141201716"></a><a name="p10757141201716"></a>NPU: [0, <strong id="b13152534314"><a name="b13152534314"></a><a name="b13152534314"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
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
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3662222235"></a>INBAND_CHANNEL = 1 // In-band reset</p>
<p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1066112202319"></a>}</p>
<div class="note" id="note20188544163013"><a name="note20188544163013"></a><a name="note20188544163013"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p159001111195110"><a name="p159001111195110"></a><a name="p159001111195110"></a><span id="text910053102312"><a name="text910053102312"></a><a name="text910053102312"></a>A200T A3 Box8 SuperPoD server</span> does not support <strong id="b2346102782612"><a name="b2346102782612"></a><a name="b2346102782612"></a>OUTBAND_CHANNEL</strong>.</p>
</div></div>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b17196326777517"><a name="b17196326777517"></a><a name="b17196326777517"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412082"></a>**

- The out-of-band chip reset function depends on ipmitool. Download the tool and load the driver in advance. For details, see  [Preparing IPMItool](faqs.md).
- iBMC 5.8.3.43 and later versions support out-of-band chip reset.
- Out-of-band chip reset depends on  [dcmi\_get\_device\_outband\_channel\_state](dcmi_get_device_outband_channel_state.md)  and  [dcmi\_pre\_reset\_soc](dcmi_pre_reset_soc.md). Ensure that the out-of-band channel is normal and the chip is successfully pre-reset before calling this API to reset the chip in out-of-band mode.
- Reset a specified chip: For the Atlas 9000 A3 SuperPoD Cluster Computing System, reset an NPU module where the specified chip is located. For the Atlas 900 A3 SuperPoD, Atlas 800T A3 SuperPoD, Atlas 800I A3 SuperPoD, and A200T A3 Box8 SuperPoD server, reset an NPU module where the specified chip is located and an NPU module that has the network port cooperation relationship with it. For details about the modules that have network port cooperation relationships, see  [dcmi\_get\_netdev\_brother\_device](dcmi_get_netdev_brother_device.md).

- For the Atlas 9000 A3 SuperPoD Cluster Computing System, Atlas 900 A3 SuperPoD, Atlas 800T A3 SuperPoD, and Atlas 800I A3 SuperPoD, this API can be used in the Linux physical machine privileged container scenario. For the A200T A3 Box8 SuperPoD server, this API supports in-band chip reset in the Linux PM privileged containers, but does not support out-of-band chip reset in the Linux PM privileged containers.

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002165418008_row18113171210"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002165418008_p1881934126"><a name="en-us_topic_0000002165418008_p1881934126"></a><a name="en-us_topic_0000002165418008_p1881934126"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="p1153744312441"><a name="p1153744312441"></a><a name="p1153744312441"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002234309644_p92326610111"><a name="en-us_topic_0000002234309644_p92326610111"></a><a name="en-us_topic_0000002234309644_p92326610111"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002165418008_row681203121213"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002165418008_p11812310123"><a name="en-us_topic_0000002165418008_p11812310123"></a><a name="en-us_topic_0000002165418008_p11812310123"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002165418008_p188215311122"><a name="en-us_topic_0000002165418008_p188215311122"></a><a name="en-us_topic_0000002165418008_p188215311122"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002165418008_p58213311210"><a name="en-us_topic_0000002165418008_p58213311210"></a><a name="en-us_topic_0000002165418008_p58213311210"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002165418008_row38243131214"><td class="cellrowborder" valign="top" width="24.86%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002165418008_p48210361212"><a name="en-us_topic_0000002165418008_p48210361212"></a><a name="en-us_topic_0000002165418008_p48210361212"></a><span id="en-us_topic_0000002165418008_text16821238124"><a name="en-us_topic_0000002165418008_text16821238124"></a><a name="en-us_topic_0000002165418008_text16821238124"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25.14%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002165418008_p1990911717125"><a name="en-us_topic_0000002165418008_p1990911717125"></a><a name="en-us_topic_0000002165418008_p1990911717125"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002165418008_p1590914714124"><a name="en-us_topic_0000002165418008_p1590914714124"></a><a name="en-us_topic_0000002165418008_p1590914714124"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p750721011231"><a name="p750721011231"></a><a name="p750721011231"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002165418008_row982437122"><td class="cellrowborder" valign="top" width="24.86%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002165418008_p4829381220"><a name="en-us_topic_0000002165418008_p4829381220"></a><a name="en-us_topic_0000002165418008_p4829381220"></a><span id="en-us_topic_0000002165418008_text582173201218"><a name="en-us_topic_0000002165418008_text582173201218"></a><a name="en-us_topic_0000002165418008_text582173201218"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25.14%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002165418008_p59098719121"><a name="en-us_topic_0000002165418008_p59098719121"></a><a name="en-us_topic_0000002165418008_p59098719121"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002165418008_p20909197161211"><a name="en-us_topic_0000002165418008_p20909197161211"></a><a name="en-us_topic_0000002165418008_p20909197161211"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p9507171062314"><a name="p9507171062314"></a><a name="p9507171062314"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002165418008_row1782915383548"><td class="cellrowborder" valign="top" width="24.86%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002165418008_p1465274619544"><a name="en-us_topic_0000002165418008_p1465274619544"></a><a name="en-us_topic_0000002165418008_p1465274619544"></a><span id="en-us_topic_0000002165418008_text10652134635412"><a name="en-us_topic_0000002165418008_text10652134635412"></a><a name="en-us_topic_0000002165418008_text10652134635412"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25.14%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002165418008_p107731653135415"><a name="en-us_topic_0000002165418008_p107731653135415"></a><a name="en-us_topic_0000002165418008_p107731653135415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002165418008_p77730531545"><a name="en-us_topic_0000002165418008_p77730531545"></a><a name="en-us_topic_0000002165418008_p77730531545"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p14507121019238"><a name="p14507121019238"></a><a name="p14507121019238"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002165418008_row19683944122816"><td class="cellrowborder" valign="top" width="24.86%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002165418008_p19717154811286"><a name="en-us_topic_0000002165418008_p19717154811286"></a><a name="en-us_topic_0000002165418008_p19717154811286"></a><span id="en-us_topic_0000002165418008_text5717204812817"><a name="en-us_topic_0000002165418008_text5717204812817"></a><a name="en-us_topic_0000002165418008_text5717204812817"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25.14%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002165418008_p13998205142815"><a name="en-us_topic_0000002165418008_p13998205142815"></a><a name="en-us_topic_0000002165418008_p13998205142815"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002165418008_p49983512287"><a name="en-us_topic_0000002165418008_p49983512287"></a><a name="en-us_topic_0000002165418008_p49983512287"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="p7507171012231"><a name="p7507171012231"></a><a name="p7507171012231"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002165418008_row06711416544"><td class="cellrowborder" valign="top" width="24.86%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002165418008_p1765294655411"><a name="en-us_topic_0000002165418008_p1765294655411"></a><a name="en-us_topic_0000002165418008_p1765294655411"></a><span id="en-us_topic_0000002165418008_text19652946185414"><a name="en-us_topic_0000002165418008_text19652946185414"></a><a name="en-us_topic_0000002165418008_text19652946185414"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25.14%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002165418008_p428811549547"><a name="en-us_topic_0000002165418008_p428811549547"></a><a name="en-us_topic_0000002165418008_p428811549547"></a>Y (in-band only)</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002165418008_p15288954155420"><a name="en-us_topic_0000002165418008_p15288954155420"></a><a name="en-us_topic_0000002165418008_p15288954155420"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002165418008_p192881754115412"><a name="en-us_topic_0000002165418008_p192881754115412"></a><a name="en-us_topic_0000002165418008_p192881754115412"></a>N</p>
</td>
</tr>
<tr id="row191917542215"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="p1550115418718"><a name="p1550115418718"></a><a name="p1550115418718"></a>Note: <strong id="en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
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
int channel_state = 0;
enum dcmi_reset_channel channel_type = OUTBAND_CHANNEL;
ret = dcmi_get_device_outband_channel_state(card_id, device_id, &channel_state);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
ret = dcmi_pre_reset_soc(card_id, device_id);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
ret = dcmi_set_device_reset(card_id, device_id, channel_type);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
…  
```

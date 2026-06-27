# dcmi\_get\_device\_outband\_channel\_state API<a name="EN-US_TOPIC_0000002515510432"></a>

**Prototype<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412077"></a>**

**int dcmi\_get\_device\_outband\_channel\_state\(int card\_id, int device\_id, int \*channel\_state\)**

**Description<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412078"></a>**

Queries the outband channel status.

**Parameter Description<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412079"></a>**

<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row7580267"><th class="cellrowborder" valign="top" width="18.35%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.64%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.89%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row36571438115418"><td class="cellrowborder" valign="top" width="18.35%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p36741947142813"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p36741947142813"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p96741747122818"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p96741747122818"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p46747472287"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p46747472287"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1467413474281"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1467413474281"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b27677697333134"><a name="b27677697333134"></a><a name="b27677697333134"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row19957136105419"><td class="cellrowborder" valign="top" width="18.35%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b97321715533015"><a name="b97321715533015"></a><a name="b97321715533015"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b181718239257"><a name="b181718239257"></a><a name="b181718239257"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row10560021192510"><td class="cellrowborder" valign="top" width="18.35%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"></a>channel_state</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"></a>int  *</p>
</td>
<td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"></a>Outband channel status.</p>
<a name="ul7729135913583"></a><a name="ul7729135913583"></a><ul id="ul7729135913583"><li><strong id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"></a>1</strong>: The channel is normal.</li><li><strong id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"></a>0</strong>: The channel is abnormal.</li></ul>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b9599590977823"><a name="b9599590977823"></a><a name="b9599590977823"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412082"></a>**

- The out-of-band channel status query function depends on the ipmitool software. You need to download the ipmitool software and load the driver in advance. For details, see  [Preparing IPMItool](faqs.md).
- For Atlas 9000 A3 SuperPoD Cluster Computing System, Atlas 900 A3 SuperPoD, Atlas 800T A3 SuperPoD, and Atlas 800I A3 SuperPoD, this API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="table12176192314614"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row0232969110"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p17232186114"><a name="en-us_topic_0000002515350556_p17232186114"></a><a name="en-us_topic_0000002515350556_p17232186114"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p172326615120"><a name="en-us_topic_0000002515350556_p172326615120"></a><a name="en-us_topic_0000002515350556_p172326615120"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p92326610111"><a name="en-us_topic_0000002515350556_p92326610111"></a><a name="en-us_topic_0000002515350556_p92326610111"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row182321968119"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p22321561118"><a name="en-us_topic_0000002515350556_p22321561118"></a><a name="en-us_topic_0000002515350556_p22321561118"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p15232136311"><a name="en-us_topic_0000002515350556_p15232136311"></a><a name="en-us_topic_0000002515350556_p15232136311"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p162325618114"><a name="en-us_topic_0000002515350556_p162325618114"></a><a name="en-us_topic_0000002515350556_p162325618114"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row42321268116"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p132321461118"><a name="en-us_topic_0000002515350556_p132321461118"></a><a name="en-us_topic_0000002515350556_p132321461118"></a><span id="en-us_topic_0000002515350556_text32327612114"><a name="en-us_topic_0000002515350556_text32327612114"></a><a name="en-us_topic_0000002515350556_text32327612114"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p42321061216"><a name="en-us_topic_0000002515350556_p42321061216"></a><a name="en-us_topic_0000002515350556_p42321061216"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p2023212612117"><a name="en-us_topic_0000002515350556_p2023212612117"></a><a name="en-us_topic_0000002515350556_p2023212612117"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p18553459193013"><a name="en-us_topic_0000002515350556_p18553459193013"></a><a name="en-us_topic_0000002515350556_p18553459193013"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row3232661513"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p192331461410"><a name="en-us_topic_0000002515350556_p192331461410"></a><a name="en-us_topic_0000002515350556_p192331461410"></a><span id="en-us_topic_0000002515350556_text22331061317"><a name="en-us_topic_0000002515350556_text22331061317"></a><a name="en-us_topic_0000002515350556_text22331061317"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p12233961611"><a name="en-us_topic_0000002515350556_p12233961611"></a><a name="en-us_topic_0000002515350556_p12233961611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p32331261514"><a name="en-us_topic_0000002515350556_p32331261514"></a><a name="en-us_topic_0000002515350556_p32331261514"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p9553559133013"><a name="en-us_topic_0000002515350556_p9553559133013"></a><a name="en-us_topic_0000002515350556_p9553559133013"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1233661415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p139545514163"><a name="en-us_topic_0000002515350556_p139545514163"></a><a name="en-us_topic_0000002515350556_p139545514163"></a><span id="en-us_topic_0000002515350556_text3954185161611"><a name="en-us_topic_0000002515350556_text3954185161611"></a><a name="en-us_topic_0000002515350556_text3954185161611"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p122331168119"><a name="en-us_topic_0000002515350556_p122331168119"></a><a name="en-us_topic_0000002515350556_p122331168119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p72333612115"><a name="en-us_topic_0000002515350556_p72333612115"></a><a name="en-us_topic_0000002515350556_p72333612115"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p16553159123012"><a name="en-us_topic_0000002515350556_p16553159123012"></a><a name="en-us_topic_0000002515350556_p16553159123012"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1233465119"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12338612117"><a name="en-us_topic_0000002515350556_p12338612117"></a><a name="en-us_topic_0000002515350556_p12338612117"></a><span id="en-us_topic_0000002515350556_text17233661215"><a name="en-us_topic_0000002515350556_text17233661215"></a><a name="en-us_topic_0000002515350556_text17233661215"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p52331461012"><a name="en-us_topic_0000002515350556_p52331461012"></a><a name="en-us_topic_0000002515350556_p52331461012"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p15233564117"><a name="en-us_topic_0000002515350556_p15233564117"></a><a name="en-us_topic_0000002515350556_p15233564117"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p055316592308"><a name="en-us_topic_0000002515350556_p055316592308"></a><a name="en-us_topic_0000002515350556_p055316592308"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row22331614114"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p192333618117"><a name="en-us_topic_0000002515350556_p192333618117"></a><a name="en-us_topic_0000002515350556_p192333618117"></a><span id="en-us_topic_0000002515350556_text92331361411"><a name="en-us_topic_0000002515350556_text92331361411"></a><a name="en-us_topic_0000002515350556_text92331361411"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p12233461615"><a name="en-us_topic_0000002515350556_p12233461615"></a><a name="en-us_topic_0000002515350556_p12233461615"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p3233366111"><a name="en-us_topic_0000002515350556_p3233366111"></a><a name="en-us_topic_0000002515350556_p3233366111"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p52331166118"><a name="en-us_topic_0000002515350556_p52331166118"></a><a name="en-us_topic_0000002515350556_p52331166118"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1819971910919"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172823598"><a name="en-us_topic_0000002515350556_p1172823598"></a><a name="en-us_topic_0000002515350556_p1172823598"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412083"></a>**

```c
...
int ret; 
int card_id = 0;
int device_id = 0;
int channel_state = 0;
ret = dcmi_get_device_outband_channel_state(card_id, device_id, &channel_state);
...
```

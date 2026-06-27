# dcmi\_get\_memory\_info<a name="EN-US_TOPIC_0000002515350592"></a>

**Prototype<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_toc533412077"></a>**

**int dcmi\_get\_memory\_info\(int card\_id, int device\_id, struct dcmi\_memory\_info\_stru \*pdevice\_memory\_info\)**

**Description<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_toc533412078"></a>**

Queries chip memory information.

**Parameter Description<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_toc533412079"></a>**

<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_row7580267"><th class="cellrowborder" valign="top" width="18.93%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p10021890"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p10021890"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="8.4%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p6466753"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p6466753"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="23.5%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p54045009"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p54045009"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="49.17%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p15569626"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p15569626"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_row10560021192510"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p36741947142813"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p36741947142813"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.4%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p96741747122818"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p96741747122818"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.5%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p46747472287"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p46747472287"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="49.17%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1467413474281"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1467413474281"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b77231622203014"><a name="b77231622203014"></a><a name="b77231622203014"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_row1155711494235"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p7711145152918"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p7711145152918"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="8.4%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p671116522914"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p671116522914"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="23.5%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1771116572910"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1771116572910"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="49.17%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b19310659232918"><a name="b19310659232918"></a><a name="b19310659232918"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b17749981126225"><a name="b17749981126225"></a><a name="b17749981126225"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_row15462171542913"><td class="cellrowborder" valign="top" width="18.93%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p840519559257"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p840519559257"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p840519559257"></a>pdevice_memory_info</p>
</td>
<td class="cellrowborder" valign="top" width="8.4%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p114051955192517"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p114051955192517"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p114051955192517"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="23.5%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1288145694919"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1288145694919"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1288145694919"></a>struct dcmi_memory_info_stru *</p>
</td>
<td class="cellrowborder" valign="top" width="49.17%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p940555522512"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p940555522512"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p940555522512"></a>Memory information. The information structure is as follows:</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p176144813014"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p176144813014"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p176144813014"></a>struct dcmi_memory_info_stru {</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p261419813307"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p261419813307"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p261419813307"></a>unsigned long long memory_size; // The unit is MB.</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p136141586307"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p136141586307"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p136141586307"></a>unsigned int freq; // Frequency (MHz)</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1761414873012"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1761414873012"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p1761414873012"></a>unsigned int utiliza; // Utilization rate</p>
<p id="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p8614680308"><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p8614680308"></a><a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_p8614680308"></a>};</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b132719254085647"><a name="b132719254085647"></a><a name="b132719254085647"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_toc533412082"></a>**

This API will be deleted from later versions. You are advised to use  [dcmi\_get\_device\_hbm\_info](dcmi_get_device_hbm_info.md).

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p974813717495"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p114288580415"><a name="en-us_topic_0000002515350556_p114288580415"></a><a name="en-us_topic_0000002515350556_p114288580415"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_row19216056194814"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p1378374019445"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text262011415447"></a><span id="en-us_topic_0000002515350556_text1564782665814"><a name="en-us_topic_0000002515350556_text1564782665814"></a><a name="en-us_topic_0000002515350556_text1564782665814"></a>Atlas 900 A3 SuperPoD</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p11683124944919"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p36831949194913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_p2683144919499"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_p137832403444"></a><span id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001819869974_text6814122411310"></a><span id="en-us_topic_0000002515350556_text1123515513517"><a name="en-us_topic_0000002515350556_text1123515513517"></a><a name="en-us_topic_0000002515350556_text1123515513517"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1285753073419"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p1985743013346"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001820029662_en-us_topic_0000001251227155_en-us_topic_0000001178213210_en-us_topic_0000001147728951_p0857203013412"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row12693311552"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p17872181618166"><a name="en-us_topic_0000002515350556_p17872181618166"></a><a name="en-us_topic_0000002515350556_p17872181618166"></a><span id="en-us_topic_0000002515350556_text17872121641614"><a name="en-us_topic_0000002515350556_text17872121641614"></a><a name="en-us_topic_0000002515350556_text17872121641614"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p177521042115520"><a name="en-us_topic_0000002515350556_p177521042115520"></a><a name="en-us_topic_0000002515350556_p177521042115520"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12752114215559"><a name="en-us_topic_0000002515350556_p12752114215559"></a><a name="en-us_topic_0000002515350556_p12752114215559"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p18752104275512"><a name="en-us_topic_0000002515350556_p18752104275512"></a><a name="en-us_topic_0000002515350556_p18752104275512"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row179407221298"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p696322918294"><a name="en-us_topic_0000002515350556_p696322918294"></a><a name="en-us_topic_0000002515350556_p696322918294"></a><span id="en-us_topic_0000002515350556_text15963162972914"><a name="en-us_topic_0000002515350556_text15963162972914"></a><a name="en-us_topic_0000002515350556_text15963162972914"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1560813335296"><a name="en-us_topic_0000002515350556_p1560813335296"></a><a name="en-us_topic_0000002515350556_p1560813335296"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p260873392918"><a name="en-us_topic_0000002515350556_p260873392918"></a><a name="en-us_topic_0000002515350556_p260873392918"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p5608333162914"><a name="en-us_topic_0000002515350556_p5608333162914"></a><a name="en-us_topic_0000002515350556_p5608333162914"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19346183355516"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p0905133713551"><a name="en-us_topic_0000002515350556_p0905133713551"></a><a name="en-us_topic_0000002515350556_p0905133713551"></a><span id="en-us_topic_0000002515350556_text1190563775520"><a name="en-us_topic_0000002515350556_text1190563775520"></a><a name="en-us_topic_0000002515350556_text1190563775520"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p7204194395516"><a name="en-us_topic_0000002515350556_p7204194395516"></a><a name="en-us_topic_0000002515350556_p7204194395516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p13205104310553"><a name="en-us_topic_0000002515350556_p13205104310553"></a><a name="en-us_topic_0000002515350556_p13205104310553"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32051943125519"><a name="en-us_topic_0000002515350556_p32051943125519"></a><a name="en-us_topic_0000002515350556_p32051943125519"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1158213431480"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p65418471681"><a name="en-us_topic_0000002515350556_p65418471681"></a><a name="en-us_topic_0000002515350556_p65418471681"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206627192_en-us_topic_0000001178373158_en-us_topic_0000001148759099_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0x3;
int device_id = 0;
struct dcmi_memory_info_stru pdevice_memory_info = {0};
ret = dcmi_get_memory_info(card_id, device_id, &pdevice_memory_info);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

# dcmi\_get\_device\_flash\_info<a name="EN-US_TOPIC_0000002515350618"></a>

**Prototype<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_toc533412077"></a>**

**int dcmi\_get\_device\_flash\_info\(int card\_id, int device\_id, unsigned int flash\_index, struct dcmi\_flash\_info\_stru \*flash\_info\)**

**Description<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_toc533412078"></a>**

Obtains the information about the flash memory in the chip.

**Parameter Description<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_toc533412079"></a>**

<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p10021890"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p10021890"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p6466753"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p6466753"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.96%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p54045009"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p54045009"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.019999999999996%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p15569626"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p15569626"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p36741947142813"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p36741947142813"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p96741747122818"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p96741747122818"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p46747472287"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p46747472287"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1467413474281"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1467413474281"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1485018197225"><a name="b1485018197225"></a><a name="b1485018197225"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p7711145152918"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p7711145152918"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p671116522914"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p671116522914"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1771116572910"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1771116572910"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b16473921162210"><a name="b16473921162210"></a><a name="b16473921162210"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b17246190636324"><a name="b17246190636324"></a><a name="b17246190636324"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644818114917"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644818114917"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644818114917"></a>flash_index</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1144801174915"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1144801174915"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1144801174915"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144812114911"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144812114911"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144812114911"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p194482014496"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p194482014496"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p194482014496"></a>Flash index, which can be obtained by calling <strong id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b422773610813"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b422773610813"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b422773610813"></a>dcmi_get_device_flash_count</strong>. Value range: [0, <strong id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b1692617401562"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b1692617401562"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_b1692617401562"></a>flash_count</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_row257814447482"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p12448316499"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p12448316499"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p12448316499"></a>flash_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p444801114918"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p444801114918"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p444801114918"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.96%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644810194914"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644810194914"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1644810194914"></a>struct dcmi_flash_info_stru *</p>
</td>
<td class="cellrowborder" valign="top" width="50.019999999999996%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p94481112494"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p94481112494"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p94481112494"></a>Flash memory information.</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144891114916"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144891114916"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p144891114916"></a>The information structure is as follows:</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p610011201252"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p610011201252"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p610011201252"></a>struct dcmi_flash_info_stru {</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p31003206516"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p31003206516"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p31003206516"></a>unsigned long long flash_id; // Flash ID</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910012201057"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910012201057"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910012201057"></a>unsigned short device_id; // Device ID</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p17100620256"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p17100620256"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p17100620256"></a>unsigned short vendor; // Vendor ID</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p2972643112210"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p2972643112210"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p2972643112210"></a>unsigned int state; // Flash health. <strong id="b88549210471"><a name="b88549210471"></a><a name="b88549210471"></a>0x8</strong> indicates normal, and <strong id="b198545214714"><a name="b198545214714"></a><a name="b198545214714"></a>0x10</strong> indicates abnormal.</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p131000201051"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p131000201051"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p131000201051"></a>unsigned long long size; // Total size of flash</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p4100182020514"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p4100182020514"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p4100182020514"></a>unsigned int sector_count; // Number of units to be erased</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p8100820855"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p8100820855"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p8100820855"></a>unsigned short manufacturer_id; // Manufacturer ID</p>
<p id="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910013201758"><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910013201758"></a><a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_p1910013201758"></a>};</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b19144576697120"><a name="b19144576697120"></a><a name="b19144576697120"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_toc533412082"></a>**

This API will be deleted from later versions. You are advised to use  [dcmi\_get\_device\_flash\_info\_v2](dcmi_get_device_flash_info_v2.md).

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p67828402447"><a name="en-us_topic_0000002515350556_p67828402447"></a><a name="en-us_topic_0000002515350556_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p16315103817414"><a name="en-us_topic_0000002515350556_p16315103817414"></a><a name="en-us_topic_0000002515350556_p16315103817414"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p992084633012"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row125012052104311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1378374019445"><a name="en-us_topic_0000002515350556_p1378374019445"></a><a name="en-us_topic_0000002515350556_p1378374019445"></a><span id="en-us_topic_0000002515350556_text262011415447"><a name="en-us_topic_0000002515350556_text262011415447"></a><a name="en-us_topic_0000002515350556_text262011415447"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p3696134919457"><a name="en-us_topic_0000002515350556_p3696134919457"></a><a name="en-us_topic_0000002515350556_p3696134919457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1069610491457"><a name="en-us_topic_0000002515350556_p1069610491457"></a><a name="en-us_topic_0000002515350556_p1069610491457"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14744104011463"><a name="en-us_topic_0000002515350556_p14744104011463"></a><a name="en-us_topic_0000002515350556_p14744104011463"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p137832403444"><a name="en-us_topic_0000002515350556_p137832403444"></a><a name="en-us_topic_0000002515350556_p137832403444"></a><span id="en-us_topic_0000002515350556_text1480012462513"><a name="en-us_topic_0000002515350556_text1480012462513"></a><a name="en-us_topic_0000002515350556_text1480012462513"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p17744194024612"><a name="en-us_topic_0000002515350556_p17744194024612"></a><a name="en-us_topic_0000002515350556_p17744194024612"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row195142220363"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p19150201815714"><a name="en-us_topic_0000002515350556_p19150201815714"></a><a name="en-us_topic_0000002515350556_p19150201815714"></a><span id="en-us_topic_0000002515350556_text1615010187716"><a name="en-us_topic_0000002515350556_text1615010187716"></a><a name="en-us_topic_0000002515350556_text1615010187716"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1831093744715"><a name="en-us_topic_0000002515350556_p1831093744715"></a><a name="en-us_topic_0000002515350556_p1831093744715"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9310337164720"><a name="en-us_topic_0000002515350556_p9310337164720"></a><a name="en-us_topic_0000002515350556_p9310337164720"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p10310113714473"><a name="en-us_topic_0000002515350556_p10310113714473"></a><a name="en-us_topic_0000002515350556_p10310113714473"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1024616413271"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1824612411277"><a name="en-us_topic_0000002515350556_p1824612411277"></a><a name="en-us_topic_0000002515350556_p1824612411277"></a><span id="en-us_topic_0000002515350556_text712252182813"><a name="en-us_topic_0000002515350556_text712252182813"></a><a name="en-us_topic_0000002515350556_text712252182813"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p436771642813"><a name="en-us_topic_0000002515350556_p436771642813"></a><a name="en-us_topic_0000002515350556_p436771642813"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p436710164281"><a name="en-us_topic_0000002515350556_p436710164281"></a><a name="en-us_topic_0000002515350556_p436710164281"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p193671116172816"><a name="en-us_topic_0000002515350556_p193671116172816"></a><a name="en-us_topic_0000002515350556_p193671116172816"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row11011140184711"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1010254064715"><a name="en-us_topic_0000002515350556_p1010254064715"></a><a name="en-us_topic_0000002515350556_p1010254064715"></a><span id="en-us_topic_0000002515350556_text15548246175319"><a name="en-us_topic_0000002515350556_text15548246175319"></a><a name="en-us_topic_0000002515350556_text15548246175319"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p0636155115534"><a name="en-us_topic_0000002515350556_p0636155115534"></a><a name="en-us_topic_0000002515350556_p0636155115534"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p16636951125317"><a name="en-us_topic_0000002515350556_p16636951125317"></a><a name="en-us_topic_0000002515350556_p16636951125317"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p163685125315"><a name="en-us_topic_0000002515350556_p163685125315"></a><a name="en-us_topic_0000002515350556_p163685125315"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row7398193211715"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p12881158154715"><a name="en-us_topic_0000002515350556_p12881158154715"></a><a name="en-us_topic_0000002515350556_p12881158154715"></a>Note: <strong id="en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206467206_en-us_topic_0000001178213222_en-us_topic_0000001148639169_toc533412083"></a>**

```c
...
int i;
int ret = 0;
int card_id = 0;
int device_id = 0;
struct dcmi_flash_info_stru flash_info = {0};
unsigned int flash_count = 0;
ret = dcmi_get_device_flash_count(card_id, device_id, &flash_count);
...
For (i = 0; i < flash_count; i++){
    ret = dcmi_get_device_flash_info(card_id, device_id, i, &flash_info);
    if (ret != 0){
        // todo: Record logs.
        return ret;
    } 
...
}
...
```

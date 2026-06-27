# dcmi\_get\_device\_utilization\_rate<a name="EN-US_TOPIC_0000002546910441"></a>

**Prototype<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412077"></a>**

**int dcmi\_get\_device\_utilization\_rate\(int card\_id, int device\_id, int input\_type, unsigned int \*utilization\_rate\)**

**Description<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412078"></a>**

Obtains the chip usage.

**Parameter Description<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412079"></a>**

<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p10021890"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p10021890"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="17.1%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p6466753"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p6466753"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="15.9%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p54045009"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p54045009"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p15569626"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p15569626"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p36741947142813"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p36741947142813"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p96741747122818"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p96741747122818"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p46747472287"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p46747472287"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b193256054432948"><a name="b193256054432948"></a><a name="b193256054432948"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b65031127432920"><a name="b65031127432920"></a><a name="b65031127432920"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b127820841655924"><a name="b127820841655924"></a><a name="b127820841655924"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"></a>Device type.</p>
<p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p126241811182811"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p126241811182811"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p126241811182811"></a>The value can be <strong id="b163994364271"><a name="b163994364271"></a><a name="b163994364271"></a>2</strong>, <strong id="b940093612275"><a name="b940093612275"></a><a name="b940093612275"></a>3</strong>, <strong id="b134001736152715"><a name="b134001736152715"></a><a name="b134001736152715"></a>4</strong>, <strong id="b140073622719"><a name="b140073622719"></a><a name="b140073622719"></a>6</strong>, <strong id="b9400536202719"><a name="b9400536202719"></a><a name="b9400536202719"></a>10</strong>, <strong id="b1640019366277"><a name="b1640019366277"></a><a name="b1640019366277"></a>12</strong>, and <strong id="b14001336162719"><a name="b14001336162719"></a><a name="b14001336162719"></a>13</strong>.</p>
<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"></a><ul id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"><li><strong id="b64036010251"><a name="b64036010251"></a><a name="b64036010251"></a>1</strong>: memory</li><li><strong id="b146763832716"><a name="b146763832716"></a><a name="b146763832716"></a>2</strong>: AI Core</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"></a>3</strong>: AI CPU</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"></a>4</strong>: Ctrl CPU</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"></a>5</strong>: memory bandwidth</li><li><strong id="b183899256110261"><a name="b183899256110261"></a><a name="b183899256110261"></a>6</strong>: on-chip memory</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"></a>8</strong>: DDR</li><li><strong id="b3765113912710"><a name="b3765113912710"></a><a name="b3765113912710"></a>10</strong>: on-chip memory bandwidth</li></ul>
<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"></a><ul id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"></a>12</strong>: Vector Core</li><li><strong id="b105911541122717"><a name="b105911541122717"></a><a name="b105911541122717"></a>13</strong>: overall NPU usage</li></ul>
<div class="note" id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p19992205925611"><a name="p19992205925611"></a><a name="p19992205925611"></a>When the device type is AI Core or Vector Core and profiling is enabled, the queried utilization rate is 0, which has no specific meaning.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row186430244012"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1895344114020"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1895344114020"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1895344114020"></a>utilization_rate</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p16953134204011"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p16953134204011"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p16953134204011"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p109534410401"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p109534410401"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p109534410401"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p59531242402"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p59531242402"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p59531242402"></a>Processor usage (%).</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b28899957685647"><a name="b28899957685647"></a><a name="b28899957685647"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412082"></a>**

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

**Example<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0x3;
int device_id = 0;
unsigned int utilization_rate = 0;
int input_type = DCMI_UTILIZATION_RATE_DDR;
ret = dcmi_get_device_utilization_rate(card_id, device_id, input_type, &utilization_rate);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

# dcmi\_get\_device\_errorcode\_string<a name="EN-US_TOPIC_0000002515350514"></a>

**Prototype<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412077"></a>**

**int dcmi\_get\_device\_errorcode\_string\(int card\_id, int device\_id, unsigned int error\_code, unsigned char \*error\_info, int buf\_size\)**

**Description<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412078"></a>**

Queries the error message of a device.

**Parameter Description<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412079"></a>**

<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row7580267"><th class="cellrowborder" valign="top" width="17.000000000000004%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p10021890"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p10021890"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.990000000000002%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6466753"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6466753"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="15.960000000000003%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p54045009"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p54045009"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.050000000000004%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p15569626"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p15569626"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row10560021192510"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p36741947142813"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p36741947142813"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p96741747122818"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p96741747122818"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p46747472287"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p46747472287"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1467413474281"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1467413474281"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b4840133101413"><a name="b4840133101413"></a><a name="b4840133101413"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row1155711494235"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p7711145152918"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p7711145152918"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p671116522914"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p671116522914"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1771116572910"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1771116572910"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p1377514432141"></a>Chip ID, which can be obtained by calling <strong id="b54183471415"><a name="b54183471415"></a><a name="b54183471415"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"><a name="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"></a><a name="en-us_topic_0000001147723703_en-us_topic_0000001148530297_p147768432143"></a>NPU: [0, <strong id="b15076089716254"><a name="b15076089716254"></a><a name="b15076089716254"></a>device_id_max</strong> – 1]</p>
<p id="en-us_topic_0000001147723703_p46986266814"><a name="en-us_topic_0000001147723703_p46986266814"></a><a name="en-us_topic_0000001147723703_p46986266814"></a>MCU: <strong id="b20748014646254"><a name="b20748014646254"></a><a name="b20748014646254"></a>mcu_id</strong></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row15462171542913"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p72389712563"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p72389712563"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p72389712563"></a>error_code</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112389725620"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112389725620"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112389725620"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p8238871561"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p8238871561"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p8238871561"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p162392075566"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p162392075566"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p162392075566"></a>Error code to be queried, which can be obtained by calling <a href="dcmi_get_device_errorcode_v2.md">dcmi_get_device_errorcode_v2</a>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row194331899543"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p523913745616"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p523913745616"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p523913745616"></a>error_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1323919719563"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1323919719563"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p1323919719563"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112391711565"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112391711565"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p112391711565"></a>unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p172395717564"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p172395717564"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p172395717564"></a>Error information.</p>
</td>
</tr>
<tr id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_row769671118543"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p12239772564"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p12239772564"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p12239772564"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p2239476561"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p2239476561"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p2239476561"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6239157175610"><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6239157175610"></a><a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_p6239157175610"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001178373142_p1661902431918"><a name="en-us_topic_0000001178373142_p1661902431918"></a><a name="en-us_topic_0000001178373142_p1661902431918"></a>The value of <strong id="b863455591419"><a name="b863455591419"></a><a name="b863455591419"></a>error_info</strong> must be greater than or equal to 48 bytes.</p>
<a name="en-us_topic_0000001178373142_ul1060910207250"></a><a name="en-us_topic_0000001178373142_ul1060910207250"></a><ul id="en-us_topic_0000001178373142_ul1060910207250"><li>An <strong id="b431901111155"><a name="b431901111155"></a><a name="b431901111155"></a>error_info</strong> size less than 48 bytes leads to a system error.</li><li>An <strong id="b1664452518151"><a name="b1664452518151"></a><a name="b1664452518151"></a>error_info</strong> size ranging from 48 bytes to 255 bytes results in simplified information returned.</li><li>An <strong id="en-us_topic_0000001178373142_b4502162864416"><a name="en-us_topic_0000001178373142_b4502162864416"></a><a name="en-us_topic_0000001178373142_b4502162864416"></a>error_info</strong> size greater than or equal to 256 bytes results in the actual fault information returned.</li></ul>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b19651288747638"><a name="b19651288747638"></a><a name="b19651288747638"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412082"></a>**

This API provides a list of error codes designed for the chip that can be reported. However, it does not indicate that the error codes have been used. For details about how to query the error codes supported by the current chip, see the description of the  **error\_code**  parameter in  [Parameter Description](#en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412079).

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

**Example<a name="en-us_topic_0000001178373142_en-us_topic_0000001147610857_toc533412083"></a>**

```c
#define ERROR_CODE_MAX_NUM  (128)
#define BUF_SIZE          (256)
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int errorcount = 0;
unsigned int error_code_list[ERROR_CODE_MAX_NUM] = {0};
unsigned char error_info[BUF_SIZE] = {0};
ret = dcmi_get_device_errorcode_v2(card_id, device_id, &errorcount, error_code_list, ERROR_CODE_MAX_NUM);
if ((ret != 0) || (errorcount == 0)){
    // todo: Record logs.
    return ret;
} 
ret = dcmi_get_device_errorcode_string(card_id, device_id, error_code_list[0], error_info, BUF_SIZE);
if (ret != 0) { 
    // todo: Record logs.
    return ret;
}
...
```

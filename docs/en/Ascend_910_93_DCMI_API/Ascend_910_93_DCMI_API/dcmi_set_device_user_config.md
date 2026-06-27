# dcmi\_set\_device\_user\_config<a name="EN-US_TOPIC_0000002546910345"></a>

**Prototype<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_toc533412077"></a>**

**int dcmi\_set\_device\_user\_config\(int card\_id, int device\_id, const char \*config\_name, unsigned int buf\_size, char \*buf\)**

**Description<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_toc533412078"></a>**

Sets user configuration.

**Parameter Description<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_toc533412079"></a>**

<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p10021890"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p10021890"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p6466753"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p6466753"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p54045009"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p54045009"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p15569626"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p15569626"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p36741947142813"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p36741947142813"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p96741747122818"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p96741747122818"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46747472287"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46747472287"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1467413474281"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1467413474281"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b182186111481637"><a name="b182186111481637"></a><a name="b182186111481637"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p7711145152918"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p7711145152918"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p671116522914"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p671116522914"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1771116572910"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1771116572910"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b116173994433121"><a name="b116173994433121"></a><a name="b116173994433121"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b18003058166126"><a name="b18003058166126"></a><a name="b18003058166126"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515350528_p10218227151413"><a name="en-us_topic_0000002515350528_p10218227151413"></a><a name="en-us_topic_0000002515350528_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515350528_b551771083414"><a name="en-us_topic_0000002515350528_b551771083414"></a><a name="en-us_topic_0000002515350528_b551771083414"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515350528_b1263401315345"><a name="en-us_topic_0000002515350528_b1263401315345"></a><a name="en-us_topic_0000002515350528_b1263401315345"></a>2</strong>. A <strong id="en-us_topic_0000002515350528_b544811733415"><a name="en-us_topic_0000002515350528_b544811733415"></a><a name="en-us_topic_0000002515350528_b544811733415"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b18565142019343"><a name="en-us_topic_0000002515350528_b18565142019343"></a><a name="en-us_topic_0000002515350528_b18565142019343"></a>0</strong> or <strong id="en-us_topic_0000002515350528_b1255272314342"><a name="en-us_topic_0000002515350528_b1255272314342"></a><a name="en-us_topic_0000002515350528_b1255272314342"></a>1</strong> indicates an NPU. A <strong id="en-us_topic_0000002515350528_b3731133414341"><a name="en-us_topic_0000002515350528_b3731133414341"></a><a name="en-us_topic_0000002515350528_b3731133414341"></a>device_id</strong> of <strong id="en-us_topic_0000002515350528_b174037378345"><a name="en-us_topic_0000002515350528_b174037378345"></a><a name="en-us_topic_0000002515350528_b174037378345"></a>2</strong> indicates an MCU.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1762123612289"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1762123612289"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1762123612289"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46211236182811"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46211236182811"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p46211236182811"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1662112368286"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1662112368286"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1662112368286"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a>Configuration item name, up to 32 characters.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1795311111557"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1795311111557"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1795311111557"></a>Supported configuration item: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b27553691811"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b27553691811"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b27553691811"></a>mac_info</strong>. Custom names are supported.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189533165513"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189533165513"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189533165513"></a>The configuration items are described as follows:</p>
<p id="p13747195920471"><a name="p13747195920471"></a><a name="p13747195920471"></a><strong id="b1268813983911"><a name="b1268813983911"></a><a name="b1268813983911"></a>mac_info</strong>: sets the MAC address.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row677353102819"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p347295412284"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p347295412284"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p347295412284"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1847275412814"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1847275412814"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1847275412814"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1472195462814"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1472195462814"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1472195462814"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"></a>Buffer size (bytes), up to 1 KB.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p33509511202"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p33509511202"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p33509511202"></a>Supported configuration item: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b14417192315717"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b14417192315717"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b14417192315717"></a>mac_info</strong>.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p5350155152014"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p5350155152014"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p5350155152014"></a>The supported configuration items are as follows:</p>
<p id="p2542749172219"><a name="p2542749172219"></a><a name="p2542749172219"></a>For <strong id="b20593348193916"><a name="b20593348193916"></a><a name="b20593348193916"></a>mac_info</strong>, this parameter is set to <strong id="b65936484397"><a name="b65936484397"></a><a name="b65936484397"></a>16</strong>.</p>
<p id="p7865034114310"><a name="p7865034114310"></a><a name="p7865034114310"></a>Except the preceding fixed names, the maximum length of other names cannot exceed 1024 bytes.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_row19625184713240"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p176251747192415"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p176251747192415"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p176251747192415"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1862534712243"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1862534712243"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1862534712243"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p462554719244"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p462554719244"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p462554719244"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"></a>Buffer pointer, pointing to the configuration option.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1398395362310"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1398395362310"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p1398395362310"></a>Supported configuration item: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b13544144113107"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b13544144113107"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b13544144113107"></a>mac_info</strong>.</p>
<p id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189915342233"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189915342233"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_p189915342233"></a>The supported configuration items are as follows:</p>
<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_ul626216442429"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_ul626216442429"></a><ul id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_en-us_topic_0204328569_ul626216442429"><li>For <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b341503718127"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b341503718127"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b341503718127"></a>mac_info</strong>, no default value is provided.<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_ul10163124817104"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_ul10163124817104"></a><ul id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_ul10163124817104"><li>buf[0]–buf[1]: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b66401241161215"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b66401241161215"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b66401241161215"></a>crc_value</strong> of <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b4218195101219"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b4218195101219"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b4218195101219"></a>buf[2]–buf[10]</strong></li><li>buf[2]: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b5932991873717"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b5932991873717"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b5932991873717"></a>data_length</strong>, set to <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b9848141043717"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b9848141043717"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b9848141043717"></a>9</strong></li><li>buf[3]: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b16004330883717"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b16004330883717"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b16004330883717"></a>mac_id</strong></li><li>buf[4]: <strong id="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b8561537093717"><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b8561537093717"></a><a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_b8561537093717"></a>mac_type</strong></li><li>buf[5]–buf[10]: <strong id="b023645721713"><a name="b023645721713"></a><a name="b023645721713"></a>mac_addr</strong>, 6 bytes</li><li>buf[11]–buf[15]: reserved, which can be set to all <strong id="b18748759201711"><a name="b18748759201711"></a><a name="b18748759201711"></a>0</strong></li></ul>
</li></ul>
<p id="p1289194120432"><a name="p1289194120432"></a><a name="p1289194120432"></a>Set this parameter for other configuration items as required.</p>
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
<a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001819869974_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b873276067433"><a name="b873276067433"></a><a name="b873276067433"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206467198_en-us_topic_0000001223494375_en-us_topic_0000001148770187_toc533412083"></a>**

```c
...
#define BUF_SIZE 1
int ret = 0;
int card_id = 0;
int device_id = 0;
char *config_name = "mac_info";
char buf[BUF_SIZE] = {0};
ret=dcmi_set_device_user_config(card_id, device_id,config_name, BUF_SIZE, buf);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
...
```

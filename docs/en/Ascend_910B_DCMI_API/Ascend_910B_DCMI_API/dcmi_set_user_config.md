# dcmi\_set\_user\_config<a name="EN-US_TOPIC_0000002515343886"></a>

**Prototype<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_toc533412077"></a>**

**int dcmi\_set\_user\_config\(int card\_id, int device\_id, const char \*config\_name, unsigned int buf\_size, unsigned char \*buf\)**

**Description<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_toc533412078"></a>**

Sets user configuration.

**Parameter Description<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_toc533412079"></a>**

<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p10021890"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p10021890"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p6466753"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p6466753"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p54045009"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p54045009"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p15569626"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p15569626"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p36741947142813"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p36741947142813"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p96741747122818"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p96741747122818"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46747472287"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46747472287"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1467413474281"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1467413474281"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b764581279102423"><a name="b764581279102423"></a><a name="b764581279102423"></a>dcmi_get_card_num_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p7711145152918"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p7711145152918"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p671116522914"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p671116522914"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1771116572910"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1771116572910"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b34327006102548"><a name="b34327006102548"></a><a name="b34327006102548"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b1234017792105411"><a name="b1234017792105411"></a><a name="b1234017792105411"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1762123612289"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1762123612289"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1762123612289"></a>config_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46211236182811"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46211236182811"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p46211236182811"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1662112368286"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1662112368286"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1662112368286"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p182531815143013"></a>Configuration item name, up to 32 characters.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1795311111557"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1795311111557"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1795311111557"></a>Supported configuration item: <strong id="b26941613145919"><a name="b26941613145919"></a><a name="b26941613145919"></a>mac_info</strong> and <strong id="b2694161375919"><a name="b2694161375919"></a><a name="b2694161375919"></a>cert_expired_threshold</strong>. Custom names are supported.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189533165513"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189533165513"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189533165513"></a>The configuration items are described as follows:</p>
<p id="p15201153616537"><a name="p15201153616537"></a><a name="p15201153616537"></a><strong id="b399103451810"><a name="b399103451810"></a><a name="b399103451810"></a>mac_info</strong>: sets the MAC address.</p>
<p id="p67663111338"><a name="p67663111338"></a><a name="p67663111338"></a><strong id="b1441252111517"><a name="b1441252111517"></a><a name="b1441252111517"></a>cert_expired_threshold</strong>: sets the certificate expiration threshold.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row677353102819"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p347295412284"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p347295412284"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p347295412284"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1847275412814"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1847275412814"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1847275412814"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1472195462814"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1472195462814"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1472195462814"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p18198579293"></a>Buffer size (bytes), up to 1 KB.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p33509511202"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p33509511202"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p33509511202"></a>Supported configuration item: <strong id="b20723520115910"><a name="b20723520115910"></a><a name="b20723520115910"></a>mac_info</strong> and <strong id="b2724720155919"><a name="b2724720155919"></a><a name="b2724720155919"></a>cert_expired_threshold</strong>.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p5350155152014"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p5350155152014"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p5350155152014"></a>The supported configuration items are as follows:</p>
<p id="p610431395413"><a name="p610431395413"></a><a name="p610431395413"></a>For <strong id="b1551011402181"><a name="b1551011402181"></a><a name="b1551011402181"></a>mac_info</strong>, this parameter is fixed at <strong id="b55111540141812"><a name="b55111540141812"></a><a name="b55111540141812"></a>16</strong>.</p>
<p id="p153758471874"><a name="p153758471874"></a><a name="p153758471874"></a>For <strong id="b1735517519613"><a name="b1735517519613"></a><a name="b1735517519613"></a>cert_expired_threshold</strong>, this parameter is fixed at <strong id="b2355450616"><a name="b2355450616"></a><a name="b2355450616"></a>1</strong>.</p>
<p id="p144411257194210"><a name="p144411257194210"></a><a name="p144411257194210"></a>Except the preceding fixed names, the maximum length of other names cannot exceed 1024 bytes.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_row19625184713240"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p176251747192415"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p176251747192415"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p176251747192415"></a>buf</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1862534712243"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1862534712243"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1862534712243"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p462554719244"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p462554719244"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p462554719244"></a>unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_en-us_topic_0158027668_p32012572298"></a>Buffer pointer, pointing to the configuration option.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1398395362310"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1398395362310"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p1398395362310"></a>Supported configuration item: <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b2547141720179"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b2547141720179"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b2547141720179"></a>mac_info</strong>.</p>
<p id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189915342233"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189915342233"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_p189915342233"></a>The supported configuration items are as follows:</p>
<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_ul626216442429"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_ul626216442429"></a><ul id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_en-us_topic_0204328569_ul626216442429"><li>For <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b535392721710"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b535392721710"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b535392721710"></a>mac_info</strong>, no default value is provided.<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_ul10163124817104"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_ul10163124817104"></a><ul id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_ul10163124817104"><li>buf[0]–buf[1]: <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b189162811175"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b189162811175"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b189162811175"></a>crc_value</strong> of <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b10922812176"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b10922812176"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b10922812176"></a>buf[2]–buf[10]</strong></li><li>buf[2]: <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b82528245381"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b82528245381"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b82528245381"></a>data_length</strong>, fixed at <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b6253724133820"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b6253724133820"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b6253724133820"></a>9</strong></li><li>buf[3]: <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b13121426163817"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b13121426163817"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b13121426163817"></a>mac_id</strong></li><li>buf[4]: <strong id="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b324472793810"><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b324472793810"></a><a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_b324472793810"></a>mac_type</strong></li><li>buf[5]–buf[10]: <strong id="b92558361231122"><a name="b92558361231122"></a><a name="b92558361231122"></a>mac_addr</strong>, 6 bytes</li><li>buf[11]–buf[15]: reserved, which can be set to all <strong id="b110562570831126"><a name="b110562570831126"></a><a name="b110562570831126"></a>0</strong></li></ul>
</li></ul>
<p id="p468111415712"><a name="p468111415712"></a><a name="p468111415712"></a>Supported configuration item: <strong id="b1265483218612"><a name="b1265483218612"></a><a name="b1265483218612"></a>cert_expired_threshold</strong>.</p>
<a name="ul15155114715"></a><a name="ul15155114715"></a><ul id="ul15155114715"><li>For <strong id="b834893513617"><a name="b834893513617"></a><a name="b834893513617"></a>cert_expired_threshold</strong>, no default value is provided.<a name="ul371918346811"></a><a name="ul371918346811"></a><ul id="ul371918346811"><li>buf[0]: certificate expiration threshold.</li></ul>
</li></ul>
<p id="p69916364320"><a name="p69916364320"></a><a name="p69916364320"></a>Set this parameter for other configuration items as required.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b119683028685656"><a name="b119683028685656"></a><a name="b119683028685656"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_toc533412082"></a>**

This API will be deleted from later versions. You are advised to use  [dcmi\_set\_device\_user\_config](dcmi_set_device_user_config.md).

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
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_en-us_topic_0000001167913765_row82952324359"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1759118207718"><a name="en-us_topic_0000002515503852_p1759118207718"></a><a name="en-us_topic_0000002515503852_p1759118207718"></a><span id="en-us_topic_0000002515503852_ph05911020372"><a name="en-us_topic_0000002515503852_ph05911020372"></a><a name="en-us_topic_0000002515503852_ph05911020372"></a><span id="en-us_topic_0000002515503852_text12591192010713"><a name="en-us_topic_0000002515503852_text12591192010713"></a><a name="en-us_topic_0000002515503852_text12591192010713"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p1018612250597"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p16903175117312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001251427187_en-us_topic_0000001188446388_p89579531835"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row72645420615"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p95911420177"><a name="en-us_topic_0000002515503852_p95911420177"></a><a name="en-us_topic_0000002515503852_p95911420177"></a><span id="en-us_topic_0000002515503852_text6591220876"><a name="en-us_topic_0000002515503852_text6591220876"></a><a name="en-us_topic_0000002515503852_text6591220876"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p291810521262"><a name="en-us_topic_0000002515503852_p291810521262"></a><a name="en-us_topic_0000002515503852_p291810521262"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p199181852061"><a name="en-us_topic_0000002515503852_p199181852061"></a><a name="en-us_topic_0000002515503852_p199181852061"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p89189521765"><a name="en-us_topic_0000002515503852_p89189521765"></a><a name="en-us_topic_0000002515503852_p89189521765"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row278413126616"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p559162010720"><a name="en-us_topic_0000002515503852_p559162010720"></a><a name="en-us_topic_0000002515503852_p559162010720"></a><span id="en-us_topic_0000002515503852_text165912204716"><a name="en-us_topic_0000002515503852_text165912204716"></a><a name="en-us_topic_0000002515503852_text165912204716"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1852110531661"><a name="en-us_topic_0000002515503852_p1852110531661"></a><a name="en-us_topic_0000002515503852_p1852110531661"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1252125311612"><a name="en-us_topic_0000002515503852_p1252125311612"></a><a name="en-us_topic_0000002515503852_p1252125311612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p652117531767"><a name="en-us_topic_0000002515503852_p652117531767"></a><a name="en-us_topic_0000002515503852_p652117531767"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row878911101267"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p259119201579"><a name="en-us_topic_0000002515503852_p259119201579"></a><a name="en-us_topic_0000002515503852_p259119201579"></a><span id="en-us_topic_0000002515503852_text55915207713"><a name="en-us_topic_0000002515503852_text55915207713"></a><a name="en-us_topic_0000002515503852_text55915207713"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
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
<tr id="en-us_topic_0000002515503852_row8655214617"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p14591202016712"><a name="en-us_topic_0000002515503852_p14591202016712"></a><a name="en-us_topic_0000002515503852_p14591202016712"></a><span id="en-us_topic_0000002515503852_text1659110201379"><a name="en-us_topic_0000002515503852_text1659110201379"></a><a name="en-us_topic_0000002515503852_text1659110201379"></a>Atlas 300T A2 training card</span></p>
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

**Example<a name="en-us_topic_0000001206627184_en-us_topic_0000001223494369_en-us_topic_0000001114051160_toc533412083"></a>**

```c
...
#define BUF_SIZE 1
int ret = 0;
int card_id = 0;
int device_id = 0;
char *config_name = "mac_info";
unsigned char buf[BUF_SIZE] = {0};
ret=dcmi_set_user_config(card_id, device_id,config_name, BUF_SIZE, buf);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

# dcmi\_set\_device\_gateway<a name="EN-US_TOPIC_0000002515343964"></a>

**Prototype<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_toc533412077"></a>**

**int dcmi\_set\_device\_gateway\(int card\_id, int device\_id, enum dcmi\_port\_type input\_type, int port\_id, struct dcmi\_ip\_addr \*gateway\)**

**Description<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_toc533412078"></a>**

Sets the gateway address.

**Parameter Description<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_toc533412079"></a>**

<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10021890"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10021890"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p6466753"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p6466753"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p54045009"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p54045009"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15569626"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15569626"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p36741947142813"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p36741947142813"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p96741747122818"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p96741747122818"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p46747472287"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p46747472287"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1467413474281"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1467413474281"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b14756978710294"><a name="b14756978710294"></a><a name="b14756978710294"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p7711145152918"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p7711145152918"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p671116522914"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p671116522914"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1771116572910"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1771116572910"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1016542892102541"><a name="b1016542892102541"></a><a name="b1016542892102541"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b46358037010544"><a name="b46358037010544"></a><a name="b46358037010544"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5522164215178"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5522164215178"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5522164215178"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8522242101715"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8522242101715"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p17522114220174"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p17522114220174"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p17522114220174"></a>enum dcmi_port_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p0522164231718"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p0522164231718"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p0522164231718"></a>Port type.</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p139261310201818"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p139261310201818"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p139261310201818"></a>enum dcmi_port_type {</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5926810151810"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5926810151810"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p5926810151810"></a>DCMI_VNIC_PORT = 0, // Virtual network port</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p4926121041817"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p4926121041817"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p4926121041817"></a>DCMI_ROCE_PORT = 1, // RoCE network port</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p159260105182"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p159260105182"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p159260105182"></a>DCMI_INVALID_PORT</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p169267108184"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p169267108184"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p169267108184"></a>};</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8907162231913"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8907162231913"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p8907162231913"></a><strong id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_b17712184294"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_b17712184294"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_b17712184294"></a>DCMI_VNIC_PORT</strong> is not supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row1382112338184"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2082216331186"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2082216331186"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2082216331186"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1982217333181"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1982217333181"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1982217333181"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p118221533101811"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p118221533101811"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p118221533101811"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1182253319187"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1182253319187"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1182253319187"></a>(Reserved) Port ID. Value range: [0, 255].</p>
</td>
</tr>
<tr id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_row14113163220181"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1911443271820"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1911443271820"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1911443271820"></a>gateway</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10114432171816"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10114432171816"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p10114432171816"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15114123220187"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15114123220187"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p15114123220187"></a>struct dcmi_ip_addr *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p496716258191"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p496716258191"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p496716258191"></a>Gateway address.</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p11821111510193"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p11821111510193"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p11821111510193"></a>struct dcmi_ip_addr {</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p178211153196"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p178211153196"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p178211153196"></a>union {</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p168212015141919"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p168212015141919"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p168212015141919"></a>unsigned char ip6[16]; // IPv6 address</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2821191541917"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2821191541917"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p2821191541917"></a>unsigned char ip4[4]; // IPv4 address</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p158211715161914"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p158211715161914"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p158211715161914"></a>} u_addr;</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1382110151199"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1382110151199"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p1382110151199"></a>enum dcmi_ip_addr_type ip_type; // IP address type</p>
<p id="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p382111158199"><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p382111158199"></a><a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_p382111158199"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b734355185649"><a name="b734355185649"></a><a name="b734355185649"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table6665182042413"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row169301746431"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p455965912315"><a name="en-us_topic_0000002515503852_p455965912315"></a><a name="en-us_topic_0000002515503852_p455965912315"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p1855915599312"><a name="en-us_topic_0000002515503852_p1855915599312"></a><a name="en-us_topic_0000002515503852_p1855915599312"></a><strong id="en-us_topic_0000002515503852_b59121333747"><a name="en-us_topic_0000002515503852_b59121333747"></a><a name="en-us_topic_0000002515503852_b59121333747"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p1155945933111"><a name="en-us_topic_0000002515503852_p1155945933111"></a><a name="en-us_topic_0000002515503852_p1155945933111"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b16139123517413"><a name="en-us_topic_0000002515503852_b16139123517413"></a><a name="en-us_topic_0000002515503852_b16139123517413"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p145593594316"><a name="en-us_topic_0000002515503852_p145593594316"></a><a name="en-us_topic_0000002515503852_p145593594316"></a><strong id="en-us_topic_0000002515503852_b153722369412"><a name="en-us_topic_0000002515503852_b153722369412"></a><a name="en-us_topic_0000002515503852_b153722369412"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row1393017444310"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p793119413433"><a name="en-us_topic_0000002515503852_p793119413433"></a><a name="en-us_topic_0000002515503852_p793119413433"></a><span id="en-us_topic_0000002515503852_ph1893115424314"><a name="en-us_topic_0000002515503852_ph1893115424314"></a><a name="en-us_topic_0000002515503852_ph1893115424314"></a><span id="en-us_topic_0000002515503852_text99311140437"><a name="en-us_topic_0000002515503852_text99311140437"></a><a name="en-us_topic_0000002515503852_text99311140437"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p99311442430"><a name="en-us_topic_0000002515503852_p99311442430"></a><a name="en-us_topic_0000002515503852_p99311442430"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1093114411431"><a name="en-us_topic_0000002515503852_p1093114411431"></a><a name="en-us_topic_0000002515503852_p1093114411431"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p39315418437"><a name="en-us_topic_0000002515503852_p39315418437"></a><a name="en-us_topic_0000002515503852_p39315418437"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row79316404316"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p3931545437"><a name="en-us_topic_0000002515503852_p3931545437"></a><a name="en-us_topic_0000002515503852_p3931545437"></a><span id="en-us_topic_0000002515503852_text893113494316"><a name="en-us_topic_0000002515503852_text893113494316"></a><a name="en-us_topic_0000002515503852_text893113494316"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p49310454319"><a name="en-us_topic_0000002515503852_p49310454319"></a><a name="en-us_topic_0000002515503852_p49310454319"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p993111464319"><a name="en-us_topic_0000002515503852_p993111464319"></a><a name="en-us_topic_0000002515503852_p993111464319"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p893111419431"><a name="en-us_topic_0000002515503852_p893111419431"></a><a name="en-us_topic_0000002515503852_p893111419431"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row39314494319"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1893154144315"><a name="en-us_topic_0000002515503852_p1893154144315"></a><a name="en-us_topic_0000002515503852_p1893154144315"></a><span id="en-us_topic_0000002515503852_text69317417433"><a name="en-us_topic_0000002515503852_text69317417433"></a><a name="en-us_topic_0000002515503852_text69317417433"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p159312418432"><a name="en-us_topic_0000002515503852_p159312418432"></a><a name="en-us_topic_0000002515503852_p159312418432"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p11931046437"><a name="en-us_topic_0000002515503852_p11931046437"></a><a name="en-us_topic_0000002515503852_p11931046437"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1093117412433"><a name="en-us_topic_0000002515503852_p1093117412433"></a><a name="en-us_topic_0000002515503852_p1093117412433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row129312414310"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p793114424311"><a name="en-us_topic_0000002515503852_p793114424311"></a><a name="en-us_topic_0000002515503852_p793114424311"></a><span id="en-us_topic_0000002515503852_text393110464310"><a name="en-us_topic_0000002515503852_text393110464310"></a><a name="en-us_topic_0000002515503852_text393110464310"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1893114154312"><a name="en-us_topic_0000002515503852_p1893114154312"></a><a name="en-us_topic_0000002515503852_p1893114154312"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p59316474318"><a name="en-us_topic_0000002515503852_p59316474318"></a><a name="en-us_topic_0000002515503852_p59316474318"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1693115417437"><a name="en-us_topic_0000002515503852_p1693115417437"></a><a name="en-us_topic_0000002515503852_p1693115417437"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row89311147437"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1893194154319"><a name="en-us_topic_0000002515503852_p1893194154319"></a><a name="en-us_topic_0000002515503852_p1893194154319"></a><span id="en-us_topic_0000002515503852_text2093119410435"><a name="en-us_topic_0000002515503852_text2093119410435"></a><a name="en-us_topic_0000002515503852_text2093119410435"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p10931104184313"><a name="en-us_topic_0000002515503852_p10931104184313"></a><a name="en-us_topic_0000002515503852_p10931104184313"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1593174124311"><a name="en-us_topic_0000002515503852_p1593174124311"></a><a name="en-us_topic_0000002515503852_p1593174124311"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1193110410433"><a name="en-us_topic_0000002515503852_p1193110410433"></a><a name="en-us_topic_0000002515503852_p1193110410433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1593110424311"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p169318417439"><a name="en-us_topic_0000002515503852_p169318417439"></a><a name="en-us_topic_0000002515503852_p169318417439"></a><span id="en-us_topic_0000002515503852_text190313342286"><a name="en-us_topic_0000002515503852_text190313342286"></a><a name="en-us_topic_0000002515503852_text190313342286"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p813010149432"><a name="en-us_topic_0000002515503852_p813010149432"></a><a name="en-us_topic_0000002515503852_p813010149432"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p4931174104310"><a name="en-us_topic_0000002515503852_p4931174104310"></a><a name="en-us_topic_0000002515503852_p4931174104310"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p29311647436"><a name="en-us_topic_0000002515503852_p29311647436"></a><a name="en-us_topic_0000002515503852_p29311647436"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row109312418438"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p159327434319"><a name="en-us_topic_0000002515503852_p159327434319"></a><a name="en-us_topic_0000002515503852_p159327434319"></a><span id="en-us_topic_0000002515503852_text179321145437"><a name="en-us_topic_0000002515503852_text179321145437"></a><a name="en-us_topic_0000002515503852_text179321145437"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p714181416435"><a name="en-us_topic_0000002515503852_p714181416435"></a><a name="en-us_topic_0000002515503852_p714181416435"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p7932114174312"><a name="en-us_topic_0000002515503852_p7932114174312"></a><a name="en-us_topic_0000002515503852_p7932114174312"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p19323418433"><a name="en-us_topic_0000002515503852_p19323418433"></a><a name="en-us_topic_0000002515503852_p19323418433"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1993264174312"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1693212411435"><a name="en-us_topic_0000002515503852_p1693212411435"></a><a name="en-us_topic_0000002515503852_p1693212411435"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206467184_en-us_topic_0000001223172937_en-us_topic_0000001148292021_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
unsigned int gateway_address = 0xC801A8C0; //192.168.1.200 (This IP address is only an example. Use the actual gateway IP address.)
struct dcmi_ip_addr ip_gateway_address = {0};
memcpy(&(ip_gateway_address.u_addr.ip4[0]),&gateway_address,4);
ret = dcmi_set_device_gateway(card_id,device_id, DCMI_ROCE_PORT, port_id, &ip_gateway_address);
if (ret != 0) {
    //todo: Record logs.
    return ret; 
}
...
```

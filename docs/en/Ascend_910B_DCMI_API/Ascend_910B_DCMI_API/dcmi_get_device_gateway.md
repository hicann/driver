# dcmi\_get\_device\_gateway<a name="EN-US_TOPIC_0000002546983741"></a>

**Prototype<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_toc533412077"></a>**

**int dcmi\_get\_device\_gateway\(int card\_id, int device\_id, enum dcmi\_port\_type input\_type, int port\_id, struct dcmi\_ip\_addr \*gateway\)**

**Description<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_toc533412078"></a>**

Obtains the gateway address.

**Parameter Description<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_toc533412079"></a>**

<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10021890"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10021890"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p6466753"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p6466753"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p54045009"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p54045009"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15569626"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15569626"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p36741947142813"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p36741947142813"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p96741747122818"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p96741747122818"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p46747472287"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p46747472287"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1467413474281"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1467413474281"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b46919666510293"><a name="b46919666510293"></a><a name="b46919666510293"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p7711145152918"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p7711145152918"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p671116522914"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p671116522914"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1771116572910"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1771116572910"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b292900773102540"><a name="b292900773102540"></a><a name="b292900773102540"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b133683842210543"><a name="b133683842210543"></a><a name="b133683842210543"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5522164215178"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5522164215178"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5522164215178"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8522242101715"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8522242101715"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8522242101715"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p17522114220174"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p17522114220174"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p17522114220174"></a>enum dcmi_port_type</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p0522164231718"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p0522164231718"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p0522164231718"></a>Port type.</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p139261310201818"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p139261310201818"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p139261310201818"></a>enum dcmi_port_type {</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5926810151810"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5926810151810"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p5926810151810"></a>DCMI_VNIC_PORT = 0, // Virtual network port</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p4926121041817"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p4926121041817"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p4926121041817"></a>DCMI_ROCE_PORT = 1, // RoCE network port</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p159260105182"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p159260105182"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p159260105182"></a>DCMI_INVALID_PORT</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p169267108184"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p169267108184"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p169267108184"></a>};</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8907162231913"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8907162231913"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p8907162231913"></a><strong id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_b1877511333540"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_b1877511333540"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_b1877511333540"></a>DCMI_VNIC_PORT</strong> is not supported.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row1382112338184"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2082216331186"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2082216331186"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2082216331186"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1982217333181"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1982217333181"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1982217333181"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p118221533101811"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p118221533101811"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p118221533101811"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1182253319187"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1182253319187"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1182253319187"></a>(Reserved) Port ID. Value range: [0, 255].</p>
</td>
</tr>
<tr id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_row14113163220181"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1911443271820"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1911443271820"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1911443271820"></a>gateway</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10114432171816"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10114432171816"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p10114432171816"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15114123220187"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15114123220187"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p15114123220187"></a>struct dcmi_ip_addr *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p496716258191"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p496716258191"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p496716258191"></a>Gateway address.</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p11821111510193"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p11821111510193"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p11821111510193"></a>struct dcmi_ip_addr {</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p178211153196"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p178211153196"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p178211153196"></a>union {</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p168212015141919"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p168212015141919"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p168212015141919"></a>unsigned char ip6[16]; // IPv6 address</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2821191541917"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2821191541917"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p2821191541917"></a>unsigned char ip4[4]; // IPv4 address</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p158211715161914"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p158211715161914"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p158211715161914"></a>} u_addr;</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1382110151199"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1382110151199"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p1382110151199"></a>enum dcmi_ip_addr_type ip_type; // IP address type</p>
<p id="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p382111158199"><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p382111158199"></a><a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_p382111158199"></a>};</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b205737928685648"><a name="b205737928685648"></a><a name="b205737928685648"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1723193692019"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p135791655203618"><a name="en-us_topic_0000002515503852_p135791655203618"></a><a name="en-us_topic_0000002515503852_p135791655203618"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p386754617313"><a name="en-us_topic_0000002515503852_p386754617313"></a><a name="en-us_topic_0000002515503852_p386754617313"></a><strong id="en-us_topic_0000002515503852_b1728419571313"><a name="en-us_topic_0000002515503852_b1728419571313"></a><a name="en-us_topic_0000002515503852_b1728419571313"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p11867346143119"><a name="en-us_topic_0000002515503852_p11867346143119"></a><a name="en-us_topic_0000002515503852_p11867346143119"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b20523115920311"><a name="en-us_topic_0000002515503852_b20523115920311"></a><a name="en-us_topic_0000002515503852_b20523115920311"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p178671246173119"><a name="en-us_topic_0000002515503852_p178671246173119"></a><a name="en-us_topic_0000002515503852_p178671246173119"></a><strong id="en-us_topic_0000002515503852_b13768140349"><a name="en-us_topic_0000002515503852_b13768140349"></a><a name="en-us_topic_0000002515503852_b13768140349"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row187242365207"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p11724836152019"><a name="en-us_topic_0000002515503852_p11724836152019"></a><a name="en-us_topic_0000002515503852_p11724836152019"></a><span id="en-us_topic_0000002515503852_ph20724336102017"><a name="en-us_topic_0000002515503852_ph20724336102017"></a><a name="en-us_topic_0000002515503852_ph20724336102017"></a><span id="en-us_topic_0000002515503852_text1672443611202"><a name="en-us_topic_0000002515503852_text1672443611202"></a><a name="en-us_topic_0000002515503852_text1672443611202"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p6724636152017"><a name="en-us_topic_0000002515503852_p6724636152017"></a><a name="en-us_topic_0000002515503852_p6724636152017"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p072493613204"><a name="en-us_topic_0000002515503852_p072493613204"></a><a name="en-us_topic_0000002515503852_p072493613204"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15724113616209"><a name="en-us_topic_0000002515503852_p15724113616209"></a><a name="en-us_topic_0000002515503852_p15724113616209"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row0724133613207"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p172433614201"><a name="en-us_topic_0000002515503852_p172433614201"></a><a name="en-us_topic_0000002515503852_p172433614201"></a><span id="en-us_topic_0000002515503852_text8724103642014"><a name="en-us_topic_0000002515503852_text8724103642014"></a><a name="en-us_topic_0000002515503852_text8724103642014"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p197241836152010"><a name="en-us_topic_0000002515503852_p197241836152010"></a><a name="en-us_topic_0000002515503852_p197241836152010"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p19724123672017"><a name="en-us_topic_0000002515503852_p19724123672017"></a><a name="en-us_topic_0000002515503852_p19724123672017"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1972453612205"><a name="en-us_topic_0000002515503852_p1972453612205"></a><a name="en-us_topic_0000002515503852_p1972453612205"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row77243362207"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1472463611209"><a name="en-us_topic_0000002515503852_p1472463611209"></a><a name="en-us_topic_0000002515503852_p1472463611209"></a><span id="en-us_topic_0000002515503852_text1872453612205"><a name="en-us_topic_0000002515503852_text1872453612205"></a><a name="en-us_topic_0000002515503852_text1872453612205"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1972433616206"><a name="en-us_topic_0000002515503852_p1972433616206"></a><a name="en-us_topic_0000002515503852_p1972433616206"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1072423612012"><a name="en-us_topic_0000002515503852_p1072423612012"></a><a name="en-us_topic_0000002515503852_p1072423612012"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1972463672019"><a name="en-us_topic_0000002515503852_p1972463672019"></a><a name="en-us_topic_0000002515503852_p1972463672019"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row17724133613204"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p67241036122013"><a name="en-us_topic_0000002515503852_p67241036122013"></a><a name="en-us_topic_0000002515503852_p67241036122013"></a><span id="en-us_topic_0000002515503852_text772414362202"><a name="en-us_topic_0000002515503852_text772414362202"></a><a name="en-us_topic_0000002515503852_text772414362202"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p772417367200"><a name="en-us_topic_0000002515503852_p772417367200"></a><a name="en-us_topic_0000002515503852_p772417367200"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p672443632016"><a name="en-us_topic_0000002515503852_p672443632016"></a><a name="en-us_topic_0000002515503852_p672443632016"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1872417364208"><a name="en-us_topic_0000002515503852_p1872417364208"></a><a name="en-us_topic_0000002515503852_p1872417364208"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1772493672010"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p272403610201"><a name="en-us_topic_0000002515503852_p272403610201"></a><a name="en-us_topic_0000002515503852_p272403610201"></a><span id="en-us_topic_0000002515503852_text12724153619206"><a name="en-us_topic_0000002515503852_text12724153619206"></a><a name="en-us_topic_0000002515503852_text12724153619206"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p127241736142014"><a name="en-us_topic_0000002515503852_p127241736142014"></a><a name="en-us_topic_0000002515503852_p127241736142014"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5724636162015"><a name="en-us_topic_0000002515503852_p5724636162015"></a><a name="en-us_topic_0000002515503852_p5724636162015"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p6724143611201"><a name="en-us_topic_0000002515503852_p6724143611201"></a><a name="en-us_topic_0000002515503852_p6724143611201"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row47241236102018"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1272463632016"><a name="en-us_topic_0000002515503852_p1272463632016"></a><a name="en-us_topic_0000002515503852_p1272463632016"></a><span id="en-us_topic_0000002515503852_text11122101592311"><a name="en-us_topic_0000002515503852_text11122101592311"></a><a name="en-us_topic_0000002515503852_text11122101592311"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p43171355112010"><a name="en-us_topic_0000002515503852_p43171355112010"></a><a name="en-us_topic_0000002515503852_p43171355112010"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p0330115562011"><a name="en-us_topic_0000002515503852_p0330115562011"></a><a name="en-us_topic_0000002515503852_p0330115562011"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p193431559206"><a name="en-us_topic_0000002515503852_p193431559206"></a><a name="en-us_topic_0000002515503852_p193431559206"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row197254368207"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p6725133615205"><a name="en-us_topic_0000002515503852_p6725133615205"></a><a name="en-us_topic_0000002515503852_p6725133615205"></a><span id="en-us_topic_0000002515503852_text17256369202"><a name="en-us_topic_0000002515503852_text17256369202"></a><a name="en-us_topic_0000002515503852_text17256369202"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1735585510205"><a name="en-us_topic_0000002515503852_p1735585510205"></a><a name="en-us_topic_0000002515503852_p1735585510205"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p123731555122014"><a name="en-us_topic_0000002515503852_p123731555122014"></a><a name="en-us_topic_0000002515503852_p123731555122014"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p3391255152012"><a name="en-us_topic_0000002515503852_p3391255152012"></a><a name="en-us_topic_0000002515503852_p3391255152012"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row15725536162012"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p6725193618208"><a name="en-us_topic_0000002515503852_p6725193618208"></a><a name="en-us_topic_0000002515503852_p6725193618208"></a><span id="en-us_topic_0000002515503852_ph66771792553"><a name="en-us_topic_0000002515503852_ph66771792553"></a><a name="en-us_topic_0000002515503852_ph66771792553"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001206627206_en-us_topic_0000001223172963_en-us_topic_0000001148044515_toc533412083"></a>**

```C
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
struct dcmi_ip_addr ip_gateway_address = {0};
ret = dcmi_get_device_gateway(card_id,device_id, DCMI_ROCE_PORT, port_id, &ip_gateway_address);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

# dcmi\_get\_device\_utilization\_rate<a name="EN-US_TOPIC_0000002515343906"></a>

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
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b13267133118328"><a name="b13267133118328"></a><a name="b13267133118328"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b328615333325"><a name="b328615333325"></a><a name="b328615333325"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b150542026810539"><a name="b150542026810539"></a><a name="b150542026810539"></a>device_id_max</strong> – 1]</p>
<p id="p932083014157"><a name="p932083014157"></a><a name="p932083014157"></a></p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p89531449406"></a>input_type</p>
</td>
<td class="cellrowborder" valign="top" width="17.1%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p795313444020"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="15.9%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p199530414407"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p666717157201"><a name="p666717157201"></a><a name="p666717157201"></a>Device type. Currently, only <strong id="b137793753211"><a name="b137793753211"></a><a name="b137793753211"></a>2</strong>, <strong id="b47723723214"><a name="b47723723214"></a><a name="b47723723214"></a>3</strong>, <strong id="b577237193220"><a name="b577237193220"></a><a name="b577237193220"></a>4</strong>, <strong id="b117713372321"><a name="b117713372321"></a><a name="b117713372321"></a>6</strong>, <strong id="b117803733215"><a name="b117803733215"></a><a name="b117803733215"></a>10</strong>, <strong id="b678153723210"><a name="b678153723210"></a><a name="b678153723210"></a>12</strong>, and <strong id="b15781037103216"><a name="b15781037103216"></a><a name="b15781037103216"></a>13</strong> are supported.</p>
<p id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_p20138046183612"></a>The mapping between parameter values and device types is as follows:</p>
<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"></a><ul id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_en-us_topic_0204328591_en-us_topic_0146325092_ul5794145112018"><li><strong id="b64036010251"><a name="b64036010251"></a><a name="b64036010251"></a>1</strong>: memory</li><li><strong id="b699713311883"><a name="b699713311883"></a><a name="b699713311883"></a>2</strong>: AI Core</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b14999752134219"></a>3</strong>: AICPU</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b18777125854212"></a>4</strong>: Ctrl CPU</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b189831459134213"></a>5</strong>: memory bandwidth</li><li><strong id="b93659161315842"><a name="b93659161315842"></a><a name="b93659161315842"></a>6</strong>: on-chip memory</li><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b19741735432"></a>8</strong>: DDR</li><li><strong id="b18601923181018"><a name="b18601923181018"></a><a name="b18601923181018"></a>10</strong>: on-chip memory bandwidth</li></ul>
<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"></a><ul id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_ul188012973618"><li><strong id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_b996214712439"></a>12</strong>: Vector Core</li><li><strong id="b3789153213100"><a name="b3789153213100"></a><a name="b3789153213100"></a>13</strong>: overall NPU utilization rate</li></ul>
<p id="p12537234101513"><a name="p12537234101513"></a><a name="p12537234101513"></a></p>
<div class="note" id="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"></a><a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_note079734513131"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="p19992205925611"><a name="p19992205925611"></a><a name="p19992205925611"></a>When the device type is AI Core or Vector Core and profiling is enabled, the queried utilization rate is 0, which has no specific meaning.</p>
<p id="p145284519146"><a name="p145284519146"></a><a name="p145284519146"></a>Only <strong id="b7330124912124"><a name="b7330124912124"></a><a name="b7330124912124"></a>AI Core (2)</strong>, <strong id="b17330114931215"><a name="b17330114931215"></a><a name="b17330114931215"></a>on-chip Memory (6)</strong>, <strong id="b133302049161212"><a name="b133302049161212"></a><a name="b133302049161212"></a>on-chip memory bandwidth (10)</strong>, and <strong id="b4330124910123"><a name="b4330124910123"></a><a name="b4330124910123"></a>Vector Core (12)</strong> are supported in VM passthrough and VM passthrough &amp; container mapping scenarios. In this scenario, the obtained on-chip memory bandwidth is <strong id="b39431413201420"><a name="b39431413201420"></a><a name="b39431413201420"></a>0</strong>, which has no specific meaning.</p>
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

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002515343916_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002515343916_b154714878985455"><a name="en-us_topic_0000002515343916_b154714878985455"></a><a name="en-us_topic_0000002515343916_b154714878985455"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251227163_en-us_topic_0000001178054674_en-us_topic_0000001148257037_toc533412082"></a>**

The on-chip memory of A300I A2 inference card,  Atlas 300T A2 training card,  Atlas 900 A2 PoD cluster basic unit, A200I A2 Box heterogeneous component, and Atlas 800I A2 inference server is 32 GB, and the system occupies 3 GB when no service is running. The on-chip memory of Atlas 800T A2 training server,  Atlas 900 A2 PoD cluster basic unit, Atlas 200T A2 Box16 heterogeneous subrack, A200I A2 Box heterogeneous component, and Atlas 800I A2 inference server is 64 GB, and the system occupies 4 GB when no service is running.

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1548132517501"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p16154843125019"><a name="en-us_topic_0000002515503852_p16154843125019"></a><a name="en-us_topic_0000002515503852_p16154843125019"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p3123182915595"><a name="en-us_topic_0000002515503852_p3123182915595"></a><a name="en-us_topic_0000002515503852_p3123182915595"></a><strong id="en-us_topic_0000002515503852_b181336402033"><a name="en-us_topic_0000002515503852_b181336402033"></a><a name="en-us_topic_0000002515503852_b181336402033"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p6271950600"><a name="en-us_topic_0000002515503852_p6271950600"></a><a name="en-us_topic_0000002515503852_p6271950600"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b56571847339"><a name="en-us_topic_0000002515503852_b56571847339"></a><a name="en-us_topic_0000002515503852_b56571847339"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p41541743195013"><a name="en-us_topic_0000002515503852_p41541743195013"></a><a name="en-us_topic_0000002515503852_p41541743195013"></a><strong id="en-us_topic_0000002515503852_b6856448332"><a name="en-us_topic_0000002515503852_b6856448332"></a><a name="en-us_topic_0000002515503852_b6856448332"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19444162914516"><a name="en-us_topic_0000002515503852_p19444162914516"></a><a name="en-us_topic_0000002515503852_p19444162914516"></a><span id="en-us_topic_0000002515503852_ph1944412296514"><a name="en-us_topic_0000002515503852_ph1944412296514"></a><a name="en-us_topic_0000002515503852_ph1944412296514"></a><span id="en-us_topic_0000002515503852_text944432913516"><a name="en-us_topic_0000002515503852_text944432913516"></a><a name="en-us_topic_0000002515503852_text944432913516"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p194441629165117"><a name="en-us_topic_0000002515503852_p194441629165117"></a><a name="en-us_topic_0000002515503852_p194441629165117"></a><span id="en-us_topic_0000002515503852_text124449291511"><a name="en-us_topic_0000002515503852_text124449291511"></a><a name="en-us_topic_0000002515503852_text124449291511"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p461320458219"><a name="en-us_topic_0000002515503852_p461320458219"></a><a name="en-us_topic_0000002515503852_p461320458219"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13613134519220"><a name="en-us_topic_0000002515503852_p13613134519220"></a><a name="en-us_topic_0000002515503852_p13613134519220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96133454211"><a name="en-us_topic_0000002515503852_p96133454211"></a><a name="en-us_topic_0000002515503852_p96133454211"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row14873174604910"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10444329155118"><a name="en-us_topic_0000002515503852_p10444329155118"></a><a name="en-us_topic_0000002515503852_p10444329155118"></a><span id="en-us_topic_0000002515503852_text1044482925119"><a name="en-us_topic_0000002515503852_text1044482925119"></a><a name="en-us_topic_0000002515503852_text1044482925119"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p896391111511"><a name="en-us_topic_0000002515503852_p896391111511"></a><a name="en-us_topic_0000002515503852_p896391111511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p119682011105113"><a name="en-us_topic_0000002515503852_p119682011105113"></a><a name="en-us_topic_0000002515503852_p119682011105113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11975911195114"><a name="en-us_topic_0000002515503852_p11975911195114"></a><a name="en-us_topic_0000002515503852_p11975911195114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row23051923114915"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p174441129175117"><a name="en-us_topic_0000002515503852_p174441129175117"></a><a name="en-us_topic_0000002515503852_p174441129175117"></a><span id="en-us_topic_0000002515503852_text34441729175119"><a name="en-us_topic_0000002515503852_text34441729175119"></a><a name="en-us_topic_0000002515503852_text34441729175119"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1298231135114"><a name="en-us_topic_0000002515503852_p1298231135114"></a><a name="en-us_topic_0000002515503852_p1298231135114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1298921117511"><a name="en-us_topic_0000002515503852_p1298921117511"></a><a name="en-us_topic_0000002515503852_p1298921117511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1799561165114"><a name="en-us_topic_0000002515503852_p1799561165114"></a><a name="en-us_topic_0000002515503852_p1799561165114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row44814564912"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1044414295516"><a name="en-us_topic_0000002515503852_p1044414295516"></a><a name="en-us_topic_0000002515503852_p1044414295516"></a><span id="en-us_topic_0000002515503852_text44441829105114"><a name="en-us_topic_0000002515503852_text44441829105114"></a><a name="en-us_topic_0000002515503852_text44441829105114"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p17181285116"><a name="en-us_topic_0000002515503852_p17181285116"></a><a name="en-us_topic_0000002515503852_p17181285116"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15131255114"><a name="en-us_topic_0000002515503852_p15131255114"></a><a name="en-us_topic_0000002515503852_p15131255114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15917127513"><a name="en-us_topic_0000002515503852_p15917127513"></a><a name="en-us_topic_0000002515503852_p15917127513"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row11171321114917"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p94441829165113"><a name="en-us_topic_0000002515503852_p94441829165113"></a><a name="en-us_topic_0000002515503852_p94441829165113"></a><span id="en-us_topic_0000002515503852_text16445122985112"><a name="en-us_topic_0000002515503852_text16445122985112"></a><a name="en-us_topic_0000002515503852_text16445122985112"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p01211275113"><a name="en-us_topic_0000002515503852_p01211275113"></a><a name="en-us_topic_0000002515503852_p01211275113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p916161212512"><a name="en-us_topic_0000002515503852_p916161212512"></a><a name="en-us_topic_0000002515503852_p916161212512"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p191911211511"><a name="en-us_topic_0000002515503852_p191911211511"></a><a name="en-us_topic_0000002515503852_p191911211511"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18385115320492"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1644572918513"><a name="en-us_topic_0000002515503852_p1644572918513"></a><a name="en-us_topic_0000002515503852_p1644572918513"></a><span id="en-us_topic_0000002515503852_text1744532925112"><a name="en-us_topic_0000002515503852_text1744532925112"></a><a name="en-us_topic_0000002515503852_text1744532925112"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1923112115119"><a name="en-us_topic_0000002515503852_p1923112115119"></a><a name="en-us_topic_0000002515503852_p1923112115119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1269122515"><a name="en-us_topic_0000002515503852_p1269122515"></a><a name="en-us_topic_0000002515503852_p1269122515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p43014126516"><a name="en-us_topic_0000002515503852_p43014126516"></a><a name="en-us_topic_0000002515503852_p43014126516"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row557915117191"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2042757191916"><a name="en-us_topic_0000002515503852_p2042757191916"></a><a name="en-us_topic_0000002515503852_p2042757191916"></a><span id="en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
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
    // TODO: Record logs.
    return ret;
}
...
```

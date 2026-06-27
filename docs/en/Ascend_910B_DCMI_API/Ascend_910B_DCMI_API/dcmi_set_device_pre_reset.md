# dcmi\_set\_device\_pre\_reset<a name="EN-US_TOPIC_0000002546903767"></a>

**Prototype<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_toc533412077"></a>**

**int dcmi\_set\_device\_pre\_reset\(int card\_id, int device\_id\)**

**Description<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_toc533412078"></a>**

Pre-resets a device to remove the dependencies of the high-level drivers and software. A chip can be isolated or reset only after the pre-reset API returns a success message.

**Parameter Description<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_toc533412079"></a>**

<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p10021890"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p10021890"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p6466753"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p6466753"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p54045009"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p54045009"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p15569626"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p15569626"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p36741947142813"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p36741947142813"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p36741947142813"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p96741747122818"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p96741747122818"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p96741747122818"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p46747472287"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p46747472287"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p46747472287"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1467413474281"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1467413474281"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1467413474281"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1674003007102918"><a name="b1674003007102918"></a><a name="b1674003007102918"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p7711145152918"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p7711145152918"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p7711145152918"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p671116522914"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p671116522914"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1771116572910"><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1771116572910"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p11747451997"></a>Chip ID, which can be obtained by calling <strong id="b1038098759102558"><a name="b1038098759102558"></a><a name="b1038098759102558"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p1377514432141"><a name="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p1377514432141"></a><a name="en-us_topic_0000001251227177_en-us_topic_0000001148530297_p1377514432141"></a>NPU: [0, <strong id="b1571115456105418"><a name="b1571115456105418"></a><a name="b1571115456105418"></a>device_id_max</strong> – 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b111317558685710"><a name="b111317558685710"></a><a name="b111317558685710"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_toc533412082"></a>**

The standard PCIe card reset function in out-of-band mode depends on IPMItool. Download the tool and load the driver in advance. For details, see  [Preparing IPMItool](faqs.md).

**Table  1** Support in different deployment scenarios

<a name="table1993685321815"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row9195184392411"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p9107107193213"><a name="en-us_topic_0000002515503852_p9107107193213"></a><a name="en-us_topic_0000002515503852_p9107107193213"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p1810714713218"><a name="en-us_topic_0000002515503852_p1810714713218"></a><a name="en-us_topic_0000002515503852_p1810714713218"></a><strong id="en-us_topic_0000002515503852_b139111431140"><a name="en-us_topic_0000002515503852_b139111431140"></a><a name="en-us_topic_0000002515503852_b139111431140"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p161071577328"><a name="en-us_topic_0000002515503852_p161071577328"></a><a name="en-us_topic_0000002515503852_p161071577328"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b7227174410420"><a name="en-us_topic_0000002515503852_b7227174410420"></a><a name="en-us_topic_0000002515503852_b7227174410420"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p91071679325"><a name="en-us_topic_0000002515503852_p91071679325"></a><a name="en-us_topic_0000002515503852_p91071679325"></a><strong id="en-us_topic_0000002515503852_b1138019451241"><a name="en-us_topic_0000002515503852_b1138019451241"></a><a name="en-us_topic_0000002515503852_b1138019451241"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row819554332411"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p8195114342417"><a name="en-us_topic_0000002515503852_p8195114342417"></a><a name="en-us_topic_0000002515503852_p8195114342417"></a><span id="en-us_topic_0000002515503852_ph21959437245"><a name="en-us_topic_0000002515503852_ph21959437245"></a><a name="en-us_topic_0000002515503852_ph21959437245"></a><span id="en-us_topic_0000002515503852_text719554332411"><a name="en-us_topic_0000002515503852_text719554332411"></a><a name="en-us_topic_0000002515503852_text719554332411"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1019515434246"><a name="en-us_topic_0000002515503852_p1019515434246"></a><a name="en-us_topic_0000002515503852_p1019515434246"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15196114318249"><a name="en-us_topic_0000002515503852_p15196114318249"></a><a name="en-us_topic_0000002515503852_p15196114318249"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p719611433243"><a name="en-us_topic_0000002515503852_p719611433243"></a><a name="en-us_topic_0000002515503852_p719611433243"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row01969439247"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p17196543192412"><a name="en-us_topic_0000002515503852_p17196543192412"></a><a name="en-us_topic_0000002515503852_p17196543192412"></a><span id="en-us_topic_0000002515503852_text1419612437243"><a name="en-us_topic_0000002515503852_text1419612437243"></a><a name="en-us_topic_0000002515503852_text1419612437243"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p10196104332415"><a name="en-us_topic_0000002515503852_p10196104332415"></a><a name="en-us_topic_0000002515503852_p10196104332415"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p141962043162415"><a name="en-us_topic_0000002515503852_p141962043162415"></a><a name="en-us_topic_0000002515503852_p141962043162415"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p219674362413"><a name="en-us_topic_0000002515503852_p219674362413"></a><a name="en-us_topic_0000002515503852_p219674362413"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row141962435246"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p18196114311245"><a name="en-us_topic_0000002515503852_p18196114311245"></a><a name="en-us_topic_0000002515503852_p18196114311245"></a><span id="en-us_topic_0000002515503852_text15196443142419"><a name="en-us_topic_0000002515503852_text15196443142419"></a><a name="en-us_topic_0000002515503852_text15196443142419"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p6196943142419"><a name="en-us_topic_0000002515503852_p6196943142419"></a><a name="en-us_topic_0000002515503852_p6196943142419"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p12196154313246"><a name="en-us_topic_0000002515503852_p12196154313246"></a><a name="en-us_topic_0000002515503852_p12196154313246"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p7196174314243"><a name="en-us_topic_0000002515503852_p7196174314243"></a><a name="en-us_topic_0000002515503852_p7196174314243"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row2196144316244"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1196204311249"><a name="en-us_topic_0000002515503852_p1196204311249"></a><a name="en-us_topic_0000002515503852_p1196204311249"></a><span id="en-us_topic_0000002515503852_text4196174322416"><a name="en-us_topic_0000002515503852_text4196174322416"></a><a name="en-us_topic_0000002515503852_text4196174322416"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p14196543132410"><a name="en-us_topic_0000002515503852_p14196543132410"></a><a name="en-us_topic_0000002515503852_p14196543132410"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p21961043142413"><a name="en-us_topic_0000002515503852_p21961043142413"></a><a name="en-us_topic_0000002515503852_p21961043142413"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2196144313249"><a name="en-us_topic_0000002515503852_p2196144313249"></a><a name="en-us_topic_0000002515503852_p2196144313249"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row019694302419"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p0196184302411"><a name="en-us_topic_0000002515503852_p0196184302411"></a><a name="en-us_topic_0000002515503852_p0196184302411"></a><span id="en-us_topic_0000002515503852_text619654317244"><a name="en-us_topic_0000002515503852_text619654317244"></a><a name="en-us_topic_0000002515503852_text619654317244"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p4196124316249"><a name="en-us_topic_0000002515503852_p4196124316249"></a><a name="en-us_topic_0000002515503852_p4196124316249"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3196154312417"><a name="en-us_topic_0000002515503852_p3196154312417"></a><a name="en-us_topic_0000002515503852_p3196154312417"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p161961043192418"><a name="en-us_topic_0000002515503852_p161961043192418"></a><a name="en-us_topic_0000002515503852_p161961043192418"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row3196743122417"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1319616436247"><a name="en-us_topic_0000002515503852_p1319616436247"></a><a name="en-us_topic_0000002515503852_p1319616436247"></a><span id="en-us_topic_0000002515503852_text430115652819"><a name="en-us_topic_0000002515503852_text430115652819"></a><a name="en-us_topic_0000002515503852_text430115652819"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p5196184312419"><a name="en-us_topic_0000002515503852_p5196184312419"></a><a name="en-us_topic_0000002515503852_p5196184312419"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p6196114382419"><a name="en-us_topic_0000002515503852_p6196114382419"></a><a name="en-us_topic_0000002515503852_p6196114382419"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p419634382413"><a name="en-us_topic_0000002515503852_p419634382413"></a><a name="en-us_topic_0000002515503852_p419634382413"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row21961435246"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p319644342412"><a name="en-us_topic_0000002515503852_p319644342412"></a><a name="en-us_topic_0000002515503852_p319644342412"></a><span id="en-us_topic_0000002515503852_text13196114320241"><a name="en-us_topic_0000002515503852_text13196114320241"></a><a name="en-us_topic_0000002515503852_text13196114320241"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p6196143112415"><a name="en-us_topic_0000002515503852_p6196143112415"></a><a name="en-us_topic_0000002515503852_p6196143112415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p171961543192420"><a name="en-us_topic_0000002515503852_p171961543192420"></a><a name="en-us_topic_0000002515503852_p171961543192420"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p121960438242"><a name="en-us_topic_0000002515503852_p121960438242"></a><a name="en-us_topic_0000002515503852_p121960438242"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row121961943162411"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p31968432242"><a name="en-us_topic_0000002515503852_p31968432242"></a><a name="en-us_topic_0000002515503852_p31968432242"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251227177_en-us_topic_0000001223172957_en-us_topic_0000001147850809_toc533412083"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
ret = dcmi_set_device_pre_reset(card_id, device_id);
if (ret != 0) {
    //todo: Record logs.
    return ret;
}
...
```

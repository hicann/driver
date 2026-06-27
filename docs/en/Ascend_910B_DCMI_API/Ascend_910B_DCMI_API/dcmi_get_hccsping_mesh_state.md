# dcmi\_get\_hccsping\_mesh\_state<a name="EN-US_TOPIC_0000002546983695"></a>

**Prototype<a name="section1153185215497"></a>**

**int dcmi\_get\_hccsping\_mesh\_state \(int card\_id, int device\_id, int port\_id, unsigned int task\_id, unsigned int \*state\)**

**Description<a name="section7120135716498"></a>**

Queries the status of a resident pingmesh task.

**Parameter Description<a name="section76611617501"></a>**

<a name="table420517174117"></a>
<table><thead align="left"><tr id="en-us_topic_0000002372935233_row0150341164913"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002372935233_p1315044114491"><a name="en-us_topic_0000002372935233_p1315044114491"></a><a name="en-us_topic_0000002372935233_p1315044114491"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002372935233_p415010410495"><a name="en-us_topic_0000002372935233_p415010410495"></a><a name="en-us_topic_0000002372935233_p415010410495"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002372935233_p2150541164920"><a name="en-us_topic_0000002372935233_p2150541164920"></a><a name="en-us_topic_0000002372935233_p2150541164920"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002372935233_p1515011417498"><a name="en-us_topic_0000002372935233_p1515011417498"></a><a name="en-us_topic_0000002372935233_p1515011417498"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002372935233_row11509416492"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372935233_p181501541184916"><a name="en-us_topic_0000002372935233_p181501541184916"></a><a name="en-us_topic_0000002372935233_p181501541184916"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372935233_p3150174174914"><a name="en-us_topic_0000002372935233_p3150174174914"></a><a name="en-us_topic_0000002372935233_p3150174174914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372935233_p2015017414497"><a name="en-us_topic_0000002372935233_p2015017414497"></a><a name="en-us_topic_0000002372935233_p2015017414497"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372935233_p8150541184913"><a name="en-us_topic_0000002372935233_p8150541184913"></a><a name="en-us_topic_0000002372935233_p8150541184913"></a>Device ID. The supported IDs can be obtained by calling <strong id="b322537037102856"><a name="b322537037102856"></a><a name="b322537037102856"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002372935233_row17150194104912"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372935233_p5151114117491"><a name="en-us_topic_0000002372935233_p5151114117491"></a><a name="en-us_topic_0000002372935233_p5151114117491"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372935233_p8151104118498"><a name="en-us_topic_0000002372935233_p8151104118498"></a><a name="en-us_topic_0000002372935233_p8151104118498"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372935233_p121511741144912"><a name="en-us_topic_0000002372935233_p121511741144912"></a><a name="en-us_topic_0000002372935233_p121511741144912"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372935233_p3151104120494"><a name="en-us_topic_0000002372935233_p3151104120494"></a><a name="en-us_topic_0000002372935233_p3151104120494"></a>Chip ID, which can be obtained by calling <strong id="b301494818102527"><a name="b301494818102527"></a><a name="b301494818102527"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002372935233_p1151541164917"><a name="en-us_topic_0000002372935233_p1151541164917"></a><a name="en-us_topic_0000002372935233_p1151541164917"></a>NPU chip: [0, <strong id="b1625249098111952"><a name="b1625249098111952"></a><a name="b1625249098111952"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002372935233_row2015154184919"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372935233_p13151164111498"><a name="en-us_topic_0000002372935233_p13151164111498"></a><a name="en-us_topic_0000002372935233_p13151164111498"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372935233_p1015164114497"><a name="en-us_topic_0000002372935233_p1015164114497"></a><a name="en-us_topic_0000002372935233_p1015164114497"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372935233_p315104118496"><a name="en-us_topic_0000002372935233_p315104118496"></a><a name="en-us_topic_0000002372935233_p315104118496"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372935233_p515174114914"><a name="en-us_topic_0000002372935233_p515174114914"></a><a name="en-us_topic_0000002372935233_p515174114914"></a>(Reserved) Network port number of the NPU device. Currently, the value can only be set to <strong id="b18673404143220"><a name="b18673404143220"></a><a name="b18673404143220"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002372935233_row1215117411495"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372935233_p101511041104910"><a name="en-us_topic_0000002372935233_p101511041104910"></a><a name="en-us_topic_0000002372935233_p101511041104910"></a>task_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372935233_p2015194114496"><a name="en-us_topic_0000002372935233_p2015194114496"></a><a name="en-us_topic_0000002372935233_p2015194114496"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372935233_p1615110418497"><a name="en-us_topic_0000002372935233_p1615110418497"></a><a name="en-us_topic_0000002372935233_p1615110418497"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372935233_p41511941154910"><a name="en-us_topic_0000002372935233_p41511941154910"></a><a name="en-us_topic_0000002372935233_p41511941154910"></a><strong id="b5528020511"><a name="b5528020511"></a><a name="b5528020511"></a>task_id</strong>: task ID. The value range is [0, 1], which is specified by <strong id="b189961611754"><a name="b189961611754"></a><a name="b189961611754"></a>dcmi_start_hccsping_mesh</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002372935233_row4151141184915"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372935233_p10151174164913"><a name="en-us_topic_0000002372935233_p10151174164913"></a><a name="en-us_topic_0000002372935233_p10151174164913"></a>state</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372935233_p215114114910"><a name="en-us_topic_0000002372935233_p215114114910"></a><a name="en-us_topic_0000002372935233_p215114114910"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372935233_p19151174111490"><a name="en-us_topic_0000002372935233_p19151174111490"></a><a name="en-us_topic_0000002372935233_p19151174111490"></a>unsigned int*</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372935233_p19151114117492"><a name="en-us_topic_0000002372935233_p19151114117492"></a><a name="en-us_topic_0000002372935233_p19151114117492"></a>Status of a resident pingmesh task.</p>
<p id="en-us_topic_0000002372935233_p191511741174916"><a name="en-us_topic_0000002372935233_p191511741174916"></a><a name="en-us_topic_0000002372935233_p191511741174916"></a><strong id="b168253820518"><a name="b168253820518"></a><a name="b168253820518"></a>0</strong>: The resident task is stopped.</p>
<p id="en-us_topic_0000002372935233_p15152141204919"><a name="en-us_topic_0000002372935233_p15152141204919"></a><a name="en-us_topic_0000002372935233_p15152141204919"></a><strong id="b136510107514"><a name="b136510107514"></a><a name="b136510107514"></a>1</strong>: The resident task is running.</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="section1440445105018"></a>**

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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b128365631685641"><a name="b128365631685641"></a><a name="b128365631685641"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="section175612813502"></a>**

None.

**Restrictions<a name="section124361912185014"></a>**

**Table  1** Support in different deployment scenarios

<a name="table75388578524"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1210513304816"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p558011817325"><a name="en-us_topic_0000002515503852_p558011817325"></a><a name="en-us_topic_0000002515503852_p558011817325"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p25806812321"><a name="en-us_topic_0000002515503852_p25806812321"></a><a name="en-us_topic_0000002515503852_p25806812321"></a><strong id="en-us_topic_0000002515503852_b156561347844"><a name="en-us_topic_0000002515503852_b156561347844"></a><a name="en-us_topic_0000002515503852_b156561347844"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p558018833211"><a name="en-us_topic_0000002515503852_p558018833211"></a><a name="en-us_topic_0000002515503852_p558018833211"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b686519481414"><a name="en-us_topic_0000002515503852_b686519481414"></a><a name="en-us_topic_0000002515503852_b686519481414"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p35801189326"><a name="en-us_topic_0000002515503852_p35801189326"></a><a name="en-us_topic_0000002515503852_p35801189326"></a><strong id="en-us_topic_0000002515503852_b398912494411"><a name="en-us_topic_0000002515503852_b398912494411"></a><a name="en-us_topic_0000002515503852_b398912494411"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_row14576182015105"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p13661881916"><a name="en-us_topic_0000002515503852_p13661881916"></a><a name="en-us_topic_0000002515503852_p13661881916"></a><span id="en-us_topic_0000002515503852_ph116612081298"><a name="en-us_topic_0000002515503852_ph116612081298"></a><a name="en-us_topic_0000002515503852_ph116612081298"></a><span id="en-us_topic_0000002515503852_text26611487916"><a name="en-us_topic_0000002515503852_text26611487916"></a><a name="en-us_topic_0000002515503852_text26611487916"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p057642081019"><a name="en-us_topic_0000002515503852_p057642081019"></a><a name="en-us_topic_0000002515503852_p057642081019"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p65761200102"><a name="en-us_topic_0000002515503852_p65761200102"></a><a name="en-us_topic_0000002515503852_p65761200102"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1357610206101"><a name="en-us_topic_0000002515503852_p1357610206101"></a><a name="en-us_topic_0000002515503852_p1357610206101"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row318512127818"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611581596"><a name="en-us_topic_0000002515503852_p86611581596"></a><a name="en-us_topic_0000002515503852_p86611581596"></a><span id="en-us_topic_0000002515503852_text66619818911"><a name="en-us_topic_0000002515503852_text66619818911"></a><a name="en-us_topic_0000002515503852_text66619818911"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1441443298"><a name="en-us_topic_0000002515503852_p1441443298"></a><a name="en-us_topic_0000002515503852_p1441443298"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2420631892"><a name="en-us_topic_0000002515503852_p2420631892"></a><a name="en-us_topic_0000002515503852_p2420631892"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p18425123899"><a name="en-us_topic_0000002515503852_p18425123899"></a><a name="en-us_topic_0000002515503852_p18425123899"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1273713241084"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p56611781094"><a name="en-us_topic_0000002515503852_p56611781094"></a><a name="en-us_topic_0000002515503852_p56611781094"></a><span id="en-us_topic_0000002515503852_text56611281693"><a name="en-us_topic_0000002515503852_text56611281693"></a><a name="en-us_topic_0000002515503852_text56611281693"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p64311736915"><a name="en-us_topic_0000002515503852_p64311736915"></a><a name="en-us_topic_0000002515503852_p64311736915"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p04391434914"><a name="en-us_topic_0000002515503852_p04391434914"></a><a name="en-us_topic_0000002515503852_p04391434914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p244917315919"><a name="en-us_topic_0000002515503852_p244917315919"></a><a name="en-us_topic_0000002515503852_p244917315919"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row7672192219815"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p166611689914"><a name="en-us_topic_0000002515503852_p166611689914"></a><a name="en-us_topic_0000002515503852_p166611689914"></a><span id="en-us_topic_0000002515503852_text126611581798"><a name="en-us_topic_0000002515503852_text126611581798"></a><a name="en-us_topic_0000002515503852_text126611581798"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p12459143996"><a name="en-us_topic_0000002515503852_p12459143996"></a><a name="en-us_topic_0000002515503852_p12459143996"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p10470531895"><a name="en-us_topic_0000002515503852_p10470531895"></a><a name="en-us_topic_0000002515503852_p10470531895"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p12476033912"><a name="en-us_topic_0000002515503852_p12476033912"></a><a name="en-us_topic_0000002515503852_p12476033912"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row153452020881"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611181098"><a name="en-us_topic_0000002515503852_p86611181098"></a><a name="en-us_topic_0000002515503852_p86611181098"></a><span id="en-us_topic_0000002515503852_text16611819911"><a name="en-us_topic_0000002515503852_text16611819911"></a><a name="en-us_topic_0000002515503852_text16611819911"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p134813311917"><a name="en-us_topic_0000002515503852_p134813311917"></a><a name="en-us_topic_0000002515503852_p134813311917"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p3486231596"><a name="en-us_topic_0000002515503852_p3486231596"></a><a name="en-us_topic_0000002515503852_p3486231596"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p44911135913"><a name="en-us_topic_0000002515503852_p44911135913"></a><a name="en-us_topic_0000002515503852_p44911135913"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row20496217988"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p86611689916"><a name="en-us_topic_0000002515503852_p86611689916"></a><a name="en-us_topic_0000002515503852_p86611689916"></a><span id="en-us_topic_0000002515503852_text105131140182910"><a name="en-us_topic_0000002515503852_text105131140182910"></a><a name="en-us_topic_0000002515503852_text105131140182910"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p649613392"><a name="en-us_topic_0000002515503852_p649613392"></a><a name="en-us_topic_0000002515503852_p649613392"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p2050114313914"><a name="en-us_topic_0000002515503852_p2050114313914"></a><a name="en-us_topic_0000002515503852_p2050114313914"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p175075312918"><a name="en-us_topic_0000002515503852_p175075312918"></a><a name="en-us_topic_0000002515503852_p175075312918"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1775216157819"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p766118812915"><a name="en-us_topic_0000002515503852_p766118812915"></a><a name="en-us_topic_0000002515503852_p766118812915"></a><span id="en-us_topic_0000002515503852_text136611481596"><a name="en-us_topic_0000002515503852_text136611481596"></a><a name="en-us_topic_0000002515503852_text136611481596"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p205121037920"><a name="en-us_topic_0000002515503852_p205121037920"></a><a name="en-us_topic_0000002515503852_p205121037920"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p5517131993"><a name="en-us_topic_0000002515503852_p5517131993"></a><a name="en-us_topic_0000002515503852_p5517131993"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p115221437916"><a name="en-us_topic_0000002515503852_p115221437916"></a><a name="en-us_topic_0000002515503852_p115221437916"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row1499855417336"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p48161158173310"><a name="en-us_topic_0000002515503852_p48161158173310"></a><a name="en-us_topic_0000002515503852_p48161158173310"></a><span id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="section2099017164502"></a>**

```c
...
int ret = 0;
int card_id = 0;
int device_id = 0;
int port_id = 0;
unsigned int task_id = 0;
unsigned int state;
ret = dcmi_get_hccsping_mesh_state (card_id, device_id, port_id, task_id, &state);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

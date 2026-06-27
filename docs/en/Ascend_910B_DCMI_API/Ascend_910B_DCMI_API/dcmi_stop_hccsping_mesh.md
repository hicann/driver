# dcmi\_stop\_hccsping\_mesh<a name="EN-US_TOPIC_0000002515503816"></a>

**Prototype<a name="section1153185215497"></a>**

**int dcmi\_stop\_hccsping\_mesh \(int card\_id, int device\_id, int port\_id, unsigned int task\_id\)**

**Description<a name="section7120135716498"></a>**

Stops a resident pingmesh task.

**Parameter Description<a name="section76611617501"></a>**

<a name="table119601757101614"></a>
<table><thead align="left"><tr id="en-us_topic_0000002338977354_row15337135717498"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002338977354_p033775774919"><a name="en-us_topic_0000002338977354_p033775774919"></a><a name="en-us_topic_0000002338977354_p033775774919"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002338977354_p6338857164914"><a name="en-us_topic_0000002338977354_p6338857164914"></a><a name="en-us_topic_0000002338977354_p6338857164914"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002338977354_p733818571492"><a name="en-us_topic_0000002338977354_p733818571492"></a><a name="en-us_topic_0000002338977354_p733818571492"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002338977354_p123381457144919"><a name="en-us_topic_0000002338977354_p123381457144919"></a><a name="en-us_topic_0000002338977354_p123381457144919"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002338977354_row133845714912"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977354_p1933815573492"><a name="en-us_topic_0000002338977354_p1933815573492"></a><a name="en-us_topic_0000002338977354_p1933815573492"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977354_p4338105734919"><a name="en-us_topic_0000002338977354_p4338105734919"></a><a name="en-us_topic_0000002338977354_p4338105734919"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977354_p633815575495"><a name="en-us_topic_0000002338977354_p633815575495"></a><a name="en-us_topic_0000002338977354_p633815575495"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977354_p033845715498"><a name="en-us_topic_0000002338977354_p033845715498"></a><a name="en-us_topic_0000002338977354_p033845715498"></a>Device ID. The supported IDs can be obtained by calling <strong id="b2106824935102857"><a name="b2106824935102857"></a><a name="b2106824935102857"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338977354_row113381457114914"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977354_p13338115711498"><a name="en-us_topic_0000002338977354_p13338115711498"></a><a name="en-us_topic_0000002338977354_p13338115711498"></a>device_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977354_p43386571498"><a name="en-us_topic_0000002338977354_p43386571498"></a><a name="en-us_topic_0000002338977354_p43386571498"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977354_p1433812578497"><a name="en-us_topic_0000002338977354_p1433812578497"></a><a name="en-us_topic_0000002338977354_p1433812578497"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977354_p1833811571495"><a name="en-us_topic_0000002338977354_p1833811571495"></a><a name="en-us_topic_0000002338977354_p1833811571495"></a>Chip ID, which can be obtained by calling <strong id="b67902763102528"><a name="b67902763102528"></a><a name="b67902763102528"></a>dcmi_get_device_id_in_card</strong>. Value range:</p>
<p id="en-us_topic_0000002338977354_p12338115734910"><a name="en-us_topic_0000002338977354_p12338115734910"></a><a name="en-us_topic_0000002338977354_p12338115734910"></a>NPU chip: [0, <strong id="b1316132158111953"><a name="b1316132158111953"></a><a name="b1316132158111953"></a>device_id_max</strong> - 1]</p>
<div class="note" id="note102181227171418"><a name="note102181227171418"></a><a name="note102181227171418"></a><span class="notetitle"> NOTE: </span><div class="notebody"><p id="en-us_topic_0000002515503822_p10218227151413"><a name="en-us_topic_0000002515503822_p10218227151413"></a><a name="en-us_topic_0000002515503822_p10218227151413"></a>The value of <strong id="en-us_topic_0000002515503822_b07404719231"><a name="en-us_topic_0000002515503822_b07404719231"></a><a name="en-us_topic_0000002515503822_b07404719231"></a>device_id_max</strong> is <strong id="en-us_topic_0000002515503822_b18691134810239"><a name="en-us_topic_0000002515503822_b18691134810239"></a><a name="en-us_topic_0000002515503822_b18691134810239"></a>1</strong>. When <strong id="en-us_topic_0000002515503822_b20866105012236"><a name="en-us_topic_0000002515503822_b20866105012236"></a><a name="en-us_topic_0000002515503822_b20866105012236"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b106252524232"><a name="en-us_topic_0000002515503822_b106252524232"></a><a name="en-us_topic_0000002515503822_b106252524232"></a>0</strong>, the NPU chip is used. When <strong id="en-us_topic_0000002515503822_b97321556102310"><a name="en-us_topic_0000002515503822_b97321556102310"></a><a name="en-us_topic_0000002515503822_b97321556102310"></a>device_id</strong> is <strong id="en-us_topic_0000002515503822_b426285819235"><a name="en-us_topic_0000002515503822_b426285819235"></a><a name="en-us_topic_0000002515503822_b426285819235"></a>1</strong>, the MCU chip is used.</p>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000002338977354_row1333895716496"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977354_p83389574491"><a name="en-us_topic_0000002338977354_p83389574491"></a><a name="en-us_topic_0000002338977354_p83389574491"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977354_p143381057164918"><a name="en-us_topic_0000002338977354_p143381057164918"></a><a name="en-us_topic_0000002338977354_p143381057164918"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977354_p1338145711494"><a name="en-us_topic_0000002338977354_p1338145711494"></a><a name="en-us_topic_0000002338977354_p1338145711494"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977354_p10338185794912"><a name="en-us_topic_0000002338977354_p10338185794912"></a><a name="en-us_topic_0000002338977354_p10338185794912"></a>(Reserved) Network port number of the NPU device. Currently, the value can only be set to <strong id="b21328043623221"><a name="b21328043623221"></a><a name="b21328043623221"></a>0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002338977354_row233955716491"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002338977354_p6339115719496"><a name="en-us_topic_0000002338977354_p6339115719496"></a><a name="en-us_topic_0000002338977354_p6339115719496"></a>task_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002338977354_p1933917576490"><a name="en-us_topic_0000002338977354_p1933917576490"></a><a name="en-us_topic_0000002338977354_p1933917576490"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002338977354_p1833918570498"><a name="en-us_topic_0000002338977354_p1833918570498"></a><a name="en-us_topic_0000002338977354_p1833918570498"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002338977354_p1633975754914"><a name="en-us_topic_0000002338977354_p1633975754914"></a><a name="en-us_topic_0000002338977354_p1633975754914"></a>Task ID. The value range is [0, 1], which is specified by <strong id="b1277273599356"><a name="b1277273599356"></a><a name="b1277273599356"></a>dcmi_start_hccsping_mesh</strong>.</p>
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
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b29813170785641"><a name="b29813170785641"></a><a name="b29813170785641"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
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
ret = dcmi_stop_hccsping_mesh (card_id, device_id, port_id, task_id);
if (ret != 0){
    // todo: Record logs.
    return ret;
}
...
```

# dcmiv2\_get\_device\_error\_code\_list<a name="EN-US_TOPIC_0000002348043821"></a>

## Prototype<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_toc533412077"></a>

**int dcmiv2\_get\_device\_error\_code\_list\(int dev\_id, int \*error\_count, unsigned int \*error\_code\_list, unsigned int list\_len\)**

## Description<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_toc533412078"></a>

Obtains the error code of a device.

## Parameter Description<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_toc533412079"></a>

<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10021890"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10021890"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p6466753"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p6466753"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.56%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p54045009"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p54045009"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="49.45%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p15569626"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p15569626"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7711145152918"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7711145152918"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p671116522914"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p671116522914"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1771116572910"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1771116572910"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="49.45%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1385334683112"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1385334683112"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1385334683112"></a>error_count</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p185314612314"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p185314612314"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p185314612314"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p19853204613117"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p19853204613117"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p19853204613117"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="49.45%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1785320464310"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1785320464310"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1785320464310"></a>Error code count, which ranges from <strong id="b13699204515616"><a name="b13699204515616"></a><a name="b13699204515616"></a>0</strong> to <strong id="b969910451616"><a name="b969910451616"></a><a name="b969910451616"></a>128</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_row5580144218312"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p88531346163115"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p88531346163115"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p88531346163115"></a>error_code_list</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10854046193119"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10854046193119"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p10854046193119"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p18541846193117"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p18541846193117"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p18541846193117"></a>unsigned int *</p>
</td>
<td class="cellrowborder" valign="top" width="49.45%" headers="mcps1.1.5.1.4 "><p id="p19941116142619"><a name="p19941116142619"></a><a name="p19941116142619"></a>Error code list.</p>
<p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p985494623117"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p985494623117"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p985494623117"></a>If the command output contains an error code, refer to the <span id="ph173171111175516"><a name="ph173171111175516"></a><a name="ph173171111175516"></a>Ascend 950 Product Black Box Error Code List</span> or <span id="ph13171711195520"><a name="ph13171711195520"></a><a name="ph13171711195520"></a>Ascend 950 Product Health Management Fault Definitions</span> to check it.</p>
</td>
</tr>
<tr id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_row15525645143119"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p48541469314"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p48541469314"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p48541469314"></a>list_len</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1185410467310"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1185410467310"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p1185410467310"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.56%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7854946143110"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7854946143110"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p7854946143110"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="49.45%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p188542046173118"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p188542046173118"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_p188542046173118"></a>Length of <strong id="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_b145964367523"><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_b145964367523"></a><a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_b145964367523"></a>error_code_list</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p65514914017"><a name="en-us_topic_0000002347924121_p65514914017"></a><a name="en-us_topic_0000002347924121_p65514914017"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p56108061"><a name="en-us_topic_0000002347924121_p56108061"></a><a name="en-us_topic_0000002347924121_p56108061"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1855189908"><a name="en-us_topic_0000002347924121_p1855189908"></a><a name="en-us_topic_0000002347924121_p1855189908"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10771327123917"><a name="en-us_topic_0000002347924121_p10771327123917"></a><a name="en-us_topic_0000002347924121_p10771327123917"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><strong id="en-us_topic_0000002347924121_b5395653155415"><a name="en-us_topic_0000002347924121_b5395653155415"></a><a name="en-us_topic_0000002347924121_b5395653155415"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b16340205411546"><a name="en-us_topic_0000002347924121_b16340205411546"></a><a name="en-us_topic_0000002347924121_b16340205411546"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p56110815619"><a name="en-us_topic_0000002347924121_p56110815619"></a><a name="en-us_topic_0000002347924121_p56110815619"></a><strong id="en-us_topic_0000002347924121_b1325919551546"><a name="en-us_topic_0000002347924121_b1325919551546"></a><a name="en-us_topic_0000002347924121_b1325919551546"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><strong id="en-us_topic_0000002347924121_b7873135516543"><a name="en-us_topic_0000002347924121_b7873135516543"></a><a name="en-us_topic_0000002347924121_b7873135516543"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p977116273398"><a name="en-us_topic_0000002347924121_p977116273398"></a><a name="en-us_topic_0000002347924121_p977116273398"></a><strong id="en-us_topic_0000002347924121_b868415562549"><a name="en-us_topic_0000002347924121_b868415562549"></a><a name="en-us_topic_0000002347924121_b868415562549"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p144147361596"><a name="en-us_topic_0000002347924121_p144147361596"></a><a name="en-us_topic_0000002347924121_p144147361596"></a><span id="en-us_topic_0000002347924121_ph12140626193614"><a name="en-us_topic_0000002347924121_ph12140626193614"></a><a name="en-us_topic_0000002347924121_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13356146465"><a name="en-us_topic_0000002347924121_p13356146465"></a><a name="en-us_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p19351314124620"><a name="en-us_topic_0000002347924121_p19351314124620"></a><a name="en-us_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p1577514751713"><a name="en-us_topic_0000002347924121_p1577514751713"></a><a name="en-us_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1435121434611"><a name="en-us_topic_0000002347924121_p1435121434611"></a><a name="en-us_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p8318151920427"><a name="en-us_topic_0000002347924121_p8318151920427"></a><a name="en-us_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p56258171305"><a name="en-us_topic_0000002347924121_p56258171305"></a><a name="en-us_topic_0000002347924121_p56258171305"></a><span id="en-us_topic_0000002347924121_ph15391145912019"><a name="en-us_topic_0000002347924121_ph15391145912019"></a><a name="en-us_topic_0000002347924121_ph15391145912019"></a>Note: <strong id="en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251307153_en-us_topic_0000001178054662_en-us_topic_0000001147730881_toc533412083"></a>

```c
#define ERROR_CODE_MAX_NUM              (128)
...
int ret = 0;
int dev_id = 0;
int error_count = 0;
unsigned int error_code_list[ERROR_CODE_MAX_NUM] = {0};
ret = dcmiv2_get_device_error_code_list(dev_id, &error_count, error_code_list, ERROR_CODE_MAX_NUM);
...
```

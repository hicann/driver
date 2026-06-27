# dcmiv2\_get\_device\_mac\_cnt<a name="EN-US_TOPIC_0000002314204850"></a>

## Prototype<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_toc533412077"></a>

**int dcmiv2\_get\_device\_mac\_cnt\(int dev\_id, int \*count\)**

## Description<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_toc533412078"></a>

Queries the number of MAC addresses of the current device.

## Parameter Description<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_toc533412079"></a>

<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p10021890"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p10021890"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p6466753"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p6466753"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p54045009"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p54045009"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="53.25%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p15569626"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p15569626"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p7711145152918"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p7711145152918"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p671116522914"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p671116522914"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1771116572910"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1771116572910"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="53.25%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p65122018413"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p65122018413"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p65122018413"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1456209414"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1456209414"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p1456209414"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p78615251246"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p78615251246"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p78615251246"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="53.25%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p19519201418"><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p19519201418"></a><a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_p19519201418"></a>MAC address count, which can be <strong id="b4550155971920"><a name="b4550155971920"></a><a name="b4550155971920"></a>0</strong> or <strong id="b62292192010"><a name="b62292192010"></a><a name="b62292192010"></a>1</strong>.</p>
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

## Restrictions<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table116394134134"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row26461043103219"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p06463434324"><a name="en-us_topic_0000002347924121_p06463434324"></a><a name="en-us_topic_0000002347924121_p06463434324"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p15646043123214"><a name="en-us_topic_0000002347924121_p15646043123214"></a><a name="en-us_topic_0000002347924121_p15646043123214"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1464614435324"><a name="en-us_topic_0000002347924121_p1464614435324"></a><a name="en-us_topic_0000002347924121_p1464614435324"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p14646174353210"><a name="en-us_topic_0000002347924121_p14646174353210"></a><a name="en-us_topic_0000002347924121_p14646174353210"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p3647104343214"><a name="en-us_topic_0000002347924121_p3647104343214"></a><a name="en-us_topic_0000002347924121_p3647104343214"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16472433324"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p16471543143217"><a name="en-us_topic_0000002347924121_p16471543143217"></a><a name="en-us_topic_0000002347924121_p16471543143217"></a><strong id="en-us_topic_0000002347924121_b1919763744"><a name="en-us_topic_0000002347924121_b1919763744"></a><a name="en-us_topic_0000002347924121_b1919763744"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p664754323210"><a name="en-us_topic_0000002347924121_p664754323210"></a><a name="en-us_topic_0000002347924121_p664754323210"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b892351261"><a name="en-us_topic_0000002347924121_b892351261"></a><a name="en-us_topic_0000002347924121_b892351261"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p66471543173215"><a name="en-us_topic_0000002347924121_p66471543173215"></a><a name="en-us_topic_0000002347924121_p66471543173215"></a><strong id="en-us_topic_0000002347924121_b125134011"><a name="en-us_topic_0000002347924121_b125134011"></a><a name="en-us_topic_0000002347924121_b125134011"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p4647943123210"><a name="en-us_topic_0000002347924121_p4647943123210"></a><a name="en-us_topic_0000002347924121_p4647943123210"></a><strong id="en-us_topic_0000002347924121_b922706339"><a name="en-us_topic_0000002347924121_b922706339"></a><a name="en-us_topic_0000002347924121_b922706339"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p176472043163218"><a name="en-us_topic_0000002347924121_p176472043163218"></a><a name="en-us_topic_0000002347924121_p176472043163218"></a><strong id="en-us_topic_0000002347924121_b202429450"><a name="en-us_topic_0000002347924121_b202429450"></a><a name="en-us_topic_0000002347924121_b202429450"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row964714313220"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p664734316322"><a name="en-us_topic_0000002347924121_p664734316322"></a><a name="en-us_topic_0000002347924121_p664734316322"></a><span id="en-us_topic_0000002347924121_ph9647194317328"><a name="en-us_topic_0000002347924121_ph9647194317328"></a><a name="en-us_topic_0000002347924121_ph9647194317328"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13924182025119"><a name="en-us_topic_0000002347924121_p13924182025119"></a><a name="en-us_topic_0000002347924121_p13924182025119"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p109262206516"><a name="en-us_topic_0000002347924121_p109262206516"></a><a name="en-us_topic_0000002347924121_p109262206516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p8926172095110"><a name="en-us_topic_0000002347924121_p8926172095110"></a><a name="en-us_topic_0000002347924121_p8926172095110"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row176481543163219"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p26481431322"><a name="en-us_topic_0000002347924121_p26481431322"></a><a name="en-us_topic_0000002347924121_p26481431322"></a><span id="en-us_topic_0000002347924121_ph9648104363220"><a name="en-us_topic_0000002347924121_ph9648104363220"></a><a name="en-us_topic_0000002347924121_ph9648104363220"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001251107205_en-us_topic_0000001223172945_en-us_topic_0000001148164483_toc533412083"></a>

```c
...
int ret = 0;
int count = -1;
int dev_id = 0;
ret = dcmiv2_get_device_mac_cnt(dev_id, &count);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

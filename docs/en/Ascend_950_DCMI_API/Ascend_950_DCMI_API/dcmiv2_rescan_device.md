# dcmiv2\_rescan\_device<a name="EN-US_TOPIC_0000002314045010"></a>

## Prototype<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_toc533412077"></a>

**int dcmiv2\_rescan\_device\(int dev\_id\)**

## Description<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_toc533412078"></a>

Rescans a device.

## Parameter Description<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_toc533412079"></a>

<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p10021890"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p10021890"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p6466753"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p6466753"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p54045009"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p54045009"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p15569626"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p15569626"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p7711145152918"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p7711145152918"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p671116522914"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p671116522914"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p1771116572910"><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p1771116572910"></a><a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
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

## Restrictions<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row1896512434515"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p6965943158"><a name="en-us_topic_0000002347924121_p6965943158"></a><a name="en-us_topic_0000002347924121_p6965943158"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p11965184315514"><a name="en-us_topic_0000002347924121_p11965184315514"></a><a name="en-us_topic_0000002347924121_p11965184315514"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p69657431958"><a name="en-us_topic_0000002347924121_p69657431958"></a><a name="en-us_topic_0000002347924121_p69657431958"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p129651243752"><a name="en-us_topic_0000002347924121_p129651243752"></a><a name="en-us_topic_0000002347924121_p129651243752"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p096511431456"><a name="en-us_topic_0000002347924121_p096511431456"></a><a name="en-us_topic_0000002347924121_p096511431456"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row596544317511"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p19965343955"><a name="en-us_topic_0000002347924121_p19965343955"></a><a name="en-us_topic_0000002347924121_p19965343955"></a><strong id="en-us_topic_0000002347924121_b1387538872"><a name="en-us_topic_0000002347924121_b1387538872"></a><a name="en-us_topic_0000002347924121_b1387538872"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p1196534313515"><a name="en-us_topic_0000002347924121_p1196534313515"></a><a name="en-us_topic_0000002347924121_p1196534313515"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b1809654715"><a name="en-us_topic_0000002347924121_b1809654715"></a><a name="en-us_topic_0000002347924121_b1809654715"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p1396510439515"><a name="en-us_topic_0000002347924121_p1396510439515"></a><a name="en-us_topic_0000002347924121_p1396510439515"></a><strong id="en-us_topic_0000002347924121_b1430704680"><a name="en-us_topic_0000002347924121_b1430704680"></a><a name="en-us_topic_0000002347924121_b1430704680"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p396564310511"><a name="en-us_topic_0000002347924121_p396564310511"></a><a name="en-us_topic_0000002347924121_p396564310511"></a><strong id="en-us_topic_0000002347924121_b324089829"><a name="en-us_topic_0000002347924121_b324089829"></a><a name="en-us_topic_0000002347924121_b324089829"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p1496519431356"><a name="en-us_topic_0000002347924121_p1496519431356"></a><a name="en-us_topic_0000002347924121_p1496519431356"></a><strong id="en-us_topic_0000002347924121_b754491812"><a name="en-us_topic_0000002347924121_b754491812"></a><a name="en-us_topic_0000002347924121_b754491812"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row096512432519"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p18965144315510"><a name="en-us_topic_0000002347924121_p18965144315510"></a><a name="en-us_topic_0000002347924121_p18965144315510"></a><span id="en-us_topic_0000002347924121_ph1796514431955"><a name="en-us_topic_0000002347924121_ph1796514431955"></a><a name="en-us_topic_0000002347924121_ph1796514431955"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p1023112549511"><a name="en-us_topic_0000002347924121_p1023112549511"></a><a name="en-us_topic_0000002347924121_p1023112549511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p92436547518"><a name="en-us_topic_0000002347924121_p92436547518"></a><a name="en-us_topic_0000002347924121_p92436547518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p725495412518"><a name="en-us_topic_0000002347924121_p725495412518"></a><a name="en-us_topic_0000002347924121_p725495412518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p5277115413515"><a name="en-us_topic_0000002347924121_p5277115413515"></a><a name="en-us_topic_0000002347924121_p5277115413515"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p82958547519"><a name="en-us_topic_0000002347924121_p82958547519"></a><a name="en-us_topic_0000002347924121_p82958547519"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row296612436519"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p8966943858"><a name="en-us_topic_0000002347924121_p8966943858"></a><a name="en-us_topic_0000002347924121_p8966943858"></a><span id="en-us_topic_0000002347924121_ph1296615432517"><a name="en-us_topic_0000002347924121_ph1296615432517"></a><a name="en-us_topic_0000002347924121_ph1296615432517"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001206307234_en-us_topic_0000001223494361_en-us_topic_0000001146379717_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
ret = dcmiv2_rescan_device(dev_id);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}
...
```

# dcmiv2\_get\_device\_outband\_channel\_state<a name="EN-US_TOPIC_0000002348043973"></a>

## Prototype<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412077"></a>

**int dcmiv2\_get\_device\_outband\_channel\_state\(int dev\_id, int \*channel\_state\)**

## Description<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412078"></a>

Queries the out-of-band channel status.

## Parameter Description<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412079"></a>

<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row7580267"><th class="cellrowborder" valign="top" width="18.35%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.64%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.89%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="48.120000000000005%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row19957136105419"><td class="cellrowborder" valign="top" width="18.35%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_row10560021192510"><td class="cellrowborder" valign="top" width="18.35%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p6853555122118"></a>channel_state</p>
</td>
<td class="cellrowborder" valign="top" width="15.64%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148536555217"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.89%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p148531055182112"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="48.120000000000005%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_p377514553591"></a>Out-of-band channel status.</p>
<a name="ul7729135913583"></a><a name="ul7729135913583"></a><ul id="ul7729135913583"><li><strong id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b711001335820"></a>1</strong>: The channel is normal.</li><li><strong id="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"></a><a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_b114336159589"></a>0</strong>: The channel is abnormal.</li></ul>
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

## Restrictions<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table12176192314614"></a>
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

## Example<a name="en-us_topic_0000001251107203_en-us_topic_0000001177894684_en-us_topic_0000001115026454_toc533412083"></a>

```c
...
int ret;
int dev_id = 0;
int channel_state = 0;
ret = dcmiv2_get_device_outband_channel_state(dev_id, &channel_state);
...
```

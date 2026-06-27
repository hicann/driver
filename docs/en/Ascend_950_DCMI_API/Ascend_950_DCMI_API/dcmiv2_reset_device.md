# dcmiv2\_reset\_device<a name="EN-US_TOPIC_0000002348043977"></a>

## Prototype<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412077"></a>

**int dcmiv2\_reset\_device\(int dev\_id, enum dcmi\_reset\_channel channel\_type\)**

## Description<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412078"></a>

Resets a chip.

## Parameter Description<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412079"></a>

<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row45631627"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001148530297_p11747451997"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
<div class="note" id="note9881134113272"><a name="note9881134113272"></a><a name="note9881134113272"></a><span class="notetitle"> NOTE: </span><div class="notebody"><a name="ul6966185610185"></a><a name="ul6966185610185"></a><ul id="ul6966185610185"><li>When this API is used for an in-band chip reset, <strong id="b891017854115"><a name="b891017854115"></a><a name="b891017854115"></a>dev_id</strong> can be set to <strong id="b1691038174114"><a name="b1691038174114"></a><a name="b1691038174114"></a>0xFF</strong> to initiate a full-card reset. This functionality is supported in the PM (bare metal) scenario (running as <strong id="b991011814112"><a name="b991011814112"></a><a name="b991011814112"></a>root</strong>) and in the PM + privileged container scenario.</li><li>When this API is used to reset a chip in out-of-band mode, <strong id="b9456031192916"><a name="b9456031192916"></a><a name="b9456031192916"></a>dev_id</strong> cannot be set to <strong id="b1794293382912"><a name="b1794293382912"></a><a name="b1794293382912"></a>0xFF</strong>.</li></ul>
</div></div>
</td>
</tr>
<tr id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_row137415397316"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p1622474112317"></a>channel_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p19225441193116"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p102251441133110"></a>enum dcmi_reset_channel</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"></a><a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_p3511101013286"></a>Reset channel.</p>
<pre class="codeblock" id="codeblock74511251101313"><a name="codeblock74511251101313"></a><a name="codeblock74511251101313"></a>enum dcmi_reset_channel {
OUTBAND_CHANNEL = 0, // Out-of-band reset
INBAND_CHANNEL = 1 // In-band reset
}</pre>
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

## Restrictions<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table6183194116432"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row9596171719419"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p1059661716417"><a name="en-us_topic_0000002347924121_p1059661716417"></a><a name="en-us_topic_0000002347924121_p1059661716417"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p115964174411"><a name="en-us_topic_0000002347924121_p115964174411"></a><a name="en-us_topic_0000002347924121_p115964174411"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p3663614615"><a name="en-us_topic_0000002347924121_p3663614615"></a><a name="en-us_topic_0000002347924121_p3663614615"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1559620177411"><a name="en-us_topic_0000002347924121_p1559620177411"></a><a name="en-us_topic_0000002347924121_p1559620177411"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10613162423514"><a name="en-us_topic_0000002347924121_p10613162423514"></a><a name="en-us_topic_0000002347924121_p10613162423514"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row959614172418"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p15596151714414"><a name="en-us_topic_0000002347924121_p15596151714414"></a><a name="en-us_topic_0000002347924121_p15596151714414"></a><strong id="b19940184211426"><a name="b19940184211426"></a><a name="b19940184211426"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p559611171344"><a name="en-us_topic_0000002347924121_p559611171344"></a><a name="en-us_topic_0000002347924121_p559611171344"></a>Running User Group (Non-<strong id="b95070447424"><a name="b95070447424"></a><a name="b95070447424"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p866318118620"><a name="en-us_topic_0000002347924121_p866318118620"></a><a name="en-us_topic_0000002347924121_p866318118620"></a><strong id="b7734174511421"><a name="b7734174511421"></a><a name="b7734174511421"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p1959614171345"><a name="en-us_topic_0000002347924121_p1959614171345"></a><a name="en-us_topic_0000002347924121_p1959614171345"></a><strong id="b76931446184210"><a name="b76931446184210"></a><a name="b76931446184210"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p82264478360"><a name="en-us_topic_0000002347924121_p82264478360"></a><a name="en-us_topic_0000002347924121_p82264478360"></a><strong id="b27161747114215"><a name="b27161747114215"></a><a name="b27161747114215"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row135967178414"><td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p2596121712410"><a name="en-us_topic_0000002347924121_p2596121712410"></a><a name="en-us_topic_0000002347924121_p2596121712410"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p6596111711414"><a name="en-us_topic_0000002347924121_p6596111711414"></a><a name="en-us_topic_0000002347924121_p6596111711414"></a>Y (in-band only)</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p25961017947"><a name="en-us_topic_0000002347924121_p25961017947"></a><a name="en-us_topic_0000002347924121_p25961017947"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p1086932715317"><a name="en-us_topic_0000002347924121_p1086932715317"></a><a name="en-us_topic_0000002347924121_p1086932715317"></a>Y (in-band only)</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1529918247412"><a name="en-us_topic_0000002347924121_p1529918247412"></a><a name="en-us_topic_0000002347924121_p1529918247412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="p18972125513302"><a name="p18972125513302"></a><a name="p18972125513302"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row155971917944"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p18597217849"><a name="en-us_topic_0000002347924121_p18597217849"></a><a name="en-us_topic_0000002347924121_p18597217849"></a><span id="ph1862551334320"><a name="ph1862551334320"></a><a name="ph1862551334320"></a>Note: <strong id="b262491310434"><a name="b262491310434"></a><a name="b262491310434"></a>Y</strong> indicates that the function is supported, <strong id="b8624813184310"><a name="b8624813184310"></a><a name="b8624813184310"></a>N</strong> indicates that the function is not supported, and <strong id="b6625413124311"><a name="b6625413124311"></a><a name="b6625413124311"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001206467196_en-us_topic_0000001177894694_en-us_topic_0000001099300038_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
enum dcmi_reset_channel channel_type = INBAND_CHANNEL;
ret = dcmiv2_reset_device(dev_id, channel_type);
if (ret != 0) {
    // TODO: Record logs.
    return ret;
}
…
```

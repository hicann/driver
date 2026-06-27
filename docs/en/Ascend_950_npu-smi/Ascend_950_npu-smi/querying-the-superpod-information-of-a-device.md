# Querying the SuperPoD Information of a Device<a name="EN-US_TOPIC_0000002516426717"></a>

## Function<a name="section1597791992519"></a>

This command is used to query the SuperPoD information of a device.

## Syntax<a name="section1751092614258"></a>

`npu-smi info -t spod-info -i dev_id`

## Parameters<a name="section684613337255"></a>

<a name="table6497194623914"></a>
<table><thead align="left"><tr id="row952944613915"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p10530204663914"><a name="p10530204663914"></a><a name="p10530204663914"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p175301246133912"><a name="p175301246133912"></a><a name="p175301246133912"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row0530446143915"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p253084618395"><a name="p253084618395"></a><a name="p253084618395"></a><span id="ph1983314174712"><a name="ph1983314174712"></a><a name="ph1983314174712"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="section1229174022519"></a>

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row1446320325484"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p1246373219488"><a name="en-us_topic_0000002484466758_p1246373219488"></a><a name="en-us_topic_0000002484466758_p1246373219488"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p1646323210484"><a name="en-us_topic_0000002484466758_p1646323210484"></a><a name="en-us_topic_0000002484466758_p1646323210484"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p13463332124812"><a name="en-us_topic_0000002484466758_p13463332124812"></a><a name="en-us_topic_0000002484466758_p13463332124812"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p174631632174810"><a name="en-us_topic_0000002484466758_p174631632174810"></a><a name="en-us_topic_0000002484466758_p174631632174810"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p2463163254810"><a name="en-us_topic_0000002484466758_p2463163254810"></a><a name="en-us_topic_0000002484466758_p2463163254810"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row134631132114819"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p15463133224819"><a name="en-us_topic_0000002484466758_p15463133224819"></a><a name="en-us_topic_0000002484466758_p15463133224819"></a><strong id="en-us_topic_0000002484466758_b879240669"><a name="en-us_topic_0000002484466758_b879240669"></a><a name="en-us_topic_0000002484466758_b879240669"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p146314327484"><a name="en-us_topic_0000002484466758_p146314327484"></a><a name="en-us_topic_0000002484466758_p146314327484"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1242403872"><a name="en-us_topic_0000002484466758_b1242403872"></a><a name="en-us_topic_0000002484466758_b1242403872"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p1346316323487"><a name="en-us_topic_0000002484466758_p1346316323487"></a><a name="en-us_topic_0000002484466758_p1346316323487"></a><strong id="en-us_topic_0000002484466758_b825338145"><a name="en-us_topic_0000002484466758_b825338145"></a><a name="en-us_topic_0000002484466758_b825338145"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p94635327482"><a name="en-us_topic_0000002484466758_p94635327482"></a><a name="en-us_topic_0000002484466758_p94635327482"></a><strong id="en-us_topic_0000002484466758_b628664973"><a name="en-us_topic_0000002484466758_b628664973"></a><a name="en-us_topic_0000002484466758_b628664973"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p2463232164818"><a name="en-us_topic_0000002484466758_p2463232164818"></a><a name="en-us_topic_0000002484466758_p2463232164818"></a><strong id="en-us_topic_0000002484466758_b17213179579"><a name="en-us_topic_0000002484466758_b17213179579"></a><a name="en-us_topic_0000002484466758_b17213179579"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row154631832174811"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p14463183204810"><a name="en-us_topic_0000002484466758_p14463183204810"></a><a name="en-us_topic_0000002484466758_p14463183204810"></a><span id="en-us_topic_0000002484466758_ph046310323481"><a name="en-us_topic_0000002484466758_ph046310323481"></a><a name="en-us_topic_0000002484466758_ph046310323481"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_p1154133834814"><a name="en-us_topic_0000002484466758_p1154133834814"></a><a name="en-us_topic_0000002484466758_p1154133834814"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_p15625385481"><a name="en-us_topic_0000002484466758_p15625385481"></a><a name="en-us_topic_0000002484466758_p15625385481"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p37043884812"><a name="en-us_topic_0000002484466758_p37043884812"></a><a name="en-us_topic_0000002484466758_p37043884812"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p17836381488"><a name="en-us_topic_0000002484466758_p17836381488"></a><a name="en-us_topic_0000002484466758_p17836381488"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p179717384485"><a name="en-us_topic_0000002484466758_p179717384485"></a><a name="en-us_topic_0000002484466758_p179717384485"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row184647328486"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p10464932174818"><a name="en-us_topic_0000002484466758_p10464932174818"></a><a name="en-us_topic_0000002484466758_p10464932174818"></a>Note: <strong id="en-us_topic_0000002484466758_b1219450132516"><a name="en-us_topic_0000002484466758_b1219450132516"></a><a name="en-us_topic_0000002484466758_b1219450132516"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_b720115020256"><a name="en-us_topic_0000002484466758_b720115020256"></a><a name="en-us_topic_0000002484466758_b720115020256"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_b02013503259"><a name="en-us_topic_0000002484466758_b02013503259"></a><a name="en-us_topic_0000002484466758_b02013503259"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section738295551114"></a>

Query the SuperPoD information of device 0.

```bash
npu-smi info -t spod-info -i 0
```

```text
This device does not support querying spod-info.
```

Note: This command is not supported by the device. Therefore, "This device does not support  _xxx_" is displayed in the command output.

## Output Description<a name="section851717212517"></a>

None

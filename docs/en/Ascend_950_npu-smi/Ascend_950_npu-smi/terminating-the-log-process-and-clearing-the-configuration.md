# Terminating the Log Process and Clearing the Configuration<a name="EN-US_TOPIC_0000002523931940"></a>

## Function<a name="section143092264417"></a>

The  **npu-smi set -t clear-syslog-cfg**  command is used to terminate all processes that continuously collect device logs and to clear the related configuration.

## Syntax<a name="section13508430152616"></a>

**npu-smi set -t clear-syslog-cfg**

## Parameters<a name="section1518211201813"></a>

None

## Usage Instruction<a name="section1751991171815"></a>

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row2056819579256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p10568457202515"><a name="en-us_topic_0000002484466758_p10568457202515"></a><a name="en-us_topic_0000002484466758_p10568457202515"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p3568155712520"><a name="en-us_topic_0000002484466758_p3568155712520"></a><a name="en-us_topic_0000002484466758_p3568155712520"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p7568757122511"><a name="en-us_topic_0000002484466758_p7568757122511"></a><a name="en-us_topic_0000002484466758_p7568757122511"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p1556812578254"><a name="en-us_topic_0000002484466758_p1556812578254"></a><a name="en-us_topic_0000002484466758_p1556812578254"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p105681557162517"><a name="en-us_topic_0000002484466758_p105681557162517"></a><a name="en-us_topic_0000002484466758_p105681557162517"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row185688570253"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p175691857172519"><a name="en-us_topic_0000002484466758_p175691857172519"></a><a name="en-us_topic_0000002484466758_p175691857172519"></a><strong id="en-us_topic_0000002484466758_b1884169617"><a name="en-us_topic_0000002484466758_b1884169617"></a><a name="en-us_topic_0000002484466758_b1884169617"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p1056925762517"><a name="en-us_topic_0000002484466758_p1056925762517"></a><a name="en-us_topic_0000002484466758_p1056925762517"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1510091906"><a name="en-us_topic_0000002484466758_b1510091906"></a><a name="en-us_topic_0000002484466758_b1510091906"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p1256975772514"><a name="en-us_topic_0000002484466758_p1256975772514"></a><a name="en-us_topic_0000002484466758_p1256975772514"></a><strong id="en-us_topic_0000002484466758_b722667928"><a name="en-us_topic_0000002484466758_b722667928"></a><a name="en-us_topic_0000002484466758_b722667928"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p2569157132518"><a name="en-us_topic_0000002484466758_p2569157132518"></a><a name="en-us_topic_0000002484466758_p2569157132518"></a><strong id="en-us_topic_0000002484466758_b527740528"><a name="en-us_topic_0000002484466758_b527740528"></a><a name="en-us_topic_0000002484466758_b527740528"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p656975711257"><a name="en-us_topic_0000002484466758_p656975711257"></a><a name="en-us_topic_0000002484466758_p656975711257"></a><strong id="en-us_topic_0000002484466758_b1518861502"><a name="en-us_topic_0000002484466758_b1518861502"></a><a name="en-us_topic_0000002484466758_b1518861502"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row65691257162516"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p1356905716259"><a name="en-us_topic_0000002484466758_p1356905716259"></a><a name="en-us_topic_0000002484466758_p1356905716259"></a><span id="en-us_topic_0000002484466758_ph1569135714257"><a name="en-us_topic_0000002484466758_ph1569135714257"></a><a name="en-us_topic_0000002484466758_ph1569135714257"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_p15569657112515"><a name="en-us_topic_0000002484466758_p15569657112515"></a><a name="en-us_topic_0000002484466758_p15569657112515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_p16569257142516"><a name="en-us_topic_0000002484466758_p16569257142516"></a><a name="en-us_topic_0000002484466758_p16569257142516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p127191613267"><a name="en-us_topic_0000002484466758_p127191613267"></a><a name="en-us_topic_0000002484466758_p127191613267"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p1356945762511"><a name="en-us_topic_0000002484466758_p1356945762511"></a><a name="en-us_topic_0000002484466758_p1356945762511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p7569135772519"><a name="en-us_topic_0000002484466758_p7569135772519"></a><a name="en-us_topic_0000002484466758_p7569135772519"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row55691557132514"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p195699573251"><a name="en-us_topic_0000002484466758_p195699573251"></a><a name="en-us_topic_0000002484466758_p195699573251"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section755517298271"></a>

Terminate all processes that continuously collect device logs and clear the related configuration.

```bash
npu-smi set -t clear-syslog-cfg
```

```text
Clear syslog config success.
```

## Output Description<a name="en-us_topic_0000001220416514_en-us_topic_0000001168887283_section29761716101314"></a>

None

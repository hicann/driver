# Querying the Log Dumping Configuration<a name="EN-US_TOPIC_0000002516546683"></a>

## Function<a name="section394911416273"></a>

This command is used to query the log dumping configuration, including persistence mode status, log capacity level, storage path, and the process of continuously collecting device logs.

## Syntax<a name="section49511814152711"></a>

`npu-smi info -t sys-log-info`

## Parameters<a name="section1518211201813"></a>

None

## Usage Instruction<a name="section796341422718"></a>

If the log dumping configuration fails to be queried and the message "ERROR: The configuration file has been maliciously modified, please clear configuration and stop syslog collecting process first. Failed to query "sys-log-info" info." is returned, run the  **npu-smi set -t clear-syslog-cfg**  command to restore the configuration file to the default settings and terminate the log dumping process, and then query the log dumping configuration again.

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

## Example<a name="section1896451462719"></a>

Query the log dumping configuration.

```bash
npu-smi info -t sys-log-info
```

```text
Current syslog dump config recover mode : disable
Current syslog dump config gear         : NA
Current syslog dump config path         : NA
```

## Output Description<a name="section896913148274"></a>

**Table  2**  Description of the displayed information

<a name="table209781414182710"></a>
<table><thead align="left"><tr id="row537315122717"><th class="cellrowborder" valign="top" width="43.43%" id="mcps1.2.3.1.1"><p id="p203791511277"><a name="p203791511277"></a><a name="p203791511277"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="56.57%" id="mcps1.2.3.1.2"><p id="p19371415182713"><a name="p19371415182713"></a><a name="p19371415182713"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row437191512719"><td class="cellrowborder" valign="top" width="43.43%" headers="mcps1.2.3.1.1 "><p id="p73704183550"><a name="p73704183550"></a><a name="p73704183550"></a>Current syslog dump config recover mode</p>
</td>
<td class="cellrowborder" valign="top" width="56.57%" headers="mcps1.2.3.1.2 "><p id="p337041885520"><a name="p337041885520"></a><a name="p337041885520"></a>Persistence mode for log configuration (<strong id="b13462173418502"><a name="b13462173418502"></a><a name="b13462173418502"></a>disable</strong> and <strong id="b24621134135018"><a name="b24621134135018"></a><a name="b24621134135018"></a>enable</strong>).</p>
</td>
</tr>
<tr id="row199846292557"><td class="cellrowborder" valign="top" width="43.43%" headers="mcps1.2.3.1.1 "><p id="p1798413291558"><a name="p1798413291558"></a><a name="p1798413291558"></a>Current syslog dump config gear</p>
</td>
<td class="cellrowborder" valign="top" width="56.57%" headers="mcps1.2.3.1.2 "><p id="p12984829155518"><a name="p12984829155518"></a><a name="p12984829155518"></a>Log capacity level.</p>
</td>
</tr>
<tr id="row197211723185511"><td class="cellrowborder" valign="top" width="43.43%" headers="mcps1.2.3.1.1 "><p id="p2721162305516"><a name="p2721162305516"></a><a name="p2721162305516"></a>Current syslog dump config path</p>
</td>
<td class="cellrowborder" valign="top" width="56.57%" headers="mcps1.2.3.1.2 "><p id="p37211023125511"><a name="p37211023125511"></a><a name="p37211023125511"></a>Log storage path.</p>
</td>
</tr>
</tbody>
</table>

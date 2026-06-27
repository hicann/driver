# Enabling or Disabling Log Dumping in Persistence Mode<a name="EN-US_TOPIC_0000002523771960"></a>

## Function<a name="section689116327160"></a>

This command is used to enable or disable log dumping in persistence mode.

## Syntax<a name="section2965174417182"></a>

`npu-smi set -t sys-log-enable -d mode`

## Parameters<a name="section121862611190"></a>

**Table  1**  Parameters

<a name="en-us_topic_0000002269302809_table20975181418279"></a>
<table><thead align="left"><tr id="en-us_topic_0000002269302809_row193661518276"><th class="cellrowborder" valign="top" width="30%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000002269302809_p1336191572710"><a name="en-us_topic_0000002269302809_p1336191572710"></a><a name="en-us_topic_0000002269302809_p1336191572710"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000002269302809_p11361215122716"><a name="en-us_topic_0000002269302809_p11361215122716"></a><a name="en-us_topic_0000002269302809_p11361215122716"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002269302809_row53671511274"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000002269302809_p936815102720"><a name="en-us_topic_0000002269302809_p936815102720"></a><a name="en-us_topic_0000002269302809_p936815102720"></a><em id="en-us_topic_0000002269302809_i1136515152711"><a name="en-us_topic_0000002269302809_i1136515152711"></a><a name="en-us_topic_0000002269302809_i1136515152711"></a>mode</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000002269302809_p173615155277"><a name="en-us_topic_0000002269302809_p173615155277"></a><a name="en-us_topic_0000002269302809_p173615155277"></a>Switch for enabling or disabling log dumping in persistence mode. The value can be <strong id="b15342422184112"><a name="b15342422184112"></a><a name="b15342422184112"></a>0</strong> (default) or <strong id="b234222244117"><a name="b234222244117"></a><a name="b234222244117"></a>1</strong>.</p>
<a name="en-us_topic_0000002269302809_ul73621532714"></a><a name="en-us_topic_0000002269302809_ul73621532714"></a><ul id="en-us_topic_0000002269302809_ul73621532714"><li><strong id="b41693611138"><a name="b41693611138"></a><a name="b41693611138"></a>0</strong>: Disable log dumping in persistence mode.</li><li><strong id="b138542810130"><a name="b138542810130"></a><a name="b138542810130"></a>1</strong>: Enable log dumping in persistence mode.</li></ul>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="section796341422718"></a>

- This command is a persistent command. After the system is restarted, the log dumping configuration persistence mode remains unchanged.
- If the log dumping configuration persistence mode fails to be set and the message "ERROR: The configuration file has been maliciously modified, please clear configuration and stop syslog collecting process first." is returned, run the  **npu-smi set -t clear-syslog-cfg**  command to restore the configuration file to the default settings and terminate the log dumping process, and then set the log dumping configuration persistence mode again.

**Table  2** Support in different deployment scenarios

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

## Example<a name="section825263010207"></a>

Enable log dumping in persistence mode.

```bash
npu-smi set -t sys-log-enable -d 1
```

```text
Set syslog mode success, mode = 1
```

## Output Description<a name="section69916340204"></a>

**Table  3**  Description of the displayed information

<a name="en-us_topic_0000002269302809_table209781414182710"></a>
<table><thead align="left"><tr id="en-us_topic_0000002269302809_row537315122717"><th class="cellrowborder" valign="top" width="43.43%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000002269302809_p203791511277"><a name="en-us_topic_0000002269302809_p203791511277"></a><a name="en-us_topic_0000002269302809_p203791511277"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="56.57%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000002269302809_p19371415182713"><a name="en-us_topic_0000002269302809_p19371415182713"></a><a name="en-us_topic_0000002269302809_p19371415182713"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002269302809_row437191512719"><td class="cellrowborder" valign="top" width="43.43%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000002269302809_p15371415192715"><a name="en-us_topic_0000002269302809_p15371415192715"></a><a name="en-us_topic_0000002269302809_p15371415192715"></a>Set syslog mode success, mode = 1</p>
</td>
<td class="cellrowborder" valign="top" width="56.57%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000002269302809_p1837141552711"><a name="en-us_topic_0000002269302809_p1837141552711"></a><a name="en-us_topic_0000002269302809_p1837141552711"></a>The command execution is successful.</p>
<p id="en-us_topic_0000002269302809_p153717154278"><a name="en-us_topic_0000002269302809_p153717154278"></a><a name="en-us_topic_0000002269302809_p153717154278"></a>The value can be <strong id="b75554522458"><a name="b75554522458"></a><a name="b75554522458"></a>mode = 1</strong> or <strong id="b1855595216459"><a name="b1855595216459"></a><a name="b1855595216459"></a>mode = 0</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000002269302809_row6371715172713"><td class="cellrowborder" valign="top" width="43.43%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000002269302809_p153741511275"><a name="en-us_topic_0000002269302809_p153741511275"></a><a name="en-us_topic_0000002269302809_p153741511275"></a>Set syslog mode failed.</p>
</td>
<td class="cellrowborder" valign="top" width="56.57%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000002269302809_p737191572718"><a name="en-us_topic_0000002269302809_p737191572718"></a><a name="en-us_topic_0000002269302809_p737191572718"></a>The command execution fails.</p>
</td>
</tr>
</tbody>
</table>

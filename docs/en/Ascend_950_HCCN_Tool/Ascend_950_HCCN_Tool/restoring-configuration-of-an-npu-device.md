# Restoring Configuration of an NPU Device<a name="EN-US_TOPIC_0000002584611362"></a>

## Product Support<a name="section5790730141118"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row55241515133010"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p1552411155307"><a name="en-us_topic_0000002614931227_p1552411155307"></a><a name="en-us_topic_0000002614931227_p1552411155307"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p652417155307"><a name="en-us_topic_0000002614931227_p652417155307"></a><a name="en-us_topic_0000002614931227_p652417155307"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p9524115123015"><a name="en-us_topic_0000002614931227_p9524115123015"></a><a name="en-us_topic_0000002614931227_p9524115123015"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p15524131583011"><a name="en-us_topic_0000002614931227_p15524131583011"></a><a name="en-us_topic_0000002614931227_p15524131583011"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p0524121573020"><a name="en-us_topic_0000002614931227_p0524121573020"></a><a name="en-us_topic_0000002614931227_p0524121573020"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p16525115203017"><a name="en-us_topic_0000002614931227_p16525115203017"></a><a name="en-us_topic_0000002614931227_p16525115203017"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p14525141513301"><a name="en-us_topic_0000002614931227_p14525141513301"></a><a name="en-us_topic_0000002614931227_p14525141513301"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row155251615133013"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p1452531563014"><a name="en-us_topic_0000002614931227_p1452531563014"></a><a name="en-us_topic_0000002614931227_p1452531563014"></a><strong id="en-us_topic_0000002614931227_b1778969477"><a name="en-us_topic_0000002614931227_b1778969477"></a><a name="en-us_topic_0000002614931227_b1778969477"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p65251515123018"><a name="en-us_topic_0000002614931227_p65251515123018"></a><a name="en-us_topic_0000002614931227_p65251515123018"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b410177140"><a name="en-us_topic_0000002614931227_b410177140"></a><a name="en-us_topic_0000002614931227_b410177140"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p1525615143010"><a name="en-us_topic_0000002614931227_p1525615143010"></a><a name="en-us_topic_0000002614931227_p1525615143010"></a><strong id="en-us_topic_0000002614931227_b760473121"><a name="en-us_topic_0000002614931227_b760473121"></a><a name="en-us_topic_0000002614931227_b760473121"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p135251615173011"><a name="en-us_topic_0000002614931227_p135251615173011"></a><a name="en-us_topic_0000002614931227_p135251615173011"></a><strong id="en-us_topic_0000002614931227_b278560612"><a name="en-us_topic_0000002614931227_b278560612"></a><a name="en-us_topic_0000002614931227_b278560612"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p65251115183014"><a name="en-us_topic_0000002614931227_p65251115183014"></a><a name="en-us_topic_0000002614931227_p65251115183014"></a><strong id="en-us_topic_0000002614931227_b1922747203"><a name="en-us_topic_0000002614931227_b1922747203"></a><a name="en-us_topic_0000002614931227_b1922747203"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p10525515113015"><a name="en-us_topic_0000002614931227_p10525515113015"></a><a name="en-us_topic_0000002614931227_p10525515113015"></a><strong id="en-us_topic_0000002614931227_b1355092004"><a name="en-us_topic_0000002614931227_b1355092004"></a><a name="en-us_topic_0000002614931227_b1355092004"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p15254151302"><a name="en-us_topic_0000002614931227_p15254151302"></a><a name="en-us_topic_0000002614931227_p15254151302"></a><strong id="en-us_topic_0000002614931227_b11392535183012"><a name="en-us_topic_0000002614931227_b11392535183012"></a><a name="en-us_topic_0000002614931227_b11392535183012"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row1852510152307"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p4525315103015"><a name="en-us_topic_0000002614931227_p4525315103015"></a><a name="en-us_topic_0000002614931227_p4525315103015"></a><span id="en-us_topic_0000002614931227_ph538966863"><a name="en-us_topic_0000002614931227_ph538966863"></a><a name="en-us_topic_0000002614931227_ph538966863"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p698392193014"><a name="en-us_topic_0000002614931227_p698392193014"></a><a name="en-us_topic_0000002614931227_p698392193014"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p16983521113010"><a name="en-us_topic_0000002614931227_p16983521113010"></a><a name="en-us_topic_0000002614931227_p16983521113010"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p209831521173018"><a name="en-us_topic_0000002614931227_p209831521173018"></a><a name="en-us_topic_0000002614931227_p209831521173018"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p898332123010"><a name="en-us_topic_0000002614931227_p898332123010"></a><a name="en-us_topic_0000002614931227_p898332123010"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p15941516258"><a name="en-us_topic_0000002614931227_p15941516258"></a><a name="en-us_topic_0000002614931227_p15941516258"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p691415162513"><a name="en-us_topic_0000002614931227_p691415162513"></a><a name="en-us_topic_0000002614931227_p691415162513"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p149101513259"><a name="en-us_topic_0000002614931227_p149101513259"></a><a name="en-us_topic_0000002614931227_p149101513259"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row18525191512302"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p25253151306"><a name="en-us_topic_0000002614931227_p25253151306"></a><a name="en-us_topic_0000002614931227_p25253151306"></a>Note: <strong id="en-us_topic_0000002614931227_b371947768"><a name="en-us_topic_0000002614931227_b371947768"></a><a name="en-us_topic_0000002614931227_b371947768"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b1553343510"><a name="en-us_topic_0000002614931227_b1553343510"></a><a name="en-us_topic_0000002614931227_b1553343510"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b50933029"><a name="en-us_topic_0000002614931227_b50933029"></a><a name="en-us_topic_0000002614931227_b50933029"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="section957615561617"></a>

Restores the configuration of an NPU device.

## Precautions<a name="section8415102071"></a>

Note the considerations for commands with persistent configuration support.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -s -cfg_recovery -i <dev_id>
```

## Parameters<a name="section107781620873"></a>

<a name="table77595370346"></a>
<table><thead align="left"><tr id="row2760173716343"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="p9760737153418"><a name="p9760737153418"></a><a name="p9760737153418"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p1076023711348"><a name="p1076023711348"></a><a name="p1076023711348"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="p37601437113413"><a name="p37601437113413"></a><a name="p37601437113413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row47601373342"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p676003763413"><a name="p676003763413"></a><a name="p676003763413"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section185511229978"></a>

```bash
hccn_tool -s -cfg_recovery -i 0
```

Configure recovery for a single device.

```text
Cmd executed successfully!
```

## Output Description<a name="section1726420371679"></a>

None.

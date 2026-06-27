# Clearing Port SU Bit Error Statistics<a name="EN-US_TOPIC_0000002584611348"></a>

## Product Support<a name="section5790730141118"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row1659565515239"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p14595855152313"><a name="en-us_topic_0000002614931227_p14595855152313"></a><a name="en-us_topic_0000002614931227_p14595855152313"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p5595655142320"><a name="en-us_topic_0000002614931227_p5595655142320"></a><a name="en-us_topic_0000002614931227_p5595655142320"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p1059518557238"><a name="en-us_topic_0000002614931227_p1059518557238"></a><a name="en-us_topic_0000002614931227_p1059518557238"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p759525511230"><a name="en-us_topic_0000002614931227_p759525511230"></a><a name="en-us_topic_0000002614931227_p759525511230"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p1559511555239"><a name="en-us_topic_0000002614931227_p1559511555239"></a><a name="en-us_topic_0000002614931227_p1559511555239"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p1659575592318"><a name="en-us_topic_0000002614931227_p1659575592318"></a><a name="en-us_topic_0000002614931227_p1659575592318"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p18595855122320"><a name="en-us_topic_0000002614931227_p18595855122320"></a><a name="en-us_topic_0000002614931227_p18595855122320"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row45951557231"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p959595516230"><a name="en-us_topic_0000002614931227_p959595516230"></a><a name="en-us_topic_0000002614931227_p959595516230"></a><strong id="en-us_topic_0000002614931227_b59232609"><a name="en-us_topic_0000002614931227_b59232609"></a><a name="en-us_topic_0000002614931227_b59232609"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p1959595592313"><a name="en-us_topic_0000002614931227_p1959595592313"></a><a name="en-us_topic_0000002614931227_p1959595592313"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b2093538893"><a name="en-us_topic_0000002614931227_b2093538893"></a><a name="en-us_topic_0000002614931227_b2093538893"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p759585542315"><a name="en-us_topic_0000002614931227_p759585542315"></a><a name="en-us_topic_0000002614931227_p759585542315"></a><strong id="en-us_topic_0000002614931227_b1053335290"><a name="en-us_topic_0000002614931227_b1053335290"></a><a name="en-us_topic_0000002614931227_b1053335290"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p2595165542313"><a name="en-us_topic_0000002614931227_p2595165542313"></a><a name="en-us_topic_0000002614931227_p2595165542313"></a><strong id="en-us_topic_0000002614931227_b1274800317"><a name="en-us_topic_0000002614931227_b1274800317"></a><a name="en-us_topic_0000002614931227_b1274800317"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p18595355102314"><a name="en-us_topic_0000002614931227_p18595355102314"></a><a name="en-us_topic_0000002614931227_p18595355102314"></a><strong id="en-us_topic_0000002614931227_b994392906"><a name="en-us_topic_0000002614931227_b994392906"></a><a name="en-us_topic_0000002614931227_b994392906"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p95954552235"><a name="en-us_topic_0000002614931227_p95954552235"></a><a name="en-us_topic_0000002614931227_p95954552235"></a><strong id="en-us_topic_0000002614931227_b1234574226"><a name="en-us_topic_0000002614931227_b1234574226"></a><a name="en-us_topic_0000002614931227_b1234574226"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p195951555152317"><a name="en-us_topic_0000002614931227_p195951555152317"></a><a name="en-us_topic_0000002614931227_p195951555152317"></a><strong id="en-us_topic_0000002614931227_b829020145"><a name="en-us_topic_0000002614931227_b829020145"></a><a name="en-us_topic_0000002614931227_b829020145"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row7595175516238"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p145954555234"><a name="en-us_topic_0000002614931227_p145954555234"></a><a name="en-us_topic_0000002614931227_p145954555234"></a><span id="en-us_topic_0000002614931227_ph1218514290"><a name="en-us_topic_0000002614931227_ph1218514290"></a><a name="en-us_topic_0000002614931227_ph1218514290"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p1595195511239"><a name="en-us_topic_0000002614931227_p1595195511239"></a><a name="en-us_topic_0000002614931227_p1595195511239"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p65958557233"><a name="en-us_topic_0000002614931227_p65958557233"></a><a name="en-us_topic_0000002614931227_p65958557233"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p115959554235"><a name="en-us_topic_0000002614931227_p115959554235"></a><a name="en-us_topic_0000002614931227_p115959554235"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p125951155182315"><a name="en-us_topic_0000002614931227_p125951155182315"></a><a name="en-us_topic_0000002614931227_p125951155182315"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p145951655102310"><a name="en-us_topic_0000002614931227_p145951655102310"></a><a name="en-us_topic_0000002614931227_p145951655102310"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p9595195514235"><a name="en-us_topic_0000002614931227_p9595195514235"></a><a name="en-us_topic_0000002614931227_p9595195514235"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p959516551236"><a name="en-us_topic_0000002614931227_p959516551236"></a><a name="en-us_topic_0000002614931227_p959516551236"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row2597155512312"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p1559775532318"><a name="en-us_topic_0000002614931227_p1559775532318"></a><a name="en-us_topic_0000002614931227_p1559775532318"></a>Note: <strong id="en-us_topic_0000002614931227_b1368545565"><a name="en-us_topic_0000002614931227_b1368545565"></a><a name="en-us_topic_0000002614931227_b1368545565"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b259987573"><a name="en-us_topic_0000002614931227_b259987573"></a><a name="en-us_topic_0000002614931227_b259987573"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b287703834"><a name="en-us_topic_0000002614931227_b287703834"></a><a name="en-us_topic_0000002614931227_b287703834"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="section957615561617"></a>

Clears a port's SU bit error statistics.

## Precautions<a name="section8415102071"></a>

None.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -s -su_ber -i <dev_id> -u <udie_id> -p <port_id> -clear
```

## Parameters<a name="section107781620873"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="17.560000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="26.150000000000002%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="en-us_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p16538337122410"><a name="en-us_topic_0000002614931223_p16538337122410"></a><a name="en-us_topic_0000002614931223_p16538337122410"></a>Chip UDie ID. The value is <strong id="en-us_topic_0000002614931223_b4277211143916"><a name="en-us_topic_0000002614931223_b4277211143916"></a><a name="en-us_topic_0000002614931223_b4277211143916"></a>0</strong>. You can run the command in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a> to query the value.</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p1911115561611"><a name="en-us_topic_0000002614931223_p1911115561611"></a><a name="en-us_topic_0000002614931223_p1911115561611"></a>Chip port ID. For details, see <strong id="en-us_topic_0000002614931223_b15791243184015"><a name="en-us_topic_0000002614931223_b15791243184015"></a><a name="en-us_topic_0000002614931223_b15791243184015"></a>Port ID</strong> in the output description in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a>.</p>
</td>
</tr>
<tr id="row1870560201313"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p18709727141319"><a name="p18709727141319"></a><a name="p18709727141319"></a>-clear</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p0709127161316"><a name="p0709127161316"></a><a name="p0709127161316"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1170962791313"><a name="p1170962791313"></a><a name="p1170962791313"></a>Clears SU bit error statistics.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section185511229978"></a>

```bash
hccn_tool -s -su_ber -i 0 -u 0 -p 4 -clear
```

Clear the SU bit error statistics for port 4 on UDie 0 under logical device ID 0.

```text
Cmd executed successfully!
```

## Output Description<a name="section55215490292"></a>

None.

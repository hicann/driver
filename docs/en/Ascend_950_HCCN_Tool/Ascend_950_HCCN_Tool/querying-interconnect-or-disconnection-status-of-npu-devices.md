# Querying Interconnect or Disconnection Status of NPU Devices<a name="EN-US_TOPIC_0000002584451434"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row47351716152418"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p673514162240"><a name="en-us_topic_0000002614931227_p673514162240"></a><a name="en-us_topic_0000002614931227_p673514162240"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p16735101652415"><a name="en-us_topic_0000002614931227_p16735101652415"></a><a name="en-us_topic_0000002614931227_p16735101652415"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p573591614247"><a name="en-us_topic_0000002614931227_p573591614247"></a><a name="en-us_topic_0000002614931227_p573591614247"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p1773531692413"><a name="en-us_topic_0000002614931227_p1773531692413"></a><a name="en-us_topic_0000002614931227_p1773531692413"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p18735316192410"><a name="en-us_topic_0000002614931227_p18735316192410"></a><a name="en-us_topic_0000002614931227_p18735316192410"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p197351716162414"><a name="en-us_topic_0000002614931227_p197351716162414"></a><a name="en-us_topic_0000002614931227_p197351716162414"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p573541602418"><a name="en-us_topic_0000002614931227_p573541602418"></a><a name="en-us_topic_0000002614931227_p573541602418"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row207354164243"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p157359169247"><a name="en-us_topic_0000002614931227_p157359169247"></a><a name="en-us_topic_0000002614931227_p157359169247"></a><strong id="en-us_topic_0000002614931227_b1694722141"><a name="en-us_topic_0000002614931227_b1694722141"></a><a name="en-us_topic_0000002614931227_b1694722141"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p2073551618243"><a name="en-us_topic_0000002614931227_p2073551618243"></a><a name="en-us_topic_0000002614931227_p2073551618243"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b339134195"><a name="en-us_topic_0000002614931227_b339134195"></a><a name="en-us_topic_0000002614931227_b339134195"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p173531617242"><a name="en-us_topic_0000002614931227_p173531617242"></a><a name="en-us_topic_0000002614931227_p173531617242"></a><strong id="en-us_topic_0000002614931227_b249061574"><a name="en-us_topic_0000002614931227_b249061574"></a><a name="en-us_topic_0000002614931227_b249061574"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p1735191611244"><a name="en-us_topic_0000002614931227_p1735191611244"></a><a name="en-us_topic_0000002614931227_p1735191611244"></a><strong id="en-us_topic_0000002614931227_b676981370"><a name="en-us_topic_0000002614931227_b676981370"></a><a name="en-us_topic_0000002614931227_b676981370"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p173531662414"><a name="en-us_topic_0000002614931227_p173531662414"></a><a name="en-us_topic_0000002614931227_p173531662414"></a><strong id="en-us_topic_0000002614931227_b2012475489"><a name="en-us_topic_0000002614931227_b2012475489"></a><a name="en-us_topic_0000002614931227_b2012475489"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p0735516172410"><a name="en-us_topic_0000002614931227_p0735516172410"></a><a name="en-us_topic_0000002614931227_p0735516172410"></a><strong id="en-us_topic_0000002614931227_b1749250665"><a name="en-us_topic_0000002614931227_b1749250665"></a><a name="en-us_topic_0000002614931227_b1749250665"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p12735716192411"><a name="en-us_topic_0000002614931227_p12735716192411"></a><a name="en-us_topic_0000002614931227_p12735716192411"></a><strong id="en-us_topic_0000002614931227_b1957761160"><a name="en-us_topic_0000002614931227_b1957761160"></a><a name="en-us_topic_0000002614931227_b1957761160"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row9735101672415"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p1735171610245"><a name="en-us_topic_0000002614931227_p1735171610245"></a><a name="en-us_topic_0000002614931227_p1735171610245"></a><span id="en-us_topic_0000002614931227_ph6885836193014"><a name="en-us_topic_0000002614931227_ph6885836193014"></a><a name="en-us_topic_0000002614931227_ph6885836193014"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p19735121618246"><a name="en-us_topic_0000002614931227_p19735121618246"></a><a name="en-us_topic_0000002614931227_p19735121618246"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p2735816172417"><a name="en-us_topic_0000002614931227_p2735816172417"></a><a name="en-us_topic_0000002614931227_p2735816172417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p14735116152415"><a name="en-us_topic_0000002614931227_p14735116152415"></a><a name="en-us_topic_0000002614931227_p14735116152415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p1973515163248"><a name="en-us_topic_0000002614931227_p1973515163248"></a><a name="en-us_topic_0000002614931227_p1973515163248"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p3735171692412"><a name="en-us_topic_0000002614931227_p3735171692412"></a><a name="en-us_topic_0000002614931227_p3735171692412"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p1773541612418"><a name="en-us_topic_0000002614931227_p1773541612418"></a><a name="en-us_topic_0000002614931227_p1773541612418"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p4735131642417"><a name="en-us_topic_0000002614931227_p4735131642417"></a><a name="en-us_topic_0000002614931227_p4735131642417"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row173741602416"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p3737151682415"><a name="en-us_topic_0000002614931227_p3737151682415"></a><a name="en-us_topic_0000002614931227_p3737151682415"></a>Note: <strong id="en-us_topic_0000002614931227_b2070980240"><a name="en-us_topic_0000002614931227_b2070980240"></a><a name="en-us_topic_0000002614931227_b2070980240"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b374192385"><a name="en-us_topic_0000002614931227_b374192385"></a><a name="en-us_topic_0000002614931227_b374192385"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b1478331068"><a name="en-us_topic_0000002614931227_b1478331068"></a><a name="en-us_topic_0000002614931227_b1478331068"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="section957615561617"></a>

Queries the interconnect or disconnection status of NPU devices.

## Precautions<a name="section8415102071"></a>

If a single card is used, no valid port is available. The ports activated in the 2-card and 4-card interconnect systems are different. This command outputs the status of the valid ports.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -g -ub_connect -i <dev_id>
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
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p542332615419"><a name="p542332615419"></a><a name="p542332615419"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section185511229978"></a>

```bash
hccn_tool -g -ub_connect -i 0
```

Query the interconnect and disconnection status of the device with logical ID 0.

```text
link status : PARTIAL LINK
port 4 : UP
port 5 : DOWN
port 6 : PARTIAL UP
```

## Output Description<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p81731506144"><a name="p81731506144"></a><a name="p81731506144"></a>link status</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p19688151811220"><a name="p19688151811220"></a><a name="p19688151811220"></a>Overall link status:</p>
<a name="ul0628115134316"></a><a name="ul0628115134316"></a><ul id="ul0628115134316"><li><strong id="b17494131312019"><a name="b17494131312019"></a><a name="b17494131312019"></a>UP</strong>: All valid ports are up.</li><li><strong id="b972161115590"><a name="b972161115590"></a><a name="b972161115590"></a>DOWN</strong>: All valid ports are down (or no valid port is available).</li><li><strong id="b1136313714594"><a name="b1136313714594"></a><a name="b1136313714594"></a>PARTIAL LINK</strong>: Some valid ports are up.</li></ul>
</td>
</tr>
<tr id="row86641169146"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p666416631411"><a name="p666416631411"></a><a name="p666416631411"></a>port X</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p136647614142"><a name="p136647614142"></a><a name="p136647614142"></a>Port link status. The options are <strong id="b390894117013"><a name="b390894117013"></a><a name="b390894117013"></a>UP</strong>, <strong id="b1753918435015"><a name="b1753918435015"></a><a name="b1753918435015"></a>DOWN</strong>, and <strong id="b10611124818011"><a name="b10611124818011"></a><a name="b10611124818011"></a>PARTIAL UP</strong>. <strong id="b16493185011010"><a name="b16493185011010"></a><a name="b16493185011010"></a>PARTIAL UP</strong> is displayed only when lanes are reduced.</p>
</td>
</tr>
</tbody>
</table>

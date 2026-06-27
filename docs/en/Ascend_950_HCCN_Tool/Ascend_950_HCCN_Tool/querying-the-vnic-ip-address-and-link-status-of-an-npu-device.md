# Querying the vNIC IP Address and Link Status of an NPU Device<a name="EN-US_TOPIC_0000002614931201"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row695219913269"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p795213913268"><a name="en-us_topic_0000002614931227_p795213913268"></a><a name="en-us_topic_0000002614931227_p795213913268"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p59525913261"><a name="en-us_topic_0000002614931227_p59525913261"></a><a name="en-us_topic_0000002614931227_p59525913261"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p195279152619"><a name="en-us_topic_0000002614931227_p195279152619"></a><a name="en-us_topic_0000002614931227_p195279152619"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p895217917264"><a name="en-us_topic_0000002614931227_p895217917264"></a><a name="en-us_topic_0000002614931227_p895217917264"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p795217919267"><a name="en-us_topic_0000002614931227_p795217919267"></a><a name="en-us_topic_0000002614931227_p795217919267"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p2952096260"><a name="en-us_topic_0000002614931227_p2952096260"></a><a name="en-us_topic_0000002614931227_p2952096260"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p995211914265"><a name="en-us_topic_0000002614931227_p995211914265"></a><a name="en-us_topic_0000002614931227_p995211914265"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row139522916266"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p295239192612"><a name="en-us_topic_0000002614931227_p295239192612"></a><a name="en-us_topic_0000002614931227_p295239192612"></a><strong id="en-us_topic_0000002614931227_b1529691667"><a name="en-us_topic_0000002614931227_b1529691667"></a><a name="en-us_topic_0000002614931227_b1529691667"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p2095213910260"><a name="en-us_topic_0000002614931227_p2095213910260"></a><a name="en-us_topic_0000002614931227_p2095213910260"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b814504621"><a name="en-us_topic_0000002614931227_b814504621"></a><a name="en-us_topic_0000002614931227_b814504621"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p17952594269"><a name="en-us_topic_0000002614931227_p17952594269"></a><a name="en-us_topic_0000002614931227_p17952594269"></a><strong id="en-us_topic_0000002614931227_b1267232280"><a name="en-us_topic_0000002614931227_b1267232280"></a><a name="en-us_topic_0000002614931227_b1267232280"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p39521996263"><a name="en-us_topic_0000002614931227_p39521996263"></a><a name="en-us_topic_0000002614931227_p39521996263"></a><strong id="en-us_topic_0000002614931227_b1740223780"><a name="en-us_topic_0000002614931227_b1740223780"></a><a name="en-us_topic_0000002614931227_b1740223780"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p15952995268"><a name="en-us_topic_0000002614931227_p15952995268"></a><a name="en-us_topic_0000002614931227_p15952995268"></a><strong id="en-us_topic_0000002614931227_b599373861"><a name="en-us_topic_0000002614931227_b599373861"></a><a name="en-us_topic_0000002614931227_b599373861"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p159521899265"><a name="en-us_topic_0000002614931227_p159521899265"></a><a name="en-us_topic_0000002614931227_p159521899265"></a><strong id="en-us_topic_0000002614931227_b750663238"><a name="en-us_topic_0000002614931227_b750663238"></a><a name="en-us_topic_0000002614931227_b750663238"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p99524917266"><a name="en-us_topic_0000002614931227_p99524917266"></a><a name="en-us_topic_0000002614931227_p99524917266"></a><strong id="en-us_topic_0000002614931227_b1808430188"><a name="en-us_topic_0000002614931227_b1808430188"></a><a name="en-us_topic_0000002614931227_b1808430188"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row10952129192612"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p119521993261"><a name="en-us_topic_0000002614931227_p119521993261"></a><a name="en-us_topic_0000002614931227_p119521993261"></a><span id="en-us_topic_0000002614931227_ph830595221"><a name="en-us_topic_0000002614931227_ph830595221"></a><a name="en-us_topic_0000002614931227_ph830595221"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p1895269152612"><a name="en-us_topic_0000002614931227_p1895269152612"></a><a name="en-us_topic_0000002614931227_p1895269152612"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p1451181622719"><a name="en-us_topic_0000002614931227_p1451181622719"></a><a name="en-us_topic_0000002614931227_p1451181622719"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p19521992265"><a name="en-us_topic_0000002614931227_p19521992265"></a><a name="en-us_topic_0000002614931227_p19521992265"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p10780102012278"><a name="en-us_topic_0000002614931227_p10780102012278"></a><a name="en-us_topic_0000002614931227_p10780102012278"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p1695319172613"><a name="en-us_topic_0000002614931227_p1695319172613"></a><a name="en-us_topic_0000002614931227_p1695319172613"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p16953129202615"><a name="en-us_topic_0000002614931227_p16953129202615"></a><a name="en-us_topic_0000002614931227_p16953129202615"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p1195349142618"><a name="en-us_topic_0000002614931227_p1195349142618"></a><a name="en-us_topic_0000002614931227_p1195349142618"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row1795413914266"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p1195419911267"><a name="en-us_topic_0000002614931227_p1195419911267"></a><a name="en-us_topic_0000002614931227_p1195419911267"></a>Note: <strong id="en-us_topic_0000002614931227_b1470668159"><a name="en-us_topic_0000002614931227_b1470668159"></a><a name="en-us_topic_0000002614931227_b1470668159"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b1250523589"><a name="en-us_topic_0000002614931227_b1250523589"></a><a name="en-us_topic_0000002614931227_b1250523589"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b1597968909"><a name="en-us_topic_0000002614931227_b1597968909"></a><a name="en-us_topic_0000002614931227_b1597968909"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="en-us_topic_0184799386_section1383319120101"></a>

Query the vNIC IP address and link status of an NPU device.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -vnic -i <dev_id>
```

## Parameters<a name="en-us_topic_0184799386_section10465854096"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0184799386_section1684018331898"></a>

```bash
hccn_tool -g -vnic -i 0
```

Query the vNIC IP address and link status of the device with logical ID 0.

```text
vnic link status: UP
vnic ipaddr: 192.168.2.199
vnic netmask: 255.255.255.0
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p28561618125718"><a name="p28561618125718"></a><a name="p28561618125718"></a>vnic link status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1851287153011"><a name="p1851287153011"></a><a name="p1851287153011"></a>Link status of the virtual network port:</p>
<a name="ul1838483733017"></a><a name="ul1838483733017"></a><ul id="ul1838483733017"><li><strong id="b15963155813555"><a name="b15963155813555"></a><a name="b15963155813555"></a>UP</strong>: The connection is normal.</li><li><strong id="b3211224563"><a name="b3211224563"></a><a name="b3211224563"></a>DOWN</strong>: The connection is interrupted.</li></ul>
</td>
</tr>
<tr id="row9947344415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1794820443117"><a name="p1794820443117"></a><a name="p1794820443117"></a>vnic ipaddr</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p15430140536"><a name="p15430140536"></a><a name="p15430140536"></a>IP address of the virtual network port.</p>
</td>
</tr>
<tr id="row1946053614"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p11946195319120"><a name="p11946195319120"></a><a name="p11946195319120"></a>vnic netmask</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p14747181634"><a name="p14747181634"></a><a name="p14747181634"></a>Mask of the virtual network port.</p>
</td>
</tr>
</tbody>
</table>

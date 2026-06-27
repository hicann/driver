# Querying the NPU Device Information<a name="EN-US_TOPIC_0000002584451440"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table38301303189"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p187611624184817"><a name="en-us_topic_0000002614931227_p187611624184817"></a><a name="en-us_topic_0000002614931227_p187611624184817"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p2761324104819"><a name="en-us_topic_0000002614931227_p2761324104819"></a><a name="en-us_topic_0000002614931227_p2761324104819"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p1476142414488"><a name="en-us_topic_0000002614931227_p1476142414488"></a><a name="en-us_topic_0000002614931227_p1476142414488"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p7761524164817"><a name="en-us_topic_0000002614931227_p7761524164817"></a><a name="en-us_topic_0000002614931227_p7761524164817"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p5761142419484"><a name="en-us_topic_0000002614931227_p5761142419484"></a><a name="en-us_topic_0000002614931227_p5761142419484"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"></a><strong id="en-us_topic_0000002614931227_b114231289515"><a name="en-us_topic_0000002614931227_b114231289515"></a><a name="en-us_topic_0000002614931227_b114231289515"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b465716294519"><a name="en-us_topic_0000002614931227_b465716294519"></a><a name="en-us_topic_0000002614931227_b465716294519"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p576152444819"><a name="en-us_topic_0000002614931227_p576152444819"></a><a name="en-us_topic_0000002614931227_p576152444819"></a><strong id="en-us_topic_0000002614931227_b56905301955"><a name="en-us_topic_0000002614931227_b56905301955"></a><a name="en-us_topic_0000002614931227_b56905301955"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p67611424144816"><a name="en-us_topic_0000002614931227_p67611424144816"></a><a name="en-us_topic_0000002614931227_p67611424144816"></a><strong id="en-us_topic_0000002614931227_b77248318517"><a name="en-us_topic_0000002614931227_b77248318517"></a><a name="en-us_topic_0000002614931227_b77248318517"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p776152411481"><a name="en-us_topic_0000002614931227_p776152411481"></a><a name="en-us_topic_0000002614931227_p776152411481"></a><strong id="en-us_topic_0000002614931227_b1571933218518"><a name="en-us_topic_0000002614931227_b1571933218518"></a><a name="en-us_topic_0000002614931227_b1571933218518"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p1376142411481"><a name="en-us_topic_0000002614931227_p1376142411481"></a><a name="en-us_topic_0000002614931227_p1376142411481"></a><strong id="en-us_topic_0000002614931227_b5732033855"><a name="en-us_topic_0000002614931227_b5732033855"></a><a name="en-us_topic_0000002614931227_b5732033855"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p676192444812"><a name="en-us_topic_0000002614931227_p676192444812"></a><a name="en-us_topic_0000002614931227_p676192444812"></a><strong id="en-us_topic_0000002614931227_b97392034855"><a name="en-us_topic_0000002614931227_b97392034855"></a><a name="en-us_topic_0000002614931227_b97392034855"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row9310018122518"><td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p496503213253"><a name="en-us_topic_0000002614931227_p496503213253"></a><a name="en-us_topic_0000002614931227_p496503213253"></a><span id="en-us_topic_0000002614931227_ph12140626193614"><a name="en-us_topic_0000002614931227_ph12140626193614"></a><a name="en-us_topic_0000002614931227_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p11731721162710"><a name="en-us_topic_0000002614931227_p11731721162710"></a><a name="en-us_topic_0000002614931227_p11731721162710"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p7731142132711"><a name="en-us_topic_0000002614931227_p7731142132711"></a><a name="en-us_topic_0000002614931227_p7731142132711"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p18731152115278"><a name="en-us_topic_0000002614931227_p18731152115278"></a><a name="en-us_topic_0000002614931227_p18731152115278"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p07311821202718"><a name="en-us_topic_0000002614931227_p07311821202718"></a><a name="en-us_topic_0000002614931227_p07311821202718"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p7770113011249"><a name="en-us_topic_0000002614931227_p7770113011249"></a><a name="en-us_topic_0000002614931227_p7770113011249"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p187701309243"><a name="en-us_topic_0000002614931227_p187701309243"></a><a name="en-us_topic_0000002614931227_p187701309243"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p2077003042417"><a name="en-us_topic_0000002614931227_p2077003042417"></a><a name="en-us_topic_0000002614931227_p2077003042417"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row1090441572511"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"><a name="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"></a>Note: <strong id="en-us_topic_0000002614931227_b156115392518"><a name="en-us_topic_0000002614931227_b156115392518"></a><a name="en-us_topic_0000002614931227_b156115392518"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b9611163911511"><a name="en-us_topic_0000002614931227_b9611163911511"></a><a name="en-us_topic_0000002614931227_b9611163911511"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b1161173913519"><a name="en-us_topic_0000002614931227_b1161173913519"></a><a name="en-us_topic_0000002614931227_b1161173913519"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="en-us_topic_0184799386_section1383319120101"></a>

Queries the NPU device information in the system.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -dev_info -i <dev_id>
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
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p1371520181525"><a name="p1371520181525"></a><a name="p1371520181525"></a>-i &lt;dev_id&gt;</p>
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
hccn_tool -g -dev_info -i 0
```

Query the information of the NPU device with logical ID 0.

```text
+---------+---------+---------------------+-----------+-------------+------------+
| UDie ID | Port ID | Speed Ability(Gbps) | Port Type | Link Status | Media Type |
+---------+---------+---------------------+-----------+-------------+------------+
| 0       | 4       | 400                 | UB        | UP          | Electrical |
| 0       | 5       | 400                 | UB        | UP          | Electrical |
| 0       | 6       | 400                 | UB        | UP          | Electrical |
+---------+---------+---------------------+-----------+-------------+------------+
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| Interface Name  | IP Address                                 | Netmask                                    | Bond Mode | Slaves          |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| end0v0          | 192.168.2.199                              | 255.255.255.0                              | NA        | NA              |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
| ipourma0        | ::10:0:dfdf:51                             | ffff:ffff:ffff:ffff::                      | NA        | NA              |
|                 | ::10:0:dfdf:30                             | ffff:ffff:ffff:ffff::                      |           |                 |
|                 | ::10:0:dfdf:28                             | ffff:ffff:ffff:ffff::                      |           |                 |
|                 | ::10:0:dfdf:20                             | ffff:ffff:ffff:ffff::                      |           |                 |
+-----------------+--------------------------------------------+--------------------------------------------+-----------+-----------------+
+-----------------+-----------+-----------------------------------------+
| Name            | EID Index | EID                                     |
+-----------------+-----------+-----------------------------------------+
| udma1           | 0         | 0000:0000:0000:0000:0010:0000:dfdf:0020 |
|                 | 1         | 0000:0000:0000:0000:0010:0000:dfdf:0028 |
|                 | 2         | 0000:0000:0000:0000:0010:0000:dfdf:0030 |
|                 | 3         | 0000:0000:0000:0000:0010:0000:dfdf:0051 |
+-----------------+-----------+-----------------------------------------+
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1545515094515"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p18662427144511"><a name="p18662427144511"></a><a name="p18662427144511"></a>UDie ID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p566132719457"><a name="p566132719457"></a><a name="p566132719457"></a>UDie ID. Die ID of the chip.</p>
</td>
</tr>
<tr id="row7307105584610"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p6307135511462"><a name="p6307135511462"></a><a name="p6307135511462"></a>Port ID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p43072055204611"><a name="p43072055204611"></a><a name="p43072055204611"></a>Port ID on the UDie.</p>
<p id="p1736992013222"><a name="p1736992013222"></a><a name="p1736992013222"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 accelerator card</span>: There is no valid port when a single card is used. When two or four cards are used, the cards are interconnected through UB. If two cards are interconnected, the port IDs for each card are 4, 5, 6, and 8. If four cards are interconnected, the port IDs for each card are 4, 5, and 6.</p>
</td>
</tr>
<tr id="row84681138478"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p846893114715"><a name="p846893114715"></a><a name="p846893114715"></a>Speed Ability(Gbps)</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1846810374720"><a name="p1846810374720"></a><a name="p1846810374720"></a>Port link speed (Gbps).</p>
</td>
</tr>
<tr id="row113615143472"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p153614146479"><a name="p153614146479"></a><a name="p153614146479"></a>Port Type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p123671412474"><a name="p123671412474"></a><a name="p123671412474"></a>Port type. <strong id="b1863006163010"><a name="b1863006163010"></a><a name="b1863006163010"></a>UB</strong> indicates the UnifiedBus (UB) port.</p>
<a name="ul28871846158"></a><a name="ul28871846158"></a><ul id="ul28871846158"><li><strong id="b18361153815125"><a name="b18361153815125"></a><a name="b18361153815125"></a>UB</strong>: UB port</li></ul>
</td>
</tr>
<tr id="row526012207470"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1926062019479"><a name="p1926062019479"></a><a name="p1926062019479"></a>Link Status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p426082094713"><a name="p426082094713"></a><a name="p426082094713"></a>Link status, which can be <strong id="b12216144325"><a name="b12216144325"></a><a name="b12216144325"></a>DOWN</strong> or <strong id="b78261615173213"><a name="b78261615173213"></a><a name="b78261615173213"></a>UP</strong>.</p>
</td>
</tr>
<tr id="row9792172514719"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p579211253472"><a name="p579211253472"></a><a name="p579211253472"></a>Media Type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p8792112514713"><a name="p8792112514713"></a><a name="p8792112514713"></a>Media type. <strong id="b198841825153214"><a name="b198841825153214"></a><a name="b198841825153214"></a>Electrical</strong> indicates an electrical port.</p>
</td>
</tr>
<tr id="row2663020204815"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p15663920114813"><a name="p15663920114813"></a><a name="p15663920114813"></a>Interface Name</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1766322034813"><a name="p1766322034813"></a><a name="p1766322034813"></a>Network device name.</p>
<p id="p4677101111216"><a name="p4677101111216"></a><a name="p4677101111216"></a>In the command output, <strong id="b746985518214"><a name="b746985518214"></a><a name="b746985518214"></a>bond</strong><em id="i5255153813215"><a name="i5255153813215"></a><a name="i5255153813215"></a>X</em> corresponds to the value specified after the <strong id="b174094482109"><a name="b174094482109"></a><a name="b174094482109"></a>-d</strong> command-line parameter, which is mapped to <strong id="b1190855917101"><a name="b1190855917101"></a><a name="b1190855917101"></a>&lt;bond_ndev_name&gt;</strong> and <strong id="b410116161117"><a name="b410116161117"></a><a name="b410116161117"></a>&lt;ndev_name&gt;</strong> variables.</p>
</td>
</tr>
<tr id="row0218192404819"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p13218624194817"><a name="p13218624194817"></a><a name="p13218624194817"></a>IP Address</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p12189246483"><a name="p12189246483"></a><a name="p12189246483"></a>IP address.</p>
</td>
</tr>
<tr id="row717433212484"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p41741732194817"><a name="p41741732194817"></a><a name="p41741732194817"></a>Netmask</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p117493214814"><a name="p117493214814"></a><a name="p117493214814"></a>IP address mask.</p>
</td>
</tr>
<tr id="row245653574814"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p8456035154811"><a name="p8456035154811"></a><a name="p8456035154811"></a>Bond Mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p66172032445"><a name="p66172032445"></a><a name="p66172032445"></a>Bonding mode:</p>
<a name="ul1954392304416"></a><a name="ul1954392304416"></a><ul id="ul1954392304416"><li><strong id="b0431029161411"><a name="b0431029161411"></a><a name="b0431029161411"></a>802.3ad</strong>: Currently, only this mode is supported.</li><li><strong id="b9348145216216"><a name="b9348145216216"></a><a name="b9348145216216"></a>Unknown</strong>: The mode is unknown.</li><li><strong id="b486915254115"><a name="b486915254115"></a><a name="b486915254115"></a>NA</strong>: Not in bonding mode.</li></ul>
</td>
</tr>
<tr id="row761143812481"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p261183814481"><a name="p261183814481"></a><a name="p261183814481"></a>Slaves</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p156111738204811"><a name="p156111738204811"></a><a name="p156111738204811"></a>Name of the sub-device corresponding to the bond device. If the bonding mode is not used, <strong id="b533244833311"><a name="b533244833311"></a><a name="b533244833311"></a>NA</strong> is displayed.</p>
<p id="p14788182282013"><a name="p14788182282013"></a><a name="p14788182282013"></a>In the command output, <strong id="b1866564417174"><a name="b1866564417174"></a><a name="b1866564417174"></a>ethc</strong><em id="i16651732192019"><a name="i16651732192019"></a><a name="i16651732192019"></a>X</em><strong id="b4853104711719"><a name="b4853104711719"></a><a name="b4853104711719"></a>d</strong><em id="i166656329205"><a name="i166656329205"></a><a name="i166656329205"></a>X</em><strong id="b7229165481714"><a name="b7229165481714"></a><a name="b7229165481714"></a>e</strong><em id="i366573242016"><a name="i366573242016"></a><a name="i366573242016"></a>X</em> corresponds to the value specified after the <strong id="b91429105183"><a name="b91429105183"></a><a name="b91429105183"></a>-d</strong> command-line parameter, which is mapped to the <strong id="b17142121011814"><a name="b17142121011814"></a><a name="b17142121011814"></a>&lt;ndev_name&gt;</strong> variable.</p>
</td>
</tr>
<tr id="row87012479484"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p117194784813"><a name="p117194784813"></a><a name="p117194784813"></a>Name</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p071947114815"><a name="p071947114815"></a><a name="p071947114815"></a>UDMA device name.</p>
<p id="p1723024315165"><a name="p1723024315165"></a><a name="p1723024315165"></a>In the command output, <strong id="b151052054171812"><a name="b151052054171812"></a><a name="b151052054171812"></a>udma</strong><em id="i87961556141815"><a name="i87961556141815"></a><a name="i87961556141815"></a>X</em> corresponds to the value specified after the <strong id="b173231511911"><a name="b173231511911"></a><a name="b173231511911"></a>-d</strong> command-line parameter, which is mapped to the <strong id="b203234511192"><a name="b203234511192"></a><a name="b203234511192"></a>&lt;udma_dev_name&gt;</strong> variable.</p>
</td>
</tr>
<tr id="row1850411501488"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1050435094812"><a name="p1050435094812"></a><a name="p1050435094812"></a>EID Index</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1504350184810"><a name="p1504350184810"></a><a name="p1504350184810"></a>EID index of the UDMA device.</p>
</td>
</tr>
<tr id="row13913652134811"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2913145218485"><a name="p2913145218485"></a><a name="p2913145218485"></a>EID</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p39134525483"><a name="p39134525483"></a><a name="p39134525483"></a>EID of the UDMA device.</p>
</td>
</tr>
</tbody>
</table>

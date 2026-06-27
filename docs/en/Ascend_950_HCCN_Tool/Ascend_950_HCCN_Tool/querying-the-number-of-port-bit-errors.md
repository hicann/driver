# Querying the Number of Port Bit Errors<a name="EN-US_TOPIC_0000002584611370"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
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

Queries the number of port bit errors.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -bit_err -i <dev_id> -u <udie_id> -p <port_id>
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
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p161765005614"><a name="p161765005614"></a><a name="p161765005614"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="en-us_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p173511754135617"><a name="p173511754135617"></a><a name="p173511754135617"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p16538337122410"><a name="en-us_topic_0000002614931223_p16538337122410"></a><a name="en-us_topic_0000002614931223_p16538337122410"></a>Chip UDie ID. The value is <strong id="en-us_topic_0000002614931223_b4277211143916"><a name="en-us_topic_0000002614931223_b4277211143916"></a><a name="en-us_topic_0000002614931223_b4277211143916"></a>0</strong>. You can run the command in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a> to query the value.</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p1911115561611"><a name="en-us_topic_0000002614931223_p1911115561611"></a><a name="en-us_topic_0000002614931223_p1911115561611"></a>Chip port ID. For details, see <strong id="en-us_topic_0000002614931223_b15791243184015"><a name="en-us_topic_0000002614931223_b15791243184015"></a><a name="en-us_topic_0000002614931223_b15791243184015"></a>Port ID</strong> in the output description in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a>.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0184799386_section1684018331898"></a>

```bash
hccn_tool -g -bit_err -i 0 -u 0 -p 4
```

Query the number of bit errors of port 4 on UDie 0 under logical device ID 0.

```text
-------------------------- dl-bit_err --------------------------
port_id: 0x4
st_fec_decoding_fail_num: 0x4
st_fec_err_bit_num: 0x3868275f
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="40%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="60%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="40%" headers="mcps1.1.3.1.1 "><p id="p28561618125718"><a name="p28561618125718"></a><a name="p28561618125718"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="60%" headers="mcps1.1.3.1.2 "><p id="p720612581168"><a name="p720612581168"></a><a name="p720612581168"></a>Port ID.</p>
</td>
</tr>
<tr id="row24313085714"><td class="cellrowborder" valign="top" width="40%" headers="mcps1.1.3.1.1 "><p id="p1446304579"><a name="p1446304579"></a><a name="p1446304579"></a>st_fec_decoding_fail_num</p>
</td>
<td class="cellrowborder" valign="top" width="60%" headers="mcps1.1.3.1.2 "><p id="p174423018579"><a name="p174423018579"></a><a name="p174423018579"></a>Number of post-FEC error frames.</p>
</td>
</tr>
<tr id="row185771035125713"><td class="cellrowborder" valign="top" width="40%" headers="mcps1.1.3.1.1 "><p id="p10577143515572"><a name="p10577143515572"></a><a name="p10577143515572"></a>st_fec_err_bit_num</p>
</td>
<td class="cellrowborder" valign="top" width="60%" headers="mcps1.1.3.1.2 "><p id="p19577163585716"><a name="p19577163585716"></a><a name="p19577163585716"></a>Number of pre-FEC bit errors.</p>
</td>
</tr>
</tbody>
</table>

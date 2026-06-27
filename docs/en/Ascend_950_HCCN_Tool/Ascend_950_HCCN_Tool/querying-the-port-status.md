# Querying the Port Status<a name="EN-US_TOPIC_0000002614931237"></a>

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

Queries the port status.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -port_info -i <dev_id> -u <udie_id> -p <port_id>
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
hccn_tool -g -port_info -i 0 -u 0 -p 4
```

Query the status of port 4 on UDie 0 under logical device ID 0.

```text
port_id: 0x4
======================= UB PORT LINK INFO =======================
target_speed: LANE_400G_X4
speed_ability: 400Gbps
lane_num: X4
fec: FEC RS
sds_rate: unset
port_usage: used
port_enable: on
port_link: link
driver_type: TYPE_NONE
port_mode: PORT_MODE_SHARED
link_down_err: 0x302
link_state: 0x0003 0x7310 0x5002 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 0x0000 
======================== UB DLPHY INFO ==========================
port_cna: 0x20
clock_freq: 0x4a3
fec: FEC Mode 1 RS (128, 120,T=4)
phy_mode_ctrl: Mode2
sds_rate: 106.25G
cur_speed: data rate8
cur_tx_lane_num: X4
cur_rx_lane_num: X4
init_succ_tx_lane_num: X4
init_succ_rx_lane_num: X4
port_en: on
port_mode: X4 2port
port_mode_en: on
dl_link: link
phy_link: link
cur_port_type: slave
lstm_state: LINK_ACTIVE
decoded_fail_block_num: 0x0
fec_err: 0x841876
retry_cnt: 0x0
dl_link_fsm: Initialization succeeded.
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row158963218468"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p10590133274615"><a name="p10590133274615"></a><a name="p10590133274615"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p6590632114610"><a name="p6590632114610"></a><a name="p6590632114610"></a>Port ID.</p>
</td>
</tr>
<tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p6109124172215"><a name="p6109124172215"></a><a name="p6109124172215"></a>target_speed</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p910920249224"><a name="p910920249224"></a><a name="p910920249224"></a>Target link establishment mode.</p>
</td>
</tr>
<tr id="row6384608211"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p4109132412222"><a name="p4109132412222"></a><a name="p4109132412222"></a>speed_ability</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p111093245225"><a name="p111093245225"></a><a name="p111093245225"></a>Supported maximum link speed represented in a bitmap.</p>
</td>
</tr>
<tr id="row17542318210"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1610915243228"><a name="p1610915243228"></a><a name="p1610915243228"></a>lane_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1710913249223"><a name="p1710913249223"></a><a name="p1710913249223"></a>Data transmission channel.</p>
</td>
</tr>
<tr id="row8543302116"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p3109172414229"><a name="p3109172414229"></a><a name="p3109172414229"></a>fec</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p110918246225"><a name="p110918246225"></a><a name="p110918246225"></a>FEC mode.</p>
</td>
</tr>
<tr id="row197115622110"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p17109192419227"><a name="p17109192419227"></a><a name="p17109192419227"></a>sds_rate</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p110912248220"><a name="p110912248220"></a><a name="p110912248220"></a>SerDes rate.</p>
</td>
</tr>
<tr id="row16711469218"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p10109924162213"><a name="p10109924162213"></a><a name="p10109924162213"></a>port_usage</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11091024132217"><a name="p11091024132217"></a><a name="p11091024132217"></a>Port usage.</p>
</td>
</tr>
<tr id="row9717662119"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p16109224172216"><a name="p16109224172216"></a><a name="p16109224172216"></a>port_enable</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p10109152412215"><a name="p10109152412215"></a><a name="p10109152412215"></a>Port enabling status.</p>
</td>
</tr>
<tr id="row137118611215"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p17109202432210"><a name="p17109202432210"></a><a name="p17109202432210"></a>port_link</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p131091824132210"><a name="p131091824132210"></a><a name="p131091824132210"></a>Port link establishment status.</p>
</td>
</tr>
<tr id="row9623104617219"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p171091249223"><a name="p171091249223"></a><a name="p171091249223"></a>driver_type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p9109122411227"><a name="p9109122411227"></a><a name="p9109122411227"></a>Driver type: <strong id="b59991250122019"><a name="b59991250122019"></a><a name="b59991250122019"></a>TYPE_NONE</strong> or <strong id="b6411254182018"><a name="b6411254182018"></a><a name="b6411254182018"></a>NA</strong>.</p>
</td>
</tr>
<tr id="row76235464214"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p13109152419221"><a name="p13109152419221"></a><a name="p13109152419221"></a>port_mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p17610152261110"><a name="p17610152261110"></a><a name="p17610152261110"></a>Port mode.</p>
</td>
</tr>
<tr id="row56234467212"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p3109182472216"><a name="p3109182472216"></a><a name="p3109182472216"></a>link_down_err</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p3610122231116"><a name="p3610122231116"></a><a name="p3610122231116"></a>Error code of a link establishment failure.</p>
</td>
</tr>
<tr id="row186232046152117"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1910922492217"><a name="p1910922492217"></a><a name="p1910922492217"></a>link_state</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p19610152211118"><a name="p19610152211118"></a><a name="p19610152211118"></a>MAC link status.</p>
</td>
</tr>
<tr id="row176231846182115"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p410972414223"><a name="p410972414223"></a><a name="p410972414223"></a>port_cna</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p15256946161112"><a name="p15256946161112"></a><a name="p15256946161112"></a>UB port network address.</p>
</td>
</tr>
<tr id="row362364692115"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1310902422210"><a name="p1310902422210"></a><a name="p1310902422210"></a>clock_freq</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1325624601113"><a name="p1325624601113"></a><a name="p1325624601113"></a>DLMAC clock frequency.</p>
</td>
</tr>
<tr id="row11143141162212"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p41094246225"><a name="p41094246225"></a><a name="p41094246225"></a>phy_mode_ctrl</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1032819214217"><a name="p1032819214217"></a><a name="p1032819214217"></a>Working mode of the physical layer.</p>
</td>
</tr>
<tr id="row514310115225"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p8109122417227"><a name="p8109122417227"></a><a name="p8109122417227"></a>sds_rate</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p9109112492215"><a name="p9109112492215"></a><a name="p9109112492215"></a>Target rate of the port.</p>
</td>
</tr>
<tr id="row514341111225"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p81098248225"><a name="p81098248225"></a><a name="p81098248225"></a>cur_speed</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p8802534102120"><a name="p8802534102120"></a><a name="p8802534102120"></a>Upper limit of the port link running speed.</p>
</td>
</tr>
<tr id="row214319110227"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p181091624172211"><a name="p181091624172211"></a><a name="p181091624172211"></a>cur_tx_lane_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p16903040132115"><a name="p16903040132115"></a><a name="p16903040132115"></a>Current TX link width.</p>
</td>
</tr>
<tr id="row12143161113224"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p14110132422213"><a name="p14110132422213"></a><a name="p14110132422213"></a>cur_rx_lane_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p207091418152614"><a name="p207091418152614"></a><a name="p207091418152614"></a>Current RX link width.</p>
</td>
</tr>
<tr id="row1214318116227"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1711052413224"><a name="p1711052413224"></a><a name="p1711052413224"></a>init_succ_tx_lane_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p6110132413222"><a name="p6110132413222"></a><a name="p6110132413222"></a>Lane width in the TX direction after successful initialization and link establishment.</p>
</td>
</tr>
<tr id="row161431111102215"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p51103245226"><a name="p51103245226"></a><a name="p51103245226"></a>init_succ_rx_lane_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1110202418228"><a name="p1110202418228"></a><a name="p1110202418228"></a>Lane width in the RX direction after successful initialization and link establishment.</p>
</td>
</tr>
<tr id="row18143181192212"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2110224192211"><a name="p2110224192211"></a><a name="p2110224192211"></a>port_en</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1110202412219"><a name="p1110202412219"></a><a name="p1110202412219"></a><strong id="b2360145114116"><a name="b2360145114116"></a><a name="b2360145114116"></a>MAC_PORT</strong> enablement.</p>
</td>
</tr>
<tr id="row19143121162210"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p18110624132213"><a name="p18110624132213"></a><a name="p18110624132213"></a>port_mode</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p21101124182218"><a name="p21101124182218"></a><a name="p21101124182218"></a><strong id="b4105175414113"><a name="b4105175414113"></a><a name="b4105175414113"></a>MAC_PORT</strong> mode.</p>
</td>
</tr>
<tr id="row14144131110229"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p4110124102210"><a name="p4110124102210"></a><a name="p4110124102210"></a>port_mode_en</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p19110162413223"><a name="p19110162413223"></a><a name="p19110162413223"></a><strong id="b122119587411"><a name="b122119587411"></a><a name="b122119587411"></a>MAC_PORT</strong> mode enablement.</p>
</td>
</tr>
<tr id="row614414119224"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p0110182462210"><a name="p0110182462210"></a><a name="p0110182462210"></a>dl_link</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p41100249229"><a name="p41100249229"></a><a name="p41100249229"></a>Data link error register.</p>
</td>
</tr>
<tr id="row1714421118223"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p411052411228"><a name="p411052411228"></a><a name="p411052411228"></a>phy_link</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p41104248227"><a name="p41104248227"></a><a name="p41104248227"></a>Whether the LSTM is in the linkup state.</p>
</td>
</tr>
<tr id="row8144011152217"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1711062417221"><a name="p1711062417221"></a><a name="p1711062417221"></a>cur_port_type</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p848055522612"><a name="p848055522612"></a><a name="p848055522612"></a>Current port type after the crosslink.</p>
</td>
</tr>
<tr id="row1914471162211"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p3110102482219"><a name="p3110102482219"></a><a name="p3110102482219"></a>lstm_state</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p163413461297"><a name="p163413461297"></a><a name="p163413461297"></a>Current LSTM status.</p>
</td>
</tr>
<tr id="row185278388227"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1482624912225"><a name="p1482624912225"></a><a name="p1482624912225"></a>decoded_fail_block_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p14826849132218"><a name="p14826849132218"></a><a name="p14826849132218"></a>MAC RX FEC <strong id="b16479103734819"><a name="b16479103734819"></a><a name="b16479103734819"></a>decoding_fail</strong> statistics.</p>
</td>
</tr>
<tr id="row9527738182210"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p108261949172216"><a name="p108261949172216"></a><a name="p108261949172216"></a>fec_err</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11826049112213"><a name="p11826049112213"></a><a name="p11826049112213"></a>MAC RX pre-FEC bit error statistics.</p>
</td>
</tr>
<tr id="row125278388229"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p148261149102220"><a name="p148261149102220"></a><a name="p148261149102220"></a>retry_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p58268497225"><a name="p58268497225"></a><a name="p58268497225"></a>Number of physical layer reinitializations.</p>
</td>
</tr>
<tr id="row13144121132210"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p148261849132220"><a name="p148261849132220"></a><a name="p148261849132220"></a>dl_link_fsm</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p0826204917221"><a name="p0826204917221"></a><a name="p0826204917221"></a>State machine status register.</p>
</td>
</tr>
</tbody>
</table>

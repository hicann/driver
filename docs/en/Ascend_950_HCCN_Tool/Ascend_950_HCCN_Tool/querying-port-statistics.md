# Querying Port Statistics<a name="EN-US_TOPIC_0000002614931235"></a>

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

Queries port statistics.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -stat -i <dev_id> -u <udie_id> -p <port_id>
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
hccn_tool -g -stat -i 0 -u 0 -p 4
```

Query the statistics of port 4 on UDie 0 under logical device ID 0.

```text
packet statistics:
port_id: 4
is_uboe_port: 0
ub_glb_ipv4_pkt_cnt_rx: 0
ub_glb_ipv6_pkt_cnt_rx: 0
unic_ipv4_pkt_cnt_rx: 0
unic_ipv6_pkt_cnt_rx: 0
ub_clan_pkt_cnt_rx: 0
ub_umoc_ctph_cnt_rx: 0
ub_umoc_ntph_cnt_rx: 0
ub_mem_pkt_cnt_rx: 0
unknown_pkt_cnt_rx: 0
drop_ind_cnt_rx: 0
err_ind_cnt_rx: 0
to_host_pkt_cnt_rx: 0
to_imp_pkt_cnt_rx: 0
to_mar_pkt_cnt_rx: 0
to_link_pkt_cnt_rx: 0
to_noc_pkt_cnt_rx: 0
route_err_cnt_rx: 0
out_err_cnt_rx: 0
length_err_cnt_rx: 0
rx_busi_flit_num: 0
rx_send_ack_flit: 0
ub_glb_ipv4_pkt_cnt_tx: 0
ub_glb_ipv6_pkt_cnt_tx: 0
unic_ipv4_pkt_cnt_tx: 0
unic_ipv6_pkt_cnt_tx: 0
ub_clan_pkt_cnt_tx: 0
ub_umoc_ctph_cnt_tx: 0
ub_umoc_ntph_cnt_tx: 0
ub_mem_pkt_cnt_tx: 0
unknown_pkt_cnt_tx: 0
drop_ind_cnt_tx: 0
err_ind_cnt_tx: 0
lpbk_ind_cnt_tx: 0
out_err_cnt_tx: 0
length_err_cnt_tx: 0
tx_busi_flit_num: 0
tx_recv_ack_flit: 0
retry_req_sum: 0
retry_ack_sum: 0
crc_error_sum: 0
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p151388917155"><a name="p151388917155"></a><a name="p151388917155"></a>port_id</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p613811941512"><a name="p613811941512"></a><a name="p613811941512"></a>Port ID.</p>
</td>
</tr>
<tr id="row161171213146"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p713817921516"><a name="p713817921516"></a><a name="p713817921516"></a>is_uboe_port</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1138698151"><a name="p1138698151"></a><a name="p1138698151"></a>Whether the port is a UBoE port.</p>
<a name="ul1647117642816"></a><a name="ul1647117642816"></a><ul id="ul1647117642816"><li><strong id="b17584121075718"><a name="b17584121075718"></a><a name="b17584121075718"></a>0</strong>: UB port.</li><li><strong id="b1115392818572"><a name="b1115392818572"></a><a name="b1115392818572"></a>1</strong>: UBoE port.</li></ul>
</td>
</tr>
<tr id="row167171714181414"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p121381591156"><a name="p121381591156"></a><a name="p121381591156"></a>ub_glb_ipv4_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p2242182519432"><a name="p2242182519432"></a><a name="p2242182519432"></a>Number of IPv4 UB packets received on the RX side.</p>
</td>
</tr>
<tr id="row197172014121410"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p161386917154"><a name="p161386917154"></a><a name="p161386917154"></a>ub_glb_ipv6_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p20242102564315"><a name="p20242102564315"></a><a name="p20242102564315"></a>Number of IPv6 UB packets received on the RX side.</p>
</td>
</tr>
<tr id="row4245191831415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1913859171516"><a name="p1913859171516"></a><a name="p1913859171516"></a>unic_ipv4_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p7734396431"><a name="p7734396431"></a><a name="p7734396431"></a>Number of IPv4 UNIC packets received on the RX side.</p>
</td>
</tr>
<tr id="row22458189144"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p141384912153"><a name="p141384912153"></a><a name="p141384912153"></a>unic_ipv6_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p47323954318"><a name="p47323954318"></a><a name="p47323954318"></a>Number of IPv6 UNIC packets received on the RX side.</p>
</td>
</tr>
<tr id="row32456189141"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p161386910150"><a name="p161386910150"></a><a name="p161386910150"></a>ub_clan_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11648195104616"><a name="p11648195104616"></a><a name="p11648195104616"></a>Number of CFG6 packets received on the RX side.</p>
</td>
</tr>
<tr id="row62459186141"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p813816910153"><a name="p813816910153"></a><a name="p813816910153"></a>ub_umoc_ctph_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p464814519466"><a name="p464814519466"></a><a name="p464814519466"></a>Number of CFG7 CLAN packets received on the RX side.</p>
</td>
</tr>
<tr id="row961202211411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1313811920154"><a name="p1313811920154"></a><a name="p1313811920154"></a>ub_umoc_ntph_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1264818517465"><a name="p1264818517465"></a><a name="p1264818517465"></a>Number of CFG7 non-CLAN packets received on the RX side.</p>
</td>
</tr>
<tr id="row136213229142"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1138995158"><a name="p1138995158"></a><a name="p1138995158"></a>ub_mem_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p364814564618"><a name="p364814564618"></a><a name="p364814564618"></a>Number of UB mem packets received on the RX side.</p>
</td>
</tr>
<tr id="row3626227140"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p141389912154"><a name="p141389912154"></a><a name="p141389912154"></a>unknown_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p136481654467"><a name="p136481654467"></a><a name="p136481654467"></a>Number of unknown packets received on the RX side.</p>
</td>
</tr>
<tr id="row16272251411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1138495154"><a name="p1138495154"></a><a name="p1138495154"></a>drop_ind_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p206482554619"><a name="p206482554619"></a><a name="p206482554619"></a><strong id="b105731214102513"><a name="b105731214102513"></a><a name="b105731214102513"></a>drop_ind</strong> packets received on the RX side.</p>
</td>
</tr>
<tr id="row1562182291418"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1313811911155"><a name="p1313811911155"></a><a name="p1313811911155"></a>err_ind_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1764875184616"><a name="p1764875184616"></a><a name="p1764875184616"></a>Number of ERR packets received on the RX side.</p>
</td>
</tr>
<tr id="row462722191411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p191381990156"><a name="p191381990156"></a><a name="p191381990156"></a>to_host_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p564813519464"><a name="p564813519464"></a><a name="p564813519464"></a>Number of packets that are received on the RX side and delivered to the host after routing (excluding enumeration configuration packets and management packets).</p>
</td>
</tr>
<tr id="row1962122211414"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1139139131516"><a name="p1139139131516"></a><a name="p1139139131516"></a>to_imp_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p176489554613"><a name="p176489554613"></a><a name="p176489554613"></a>Number of enumeration configuration packets and management packets that are received on the RX side and delivered to the host after routing.</p>
</td>
</tr>
<tr id="row4621522141413"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p213912961510"><a name="p213912961510"></a><a name="p213912961510"></a>to_mar_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1664818518461"><a name="p1664818518461"></a><a name="p1664818518461"></a>Number of UB memory packets that are received on the RX side and delivered to the host after routing.</p>
</td>
</tr>
<tr id="row5513925201410"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2013969171516"><a name="p2013969171516"></a><a name="p2013969171516"></a>to_link_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p156481516466"><a name="p156481516466"></a><a name="p156481516466"></a>Number of packets received on the RX side that, after routing, are forwarded to the TX side of the same port.</p>
</td>
</tr>
<tr id="row451462520140"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p4139695159"><a name="p4139695159"></a><a name="p4139695159"></a>to_noc_pkt_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p56482058469"><a name="p56482058469"></a><a name="p56482058469"></a>Number of P2P packets received on the RX side after routing.</p>
</td>
</tr>
<tr id="row151432518147"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1513910941518"><a name="p1513910941518"></a><a name="p1513910941518"></a>route_err_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p11401146104914"><a name="p11401146104914"></a><a name="p11401146104914"></a>Number of packets received on the RX side that encounter routing table lookup errors after routing.</p>
</td>
</tr>
<tr id="row15514132517149"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p141391941511"><a name="p141391941511"></a><a name="p141391941511"></a>out_err_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p140194694917"><a name="p140194694917"></a><a name="p140194694917"></a>Total number of erroneous packets, among those received on the RX side, identified after verification.</p>
</td>
</tr>
<tr id="row85141257144"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p81391491158"><a name="p81391491158"></a><a name="p81391491158"></a>length_err_cnt_rx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p64014624915"><a name="p64014624915"></a><a name="p64014624915"></a>Number of packets with length errors among those received on the RX side.</p>
</td>
</tr>
<tr id="row1951472513141"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p813912961518"><a name="p813912961518"></a><a name="p813912961518"></a>rx_busi_flit_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p740194617496"><a name="p740194617496"></a><a name="p740194617496"></a>Number of bytes in RX packets.</p>
</td>
</tr>
<tr id="row1351472571412"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1813979201520"><a name="p1813979201520"></a><a name="p1813979201520"></a>rx_send_ack_flit</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p140104616491"><a name="p140104616491"></a><a name="p140104616491"></a>Number of bytes in acknowledgement packets sent from the RX side to the peer.</p>
</td>
</tr>
<tr id="row55145257142"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p21399911511"><a name="p21399911511"></a><a name="p21399911511"></a>ub_glb_ipv4_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p589021016500"><a name="p589021016500"></a><a name="p589021016500"></a>Number of IPv4 UB packets sent from the TX side.</p>
</td>
</tr>
<tr id="row9514225191412"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1013919921513"><a name="p1013919921513"></a><a name="p1013919921513"></a>ub_glb_ipv6_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p98901510195017"><a name="p98901510195017"></a><a name="p98901510195017"></a>Number of IPv6 UB packets sent from the TX side.</p>
</td>
</tr>
<tr id="row1351418258147"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p12139998155"><a name="p12139998155"></a><a name="p12139998155"></a>unic_ipv4_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p88904107506"><a name="p88904107506"></a><a name="p88904107506"></a>Number of IPv4 UNIC packets sent from the TX side.</p>
</td>
</tr>
<tr id="row05142257143"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p191397941513"><a name="p191397941513"></a><a name="p191397941513"></a>unic_ipv6_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p118902010165015"><a name="p118902010165015"></a><a name="p118902010165015"></a>Number of IPv6 UNIC packets sent from the TX side.</p>
</td>
</tr>
<tr id="row1651432519145"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p213916961511"><a name="p213916961511"></a><a name="p213916961511"></a>ub_clan_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1789020106504"><a name="p1789020106504"></a><a name="p1789020106504"></a>Number of CFG6 packets sent from the TX side.</p>
</td>
</tr>
<tr id="row4514625121418"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p2139797153"><a name="p2139797153"></a><a name="p2139797153"></a>ub_umoc_ctph_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p28901910195014"><a name="p28901910195014"></a><a name="p28901910195014"></a>Number of CFG7 CLAN packets sent from the TX side.</p>
</td>
</tr>
<tr id="row205141425191414"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p171399920157"><a name="p171399920157"></a><a name="p171399920157"></a>ub_umoc_ntph_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1489011015503"><a name="p1489011015503"></a><a name="p1489011015503"></a>Number of CFG7 non-CLAN packets sent from the TX side.</p>
</td>
</tr>
<tr id="row165141225191411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p413914941517"><a name="p413914941517"></a><a name="p413914941517"></a>ub_mem_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p198902010205019"><a name="p198902010205019"></a><a name="p198902010205019"></a>Number of UB mem packets sent from the TX side.</p>
</td>
</tr>
<tr id="row13514162551419"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1139179201515"><a name="p1139179201515"></a><a name="p1139179201515"></a>unknown_pkt_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1989013102503"><a name="p1989013102503"></a><a name="p1989013102503"></a>Number of unknown packets sent from the TX side.</p>
</td>
</tr>
<tr id="row6797534161411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1313912917157"><a name="p1313912917157"></a><a name="p1313912917157"></a>drop_ind_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p10507151815515"><a name="p10507151815515"></a><a name="p10507151815515"></a><strong id="b104466573313"><a name="b104466573313"></a><a name="b104466573313"></a>drop_ind</strong> packets sent from the TX side.</p>
</td>
</tr>
<tr id="row9797193410146"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1613909121513"><a name="p1613909121513"></a><a name="p1613909121513"></a>err_ind_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p17507318145117"><a name="p17507318145117"></a><a name="p17507318145117"></a>Number of ERR packets sent from the TX side.</p>
</td>
</tr>
<tr id="row18798234111411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p111397931512"><a name="p111397931512"></a><a name="p111397931512"></a>lpbk_ind_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1350771825117"><a name="p1350771825117"></a><a name="p1350771825117"></a>Number of packets sent from the TX side in Netlist Loopback (NL).</p>
</td>
</tr>
<tr id="row879843481411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p101393971518"><a name="p101393971518"></a><a name="p101393971518"></a>out_err_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p45076184519"><a name="p45076184519"></a><a name="p45076184519"></a>Total number of erroneous packets, among those sent from the TX side, identified after verification.</p>
</td>
</tr>
<tr id="row779853461415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p21395915156"><a name="p21395915156"></a><a name="p21395915156"></a>length_err_cnt_tx</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p850761845119"><a name="p850761845119"></a><a name="p850761845119"></a>Number of packets length errors among those sent from the TX side.</p>
</td>
</tr>
<tr id="row14798103411147"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p5139209141515"><a name="p5139209141515"></a><a name="p5139209141515"></a>tx_busi_flit_num</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p105071718185119"><a name="p105071718185119"></a><a name="p105071718185119"></a>Number of bytes in TX packets.</p>
</td>
</tr>
<tr id="row2798143491416"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p4139194158"><a name="p4139194158"></a><a name="p4139194158"></a>tx_recv_ack_flit</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p4507118195111"><a name="p4507118195111"></a><a name="p4507118195111"></a>Number of bytes in acknowledgement packets received on the TX side from the peer.</p>
</td>
</tr>
<tr id="row14798173416149"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p101393911153"><a name="p101393911153"></a><a name="p101393911153"></a>retry_req_sum</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1850718181510"><a name="p1850718181510"></a><a name="p1850718181510"></a>Number of retransmission requests.</p>
</td>
</tr>
<tr id="row179813431417"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p61402091154"><a name="p61402091154"></a><a name="p61402091154"></a>retry_ack_sum</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p14508218205110"><a name="p14508218205110"></a><a name="p14508218205110"></a>Number of acknowledgment retransmissions.</p>
</td>
</tr>
<tr id="row1079817343149"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p17140594153"><a name="p17140594153"></a><a name="p17140594153"></a>crc_error_sum</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p15086189512"><a name="p15086189512"></a><a name="p15086189512"></a>Number of CRC errors.</p>
</td>
</tr>
</tbody>
</table>

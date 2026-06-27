# Querying Port Link Information When the Link Is Down<a name="EN-US_TOPIC_0000002584451438"></a>

## Product Support<a name="section5790730141118"></a>

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

## Function<a name="section957615561617"></a>

Queries the port link information when the link is down.

## Precautions<a name="section8415102071"></a>

If the link down event is triggered for five or more times, five link information records are displayed after this command is executed. If the link down event is triggered for less than five times, the actual number of link down records is displayed.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -g -down_data -i <dev_id> -u <udie_id> -p <port_id>
```

## Parameters<a name="section107781620873"></a>

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
<tr id="en-us_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
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

## Example<a name="section185511229978"></a>

```bash
hccn_tool -g -down_data -i 0 -u 0 -p 4
```

Query the information about the link of port 4 on UDie 0 under logical device ID 0 when the link is down.

```text
down data of udie 0 port 4 - log row 0:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 498960     | 0              | 0       | 770        | 81      | 93         | 3          |
| 1    | 473616     | 0              | 0       | 759        | 78      | 93         | 1          |
| 2    | 484720     | 0              | 0       | 730        | 83      | 93         | 3          |
| 3    | 467552     | 0              | 0       | 769        | 76      | 91         | 127        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 1:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 465152     | 0              | 0       | 736        | 79      | 93         | 2          |
| 1    | 469576     | 0              | 0       | 743        | 79      | 93         | 1          |
| 2    | 489888     | 0              | 0       | 756        | 81      | 93         | 3          |
| 3    | 478016     | 0              | 0       | 776        | 77      | 91         | 0          |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 2:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 477792     | 0              | 0       | 756        | 79      | 93         | 2          |
| 1    | 443032     | 0              | 0       | 701        | 79      | 91         | 2          |
| 2    | 0          | -2             | 0       | 0          | 0       | 95         | 2          |
| 3    | 496128     | 0              | 0       | 816        | 76      | 91         | 127        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 3:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 468120     | 0              | 0       | 705        | 83      | 93         | 5          |
| 1    | 474000     | 0              | 0       | 750        | 79      | 94         | 1          |
| 2    | 495456     | 0              | 0       | 794        | 78      | 93         | 3          |
| 3    | 485888     | 0              | 0       | 832        | 73      | 90         | 126        |
+------+------------+----------------+---------+------------+---------+------------+------------+
down data of udie 0 port 4 - log row 4:

+------+------------+----------------+---------+------------+---------+------------+------------+
| lane | snr_metric | metric_his_min | err_avg | cycles_avg | heh_avg | c3_ud_2csr | c5_ud_2csr |
+------+------------+----------------+---------+------------+---------+------------+------------+
| 0    | 0          | -2             | 0       | 0          | 0       | 93         | 1          |
| 1    | 492608     | 0              | 0       | 716        | 86      | 93         | 4          |
| 2    | 497904     | 0              | 0       | 759        | 82      | 93         | 2          |
| 3    | 477744     | 0              | 0       | 807        | 74      | 91         | 0          |
+------+------------+----------------+---------+------------+---------+------------+------------+
```

## Output Description<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row449219401435"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1349212401437"><a name="p1349212401437"></a><a name="p1349212401437"></a>lane</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1649216401234"><a name="p1649216401234"></a><a name="p1649216401234"></a>Data transmission channel.</p>
</td>
</tr>
<tr id="row4340844835"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1340344431"><a name="p1340344431"></a><a name="p1340344431"></a>snr_metric</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p834020441319"><a name="p834020441319"></a><a name="p834020441319"></a>SNR.</p>
</td>
</tr>
<tr id="row1449592171419"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1549511251416"><a name="p1549511251416"></a><a name="p1549511251416"></a>metric_his_min</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1749519281418"><a name="p1749519281418"></a><a name="p1749519281418"></a>Historical minimum metric value.</p>
</td>
</tr>
<tr id="row18495222144"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p749515210145"><a name="p749515210145"></a><a name="p749515210145"></a>err_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p184951720147"><a name="p184951720147"></a><a name="p184951720147"></a>Error rate.</p>
</td>
</tr>
<tr id="row178331094146"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p15833594140"><a name="p15833594140"></a><a name="p15833594140"></a>cycles_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p58331992148"><a name="p58331992148"></a><a name="p58331992148"></a>Average period value.</p>
</td>
</tr>
<tr id="row783318961411"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p38331291146"><a name="p38331291146"></a><a name="p38331291146"></a>heh_avg</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p1483316913147"><a name="p1483316913147"></a><a name="p1483316913147"></a>Average value of historical hardware errors.</p>
</td>
</tr>
<tr id="row55597130142"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p185597134148"><a name="p185597134148"></a><a name="p185597134148"></a>c3_ud_2csr</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p8559101310149"><a name="p8559101310149"></a><a name="p8559101310149"></a>Updates the C3 register to the configuration status register.</p>
</td>
</tr>
<tr id="row655901316146"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p25594137142"><a name="p25594137142"></a><a name="p25594137142"></a>c5_ud_2csr</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p20559111316149"><a name="p20559111316149"></a><a name="p20559111316149"></a>Updates the C5 register to the configuration status register.</p>
</td>
</tr>
</tbody>
</table>

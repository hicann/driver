# Exporting Register Information of a Port<a name="EN-US_TOPIC_0000002614931221"></a>

## Product Support<a name="section5790730141118"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row14269102720616"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p172695271467"><a name="en-us_topic_0000002614931227_p172695271467"></a><a name="en-us_topic_0000002614931227_p172695271467"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p52691927763"><a name="en-us_topic_0000002614931227_p52691927763"></a><a name="en-us_topic_0000002614931227_p52691927763"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p42695271962"><a name="en-us_topic_0000002614931227_p42695271962"></a><a name="en-us_topic_0000002614931227_p42695271962"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p17269227665"><a name="en-us_topic_0000002614931227_p17269227665"></a><a name="en-us_topic_0000002614931227_p17269227665"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p182691427865"><a name="en-us_topic_0000002614931227_p182691427865"></a><a name="en-us_topic_0000002614931227_p182691427865"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p132695278611"><a name="en-us_topic_0000002614931227_p132695278611"></a><a name="en-us_topic_0000002614931227_p132695278611"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p1026914271765"><a name="en-us_topic_0000002614931227_p1026914271765"></a><a name="en-us_topic_0000002614931227_p1026914271765"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row42691727369"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p72697275618"><a name="en-us_topic_0000002614931227_p72697275618"></a><a name="en-us_topic_0000002614931227_p72697275618"></a><strong id="en-us_topic_0000002614931227_b264715591859"><a name="en-us_topic_0000002614931227_b264715591859"></a><a name="en-us_topic_0000002614931227_b264715591859"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p826942711620"><a name="en-us_topic_0000002614931227_p826942711620"></a><a name="en-us_topic_0000002614931227_p826942711620"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b69463020619"><a name="en-us_topic_0000002614931227_b69463020619"></a><a name="en-us_topic_0000002614931227_b69463020619"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p1126912271564"><a name="en-us_topic_0000002614931227_p1126912271564"></a><a name="en-us_topic_0000002614931227_p1126912271564"></a><strong id="en-us_topic_0000002614931227_b1314602866"><a name="en-us_topic_0000002614931227_b1314602866"></a><a name="en-us_topic_0000002614931227_b1314602866"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p122691627568"><a name="en-us_topic_0000002614931227_p122691627568"></a><a name="en-us_topic_0000002614931227_p122691627568"></a><strong id="en-us_topic_0000002614931227_b26181437611"><a name="en-us_topic_0000002614931227_b26181437611"></a><a name="en-us_topic_0000002614931227_b26181437611"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p1326917271617"><a name="en-us_topic_0000002614931227_p1326917271617"></a><a name="en-us_topic_0000002614931227_p1326917271617"></a><strong id="en-us_topic_0000002614931227_b12619740614"><a name="en-us_topic_0000002614931227_b12619740614"></a><a name="en-us_topic_0000002614931227_b12619740614"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p192691827266"><a name="en-us_topic_0000002614931227_p192691827266"></a><a name="en-us_topic_0000002614931227_p192691827266"></a><strong id="en-us_topic_0000002614931227_b15809755613"><a name="en-us_topic_0000002614931227_b15809755613"></a><a name="en-us_topic_0000002614931227_b15809755613"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p9269112715614"><a name="en-us_topic_0000002614931227_p9269112715614"></a><a name="en-us_topic_0000002614931227_p9269112715614"></a><strong id="en-us_topic_0000002614931227_b692676363"><a name="en-us_topic_0000002614931227_b692676363"></a><a name="en-us_topic_0000002614931227_b692676363"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row32690271462"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p1326922714616"><a name="en-us_topic_0000002614931227_p1326922714616"></a><a name="en-us_topic_0000002614931227_p1326922714616"></a><span id="en-us_topic_0000002614931227_ph026915273616"><a name="en-us_topic_0000002614931227_ph026915273616"></a><a name="en-us_topic_0000002614931227_ph026915273616"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p1726915271965"><a name="en-us_topic_0000002614931227_p1726915271965"></a><a name="en-us_topic_0000002614931227_p1726915271965"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p162697275617"><a name="en-us_topic_0000002614931227_p162697275617"></a><a name="en-us_topic_0000002614931227_p162697275617"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p1626910276617"><a name="en-us_topic_0000002614931227_p1626910276617"></a><a name="en-us_topic_0000002614931227_p1626910276617"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p1934621384210"><a name="en-us_topic_0000002614931227_p1934621384210"></a><a name="en-us_topic_0000002614931227_p1934621384210"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p19841137192417"><a name="en-us_topic_0000002614931227_p19841137192417"></a><a name="en-us_topic_0000002614931227_p19841137192417"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p17984123714247"><a name="en-us_topic_0000002614931227_p17984123714247"></a><a name="en-us_topic_0000002614931227_p17984123714247"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p9984103792411"><a name="en-us_topic_0000002614931227_p9984103792411"></a><a name="en-us_topic_0000002614931227_p9984103792411"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row1327082715616"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p202701127863"><a name="en-us_topic_0000002614931227_p202701127863"></a><a name="en-us_topic_0000002614931227_p202701127863"></a>Note: <strong id="en-us_topic_0000002614931227_b16391912863"><a name="en-us_topic_0000002614931227_b16391912863"></a><a name="en-us_topic_0000002614931227_b16391912863"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b13961218612"><a name="en-us_topic_0000002614931227_b13961218612"></a><a name="en-us_topic_0000002614931227_b13961218612"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b1640112165"><a name="en-us_topic_0000002614931227_b1640112165"></a><a name="en-us_topic_0000002614931227_b1640112165"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="section957615561617"></a>

Exports a port's register information.

## Precautions<a name="section8415102071"></a>

Before running this command, enable the debug log level as described in "Setting the Device-Side System Log Level" in the  _msnpureport Instructions_. After running this command, you can run the  **msnpureport -f**  command to collect NPU logs. A timestamped log folder is generated in the current path. For device logs, view the target register information in the  **/slog/device-os-X/debug/device-os**  or  **/slog/device-os-X/debug/device-X**  directory of this log folder.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -t -dump -i <dev_id> -u <udie_id> -p <port_id>
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
hccn_tool -t -dump -i 0 -u 0 -p 4
```

Export the register information of port 4 on UDie 0 under logical device ID 0.

```text
Cmd executed successfully!
```

## Output Description<a name="section1726420371679"></a>

None.

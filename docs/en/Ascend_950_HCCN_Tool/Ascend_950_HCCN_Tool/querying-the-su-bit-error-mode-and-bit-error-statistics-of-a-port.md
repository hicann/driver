# Querying the SU Bit Error Mode and Bit Error Statistics of a Port<a name="EN-US_TOPIC_0000002584451422"></a>

## Product Support<a name="section5790730141118"></a>

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

Queries a port's SU bit error mode and bit error statistics.

## Precautions<a name="section8415102071"></a>

None.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -g -su_ber -i <dev_id> -u <udie_id> -p <port_id> [-mode_status | -result]
```

## Parameters<a name="section107781620873"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="21.15%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="22.56%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="en-us_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p16538337122410"><a name="en-us_topic_0000002614931223_p16538337122410"></a><a name="en-us_topic_0000002614931223_p16538337122410"></a>Chip UDie ID. The value is <strong id="en-us_topic_0000002614931223_b4277211143916"><a name="en-us_topic_0000002614931223_b4277211143916"></a><a name="en-us_topic_0000002614931223_b4277211143916"></a>0</strong>. You can run the command in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a> to query the value.</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p1911115561611"><a name="en-us_topic_0000002614931223_p1911115561611"></a><a name="en-us_topic_0000002614931223_p1911115561611"></a>Chip port ID. For details, see <strong id="en-us_topic_0000002614931223_b15791243184015"><a name="en-us_topic_0000002614931223_b15791243184015"></a><a name="en-us_topic_0000002614931223_b15791243184015"></a>Port ID</strong> in the output description in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a>.</p>
</td>
</tr>
<tr id="row18231157685"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p15238575810"><a name="p15238575810"></a><a name="p15238575810"></a>-mode_status</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p523205712819"><a name="p523205712819"></a><a name="p523205712819"></a>Optional. Use either this option or the <strong id="b4781826163713"><a name="b4781826163713"></a><a name="b4781826163713"></a>-result</strong> option.</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p11237571984"><a name="p11237571984"></a><a name="p11237571984"></a>If this option is specified, the SU bit error mode is queried.</p>
</td>
</tr>
<tr id="row1713811316106"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p1913812319104"><a name="p1913812319104"></a><a name="p1913812319104"></a>-result</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p11383341017"><a name="p11383341017"></a><a name="p11383341017"></a>Optional. Use either this option or the <strong id="b15572182717217"><a name="b15572182717217"></a><a name="b15572182717217"></a>-mode_status</strong> option.</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p51381314101"><a name="p51381314101"></a><a name="p51381314101"></a>If this option is specified, the SU bit error statistics are queried.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section185511229978"></a>

- Example 1:

    ```bash
    hccn_tool -g -su_ber -i 0 -u 0 -p 4 -mode_status
    ```

    Query the SU bit error mode of port 4 on UDie 0 under logical device ID 0.

    ```text
    +-----+------+------+--------------+-----------+
    | NPU | UDie | Port | su_itlv_mode | status    |
    +-----+------+------+--------------+-----------+
    | 0   | 0    | 4    | non-itlv     | stop      |
    +-----+------+------+--------------+-----------+
    ```

- Example 2:

    ```bash
    hccn_tool -g -su_ber -i 0 -u 0 -p 4 -result
    ```

    Query the SU bit error statistics for port 4 on UDie 0 under logical device ID 0.

    ```text
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    | NPU | UDie | Port | Lane | Done | Bit_err_cnt | Err_symb_t4 | Frm_cnt   | Frm_bit | Su_ber_rate  | Su_err_frame_rate |
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    | 0   | 0    | 4    | 0x0  | 0x1  | 0x2ea       | 0x0         | 0x8000000 | 0x400   | 5.427864e-09 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x1  | 0x1  | 0x2d8       | 0x0         | 0x8000000 | 0x400   | 5.296897e-09 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x2  | 0x1  | 0xb1c       | 0x0         | 0x8000000 | 0x400   | 2.069282e-08 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x3  | 0x1  | 0x492       | 0x0         | 0x8000000 | 0x400   | 8.512870e-09 | 0.000000e+00      |
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    ```

## Output Description<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p831664130"><a name="p831664130"></a><a name="p831664130"></a>NPU</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p129921859135"><a name="p129921859135"></a><a name="p129921859135"></a><span id="ph1350914718575"><a name="ph1350914718575"></a><a name="ph1350914718575"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="row102441771424"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1724410719210"><a name="p1724410719210"></a><a name="p1724410719210"></a>UDie</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p15244471828"><a name="p15244471828"></a><a name="p15244471828"></a>Chip UDie ID.</p>
</td>
</tr>
<tr id="row1737121118214"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p337118111024"><a name="p337118111024"></a><a name="p337118111024"></a>Port</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1037111110214"><a name="p1037111110214"></a><a name="p1037111110214"></a>Port ID.</p>
</td>
</tr>
<tr id="row105804431624"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p155806431028"><a name="p155806431028"></a><a name="p155806431028"></a>su_itlv_mode</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1858010433218"><a name="p1858010433218"></a><a name="p1858010433218"></a>SU BER interleaving mode status. Currently, it is set to the non-interleaving mode.</p>
<a name="ul2057074114164"></a><a name="ul2057074114164"></a><ul id="ul2057074114164"><li><strong id="b8267524153318"><a name="b8267524153318"></a><a name="b8267524153318"></a>itlv</strong>: interleaving mode.</li><li><strong id="b71896305339"><a name="b71896305339"></a><a name="b71896305339"></a>non-itlv</strong>: non-interleaving mode.</li></ul>
</td>
</tr>
<tr id="row9580743629"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p25801443822"><a name="p25801443822"></a><a name="p25801443822"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p17443443171613"><a name="p17443443171613"></a><a name="p17443443171613"></a>Configuration status of the port SU bit error detection function.</p>
<a name="ul820193403715"></a><a name="ul820193403715"></a><ul id="ul820193403715"><li><strong id="b1447675518448"><a name="b1447675518448"></a><a name="b1447675518448"></a>tx_enable</strong>: enabled for TX.</li><li><strong id="b980941458"><a name="b980941458"></a><a name="b980941458"></a>rx_enable</strong>: enabled for RX.</li><li><strong id="b47991796451"><a name="b47991796451"></a><a name="b47991796451"></a>stop</strong>: disabled.</li></ul>
</td>
</tr>
<tr id="row178501240151416"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p113145619146"><a name="p113145619146"></a><a name="p113145619146"></a>Lane</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1831195617142"><a name="p1831195617142"></a><a name="p1831195617142"></a>Lane ID.</p>
</td>
</tr>
<tr id="row785194015141"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p153115618148"><a name="p153115618148"></a><a name="p153115618148"></a>Done</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p19397152962610"><a name="p19397152962610"></a><a name="p19397152962610"></a>SU bit error result status:</p>
<a name="ul113353552718"></a><a name="ul113353552718"></a><ul id="ul113353552718"><li><strong id="b8478134744619"><a name="b8478134744619"></a><a name="b8478134744619"></a>0x0</strong>: No data is available or bit error statistics are not complete.</li><li><strong id="b11599105517460"><a name="b11599105517460"></a><a name="b11599105517460"></a>0x1</strong>: Completed.</li><li><strong id="b076905874614"><a name="b076905874614"></a><a name="b076905874614"></a>Others</strong>: Abnormal state.</li></ul>
</td>
</tr>
<tr id="row138519407149"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p331115615144"><a name="p331115615144"></a><a name="p331115615144"></a>Bit_err_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p7311356151418"><a name="p7311356151418"></a><a name="p7311356151418"></a>Number of SU bit errors.</p>
</td>
</tr>
<tr id="row128511840141410"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p19312569149"><a name="p19312569149"></a><a name="p19312569149"></a>Err_symb_t4</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p18318561145"><a name="p18318561145"></a><a name="p18318561145"></a>Number of SU error frames with more than four symbol errors.</p>
</td>
</tr>
<tr id="row785114403148"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p2031115617144"><a name="p2031115617144"></a><a name="p2031115617144"></a>Frm_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p2311256191414"><a name="p2311256191414"></a><a name="p2311256191414"></a>Total number of SU frames.</p>
</td>
</tr>
<tr id="row4645203712595"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p431115614141"><a name="p431115614141"></a><a name="p431115614141"></a>Frm_bit</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p23185651414"><a name="p23185651414"></a><a name="p23185651414"></a>Number of SU error bits in each frame.</p>
</td>
</tr>
<tr id="row119661251171514"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p23185641414"><a name="p23185641414"></a><a name="p23185641414"></a>Su_ber_rate</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1131125691418"><a name="p1131125691418"></a><a name="p1131125691418"></a>SU BER. Formula: <strong id="b11911174922312"><a name="b11911174922312"></a><a name="b11911174922312"></a>Bit_err_cnt</strong>/(<strong id="b192091453172312"><a name="b192091453172312"></a><a name="b192091453172312"></a>Frm_cnt</strong> x <strong id="b52071055192319"><a name="b52071055192319"></a><a name="b52071055192319"></a>Frm_bit</strong>)</p>
</td>
</tr>
<tr id="row771115579163"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p33115601418"><a name="p33115601418"></a><a name="p33115601418"></a>Su_err_frame_rate</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1531185681420"><a name="p1531185681420"></a><a name="p1531185681420"></a>SU error frame rate. Formula: <strong id="b237922287"><a name="b237922287"></a><a name="b237922287"></a>Err_symb_t4</strong>/<strong id="b154883792511240"><a name="b154883792511240"></a><a name="b154883792511240"></a>Frm_cnt</strong></p>
</td>
</tr>
</tbody>
</table>

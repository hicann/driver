# dcmiv2\_exec\_ub\_ping<a name="EN-US_TOPIC_0000002563055455"></a>

## Prototype<a name="en-us_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_exec\_ub\_ping\(int dev\_id, struct dcmi\_ub\_ping\_operate \*ping\_args, struct ub\_ping\_result \*ping\_result\)**

## Description<a name="en-us_topic_0000002227065381_section126852122411"></a>

Queries the result of a UB ping from a specified device to a destination address.

## Parameter Description<a name="en-us_topic_0000002227065381_section1527155212240"></a>

<a name="en-us_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="en-us_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002227065381_p1467135212241"><a name="en-us_topic_0000002227065381_p1467135212241"></a><a name="en-us_topic_0000002227065381_p1467135212241"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002227065381_p1367152172415"><a name="en-us_topic_0000002227065381_p1367152172415"></a><a name="en-us_topic_0000002227065381_p1367152172415"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002227065381_p1967952112412"><a name="en-us_topic_0000002227065381_p1967952112412"></a><a name="en-us_topic_0000002227065381_p1967952112412"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002227065381_p967135212413"><a name="en-us_topic_0000002227065381_p967135212413"></a><a name="en-us_topic_0000002227065381_p967135212413"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002227065381_row667452172412"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002227065381_p1767185202414"><a name="en-us_topic_0000002227065381_p1767185202414"></a><a name="en-us_topic_0000002227065381_p1767185202414"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002227065381_p86718523246"><a name="en-us_topic_0000002227065381_p86718523246"></a><a name="en-us_topic_0000002227065381_p86718523246"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002227065381_p26718521243"><a name="en-us_topic_0000002227065381_p26718521243"></a><a name="en-us_topic_0000002227065381_p26718521243"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="row3473517121611"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p526933610458"><a name="p526933610458"></a><a name="p526933610458"></a>ping_args</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12697362450"><a name="p12697362450"></a><a name="p12697362450"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1026953674513"><a name="p1026953674513"></a><a name="p1026953674513"></a>struct dcmi_ub_ping_operate<strong id="b935691192512"><a name="b935691192512"></a><a name="b935691192512"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p194783273514"><a name="p194783273514"></a><a name="p194783273514"></a>Ping request information.</p>
<pre>
#define UB_PING_RESERVE_NUM     4
#define MAX_IP_VAL_LEN     48
struct ubping_pair_info {
    char src_addr[MAX_IP_VAL_LEN]; // Source EID.
    char dst_addr[MAX_IP_VAL_LEN]; // Destination EID.
};
struct dcmi_ub_ping_operate {
struct ubping_pair_info ub_pair_info; // Source EID and destination EID pair.
int pkt_size; // Size of a ping packet, in bytes. The value ranges from 0 to 4046.
int pkt_send_num; // Number of ping packets to be sent. The value ranges from 1 to 1000.
int pkt_interval; // Interval for sending ping packets, in milliseconds. The value ranges from 0 to 10000.
int timeout; // Timeout interval for each ping packet, in milliseconds. The value ranges from 1 to 10000.

unsigned int reserve[UB_PING_RESERVE_NUM]; // Reserved field, which is not used currently.
};

</pre>
</td>
</tr>
<tr id="row171153213405"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p184820315253"><a name="p184820315253"></a><a name="p184820315253"></a>ping_result</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1011682116400"><a name="p1011682116400"></a><a name="p1011682116400"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1911612164019"><a name="p1911612164019"></a><a name="p1911612164019"></a>struct ub_ping_result *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><div class="p" id="p131168217402"><a name="p131168217402"></a><a name="p131168217402"></a>Ping result.<pre class="codeblock" id="codeblock171981662614"><a name="codeblock171981662614"></a><a name="codeblock171981662614"></a>struct ub_ping_result {
unsigned int suc_pkt_num; // Number of successful ping operations.
unsigned int fail_pkt_num; // Number of ping failures.
long max_time; // Maximum delay in receiving reply packets.
long min_time; // Minimum delay in receiving reply packets.
long avg_time; // Average delay in receiving reply packets.
long tp95_time; // 95th percentile delay in receiving reply packets.
unsigned int reserve[UB_PING_RESERVE_NUM]; // Reserved field, which is not used currently.
};</pre>
</div>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="section113625214244"></a>

**Table  1** Support in different deployment scenarios

<a name="table1495412398240"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_row26461043103219"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_p06463434324"><a name="en-us_topic_0000002347924121_p06463434324"></a><a name="en-us_topic_0000002347924121_p06463434324"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p15646043123214"><a name="en-us_topic_0000002347924121_p15646043123214"></a><a name="en-us_topic_0000002347924121_p15646043123214"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p1464614435324"><a name="en-us_topic_0000002347924121_p1464614435324"></a><a name="en-us_topic_0000002347924121_p1464614435324"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p14646174353210"><a name="en-us_topic_0000002347924121_p14646174353210"></a><a name="en-us_topic_0000002347924121_p14646174353210"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p3647104343214"><a name="en-us_topic_0000002347924121_p3647104343214"></a><a name="en-us_topic_0000002347924121_p3647104343214"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_row16472433324"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_p16471543143217"><a name="en-us_topic_0000002347924121_p16471543143217"></a><a name="en-us_topic_0000002347924121_p16471543143217"></a><strong id="en-us_topic_0000002347924121_b1919763744"><a name="en-us_topic_0000002347924121_b1919763744"></a><a name="en-us_topic_0000002347924121_b1919763744"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_p664754323210"><a name="en-us_topic_0000002347924121_p664754323210"></a><a name="en-us_topic_0000002347924121_p664754323210"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b892351261"><a name="en-us_topic_0000002347924121_b892351261"></a><a name="en-us_topic_0000002347924121_b892351261"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p66471543173215"><a name="en-us_topic_0000002347924121_p66471543173215"></a><a name="en-us_topic_0000002347924121_p66471543173215"></a><strong id="en-us_topic_0000002347924121_b125134011"><a name="en-us_topic_0000002347924121_b125134011"></a><a name="en-us_topic_0000002347924121_b125134011"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_p4647943123210"><a name="en-us_topic_0000002347924121_p4647943123210"></a><a name="en-us_topic_0000002347924121_p4647943123210"></a><strong id="en-us_topic_0000002347924121_b922706339"><a name="en-us_topic_0000002347924121_b922706339"></a><a name="en-us_topic_0000002347924121_b922706339"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p176472043163218"><a name="en-us_topic_0000002347924121_p176472043163218"></a><a name="en-us_topic_0000002347924121_p176472043163218"></a><strong id="en-us_topic_0000002347924121_b202429450"><a name="en-us_topic_0000002347924121_b202429450"></a><a name="en-us_topic_0000002347924121_b202429450"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row964714313220"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p664734316322"><a name="en-us_topic_0000002347924121_p664734316322"></a><a name="en-us_topic_0000002347924121_p664734316322"></a><span id="en-us_topic_0000002347924121_ph9647194317328"><a name="en-us_topic_0000002347924121_ph9647194317328"></a><a name="en-us_topic_0000002347924121_ph9647194317328"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13924182025119"><a name="en-us_topic_0000002347924121_p13924182025119"></a><a name="en-us_topic_0000002347924121_p13924182025119"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p109262206516"><a name="en-us_topic_0000002347924121_p109262206516"></a><a name="en-us_topic_0000002347924121_p109262206516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p8926172095110"><a name="en-us_topic_0000002347924121_p8926172095110"></a><a name="en-us_topic_0000002347924121_p8926172095110"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p13954161211518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p1086216713513"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row176481543163219"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p26481431322"><a name="en-us_topic_0000002347924121_p26481431322"></a><a name="en-us_topic_0000002347924121_p26481431322"></a><span id="en-us_topic_0000002347924121_ph9648104363220"><a name="en-us_topic_0000002347924121_ph9648104363220"></a><a name="en-us_topic_0000002347924121_ph9648104363220"></a>Note: <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000002227065381_section6395526248"></a>

```c
...
int ret = 0;
int dev_id = 0;
struct dcmi_ub_ping_operate ping_args = {0};
struct ub_ping_result ping_result = {0};

strcpy(ping_args.ub_pair_info.src_addr, "::40:10:0:dfdf:92");
strcpy(ping_args.ub_pair_info.dst_addr, "::40:10:0:dfdf:8a");
ping_args.pkt_size = 4046;
ping_args.pkt_send_num = 6;
ping_args.pkt_interval = 1000;
ping_args.timeout = 1000;
ret = dcmiv2_exec_ub_ping(dev_id, &ping_args, &ping_result);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

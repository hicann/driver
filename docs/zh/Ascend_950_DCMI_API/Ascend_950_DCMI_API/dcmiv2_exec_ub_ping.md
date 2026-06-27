# dcmiv2\_exec\_ub\_ping<a name="ZH-CN_TOPIC_0000002563055455"></a>

## 函数原型<a name="zh-cn_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_exec\_ub\_ping\(int dev\_id, struct dcmi\_ub\_ping\_operate \*ping\_args, struct ub\_ping\_result \*ping\_result\)**

## 功能说明<a name="zh-cn_topic_0000002227065381_section126852122411"></a>

查询指定设备到目的地址的UB ping结果。

## 参数说明<a name="zh-cn_topic_0000002227065381_section1527155212240"></a>

<a name="zh-cn_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000002227065381_p1467135212241"><a name="zh-cn_topic_0000002227065381_p1467135212241"></a><a name="zh-cn_topic_0000002227065381_p1467135212241"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000002227065381_p1367152172415"><a name="zh-cn_topic_0000002227065381_p1367152172415"></a><a name="zh-cn_topic_0000002227065381_p1367152172415"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000002227065381_p1967952112412"><a name="zh-cn_topic_0000002227065381_p1967952112412"></a><a name="zh-cn_topic_0000002227065381_p1967952112412"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000002227065381_p967135212413"><a name="zh-cn_topic_0000002227065381_p967135212413"></a><a name="zh-cn_topic_0000002227065381_p967135212413"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002227065381_row667452172412"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000002227065381_p1767185202414"><a name="zh-cn_topic_0000002227065381_p1767185202414"></a><a name="zh-cn_topic_0000002227065381_p1767185202414"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000002227065381_p86718523246"><a name="zh-cn_topic_0000002227065381_p86718523246"></a><a name="zh-cn_topic_0000002227065381_p86718523246"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000002227065381_p26718521243"><a name="zh-cn_topic_0000002227065381_p26718521243"></a><a name="zh-cn_topic_0000002227065381_p26718521243"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row3473517121611"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p526933610458"><a name="p526933610458"></a><a name="p526933610458"></a>ping_args</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p12697362450"><a name="p12697362450"></a><a name="p12697362450"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1026953674513"><a name="p1026953674513"></a><a name="p1026953674513"></a>struct dcmi_ub_ping_operate<strong id="b935691192512"><a name="b935691192512"></a><a name="b935691192512"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p194783273514"><a name="p194783273514"></a><a name="p194783273514"></a>ping请求信息。</p>
<pre>
#define UB_PING_RESERVE_NUM     4
#define MAX_IP_VAL_LEN     48
struct ubping_pair_info {
    char src_addr[MAX_IP_VAL_LEN]; //源端EID地址
    char dst_addr[MAX_IP_VAL_LEN]; //目的EID地址
};
struct dcmi_ub_ping_operate {
struct ubping_pair_info ub_pair_info; //源端EID、目的EID对
int pkt_size; //ping的数据包大小，单位为Byte，取值范围为[0, 4046]
int pkt_send_num; //要发送的ping包数量，取值范围为[1, 1000]
int pkt_interval; //两次ping包之间的发送时间间隔，单位为ms，取值范围为为[0, 1000]
int timeout; //ping的每包超时等待时间，单位为ms，取值范围为为[1, 1000]  

unsigned int reserve[UB_PING_RESERVE_NUM]; //预留字段，暂未使用
};

</pre>
</td>
</tr>
<tr id="row171153213405"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p184820315253"><a name="p184820315253"></a><a name="p184820315253"></a>ping_result</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1011682116400"><a name="p1011682116400"></a><a name="p1011682116400"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1911612164019"><a name="p1911612164019"></a><a name="p1911612164019"></a>struct ub_ping_result *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><div class="p" id="p131168217402"><a name="p131168217402"></a><a name="p131168217402"></a>ping返回结果。<pre class="codeblock" id="codeblock171981662614"><a name="codeblock171981662614"></a><a name="codeblock171981662614"></a>struct ub_ping_result {
unsigned int suc_pkt_num; //ping成功次数
unsigned int fail_pkt_num; //ping失败次数
long max_time; //接收回复报文中最大时延
long min_time; //接收回复报文中最小时延
long avg_time; //接收回复报文中平均时延
long tp95_time; //接收回复报文中95分位数时延
unsigned int reserve[UB_PING_RESERVE_NUM]; //预留字段，暂未使用
};</pre>
</div>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="section113625214244"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1495412398240"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row26461043103219"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p06463434324"><a name="zh-cn_topic_0000002347924121_p06463434324"></a><a name="zh-cn_topic_0000002347924121_p06463434324"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p15646043123214"><a name="zh-cn_topic_0000002347924121_p15646043123214"></a><a name="zh-cn_topic_0000002347924121_p15646043123214"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p1464614435324"><a name="zh-cn_topic_0000002347924121_p1464614435324"></a><a name="zh-cn_topic_0000002347924121_p1464614435324"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p14646174353210"><a name="zh-cn_topic_0000002347924121_p14646174353210"></a><a name="zh-cn_topic_0000002347924121_p14646174353210"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p3647104343214"><a name="zh-cn_topic_0000002347924121_p3647104343214"></a><a name="zh-cn_topic_0000002347924121_p3647104343214"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row16472433324"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p16471543143217"><a name="zh-cn_topic_0000002347924121_p16471543143217"></a><a name="zh-cn_topic_0000002347924121_p16471543143217"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p664754323210"><a name="zh-cn_topic_0000002347924121_p664754323210"></a><a name="zh-cn_topic_0000002347924121_p664754323210"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p66471543173215"><a name="zh-cn_topic_0000002347924121_p66471543173215"></a><a name="zh-cn_topic_0000002347924121_p66471543173215"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p4647943123210"><a name="zh-cn_topic_0000002347924121_p4647943123210"></a><a name="zh-cn_topic_0000002347924121_p4647943123210"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p176472043163218"><a name="zh-cn_topic_0000002347924121_p176472043163218"></a><a name="zh-cn_topic_0000002347924121_p176472043163218"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row964714313220"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p664734316322"><a name="zh-cn_topic_0000002347924121_p664734316322"></a><a name="zh-cn_topic_0000002347924121_p664734316322"></a><span id="zh-cn_topic_0000002347924121_ph9647194317328"><a name="zh-cn_topic_0000002347924121_ph9647194317328"></a><a name="zh-cn_topic_0000002347924121_ph9647194317328"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13924182025119"><a name="zh-cn_topic_0000002347924121_p13924182025119"></a><a name="zh-cn_topic_0000002347924121_p13924182025119"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p109262206516"><a name="zh-cn_topic_0000002347924121_p109262206516"></a><a name="zh-cn_topic_0000002347924121_p109262206516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p8926172095110"><a name="zh-cn_topic_0000002347924121_p8926172095110"></a><a name="zh-cn_topic_0000002347924121_p8926172095110"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p13954161211518"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p13954161211518"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p13954161211518"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1086216713513"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1086216713513"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1086216713513"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row176481543163219"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p26481431322"><a name="zh-cn_topic_0000002347924121_p26481431322"></a><a name="zh-cn_topic_0000002347924121_p26481431322"></a><span id="zh-cn_topic_0000002347924121_ph9648104363220"><a name="zh-cn_topic_0000002347924121_ph9648104363220"></a><a name="zh-cn_topic_0000002347924121_ph9648104363220"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000002227065381_section6395526248"></a>

```c
…
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
    //todo：记录日志
    return ret;
}
…
```

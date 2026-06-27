# dcmiv2\_exec\_netdev\_traceroute<a name="ZH-CN_TOPIC_0000002314204998"></a>

## 函数原型<a name="section1994468155813"></a>

**int dcmiv2\_exec\_netdev\_traceroute\(int dev\_id, const char \*netdev\_name, unsigned int netdev\_name\_len, struct dcmi\_traceroute\_params traceroute\_info, struct dcmi\_traceroute\_result \*result\)**

## 功能说明<a name="section10946138105811"></a>

配置traceroute参数探测报文途经的网络节点信息。

## 参数说明<a name="section1294798155811"></a>

<a name="table1499319814585"></a>
<table><thead align="left"><tr id="row119149115814"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p191169145811"><a name="p191169145811"></a><a name="p191169145811"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.129999999999999%" id="mcps1.1.5.1.2"><p id="p199115925812"><a name="p199115925812"></a><a name="p199115925812"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.19%" id="mcps1.1.5.1.3"><p id="p13911190581"><a name="p13911190581"></a><a name="p13911190581"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p1091129155817"><a name="p1091129155817"></a><a name="p1091129155817"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row4912099583"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p109169205814"><a name="p109169205814"></a><a name="p109169205814"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.129999999999999%" headers="mcps1.1.5.1.2 "><p id="p29139115814"><a name="p29139115814"></a><a name="p29139115814"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.5.1.3 "><p id="p1691993587"><a name="p1691993587"></a><a name="p1691993587"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row16334105814379"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p208471053256"><a name="p208471053256"></a><a name="p208471053256"></a>netdev_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.129999999999999%" headers="mcps1.1.5.1.2 "><p id="p07983018267"><a name="p07983018267"></a><a name="p07983018267"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.5.1.3 "><p id="p178471954250"><a name="p178471954250"></a><a name="p178471954250"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1194494412540"><a name="p1194494412540"></a><a name="p1194494412540"></a>UBoE端口的bond设备名，通过<a href="dcmiv2_get_device_netdev_list_info.md">dcmiv2_get_device_netdev_list_info</a>接口获取。</p>
</td>
</tr>
<tr id="row1466275653715"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p203271442254"><a name="p203271442254"></a><a name="p203271442254"></a>netdev_name_len</p>
</td>
<td class="cellrowborder" valign="top" width="15.129999999999999%" headers="mcps1.1.5.1.2 "><p id="p28019082615"><a name="p28019082615"></a><a name="p28019082615"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.5.1.3 "><p id="p113272410259"><a name="p113272410259"></a><a name="p113272410259"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p5863185219555"><a name="p5863185219555"></a><a name="p5863185219555"></a>UBoE端口bond设备名的长度。</p>
</td>
</tr>
<tr id="row1895175493712"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p158951354153718"><a name="p158951354153718"></a><a name="p158951354153718"></a>traceroute_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.129999999999999%" headers="mcps1.1.5.1.2 "><p id="p18951754173712"><a name="p18951754173712"></a><a name="p18951754173712"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.5.1.3 "><p id="p1289518549371"><a name="p1289518549371"></a><a name="p1289518549371"></a>struct dcmi_traceroute_params</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p2992133194212"><a name="p2992133194212"></a><a name="p2992133194212"></a>traceroute接口的入参。</p>
<p id="p499213364219"><a name="p499213364219"></a><a name="p499213364219"></a>struct dcmi_traceroute_params {</p>
<p id="p9992203354211"><a name="p9992203354211"></a><a name="p9992203354211"></a>int max_ttl; //探测报文的最大跳数。取值范围为[1, 255]，默认值为30。</p>
<p id="p8992733134213"><a name="p8992733134213"></a><a name="p8992733134213"></a>int tos; //IPv4设置TOS优先级。取值范围为[0, 63]，默认值为0，数值越大优先级越高。</p>
<p id="p19923336422"><a name="p19923336422"></a><a name="p19923336422"></a>int waittime; //设置等待探测响应的时间。单位为秒，取值范围为[1, 60]，默认值为3。</p>
<p id="p1199223384210"><a name="p1199223384210"></a><a name="p1199223384210"></a>int src_port; //设置源端口号。取值范围为[0, 65535]，默认值为大于30000的随机值。设置为0时，系统会使用大于30000的随机值。</p>
<p id="p14992113320421"><a name="p14992113320421"></a><a name="p14992113320421"></a>int dst_port; //设置目的端口号。取值范围为[0, 65535]，默认值为大于30000的随机值。设置为0时，系统会使用大于30000的随机值。</p>
<p id="p2992123320424"><a name="p2992123320424"></a><a name="p2992123320424"></a>char src_ip[48]; //源主机IP</p>
<p id="p1871524312"><a name="p1871524312"></a><a name="p1871524312"></a>char dst_ip[48]; //目标主机IP</p>
<p id="p99921233164219"><a name="p99921233164219"></a><a name="p99921233164219"></a>bool reset_flag; //终止device侧traceroute所有后台进程，当traceroute测试异常时配置为1结束device侧进程。</p>
<p id="p8370137114310"><a name="p8370137114310"></a><a name="p8370137114310"></a>char reserved[7]; //预留参数，暂未使用</p>
<p id="p119928339429"><a name="p119928339429"></a><a name="p119928339429"></a>};</p>
</td>
</tr>
<tr id="row070653153719"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1870153143717"><a name="p1870153143717"></a><a name="p1870153143717"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="15.129999999999999%" headers="mcps1.1.5.1.2 "><p id="p570115303711"><a name="p570115303711"></a><a name="p570115303711"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.19%" headers="mcps1.1.5.1.3 "><p id="p37095316370"><a name="p37095316370"></a><a name="p37095316370"></a>struct dcmi_traceroute_result *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p068131115446"><a name="p068131115446"></a><a name="p068131115446"></a>traceroute接口的返回信息。</p>
<p id="p1968191184414"><a name="p1968191184414"></a><a name="p1968191184414"></a>struct dcmi_traceroute_result {</p>
<p id="p17681131194413"><a name="p17681131194413"></a><a name="p17681131194413"></a>int func_mask; //掩码，表示后面的数据是否有效，例如：0xFF代表mask后的8个字段是有效的</p>
<p id="p1681131114410"><a name="p1681131114410"></a><a name="p1681131114410"></a>char src_ip[48]; //源主机IP</p>
<p id="p36631742144417"><a name="p36631742144417"></a><a name="p36631742144417"></a>char dst_ip[48]; //目标主机IP</p>
<p id="p36811711104420"><a name="p36811711104420"></a><a name="p36811711104420"></a>int snt; //发送ICMP请求报文的数量</p>
<p id="p36811211134413"><a name="p36811211134413"></a><a name="p36811211134413"></a>double loss; //对应节点的丢包率</p>
<p id="p9681201124418"><a name="p9681201124418"></a><a name="p9681201124418"></a>double last; //最新报文的响应时间，单位ms</p>
<p id="p1268191114417"><a name="p1268191114417"></a><a name="p1268191114417"></a>double avg; //所有报文的平均响应时间，单位ms</p>
<p id="p96811311164410"><a name="p96811311164410"></a><a name="p96811311164410"></a>double best; //报文最快响应时间，单位ms</p>
<p id="p16681171112445"><a name="p16681171112445"></a><a name="p16681171112445"></a>double wrst; //报文最慢响应时间，单位ms</p>
<p id="p1168113113442"><a name="p1168113113442"></a><a name="p1168113113442"></a>double stdev; //标准偏差值，越大说明相应节点越不稳定</p>
<p id="p768181118448"><a name="p768181118448"></a><a name="p768181118448"></a>char reserve[64]; //预留参数，暂未使用</p>
<p id="p4681811134414"><a name="p4681811134414"></a><a name="p4681811134414"></a>};</p>
<div class="note" id="note86041401469"><a name="note86041401469"></a><a name="note86041401469"></a><span class="notetitle"> 说明： </span><div class="notebody"><p id="p96043064615"><a name="p96043064615"></a><a name="p96043064615"></a>返回信息的使用结构体数组存储，每个节点信息使用一个结构体。</p>
</div></div>
</td>
</tr>
</tbody>
</table>

## 返回值说明<a name="zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_section1256282115569"></a>

<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p16312252"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p46224020"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_p79561110476"></a>处理结果：</p>
<a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><a name="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"></a><ul id="zh-cn_topic_0000002348043941_zh-cn_topic_0000001251227149_zh-cn_topic_0000001178213202_zh-cn_topic_0000001097675636_zh-cn_topic_0000001170223803_zh-cn_topic_0160151812_ul55711364478"><li>成功：返回0。</li><li>失败：返回码请参见<a href="return_codes.md">return_codes</a>。</li></ul>
</td>
</tr>
</tbody>
</table>

## 约束说明<a name="section1298518810584"></a>

- 为防止由于ICMP报文被丢弃出现traceroute指令卡死的情况，建议IPv4的两条指令间隔3秒执行。
- 若强制中断Host侧指令或执行指令时返回值显示为-8020，则需配置traceroute\_info.reset\_flag=1，调用[dcmiv2\_exec\_netdev\_traceroute](dcmiv2_exec_netdev_traceroute.md)接口结束device侧进程。
- traceroute指令结束后，建议配置traceroute\_info.reset\_flag=1，调用[dcmiv2\_exec\_netdev\_traceroute](dcmiv2_exec_netdev_traceroute.md)接口结束device侧进程，防止进程持续运行影响NPU性能。
- 若traceroute\_info.reset\_flag=1，则其他参数不生效。

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row20501184671216"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p15501144620125"><a name="zh-cn_topic_0000002347924121_p15501144620125"></a><a name="zh-cn_topic_0000002347924121_p15501144620125"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p105011046141220"><a name="zh-cn_topic_0000002347924121_p105011046141220"></a><a name="zh-cn_topic_0000002347924121_p105011046141220"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p1350113461123"><a name="zh-cn_topic_0000002347924121_p1350113461123"></a><a name="zh-cn_topic_0000002347924121_p1350113461123"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p850184611216"><a name="zh-cn_topic_0000002347924121_p850184611216"></a><a name="zh-cn_topic_0000002347924121_p850184611216"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p1850116468126"><a name="zh-cn_topic_0000002347924121_p1850116468126"></a><a name="zh-cn_topic_0000002347924121_p1850116468126"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1950184610124"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p250194613125"><a name="zh-cn_topic_0000002347924121_p250194613125"></a><a name="zh-cn_topic_0000002347924121_p250194613125"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p13501346181216"><a name="zh-cn_topic_0000002347924121_p13501346181216"></a><a name="zh-cn_topic_0000002347924121_p13501346181216"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p35017465127"><a name="zh-cn_topic_0000002347924121_p35017465127"></a><a name="zh-cn_topic_0000002347924121_p35017465127"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p18501204661212"><a name="zh-cn_topic_0000002347924121_p18501204661212"></a><a name="zh-cn_topic_0000002347924121_p18501204661212"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p45011146181214"><a name="zh-cn_topic_0000002347924121_p45011146181214"></a><a name="zh-cn_topic_0000002347924121_p45011146181214"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row9501114651213"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p55011046111218"><a name="zh-cn_topic_0000002347924121_p55011046111218"></a><a name="zh-cn_topic_0000002347924121_p55011046111218"></a><span id="zh-cn_topic_0000002347924121_ph18501646111210"><a name="zh-cn_topic_0000002347924121_ph18501646111210"></a><a name="zh-cn_topic_0000002347924121_ph18501646111210"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p95014467120"><a name="zh-cn_topic_0000002347924121_p95014467120"></a><a name="zh-cn_topic_0000002347924121_p95014467120"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p5501346121220"><a name="zh-cn_topic_0000002347924121_p5501346121220"></a><a name="zh-cn_topic_0000002347924121_p5501346121220"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p13501124611120"><a name="zh-cn_topic_0000002347924121_p13501124611120"></a><a name="zh-cn_topic_0000002347924121_p13501124611120"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1850119467124"><a name="zh-cn_topic_0000002347924121_p1850119467124"></a><a name="zh-cn_topic_0000002347924121_p1850119467124"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p350114610127"><a name="zh-cn_topic_0000002347924121_p350114610127"></a><a name="zh-cn_topic_0000002347924121_p350114610127"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1650318464128"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p550315469126"><a name="zh-cn_topic_0000002347924121_p550315469126"></a><a name="zh-cn_topic_0000002347924121_p550315469126"></a><span id="zh-cn_topic_0000002347924121_ph150344631219"><a name="zh-cn_topic_0000002347924121_ph150344631219"></a><a name="zh-cn_topic_0000002347924121_ph150344631219"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="section1598913835819"></a>

```c
…
int ret = 0;
int dev_id = 0;
const char *netdev_name = "bond0";
unsigned int netdev_name_len = 5;
struct dcmi_traceroute_info traceroute_info = {0};
struct dcmi_network_node_info result = {0};
traceroute_info .source_port = 40000;
traceroute_info.max_ttl = 30;
traceroute_info.tos = 0;
traceroute_info.waittime = 3;
traceroute_info.src_port = 65535;
traceroute_info.dst_port = 30001;
(void)sprintf(param_in.dst_ip, "%s", "***.***.**.**");
(void)sprintf(param_in.src_ip, "%s", "***.***.**.**");
result.result_nums = 1;
result.result_data = (struct traceroute_result *)malloc(sizeof(struct traceroute_result));

ret = dcmiv2_exec_netdev_traceroute(dev_id, netdev_name, netdev_name_len, traceroute_info, &result);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

>**说明：** 
>_x.x.x.x_表示目的IP地址。

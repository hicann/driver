# dcmiv2\_get\_pfc\_duration\_info<a name="ZH-CN_TOPIC_0000002314204974"></a>

## 函数原型<a name="section1873810317462"></a>

**int dcmiv2\_get\_pfc\_duration\_info\(int dev\_id, const char \*netdev\_name, unsigned int netdev\_name\_len, struct dcmi\_netdev\_pfc\_duration\_info \*pfc\_duration\_info\)**

## 功能说明<a name="section474073164613"></a>

获取指定设备的PFC（Priority Flow Control，优先级流控）反压帧持续时间统计值。

## 参数说明<a name="section167411314464"></a>

<a name="table87791434466"></a>
<table><thead align="left"><tr id="row285620314611"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p118569324610"><a name="p118569324610"></a><a name="p118569324610"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p6856113174610"><a name="p6856113174610"></a><a name="p6856113174610"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p38568320467"><a name="p38568320467"></a><a name="p38568320467"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p1885620311466"><a name="p1885620311466"></a><a name="p1885620311466"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row485615313467"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p198565334613"><a name="p198565334613"></a><a name="p198565334613"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p16856183104614"><a name="p16856183104614"></a><a name="p16856183104614"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p138563311469"><a name="p138563311469"></a><a name="p138563311469"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1598932319464"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1729101525418"><a name="p1729101525418"></a><a name="p1729101525418"></a>netdev_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1429915185417"><a name="p1429915185417"></a><a name="p1429915185417"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p162991555411"><a name="p162991555411"></a><a name="p162991555411"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1194494412540"><a name="p1194494412540"></a><a name="p1194494412540"></a>UBoE端口的bond设备名，通过<a href="dcmiv2_get_device_netdev_list_info.md">dcmiv2_get_device_netdev_list_info</a>接口获取。</p>
</td>
</tr>
<tr id="row1279751484610"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p168631252165514"><a name="p168631252165514"></a><a name="p168631252165514"></a>netdev_name_len</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p168634526551"><a name="p168634526551"></a><a name="p168634526551"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p78631752175513"><a name="p78631752175513"></a><a name="p78631752175513"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p5863185219555"><a name="p5863185219555"></a><a name="p5863185219555"></a>UBoE端口bond设备名的长度。</p>
</td>
</tr>
<tr id="row3109132217468"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p12109142217462"><a name="p12109142217462"></a><a name="p12109142217462"></a>pfc_duration_info</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p71091022124611"><a name="p71091022124611"></a><a name="p71091022124611"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p17109142214464"><a name="p17109142214464"></a><a name="p17109142214464"></a>struct dcmi_netdev_pfc_duration_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><div class="p" id="p61097222468"><a name="p61097222468"></a><a name="p61097222468"></a>PFC pause duration值。<pre class="codeblock" id="codeblock5982234184713"><a name="codeblock5982234184713"></a><a name="codeblock5982234184713"></a>#define NETDEV_MAX_NUM      8
#define NETDEV_NAME_MAX_LEN 16
struct dcmi_bond_pfc_duration_info {
    unsigned char slave0_name[NETDEV_NAME_MAX_LEN]; //slave0网络设备名称
    unsigned long long slave0_tx[PRIORITY_NUM]; //slave0网络设备名称的tx方向的PFC反压时长
    unsigned long long slave0_rx[PRIORITY_NUM]; //slave0网络设备名称的rx方向的PFC反压时长
    unsigned char slave1_name[NETDEV_NAME_MAX_LEN]; //slave1网络设备名称
    unsigned long long slave1_tx[PRIORITY_NUM]; //slave1网络设备名称的tx方向的PFC反压时长
    unsigned long long slave1_rx[PRIORITY_NUM]; //slave1网络设备名称的rx方向的PFC反压时长
};
struct dcmi_netdev_pfc_duration_info {
    union {
        struct dcmi_bond_pfc_duration_info duration_info;
        unsigned long long reserved[36]; //预留参数，暂未使用
    };
};</pre>
</div>
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

## 约束说明<a name="section14766153174617"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row295462085819"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p59546200584"><a name="zh-cn_topic_0000002347924121_p59546200584"></a><a name="zh-cn_topic_0000002347924121_p59546200584"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p69541220175811"><a name="zh-cn_topic_0000002347924121_p69541220175811"></a><a name="zh-cn_topic_0000002347924121_p69541220175811"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p1954720165817"><a name="zh-cn_topic_0000002347924121_p1954720165817"></a><a name="zh-cn_topic_0000002347924121_p1954720165817"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p595432065811"><a name="zh-cn_topic_0000002347924121_p595432065811"></a><a name="zh-cn_topic_0000002347924121_p595432065811"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p295462019586"><a name="zh-cn_topic_0000002347924121_p295462019586"></a><a name="zh-cn_topic_0000002347924121_p295462019586"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1995492015813"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p1954162018588"><a name="zh-cn_topic_0000002347924121_p1954162018588"></a><a name="zh-cn_topic_0000002347924121_p1954162018588"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p1995452025814"><a name="zh-cn_topic_0000002347924121_p1995452025814"></a><a name="zh-cn_topic_0000002347924121_p1995452025814"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p6954620185813"><a name="zh-cn_topic_0000002347924121_p6954620185813"></a><a name="zh-cn_topic_0000002347924121_p6954620185813"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p1695482055820"><a name="zh-cn_topic_0000002347924121_p1695482055820"></a><a name="zh-cn_topic_0000002347924121_p1695482055820"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p1395414204584"><a name="zh-cn_topic_0000002347924121_p1395414204584"></a><a name="zh-cn_topic_0000002347924121_p1395414204584"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row149541020115816"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p3954122045810"><a name="zh-cn_topic_0000002347924121_p3954122045810"></a><a name="zh-cn_topic_0000002347924121_p3954122045810"></a><span id="zh-cn_topic_0000002347924121_ph295472018582"><a name="zh-cn_topic_0000002347924121_ph295472018582"></a><a name="zh-cn_topic_0000002347924121_ph295472018582"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p277623313589"><a name="zh-cn_topic_0000002347924121_p277623313589"></a><a name="zh-cn_topic_0000002347924121_p277623313589"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p17805113310586"><a name="zh-cn_topic_0000002347924121_p17805113310586"></a><a name="zh-cn_topic_0000002347924121_p17805113310586"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p1483573355819"><a name="zh-cn_topic_0000002347924121_p1483573355819"></a><a name="zh-cn_topic_0000002347924121_p1483573355819"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p118571033105810"><a name="zh-cn_topic_0000002347924121_p118571033105810"></a><a name="zh-cn_topic_0000002347924121_p118571033105810"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p4878833115815"><a name="zh-cn_topic_0000002347924121_p4878833115815"></a><a name="zh-cn_topic_0000002347924121_p4878833115815"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row0965820165812"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p9965320205818"><a name="zh-cn_topic_0000002347924121_p9965320205818"></a><a name="zh-cn_topic_0000002347924121_p9965320205818"></a><span id="zh-cn_topic_0000002347924121_ph49651020145810"><a name="zh-cn_topic_0000002347924121_ph49651020145810"></a><a name="zh-cn_topic_0000002347924121_ph49651020145810"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="section12776336460"></a>

```c
…
int ret = 0;
int dev_id = 0;
const char *netdev_name = "bond0";
unsigned int netdev_name_len = 5;
struct dcmi_netdev_pfc_duration_info *pfc_duration_info = {0};
ret = dcmiv2_get_pfc_duration_info(dev_id, netdev_name, netdev_name_len, pfc_duration_info);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

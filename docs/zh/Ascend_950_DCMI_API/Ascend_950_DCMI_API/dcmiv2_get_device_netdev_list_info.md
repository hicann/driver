# dcmiv2\_get\_device\_netdev\_list\_info<a name="ZH-CN_TOPIC_0000002571616048"></a>

## 函数原型<a name="zh-cn_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_get\_device\_netdev\_list\_info\(int dev\_id, struct dcmi\_netdev\_list\_info \*netdev\_list\)**

## 功能说明<a name="zh-cn_topic_0000002227065381_section126852122411"></a>

查询UBoE端口的bond设备名和数量。

## 参数说明<a name="zh-cn_topic_0000002227065381_section1527155212240"></a>

<a name="zh-cn_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000002227065381_p1467135212241"><a name="zh-cn_topic_0000002227065381_p1467135212241"></a><a name="zh-cn_topic_0000002227065381_p1467135212241"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.14%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000002227065381_p1367152172415"><a name="zh-cn_topic_0000002227065381_p1367152172415"></a><a name="zh-cn_topic_0000002227065381_p1367152172415"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.18%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000002227065381_p1967952112412"><a name="zh-cn_topic_0000002227065381_p1967952112412"></a><a name="zh-cn_topic_0000002227065381_p1967952112412"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000002227065381_p967135212413"><a name="zh-cn_topic_0000002227065381_p967135212413"></a><a name="zh-cn_topic_0000002227065381_p967135212413"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row15169217173917"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002227065381_row146720522240"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p98861141342"><a name="p98861141342"></a><a name="p98861141342"></a>netdev_list</p>
</td>
<td class="cellrowborder" valign="top" width="15.14%" headers="mcps1.1.5.1.2 "><p id="p1388515141443"><a name="p1388515141443"></a><a name="p1388515141443"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.18%" headers="mcps1.1.5.1.3 "><p id="p7885814944"><a name="p7885814944"></a><a name="p7885814944"></a>struct dcmi_netdev_list_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1188521418418"><a name="p1188521418418"></a><a name="p1188521418418"></a>查询UBoE端口的bond设备名和数量。</p>
<pre class="codeblock" id="codeblock9188113415318"><a name="codeblock9188113415318"></a><a name="codeblock9188113415318"></a>#define NETDEV_MAX_NUM 8
#define NETDEV_NAME_MAX_LEN 16
struct dcmi_netdev_list_info {
int netdev_nums; //有效netdev数量
char netdev_name[NETDEV_MAX_NUM ][NETDEV_NAME_MAX_LEN];//UBoE端口bond设备名
};</pre>
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

## 约束说明<a name="section113625214244"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_row26461043103219"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p06463434324"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p06463434324"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p06463434324"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p15646043123214"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p15646043123214"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p15646043123214"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p1464614435324"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p1464614435324"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p1464614435324"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p14646174353210"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p14646174353210"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p14646174353210"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p3647104343214"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p3647104343214"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p3647104343214"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p8677551165718"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p8677551165718"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p8677551165718"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_row16472433324"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p16471543143217"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p16471543143217"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p16471543143217"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p664754323210"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p664754323210"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p664754323210"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p66471543173215"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p66471543173215"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p66471543173215"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p4647943123210"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p4647943123210"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p4647943123210"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p176472043163218"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p176472043163218"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p176472043163218"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p867710519578"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p867710519578"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p867710519578"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_row964714313220"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002571775678_p144147361596"><a name="zh-cn_topic_0000002571775678_p144147361596"></a><a name="zh-cn_topic_0000002571775678_p144147361596"></a><span id="zh-cn_topic_0000002571775678_ph12140626193614"><a name="zh-cn_topic_0000002571775678_ph12140626193614"></a><a name="zh-cn_topic_0000002571775678_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002571775678_p48379131362"><a name="zh-cn_topic_0000002571775678_p48379131362"></a><a name="zh-cn_topic_0000002571775678_p48379131362"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002571775678_p7837213465"><a name="zh-cn_topic_0000002571775678_p7837213465"></a><a name="zh-cn_topic_0000002571775678_p7837213465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002571775678_p883731314614"><a name="zh-cn_topic_0000002571775678_p883731314614"></a><a name="zh-cn_topic_0000002571775678_p883731314614"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002571775678_p383718136612"><a name="zh-cn_topic_0000002571775678_p383718136612"></a><a name="zh-cn_topic_0000002571775678_p383718136612"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002571775678_p1183714137613"><a name="zh-cn_topic_0000002571775678_p1183714137613"></a><a name="zh-cn_topic_0000002571775678_p1183714137613"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002571775678_p48371513662"><a name="zh-cn_topic_0000002571775678_p48371513662"></a><a name="zh-cn_topic_0000002571775678_p48371513662"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_row176481543163219"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p26481431322"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p26481431322"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_p26481431322"></a><span id="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_ph9648104363220"><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_ph9648104363220"></a><a name="zh-cn_topic_0000002571775678_zh-cn_topic_0000002347924121_ph9648104363220"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000002227065381_section6395526248"></a>

```c
…  
int ret;
int dev_id = 0;
struct dcmi_netdev_list_info netdev_list = {0};
ret = dcmiv2_get_device_netdev_list_info(dev_id, &netdev_list);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

# dcmiv2\_get\_device\_netdev\_health<a name="ZH-CN_TOPIC_0000002314204858"></a>

## 函数原型<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_toc533412077"></a>

**int dcmiv2\_get\_device\_netdev\_health\(int dev\_id, const char \*netdev\_name, unsigned int netdev\_name\_len, enum dcmi\_rdfx\_detect\_result \*result\)**

## 功能说明<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_toc533412078"></a>

查询UBoE端口的IP地址的连通状态。

## 参数说明<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_toc533412079"></a>

<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p10021890"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p10021890"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p6466753"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p6466753"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p54045009"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p54045009"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p15569626"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p15569626"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1997714508912"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1729101525418"><a name="p1729101525418"></a><a name="p1729101525418"></a>netdev_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="p1429915185417"><a name="p1429915185417"></a><a name="p1429915185417"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p162991555411"><a name="p162991555411"></a><a name="p162991555411"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1194494412540"><a name="p1194494412540"></a><a name="p1194494412540"></a>UBoE端口的bond设备名，通过<a href="dcmiv2_get_device_netdev_list_info.md">dcmiv2_get_device_netdev_list_info</a>接口获取。</p>
</td>
</tr>
<tr id="row85464331891"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p168631252165514"><a name="p168631252165514"></a><a name="p168631252165514"></a>netdev_name_len</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="p168634526551"><a name="p168634526551"></a><a name="p168634526551"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="p78631752175513"><a name="p78631752175513"></a><a name="p78631752175513"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p5863185219555"><a name="p5863185219555"></a><a name="p5863185219555"></a>UBoE端口bond设备名的长度。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p5522164215178"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p5522164215178"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p5522164215178"></a>result</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p8522242101715"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p8522242101715"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p8522242101715"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p17522114220174"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p17522114220174"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p17522114220174"></a>enum dcmi_rdfx_detect_result *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1723415192311"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1723415192311"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1723415192311"></a>查询UBoE端口的IP地址的连通状态，内容定义为：</p>
<pre class="codeblock" id="codeblock1112491976"><a name="codeblock1112491976"></a><a name="codeblock1112491976"></a>enum dcmi_rdfx_detect_result {
DCMI_RDFX_DETECT_OK = 0, //网络健康状态正常
DCMI_RDFX_DETECT_SOCK_FAIL = 1, //网络套接字创建失败
DCMI_RDFX_DETECT_RECV_TIMEOUT = 2, //网口收包超时
DCMI_RDFX_DETECT_UNREACH = 3, //侦测IP地址不可达
DCMI_RDFX_DETECT_TIME_EXCEEDED = 4, //发送侦测报文执行超时
DCMI_RDFX_DETECT_FAULT = 5, //发送侦测报文失败
DCMI_RDFX_DETECT_INIT = 6, //侦测任务初始化中
DCMI_RDFX_DETECT_THREAD_ERR = 7, //侦测任务创建失败
DCMI_RDFX_DETECT_IP_SET = 8, //正在设置侦测IP地址
DCMI_RDFX_DETECT_MAX = 0xFF //枚举值上限标记
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

## 约束说明<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_toc533412082"></a>

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

在调用**dcmiv2\_get\_device\_netdev\_health**接口前，需在Host侧以root用户执行如下命令设置IP地址：

- 设置UBoE端口的IP地址和子网掩码

    ```c
    hccn_tool -s -ip -i <dev_id> -d <bond_ndev_name> -address <ip> -netmask <netmask>
    ```

    您需要根据实际情况，修改如下内容：

    - _dev\_id_  ：设置为软件的逻辑ID。
    - _<bond\_ndev\_name\>_：设置为UBoE端口的Bond设备名。
    - _<ip\>_：设置为IP地址。
    - <netmask\>：设置为子网掩码。

- 设置UBoE端口网络检测对象

    ```c
    hccn_tool -s -netdetect -i <dev_id> -address <netdetect_address>
    ```

    您需要根据实际情况，修改如下内容：

    - _<dev\_id\>_：设置为软件的逻辑ID。
    - _<netdetect\_address\>_：设置网络检测对象IP地址。仅支持IPv4（如‘x.x.x.x’格式）。

## 调用示例<a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
const char *netdev_name = "bond0";
unsigned int netdev_name_len = 5;
enum dcmi_rdfx_detect_result health = DCMI_RDFX_DETECT_MAX;
ret = dcmiv2_get_device_netdev_health(dev_id, netdev_name, netdev_name_len, &health);
if (ret != 0){
    //todo:记录日志
    return ret;
}
…
```

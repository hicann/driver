# dcmiv2\_get\_pcie\_link\_bandwidth\_info<a name="ZH-CN_TOPIC_0000002314204926"></a>

## 函数原型<a name="section196251231145019"></a>

**int dcmiv2\_get\_pcie\_link\_bandwidth\_info \(int dev\_id, struct dcmi\_pcie\_link\_bandwidth\_info \*pcie\_link\_bandwidth\_info\)**

## 功能说明<a name="section116271631195017"></a>

查询指定采样时间内，NPU设备与host OS间PCIe带宽信息。

## 参数说明<a name="section11627103114506"></a>

<a name="table196551731155016"></a>
<table><thead align="left"><tr id="row6708031165017"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p17708123120507"><a name="p17708123120507"></a><a name="p17708123120507"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p13708143185017"><a name="p13708143185017"></a><a name="p13708143185017"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p67081031185017"><a name="p67081031185017"></a><a name="p67081031185017"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p3708131145014"><a name="p3708131145014"></a><a name="p3708131145014"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1170873116504"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p11708131185016"><a name="p11708131185016"></a><a name="p11708131185016"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p1070811311504"><a name="p1070811311504"></a><a name="p1070811311504"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p970973119509"><a name="p970973119509"></a><a name="p970973119509"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1170919312507"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p2709331125015"><a name="p2709331125015"></a><a name="p2709331125015"></a>pcie_link_bandwidth_info</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p5709153165015"><a name="p5709153165015"></a><a name="p5709153165015"></a>输入/输出</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p270923119508"><a name="p270923119508"></a><a name="p270923119508"></a>struct dcmi_pcie_link_bandwidth_info<strong id="b119504553355"><a name="b119504553355"></a><a name="b119504553355"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p147094314502"><a name="p147094314502"></a><a name="p147094314502"></a>struct dcmi_pcie_link_bandwidth_info {</p>
<p id="p15709103111504"><a name="p15709103111504"></a><a name="p15709103111504"></a>int profiling_time; //输入，控制采样时长</p>
<p id="p8709731105013"><a name="p8709731105013"></a><a name="p8709731105013"></a>unsigned int tx_p_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备向远端写带宽</p>
<p id="p5709431135014"><a name="p5709431135014"></a><a name="p5709431135014"></a>unsigned int tx_np_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备从远端读带宽</p>
<p id="p770913120509"><a name="p770913120509"></a><a name="p770913120509"></a>unsigned int tx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备回复远端读操作CPL的带宽</p>
<p id="p67096319500"><a name="p67096319500"></a><a name="p67096319500"></a>unsigned int tx_np_lantency[AGENTDRV_PROF_DATA_NUM];</p>
<p id="p18709631165013"><a name="p18709631165013"></a><a name="p18709631165013"></a>//输出，device设备从远端读的延时（ns）</p>
<p id="p19709173185010"><a name="p19709173185010"></a><a name="p19709173185010"></a>unsigned int rx_p_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备接收远端写的带宽</p>
<p id="p15709631135012"><a name="p15709631135012"></a><a name="p15709631135012"></a>unsigned int rx_np_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备接收远端读的带宽</p>
<p id="p27091312507"><a name="p27091312507"></a><a name="p27091312507"></a>unsigned int rx_cpl_bw[AGENTDRV_PROF_DATA_NUM]; //输出，device设备从远端读收到CPL回复的带宽</p>
<p id="p5709173115012"><a name="p5709173115012"></a><a name="p5709173115012"></a>};</p>
<p id="p157098315509"><a name="p157098315509"></a><a name="p157098315509"></a>profiling_time取值范围：0ms~2000ms。</p>
<p id="p207091631185018"><a name="p207091631185018"></a><a name="p207091631185018"></a>带宽单位均为MB/ms。</p>
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

## 约束说明<a name="section364683165017"></a>

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row631912811716"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p431978101711"><a name="zh-cn_topic_0000002347924121_p431978101711"></a><a name="zh-cn_topic_0000002347924121_p431978101711"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p1431910881719"><a name="zh-cn_topic_0000002347924121_p1431910881719"></a><a name="zh-cn_topic_0000002347924121_p1431910881719"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p331916881710"><a name="zh-cn_topic_0000002347924121_p331916881710"></a><a name="zh-cn_topic_0000002347924121_p331916881710"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p931919891717"><a name="zh-cn_topic_0000002347924121_p931919891717"></a><a name="zh-cn_topic_0000002347924121_p931919891717"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p163196819175"><a name="zh-cn_topic_0000002347924121_p163196819175"></a><a name="zh-cn_topic_0000002347924121_p163196819175"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row1731912871716"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p431915810175"><a name="zh-cn_topic_0000002347924121_p431915810175"></a><a name="zh-cn_topic_0000002347924121_p431915810175"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p1031918121716"><a name="zh-cn_topic_0000002347924121_p1031918121716"></a><a name="zh-cn_topic_0000002347924121_p1031918121716"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p031968181720"><a name="zh-cn_topic_0000002347924121_p031968181720"></a><a name="zh-cn_topic_0000002347924121_p031968181720"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p43193831711"><a name="zh-cn_topic_0000002347924121_p43193831711"></a><a name="zh-cn_topic_0000002347924121_p43193831711"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p331919819177"><a name="zh-cn_topic_0000002347924121_p331919819177"></a><a name="zh-cn_topic_0000002347924121_p331919819177"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row1431948101718"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p2319138131720"><a name="zh-cn_topic_0000002347924121_p2319138131720"></a><a name="zh-cn_topic_0000002347924121_p2319138131720"></a><span id="zh-cn_topic_0000002347924121_ph1531918811177"><a name="zh-cn_topic_0000002347924121_ph1531918811177"></a><a name="zh-cn_topic_0000002347924121_ph1531918811177"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p43191083177"><a name="zh-cn_topic_0000002347924121_p43191083177"></a><a name="zh-cn_topic_0000002347924121_p43191083177"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p73191682178"><a name="zh-cn_topic_0000002347924121_p73191682178"></a><a name="zh-cn_topic_0000002347924121_p73191682178"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p0273714191718"><a name="zh-cn_topic_0000002347924121_p0273714191718"></a><a name="zh-cn_topic_0000002347924121_p0273714191718"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p12291114151711"><a name="zh-cn_topic_0000002347924121_p12291114151711"></a><a name="zh-cn_topic_0000002347924121_p12291114151711"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p1432312144179"><a name="zh-cn_topic_0000002347924121_p1432312144179"></a><a name="zh-cn_topic_0000002347924121_p1432312144179"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row133201883178"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1432018131718"><a name="zh-cn_topic_0000002347924121_p1432018131718"></a><a name="zh-cn_topic_0000002347924121_p1432018131718"></a><span id="zh-cn_topic_0000002347924121_ph183205820171"><a name="zh-cn_topic_0000002347924121_ph183205820171"></a><a name="zh-cn_topic_0000002347924121_ph183205820171"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="section13653173113509"></a>

```c
…
int ret = 0;
int dev_id = 0;
struct dcmi_pcie_link_bandwidth_info bandwidth_info = {0};
bandwidth_info.profiling_time = 1000;
ret = dcmiv2_get_pcie_link_bandwidth_info(dev_id, &bandwidth_info);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

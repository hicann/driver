# dcmiv2\_get\_device\_pcie\_info<a name="ZH-CN_TOPIC_0000002314204918"></a>

## 函数原型<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_toc533412077"></a>

**int dcmiv2\_get\_device\_pcie\_info\(int dev\_id, struct dcmi\_pcie\_info\_all \*pcie\_info\)**

## 功能说明<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_toc533412078"></a>

获取指定设备的PCIe信息，包括PCIe domain域信息。

## 参数说明<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_toc533412079"></a>

<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p10021890"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p10021890"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p6466753"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p6466753"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p54045009"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p54045009"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p15569626"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p15569626"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p7711145152918"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p7711145152918"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p671116522914"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p671116522914"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p1771116572910"><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p1771116572910"></a><a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001239051225_p167202042104713"><a name="zh-cn_topic_0000001239051225_p167202042104713"></a><a name="zh-cn_topic_0000001239051225_p167202042104713"></a>pcie_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001239051225_p16721242134719"><a name="zh-cn_topic_0000001239051225_p16721242134719"></a><a name="zh-cn_topic_0000001239051225_p16721242134719"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001239051225_p1721154216474"><a name="zh-cn_topic_0000001239051225_p1721154216474"></a><a name="zh-cn_topic_0000001239051225_p1721154216474"></a>struct dcmi_pcie_info_all *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001239051225_p6721942174712"><a name="zh-cn_topic_0000001239051225_p6721942174712"></a><a name="zh-cn_topic_0000001239051225_p6721942174712"></a>PCIe信息。</p>
<p id="zh-cn_topic_0000001239051225_p11721154216478"><a name="zh-cn_topic_0000001239051225_p11721154216478"></a><a name="zh-cn_topic_0000001239051225_p11721154216478"></a>struct dcmi_pcie_info_all {</p>
<p id="zh-cn_topic_0000001239051225_p15721194234712"><a name="zh-cn_topic_0000001239051225_p15721194234712"></a><a name="zh-cn_topic_0000001239051225_p15721194234712"></a>unsigned int venderid; //厂商ID</p>
<p id="zh-cn_topic_0000001239051225_p372118429479"><a name="zh-cn_topic_0000001239051225_p372118429479"></a><a name="zh-cn_topic_0000001239051225_p372118429479"></a>unsigned int subvenderid; //厂商子ID</p>
<p id="zh-cn_topic_0000001239051225_p1472110426475"><a name="zh-cn_topic_0000001239051225_p1472110426475"></a><a name="zh-cn_topic_0000001239051225_p1472110426475"></a>unsigned int deviceid; //设备ID</p>
<p id="zh-cn_topic_0000001239051225_p1072115425479"><a name="zh-cn_topic_0000001239051225_p1072115425479"></a><a name="zh-cn_topic_0000001239051225_p1072115425479"></a>unsigned int subdeviceid; //设备子ID</p>
<p id="zh-cn_topic_0000001239051225_p14721114217477"><a name="zh-cn_topic_0000001239051225_p14721114217477"></a><a name="zh-cn_topic_0000001239051225_p14721114217477"></a>int domain; //pcie domain</p>
<p id="zh-cn_topic_0000001239051225_p972164215479"><a name="zh-cn_topic_0000001239051225_p972164215479"></a><a name="zh-cn_topic_0000001239051225_p972164215479"></a>unsigned int bdf_busid; //BDF（Bus，Device，Function）中的总线ID</p>
<p id="zh-cn_topic_0000001239051225_p672124254717"><a name="zh-cn_topic_0000001239051225_p672124254717"></a><a name="zh-cn_topic_0000001239051225_p672124254717"></a>unsigned int bdf_deviceid; //BDF（Bus，Device，Function）中的设备ID</p>
<p id="zh-cn_topic_0000001239051225_p147215422473"><a name="zh-cn_topic_0000001239051225_p147215422473"></a><a name="zh-cn_topic_0000001239051225_p147215422473"></a>unsigned int bdf_funcid; //BDF（Bus，Device，Function）中的功能ID</p>
<p id="zh-cn_topic_0000001239051225_p1572164219475"><a name="zh-cn_topic_0000001239051225_p1572164219475"></a><a name="zh-cn_topic_0000001239051225_p1572164219475"></a>unsigned char reserve[32];</p>
<p id="zh-cn_topic_0000001239051225_p7721842114716"><a name="zh-cn_topic_0000001239051225_p7721842114716"></a><a name="zh-cn_topic_0000001239051225_p7721842114716"></a>};</p>
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

## 约束说明<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_toc533412082"></a>

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

## 调用示例<a name="zh-cn_topic_0000001239051225_zh-cn_topic_0000001100298000_toc533412083"></a>

```c
…
int ret;
int dev_id = 0;
struct dcmi_pcie_info_all pcie_info = {0};
ret = dcmiv2_get_device_pcie_info(dev_id, &pcie_info);
…
```

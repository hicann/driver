# dcmiv2\_get\_device\_pcie\_slot\_id<a name="ZH-CN_TOPIC_0000002348043861"></a>

## 函数原型<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412077"></a>

**int dcmiv2\_get\_device\_pcie\_slot\_id\(int dev\_id, int \*pcie\_slot\)**

## 功能说明<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412078"></a>

查询指定设备的PCIe slot ID。

## 参数说明<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412079"></a>

<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10021890"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10021890"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p6466753"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p6466753"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p54045009"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p54045009"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p15569626"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p15569626"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_row10560021192510"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"></a><a name="zh-cn_topic_0000001206147228_zh-cn_topic_0000001178213206_zh-cn_topic_0000001101611602_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"></a>pcie_slot</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"></a>PCIe slot ID</p>
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

## 约束说明<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table116394134134"></a>
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

## 调用示例<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
int pcie_slot = 0;
ret = dcmiv2_get_device_pcie_slot_id(dev_id, &pcie_slot);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

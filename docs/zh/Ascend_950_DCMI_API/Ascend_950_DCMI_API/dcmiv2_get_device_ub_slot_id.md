# dcmiv2\_get\_device\_ub\_slot\_id<a name="ZH-CN_TOPIC_0000002585785033"></a>

## 函数原型<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412077"></a>

**int dcmiv2\_get\_device\_ub\_slot\_id\(int dev\_id, int \*ub\_slot\)**

## 功能说明<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412078"></a>

查询指定设备的UB端口slot ID。

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
<tr id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10696122145715"></a>ub_slot</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p17696121165710"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p10697122115710"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"></a><a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_p1669792195720"></a>UB端口slot ID。</p>
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
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row313212815215"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p9132382529"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p165659620015"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p177681147617"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p15654617010"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p4891412143910"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row61328855215"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p17132168105212"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p171329855216"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p07691949613"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1513228195214"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p48911512183914"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row7132208165219"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="p144147361596"><a name="p144147361596"></a><a name="p144147361596"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="p772194981912"><a name="p772194981912"></a><a name="p772194981912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="p1372916492196"><a name="p1372916492196"></a><a name="p1372916492196"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="p17361249171913"><a name="p17361249171913"></a><a name="p17361249171913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="p1737154910194"><a name="p1737154910194"></a><a name="p1737154910194"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="p1473815496194"><a name="p1473815496194"></a><a name="p1473815496194"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row6356211905"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><span id="zh-cn_topic_0000002347924121_ph39818321514"><a name="zh-cn_topic_0000002347924121_ph39818321514"></a><a name="zh-cn_topic_0000002347924121_ph39818321514"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001206307230_zh-cn_topic_0000001178373128_zh-cn_topic_0000001169397257_toc533412083"></a>

```c
…
int ret = 0;
int dev_id = 0;
int ub_slot = 0;
ret = dcmiv2_get_device_ub_slot_id(dev_id, &ub_slot);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

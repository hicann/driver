# dcmiv2\_get\_group\_intra\_id\_by\_dev\_id<a name="ZH-CN_TOPIC_0000002555106015"></a>

## 函数原型<a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_toc533412077"></a>

**int dcmiv2\_get\_group\_intra\_id\_by\_dev\_id\(int dev\_id, unsigned int \*group\_intra\_id\)**

## 功能说明<a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_toc533412078"></a>

多卡互联场景下，根据软件的逻辑ID查询UB互联GROUP组内ID编号。

## 参数说明<a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_toc533412079"></a>

<a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p10021890"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p10021890"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p6466753"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p6466753"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p54045009"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p54045009"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p15569626"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p15569626"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p7711145152918"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p7711145152918"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p671116522914"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p671116522914"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p1771116572910"><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p1771116572910"></a><a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p9876144122716"><a name="p9876144122716"></a><a name="p9876144122716"></a>group_intra_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p138768442718"><a name="p138768442718"></a><a name="p138768442718"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p587610410275"><a name="p587610410275"></a><a name="p587610410275"></a>unsigned int<strong id="b19236424132317"><a name="b19236424132317"></a><a name="b19236424132317"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p19941243163118"><a name="p19941243163118"></a><a name="p19941243163118"></a>UB互联GROUP组内ID编号，用于唯一标识组内各标卡的物理位置。ID与互连板的插槽槽位一一对应，若卡插入第N号插槽，则ID值为N。</p>
<a name="ul1829511720321"></a><a name="ul1829511720321"></a><ul id="ul1829511720321"><li>2卡互联场景的值为[0,1]</li><li>4卡互联场景的值为[0,3]</li></ul>
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

## 约束说明<a name="section123251041142612"></a>

**表 1** 不同部署场景下的支持情况

<a name="table6183194116432"></a>
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
<tbody><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row7132208165219"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p15420103714516"><a name="zh-cn_topic_0000002347924121_p15420103714516"></a><a name="zh-cn_topic_0000002347924121_p15420103714516"></a><span id="zh-cn_topic_0000002347924121_ph6420193745115"><a name="zh-cn_topic_0000002347924121_ph6420193745115"></a><a name="zh-cn_topic_0000002347924121_ph6420193745115"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p819818203526"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p399810267455"><a name="zh-cn_topic_0000002347924121_p399810267455"></a><a name="zh-cn_topic_0000002347924121_p399810267455"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p199994269451"><a name="zh-cn_topic_0000002347924121_p199994269451"></a><a name="zh-cn_topic_0000002347924121_p199994269451"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p50172714514"><a name="zh-cn_topic_0000002347924121_p50172714514"></a><a name="zh-cn_topic_0000002347924121_p50172714514"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p8957193025710"><a name="zh-cn_topic_0000002347924121_p8957193025710"></a><a name="zh-cn_topic_0000002347924121_p8957193025710"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row6356211905"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p1231162514015"></a><span id="zh-cn_topic_0000002347924121_ph39818321514"><a name="zh-cn_topic_0000002347924121_ph39818321514"></a><a name="zh-cn_topic_0000002347924121_ph39818321514"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001251227173_zh-cn_topic_0000001223292889_zh-cn_topic_0000001147723703_toc533412083"></a>

```c
…
int ret;
int dev_id = 0;
unsigned int group_intra_id = 0;
ret = dcmiv2_get_group_intra_id_by_dev_id(dev_id, &group_intra_id);
…
```

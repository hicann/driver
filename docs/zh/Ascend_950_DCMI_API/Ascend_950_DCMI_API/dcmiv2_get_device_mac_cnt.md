# dcmiv2\_get\_device\_mac\_cnt<a name="ZH-CN_TOPIC_0000002314204850"></a>

## 函数原型<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_toc533412077"></a>

**int dcmiv2\_get\_device\_mac\_cnt\(int dev\_id, int \*count\)**

## 功能说明<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_toc533412078"></a>

查询当前设备的MAC地址数量。

## 参数说明<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_toc533412079"></a>

<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p10021890"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p10021890"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p6466753"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p6466753"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="14.729999999999999%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p54045009"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p54045009"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="53.25%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p15569626"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p15569626"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p7711145152918"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p7711145152918"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p671116522914"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p671116522914"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1771116572910"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1771116572910"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="53.25%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p65122018413"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p65122018413"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p65122018413"></a>count</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1456209414"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1456209414"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p1456209414"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="14.729999999999999%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p78615251246"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p78615251246"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p78615251246"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="53.25%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p19519201418"><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p19519201418"></a><a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_p19519201418"></a>查询出MAC数，取值范围：0~1。</p>
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

## 约束说明<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_toc533412082"></a>

**表 1** 不同部署场景下的支持情况

<a name="table116394134134"></a>
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

## 调用示例<a name="zh-cn_topic_0000001251107205_zh-cn_topic_0000001223172945_zh-cn_topic_0000001148164483_toc533412083"></a>

```c
…
int ret = 0;
int count = -1;
int dev_id = 0;
ret = dcmiv2_get_device_mac_cnt(dev_id, &count);
if (ret != 0){
    //todo:记录日志
    return ret;
}
…
```

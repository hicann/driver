# dcmiv2\_clear\_pfc\_duration<a name="ZH-CN_TOPIC_0000002347923989"></a>

## 函数原型<a name="section12365583546"></a>

**int dcmiv2\_clear\_pfc\_duration\(int dev\_id, const char \*netdev\_name, unsigned int netdev\_name\_len\)**

## 功能说明<a name="section142361658175418"></a>

清除指定设备的PFC反压帧持续时间统计值。

## 参数说明<a name="section32371758125411"></a>

<a name="table2274145813545"></a>
<table><thead align="left"><tr id="row106575945418"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="p665759125418"><a name="p665759125418"></a><a name="p665759125418"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="p10659593544"><a name="p10659593544"></a><a name="p10659593544"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="p1265259155414"><a name="p1265259155414"></a><a name="p1265259155414"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="p196611598540"><a name="p196611598540"></a><a name="p196611598540"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1662595540"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p16610593540"><a name="p16610593540"></a><a name="p16610593540"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p06675913543"><a name="p06675913543"></a><a name="p06675913543"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p1666159175411"><a name="p1666159175411"></a><a name="p1666159175411"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row1387683317617"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p1729101525418"><a name="p1729101525418"></a><a name="p1729101525418"></a>netdev_name</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p1429915185417"><a name="p1429915185417"></a><a name="p1429915185417"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p162991555411"><a name="p162991555411"></a><a name="p162991555411"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p1194494412540"><a name="p1194494412540"></a><a name="p1194494412540"></a>UBoE端口的bond设备名，通过<a href="dcmiv2_get_device_netdev_list_info.md">dcmiv2_get_device_netdev_list_info</a>接口获取。</p>
</td>
</tr>
<tr id="row156001305615"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p168631252165514"><a name="p168631252165514"></a><a name="p168631252165514"></a>netdev_name_len</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="p168634526551"><a name="p168634526551"></a><a name="p168634526551"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="p78631752175513"><a name="p78631752175513"></a><a name="p78631752175513"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="p5863185219555"><a name="p5863185219555"></a><a name="p5863185219555"></a>UBoE端口bond设备名的长度。</p>
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

## 约束说明<a name="section1625614581546"></a>

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

## 调用示例<a name="section192671558125418"></a>

```c
…
int ret = 0;
int dev_id = 0;
char netdev_name[6] = "bond0";
unsigned int netdev_name_len = 5;
ret = dcmiv2_clear_pfc_duration(dev_id, netdev_name, netdev_name_len);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

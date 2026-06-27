# dcmiv2\_upgrade\_vrd<a name="ZH-CN_TOPIC_0000002533268079"></a>

## 函数原型<a name="zh-cn_topic_0000002227065381_section62545218249"></a>

**int dcmiv2\_upgrade\_vrd\(int dev\_id, const char \*file\)**

## 功能说明<a name="zh-cn_topic_0000002227065381_section126852122411"></a>

升级VRD固件。

## 参数说明<a name="zh-cn_topic_0000002227065381_section1527155212240"></a>

<a name="zh-cn_topic_0000002227065381_table15407522241"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002227065381_row1467752102414"><th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000002227065381_p1467135212241"><a name="zh-cn_topic_0000002227065381_p1467135212241"></a><a name="zh-cn_topic_0000002227065381_p1467135212241"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="15.15%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000002227065381_p1367152172415"><a name="zh-cn_topic_0000002227065381_p1367152172415"></a><a name="zh-cn_topic_0000002227065381_p1367152172415"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="17.169999999999998%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000002227065381_p1967952112412"><a name="zh-cn_topic_0000002227065381_p1967952112412"></a><a name="zh-cn_topic_0000002227065381_p1967952112412"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000002227065381_p967135212413"><a name="zh-cn_topic_0000002227065381_p967135212413"></a><a name="zh-cn_topic_0000002227065381_p967135212413"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002227065381_row146720522240"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000002227065381_p8672522246"><a name="zh-cn_topic_0000002227065381_p8672522246"></a><a name="zh-cn_topic_0000002227065381_p8672522246"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000002227065381_p667452182410"><a name="zh-cn_topic_0000002227065381_p667452182410"></a><a name="zh-cn_topic_0000002227065381_p667452182410"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000002227065381_p116705215249"><a name="zh-cn_topic_0000002227065381_p116705215249"></a><a name="zh-cn_topic_0000002227065381_p116705215249"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002227065381_row667452172412"><td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.1 "><p id="p168608275467"><a name="p168608275467"></a><a name="p168608275467"></a>file</p>
</td>
<td class="cellrowborder" valign="top" width="15.15%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000002227065381_p86718523246"><a name="zh-cn_topic_0000002227065381_p86718523246"></a><a name="zh-cn_topic_0000002227065381_p86718523246"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="17.169999999999998%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000002227065381_p26718521243"><a name="zh-cn_topic_0000002227065381_p26718521243"></a><a name="zh-cn_topic_0000002227065381_p26718521243"></a>const char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001251227159_zh-cn_topic_0000001223172947_zh-cn_topic_0000001148530297_p868945411372"><a name="zh-cn_topic_0000001251227159_zh-cn_topic_0000001223172947_zh-cn_topic_0000001148530297_p868945411372"></a><a name="zh-cn_topic_0000001251227159_zh-cn_topic_0000001223172947_zh-cn_topic_0000001148530297_p868945411372"></a>VRD升级包。</p>
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

<a name="table1495412398240"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_row1219955113916"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_p1519555163918"><a name="zh-cn_topic_0000002347924121_p1519555163918"></a><a name="zh-cn_topic_0000002347924121_p1519555163918"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p10191551393"><a name="zh-cn_topic_0000002347924121_p10191551393"></a><a name="zh-cn_topic_0000002347924121_p10191551393"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p31935573913"><a name="zh-cn_topic_0000002347924121_p31935573913"></a><a name="zh-cn_topic_0000002347924121_p31935573913"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p419125563917"><a name="zh-cn_topic_0000002347924121_p419125563917"></a><a name="zh-cn_topic_0000002347924121_p419125563917"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p019555103920"><a name="zh-cn_topic_0000002347924121_p019555103920"></a><a name="zh-cn_topic_0000002347924121_p019555103920"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_row2019185519395"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_p519205514399"><a name="zh-cn_topic_0000002347924121_p519205514399"></a><a name="zh-cn_topic_0000002347924121_p519205514399"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_p51918553399"><a name="zh-cn_topic_0000002347924121_p51918553399"></a><a name="zh-cn_topic_0000002347924121_p51918553399"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p31917558393"><a name="zh-cn_topic_0000002347924121_p31917558393"></a><a name="zh-cn_topic_0000002347924121_p31917558393"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_p2194555398"><a name="zh-cn_topic_0000002347924121_p2194555398"></a><a name="zh-cn_topic_0000002347924121_p2194555398"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p21995593919"><a name="zh-cn_topic_0000002347924121_p21995593919"></a><a name="zh-cn_topic_0000002347924121_p21995593919"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row101915558397"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p8191355143917"><a name="zh-cn_topic_0000002347924121_p8191355143917"></a><a name="zh-cn_topic_0000002347924121_p8191355143917"></a><span id="zh-cn_topic_0000002347924121_ph819115583917"><a name="zh-cn_topic_0000002347924121_ph819115583917"></a><a name="zh-cn_topic_0000002347924121_ph819115583917"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p12191055143917"><a name="zh-cn_topic_0000002347924121_p12191055143917"></a><a name="zh-cn_topic_0000002347924121_p12191055143917"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p2191255113910"><a name="zh-cn_topic_0000002347924121_p2191255113910"></a><a name="zh-cn_topic_0000002347924121_p2191255113910"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p51912552396"><a name="zh-cn_topic_0000002347924121_p51912552396"></a><a name="zh-cn_topic_0000002347924121_p51912552396"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1201455113912"><a name="zh-cn_topic_0000002347924121_p1201455113912"></a><a name="zh-cn_topic_0000002347924121_p1201455113912"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p220955113913"><a name="zh-cn_topic_0000002347924121_p220955113913"></a><a name="zh-cn_topic_0000002347924121_p220955113913"></a>N</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row4201855143918"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p112012555392"><a name="zh-cn_topic_0000002347924121_p112012555392"></a><a name="zh-cn_topic_0000002347924121_p112012555392"></a><span id="zh-cn_topic_0000002347924121_ph921055143919"><a name="zh-cn_topic_0000002347924121_ph921055143919"></a><a name="zh-cn_topic_0000002347924121_ph921055143919"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000002227065381_section6395526248"></a>

```c
…
int ret = 0;
int dev_id = 0;
const char *file = "Atlas-A5-hdk-vrd-firmware_xxx.hpm";
ret = dcmiv2_upgrade_vrd(dev_id, file);
if (ret != 0){
    //todo：记录日志
    return ret;
}
…
```

# dcmiv2\_get\_affinity\_cpu\_info\_by\_dev\_id<a name="ZH-CN_TOPIC_0000002314045130"></a>

## 函数原型<a name="section0487181861417"></a>

**int dcmiv2\_get\_affinity\_cpu\_info\_by\_dev\_id\(int dev\_id, char \*affinity\_cpu, int \*len\)**

## 功能说明<a name="section248711861419"></a>

查询指定NPU的CPU亲和性。

## 参数说明<a name="section448711891417"></a>

<a name="table348771812142"></a>
<table><thead align="left"><tr id="row1487918101413"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="p1048720181148"><a name="p1048720181148"></a><a name="p1048720181148"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.2"><p id="p11487151841419"><a name="p11487151841419"></a><a name="p11487151841419"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="16%" id="mcps1.1.5.1.3"><p id="p184876188146"><a name="p184876188146"></a><a name="p184876188146"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="p34881318151413"><a name="p34881318151413"></a><a name="p34881318151413"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="row1748881815146"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p74884186146"><a name="p74884186146"></a><a name="p74884186146"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p54881818151413"><a name="p54881818151413"></a><a name="p54881818151413"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p2488131815149"><a name="p2488131815149"></a><a name="p2488131815149"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="row048812180148"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p18489131814145"><a name="p18489131814145"></a><a name="p18489131814145"></a><span>affinity_cpu</span></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p16489141813146"><a name="p16489141813146"></a><a name="p16489141813146"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p1148912180142"><a name="p1148912180142"></a><a name="p1148912180142"></a>char *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1048951841415"><a name="p1048951841415"></a><a name="p1048951841415"></a>获取指定NPU的CPU亲和性。</p>
</td>
</tr>
<tr id="row10489318191418"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p16489718161414"><a name="p16489718161414"></a><a name="p16489718161414"></a><span>len</span></p>
</td>
<td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.2 "><p id="p0489818161416"><a name="p0489818161416"></a><a name="p0489818161416"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="16%" headers="mcps1.1.5.1.3 "><p id="p14489111811420"><a name="p14489111811420"></a><a name="p14489111811420"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1848911801411"><a name="p1848911801411"></a><a name="p1848911801411"></a>输出亲和性字符串的长度。</p>
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

## 约束说明<a name="section18490181816141"></a>

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

## 调用示例<a name="section5491121812143"></a>

```c
…
int ret;
int dev_id = 0;
char affinity_cpu[TOPO_INFO_MAX_LENTH] ={0};
int len;
ret = dcmiv2_get_affinity_cpu_info_by_dev_id(dev_id, affinity_cpu, &len);
…
```

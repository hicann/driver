# dcmiv2\_get\_device\_error\_info<a name="ZH-CN_TOPIC_0000002314204882"></a>

## 函数原型<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412077"></a>

**int dcmiv2\_get\_device\_error\_info\(int dev\_id, unsigned int error\_code, unsigned char \*error\_info, int buf\_size\)**

## 功能说明<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412078"></a>

查询设备故障描述。

## 参数说明<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412079"></a>

<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_table10480683"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_row7580267"><th class="cellrowborder" valign="top" width="17.000000000000004%" id="mcps1.1.5.1.1"><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p10021890"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p10021890"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p10021890"></a>参数名称</p>
</th>
<th class="cellrowborder" valign="top" width="16.990000000000002%" id="mcps1.1.5.1.2"><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6466753"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6466753"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6466753"></a>输入/输出</p>
</th>
<th class="cellrowborder" valign="top" width="15.960000000000003%" id="mcps1.1.5.1.3"><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p54045009"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p54045009"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p54045009"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="50.050000000000004%" id="mcps1.1.5.1.4"><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p15569626"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p15569626"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p15569626"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_row1155711494235"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p7711145152918"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p7711145152918"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p671116522914"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p671116522914"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p671116522914"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1771116572910"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1771116572910"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000002348043873_p1761223114720"><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><a name="zh-cn_topic_0000002348043873_p1761223114720"></a><span id="zh-cn_topic_0000002348043873_ph1263073113614"><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a><a name="zh-cn_topic_0000002348043873_ph1263073113614"></a>软件的逻辑ID</span>，通过<a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>接口获取。取值范围为[0, device_cnt-1]。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_row15462171542913"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p72389712563"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p72389712563"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p72389712563"></a>error_code</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112389725620"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112389725620"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112389725620"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p8238871561"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p8238871561"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p8238871561"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p162392075566"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p162392075566"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p162392075566"></a>要查询的错误码，通过<a href="dcmiv2_get_device_error_code_list.md">dcmiv2_get_device_error_code_list</a>接口获取。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_row194331899543"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p523913745616"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p523913745616"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p523913745616"></a>error_info</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1323919719563"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1323919719563"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p1323919719563"></a>输出</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112391711565"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112391711565"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p112391711565"></a>unsigned char *</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p172395717564"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p172395717564"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p172395717564"></a>对应的错误描述。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_row769671118543"><td class="cellrowborder" valign="top" width="17.000000000000004%" headers="mcps1.1.5.1.1 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p12239772564"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p12239772564"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p12239772564"></a>buf_size</p>
</td>
<td class="cellrowborder" valign="top" width="16.990000000000002%" headers="mcps1.1.5.1.2 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p2239476561"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p2239476561"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p2239476561"></a>输入</p>
</td>
<td class="cellrowborder" valign="top" width="15.960000000000003%" headers="mcps1.1.5.1.3 "><p id="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6239157175610"><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6239157175610"></a><a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_p6239157175610"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50.050000000000004%" headers="mcps1.1.5.1.4 "><p id="zh-cn_topic_0000001178373142_p1661902431918"><a name="zh-cn_topic_0000001178373142_p1661902431918"></a><a name="zh-cn_topic_0000001178373142_p1661902431918"></a>传入的error_info取值范围是大于等于48字节。</p>
<a name="zh-cn_topic_0000001178373142_ul1060910207250"></a><a name="zh-cn_topic_0000001178373142_ul1060910207250"></a><ul id="zh-cn_topic_0000001178373142_ul1060910207250"><li>若设置的error_info小于48字节，则系统报错。</li><li>若设置的error_info在48~255字节之间，则在<span id="ph1630384313518"><a name="ph1630384313518"></a><a name="ph1630384313518"></a>《<a href="https://support.huawei.com/enterprise/zh/doc/EDOC1100569783" target="_blank" rel="noopener noreferrer">昇腾950代际产品 健康管理故障定义</a>》</span>中的故障码，查询出来的故障信息为简化信息。</li><li>若设置的error_info大于等于256字节，则查询出来的故障信息为实际故障信息。</li></ul>
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

## 约束说明<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412082"></a>

调用该接口查询到的信息仅代表当前芯片设计了这种错误码类型，具有上报这种故障类型的能力，但不代表当前已经使用这个错误码。当前芯片已经支持的错误码请按照[参数说明](#zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412079)表中error\_code参数的描述获取。

**表 1** 不同部署场景下的支持情况

<a name="table1891871242416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_p67828402447"></a>产品形态</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002347924121_p65514914017"><a name="zh-cn_topic_0000002347924121_p65514914017"></a><a name="zh-cn_topic_0000002347924121_p65514914017"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002347924121_p56108061"><a name="zh-cn_topic_0000002347924121_p56108061"></a><a name="zh-cn_topic_0000002347924121_p56108061"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002347924121_p1855189908"><a name="zh-cn_topic_0000002347924121_p1855189908"></a><a name="zh-cn_topic_0000002347924121_p1855189908"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002347924121_p10771327123917"><a name="zh-cn_topic_0000002347924121_p10771327123917"></a><a name="zh-cn_topic_0000002347924121_p10771327123917"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p792013462306"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p16920346133016"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002347924121_p56110815619"><a name="zh-cn_topic_0000002347924121_p56110815619"></a><a name="zh-cn_topic_0000002347924121_p56110815619"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a><a name="zh-cn_topic_0000002347924121_zh-cn_topic_0000002347924121_zh-cn_topic_0000001206627196_zh-cn_topic_0000001178213188_zh-cn_topic_0000001146459833_p166440421324"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002347924121_p977116273398"><a name="zh-cn_topic_0000002347924121_p977116273398"></a><a name="zh-cn_topic_0000002347924121_p977116273398"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002347924121_p144147361596"><a name="zh-cn_topic_0000002347924121_p144147361596"></a><a name="zh-cn_topic_0000002347924121_p144147361596"></a><span id="zh-cn_topic_0000002347924121_ph12140626193614"><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a><a name="zh-cn_topic_0000002347924121_ph12140626193614"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002347924121_p13356146465"><a name="zh-cn_topic_0000002347924121_p13356146465"></a><a name="zh-cn_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002347924121_p19351314124620"><a name="zh-cn_topic_0000002347924121_p19351314124620"></a><a name="zh-cn_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002347924121_p1577514751713"><a name="zh-cn_topic_0000002347924121_p1577514751713"></a><a name="zh-cn_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p1435121434611"><a name="zh-cn_topic_0000002347924121_p1435121434611"></a><a name="zh-cn_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002347924121_p8318151920427"><a name="zh-cn_topic_0000002347924121_p8318151920427"></a><a name="zh-cn_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002347924121_p56258171305"><a name="zh-cn_topic_0000002347924121_p56258171305"></a><a name="zh-cn_topic_0000002347924121_p56258171305"></a><span id="zh-cn_topic_0000002347924121_ph15391145912019"><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a><a name="zh-cn_topic_0000002347924121_ph15391145912019"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</span></p>
</td>
</tr>
</tbody>
</table>

## 调用示例<a name="zh-cn_topic_0000001178373142_zh-cn_topic_0000001147610857_toc533412083"></a>

```c
#define ERROR_CODE_MAX_NUM  (128)
#define BUF_SIZE          (256)
…
int ret = 0;
int dev_id = 0;
int error_count = 0;
unsigned int error_code_list[ERROR_CODE_MAX_NUM] = {0};
unsigned char error_info[BUF_SIZE] = {0};
ret = dcmiv2_get_device_error_code_list(dev_id, &error_count, error_code_list, ERROR_CODE_MAX_NUM);
if ((ret != 0) || (error_count == 0)){
    //todo:记录日志
    return ret;
} 
ret = dcmiv2_get_device_error_info(dev_id, error_code_list[0], error_info, BUF_SIZE);
if (ret != 0) { 
    //todo:记录日志
    return ret;
}
…
```

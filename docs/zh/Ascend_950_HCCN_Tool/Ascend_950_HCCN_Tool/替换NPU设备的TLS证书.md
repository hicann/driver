# 替换NPU设备的TLS证书<a name="ZH-CN_TOPIC_0000002584451450"></a>

## 产品支持情况<a name="section8178181118225"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row1152516361961"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p65251336569"><a name="zh-cn_topic_0000002614931227_p65251336569"></a><a name="zh-cn_topic_0000002614931227_p65251336569"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p1452518361269"><a name="zh-cn_topic_0000002614931227_p1452518361269"></a><a name="zh-cn_topic_0000002614931227_p1452518361269"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p12525133617618"><a name="zh-cn_topic_0000002614931227_p12525133617618"></a><a name="zh-cn_topic_0000002614931227_p12525133617618"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p175251236867"><a name="zh-cn_topic_0000002614931227_p175251236867"></a><a name="zh-cn_topic_0000002614931227_p175251236867"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p135256361566"><a name="zh-cn_topic_0000002614931227_p135256361566"></a><a name="zh-cn_topic_0000002614931227_p135256361566"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p9525173614613"><a name="zh-cn_topic_0000002614931227_p9525173614613"></a><a name="zh-cn_topic_0000002614931227_p9525173614613"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row175255361369"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p175257363614"><a name="zh-cn_topic_0000002614931227_p175257363614"></a><a name="zh-cn_topic_0000002614931227_p175257363614"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p175255361567"><a name="zh-cn_topic_0000002614931227_p175255361567"></a><a name="zh-cn_topic_0000002614931227_p175255361567"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p052519366616"><a name="zh-cn_topic_0000002614931227_p052519366616"></a><a name="zh-cn_topic_0000002614931227_p052519366616"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p1152593617617"><a name="zh-cn_topic_0000002614931227_p1152593617617"></a><a name="zh-cn_topic_0000002614931227_p1152593617617"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p175251236967"><a name="zh-cn_topic_0000002614931227_p175251236967"></a><a name="zh-cn_topic_0000002614931227_p175251236967"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p175252363616"><a name="zh-cn_topic_0000002614931227_p175252363616"></a><a name="zh-cn_topic_0000002614931227_p175252363616"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row18525103618619"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p7525736665"><a name="zh-cn_topic_0000002614931227_p7525736665"></a><a name="zh-cn_topic_0000002614931227_p7525736665"></a><span id="zh-cn_topic_0000002614931227_ph115250361460"><a name="zh-cn_topic_0000002614931227_ph115250361460"></a><a name="zh-cn_topic_0000002614931227_ph115250361460"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p29591819165216"><a name="zh-cn_topic_0000002614931227_p29591819165216"></a><a name="zh-cn_topic_0000002614931227_p29591819165216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p19525143135318"><a name="zh-cn_topic_0000002614931227_p19525143135318"></a><a name="zh-cn_topic_0000002614931227_p19525143135318"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p4905122915216"><a name="zh-cn_topic_0000002614931227_p4905122915216"></a><a name="zh-cn_topic_0000002614931227_p4905122915216"></a>Y（Device侧、Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p10942162645212"><a name="zh-cn_topic_0000002614931227_p10942162645212"></a><a name="zh-cn_topic_0000002614931227_p10942162645212"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p1247513092013"><a name="zh-cn_topic_0000002614931227_p1247513092013"></a><a name="zh-cn_topic_0000002614931227_p1247513092013"></a>Y（Host侧证书）</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p179751228202115"><a name="zh-cn_topic_0000002614931227_p179751228202115"></a><a name="zh-cn_topic_0000002614931227_p179751228202115"></a>Y（Host侧证书）</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row55261736962"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p0526133614614"><a name="zh-cn_topic_0000002614931227_p0526133614614"></a><a name="zh-cn_topic_0000002614931227_p0526133614614"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="zh-cn_topic_0184799386_section1383319120101"></a>

替换Host侧或Device侧的TLS证书信息。

>**须知：** 
>
>- 初始证书仅用于部署阶段为设备接入用户网络建立初始安全通道，华为不对初始证书的安全性做承诺与保证。
>- 对于将华为初始证书作为业务证书使用而导致的安全风险和安全事件，由用户自行处置并承担后果。
>- 初始证书有效期自生产制造之日起计算，因设备生产批次不同，有效期截止到2099年。
>- 建议用户通过部署PKI系统对现网设备、软件签发证书并做好证书的生命周期管理（为保证安全性推荐使用短有效期的证书）。
>- 初始证书过期后，使用初始证书的业务会中断。

## 注意事项<a name="zh-cn_topic_0238914640_section127461744152119"></a>

1. 预置（首次）通常在装备阶段完成，用户可使用该命令替换已存在的证书（自己生成，或从设备厂商或第三方机构获取）。建议用户运行业务前替换装备阶段的初始证书。
2. 证书、私钥和吊销列表配置：
    1. 证书的级数是可选择的，最少二级（只包含设备证书、根证书），最多十五级（设备证书、根证书、二级根证书…十四级根证书），出厂默认使用三级（设备证书、根证书、二级根证书）。设备证书中建议带有唯一性信息，保障一机一密。
    2. 用户可以选择只替换证书，或单独更新吊销列表，但需要保证TLS证书和吊销列表是配套的；单独更新吊销列表的操作只支持对Device侧进行。
    3. 文件名长度：最多255Byte，包括后缀（如：pub.pem，文件名长度为7）。
    4. 文件大小：
        1. 证书：Device侧最大3072Byte，Host侧最大2048Byte。
        2. 私钥：最大4096Byte。
        3. 吊销列表：最大20480Byte。

    5. 证书签发者名称：最大长度为64Byte。
    6. 证书必须是X.509v3格式；根CA和中级CA证书的“基本限制”扩展域必须标明为“CA”，“密钥用法”扩展域中必须包含“证书签名”，所有数字证书和吊销列表必须处于有效期内，建议定期更新配置。
    7. 仅支持pem类型的证书和私钥，crl类型的吊销列表。
    8. 仅支持RSA私钥，RSA长度为\[2048,4096\]，私钥必须是密文的，且私钥的加密算法仅支持AES-256。
    9. 用户需确保私钥、证书和吊销列表配套，否则可能导致替换失败。
    10. 私钥和设备证书需要配套替换。
    11. 用户需要指定完整的证书链（-ca1到-caN，N越大，级别越低），需保证低级别证书是由高级别证书签发、设备证书和吊销列表由最低级别的根证书签发，否则会导致证书链校验失败及配置失败。
    12. 预置或者更新私钥时，输入的口令必须和生成私钥时输入的口令一致。

3. 口令使用：
    1. 口令使用交互式命令行输入，且不回显，口令的长度为8\~15，且最少包含大写字母、小写字母、数字、特殊符号中的2种组合。
    2. 输入的口令不能在弱口令字典中，否则会配置失败。弱口令字典在“/etc”（root用户）或者“/home/$\{USER\}”（非root用户）目录下，文件名为“hccn\_weak\_dict.conf”，权限为600。用户可增删该文件内容，但不能重命名或者删除该文件，否则弱口令字典校验功能失效。

4. Host侧证书配置：
    1. 当证书配置在Host侧时，配置的有效性与设备ID值无关。
    2. 配置Host侧的TLS证书时，需要保证hccn\_tool文件的权限为555，其所在路径“/usr/local/Ascend/driver/tools”（指工具的安装路径）的权限为755。

5. 配置完成后，要将密文的私钥删除，回显会提示“\[WARNING\] Please delete the private key file after updating for security considerations.”。
6. 集合通信时会使用该命令配置的TLS证书套件进行TLS认证，若TLS认证失败，则会记录日志。

## 命令格式<a name="zh-cn_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -s -tls -i <dev_id> -path <file path> -pri <filename> -pub <filename> -ca1 <filename> [-ca2 <filename>] ...[-ca14 <filename>] [-crl <filename>] [-host]
```

## 参数说明<a name="zh-cn_topic_0184799386_section10465854096"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="29.95%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="13.76%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
<tr id="row14535125123912"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p125352523911"><a name="p125352523911"></a><a name="p125352523911"></a>-path &lt;file path&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p18535105153916"><a name="p18535105153916"></a><a name="p18535105153916"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1153516518398"><a name="p1153516518398"></a><a name="p1153516518398"></a>证书文件存放的系统位置路径。</p>
</td>
</tr>
<tr id="row1874318562390"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p0743356183910"><a name="p0743356183910"></a><a name="p0743356183910"></a>-pri &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p4743756183919"><a name="p4743756183919"></a><a name="p4743756183919"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p6743056173912"><a name="p6743056173912"></a><a name="p6743056173912"></a>私钥文件名。</p>
</td>
</tr>
<tr id="row161351720409"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p13135142164014"><a name="p13135142164014"></a><a name="p13135142164014"></a>-pub &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p98891023184017"><a name="p98891023184017"></a><a name="p98891023184017"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1613522124013"><a name="p1613522124013"></a><a name="p1613522124013"></a>设备证书文件名。</p>
</td>
</tr>
<tr id="row1874155803917"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p208052051134017"><a name="p208052051134017"></a><a name="p208052051134017"></a>-ca1 &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1896714543400"><a name="p1896714543400"></a><a name="p1896714543400"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p2522026104110"><a name="p2522026104110"></a><a name="p2522026104110"></a>根证书（第1级）证书文件名称。</p>
</td>
</tr>
<tr id="row18612101715413"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p12613617194111"><a name="p12613617194111"></a><a name="p12613617194111"></a>-caN &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2061371784110"><a name="p2061371784110"></a><a name="p2061371784110"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p13805175174015"><a name="p13805175174015"></a><a name="p13805175174015"></a>N级根证书（第N级，1&lt;N&lt;15）证书文件名称。</p>
</td>
</tr>
<tr id="row15914103611424"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p1397813374425"><a name="p1397813374425"></a><a name="p1397813374425"></a>-crl &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p797883718421"><a name="p797883718421"></a><a name="p797883718421"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p199141336184213"><a name="p199141336184213"></a><a name="p199141336184213"></a>吊销列表文件名称。</p>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>可选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p379092172711"><a name="p379092172711"></a><a name="p379092172711"></a>指定设置Host侧TLS信息。无该项时默认设置Device侧信息。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section82714204319"></a>

- 示例1：

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -pri server_2.key -pub server_2.pem -ca1 1thCA.pem -ca2 2_1thCA.pem
    ```

    替换逻辑设备ID为0的Device侧的TLS证书。

    ```text
    Please enter pass phrase for pri key:
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

- 示例2：

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -crl cert.crl
    ```

    更新逻辑设备ID为0的Device侧的TLS证书吊销列表。

    ```text
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

- 示例3：

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -pri server_2.key -pub server_2.pem -ca1 1thCA.pem -ca2 2_1thCA.pem -host
    ```

    替换逻辑设备ID为0的Host侧的TLS证书。

    ```text
    Please enter pass phrase for pri key:
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

## 输出说明<a name="section55215490292"></a>

无。

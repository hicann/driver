# 设置KMSAgent进程的服务状态<a name="ZH-CN_TOPIC_0000002583172574"></a>

## 前提条件<a name="section3176079345"></a>

设置KMSAgent进程服务状态前，需先进行证书设置，操作如下：

1. 执行如下命令，进入kmsagentd目录。

    ```bash
    cd /var/kmsagentd
    ```

2. 生成CA证书（以root\_ca.pem为例）
    1. 执行如下命令，生成CA私钥。

        ```bash
        openssl genrsa -out root_ca.key 4096
        ```

    2. 执行如下命令，生成证书请求文件。

        ```bash
        openssl req -new -key root_ca.key -subj "/CN=Root CA" -out root_ca.csr
        ```

    3. 执行如下命令，生成CA证书。

        ```bash
        openssl x509 -req -in root_ca.csr -signkey root_ca.key -days 3650 -extfile openssl.cnf -extensions v3_ca -set_serial 1591942200000 -out root_ca.pem
        ```

3. 设置根CA路径。
    - 执行如下命令，为CFS设置根CA路径。

        ```bash
        su - HwHiAiUser -s /bin/bash -c "export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64/inner:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64/common;/usr/local/Ascend/driver/tools/kmsagent -c /var/kmsagentd/kmsagent.conf -k /var/kmsagentd/kmsconf.ksf -s SERVER_FOR_CFS -n CaPath -v /var/kmsagentd/root_ca.pem"
        ```

    - 执行如下命令，为AIVault设置根CA路径。

        ```bash
        su - HwHiAiUser -s /bin/bash -c "export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64/inner:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64/common;/usr/local/Ascend/driver/tools/kmsagent -c /var/kmsagentd/kmsagent.conf -k /var/kmsagentd/kmsconf.ksf -s CLIENT_FOR_AIVAULT -n CaPath -v /var/kmsagentd/root_ca.pem"
        ```

        > **说明：** 
        > 
        > 如果安装驱动时指定安装路径，则命令中的“_/usr/local/Ascend_”请根据实际情况替换。

## 功能说明<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_section18674262006"></a>

用于设置KMSAgent进程（密钥管理进程）的服务状态。

## 命令格式<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_section386902615016"></a>

`npu-smi set -t key-manage -s value`

## 参数说明<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_section1786919261014"></a>

<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_table7208814"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p3985976"><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p3985976"></a><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p3985976"></a>类型</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p54428625"><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p54428625"></a><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p54428625"></a>描述</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_row1780353745014"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p81048471715"><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p81048471715"></a><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p81048471715"></a><em id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_i846511579238"><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_i846511579238"></a><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_i846511579238"></a>value</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><div class="p" id="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p366013319915"><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p366013319915"></a><a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_p366013319915"></a>服务状态：<a name="zh-cn_topic_0000001264816685_ul1244815329339"></a><a name="zh-cn_topic_0000001264816685_ul1244815329339"></a><ul id="zh-cn_topic_0000001264816685_ul1244815329339"><li>start：启动服务并开启服务自启动</li><li>stop：关闭服务并禁止服务自启动，默认值</li></ul>
</div>
</td>
</tr>
</tbody>
</table>

## 使用指南<a name="zh-cn_topic_0000001264816685_section12330458135411"></a>

OpenSSL版本需在3.0.0及以上，若版本不满足要求，请升级OpenSSL版本，建议安装最新且无漏洞版本。

**表 1** 不同部署场景下的支持情况

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002583332642_row2056819579256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="zh-cn_topic_0000002583332642_p10568457202515"><a name="zh-cn_topic_0000002583332642_p10568457202515"></a><a name="zh-cn_topic_0000002583332642_p10568457202515"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="zh-cn_topic_0000002583332642_p3568155712520"><a name="zh-cn_topic_0000002583332642_p3568155712520"></a><a name="zh-cn_topic_0000002583332642_p3568155712520"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="zh-cn_topic_0000002583332642_p7568757122511"><a name="zh-cn_topic_0000002583332642_p7568757122511"></a><a name="zh-cn_topic_0000002583332642_p7568757122511"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="zh-cn_topic_0000002583332642_p1556812578254"><a name="zh-cn_topic_0000002583332642_p1556812578254"></a><a name="zh-cn_topic_0000002583332642_p1556812578254"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="zh-cn_topic_0000002583332642_p105681557162517"><a name="zh-cn_topic_0000002583332642_p105681557162517"></a><a name="zh-cn_topic_0000002583332642_p105681557162517"></a>直通虚拟机场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002583332642_row185688570253"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="zh-cn_topic_0000002583332642_p175691857172519"><a name="zh-cn_topic_0000002583332642_p175691857172519"></a><a name="zh-cn_topic_0000002583332642_p175691857172519"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="zh-cn_topic_0000002583332642_p1056925762517"><a name="zh-cn_topic_0000002583332642_p1056925762517"></a><a name="zh-cn_topic_0000002583332642_p1056925762517"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="zh-cn_topic_0000002583332642_p1256975772514"><a name="zh-cn_topic_0000002583332642_p1256975772514"></a><a name="zh-cn_topic_0000002583332642_p1256975772514"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="zh-cn_topic_0000002583332642_p2569157132518"><a name="zh-cn_topic_0000002583332642_p2569157132518"></a><a name="zh-cn_topic_0000002583332642_p2569157132518"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="zh-cn_topic_0000002583332642_p656975711257"><a name="zh-cn_topic_0000002583332642_p656975711257"></a><a name="zh-cn_topic_0000002583332642_p656975711257"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002583332642_row65691257162516"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="zh-cn_topic_0000002583332642_p1356905716259"><a name="zh-cn_topic_0000002583332642_p1356905716259"></a><a name="zh-cn_topic_0000002583332642_p1356905716259"></a><span id="zh-cn_topic_0000002583332642_ph1569135714257"><a name="zh-cn_topic_0000002583332642_ph1569135714257"></a><a name="zh-cn_topic_0000002583332642_ph1569135714257"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="zh-cn_topic_0000002583332642_p15569657112515"><a name="zh-cn_topic_0000002583332642_p15569657112515"></a><a name="zh-cn_topic_0000002583332642_p15569657112515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="zh-cn_topic_0000002583332642_p16569257142516"><a name="zh-cn_topic_0000002583332642_p16569257142516"></a><a name="zh-cn_topic_0000002583332642_p16569257142516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="zh-cn_topic_0000002583332642_p127191613267"><a name="zh-cn_topic_0000002583332642_p127191613267"></a><a name="zh-cn_topic_0000002583332642_p127191613267"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p1356945762511"><a name="zh-cn_topic_0000002583332642_p1356945762511"></a><a name="zh-cn_topic_0000002583332642_p1356945762511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="zh-cn_topic_0000002583332642_p7569135772519"><a name="zh-cn_topic_0000002583332642_p7569135772519"></a><a name="zh-cn_topic_0000002583332642_p7569135772519"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002583332642_row55691557132514"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="zh-cn_topic_0000002583332642_p195699573251"><a name="zh-cn_topic_0000002583332642_p195699573251"></a><a name="zh-cn_topic_0000002583332642_p195699573251"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_section66051714132117"></a>

启动服务并开启服务自启动。

```bash
npu-smi set -t key-manage -s start
```

```text
        Status                         : OK
        Message                        : Set key-manage start successfully
```

## 输出说明<a name="zh-cn_topic_0000001264816685_zh-cn_topic_0000001154308954_section29761716101314"></a>

**表 2**  打印信息说明

<a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p6005466"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_zh-cn_topic_0200634534_p8965319"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_zh-cn_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p36441839191318"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p36441839191318"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p36441839191318"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p104381429856"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p104381429856"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p104381429856"></a>命令执行结果。</p>
<p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1164353918134"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1164353918134"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1164353918134"></a>有如下两种状态：OK，Fail。</p>
</td>
</tr>
<tr id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_row7359205111318"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p103559511133"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p103559511133"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p103559511133"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1535515501311"><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1535515501311"></a><a name="zh-cn_topic_0000001220416506_zh-cn_topic_0000001129176320_p1535515501311"></a>命令执行后的提示信息。</p>
</td>
</tr>
</tbody>
</table>

# 查询端口的SU误码模式和误码统计结果<a name="ZH-CN_TOPIC_0000002584451422"></a>

## 产品支持情况<a name="section5790730141118"></a>

**表 1** 不同部署场景下的支持情况

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="zh-cn_topic_0000002614931227_row47351716152418"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.8.1.1"><p id="zh-cn_topic_0000002614931227_p673514162240"><a name="zh-cn_topic_0000002614931227_p673514162240"></a><a name="zh-cn_topic_0000002614931227_p673514162240"></a>硬件型号/场景</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.8.1.2"><p id="zh-cn_topic_0000002614931227_p16735101652415"><a name="zh-cn_topic_0000002614931227_p16735101652415"></a><a name="zh-cn_topic_0000002614931227_p16735101652415"></a>物理机场景（裸机）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.3"><p id="zh-cn_topic_0000002614931227_p573591614247"><a name="zh-cn_topic_0000002614931227_p573591614247"></a><a name="zh-cn_topic_0000002614931227_p573591614247"></a>物理机+特权容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.4"><p id="zh-cn_topic_0000002614931227_p1773531692413"><a name="zh-cn_topic_0000002614931227_p1773531692413"></a><a name="zh-cn_topic_0000002614931227_p1773531692413"></a>物理机+普通容器场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.5"><p id="zh-cn_topic_0000002614931227_p18735316192410"><a name="zh-cn_topic_0000002614931227_p18735316192410"></a><a name="zh-cn_topic_0000002614931227_p18735316192410"></a>直通虚拟机场景</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.1.6"><p id="zh-cn_topic_0000002614931227_p197351716162414"><a name="zh-cn_topic_0000002614931227_p197351716162414"></a><a name="zh-cn_topic_0000002614931227_p197351716162414"></a>直通虚拟机+普通容器场景</p>
</th>
</tr>
<tr id="zh-cn_topic_0000002614931227_row207354164243"><th class="cellrowborder" valign="top" id="mcps1.2.8.2.1"><p id="zh-cn_topic_0000002614931227_p157359169247"><a name="zh-cn_topic_0000002614931227_p157359169247"></a><a name="zh-cn_topic_0000002614931227_p157359169247"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.2"><p id="zh-cn_topic_0000002614931227_p2073551618243"><a name="zh-cn_topic_0000002614931227_p2073551618243"></a><a name="zh-cn_topic_0000002614931227_p2073551618243"></a>运行用户组（非root用户）</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.3"><p id="zh-cn_topic_0000002614931227_p173531617242"><a name="zh-cn_topic_0000002614931227_p173531617242"></a><a name="zh-cn_topic_0000002614931227_p173531617242"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.4"><p id="zh-cn_topic_0000002614931227_p1735191611244"><a name="zh-cn_topic_0000002614931227_p1735191611244"></a><a name="zh-cn_topic_0000002614931227_p1735191611244"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.5"><p id="zh-cn_topic_0000002614931227_p173531662414"><a name="zh-cn_topic_0000002614931227_p173531662414"></a><a name="zh-cn_topic_0000002614931227_p173531662414"></a>root用户</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.8.2.6"><p id="zh-cn_topic_0000002614931227_p0735516172410"><a name="zh-cn_topic_0000002614931227_p0735516172410"></a><a name="zh-cn_topic_0000002614931227_p0735516172410"></a>root用户</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0000002614931227_row9735101672415"><td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.1 mcps1.2.8.2.1 "><p id="zh-cn_topic_0000002614931227_p1735171610245"><a name="zh-cn_topic_0000002614931227_p1735171610245"></a><a name="zh-cn_topic_0000002614931227_p1735171610245"></a><span id="zh-cn_topic_0000002614931227_ph18735616162416"><a name="zh-cn_topic_0000002614931227_ph18735616162416"></a><a name="zh-cn_topic_0000002614931227_ph18735616162416"></a>Atlas 350 加速卡</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.2 "><p id="zh-cn_topic_0000002614931227_p19735121618246"><a name="zh-cn_topic_0000002614931227_p19735121618246"></a><a name="zh-cn_topic_0000002614931227_p19735121618246"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.2 mcps1.2.8.2.3 "><p id="zh-cn_topic_0000002614931227_p2735816172417"><a name="zh-cn_topic_0000002614931227_p2735816172417"></a><a name="zh-cn_topic_0000002614931227_p2735816172417"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.3 mcps1.2.8.2.4 "><p id="zh-cn_topic_0000002614931227_p14735116152415"><a name="zh-cn_topic_0000002614931227_p14735116152415"></a><a name="zh-cn_topic_0000002614931227_p14735116152415"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.4 mcps1.2.8.2.5 "><p id="zh-cn_topic_0000002614931227_p1973515163248"><a name="zh-cn_topic_0000002614931227_p1973515163248"></a><a name="zh-cn_topic_0000002614931227_p1973515163248"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p932658869"><a name="zh-cn_topic_0000002614931227_p932658869"></a><a name="zh-cn_topic_0000002614931227_p932658869"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="14.285714285714285%" headers="mcps1.2.8.1.6 "><p id="zh-cn_topic_0000002614931227_p1034512820618"><a name="zh-cn_topic_0000002614931227_p1034512820618"></a><a name="zh-cn_topic_0000002614931227_p1034512820618"></a>Y</p>
</td>
</tr>
<tr id="zh-cn_topic_0000002614931227_row173741602416"><td class="cellrowborder" colspan="7" valign="top" headers="mcps1.2.8.1.1 mcps1.2.8.1.2 mcps1.2.8.1.3 mcps1.2.8.1.4 mcps1.2.8.1.5 mcps1.2.8.1.6 mcps1.2.8.2.1 mcps1.2.8.2.2 mcps1.2.8.2.3 mcps1.2.8.2.4 mcps1.2.8.2.5 mcps1.2.8.2.6 "><p id="zh-cn_topic_0000002614931227_p157551311498"><a name="zh-cn_topic_0000002614931227_p157551311498"></a><a name="zh-cn_topic_0000002614931227_p157551311498"></a>注：Y表示支持；N表示不支持；NA表示不涉及，当前未规划此场景。</p>
</td>
</tr>
</tbody>
</table>

## 功能说明<a name="section957615561617"></a>

查询端口SU误码模式和误码统计结果。

## 注意事项<a name="section8415102071"></a>

无。

## 命令格式<a name="section4655161312717"></a>

```bash
hccn_tool -g -su_ber -i <dev_id> -u <udie_id> -p <port_id> [-mode_status | -result]
```

## 参数说明<a name="section107781620873"></a>

<a name="zh-cn_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="zh-cn_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="21.15%" id="mcps1.1.4.1.1"><p id="zh-cn_topic_0184799386_p1329121214558"><a name="zh-cn_topic_0184799386_p1329121214558"></a><a name="zh-cn_topic_0184799386_p1329121214558"></a>参数</p>
</th>
<th class="cellrowborder" valign="top" width="22.56%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>可选/必选</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="zh-cn_topic_0184799386_p83121275519"><a name="zh-cn_topic_0184799386_p83121275519"></a><a name="zh-cn_topic_0184799386_p83121275519"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="zh-cn_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="zh-cn_topic_0184799386_p91902281586"><a name="zh-cn_topic_0184799386_p91902281586"></a><a name="zh-cn_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p17451457141517"><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><a name="zh-cn_topic_0000002614931223_p17451457141517"></a><span id="zh-cn_topic_0000002614931223_ph13800154794716"><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a><a name="zh-cn_topic_0000002614931223_ph13800154794716"></a>软件的逻辑ID</span>。执行<strong id="zh-cn_topic_0000002614931223_b203142152219"><a name="zh-cn_topic_0000002614931223_b203142152219"></a><a name="zh-cn_topic_0000002614931223_b203142152219"></a>npu-smi info</strong>命令查询到的“NPU ID”字段值即为-i参数取值。</p>
</td>
</tr>
<tr id="zh-cn_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p145391537152415"><a name="p145391537152415"></a><a name="p145391537152415"></a>-u &lt;udie_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p20463164634118"><a name="p20463164634118"></a><a name="p20463164634118"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p16538337122410"><a name="zh-cn_topic_0000002614931223_p16538337122410"></a><a name="zh-cn_topic_0000002614931223_p16538337122410"></a>芯片UDie ID。取值：0。可通过<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令查询。</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p9451316122411"><a name="p9451316122411"></a><a name="p9451316122411"></a>-p &lt;port_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p84833461411"><a name="p84833461411"></a><a name="p84833461411"></a>必选</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="zh-cn_topic_0000002614931223_p1911115561611"><a name="zh-cn_topic_0000002614931223_p1911115561611"></a><a name="zh-cn_topic_0000002614931223_p1911115561611"></a>芯片端口ID，详见<a href="查询NPU设备信息.md">查询NPU设备信息</a>命令输出说明中的“Port ID”。</p>
</td>
</tr>
<tr id="row18231157685"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p15238575810"><a name="p15238575810"></a><a name="p15238575810"></a>-mode_status</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p523205712819"><a name="p523205712819"></a><a name="p523205712819"></a>可选，与-result二选一使用</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p11237571984"><a name="p11237571984"></a><a name="p11237571984"></a>指定时查询SU误码模式状态。</p>
</td>
</tr>
<tr id="row1713811316106"><td class="cellrowborder" valign="top" width="21.15%" headers="mcps1.1.4.1.1 "><p id="p1913812319104"><a name="p1913812319104"></a><a name="p1913812319104"></a>-result</p>
</td>
<td class="cellrowborder" valign="top" width="22.56%" headers="mcps1.1.4.1.2 "><p id="p11383341017"><a name="p11383341017"></a><a name="p11383341017"></a>可选，与-mode_status二选一使用</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p51381314101"><a name="p51381314101"></a><a name="p51381314101"></a>指定时查询SU误码统计结果。</p>
</td>
</tr>
</tbody>
</table>

## 使用示例<a name="section185511229978"></a>

- 示例1：

    ```bash
    hccn_tool -g -su_ber -i 0 -u 0 -p 4 -mode_status
    ```

    查询逻辑设备ID为0的UDie 0端口4的SU误码模式。

    ```text
    +-----+------+------+--------------+-----------+
    | NPU | UDie | Port | su_itlv_mode | status    |
    +-----+------+------+--------------+-----------+
    | 0   | 0    | 4    | non-itlv     | stop      |
    +-----+------+------+--------------+-----------+
    ```

- 示例2：

    ```bash
    hccn_tool -g -su_ber -i 0 -u 0 -p 4 -result
    ```

    查询逻辑设备ID为0的UDie 0端口4的SU误码统计结果。

    ```text
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    | NPU | UDie | Port | Lane | Done | Bit_err_cnt | Err_symb_t4 | Frm_cnt   | Frm_bit | Su_ber_rate  | Su_err_frame_rate |
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    | 0   | 0    | 4    | 0x0  | 0x1  | 0x2ea       | 0x0         | 0x8000000 | 0x400   | 5.427864e-09 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x1  | 0x1  | 0x2d8       | 0x0         | 0x8000000 | 0x400   | 5.296897e-09 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x2  | 0x1  | 0xb1c       | 0x0         | 0x8000000 | 0x400   | 2.069282e-08 | 0.000000e+00      |
    | 0   | 0    | 4    | 0x3  | 0x1  | 0x492       | 0x0         | 0x8000000 | 0x400   | 8.512870e-09 | 0.000000e+00      |
    +-----+------+------+------+------+-------------+-------------+-----------+---------+--------------+-------------------+
    ```

## 输出说明<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>字段</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>说明</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p831664130"><a name="p831664130"></a><a name="p831664130"></a>NPU</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p129921859135"><a name="p129921859135"></a><a name="p129921859135"></a><span id="ph13800154794716"><a name="ph13800154794716"></a><a name="ph13800154794716"></a>软件的逻辑ID</span>。</p>
</td>
</tr>
<tr id="row102441771424"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1724410719210"><a name="p1724410719210"></a><a name="p1724410719210"></a>UDie</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p15244471828"><a name="p15244471828"></a><a name="p15244471828"></a>芯片UDie ID。</p>
</td>
</tr>
<tr id="row1737121118214"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p337118111024"><a name="p337118111024"></a><a name="p337118111024"></a>Port</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1037111110214"><a name="p1037111110214"></a><a name="p1037111110214"></a>芯片端口号。</p>
</td>
</tr>
<tr id="row105804431624"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p155806431028"><a name="p155806431028"></a><a name="p155806431028"></a>su_itlv_mode</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1858010433218"><a name="p1858010433218"></a><a name="p1858010433218"></a>SU误码率交织模式状态，当前固定为非交织模式。</p>
<a name="ul2057074114164"></a><a name="ul2057074114164"></a><ul id="ul2057074114164"><li><span>itlv：交织模式。</span></li><li>non-itlv：非交织模式。</li></ul>
</td>
</tr>
<tr id="row9580743629"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p25801443822"><a name="p25801443822"></a><a name="p25801443822"></a>status</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p17443443171613"><a name="p17443443171613"></a><a name="p17443443171613"></a><span>端口SU误码功能配置状态：</span></p>
<a name="ul820193403715"></a><a name="ul820193403715"></a><ul id="ul820193403715"><li>tx_enable：启用发送功能。</li><li>rx_enable：启用接收功能。</li><li>stop：停止工作。</li></ul>
</td>
</tr>
<tr id="row178501240151416"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p113145619146"><a name="p113145619146"></a><a name="p113145619146"></a>Lane</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1831195617142"><a name="p1831195617142"></a><a name="p1831195617142"></a>当前结果为第几条lane的结果。</p>
</td>
</tr>
<tr id="row785194015141"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p153115618148"><a name="p153115618148"></a><a name="p153115618148"></a>Done</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p19397152962610"><a name="p19397152962610"></a><a name="p19397152962610"></a>SU误码统计结果状态：</p>
<a name="ul113353552718"></a><a name="ul113353552718"></a><ul id="ul113353552718"><li>0x0：无数据或未完成误码统计。</li><li>0x1：已完成状态。</li><li>其他：异常状态。</li></ul>
</td>
</tr>
<tr id="row138519407149"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p331115615144"><a name="p331115615144"></a><a name="p331115615144"></a>Bit_err_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p7311356151418"><a name="p7311356151418"></a><a name="p7311356151418"></a>统计SU误码数。</p>
</td>
</tr>
<tr id="row128511840141410"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p19312569149"><a name="p19312569149"></a><a name="p19312569149"></a>Err_symb_t4</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p18318561145"><a name="p18318561145"></a><a name="p18318561145"></a>统计超过4个symbol错误的SU误帧数。</p>
</td>
</tr>
<tr id="row785114403148"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p2031115617144"><a name="p2031115617144"></a><a name="p2031115617144"></a>Frm_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p2311256191414"><a name="p2311256191414"></a><a name="p2311256191414"></a>统计SU总帧数。</p>
</td>
</tr>
<tr id="row4645203712595"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p431115614141"><a name="p431115614141"></a><a name="p431115614141"></a>Frm_bit</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p23185651414"><a name="p23185651414"></a><a name="p23185651414"></a>每一帧SU误码包含的bit数。</p>
</td>
</tr>
<tr id="row119661251171514"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p23185641414"><a name="p23185641414"></a><a name="p23185641414"></a>Su_ber_rate</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1131125691418"><a name="p1131125691418"></a><a name="p1131125691418"></a>SU误码率。<span>计算公式：Bit_err_cnt / ( Frm_cnt * Frm_bit)。</span></p>
</td>
</tr>
<tr id="row771115579163"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p33115601418"><a name="p33115601418"></a><a name="p33115601418"></a>Su_err_frame_rate</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p1531185681420"><a name="p1531185681420"></a><a name="p1531185681420"></a>SU误帧率。<span>计算公式：Err_symb_t4 / Frm_cnt。</span></p>
</td>
</tr>
</tbody>
</table>

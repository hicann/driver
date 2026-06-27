# dcmiv2\_get\_computing\_power\_info<a name="EN-US_TOPIC_0000002347924037"></a>

## Prototype<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_toc533412077"></a>

**int dcmiv2\_get\_computing\_power\_info\(int dev\_id, int type, struct dsmi\_computing\_power\_info \*pcomputing\_power\)**

## Description<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_toc533412078"></a>

Queries the computing power.

## Parameter Description<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_toc533412079"></a>

<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_row7580267"><th class="cellrowborder" valign="top" width="22.25%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10021890"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10021890"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="9.77%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6466753"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6466753"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p54045009"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p54045009"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p15569626"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p15569626"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_row1155711494235"><td class="cellrowborder" valign="top" width="22.25%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p7711145152918"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p7711145152918"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p671116522914"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p671116522914"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1771116572910"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1771116572910"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_row15462171542913"><td class="cellrowborder" valign="top" width="22.25%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p42846102455"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p42846102455"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p42846102455"></a>type</p>
</td>
<td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1228461054514"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1228461054514"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1228461054514"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428471054518"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428471054518"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428471054518"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1028461016457"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1028461016457"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p1028461016457"></a>Type of computing power information.</p>
<p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6284141064515"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6284141064515"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p6284141064515"></a>The value indicates the number of AI Cores to be queried, and it supports only <strong id="b112061042319"><a name="b112061042319"></a><a name="b112061042319"></a>1</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_row677353102819"><td class="cellrowborder" valign="top" width="22.25%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p92855100450"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p92855100450"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p92855100450"></a>pcomputing_power</p>
</td>
<td class="cellrowborder" valign="top" width="9.77%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p828581054513"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p828581054513"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p828581054513"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p8285161012454"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p8285161012454"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p8285161012454"></a>struct dsmi_computing_power_info *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10285181015458"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10285181015458"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p10285181015458"></a>Computing power information. The information structure is as follows:</p>
<p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p20285141064513"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p20285141064513"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p20285141064513"></a>struct dsmi_computing_power_info {</p>
<p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p14601143103618"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p14601143103618"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p14601143103618"></a>unsigned int data1;</p>
<p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p920274512369"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p920274512369"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p920274512369"></a>unsigned int reserve[3];</p>
<p id="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428501019452"><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428501019452"></a><a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_p428501019452"></a>};</p>
<p id="p17747184917113"><a name="p17747184917113"></a><a name="p17747184917113"></a>When <strong id="b137713243714"><a name="b137713243714"></a><a name="b137713243714"></a>type</strong> is set to <strong id="b1277162420714"><a name="b1277162420714"></a><a name="b1277162420714"></a>NPU_TYPE</strong>, that is, <strong id="b478024973"><a name="b478024973"></a><a name="b478024973"></a>1</strong>, <strong id="b27852413715"><a name="b27852413715"></a><a name="b27852413715"></a>data1</strong> indicates the number of AI Cores.</p>
</td>
</tr>
</tbody>
</table>

## Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>

<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002348043941_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002348043941_b16147213413"><a name="en-us_topic_0000002348043941_b16147213413"></a><a name="en-us_topic_0000002348043941_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return_codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

## Restrictions<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_toc533412082"></a>

**Table  1** Support in different deployment scenarios

<a name="table116394134134"></a>
<table><thead align="left"><tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row119194469302"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_p67828402447"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002347924121_p65514914017"><a name="en-us_topic_0000002347924121_p65514914017"></a><a name="en-us_topic_0000002347924121_p65514914017"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002347924121_p56108061"><a name="en-us_topic_0000002347924121_p56108061"></a><a name="en-us_topic_0000002347924121_p56108061"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002347924121_p1855189908"><a name="en-us_topic_0000002347924121_p1855189908"></a><a name="en-us_topic_0000002347924121_p1855189908"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002347924121_p10771327123917"><a name="en-us_topic_0000002347924121_p10771327123917"></a><a name="en-us_topic_0000002347924121_p10771327123917"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_row116673024514"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p792013462306"></a><strong id="en-us_topic_0000002347924121_b5395653155415"><a name="en-us_topic_0000002347924121_b5395653155415"></a><a name="en-us_topic_0000002347924121_b5395653155415"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p16920346133016"></a>Running User Group (Non-<strong id="en-us_topic_0000002347924121_b16340205411546"><a name="en-us_topic_0000002347924121_b16340205411546"></a><a name="en-us_topic_0000002347924121_b16340205411546"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002347924121_p56110815619"><a name="en-us_topic_0000002347924121_p56110815619"></a><a name="en-us_topic_0000002347924121_p56110815619"></a><strong id="en-us_topic_0000002347924121_b1325919551546"><a name="en-us_topic_0000002347924121_b1325919551546"></a><a name="en-us_topic_0000002347924121_b1325919551546"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><a name="en-us_topic_0000002347924121_en-us_topic_0000002347924121_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p166440421324"></a><strong id="en-us_topic_0000002347924121_b7873135516543"><a name="en-us_topic_0000002347924121_b7873135516543"></a><a name="en-us_topic_0000002347924121_b7873135516543"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002347924121_p977116273398"><a name="en-us_topic_0000002347924121_p977116273398"></a><a name="en-us_topic_0000002347924121_p977116273398"></a><strong id="en-us_topic_0000002347924121_b868415562549"><a name="en-us_topic_0000002347924121_b868415562549"></a><a name="en-us_topic_0000002347924121_b868415562549"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002347924121_row57331624612"><td class="cellrowborder" valign="top" width="18.47630473905219%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002347924121_p144147361596"><a name="en-us_topic_0000002347924121_p144147361596"></a><a name="en-us_topic_0000002347924121_p144147361596"></a><span id="en-us_topic_0000002347924121_ph12140626193614"><a name="en-us_topic_0000002347924121_ph12140626193614"></a><a name="en-us_topic_0000002347924121_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="14.857028594281147%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002347924121_p13356146465"><a name="en-us_topic_0000002347924121_p13356146465"></a><a name="en-us_topic_0000002347924121_p13356146465"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002347924121_p19351314124620"><a name="en-us_topic_0000002347924121_p19351314124620"></a><a name="en-us_topic_0000002347924121_p19351314124620"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002347924121_p1577514751713"><a name="en-us_topic_0000002347924121_p1577514751713"></a><a name="en-us_topic_0000002347924121_p1577514751713"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p1435121434611"><a name="en-us_topic_0000002347924121_p1435121434611"></a><a name="en-us_topic_0000002347924121_p1435121434611"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002347924121_p8318151920427"><a name="en-us_topic_0000002347924121_p8318151920427"></a><a name="en-us_topic_0000002347924121_p8318151920427"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002347924121_row165961813903"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002347924121_p56258171305"><a name="en-us_topic_0000002347924121_p56258171305"></a><a name="en-us_topic_0000002347924121_p56258171305"></a><span id="en-us_topic_0000002347924121_ph15391145912019"><a name="en-us_topic_0000002347924121_ph15391145912019"></a><a name="en-us_topic_0000002347924121_ph15391145912019"></a>Note: <strong id="en-us_topic_0000002347924121_b94410119553"><a name="en-us_topic_0000002347924121_b94410119553"></a><a name="en-us_topic_0000002347924121_b94410119553"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002347924121_b204410113551"><a name="en-us_topic_0000002347924121_b204410113551"></a><a name="en-us_topic_0000002347924121_b204410113551"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002347924121_b15441911550"><a name="en-us_topic_0000002347924121_b15441911550"></a><a name="en-us_topic_0000002347924121_b15441911550"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001206147252_en-us_topic_0000001223292873_en-us_topic_0000001148450137_toc533412083"></a>

```c
...
int ret = 0;
int dev_id = 0;
struct dsmi_computing_power_info computing_power = {0};
int type = 1;
ret = dcmiv2_get_computing_power_info(dev_id, type, &computing_power);
if (ret != 0){
    // TODO: Record logs.
    return ret;
}
...
```

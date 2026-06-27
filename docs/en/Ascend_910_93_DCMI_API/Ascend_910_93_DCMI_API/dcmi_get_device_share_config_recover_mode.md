# dcmi\_get\_device\_share\_config\_recover\_mode<a name="EN-US_TOPIC_0000002515510534"></a>

**Prototype<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_toc533412077"></a>**

**int dcmi\_get\_device\_share\_config\_recover\_mode\(unsigned int \*enable\_flag\)**

**Description<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_toc533412078"></a>**

Querying the Enable Status of Persistent Container Sharing

**Parameter Description<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_toc533412079"></a>**

<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p10021890"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p10021890"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="15.02%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p6466753"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p6466753"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="17.98%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p54045009"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p54045009"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p15569626"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p15569626"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_row189061455124014"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p3873105644017"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p3873105644017"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p3873105644017"></a>enable_flag</p>
</td>
<td class="cellrowborder" valign="top" width="15.02%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p12873105644020"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p12873105644020"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p12873105644020"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="17.98%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p1187365654013"><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p1187365654013"></a><a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_p1187365654013"></a>int *</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002372934453_p2751111174515"><a name="en-us_topic_0000002372934453_p2751111174515"></a><a name="en-us_topic_0000002372934453_p2751111174515"></a>Enables or disables persistent container sharing. The value can be <strong id="b2056508281738"><a name="b2056508281738"></a><a name="b2056508281738"></a>0</strong> (default) or <strong id="b141522402481738"><a name="b141522402481738"></a><a name="b141522402481738"></a>1</strong>.</p>
<a name="ul0243176198"></a><a name="ul0243176198"></a><ul id="ul0243176198"><li><strong id="b203660829281738"><a name="b203660829281738"></a><a name="b203660829281738"></a>1</strong>: enabled</li><li><strong id="b174865990081738"><a name="b174865990081738"></a><a name="b174865990081738"></a>0</strong>: disabled</li></ul>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000002372934453_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000002546910411_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="en-us_topic_0000002546910411_b16147213413"><a name="en-us_topic_0000002546910411_b16147213413"></a><a name="en-us_topic_0000002546910411_b16147213413"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000002372934453_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None

**Restrictions<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_toc533412082"></a>**

- After the container sharing mode is set, enabling the persistence function ensures the container status remains unchanged after a system restart.
- This API can be used in the PM + privileged container scenario.

**Table  1** Support in different deployment scenarios

<a name="en-us_topic_0000002372935233_table1997161105818"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515350556_row163024263717"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515350556_p1830164223716"><a name="en-us_topic_0000002515350556_p1830164223716"></a><a name="en-us_topic_0000002515350556_p1830164223716"></a>Product Model</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515350556_p12302042193720"><a name="en-us_topic_0000002515350556_p12302042193720"></a><a name="en-us_topic_0000002515350556_p12302042193720"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515350556_p103034212370"><a name="en-us_topic_0000002515350556_p103034212370"></a><a name="en-us_topic_0000002515350556_p103034212370"></a>PM + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002515350556_row1330184219373"><th class="cellrowborder" valign="top" id="mcps1.2.5.2.1"><p id="en-us_topic_0000002515350556_p173034210371"><a name="en-us_topic_0000002515350556_p173034210371"></a><a name="en-us_topic_0000002515350556_p173034210371"></a>Root User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.2"><p id="en-us_topic_0000002515350556_p1930842133711"><a name="en-us_topic_0000002515350556_p1930842133711"></a><a name="en-us_topic_0000002515350556_p1930842133711"></a>Running User Group (Non-root User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.5.2.3"><p id="en-us_topic_0000002515350556_p330194283713"><a name="en-us_topic_0000002515350556_p330194283713"></a><a name="en-us_topic_0000002515350556_p330194283713"></a>Root User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515350556_row1030104243717"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p1830184219376"><a name="en-us_topic_0000002515350556_p1830184219376"></a><a name="en-us_topic_0000002515350556_p1830184219376"></a><span id="en-us_topic_0000002515350556_text83017424375"><a name="en-us_topic_0000002515350556_text83017424375"></a><a name="en-us_topic_0000002515350556_text83017424375"></a>Atlas 900 A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p130242163712"><a name="en-us_topic_0000002515350556_p130242163712"></a><a name="en-us_topic_0000002515350556_p130242163712"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p9487578148"><a name="en-us_topic_0000002515350556_p9487578148"></a><a name="en-us_topic_0000002515350556_p9487578148"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1026715119156"><a name="en-us_topic_0000002515350556_p1026715119156"></a><a name="en-us_topic_0000002515350556_p1026715119156"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row10308422379"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p12301642143712"><a name="en-us_topic_0000002515350556_p12301642143712"></a><a name="en-us_topic_0000002515350556_p12301642143712"></a><span id="en-us_topic_0000002515350556_text1930114213371"><a name="en-us_topic_0000002515350556_text1930114213371"></a><a name="en-us_topic_0000002515350556_text1930114213371"></a>Atlas 9000 A3 SuperPoD Cluster Computing System</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p03034253714"><a name="en-us_topic_0000002515350556_p03034253714"></a><a name="en-us_topic_0000002515350556_p03034253714"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p6481457181412"><a name="en-us_topic_0000002515350556_p6481457181412"></a><a name="en-us_topic_0000002515350556_p6481457181412"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p32683118153"><a name="en-us_topic_0000002515350556_p32683118153"></a><a name="en-us_topic_0000002515350556_p32683118153"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row14661158135410"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p23113818160"><a name="en-us_topic_0000002515350556_p23113818160"></a><a name="en-us_topic_0000002515350556_p23113818160"></a><span id="en-us_topic_0000002515350556_text12311789168"><a name="en-us_topic_0000002515350556_text12311789168"></a><a name="en-us_topic_0000002515350556_text12311789168"></a>Atlas 800T A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p653191095518"><a name="en-us_topic_0000002515350556_p653191095518"></a><a name="en-us_topic_0000002515350556_p653191095518"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p18531101018557"><a name="en-us_topic_0000002515350556_p18531101018557"></a><a name="en-us_topic_0000002515350556_p18531101018557"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p85319108552"><a name="en-us_topic_0000002515350556_p85319108552"></a><a name="en-us_topic_0000002515350556_p85319108552"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row19188145615284"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p111821034299"><a name="en-us_topic_0000002515350556_p111821034299"></a><a name="en-us_topic_0000002515350556_p111821034299"></a><span id="en-us_topic_0000002515350556_text11821030299"><a name="en-us_topic_0000002515350556_text11821030299"></a><a name="en-us_topic_0000002515350556_text11821030299"></a>Atlas 800I A3 SuperPoD</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p1365116614298"><a name="en-us_topic_0000002515350556_p1365116614298"></a><a name="en-us_topic_0000002515350556_p1365116614298"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p10651186172913"><a name="en-us_topic_0000002515350556_p10651186172913"></a><a name="en-us_topic_0000002515350556_p10651186172913"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p14651176142917"><a name="en-us_topic_0000002515350556_p14651176142917"></a><a name="en-us_topic_0000002515350556_p14651176142917"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1472160165512"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 mcps1.2.5.2.1 "><p id="en-us_topic_0000002515350556_p134575595519"><a name="en-us_topic_0000002515350556_p134575595519"></a><a name="en-us_topic_0000002515350556_p134575595519"></a><span id="en-us_topic_0000002515350556_text5457657553"><a name="en-us_topic_0000002515350556_text5457657553"></a><a name="en-us_topic_0000002515350556_text5457657553"></a>A200T A3 Box8 SuperPoD server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.2 "><p id="en-us_topic_0000002515350556_p71421111559"><a name="en-us_topic_0000002515350556_p71421111559"></a><a name="en-us_topic_0000002515350556_p71421111559"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p8141511165511"><a name="en-us_topic_0000002515350556_p8141511165511"></a><a name="en-us_topic_0000002515350556_p8141511165511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515350556_p1914171165517"><a name="en-us_topic_0000002515350556_p1914171165517"></a><a name="en-us_topic_0000002515350556_p1914171165517"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002515350556_row1983816248811"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.2.1 mcps1.2.5.2.2 mcps1.2.5.2.3 "><p id="en-us_topic_0000002515350556_p1172291987"><a name="en-us_topic_0000002515350556_p1172291987"></a><a name="en-us_topic_0000002515350556_p1172291987"></a>Note: <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b130904228481512"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b200767006881512"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a><a name="en-us_topic_0000002515350556_en-us_topic_0000002515350556_b90682012381512"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000002372934453_en-us_topic_0000001251227179_en-us_topic_0000001223292897_en-us_topic_0000001101830678_toc533412083"></a>**

```c
...
int ret = 0;
int enable_flag = -1;
ret = dcmi_get_device_share_config_recover_mode(&enable_flag);
if (ret != 0) {
    // todo: Record logs.
    return ret;
}
...
```

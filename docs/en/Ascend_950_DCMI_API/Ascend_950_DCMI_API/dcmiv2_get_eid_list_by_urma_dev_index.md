# dcmiv2\_get\_eid\_list\_by\_urma\_dev\_index<a name="EN-US_TOPIC_0000002487017104"></a>

## Prototype<a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_toc533412077"></a>

**int dcmiv2\_get\_eid\_list\_by\_urma\_dev\_index\(int dev\_id, unsigned int dev\_index, dcmi\_urma\_eid\_info\_t \*eid\_list, unsigned int \*eid\_cnt\)**

## Description<a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_toc533412078"></a>

Obtains the entity ID \(EID\) list of a URMA device on a chip.

## Parameter Description<a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_toc533412079"></a>

<a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p10021890"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p10021890"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p6466753"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p6466753"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p54045009"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p54045009"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p15569626"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p15569626"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_row1155711494235"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p7711145152918"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p7711145152918"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p7711145152918"></a>dev_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p671116522914"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p671116522914"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p671116522914"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p1771116572910"><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p1771116572910"></a><a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_p1771116572910"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="en-us_topic_0000002348043873_p1761223114720"><a name="en-us_topic_0000002348043873_p1761223114720"></a><a name="en-us_topic_0000002348043873_p1761223114720"></a><span id="en-us_topic_0000002348043873_ph1263073113614"><a name="en-us_topic_0000002348043873_ph1263073113614"></a><a name="en-us_topic_0000002348043873_ph1263073113614"></a>Logical ID of the software</span>, which can be obtained by calling <a href="dcmiv2_get_device_list.md">dcmiv2_get_device_list</a>. Value range: [0, <strong id="en-us_topic_0000002348043873_b12326105411295"><a name="en-us_topic_0000002348043873_b12326105411295"></a><a name="en-us_topic_0000002348043873_b12326105411295"></a>device_cnt</strong> – 1]</p>
</td>
</tr>
<tr id="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_row15462171542913"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p22401876345"><a name="p22401876345"></a><a name="p22401876345"></a>dev_index</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p18431094340"><a name="p18431094340"></a><a name="p18431094340"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p178437914346"><a name="p178437914346"></a><a name="p178437914346"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p184269133419"><a name="p184269133419"></a><a name="p184269133419"></a>URMA device ID, which is obtained by calling <a href="dcmiv2_get_urma_device_cnt.md">dcmiv2_get_urma_device_cnt</a>. The value range is [0, <strong id="b10667191205914"><a name="b10667191205914"></a><a name="b10667191205914"></a>dev_cnt</strong> – 1].</p>
</td>
</tr>
<tr id="row195541512113415"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p95544125343"><a name="p95544125343"></a><a name="p95544125343"></a>eid_list</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p12554712163413"><a name="p12554712163413"></a><a name="p12554712163413"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p1554212183419"><a name="p1554212183419"></a><a name="p1554212183419"></a>dcmi_urma_eid_info_t<strong id="b2317135710388"><a name="b2317135710388"></a><a name="b2317135710388"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p195541012143416"><a name="p195541012143416"></a><a name="p195541012143416"></a>EID list of the URMA device. The maximum length is 32 EIDs.</p>
<p id="p6916182711502"><a name="p6916182711502"></a><a name="p6916182711502"></a>The information structure dcmi_urma_eid_info_t is defined as follows:</p>
<p id="p1998817537499"><a name="p1998817537499"></a><a name="p1998817537499"></a>#define DCMI_URMA_EID_SIZE (16)</p>
<p id="p1598818535496"><a name="p1598818535496"></a><a name="p1598818535496"></a>#define DCMI_URMA_EID_MAX_COUNT (32)</p>
<p id="p49882533498"><a name="p49882533498"></a><a name="p49882533498"></a>typedef union dcmi_urma_eid {</p>
<p id="p129881953114911"><a name="p129881953114911"></a><a name="p129881953114911"></a>unsigned char raw[DCMI_URMA_EID_SIZE]; /* Complete and unresolved EID */</p>
<p id="p2988185310490"><a name="p2988185310490"></a><a name="p2988185310490"></a>struct {</p>
<p id="p598845319497"><a name="p598845319497"></a><a name="p598845319497"></a>unsigned long reserved;          /* If IPv4 mapped to IPv6, == 0 */</p>
<p id="p498825317498"><a name="p498825317498"></a><a name="p498825317498"></a>unsigned int prefix;        /* If IPv4 mapped to IPv6, == 0x0000ffff */</p>
<p id="p129884532493"><a name="p129884532493"></a><a name="p129884532493"></a>unsigned int addr;          /* If IPv4 mapped to IPv6, == IPv4 addr */</p>
<p id="p179881553124915"><a name="p179881553124915"></a><a name="p179881553124915"></a>} in4;          /* Parse the EID as an IPv4 address. */</p>
<p id="p59882535498"><a name="p59882535498"></a><a name="p59882535498"></a>struct {</p>
<p id="p1698813535493"><a name="p1698813535493"></a><a name="p1698813535493"></a>unsigned long subnet_prefix;</p>
<p id="p5988175334917"><a name="p5988175334917"></a><a name="p5988175334917"></a>unsigned long interface_id;</p>
<p id="p1098855324912"><a name="p1098855324912"></a><a name="p1098855324912"></a>} in6;          /* Parse the EID as an IPv6 address. */</p>
<p id="p8988185313494"><a name="p8988185313494"></a><a name="p8988185313494"></a>} dcmi_urma_eid_t;</p>
<p id="p19988253124914"><a name="p19988253124914"></a><a name="p19988253124914"></a>typedef struct dcmi_urma_eid_info {</p>
<p id="p1398819535492"><a name="p1398819535492"></a><a name="p1398819535492"></a>dcmi_urma_eid_t eid;</p>
<p id="p14988175354919"><a name="p14988175354919"></a><a name="p14988175354919"></a>unsigned int eid_index;</p>
<p id="p16988953154920"><a name="p16988953154920"></a><a name="p16988953154920"></a>} dcmi_urma_eid_info_t;</p>
</td>
</tr>
<tr id="row18938914193419"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1938414193411"><a name="p1938414193411"></a><a name="p1938414193411"></a>eid_cnt</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p993891403414"><a name="p993891403414"></a><a name="p993891403414"></a>Input/Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p2938914103419"><a name="p2938914103419"></a><a name="p2938914103419"></a>unsigned int<strong id="b10841512153912"><a name="b10841512153912"></a><a name="b10841512153912"></a> *</strong></p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><a name="ul1948102514227"></a><a name="ul1948102514227"></a><ul id="ul1948102514227"><li>Input: length of the EID list. The maximum length is 32 EIDs.</li><li>Output: number of EIDs of the URMA device.</li></ul>
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

## Restrictions<a name="section123251041142612"></a>

**Table  1** Support in different deployment scenarios

<a name="table1891871242416"></a>
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

## Example<a name="en-us_topic_0000001251227173_en-us_topic_0000001223292889_en-us_topic_0000001147723703_toc533412083"></a>

```c
...
int ret;
int dev_id = 0;
unsigned int dev_cnt = 0;
dcmi_urma_eid_info_t eid_list = {0};
unsigned int eid_cnt = 0;
unsigned int i;
ret = dcmiv2_get_urma_device_cnt(dev_id, &dev_cnt);
for (i = 0; i < dev_cnt; i++) {
ret = dcmiv2_get_eid_list_by_urma_dev_index(dev_id, i, &eid_list, &eid_cnt);
}
...
```

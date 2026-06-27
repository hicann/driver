# dcmi\_get\_multi\_ecc\_record\_info<a name="EN-US_TOPIC_0000002515343862"></a>

**Prototype<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412077"></a>**

**int dcmi\_get\_multi\_ecc\_record\_info\(int card\_id, unsigned int \*ecc\_count, unsigned char read\_type, unsigned char module\_type, struct dcmi\_ecc\_common\_data \*ecc\_common\_data\_s\)**

**Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412078"></a>**

Queries detailed ECC address information of the on-chip memory.

**Parameter Description<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412079"></a>**

<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_table10480683"></a>
<table><thead align="left"><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row7580267"><th class="cellrowborder" valign="top" width="17%" id="mcps1.1.5.1.1"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p10021890"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="16.99%" id="mcps1.1.5.1.2"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p6466753"></a>Input/Output</p>
</th>
<th class="cellrowborder" valign="top" width="16.009999999999998%" id="mcps1.1.5.1.3"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p54045009"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.5.1.4"><p id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a><a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_p15569626"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_row5908907"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p1290353951711"><a name="p1290353951711"></a><a name="p1290353951711"></a>card_id</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p13903193920176"><a name="p13903193920176"></a><a name="p13903193920176"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p09048390172"><a name="p09048390172"></a><a name="p09048390172"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p119041539161713"><a name="p119041539161713"></a><a name="p119041539161713"></a>Device ID. The supported IDs can be obtained by calling <strong id="b1643216855102833"><a name="b1643216855102833"></a><a name="b1643216855102833"></a>dcmi_get_card_list</strong>.</p>
</td>
</tr>
<tr id="row3769175031212"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p290453920178"><a name="p290453920178"></a><a name="p290453920178"></a>ecc_count</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p20904139131716"><a name="p20904139131716"></a><a name="p20904139131716"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p890483961710"><a name="p890483961710"></a><a name="p890483961710"></a>unsigned int</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1590417394179"><a name="p1590417394179"></a><a name="p1590417394179"></a>Number of ECC errors in the on-chip memory.</p>
</td>
</tr>
<tr id="row5354192415172"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p109041392173"><a name="p109041392173"></a><a name="p109041392173"></a>read_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p11904193910179"><a name="p11904193910179"></a><a name="p11904193910179"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p190403981714"><a name="p190403981714"></a><a name="p190403981714"></a>unsigned char</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p1090443913175"><a name="p1090443913175"></a><a name="p1090443913175"></a>enum ECC_INFO_READ {</p>
<p id="p890453911176"><a name="p890453911176"></a><a name="p890453911176"></a>MULTI_ECC_TIMES_READ = 0, // Obtain the number of multi-bit errors.</p>
<p id="p5904113931711"><a name="p5904113931711"></a><a name="p5904113931711"></a>SINGLE_ECC_INFO_READ, // Obtain single-bit error information.</p>
<p id="p29041639111712"><a name="p29041639111712"></a><a name="p29041639111712"></a>MULTI_ECC_INFO_READ, // Obtain multi-bit error information.</p>
<p id="p1190463917174"><a name="p1190463917174"></a><a name="p1190463917174"></a>ECC_ADDRESS_COUNT_READ, // Count of ECC error addresses</p>
<p id="p190412393172"><a name="p190412393172"></a><a name="p190412393172"></a>ECC_MAX_READ_CMD</p>
<p id="p3904183912173"><a name="p3904183912173"></a><a name="p3904183912173"></a>};</p>
<p id="p490433919175"><a name="p490433919175"></a><a name="p490433919175"></a>Only <strong id="b20456157133720"><a name="b20456157133720"></a><a name="b20456157133720"></a>SINGLE_ECC_INFO_READ</strong> and <strong id="b8456657103715"><a name="b8456657103715"></a><a name="b8456657103715"></a>MULTI_ECC_INFO_READ</strong> are supported.</p>
</td>
</tr>
<tr id="row235462418176"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p14904153941719"><a name="p14904153941719"></a><a name="p14904153941719"></a>module_type</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p1990483951716"><a name="p1990483951716"></a><a name="p1990483951716"></a>Input</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p139041739131716"><a name="p139041739131716"></a><a name="p139041739131716"></a>unsigned char</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p090453951716"><a name="p090453951716"></a><a name="p090453951716"></a>enum dcmi_device_type {</p>
<p id="p14904193918170"><a name="p14904193918170"></a><a name="p14904193918170"></a>DCMI_DEVICE_TYPE_DDR,</p>
<p id="p20904143991715"><a name="p20904143991715"></a><a name="p20904143991715"></a>DCMI_DEVICE_TYPE_SRAM,</p>
<p id="p1190415391179"><a name="p1190415391179"></a><a name="p1190415391179"></a>DCMI_DEVICE_TYPE_HBM,</p>
<p id="p09045391173"><a name="p09045391173"></a><a name="p09045391173"></a>DCMI_DEVICE_TYPE_NPU,</p>
<p id="p149042039201715"><a name="p149042039201715"></a><a name="p149042039201715"></a>DCMI_HBM_RECORDED_SINGLE_ADDR,</p>
<p id="p16904143919177"><a name="p16904143919177"></a><a name="p16904143919177"></a>DCMI_HBM_RECORDED_MULTI_ADDR,</p>
<p id="p109040399177"><a name="p109040399177"></a><a name="p109040399177"></a>DCMI_DEVICE_TYPE_NONE = 0xff</p>
<p id="p13904113919177"><a name="p13904113919177"></a><a name="p13904113919177"></a>};</p>
<p id="p1904939181714"><a name="p1904939181714"></a><a name="p1904939181714"></a>Only <strong id="b23448478811429"><a name="b23448478811429"></a><a name="b23448478811429"></a>DCMI_DEVICE_TYPE_HBM</strong> (on-chip memory) is supported.</p>
</td>
</tr>
<tr id="row17872102918170"><td class="cellrowborder" valign="top" width="17%" headers="mcps1.1.5.1.1 "><p id="p19904203912178"><a name="p19904203912178"></a><a name="p19904203912178"></a>ecc_common_data_s</p>
</td>
<td class="cellrowborder" valign="top" width="16.99%" headers="mcps1.1.5.1.2 "><p id="p11905183919178"><a name="p11905183919178"></a><a name="p11905183919178"></a>Output</p>
</td>
<td class="cellrowborder" valign="top" width="16.009999999999998%" headers="mcps1.1.5.1.3 "><p id="p15905173919174"><a name="p15905173919174"></a><a name="p15905173919174"></a>struct dcmi_ecc_common_data</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.5.1.4 "><p id="p39051339171712"><a name="p39051339171712"></a><a name="p39051339171712"></a>struct dcmi_ecc_common_data {</p>
<p id="p29051339171711"><a name="p29051339171711"></a><a name="p29051339171711"></a>unsigned long long physical_addr; // Physical address</p>
<p id="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p13905133961716"><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p13905133961716"></a><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p13905133961716"></a>unsigned int stack_pc_id; //hbmc_id</p>
<p id="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p290523918173"><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p290523918173"></a><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p290523918173"></a>unsigned int reg_addr_h; // Row and column information of the register</p>
<p id="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p1390515396174"><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p1390515396174"></a><a name="en-us_topic_0000001734771165_en-us_topic_0000001666318140_en-us_topic_0000001662531202_p1390515396174"></a>unsigned int reg_addr_l; // SID bank information</p>
<p id="p11905123914170"><a name="p11905123914170"></a><a name="p11905123914170"></a>unsigned int ecc_count; // ECC count</p>
<p id="p09051339191714"><a name="p09051339191714"></a><a name="p09051339191714"></a>int timestamp; // ECC occurrence time</p>
<p id="p10905339161719"><a name="p10905339161719"></a><a name="p10905339161719"></a>};</p>
</td>
</tr>
</tbody>
</table>

**Return Value<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_section1256282115569"></a>**

<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_table19654399"></a>
<table><thead align="left"><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row59025204"><th class="cellrowborder" valign="top" width="24.18%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p16312252"></a>Type</p>
</th>
<th class="cellrowborder" valign="top" width="75.82%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p46224020"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_row13362997"><td class="cellrowborder" valign="top" width="24.18%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p8661001"></a>int</p>
</td>
<td class="cellrowborder" valign="top" width="75.82%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_p79561110476"></a>Results:</p>
<a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><a name="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"></a><ul id="en-us_topic_0000001917887173_en-us_topic_0000001251227149_en-us_topic_0000001178213202_en-us_topic_0000001097675636_en-us_topic_0000001170223803_en-us_topic_0160151812_ul55711364478"><li>Success: The value <strong id="b207134697585623"><a name="b207134697585623"></a><a name="b207134697585623"></a>0</strong> is returned.</li><li>Failure: For details about the return codes, see <a href="return-codes.md">Return Codes</a>.</li></ul>
</td>
</tr>
</tbody>
</table>

**Exception Handling<a name="en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_toc533412081"></a>**

None.

**Restrictions<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412082"></a>**

**Table  1** Support in different deployment scenarios

<a name="table1113417173519"></a>
<table><thead align="left"><tr id="en-us_topic_0000002515503852_row1548132517501"><th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.1"><p id="en-us_topic_0000002515503852_p16154843125019"><a name="en-us_topic_0000002515503852_p16154843125019"></a><a name="en-us_topic_0000002515503852_p16154843125019"></a>Product Model</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.2"><p id="en-us_topic_0000002515503852_p3123182915595"><a name="en-us_topic_0000002515503852_p3123182915595"></a><a name="en-us_topic_0000002515503852_p3123182915595"></a><strong id="en-us_topic_0000002515503852_b181336402033"><a name="en-us_topic_0000002515503852_b181336402033"></a><a name="en-us_topic_0000002515503852_b181336402033"></a>root</strong> User in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.3"><p id="en-us_topic_0000002515503852_p6271950600"><a name="en-us_topic_0000002515503852_p6271950600"></a><a name="en-us_topic_0000002515503852_p6271950600"></a>Running User Group (Non-<strong id="en-us_topic_0000002515503852_b56571847339"><a name="en-us_topic_0000002515503852_b56571847339"></a><a name="en-us_topic_0000002515503852_b56571847339"></a>root</strong> User) in PM (Bare Metal) Scenarios</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.2.5.1.4"><p id="en-us_topic_0000002515503852_p41541743195013"><a name="en-us_topic_0000002515503852_p41541743195013"></a><a name="en-us_topic_0000002515503852_p41541743195013"></a><strong id="en-us_topic_0000002515503852_b6856448332"><a name="en-us_topic_0000002515503852_b6856448332"></a><a name="en-us_topic_0000002515503852_b6856448332"></a>root</strong> User in PM + Unprivileged Container Scenarios</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row18920204653019"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p19444162914516"><a name="en-us_topic_0000002515503852_p19444162914516"></a><a name="en-us_topic_0000002515503852_p19444162914516"></a><span id="en-us_topic_0000002515503852_ph1944412296514"><a name="en-us_topic_0000002515503852_ph1944412296514"></a><a name="en-us_topic_0000002515503852_ph1944412296514"></a><span id="en-us_topic_0000002515503852_text944432913516"><a name="en-us_topic_0000002515503852_text944432913516"></a><a name="en-us_topic_0000002515503852_text944432913516"></a>Atlas 900 A2 PoD cluster basic unit</span></span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p162792612478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p172742619478"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a><a name="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_p527162654713"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_en-us_topic_0000001917887173_en-us_topic_0000001206627196_en-us_topic_0000001178213188_en-us_topic_0000001146459833_row6920114611302"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p194441629165117"><a name="en-us_topic_0000002515503852_p194441629165117"></a><a name="en-us_topic_0000002515503852_p194441629165117"></a><span id="en-us_topic_0000002515503852_text124449291511"><a name="en-us_topic_0000002515503852_text124449291511"></a><a name="en-us_topic_0000002515503852_text124449291511"></a>Atlas 800T A2 training server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p461320458219"><a name="en-us_topic_0000002515503852_p461320458219"></a><a name="en-us_topic_0000002515503852_p461320458219"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p13613134519220"><a name="en-us_topic_0000002515503852_p13613134519220"></a><a name="en-us_topic_0000002515503852_p13613134519220"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p96133454211"><a name="en-us_topic_0000002515503852_p96133454211"></a><a name="en-us_topic_0000002515503852_p96133454211"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row14873174604910"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p10444329155118"><a name="en-us_topic_0000002515503852_p10444329155118"></a><a name="en-us_topic_0000002515503852_p10444329155118"></a><span id="en-us_topic_0000002515503852_text1044482925119"><a name="en-us_topic_0000002515503852_text1044482925119"></a><a name="en-us_topic_0000002515503852_text1044482925119"></a>Atlas 800I A2 inference server</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p896391111511"><a name="en-us_topic_0000002515503852_p896391111511"></a><a name="en-us_topic_0000002515503852_p896391111511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p119682011105113"><a name="en-us_topic_0000002515503852_p119682011105113"></a><a name="en-us_topic_0000002515503852_p119682011105113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p11975911195114"><a name="en-us_topic_0000002515503852_p11975911195114"></a><a name="en-us_topic_0000002515503852_p11975911195114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row23051923114915"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p174441129175117"><a name="en-us_topic_0000002515503852_p174441129175117"></a><a name="en-us_topic_0000002515503852_p174441129175117"></a><span id="en-us_topic_0000002515503852_text34441729175119"><a name="en-us_topic_0000002515503852_text34441729175119"></a><a name="en-us_topic_0000002515503852_text34441729175119"></a>Atlas 200T A2 Box16 heterogeneous subrack</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1298231135114"><a name="en-us_topic_0000002515503852_p1298231135114"></a><a name="en-us_topic_0000002515503852_p1298231135114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1298921117511"><a name="en-us_topic_0000002515503852_p1298921117511"></a><a name="en-us_topic_0000002515503852_p1298921117511"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p1799561165114"><a name="en-us_topic_0000002515503852_p1799561165114"></a><a name="en-us_topic_0000002515503852_p1799561165114"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row44814564912"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1044414295516"><a name="en-us_topic_0000002515503852_p1044414295516"></a><a name="en-us_topic_0000002515503852_p1044414295516"></a><span id="en-us_topic_0000002515503852_text44441829105114"><a name="en-us_topic_0000002515503852_text44441829105114"></a><a name="en-us_topic_0000002515503852_text44441829105114"></a>A200I A2 Box heterogeneous component</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p17181285116"><a name="en-us_topic_0000002515503852_p17181285116"></a><a name="en-us_topic_0000002515503852_p17181285116"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p15131255114"><a name="en-us_topic_0000002515503852_p15131255114"></a><a name="en-us_topic_0000002515503852_p15131255114"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p15917127513"><a name="en-us_topic_0000002515503852_p15917127513"></a><a name="en-us_topic_0000002515503852_p15917127513"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row11171321114917"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p94441829165113"><a name="en-us_topic_0000002515503852_p94441829165113"></a><a name="en-us_topic_0000002515503852_p94441829165113"></a><span id="en-us_topic_0000002515503852_text16445122985112"><a name="en-us_topic_0000002515503852_text16445122985112"></a><a name="en-us_topic_0000002515503852_text16445122985112"></a>A300I A2 inference card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p01211275113"><a name="en-us_topic_0000002515503852_p01211275113"></a><a name="en-us_topic_0000002515503852_p01211275113"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p916161212512"><a name="en-us_topic_0000002515503852_p916161212512"></a><a name="en-us_topic_0000002515503852_p916161212512"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p191911211511"><a name="en-us_topic_0000002515503852_p191911211511"></a><a name="en-us_topic_0000002515503852_p191911211511"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row18385115320492"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.1 "><p id="en-us_topic_0000002515503852_p1644572918513"><a name="en-us_topic_0000002515503852_p1644572918513"></a><a name="en-us_topic_0000002515503852_p1644572918513"></a><span id="en-us_topic_0000002515503852_text1744532925112"><a name="en-us_topic_0000002515503852_text1744532925112"></a><a name="en-us_topic_0000002515503852_text1744532925112"></a>Atlas 300T A2 training card</span></p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.2 "><p id="en-us_topic_0000002515503852_p1923112115119"><a name="en-us_topic_0000002515503852_p1923112115119"></a><a name="en-us_topic_0000002515503852_p1923112115119"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.3 "><p id="en-us_topic_0000002515503852_p1269122515"><a name="en-us_topic_0000002515503852_p1269122515"></a><a name="en-us_topic_0000002515503852_p1269122515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p43014126516"><a name="en-us_topic_0000002515503852_p43014126516"></a><a name="en-us_topic_0000002515503852_p43014126516"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002515503852_row557915117191"><td class="cellrowborder" colspan="4" valign="top" headers="mcps1.2.5.1.1 mcps1.2.5.1.2 mcps1.2.5.1.3 mcps1.2.5.1.4 "><p id="en-us_topic_0000002515503852_p2042757191916"><a name="en-us_topic_0000002515503852_p2042757191916"></a><a name="en-us_topic_0000002515503852_p2042757191916"></a><span id="en-us_topic_0000002515503852_ph209063317554"><a name="en-us_topic_0000002515503852_ph209063317554"></a><a name="en-us_topic_0000002515503852_ph209063317554"></a>Note: <strong id="en-us_topic_0000002515503852_b169314010451"><a name="en-us_topic_0000002515503852_b169314010451"></a><a name="en-us_topic_0000002515503852_b169314010451"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002515503852_b2931140104515"><a name="en-us_topic_0000002515503852_b2931140104515"></a><a name="en-us_topic_0000002515503852_b2931140104515"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002515503852_b16931503456"><a name="en-us_topic_0000002515503852_b16931503456"></a><a name="en-us_topic_0000002515503852_b16931503456"></a>NA</strong> indicates that the function is not involved and planned currently.</span></p>
</td>
</tr>
</tbody>
</table>

**Example<a name="en-us_topic_0000001251107199_en-us_topic_0000001223414423_en-us_topic_0000001146259777_toc533412083"></a>**

```c
...
int ret = 0;
int dev_id=0;
unsigned int ecc_count = 0;
unsigned char read_type = SINGLE_ECC_INFO_READ;
unsigned char module_type = DCMI_DEVICE_TYPE_HBM;
struct dcmi_ecc_common_data ecc_common_data_s[MAX_RECORD_ECC_ADDR_COUNT] = {0};
ret = dcmi_get_multi_ecc_record_info(dev_id, &ecc_count, read_type, module_type, ecc_common_data_s);
if (ret != 0){
    //todo: Record logs.
    return ret;
}
...
```

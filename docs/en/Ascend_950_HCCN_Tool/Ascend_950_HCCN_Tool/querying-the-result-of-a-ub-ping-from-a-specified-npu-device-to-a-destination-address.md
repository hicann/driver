# Querying the Result of a UB Ping from a Specified NPU Device to a Destination Address<a name="EN-US_TOPIC_0000002584451416"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p44201360411"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p75637171408"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p187611624184817"><a name="en-us_topic_0000002614931227_p187611624184817"></a><a name="en-us_topic_0000002614931227_p187611624184817"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p2761324104819"><a name="en-us_topic_0000002614931227_p2761324104819"></a><a name="en-us_topic_0000002614931227_p2761324104819"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p1476142414488"><a name="en-us_topic_0000002614931227_p1476142414488"></a><a name="en-us_topic_0000002614931227_p1476142414488"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p7761524164817"><a name="en-us_topic_0000002614931227_p7761524164817"></a><a name="en-us_topic_0000002614931227_p7761524164817"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p5761142419484"><a name="en-us_topic_0000002614931227_p5761142419484"></a><a name="en-us_topic_0000002614931227_p5761142419484"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p15564417174012"></a><strong id="en-us_topic_0000002614931227_b114231289515"><a name="en-us_topic_0000002614931227_b114231289515"></a><a name="en-us_topic_0000002614931227_b114231289515"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002062844850_p14564617114019"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b465716294519"><a name="en-us_topic_0000002614931227_b465716294519"></a><a name="en-us_topic_0000002614931227_b465716294519"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p576152444819"><a name="en-us_topic_0000002614931227_p576152444819"></a><a name="en-us_topic_0000002614931227_p576152444819"></a><strong id="en-us_topic_0000002614931227_b56905301955"><a name="en-us_topic_0000002614931227_b56905301955"></a><a name="en-us_topic_0000002614931227_b56905301955"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p67611424144816"><a name="en-us_topic_0000002614931227_p67611424144816"></a><a name="en-us_topic_0000002614931227_p67611424144816"></a><strong id="en-us_topic_0000002614931227_b77248318517"><a name="en-us_topic_0000002614931227_b77248318517"></a><a name="en-us_topic_0000002614931227_b77248318517"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p776152411481"><a name="en-us_topic_0000002614931227_p776152411481"></a><a name="en-us_topic_0000002614931227_p776152411481"></a><strong id="en-us_topic_0000002614931227_b1571933218518"><a name="en-us_topic_0000002614931227_b1571933218518"></a><a name="en-us_topic_0000002614931227_b1571933218518"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p1376142411481"><a name="en-us_topic_0000002614931227_p1376142411481"></a><a name="en-us_topic_0000002614931227_p1376142411481"></a><strong id="en-us_topic_0000002614931227_b5732033855"><a name="en-us_topic_0000002614931227_b5732033855"></a><a name="en-us_topic_0000002614931227_b5732033855"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p676192444812"><a name="en-us_topic_0000002614931227_p676192444812"></a><a name="en-us_topic_0000002614931227_p676192444812"></a><strong id="en-us_topic_0000002614931227_b97392034855"><a name="en-us_topic_0000002614931227_b97392034855"></a><a name="en-us_topic_0000002614931227_b97392034855"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row9310018122518"><td class="cellrowborder" valign="top" width="12.57%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p496503213253"><a name="en-us_topic_0000002614931227_p496503213253"></a><a name="en-us_topic_0000002614931227_p496503213253"></a><span id="en-us_topic_0000002614931227_ph12140626193614"><a name="en-us_topic_0000002614931227_ph12140626193614"></a><a name="en-us_topic_0000002614931227_ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.43%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p11731721162710"><a name="en-us_topic_0000002614931227_p11731721162710"></a><a name="en-us_topic_0000002614931227_p11731721162710"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p7731142132711"><a name="en-us_topic_0000002614931227_p7731142132711"></a><a name="en-us_topic_0000002614931227_p7731142132711"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p18731152115278"><a name="en-us_topic_0000002614931227_p18731152115278"></a><a name="en-us_topic_0000002614931227_p18731152115278"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p07311821202718"><a name="en-us_topic_0000002614931227_p07311821202718"></a><a name="en-us_topic_0000002614931227_p07311821202718"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p7770113011249"><a name="en-us_topic_0000002614931227_p7770113011249"></a><a name="en-us_topic_0000002614931227_p7770113011249"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p187701309243"><a name="en-us_topic_0000002614931227_p187701309243"></a><a name="en-us_topic_0000002614931227_p187701309243"></a>N/A</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p2077003042417"><a name="en-us_topic_0000002614931227_p2077003042417"></a><a name="en-us_topic_0000002614931227_p2077003042417"></a>N/A</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row1090441572511"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"><a name="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"></a><a name="en-us_topic_0000002614931227_en-us_topic_0000002338979954_p12881158154715"></a>Note: <strong id="en-us_topic_0000002614931227_b156115392518"><a name="en-us_topic_0000002614931227_b156115392518"></a><a name="en-us_topic_0000002614931227_b156115392518"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b9611163911511"><a name="en-us_topic_0000002614931227_b9611163911511"></a><a name="en-us_topic_0000002614931227_b9611163911511"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b1161173913519"><a name="en-us_topic_0000002614931227_b1161173913519"></a><a name="en-us_topic_0000002614931227_b1161173913519"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="section957615561617"></a>

Queries the result of a UB ping from a specified NPU device to a destination address.

## Precautions<a name="section8415102071"></a>

The device supports a maximum of eight concurrent ping operations.

## Syntax<a name="section4655161312717"></a>

```bash
hccn_tool -t -ub_ping -i <dev_id> -src_eid <src_eid> -dst_eid <dst_eid> [-pkt <size>] [-cnt <size>] [-interval <size>]
```

## Parameters<a name="section107781620873"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="17.560000000000002%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="26.150000000000002%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="en-us_topic_0184799386_row3343181924120"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p45503264287"><a name="p45503264287"></a><a name="p45503264287"></a>-src_eid &lt;src_eid&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>Source EID in the standard format, for example, <em id="i1839152616434"><a name="i1839152616434"></a><a name="i1839152616434"></a>x</em><strong id="b2057211423435"><a name="b2057211423435"></a><a name="b2057211423435"></a>:</strong><em id="i9669172712435"><a name="i9669172712435"></a><a name="i9669172712435"></a>x</em><strong id="b11361344164315"><a name="b11361344164315"></a><a name="b11361344164315"></a>:</strong><em id="i1826832911435"><a name="i1826832911435"></a><a name="i1826832911435"></a>x</em><strong id="b19706452436"><a name="b19706452436"></a><a name="b19706452436"></a>:</strong><em id="i121863314431"><a name="i121863314431"></a><a name="i121863314431"></a>x</em><strong id="b10605164710430"><a name="b10605164710430"></a><a name="b10605164710430"></a>:</strong><em id="i1783932124313"><a name="i1783932124313"></a><a name="i1783932124313"></a>x</em><strong id="b152061850154314"><a name="b152061850154314"></a><a name="b152061850154314"></a>:</strong><em id="i202442343438"><a name="i202442343438"></a><a name="i202442343438"></a>x</em><strong id="b209361752124315"><a name="b209361752124315"></a><a name="b209361752124315"></a>:</strong><em id="i8915133574315"><a name="i8915133574315"></a><a name="i8915133574315"></a>x</em><strong id="b1713585516436"><a name="b1713585516436"></a><a name="b1713585516436"></a>:</strong><em id="i134012396437"><a name="i134012396437"></a><a name="i134012396437"></a>x</em>. You can run the command in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a> to query the EID. In the command output, the values of <strong id="b720317984715"><a name="b720317984715"></a><a name="b720317984715"></a>IP Address</strong> for the <strong id="b1559161413473"><a name="b1559161413473"></a><a name="b1559161413473"></a>ipourma</strong> field can be used as the EID.</p>
</td>
</tr>
<tr id="row12451101662415"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p783412581807"><a name="p783412581807"></a><a name="p783412581807"></a>-dst_eid &lt;dst_eid&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p3688154719016"><a name="p3688154719016"></a><a name="p3688154719016"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p268815471808"><a name="p268815471808"></a><a name="p268815471808"></a>Destination EID in the standard format, for example, <em id="i04669919563"><a name="i04669919563"></a><a name="i04669919563"></a>x</em><strong id="b846718965616"><a name="b846718965616"></a><a name="b846718965616"></a>:</strong><em id="i846712917561"><a name="i846712917561"></a><a name="i846712917561"></a>x</em><strong id="b246769195614"><a name="b246769195614"></a><a name="b246769195614"></a>:</strong><em id="i19468179195618"><a name="i19468179195618"></a><a name="i19468179195618"></a>x</em><strong id="b13468139175612"><a name="b13468139175612"></a><a name="b13468139175612"></a>:</strong><em id="i134687917566"><a name="i134687917566"></a><a name="i134687917566"></a>x</em><strong id="b44684915616"><a name="b44684915616"></a><a name="b44684915616"></a>:</strong><em id="i1546969185614"><a name="i1546969185614"></a><a name="i1546969185614"></a>x</em><strong id="b144690910564"><a name="b144690910564"></a><a name="b144690910564"></a>:</strong><em id="i1246916965618"><a name="i1246916965618"></a><a name="i1246916965618"></a>x</em><strong id="b547015917568"><a name="b547015917568"></a><a name="b547015917568"></a>:</strong><em id="i747013985610"><a name="i747013985610"></a><a name="i747013985610"></a>x</em><strong id="b94709915617"><a name="b94709915617"></a><a name="b94709915617"></a>:</strong><em id="i7470139195610"><a name="i7470139195610"></a><a name="i7470139195610"></a>x</em>. You can run the command in <a href="querying-the-npu-device-information.md">Querying the NPU Device Information</a> to query the EID. In the command output, the values of <strong id="b81013819526"><a name="b81013819526"></a><a name="b81013819526"></a>IP Address</strong> for the <strong id="b171013810526"><a name="b171013810526"></a><a name="b171013810526"></a>ipourma</strong> field can be used as the EID.</p>
</td>
</tr>
<tr id="row172361433123514"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p31823764217"><a name="p31823764217"></a><a name="p31823764217"></a>-pkt &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p91825724213"><a name="p91825724213"></a><a name="p91825724213"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p10182197104216"><a name="p10182197104216"></a><a name="p10182197104216"></a>Size of the ping packet. The value ranges from 0 to 4046, in bytes. The default value is <strong id="b45181712105218"><a name="b45181712105218"></a><a name="b45181712105218"></a>4046</strong>.</p>
</td>
</tr>
<tr id="row5236123316356"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p045414171710"><a name="p045414171710"></a><a name="p045414171710"></a>-cnt &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p134545177117"><a name="p134545177117"></a><a name="p134545177117"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p134543171119"><a name="p134543171119"></a><a name="p134543171119"></a>Number of ping packets to be sent. The value ranges from 1 to 1000, and the default value is <strong id="b1294250205219"><a name="b1294250205219"></a><a name="b1294250205219"></a>3</strong>.</p>
</td>
</tr>
<tr id="row8387336193516"><td class="cellrowborder" valign="top" width="17.560000000000002%" headers="mcps1.1.4.1.1 "><p id="p1833964572814"><a name="p1833964572814"></a><a name="p1833964572814"></a>-interval &lt;size&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="26.150000000000002%" headers="mcps1.1.4.1.2 "><p id="p17387153663516"><a name="p17387153663516"></a><a name="p17387153663516"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1774744514911"><a name="p1774744514911"></a><a name="p1774744514911"></a>Interval between two consecutive ping packet transmissions. The value ranges from 0 to 10000, in milliseconds. The default value is <strong id="b146370816536"><a name="b146370816536"></a><a name="b146370816536"></a>1000</strong>.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section185511229978"></a>

```bash
hccn_tool -t -ub_ping -i 0 -src_eid ::40:10:0:dfdf:90 -dst_eid ::60:10:0:dfdf:b0 -pkt 128 -cnt 6 -interval 1
```

Query the ping result from the device with logical ID 0 \(::40:10:0:dfdf:90\) to the destination EID \(::60:10:0:dfdf:b0\).

```text
device 0 dev  EID ::40:10:0:dfdf:90 to ::60:10:0:dfdf:b0
recv seq:0,time:0.286000ms
recv seq:1,time:0.288000ms
recv seq:2,time:0.278000ms
recv seq:3,time:0.282000ms
recv seq:4,time:0.289000ms
recv seq:5,time:0.295000ms
6 packets transmitted, 6 received, 0.00% packet loss
max time 0.295000ms
min time 0.278000ms
average time 0.286000ms
TP95 time 0.295000ms
Cmd executed successfully!
```

## Output Description<a name="section1726420371679"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="39.76%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="60.24%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1522419311266"><a name="p1522419311266"></a><a name="p1522419311266"></a>recv seq</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p159371238267"><a name="p159371238267"></a><a name="p159371238267"></a>Received sequence number.</p>
</td>
</tr>
<tr id="row891712572230"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1991745712232"><a name="p1991745712232"></a><a name="p1991745712232"></a>time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p11917257192318"><a name="p11917257192318"></a><a name="p11917257192318"></a>Interval between the time when a packet is sent and the time when the packet is received.</p>
</td>
</tr>
<tr id="row4337111320368"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p1718216442065"><a name="p1718216442065"></a><a name="p1718216442065"></a>max time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p132931729115219"><a name="p132931729115219"></a><a name="p132931729115219"></a>Maximum delay in receiving a reply packet.</p>
</td>
</tr>
<tr id="row16665415163615"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p179332743619"><a name="p179332743619"></a><a name="p179332743619"></a>min time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p7293172955219"><a name="p7293172955219"></a><a name="p7293172955219"></a>Minimum delay in receiving a reply packet.</p>
</td>
</tr>
<tr id="row17665161512367"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p5208103323618"><a name="p5208103323618"></a><a name="p5208103323618"></a>average time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p132934298522"><a name="p132934298522"></a><a name="p132934298522"></a>Average delay in receiving reply packets.</p>
</td>
</tr>
<tr id="row69731248173614"><td class="cellrowborder" valign="top" width="39.76%" headers="mcps1.1.3.1.1 "><p id="p7307195118368"><a name="p7307195118368"></a><a name="p7307195118368"></a>TP95 time</p>
</td>
<td class="cellrowborder" valign="top" width="60.24%" headers="mcps1.1.3.1.2 "><p id="p729310294529"><a name="p729310294529"></a><a name="p729310294529"></a>95th percentile delay in receiving reply packets.</p>
</td>
</tr>
</tbody>
</table>

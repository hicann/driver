# Querying the TLS Certificate Information of an NPU Device<a name="EN-US_TOPIC_0000002584611342"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002062844850_row5420336204112"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002062844850_p44201360411"><a name="en-us_topic_0000002062844850_p44201360411"></a><a name="en-us_topic_0000002062844850_p44201360411"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002062844850_p75637171408"><a name="en-us_topic_0000002062844850_p75637171408"></a><a name="en-us_topic_0000002062844850_p75637171408"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="p187611624184817"><a name="p187611624184817"></a><a name="p187611624184817"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="p2761324104819"><a name="p2761324104819"></a><a name="p2761324104819"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="p1476142414488"><a name="p1476142414488"></a><a name="p1476142414488"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="p7761524164817"><a name="p7761524164817"></a><a name="p7761524164817"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="p5761142419484"><a name="p5761142419484"></a><a name="p5761142419484"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002062844850_row14266172713411"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002062844850_p15564417174012"><a name="en-us_topic_0000002062844850_p15564417174012"></a><a name="en-us_topic_0000002062844850_p15564417174012"></a><strong id="b16778104475812"><a name="b16778104475812"></a><a name="b16778104475812"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002062844850_p14564617114019"><a name="en-us_topic_0000002062844850_p14564617114019"></a><a name="en-us_topic_0000002062844850_p14564617114019"></a>Running User Group (Non-<strong id="b1387119551585"><a name="b1387119551585"></a><a name="b1387119551585"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="p576152444819"><a name="p576152444819"></a><a name="p576152444819"></a><strong id="b1491416573582"><a name="b1491416573582"></a><a name="b1491416573582"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="p67611424144816"><a name="p67611424144816"></a><a name="p67611424144816"></a><strong id="b59325915818"><a name="b59325915818"></a><a name="b59325915818"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="p776152411481"><a name="p776152411481"></a><a name="p776152411481"></a><strong id="b1514700105914"><a name="b1514700105914"></a><a name="b1514700105914"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="p1376142411481"><a name="p1376142411481"></a><a name="p1376142411481"></a><strong id="b45922317014"><a name="b45922317014"></a><a name="b45922317014"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="p676192444812"><a name="p676192444812"></a><a name="p676192444812"></a><strong id="b1111619510015"><a name="b1111619510015"></a><a name="b1111619510015"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="row9310018122518"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="p496503213253"><a name="p496503213253"></a><a name="p496503213253"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="p10676134104320"><a name="p10676134104320"></a><a name="p10676134104320"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="p467693412433"><a name="p467693412433"></a><a name="p467693412433"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="p1567616346430"><a name="p1567616346430"></a><a name="p1567616346430"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="p44591743488"><a name="p44591743488"></a><a name="p44591743488"></a>Y (host certificate)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="p78841858195018"><a name="p78841858195018"></a><a name="p78841858195018"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="p288555855016"><a name="p288555855016"></a><a name="p288555855016"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="p56801710204816"><a name="p56801710204816"></a><a name="p56801710204816"></a>Y (host certificate)</p>
</td>
</tr>
<tr id="row1090441572511"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002338979954_p12881158154715"><a name="en-us_topic_0000002338979954_p12881158154715"></a><a name="en-us_topic_0000002338979954_p12881158154715"></a>Note: <strong id="b17377134318015"><a name="b17377134318015"></a><a name="b17377134318015"></a>Y</strong> indicates that the function is supported, <strong id="b12377154318017"><a name="b12377154318017"></a><a name="b12377154318017"></a>N</strong> indicates that the function is not supported, and <strong id="b1837784313010"><a name="b1837784313010"></a><a name="b1837784313010"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="en-us_topic_0184799386_section1383319120101"></a>

Queries the host or device TLS certificate information.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

None.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -g -tls -i <dev_id> [-host]
```

## Parameters<a name="en-us_topic_0184799386_section10465854096"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="25%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="50%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="25%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="50%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>If this option is specified, the host-side TLS information is queried. If this option is not specified, the device-side TLS information is queried by default.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0184799386_section1684018331898"></a>

```bash
hccn_tool -g -tls -i 0
```

Query the TLS certificate information of device 0.

```text
dev_id:0, tls switch[0](0:disable, 1:enable), tls preconfigured[0](0:non-preset, 1:preset), tls alarm time threshold[60]days
dev_id:0, [pub cert] info:
         subject[/C=CN/O=xxx/CN=www.xxx.com]
         issuer[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Wed Jun 18 03:10:27 2053 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [ca1 cert] info:
         subject[/C=CN/O=xxx/CN=xxx RSA CA]
         issuer[/C=CN/O=xxx/CN=xxx RSA CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Thu Feb  3 03:10:27 2056 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [ca2 cert] info:
         subject[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         issuer[/C=CN/O=xxx/CN=Test RSA CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Thu Mar 22 03:10:27 2108 GMT]
         tls expiration status[0](0:normal, 1:near expiration, 2:has expired)
dev_id:0, [crl] info:
         subject[]
         issuer[/C=CN/O=xxx/CN=xxx RSA PSS Sub CA]
         start_time[Sat Jan 31 03:10:27 2026 GMT]
         end_time[Mon Mar  2 03:10:27 2026 GMT]
         tls expiration status[1](0:normal, 1:near expiration, 2:has expired)
```

## Output Description<a name="section55215490292"></a>

<a name="table13173658171619"></a>
<table><thead align="left"><tr id="row3206165891617"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="p6206135871615"><a name="p6206135871615"></a><a name="p6206135871615"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="p520617581169"><a name="p520617581169"></a><a name="p520617581169"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row720695814162"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p149462212379"><a name="p149462212379"></a><a name="p149462212379"></a>tls switch</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p12176156183113"><a name="p12176156183113"></a><a name="p12176156183113"></a>TLS enable status:</p>
<a name="ul76102363212"></a><a name="ul76102363212"></a><ul id="ul76102363212"><li><strong id="b1344472515251"><a name="b1344472515251"></a><a name="b1344472515251"></a>0</strong>: disabled</li><li><strong id="b11192103942313"><a name="b11192103942313"></a><a name="b11192103942313"></a>1</strong>: enabled</li></ul>
</td>
</tr>
<tr id="row9947344415"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p78214963818"><a name="p78214963818"></a><a name="p78214963818"></a>tls preconfigured</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p949287113210"><a name="p949287113210"></a><a name="p949287113210"></a>TLS certificate type:</p>
<a name="ul04101314113217"></a><a name="ul04101314113217"></a><ul id="ul04101314113217"><li><strong id="b1948351192713"><a name="b1948351192713"></a><a name="b1948351192713"></a>0</strong>: non-preset certificate</li><li><strong id="b163201554172711"><a name="b163201554172711"></a><a name="b163201554172711"></a>1</strong>: preset certificate</li></ul>
</td>
</tr>
<tr id="row1946053614"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p11514297399"><a name="p11514297399"></a><a name="p11514297399"></a>tls alarm time threshold</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p155751159171813"><a name="p155751159171813"></a><a name="p155751159171813"></a>TLS expiration alarm threshold.</p>
</td>
</tr>
<tr id="row10242029533"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p026421412325"><a name="p026421412325"></a><a name="p026421412325"></a>subject</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p7264814113216"><a name="p7264814113216"></a><a name="p7264814113216"></a>Identity information of the TLS certificate holder.</p>
</td>
</tr>
<tr id="row19132121513299"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p42319554399"><a name="p42319554399"></a><a name="p42319554399"></a>issuer</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p141331215152914"><a name="p141331215152914"></a><a name="p141331215152914"></a>TLS certificate authority:</p>
</td>
</tr>
<tr id="row766421693318"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p5665716153317"><a name="p5665716153317"></a><a name="p5665716153317"></a>start_time</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p26657161333"><a name="p26657161333"></a><a name="p26657161333"></a>Time when the TLS certificate becomes effective.</p>
</td>
</tr>
<tr id="row5813191853319"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p981311833312"><a name="p981311833312"></a><a name="p981311833312"></a>end_time</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p188133183333"><a name="p188133183333"></a><a name="p188133183333"></a>Time when the TLS certificate expires.</p>
</td>
</tr>
<tr id="row10692129153312"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="p1069212913314"><a name="p1069212913314"></a><a name="p1069212913314"></a>tls expiration status</p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="p18635151703213"><a name="p18635151703213"></a><a name="p18635151703213"></a>TLS certificate validity status:</p>
<a name="ul6419132713326"></a><a name="ul6419132713326"></a><ul id="ul6419132713326"><li><strong id="b186433912712"><a name="b186433912712"></a><a name="b186433912712"></a>0</strong>: valid</li><li><strong id="b17621945152710"><a name="b17621945152710"></a><a name="b17621945152710"></a>1</strong>: expiring soon</li><li><strong id="b1339931217305"><a name="b1339931217305"></a><a name="b1339931217305"></a>2</strong>: expired</li></ul>
</td>
</tr>
</tbody>
</table>

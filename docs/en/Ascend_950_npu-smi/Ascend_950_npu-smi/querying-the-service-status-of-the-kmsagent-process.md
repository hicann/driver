# Querying the Service Status of the KMSAgent Process<a name="EN-US_TOPIC_0000002484306790"></a>

## Function<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section18674262006"></a>

This command is used to query the service status of the KMSAgent process \(key management process\).

## Syntax<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section386902615016"></a>

`npu-smi info -t key-manage`

## Parameters<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section1786919261014"></a>

None

## Usage Instruction<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section6636145619341"></a>

The OpenSSL version must be 3.0.0 or later. If the version does not meet the requirement, upgrade it. You are advised to install the latest vulnerability-free version.

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row2056819579256"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p10568457202515"><a name="en-us_topic_0000002484466758_p10568457202515"></a><a name="en-us_topic_0000002484466758_p10568457202515"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p3568155712520"><a name="en-us_topic_0000002484466758_p3568155712520"></a><a name="en-us_topic_0000002484466758_p3568155712520"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p7568757122511"><a name="en-us_topic_0000002484466758_p7568757122511"></a><a name="en-us_topic_0000002484466758_p7568757122511"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p1556812578254"><a name="en-us_topic_0000002484466758_p1556812578254"></a><a name="en-us_topic_0000002484466758_p1556812578254"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p105681557162517"><a name="en-us_topic_0000002484466758_p105681557162517"></a><a name="en-us_topic_0000002484466758_p105681557162517"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row185688570253"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p175691857172519"><a name="en-us_topic_0000002484466758_p175691857172519"></a><a name="en-us_topic_0000002484466758_p175691857172519"></a><strong id="en-us_topic_0000002484466758_b1884169617"><a name="en-us_topic_0000002484466758_b1884169617"></a><a name="en-us_topic_0000002484466758_b1884169617"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p1056925762517"><a name="en-us_topic_0000002484466758_p1056925762517"></a><a name="en-us_topic_0000002484466758_p1056925762517"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1510091906"><a name="en-us_topic_0000002484466758_b1510091906"></a><a name="en-us_topic_0000002484466758_b1510091906"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p1256975772514"><a name="en-us_topic_0000002484466758_p1256975772514"></a><a name="en-us_topic_0000002484466758_p1256975772514"></a><strong id="en-us_topic_0000002484466758_b722667928"><a name="en-us_topic_0000002484466758_b722667928"></a><a name="en-us_topic_0000002484466758_b722667928"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p2569157132518"><a name="en-us_topic_0000002484466758_p2569157132518"></a><a name="en-us_topic_0000002484466758_p2569157132518"></a><strong id="en-us_topic_0000002484466758_b527740528"><a name="en-us_topic_0000002484466758_b527740528"></a><a name="en-us_topic_0000002484466758_b527740528"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p656975711257"><a name="en-us_topic_0000002484466758_p656975711257"></a><a name="en-us_topic_0000002484466758_p656975711257"></a><strong id="en-us_topic_0000002484466758_b1518861502"><a name="en-us_topic_0000002484466758_b1518861502"></a><a name="en-us_topic_0000002484466758_b1518861502"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row65691257162516"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p1356905716259"><a name="en-us_topic_0000002484466758_p1356905716259"></a><a name="en-us_topic_0000002484466758_p1356905716259"></a><span id="en-us_topic_0000002484466758_ph1569135714257"><a name="en-us_topic_0000002484466758_ph1569135714257"></a><a name="en-us_topic_0000002484466758_ph1569135714257"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_p15569657112515"><a name="en-us_topic_0000002484466758_p15569657112515"></a><a name="en-us_topic_0000002484466758_p15569657112515"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_p16569257142516"><a name="en-us_topic_0000002484466758_p16569257142516"></a><a name="en-us_topic_0000002484466758_p16569257142516"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p127191613267"><a name="en-us_topic_0000002484466758_p127191613267"></a><a name="en-us_topic_0000002484466758_p127191613267"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.64667066586683%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p1356945762511"><a name="en-us_topic_0000002484466758_p1356945762511"></a><a name="en-us_topic_0000002484466758_p1356945762511"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.686662667466507%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p7569135772519"><a name="en-us_topic_0000002484466758_p7569135772519"></a><a name="en-us_topic_0000002484466758_p7569135772519"></a>Y</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row55691557132514"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p195699573251"><a name="en-us_topic_0000002484466758_p195699573251"></a><a name="en-us_topic_0000002484466758_p195699573251"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section66051714132117"></a>

Query the service status of the KMSAgent process.

```bash
npu-smi info -t key-manage
```

```text
        service auto startup           : Disable
        service running status         : Stop
```

## Output Description<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p36441839191318"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p36441839191318"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p36441839191318"></a>service auto startup</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p166905557715"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p166905557715"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p166905557715"></a>Service auto-startup status.</p>
<p id="en-us_topic_0000001220416510_p1653011774216"><a name="en-us_topic_0000001220416510_p1653011774216"></a><a name="en-us_topic_0000001220416510_p1653011774216"></a>The value can be <strong id="b9128142018287"><a name="b9128142018287"></a><a name="b9128142018287"></a>Enable</strong> or <strong id="b912815204282"><a name="b912815204282"></a><a name="b912815204282"></a>Disable</strong>.</p>
<p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p15416184352714"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p15416184352714"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p15416184352714"></a>The default value is <strong id="b187291125112815"><a name="b187291125112815"></a><a name="b187291125112815"></a>Disable</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p4642739141315"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p4642739141315"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p4642739141315"></a>service running status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p202841353182817"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p202841353182817"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p202841353182817"></a>Service status.</p>
<p id="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p428415313286"><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p428415313286"></a><a name="en-us_topic_0000001220416510_en-us_topic_0000001200340465_p428415313286"></a>The value can be <strong id="b12178639152816"><a name="b12178639152816"></a><a name="b12178639152816"></a>Running</strong> or <strong id="b9178113992818"><a name="b9178113992818"></a><a name="b9178113992818"></a>Stop</strong>.</p>
<p id="en-us_topic_0000001220416510_p16514162218427"><a name="en-us_topic_0000001220416510_p16514162218427"></a><a name="en-us_topic_0000001220416510_p16514162218427"></a>The default value is <strong id="b156111042102812"><a name="b156111042102812"></a><a name="b156111042102812"></a>Stop</strong>.</p>
</td>
</tr>
</tbody>
</table>

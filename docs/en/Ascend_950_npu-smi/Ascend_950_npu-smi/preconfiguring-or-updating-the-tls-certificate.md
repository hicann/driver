# Preconfiguring or Updating the TLS Certificate<a name="EN-US_TOPIC_0000002484466732"></a>

## Function<a name="en-us_topic_0000001937698749_section1012914384613"></a>

This command is used to import the TLS certificate.

## Syntax<a name="en-us_topic_0000001937698749_section913083810614"></a>

`npu-smi set -t tls-cert -i dev_id -f "TLS certificate CA root certificate Level-2 CA certificate"`

## Parameters<a name="en-us_topic_0000001937698749_section1813112381066"></a>

<a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><a name="en-us_topic_0000001937698749_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><em id="i5270129122719"><a name="i5270129122719"></a><a name="i5270129122719"></a><span id="ph52707942715"><a name="ph52707942715"></a><a name="ph52707942715"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
<tr id="en-us_topic_0000001937698749_row098220478355"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001937698749_p2214041215"><a name="en-us_topic_0000001937698749_p2214041215"></a><a name="en-us_topic_0000001937698749_p2214041215"></a><em id="i59938910437"><a name="i59938910437"></a><a name="i59938910437"></a>TLS certificate CA root certificate Level-2 CA certificate</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000001937698749_p69831847103512"><a name="en-us_topic_0000001937698749_p69831847103512"></a><a name="en-us_topic_0000001937698749_p69831847103512"></a>TLS certificate path, CA root certificate path, and level-2 CA certificate path.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001937698749_section814218382062"></a>

**Table  1** Support in different deployment scenarios

<a name="table7280184483416"></a>
<table><thead align="left"><tr id="en-us_topic_0000002484466758_row964854311460"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.7.1.1"><p id="en-us_topic_0000002484466758_p13648143204610"><a name="en-us_topic_0000002484466758_p13648143204610"></a><a name="en-us_topic_0000002484466758_p13648143204610"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.7.1.2"><p id="en-us_topic_0000002484466758_p1864874319464"><a name="en-us_topic_0000002484466758_p1864874319464"></a><a name="en-us_topic_0000002484466758_p1864874319464"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.3"><p id="en-us_topic_0000002484466758_p8648124314461"><a name="en-us_topic_0000002484466758_p8648124314461"></a><a name="en-us_topic_0000002484466758_p8648124314461"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.4"><p id="en-us_topic_0000002484466758_p7648843164617"><a name="en-us_topic_0000002484466758_p7648843164617"></a><a name="en-us_topic_0000002484466758_p7648843164617"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.1.5"><p id="en-us_topic_0000002484466758_p7648174364614"><a name="en-us_topic_0000002484466758_p7648174364614"></a><a name="en-us_topic_0000002484466758_p7648174364614"></a>VM Passthrough</p>
</th>
</tr>
<tr id="en-us_topic_0000002484466758_row8648643184618"><th class="cellrowborder" valign="top" id="mcps1.2.7.2.1"><p id="en-us_topic_0000002484466758_p1164844314620"><a name="en-us_topic_0000002484466758_p1164844314620"></a><a name="en-us_topic_0000002484466758_p1164844314620"></a><strong id="en-us_topic_0000002484466758_b1894223994"><a name="en-us_topic_0000002484466758_b1894223994"></a><a name="en-us_topic_0000002484466758_b1894223994"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.2"><p id="en-us_topic_0000002484466758_p96483431466"><a name="en-us_topic_0000002484466758_p96483431466"></a><a name="en-us_topic_0000002484466758_p96483431466"></a>Running User Group (Non-<strong id="en-us_topic_0000002484466758_b1566399257"><a name="en-us_topic_0000002484466758_b1566399257"></a><a name="en-us_topic_0000002484466758_b1566399257"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.3"><p id="en-us_topic_0000002484466758_p11648174310465"><a name="en-us_topic_0000002484466758_p11648174310465"></a><a name="en-us_topic_0000002484466758_p11648174310465"></a><strong id="en-us_topic_0000002484466758_b1896044746"><a name="en-us_topic_0000002484466758_b1896044746"></a><a name="en-us_topic_0000002484466758_b1896044746"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.4"><p id="en-us_topic_0000002484466758_p264864313463"><a name="en-us_topic_0000002484466758_p264864313463"></a><a name="en-us_topic_0000002484466758_p264864313463"></a><strong id="en-us_topic_0000002484466758_b1365462222"><a name="en-us_topic_0000002484466758_b1365462222"></a><a name="en-us_topic_0000002484466758_b1365462222"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.7.2.5"><p id="en-us_topic_0000002484466758_p19648943114611"><a name="en-us_topic_0000002484466758_p19648943114611"></a><a name="en-us_topic_0000002484466758_p19648943114611"></a><strong id="en-us_topic_0000002484466758_b1087084158"><a name="en-us_topic_0000002484466758_b1087084158"></a><a name="en-us_topic_0000002484466758_b1087084158"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002484466758_row12648144394611"><td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.1 mcps1.2.7.2.1 "><p id="en-us_topic_0000002484466758_p1764844354613"><a name="en-us_topic_0000002484466758_p1764844354613"></a><a name="en-us_topic_0000002484466758_p1764844354613"></a><span id="en-us_topic_0000002484466758_ph46481643174611"><a name="en-us_topic_0000002484466758_ph46481643174611"></a><a name="en-us_topic_0000002484466758_ph46481643174611"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.2 "><p id="en-us_topic_0000002484466758_p6648194364615"><a name="en-us_topic_0000002484466758_p6648194364615"></a><a name="en-us_topic_0000002484466758_p6648194364615"></a>Y</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.2 mcps1.2.7.2.3 "><p id="en-us_topic_0000002484466758_p136487437467"><a name="en-us_topic_0000002484466758_p136487437467"></a><a name="en-us_topic_0000002484466758_p136487437467"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.3 mcps1.2.7.2.4 "><p id="en-us_topic_0000002484466758_p26077503460"><a name="en-us_topic_0000002484466758_p26077503460"></a><a name="en-us_topic_0000002484466758_p26077503460"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p18611175034612"><a name="en-us_topic_0000002484466758_p18611175034612"></a><a name="en-us_topic_0000002484466758_p18611175034612"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="16.666666666666664%" headers="mcps1.2.7.1.5 "><p id="en-us_topic_0000002484466758_p1161365020461"><a name="en-us_topic_0000002484466758_p1161365020461"></a><a name="en-us_topic_0000002484466758_p1161365020461"></a>N</p>
</td>
</tr>
<tr id="en-us_topic_0000002484466758_row10649154311467"><td class="cellrowborder" colspan="6" valign="top" headers="mcps1.2.7.1.1 mcps1.2.7.1.2 mcps1.2.7.1.3 mcps1.2.7.1.4 mcps1.2.7.1.5 mcps1.2.7.2.1 mcps1.2.7.2.2 mcps1.2.7.2.3 mcps1.2.7.2.4 mcps1.2.7.2.5 "><p id="en-us_topic_0000002484466758_p12649164316467"><a name="en-us_topic_0000002484466758_p12649164316467"></a><a name="en-us_topic_0000002484466758_p12649164316467"></a>Note: <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b109022033362"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b1290216331663"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a><a name="en-us_topic_0000002484466758_en-us_topic_0000002484466758_b290310333620"></a>NA</strong> indicates that the function is not involved and planned currently.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="en-us_topic_0000001937698749_section81981638760"></a>

Import the TLS certificate to device 0.

```bash
npu-smi set -t tls-cert -i 0 -f "rsa.d2.pem rsa.rca.pem rsa.oca.pem"
```

```text
Status                         : OK
Message                        : The tls-cert of the chip is set successfully.
```

## Output Description<a name="en-us_topic_0000001937698749_section9199538460"></a>

**Table  2**  Description of the displayed information

<a name="table5232133817619"></a>
<table><thead align="left"><tr id="row1436523813615"><th class="cellrowborder" valign="top" width="49.49%" id="mcps1.2.3.1.1"><p id="p63652380614"><a name="p63652380614"></a><a name="p63652380614"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.2.3.1.2"><p id="p153654388611"><a name="p153654388611"></a><a name="p153654388611"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row836511381611"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p136514381366"><a name="p136514381366"></a><a name="p136514381366"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p33657383620"><a name="p33657383620"></a><a name="p33657383620"></a>Command output.</p>
<p id="p10365338463"><a name="p10365338463"></a><a name="p10365338463"></a>The value can be <strong id="b293412118415"><a name="b293412118415"></a><a name="b293412118415"></a>OK</strong> or <strong id="b29355215413"><a name="b29355215413"></a><a name="b29355215413"></a>Fail</strong>.</p>
</td>
</tr>
<tr id="row183658381163"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p1236615381866"><a name="p1236615381866"></a><a name="p1236615381866"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p036617381966"><a name="p036617381966"></a><a name="p036617381966"></a>Message displayed after the command is executed.</p>
</td>
</tr>
</tbody>
</table>

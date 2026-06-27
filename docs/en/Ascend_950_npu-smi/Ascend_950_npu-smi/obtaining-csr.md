# Obtaining CSR<a name="EN-US_TOPIC_0000002484306818"></a>

## Function<a name="en-us_topic_0000001897339252_section1943544104812"></a>

This command is used to obtain the CSR file of the TLS certificate.

## Syntax<a name="en-us_topic_0000001897339252_section164424414486"></a>

`npu-smi info -t tls-csr-get -i dev_id`

## Parameters<a name="en-us_topic_0000001897339252_section645174414488"></a>

<a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><a name="en-us_topic_0000001897339252_en-us_topic_0000001220416486_en-us_topic_0000001168070435_p57396781"></a><em id="i12830164192620"><a name="i12830164192620"></a><a name="i12830164192620"></a><span id="ph168304413268"><a name="ph168304413268"></a><a name="ph168304413268"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001897339252_section145711449481"></a>

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

## Example<a name="en-us_topic_0000001897339252_section1110394413482"></a>

Obtain the CSR file of the TLS certificate of device 0.

```bash
npu-smi info -t tls-csr-get -i 0
```

```text
Enter country_name|province_name|city_name|organization_name|department_name.
Example: CN|ZHEJIANG|HANGZHOU|Huawei|Marketing
CN|ZHEJIANG|HANGZHOU|Huawei|Marketing
        Message                        : The tls csr file of the chip is obtained successfully.
```

Check the generated CSR file.

```text
cat /run/csr/cert_type_PKI2.0_tls_*.csr
-----BEGIN CERTIFICATE REQUEST-----
MIIEzzCCArkCAQAwgYsxCzAJBgNVBAYTAkNOMQ8wDQYDVQQKDAZIdWF3ZWkxETAP
BgNVBAgMCFpIRUpJQU5HMREwDwYDVQQHDAhIQU5HWkhPVTESMBAGA1UECwwJTWFy
*********************************************************
-----END CERTIFICATE REQUEST-----
```

> **NOTE:** 
> 
> **/run/csr/**  is the CSR file path.

## Output Description<a name="en-us_topic_0000001897339252_section21061544144810"></a>

**Table  2**  Description of the displayed information

<a name="table13130194414811"></a>
<table><thead align="left"><tr id="row142291944144816"><th class="cellrowborder" valign="top" width="49.49%" id="mcps1.2.3.1.1"><p id="p8230144410489"><a name="p8230144410489"></a><a name="p8230144410489"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.51%" id="mcps1.2.3.1.2"><p id="p723024484811"><a name="p723024484811"></a><a name="p723024484811"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="row1523084484817"><td class="cellrowborder" valign="top" width="49.49%" headers="mcps1.2.3.1.1 "><p id="p14230184484813"><a name="p14230184484813"></a><a name="p14230184484813"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.51%" headers="mcps1.2.3.1.2 "><p id="p4230184464819"><a name="p4230184464819"></a><a name="p4230184464819"></a>Message displayed after the command is executed.</p>
</td>
</tr>
</tbody>
</table>

# Clearing the ECC Error Count of a Device<a name="EN-US_TOPIC_0000002484306742"></a>

## Function<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section18674262006"></a>

This command is used to clear the ECC error count of a device.

## Syntax<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section21351620"></a>

`npu-smi clear -t ecc-info -i dev_id`

## Parameters<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section1786919261014"></a>

<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p3985976"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p3985976"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p54428625"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p54428625"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_row20095581"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p57396781"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p57396781"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p57396781"></a><span id="ph1573145710494"><a name="ph1573145710494"></a><a name="ph1573145710494"></a><em id="en-us_topic_0000002552580505_i177511300519_2"><a name="en-us_topic_0000002552580505_i177511300519_2"></a><a name="en-us_topic_0000002552580505_i177511300519_2"></a>dev_id</em></span></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><p id="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><a name="en-us_topic_0000002484466710_en-us_topic_0000001264656677_en-us_topic_0000001163797135_p45299595"></a><span id="en-us_topic_0000002484466710_ph861524220464"><a name="en-us_topic_0000002484466710_ph861524220464"></a><a name="en-us_topic_0000002484466710_ph861524220464"></a>Logical ID of the software</span>. The NPU ID obtained by running the <strong id="en-us_topic_0000002484466710_b208978812147"><a name="en-us_topic_0000002484466710_b208978812147"></a><a name="en-us_topic_0000002484466710_b208978812147"></a>npu-smi info -l</strong> command is the logical ID of the software.</p>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section666723534613"></a>

> **NOTICE:** 
> 
> This command clears multi-bit ECC errors in the on-chip memory addresses to be isolated, resulting in cold isolation failure of the addresses. Exercise caution when running this command.

This command can be used to clear only historical ECC error counts and ECC error counts of all chips on isolated pages. The ECC error counts are automatically cleared after the device is restarted.

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

## Example<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section66051714132117"></a>

Clear the ECC error count of device 0.

```bash
npu-smi clear -t ecc-info -i 0
```

```text
Status                         : OK
Message                        : Clear ecc-info successfully.
```

## Output Description<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p74517391716"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p74517391716"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p74517391716"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4658179185011"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4658179185011"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4658179185011"></a>Command output.</p>
<p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p83465391210"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p83465391210"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p83465391210"></a>The value can be <strong id="b1190122515710"><a name="b1190122515710"></a><a name="b1190122515710"></a>OK</strong> or <strong id="b419002511716"><a name="b419002511716"></a><a name="b419002511716"></a>Fail</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4642739141315"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4642739141315"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p4642739141315"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p165869115015"><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p165869115015"></a><a name="en-us_topic_0000001220576478_en-us_topic_0000001124097810_p165869115015"></a>Message displayed after the command is executed.</p>
</td>
</tr>
</tbody>
</table>

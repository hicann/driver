# Printing Settings Help<a name="EN-US_TOPIC_0000002516546705"></a>

## Function<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section18674262006"></a>

This command is used to display the help information about settings commands.

## Syntax<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section386902615016"></a>

```bash
npu-smi set -h
npu-smi set --help
```

## Parameters<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section52928161114"></a>

None

## Usage Instruction<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section2106140121613"></a>

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

## Example<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section66051714132117"></a>

Display the help information about commands for settings.

```bash
npu-smi set -h
```

```text
Usage: npu-smi set <-h|-t type> [Options...]

Commands:
       -h, --help     Show this help text and exit
       -t type        The set type for device
                      type: reset, clear-ecc-info, key-manage, sys-log-enable, sys-log-dump,
                            clear-syslog-cfg, tls-cert, tls-cert-period.
Options:
       -i %d          NPU ID
       -d %d          Config value
       -s             String format configuration
       -f             License (1-255) or path of SoC certificate files
                      or path of all device logs are continuously collected
       -m             By in-band reset, only can input 1
```

## Output Description<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p36441839191318"></a>-h</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p1164353918134"></a>Help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row663394510712"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p4642739141315"></a>--help</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p8642123913138"></a>Help information about the command.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row1363313457715"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1389113410304"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1389113410304"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1389113410304"></a>-t type</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p611995314338"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p611995314338"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p611995314338"></a>Command type.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_en-us_topic_0251720880_row1263315457717"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p211815617440"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p211815617440"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p211815617440"></a>-i %d</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264656721_en-us_topic_0000001117597244_p45299595"></a><span id="ph1326456171014"><a name="ph1326456171014"></a><a name="ph1326456171014"></a>Logical ID of the software</span>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row115212416509"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p187433615315"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p187433615315"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p187433615315"></a>-d %d</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p14744106143116"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p14744106143116"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p14744106143116"></a>Set value.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_row268112514506"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p9681192585016"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p9681192585016"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_en-us_topic_0000001264536705_en-us_topic_0000001117597254_p9681192585016"></a>-s</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p132321215114410"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p132321215114410"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p132321215114410"></a>Character string format configuration.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_row5444444114514"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1744512448459"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1744512448459"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p1744512448459"></a>-f</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15445154410458"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15445154410458"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15445154410458"></a>Certificate (1–255) or SoC certificate file path or path for continuously collecting all device logs.</p>
</td>
</tr>
<tr id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_row5600734104720"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15600834164717"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15600834164717"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p15600834164717"></a>-m</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p12601173415478"><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p12601173415478"></a><a name="en-us_topic_0000001409243502_en-us_topic_0000001407019372_p12601173415478"></a>In-band reset. Only <strong id="b1650031502013"><a name="b1650031502013"></a><a name="b1650031502013"></a>1</strong> can be entered for this option.</p>
</td>
</tr>
</tbody>
</table>

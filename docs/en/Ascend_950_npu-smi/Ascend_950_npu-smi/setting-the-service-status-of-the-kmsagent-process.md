# Setting the Service Status of the KMSAgent Process<a name="EN-US_TOPIC_0000002484466730"></a>

## Prerequisites<a name="section3176079345"></a>

Before setting the service status of the KMSAgent process, you need to set the certificate. The operations are as follows:

1. Run the following command to switch to the  **kmsagentd**  directory:

    ```bash
    cd /var/kmsagentd
    ```

2. Generate a CA certificate \(**root\_ca.pem**  is used for an example\).
    1. Run the following command to create a CA private key:

        ```bash
        openssl genrsa -out root_ca.key 4096
        ```

    2. Run the following command to generate a certificate request file:

        ```bash
        openssl req -new -key root_ca.key -subj "/CN=Root CA" -out root_ca.csr
        ```

    3. Run the following command to generate a CA certificate:

        ```bash
        openssl x509 -req -in root_ca.csr -signkey root_ca.key -days 3650 -extfile openssl.cnf -extensions v3_ca -set_serial 1591942200000 -out root_ca.pem
        ```

3. Set the root CA paths.
    - Run the following command to set the root CA path for CFS:

        ```bash
        su - HwHiAiUser -s /bin/bash -c "export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64/inner:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64/common;/usr/local/Ascend/driver/tools/kmsagent -c /var/kmsagentd/kmsagent.conf -k /var/kmsagentd/kmsconf.ksf -s SERVER_FOR_CFS -n CaPath -v /var/kmsagentd/root_ca.pem"
        ```

    - Run the following command to set the root CA path for AI-VAULT:

        ```bash
        su - HwHiAiUser -s /bin/bash -c "export LD_LIBRARY_PATH=/usr/local/Ascend/driver/lib64/inner:/usr/local/Ascend/driver/lib64:/usr/local/Ascend/driver/lib64/driver:/usr/local/Ascend/driver/lib64/common;/usr/local/Ascend/driver/tools/kmsagent -c /var/kmsagentd/kmsagent.conf -k /var/kmsagentd/kmsconf.ksf -s CLIENT_FOR_AIVAULT -n CaPath -v /var/kmsagentd/root_ca.pem"
        ```

        > **NOTE:** 
        >
        > If the installation path is specified during driver installation, replace  _/usr/local/Ascend_  in the command with the actual installation path.

## Function<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_section18674262006"></a>

This command is used to set the service status of the KMSAgent process \(key management process\).

## Syntax<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_section386902615016"></a>

`npu-smi set -t key-manage -s value`

## Parameters<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_section1786919261014"></a>

<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_table7208814"></a>
<table><thead align="left"><tr id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_row57216019"><th class="cellrowborder" valign="top" width="30%" id="mcps1.1.3.1.1"><p id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p3985976"><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p3985976"></a><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p3985976"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="70%" id="mcps1.1.3.1.2"><p id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p54428625"><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p54428625"></a><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p54428625"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_row1780353745014"><td class="cellrowborder" valign="top" width="30%" headers="mcps1.1.3.1.1 "><p id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p81048471715"><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p81048471715"></a><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p81048471715"></a><em id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_i846511579238"><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_i846511579238"></a><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_i846511579238"></a>value</em></p>
</td>
<td class="cellrowborder" valign="top" width="70%" headers="mcps1.1.3.1.2 "><div class="p" id="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p366013319915"><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p366013319915"></a><a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_p366013319915"></a>Service status:<a name="en-us_topic_0000001264816685_ul1244815329339"></a><a name="en-us_topic_0000001264816685_ul1244815329339"></a><ul id="en-us_topic_0000001264816685_ul1244815329339"><li><strong id="b55647235041614"><a name="b55647235041614"></a><a name="b55647235041614"></a>start</strong>: starts the service and enables auto startup.</li><li><strong id="b105923678241614"><a name="b105923678241614"></a><a name="b105923678241614"></a>stop</strong> (default value): stops the service and disables auto startup.</li></ul>
</div>
</td>
</tr>
</tbody>
</table>

## Usage Instruction<a name="en-us_topic_0000001264816685_section12330458135411"></a>

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

## Example<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_section66051714132117"></a>

Start the service and enable auto startup.

```bash
npu-smi set -t key-manage -s start
```

```text
        Status                         : OK
        Message                        : Set key-manage start successfully
```

## Output Description<a name="en-us_topic_0000001264816685_en-us_topic_0000001154308954_section29761716101314"></a>

**Table  2**  Description of the displayed information

<a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_table56659528"></a>
<table><thead align="left"><tr id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_row6702177"><th class="cellrowborder" valign="top" width="49.230000000000004%" id="mcps1.2.3.1.1"><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p6005466"></a>Field</p>
</th>
<th class="cellrowborder" valign="top" width="50.77%" id="mcps1.2.3.1.2"><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_en-us_topic_0200634534_p8965319"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_en-us_topic_0251720880_row96337451711"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p36441839191318"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p36441839191318"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p36441839191318"></a>Status</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p104381429856"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p104381429856"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p104381429856"></a>Command output.</p>
<p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1164353918134"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1164353918134"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1164353918134"></a>The value can be <strong id="b987025365816"><a name="b987025365816"></a><a name="b987025365816"></a>OK</strong> or <strong id="b11870853135819"><a name="b11870853135819"></a><a name="b11870853135819"></a>Fail</strong>.</p>
</td>
</tr>
<tr id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_row7359205111318"><td class="cellrowborder" valign="top" width="49.230000000000004%" headers="mcps1.2.3.1.1 "><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p103559511133"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p103559511133"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p103559511133"></a>Message</p>
</td>
<td class="cellrowborder" valign="top" width="50.77%" headers="mcps1.2.3.1.2 "><p id="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1535515501311"><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1535515501311"></a><a name="en-us_topic_0000001220416506_en-us_topic_0000001129176320_p1535515501311"></a>Message displayed after the command is executed.</p>
</td>
</tr>
</tbody>
</table>

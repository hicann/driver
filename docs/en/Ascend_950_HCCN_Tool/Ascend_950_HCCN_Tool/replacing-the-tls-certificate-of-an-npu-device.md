# Replacing the TLS Certificate of an NPU Device<a name="EN-US_TOPIC_0000002584451450"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002614931227_row1152516361961"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002614931227_p65251336569"><a name="en-us_topic_0000002614931227_p65251336569"></a><a name="en-us_topic_0000002614931227_p65251336569"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002614931227_p1452518361269"><a name="en-us_topic_0000002614931227_p1452518361269"></a><a name="en-us_topic_0000002614931227_p1452518361269"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002614931227_p12525133617618"><a name="en-us_topic_0000002614931227_p12525133617618"></a><a name="en-us_topic_0000002614931227_p12525133617618"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002614931227_p175251236867"><a name="en-us_topic_0000002614931227_p175251236867"></a><a name="en-us_topic_0000002614931227_p175251236867"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002614931227_p135256361566"><a name="en-us_topic_0000002614931227_p135256361566"></a><a name="en-us_topic_0000002614931227_p135256361566"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002614931227_p9525173614613"><a name="en-us_topic_0000002614931227_p9525173614613"></a><a name="en-us_topic_0000002614931227_p9525173614613"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002614931227_p35251836365"><a name="en-us_topic_0000002614931227_p35251836365"></a><a name="en-us_topic_0000002614931227_p35251836365"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002614931227_row175255361369"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002614931227_p175257363614"><a name="en-us_topic_0000002614931227_p175257363614"></a><a name="en-us_topic_0000002614931227_p175257363614"></a><strong id="en-us_topic_0000002614931227_b13640221967"><a name="en-us_topic_0000002614931227_b13640221967"></a><a name="en-us_topic_0000002614931227_b13640221967"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002614931227_p175255361567"><a name="en-us_topic_0000002614931227_p175255361567"></a><a name="en-us_topic_0000002614931227_p175255361567"></a>Running User Group (Non-<strong id="en-us_topic_0000002614931227_b82415235611"><a name="en-us_topic_0000002614931227_b82415235611"></a><a name="en-us_topic_0000002614931227_b82415235611"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002614931227_p052519366616"><a name="en-us_topic_0000002614931227_p052519366616"></a><a name="en-us_topic_0000002614931227_p052519366616"></a><strong id="en-us_topic_0000002614931227_b51299241160"><a name="en-us_topic_0000002614931227_b51299241160"></a><a name="en-us_topic_0000002614931227_b51299241160"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002614931227_p1152593617617"><a name="en-us_topic_0000002614931227_p1152593617617"></a><a name="en-us_topic_0000002614931227_p1152593617617"></a><strong id="en-us_topic_0000002614931227_b17316172511612"><a name="en-us_topic_0000002614931227_b17316172511612"></a><a name="en-us_topic_0000002614931227_b17316172511612"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002614931227_p175251236967"><a name="en-us_topic_0000002614931227_p175251236967"></a><a name="en-us_topic_0000002614931227_p175251236967"></a><strong id="en-us_topic_0000002614931227_b1259719263614"><a name="en-us_topic_0000002614931227_b1259719263614"></a><a name="en-us_topic_0000002614931227_b1259719263614"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002614931227_p175252363616"><a name="en-us_topic_0000002614931227_p175252363616"></a><a name="en-us_topic_0000002614931227_p175252363616"></a><strong id="en-us_topic_0000002614931227_b1123012815614"><a name="en-us_topic_0000002614931227_b1123012815614"></a><a name="en-us_topic_0000002614931227_b1123012815614"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002614931227_p35251336568"><a name="en-us_topic_0000002614931227_p35251336568"></a><a name="en-us_topic_0000002614931227_p35251336568"></a><strong id="en-us_topic_0000002614931227_b5375152917613"><a name="en-us_topic_0000002614931227_b5375152917613"></a><a name="en-us_topic_0000002614931227_b5375152917613"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002614931227_row18525103618619"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002614931227_p7525736665"><a name="en-us_topic_0000002614931227_p7525736665"></a><a name="en-us_topic_0000002614931227_p7525736665"></a><span id="en-us_topic_0000002614931227_ph115250361460"><a name="en-us_topic_0000002614931227_ph115250361460"></a><a name="en-us_topic_0000002614931227_ph115250361460"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002614931227_p29591819165216"><a name="en-us_topic_0000002614931227_p29591819165216"></a><a name="en-us_topic_0000002614931227_p29591819165216"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="en-us_topic_0000002614931227_p19525143135318"><a name="en-us_topic_0000002614931227_p19525143135318"></a><a name="en-us_topic_0000002614931227_p19525143135318"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002614931227_p4905122915216"><a name="en-us_topic_0000002614931227_p4905122915216"></a><a name="en-us_topic_0000002614931227_p4905122915216"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="en-us_topic_0000002614931227_p10942162645212"><a name="en-us_topic_0000002614931227_p10942162645212"></a><a name="en-us_topic_0000002614931227_p10942162645212"></a>Y (host certificate)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="en-us_topic_0000002614931227_p1247513092013"><a name="en-us_topic_0000002614931227_p1247513092013"></a><a name="en-us_topic_0000002614931227_p1247513092013"></a>Y (host certificate)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p179751228202115"><a name="en-us_topic_0000002614931227_p179751228202115"></a><a name="en-us_topic_0000002614931227_p179751228202115"></a>Y (host certificate)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="en-us_topic_0000002614931227_p183781132115118"><a name="en-us_topic_0000002614931227_p183781132115118"></a><a name="en-us_topic_0000002614931227_p183781132115118"></a>Y (host certificate)</p>
</td>
</tr>
<tr id="en-us_topic_0000002614931227_row55261736962"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002614931227_p0526133614614"><a name="en-us_topic_0000002614931227_p0526133614614"></a><a name="en-us_topic_0000002614931227_p0526133614614"></a>Note: <strong id="en-us_topic_0000002614931227_b14835652968"><a name="en-us_topic_0000002614931227_b14835652968"></a><a name="en-us_topic_0000002614931227_b14835652968"></a>Y</strong> indicates that the function is supported, <strong id="en-us_topic_0000002614931227_b20835165215617"><a name="en-us_topic_0000002614931227_b20835165215617"></a><a name="en-us_topic_0000002614931227_b20835165215617"></a>N</strong> indicates that the function is not supported, and <strong id="en-us_topic_0000002614931227_b178357521264"><a name="en-us_topic_0000002614931227_b178357521264"></a><a name="en-us_topic_0000002614931227_b178357521264"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="en-us_topic_0184799386_section1383319120101"></a>

Replaces the TLS certificate on the host or device side.

> **NOTICE:** 
>
>- Initial certificates are used only in the deployment phase, for establishing initial security channels between devices and the user network. The security of initial certificates is not guaranteed by Huawei.
>- The user shall be liable for consequences of all security risks and incidents arising from using Huawei's initial certificates as service certificates.
>- The validity period of a Huawei's initial certificate starts from the manufacturing date and ends in 2099, depending on the production batch of the equipment.
>- It is recommended that users deploy a PKI system to issue certificates for devices and software on live networks and to manage the lifecycle of the certificates. For security purposes, certificates with short validity periods are recommended.
>- Services using an initial certificate will be interrupted when the certificate expires.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

1. You can run this command to replace the existing certificates regardless of their sources. Initial pre-installation typically happens in the equipment test phase. You are advised to replace the initial certificates before running services.
2. Certificate, private key, and CRL configurations:
    1. The number of levels in the certificate chain is configurable, with a minimum of two levels \(device certificate and root certificate\) and a maximum of fifteen levels \(device certificate, root certificate, secondary root certificate … up to the 14th-level root certificate\). By default, the factory setting uses three levels \(device certificate, root certificate, and secondary root certificate\). It is recommended that device certificates contain unique information to ensure security.
    2. You can replace only the certificate or update the CRL separately. However, the TLS certificate and CRL must match each other. The CRL can be updated only on the device side.
    3. A file name allows a maximum of 255 bytes, including the suffix. For example, the length of file name  **pub.pem**  is 7 bytes.
    4. File size:
        1. Certificate: up to 3072 bytes for the device and 2048 bytes for the host
        2. Private key: up to 4096 bytes
        3. CRL: up to 20480 bytes

    5. Certificate issuer name: up to 64 bytes
    6. The certificates must be in X.509v3 format. For a root CA or intermediate CA certificate, the "Basic Constraints" extensions must be "CA", and the "Key Usage" extensions must contain "Certificate Signature". The digital certificates and the CRL must be within the validity periods. You are advised to periodically update the configuration.
    7. Only PEM-encoded certificates and private keys are supported, and the CRL must be in CRL format.
    8. Only an RSA private key with the length of \[2048, 4096\] is supported. The private key must be in ciphertext, and the encryption algorithm of the private key can only be AES-256.
    9. Ensure that the private key, certificate, and CRL match each other. Otherwise, replacement fails.
    10. The private key and device certificate must be replaced together.
    11. You need to specify a complete certificate chain \(a larger  _N_  in -ca_N_  indicates a lower level\). Ensure that each lower-level certificate is issued by its higher-level certificate and the device certificate and CRL are issued by the root certificate of the lowest level. Otherwise, the certificate chain verification fails, and the configuration fails.
    12. When pre-installing or updating a private key, ensure that the password is the same as that entered for generating the private key.

3. Password configuration:
    1. The password is entered in interactive mode and is not displayed in plaintext. The password is a string of 8 to 15 characters and must contain at least two types of the following: uppercase letters, lowercase letters, digits, and special characters.
    2. The entered password must not be in the weak password dictionary. Otherwise, the configuration fails. The weak password dictionary is stored in the  **hccn\_weak\_dict.conf**  file in the  **/etc**  \(for the  **root**  user\) or  **/home/_$\{USER\}_**  \(for users except  **root**\) directory. The file permission is 600. You can add or delete the file content, but must not rename or delete the file. Otherwise, the weak password dictionary verification function becomes invalid.

4. Host-side certificate configuration:
    1. If certificates are configured on the host, the validity of the configuration is irrelevant to the device ID.
    2. To configure TLS certificates on the host, ensure that the permission on the  **hccn\_tool**  file is 555 and the permission on the  **/usr/local/Ascend/driver/tools**  directory \(where the tool is installed\) is 755.

5. After the configuration is complete, delete the ciphertext private key. The following message will be displayed: "\[warning\] Please delete the private key file after updating for security considerations."
6. During collective communication, the TLS certificate suite configured using this command is used for TLS authentication. If TLS authentication fails, a log is recorded.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -s -tls -i <dev_id> -path <file path> -pri <filename> -pub <filename> -ca1 <filename> [-ca2 <filename>] ...[-ca14 <filename>] [-crl <filename>] [-host]
```

## Parameters<a name="en-us_topic_0184799386_section10465854096"></a>

<a name="en-us_topic_0184799386_table827101275518"></a>
<table><thead align="left"><tr id="en-us_topic_0184799386_row429121265517"><th class="cellrowborder" valign="top" width="29.95%" id="mcps1.1.4.1.1"><p id="en-us_topic_0184799386_p1329121214558"><a name="en-us_topic_0184799386_p1329121214558"></a><a name="en-us_topic_0184799386_p1329121214558"></a>Parameter</p>
</th>
<th class="cellrowborder" valign="top" width="13.76%" id="mcps1.1.4.1.2"><p id="p14928362410"><a name="p14928362410"></a><a name="p14928362410"></a>Optional/Required</p>
</th>
<th class="cellrowborder" valign="top" width="56.28999999999999%" id="mcps1.1.4.1.3"><p id="en-us_topic_0184799386_p83121275519"><a name="en-us_topic_0184799386_p83121275519"></a><a name="en-us_topic_0184799386_p83121275519"></a>Description</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0184799386_row191899195459"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="en-us_topic_0184799386_p91902281586"><a name="en-us_topic_0184799386_p91902281586"></a><a name="en-us_topic_0184799386_p91902281586"></a>-i &lt;dev_id&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1992917674118"><a name="p1992917674118"></a><a name="p1992917674118"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="en-us_topic_0000002614931223_p17451457141517"><a name="en-us_topic_0000002614931223_p17451457141517"></a><a name="en-us_topic_0000002614931223_p17451457141517"></a><span id="en-us_topic_0000002614931223_ph16119162121517"><a name="en-us_topic_0000002614931223_ph16119162121517"></a><a name="en-us_topic_0000002614931223_ph16119162121517"></a>Logical ID of the software</span>. The <strong id="en-us_topic_0000002614931223_b823820395231"><a name="en-us_topic_0000002614931223_b823820395231"></a><a name="en-us_topic_0000002614931223_b823820395231"></a>NPU ID</strong> field queried by running the <strong id="en-us_topic_0000002614931223_b203142152219"><a name="en-us_topic_0000002614931223_b203142152219"></a><a name="en-us_topic_0000002614931223_b203142152219"></a>npu-smi info</strong> command is the value of the <strong id="en-us_topic_0000002614931223_b38385413386"><a name="en-us_topic_0000002614931223_b38385413386"></a><a name="en-us_topic_0000002614931223_b38385413386"></a>-i</strong> parameter.</p>
</td>
</tr>
<tr id="row14535125123912"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p125352523911"><a name="p125352523911"></a><a name="p125352523911"></a>-path &lt;file path&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p18535105153916"><a name="p18535105153916"></a><a name="p18535105153916"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1153516518398"><a name="p1153516518398"></a><a name="p1153516518398"></a>System path for storing the certificate file.</p>
</td>
</tr>
<tr id="row1874318562390"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p0743356183910"><a name="p0743356183910"></a><a name="p0743356183910"></a>-pri &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p4743756183919"><a name="p4743756183919"></a><a name="p4743756183919"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p6743056173912"><a name="p6743056173912"></a><a name="p6743056173912"></a>Private key file name.</p>
</td>
</tr>
<tr id="row161351720409"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p13135142164014"><a name="p13135142164014"></a><a name="p13135142164014"></a>-pub &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p98891023184017"><a name="p98891023184017"></a><a name="p98891023184017"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1613522124013"><a name="p1613522124013"></a><a name="p1613522124013"></a>File name of the device certificate.</p>
</td>
</tr>
<tr id="row1874155803917"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p208052051134017"><a name="p208052051134017"></a><a name="p208052051134017"></a>-ca1 &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p1896714543400"><a name="p1896714543400"></a><a name="p1896714543400"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p2522026104110"><a name="p2522026104110"></a><a name="p2522026104110"></a>Name of the level-1 root certificate file.</p>
</td>
</tr>
<tr id="row18612101715413"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p12613617194111"><a name="p12613617194111"></a><a name="p12613617194111"></a>-caN &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2061371784110"><a name="p2061371784110"></a><a name="p2061371784110"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p13805175174015"><a name="p13805175174015"></a><a name="p13805175174015"></a>Name of the level-<em id="i9943105317260"><a name="i9943105317260"></a><a name="i9943105317260"></a>N</em> root certificate file (1 &lt; <em id="i1294411531265"><a name="i1294411531265"></a><a name="i1294411531265"></a>N</em> &lt; 15).</p>
</td>
</tr>
<tr id="row15914103611424"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p1397813374425"><a name="p1397813374425"></a><a name="p1397813374425"></a>-crl &lt;filename&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p797883718421"><a name="p797883718421"></a><a name="p797883718421"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p199141336184213"><a name="p199141336184213"></a><a name="p199141336184213"></a>CRL file name.</p>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p379092172711"><a name="p379092172711"></a><a name="p379092172711"></a>If this option is specified, the host-side TLS information is set. If this option is not specified, the device-side TLS information is set by default.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section82714204319"></a>

- Example 1:

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -pri server_2.key -pub server_2.pem -ca1 1thCA.pem -ca2 2_1thCA.pem
    ```

    Replace the device-side TLS certificate for the device with logical ID 0.

    ```text
    Please enter pass phrase for pri key:
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

- Example 2:

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -crl cert.crl
    ```

    Update the device-side TLS CRL for the device with logical ID 0.

    ```text
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

- Example 3:

    ```bash
    hccn_tool -s -tls -i 0 -path ./CA/level3_CA/2048/sha256/1 -pri server_2.key -pub server_2.pem -ca1 1thCA.pem -ca2 2_1thCA.pem -host
    ```

    Replace the host-side TLS certificate for the device with logical ID 0.

    ```text
    Please enter pass phrase for pri key:
    [WARNING] Please delete the private key file after updating for security considerations.
    Cmd executed successfully!
    ```

## Output Description<a name="section55215490292"></a>

None.

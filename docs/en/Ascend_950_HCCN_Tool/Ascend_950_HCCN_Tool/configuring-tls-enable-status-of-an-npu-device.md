# Configuring TLS Enable Status of an NPU Device<a name="EN-US_TOPIC_0000002614931217"></a>

## Product Support<a name="section8178181118225"></a>

**Table  1** Support in different deployment scenarios

<a name="table17481317184015"></a>
<table><thead align="left"><tr id="en-us_topic_0000002508152086_row1152516361961"><th class="cellrowborder" rowspan="2" valign="top" id="mcps1.2.9.1.1"><p id="en-us_topic_0000002508152086_p65251336569"><a name="en-us_topic_0000002508152086_p65251336569"></a><a name="en-us_topic_0000002508152086_p65251336569"></a>Hardware Model/Scenario</p>
</th>
<th class="cellrowborder" colspan="2" valign="top" id="mcps1.2.9.1.2"><p id="en-us_topic_0000002508152086_p1452518361269"><a name="en-us_topic_0000002508152086_p1452518361269"></a><a name="en-us_topic_0000002508152086_p1452518361269"></a>PM (Bare Metal)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.3"><p id="en-us_topic_0000002508152086_p12525133617618"><a name="en-us_topic_0000002508152086_p12525133617618"></a><a name="en-us_topic_0000002508152086_p12525133617618"></a>PM + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.4"><p id="en-us_topic_0000002508152086_p175251236867"><a name="en-us_topic_0000002508152086_p175251236867"></a><a name="en-us_topic_0000002508152086_p175251236867"></a>PM + Unprivileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.5"><p id="en-us_topic_0000002508152086_p135256361566"><a name="en-us_topic_0000002508152086_p135256361566"></a><a name="en-us_topic_0000002508152086_p135256361566"></a>VM Passthrough</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.6"><p id="en-us_topic_0000002508152086_p9525173614613"><a name="en-us_topic_0000002508152086_p9525173614613"></a><a name="en-us_topic_0000002508152086_p9525173614613"></a>VM Passthrough + Privileged Container</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.1.7"><p id="en-us_topic_0000002508152086_p35251836365"><a name="en-us_topic_0000002508152086_p35251836365"></a><a name="en-us_topic_0000002508152086_p35251836365"></a>VM Passthrough + Unprivileged Container</p>
</th>
</tr>
<tr id="en-us_topic_0000002508152086_row175255361369"><th class="cellrowborder" valign="top" id="mcps1.2.9.2.1"><p id="en-us_topic_0000002508152086_p175257363614"><a name="en-us_topic_0000002508152086_p175257363614"></a><a name="en-us_topic_0000002508152086_p175257363614"></a><strong id="b1360881723017"><a name="b1360881723017"></a><a name="b1360881723017"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.2"><p id="en-us_topic_0000002508152086_p175255361567"><a name="en-us_topic_0000002508152086_p175255361567"></a><a name="en-us_topic_0000002508152086_p175255361567"></a>Running User Group (Non-<strong id="b1837272019309"><a name="b1837272019309"></a><a name="b1837272019309"></a>root</strong> User)</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.3"><p id="en-us_topic_0000002508152086_p052519366616"><a name="en-us_topic_0000002508152086_p052519366616"></a><a name="en-us_topic_0000002508152086_p052519366616"></a><strong id="b2546421153018"><a name="b2546421153018"></a><a name="b2546421153018"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.4"><p id="en-us_topic_0000002508152086_p1152593617617"><a name="en-us_topic_0000002508152086_p1152593617617"></a><a name="en-us_topic_0000002508152086_p1152593617617"></a><strong id="b3647322183015"><a name="b3647322183015"></a><a name="b3647322183015"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.5"><p id="en-us_topic_0000002508152086_p175251236967"><a name="en-us_topic_0000002508152086_p175251236967"></a><a name="en-us_topic_0000002508152086_p175251236967"></a><strong id="b810022453020"><a name="b810022453020"></a><a name="b810022453020"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.6"><p id="en-us_topic_0000002508152086_p175252363616"><a name="en-us_topic_0000002508152086_p175252363616"></a><a name="en-us_topic_0000002508152086_p175252363616"></a><strong id="b132765254301"><a name="b132765254301"></a><a name="b132765254301"></a>root</strong> User</p>
</th>
<th class="cellrowborder" valign="top" id="mcps1.2.9.2.7"><p id="en-us_topic_0000002508152086_p35251336568"><a name="en-us_topic_0000002508152086_p35251336568"></a><a name="en-us_topic_0000002508152086_p35251336568"></a><strong id="b554016261309"><a name="b554016261309"></a><a name="b554016261309"></a>root</strong> User</p>
</th>
</tr>
</thead>
<tbody><tr id="en-us_topic_0000002508152086_row18525103618619"><td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.1 mcps1.2.9.2.1 "><p id="en-us_topic_0000002508152086_p7525736665"><a name="en-us_topic_0000002508152086_p7525736665"></a><a name="en-us_topic_0000002508152086_p7525736665"></a><span id="ph12140626193614"><a name="ph12140626193614"></a><a name="ph12140626193614"></a>Atlas 350 accelerator card</span></p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.2 "><p id="en-us_topic_0000002508152086_p29591819165216"><a name="en-us_topic_0000002508152086_p29591819165216"></a><a name="en-us_topic_0000002508152086_p29591819165216"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.2 mcps1.2.9.2.3 "><p id="p165214437531"><a name="p165214437531"></a><a name="p165214437531"></a>N</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.3 mcps1.2.9.2.4 "><p id="en-us_topic_0000002508152086_p4905122915216"><a name="en-us_topic_0000002508152086_p4905122915216"></a><a name="en-us_topic_0000002508152086_p4905122915216"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.4 mcps1.2.9.2.5 "><p id="p8491161514521"><a name="p8491161514521"></a><a name="p8491161514521"></a>Y (host certificate)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.5 mcps1.2.9.2.6 "><p id="p1247513092013"><a name="p1247513092013"></a><a name="p1247513092013"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.6 mcps1.2.9.2.7 "><p id="p179751228202115"><a name="p179751228202115"></a><a name="p179751228202115"></a>Y (device and host certificates)</p>
</td>
<td class="cellrowborder" valign="top" width="12.5%" headers="mcps1.2.9.1.7 "><p id="p5975152811210"><a name="p5975152811210"></a><a name="p5975152811210"></a>Y (host certificate)</p>
</td>
</tr>
<tr id="en-us_topic_0000002508152086_row55261736962"><td class="cellrowborder" colspan="8" valign="top" headers="mcps1.2.9.1.1 mcps1.2.9.1.2 mcps1.2.9.1.3 mcps1.2.9.1.4 mcps1.2.9.1.5 mcps1.2.9.1.6 mcps1.2.9.1.7 mcps1.2.9.2.1 mcps1.2.9.2.2 mcps1.2.9.2.3 mcps1.2.9.2.4 mcps1.2.9.2.5 mcps1.2.9.2.6 mcps1.2.9.2.7 "><p id="en-us_topic_0000002508152086_p0526133614614"><a name="en-us_topic_0000002508152086_p0526133614614"></a><a name="en-us_topic_0000002508152086_p0526133614614"></a>Note: <strong id="b1196681143114"><a name="b1196681143114"></a><a name="b1196681143114"></a>Y</strong> indicates that the function is supported, <strong id="b129673118310"><a name="b129673118310"></a><a name="b129673118310"></a>N</strong> indicates that the function is not supported, and <strong id="b1996711117318"><a name="b1996711117318"></a><a name="b1996711117318"></a>N/A</strong> indicates that the function is not applicable or is not currently planned.</p>
</td>
</tr>
</tbody>
</table>

## Function<a name="en-us_topic_0184799386_section1383319120101"></a>

Sets the TLS switch status for the host or device.

## Precautions<a name="en-us_topic_0238914640_section127461744152119"></a>

- For services that depend on TLS communication, the TLS switch status must be the same for both communication parties. Otherwise, service running may be affected.
- This command supports configuration persistence.

## Syntax<a name="en-us_topic_0184799386_section2083668161015"></a>

```bash
hccn_tool -s -tls -i <dev_id> -enable <enable_val> [-host]
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
<tr id="row14535125123912"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p1134164015249"><a name="p1134164015249"></a><a name="p1134164015249"></a>-enable &lt;enable_val&gt;</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p18535105153916"><a name="p18535105153916"></a><a name="p18535105153916"></a>Required</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p88891211133217"><a name="p88891211133217"></a><a name="p88891211133217"></a>TLS enable status:</p>
<a name="ul146911122193219"></a><a name="ul146911122193219"></a><ul id="ul146911122193219"><li><strong id="b1877512974020"><a name="b1877512974020"></a><a name="b1877512974020"></a>0</strong>: disabled</li><li><strong id="b201251113154018"><a name="b201251113154018"></a><a name="b201251113154018"></a>1</strong>: enabled If this parameter is not set on the device, the default value <strong id="b1812372018401"><a name="b1812372018401"></a><a name="b1812372018401"></a>1</strong> is used.</li></ul>
</td>
</tr>
<tr id="row1817383952015"><td class="cellrowborder" valign="top" width="29.95%" headers="mcps1.1.4.1.1 "><p id="p7173839152017"><a name="p7173839152017"></a><a name="p7173839152017"></a>-host</p>
</td>
<td class="cellrowborder" valign="top" width="13.76%" headers="mcps1.1.4.1.2 "><p id="p2173173912205"><a name="p2173173912205"></a><a name="p2173173912205"></a>Optional</p>
</td>
<td class="cellrowborder" valign="top" width="56.28999999999999%" headers="mcps1.1.4.1.3 "><p id="p1017333911208"><a name="p1017333911208"></a><a name="p1017333911208"></a>If this option is specified, the host-side TLS information is set. If this option is not specified, the device-side TLS information is set by default.</p>
</td>
</tr>
</tbody>
</table>

## Example<a name="section82714204319"></a>

- Example 1:

    ```bash
    hccn_tool -s -tls -i 0 -enable 1
    ```

    Enable the device-side TLS for the device with logical ID 0.

    ```text
    Cmd executed successfully!
    ```

- Example 2:

    ```bash
    hccn_tool -s -tls -i 0 -enable 0 -host
    ```

    Disable the host-side TLS for the device with logical ID 0.

    ```text
    Cmd executed successfully!
    ```

## Output Description<a name="section55215490292"></a>

None.

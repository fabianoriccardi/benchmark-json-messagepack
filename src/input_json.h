/**
 * The data used for the benchmark.
 */

// Short keys and numeric values
const char shortInts[] =
    "{\"int1\":0,\"int2\":2,\"int3\":3,\"n2\":5.2,\"n1\":10.45}";
// Test an array of strings
const char arrayString[] = "[\"hello\",\"world\",\"testing\",\"message "
                           "pack\",\"!\",\"ARDUINO\",\" JSON\",\"LIBRARY\"]";
// Test an array of integers
const char arrayInt[] = "[0,1,23212,3,2039394,5,6,7122335,8,565100879]";
// Null
const char jsonNull[] = "{\"key\":null}";
// Generic short JSON, the first example on msgpack.org
const char objMsgPack[] = "{\"compact\":true,\"schema\":0}";
// JSON found at json.org
const char objOrg[] =
    "{\"glossary\":{\"title\":\"example "
    "glossary\",\"GlossDiv\":{\"title\":\"S\",\"GlossList\":{\"GlossEntry\":{"
    "\"ID\":\"SGML\",\"SortAs\":\"SGML\",\"GlossTerm\":\"Standard Generalized "
    "Markup Language\",\"Acronym\":\"SGML\",\"Abbrev\":\"ISO "
    "8879:1986\",\"GlossDef\":{\"para\":\"A meta-markup language, used to "
    "create markup languages such as "
    "DocBook.\",\"GlossSeeAlso\":[\"GML\",\"XML\"]},\"GlossSee\":\"markup\"}}}}"
    "}";
// JSON found in documentation of WoT (iot.mozilla.org)
const char objWoT[] =
    "{\"id\":\"https://mywebthingserver.com/things/switch\",\"title\":\"On/Off "
    "Switch\",\"description\":\"A web connected "
    "switch\",\"properties\":{\"on\":{\"title\":\"On/"
    "Off\",\"type\":\"boolean\",\"description\":\"Whether the lamp is turned "
    "on\",\"links\":[{\"href\":\"/things/switch/properties/on\"}]}}}";
// JSON found in documentation of Tasmota firmware
const char objTasmota[] =
    "{\"Status\":{\"Module\":1,\"FriendlyName\":\"XXX\",\"Topic\":\"sonoff\","
    "\"ButtonTopic\":\"0\",\"Power\":0,\"PowerOnState\":0,\"LedState\":1,"
    "\"SaveData\":0,\"SaveState\":1,\"ButtonRetain\":0,\"PowerRetain\":0},"
    "\"StatusPRM\":{\"Baudrate\":115200,\"GroupTopic\":\"sonoffs\",\"OtaUrl\":"
    "\"XXX\",\"Uptime\":\"1 "
    "02:33:26\",\"Sleep\":150,\"BootCount\":32,\"SaveCount\":72,"
    "\"SaveAddress\":\"FB000\"},\"StatusFWR\":{\"Version\":\"5.12.0a\","
    "\"BuildDateTime\":\"2018.02.11 "
    "16:15:40\",\"Boot\":31,\"Core\":\"2_4_0\",\"SDK\":\"2.1.0(deb1901)\"},"
    "\"StatusLOG\":{\"SerialLog\":0,\"WebLog\":4,\"SysLog\":0,\"LogHost\":"
    "\"domus1\",\"LogPort\":514,\"SSId1\":\"XXX\",\"SSId2\":\"XXX\","
    "\"TelePeriod\":300,\"SetOption\":\"00000001\"},\"StatusMEM\":{"
    "\"ProgramSize\":457,\"Free\":544,\"Heap\":23,\"ProgramFlashSize\":1024,"
    "\"FlashSize\":1024,\"FlashMode\":3},\"StatusNET\":{\"Hostname\":\"XXX\","
    "\"IPAddress\":\"192.168.178.XX\",\"Gateway\":\"192.168.178.XX\","
    "\"Subnetmask\":\"255.255.255.XX\",\"DNSServer\":\"192.168.178.XX\","
    "\"Mac\":\"2C:3A:E8:XX:XX:XX\",\"Webserver\":2,\"WifiConfig\":4},"
    "\"StatusTIM\":{\"UTC\":\"Thu Feb 15 00:00:50 2018\",\"Local\":\"Thu Feb "
    "15 01:00:50 2018\",\"StartDST\":\"Sun Mar 25 02:00:00 "
    "2018\",\"EndDST\":\"Sun Oct 28 03:00:00 "
    "2018\",\"Timezone\":1},\"StatusSNS\":{\"Time\":\"2018.02.15 "
    "01:00:50\",\"Switch1\":\"OFF\"},\"StatusSTS\":{\"Time\":\"2018.02.15 "
    "01:00:50\",\"Uptime\":\"1 "
    "02:33:26\",\"Vcc\":3.504,\"POWER\":\"OFF\",\"Wifi\":{\"AP\":1,\"SSId\":"
    "\"XXX\",\"RSSI\":100,\"APMac\":\"34:31:C4:XX:XX:XX\"}}}";
// mid-length JSON from documentation of Home Assistant
const char objHomeAssistant[] =
    "[{\"context_user_id\":null,\"domain\":\"alarm_control_panel\",\"entity_"
    "id\":\"alarm_control_panel.area_001\",\"message\":\"changed to "
    "disarmed\",\"name\":\"Security\",\"when\":\"2020-06-20T16:44:26.127295+00:"
    "00\"},{\"context_user_id\":null,\"domain\":\"homekit\",\"entity_id\":"
    "\"alarm_control_panel.area_001\",\"message\":\"send command "
    "alarm_arm_night for "
    "Security\",\"name\":\"HomeKit\",\"when\":\"2020-06-21T02:59:05.759645+00:"
    "00\"},{\"context_user_id\":null,\"domain\":\"alarm_control_panel\","
    "\"entity_id\":\"alarm_control_panel.area_001\",\"message\":\"changed to "
    "armed_night\",\"name\":\"Security\",\"when\":\"2020-06-21T02:59:06.015463+"
    "00:00\"}]";
// long and mixed content, randomly generated on json-generator.com
const char objRandom[] =
    "[{\"_id\":\"5e70a2599fdb2683bf64f6ee\",\"index\":0,\"guid\":\"b1eb24b5-"
    "a686-4a55-a001-7ebaee5a6d38\",\"isActive\":false,\"balance\":\"$2,144."
    "19\",\"picture\":\"http://placehold.it/"
    "32x32\",\"age\":31,\"eyeColor\":\"blue\",\"name\":\"Berger "
    "Daniel\",\"gender\":\"male\",\"company\":\"GEEKMOSIS\",\"email\":"
    "\"bergerdaniel@geekmosis.com\",\"phone\":\"+1 (855) "
    "492-2598\",\"address\":\"512 Hinsdale Street, Sperryville, Maine, "
    "9393\",\"about\":\"In in aute ea eiusmod dolor consectetur minim officia "
    "ea ad ipsum est veniam. Irure esse tempor id sit consequat ea magna quis "
    "id. Amet consequat qui anim irure elit do pariatur duis veniam "
    "mollit.\\r\\n\",\"registered\":\"2014-12-13T08:46:38 "
    "-01:00\",\"latitude\":65.127475,\"longitude\":3.310166,\"tags\":["
    "\"culpa\",\"ex\",\"consectetur\",\"cillum\",\"anim\",\"velit\","
    "\"occaecat\"],\"friends\":[{\"id\":0,\"name\":\"Sosa "
    "Harper\"},{\"id\":1,\"name\":\"Rollins "
    "Decker\"},{\"id\":2,\"name\":\"Deena Drake\"}],\"greeting\":\"Hello, "
    "Berger Daniel! You have 7 unread "
    "messages.\",\"favoriteFruit\":\"apple\"},{\"_id\":"
    "\"5e70a259708a5a37336b6763\",\"index\":1,\"guid\":\"13520ef9-7376-4fa9-"
    "ab2d-f4969fc9a8a4\",\"isActive\":true,\"balance\":\"$3,444.46\","
    "\"picture\":\"http://placehold.it/"
    "32x32\",\"age\":29,\"eyeColor\":\"brown\",\"name\":\"Yolanda "
    "Mckay\",\"gender\":\"female\",\"company\":\"DREAMIA\",\"email\":"
    "\"yolandamckay@dreamia.com\",\"phone\":\"+1 (801) "
    "526-3521\",\"address\":\"299 Judge Street, Denio, New Jersey, "
    "7087\",\"about\":\"Veniam irure magna nulla excepteur non exercitation ex "
    "ullamco ex adipisicing nostrud ipsum. Ad aute velit reprehenderit "
    "proident velit amet. Ut amet nulla sunt velit laboris aliquip officia "
    "nulla Lorem in elit consectetur ad. Id sit anim nisi ut aute velit id "
    "occaecat aliquip occaecat ut "
    "labore.\\r\\n\",\"registered\":\"2018-03-28T05:08:23 "
    "-02:00\",\"latitude\":7.713533,\"longitude\":111.534573,\"tags\":["
    "\"eiusmod\",\"elit\",\"Lorem\",\"occaecat\",\"nostrud\",\"fugiat\",\"ea\"]"
    ",\"friends\":[{\"id\":0,\"name\":\"Dolores "
    "Moran\"},{\"id\":1,\"name\":\"Fay Wagner\"},{\"id\":2,\"name\":\"Richmond "
    "Slater\"}],\"greeting\":\"Hello, Yolanda Mckay! You have 10 unread "
    "messages.\",\"favoriteFruit\":\"apple\"}]";

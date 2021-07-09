/**
 * Test performances of MessagePack vs JSON using ArduinoJson library.
 */

#include "benchmark.h"
#include "input_json.h"
#include <Arduino.h>

/**
 * Define the json used for benchmark. The order matters!
 */
Item items[] = {{"obj int", shortInts},    {"array string", arrayString},
                {"array int", arrayInt},   {"obj null", jsonNull},
                {"obj random", objRandom}, {"Msgpack", objMsgPack},
                {"HA", objHomeAssistant},  {"json.org", objOrg},
                {"WoT", objWoT},           {"Tasmota", objTasmota}};

const int nJsons = sizeof(items) / sizeof(items[0]);

ItemResults results[nJsons];

void doBenchmarks() {
  for (int i = 0; i < nJsons; ++i) {
    results[i] = benchmarkJson(items[i]);
    Serial.println();
    Serial.println();
  }

  // print all the information in CSV format

  Serial.println("name,deserTimeJson,deserTimeMsgPack,serTimeJson,"
                 "serTimeMsgPack,serSpaceJson,serSpaceMsgPack");
  for (int i = 0; i < nJsons; ++i) {
    Serial.print(results[i].name);
    Serial.print(',');
    Serial.print(results[i].deserTimeJson);
    Serial.print(',');
    Serial.print(results[i].deserTimeMsgPack);
    Serial.print(',');
    Serial.print(results[i].serTimeJson);
    Serial.print(',');
    Serial.print(results[i].serTimeMsgPack);
    Serial.print(',');
    Serial.print(results[i].serSpaceJson);
    Serial.print(',');
    Serial.println(results[i].serSpaceMsgPack);
  }

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  Serial.println();

  Serial.println("Benchmark of (de)serialization of JSON and MessagePack using "
                 "ArduinoJson");
  Serial.println();

  Serial.println("Press a key to start the benchmark");
  while (!Serial.available()) {
    delay(20);
  }

  // Flush received bytes
  while (Serial.available()) {
    Serial.read();
  }
}

void loop() {
  doBenchmarks();

  Serial.println("Press a key to repeat the benchmark");
  while (!Serial.available()) {
    delay(20);
  }

  // Flush received bytes
  while (Serial.available()) {
    Serial.read();
  }

  Serial.println();
  Serial.println();
  Serial.println();
  Serial.println();
}

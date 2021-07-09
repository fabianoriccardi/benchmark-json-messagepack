#include "benchmark.h"
#include "benchmark_config.h"
#include "benchmark_utils.h"
#include <Arduino.h>
#include <ArduinoJson.h>

StaticJsonDocument<5000> doc;
char result[2000];

/**
 * Print first n characters of a string, eventually add ellips.
 */
void printFirstNChars(const char text[], int n) {
  // Print the first 30 chars of the text
  int bufferLength = n + 1;
  char buff[bufferLength];
  int wouldBeprintedChars = snprintf(buff, bufferLength, "%s", text);
  // int n = Serial.printf("%.30s", text);
  Serial.print(buff);
  if (wouldBeprintedChars >= bufferLength) {
    Serial.print("...");
  }
}

ItemResults benchmarkJson(const Item &item) {
  Serial.print("Benchmarking \"");
  Serial.print(item.name);
  Serial.print("\", lenght:");
  Serial.print(strlen(item.json));
  Serial.print("byte, content: ");
  printFirstNChars(item.json, 30);
  Serial.println();

  ItemResults itemResults;
  strcpy(itemResults.name, "");

  DeserializationError error = deserializeJson(doc, item.json);
  if (error == DeserializationError::Ok) {
    // Serial.println("parsing ok");
  } else {
    Serial.println("parsing error, skipping this text");
    return itemResults;
  }
  strcpy(itemResults.name, item.name);

  Serial.println("Serialization results");
  struct Result rMsgPack;
  for (int i = 0; i < N_ITERATION; i++) {
    struct Result r =
        benchmarkSerializationMsgPack(doc, result, sizeof(result));
    if (i == 0) {
      rMsgPack = r;
    }

    int n = 70;
    char buff[n];
    snprintf(buff, n, "    MessagePack  time: %3luus written: %3lubyte", r.time,
             r.byteWritten);
    Serial.println(buff);
    itemResults.serTimeMsgPack = r.time;
    itemResults.serSpaceMsgPack = r.byteWritten;
  }

  struct Result rJson;
  for (int i = 0; i < N_ITERATION; i++) {
    struct Result r = benchmarkSerializationJson(doc, result, sizeof(result));
    if (i == 0) {
      rJson = r;
    }

    int n = 70;
    char buff[n];
    snprintf(buff, n, "    Json         time: %3luus written: %3lubyte", r.time,
             r.byteWritten);
    Serial.println(buff);
    itemResults.serTimeJson = r.time;
    itemResults.serSpaceJson = r.byteWritten;
  }

  float ratioTime = ((float)rMsgPack.time - rJson.time) / rJson.time * 100;
  float ratioByte = ((float)rMsgPack.byteWritten - rJson.byteWritten) /
                    rJson.byteWritten * 100;
  Serial.println("  Serialization improvements over JSON");
  Serial.println(String("      time: ") + ratioTime + "% size: " + ratioByte +
                 "%");

  // Deserialization benchmark

  // Deserialization of Msgpack
  Serial.println("Deserialization results");
  serializeMsgPack(doc, result, sizeof(result));
  unsigned long deserMsgPackTime;
  for (int i = 0; i < N_ITERATION; i++) {
    unsigned long r =
        benchmarkDeserializationMsgPack(result, sizeof(result), doc);
    if (i == 0) {
      deserMsgPackTime = r;
    }

    int n = 50;
    char buff[n];
    snprintf(buff, n, "    MessagePack     time: %3luus", deserMsgPackTime);
    Serial.println(buff);
    itemResults.deserTimeMsgPack = r;
  }

  // Deserialization of Json
  serializeJson(doc, result, sizeof(result));
  unsigned long deserJsonTime;
  for (int i = 0; i < N_ITERATION; i++) {
    unsigned long r = benchmarkDeserializationJson(result, sizeof(result), doc);
    if (i == 0) {
      deserJsonTime = r;
    }

    int n = 50;
    char buff[n];
    snprintf(buff, n, "    Json            time: %3luus", deserJsonTime);
    Serial.println(buff);
    itemResults.deserTimeJson = r;
  }
  float deserRatioTime =
      ((float)deserMsgPackTime - deserJsonTime) / deserJsonTime * 100;
  Serial.println("  Deserialization improvements over JSON");
  Serial.println(String("      time: ") + deserRatioTime + "%");

  return itemResults;
}
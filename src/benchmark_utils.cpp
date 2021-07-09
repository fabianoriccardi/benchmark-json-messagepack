#include "benchmark_utils.h"

struct Result benchmarkSerializationMsgPack(JsonDocument &doc, char *buffer,
                                            int length) {
  unsigned long a = micros();
  unsigned long bw = serializeMsgPack(doc, buffer, length);
  unsigned long b = micros();
  return {.time = (b - a), .byteWritten = bw};
}

struct Result benchmarkSerializationJson(JsonDocument &doc, char *buffer,
                                         int length) {
  unsigned long a = micros();
  unsigned long bw = serializeJson(doc, buffer, length);
  unsigned long b = micros();
  return {.time = (b - a), .byteWritten = bw};
}

unsigned long benchmarkDeserializationMsgPack(const char *buffer, int length,
                                              JsonDocument &doc) {
  unsigned long a = micros();
  deserializeMsgPack(doc, buffer, length);
  unsigned long b = micros();
  return b - a;
}

unsigned long benchmarkDeserializationJson(const char *buffer, int length,
                                           JsonDocument &doc) {
  unsigned long a = micros();
  deserializeJson(doc, buffer, length);
  unsigned long b = micros();
  return b - a;
}
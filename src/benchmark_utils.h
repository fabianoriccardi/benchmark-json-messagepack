#ifndef BENCHMARK_UTILS_H
#define BENCHMARK_UTILS_H

#include <ArduinoJson.h>

/**
 * Contain the result of a single serialization test.
 */
struct Result {
  unsigned long time;
  unsigned long byteWritten;
};

/**
 * Benchmark the serialization of a MessagePack.
 * Return the time elapsed in microseconds and the bytes written.
 */
struct Result benchmarkSerializationMsgPack(JsonDocument &doc, char *buffer,
                                            int length);

/**
 * Benchmark the serialization of a JSON.
 * Return the time elapsed in microseconds and the bytes written.
 */
struct Result benchmarkSerializationJson(JsonDocument &doc, char *buffer,
                                         int length);

/**
 * Benchmark the deserialization of a MessagePack.
 * Return the time elapsed in microseconds.
 */
unsigned long benchmarkDeserializationMsgPack(const char *buffer, int length,
                                              JsonDocument &doc);

/**
 * Benchmark the deserialization of a JSON.
 * Return the time elapsed in microseconds.
 */
unsigned long benchmarkDeserializationJson(const char *buffer, int length,
                                           JsonDocument &doc);

#endif // END BENCHMARK_UTILS_H
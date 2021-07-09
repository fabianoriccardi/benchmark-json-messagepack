#ifndef BENCHMARK_H
#define BENCHMARK_H

/**
 * Results about an input Item.
 */
typedef struct {
  char name[20];
  unsigned long deserTimeJson;
  unsigned long deserTimeMsgPack;

  unsigned long serTimeJson;
  unsigned long serTimeMsgPack;

  unsigned long serSpaceJson;
  unsigned long serSpaceMsgPack;
} ItemResults;

/**
 * Info about an input item.
 */
typedef struct {
  char name[20];
  const char *json;
} Item;

/**
 * Benchmark the performances given on a specific JSON.
 */
ItemResults benchmarkJson(const Item &item);

#endif // END BENCHMARK_H
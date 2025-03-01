#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
  int res;
  struct hash_map* map = hash_map_create(100);

  hash_map_insert(map, "aboba", 0);
  hash_map_insert(map, "abobwf", 32);
  hash_map_insert(map, "abobs", 2);

  
  res = hash_map_size(map);
  printf("size = %d\n", res);

  res = hash_map_find(map, "aboba");
  printf("%d\n", res);

  res = hash_map_get(map, "abobwf");
  printf("%d\n", res);

  res = hash_map_remove(map, "abobwf");
  printf("%d\n", res);

  res = hash_map_find(map, "abobwf");
  printf("%d\n", res);

  hash_map_free(map);

  return 0;
}
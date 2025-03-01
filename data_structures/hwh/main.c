#include <stdio.h>
#include <stdlib.h>

#include "hash_map.h"

int main() {
  int s;
  struct hash_map* map = hash_map_create(10);
  
  s = hash_map_size(map);
  printf("%d", s);

  hash_map_free(map);

  return 0;
}
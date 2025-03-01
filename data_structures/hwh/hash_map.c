#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_map.h"

const unsigned R = 10u;
const unsigned Q = 31u;

unsigned get_hash(const char *pat, const char *end) {
  unsigned p = 0;
  for (; pat != end; ++pat)
    p = (p * R + *pat) % Q;
  return p;
}

struct hash_map* hash_map_create(int size) {
  struct hash_map* ret = malloc(sizeof(struct hash_map));
  ret->array = malloc(size * sizeof(struct node*));
  memset(ret->array, 0, size * sizeof(struct node*));
  if (ret == NULL || ret->array == NULL) {
    printf("Error creating hash_map, malloc returned NULL");
  }
  ret->len = size;
  return ret;
}

void hash_map_insert(struct hash_map* map, const char* key, int value){
  return;
}

int hash_map_get(const struct hash_map* map, const char* key){
  return 1;
}

int hash_map_update(struct hash_map* map, const char* key, int value){ 
  return 1;
}

int hash_map_remove(struct hash_map* map, const char* key, int value){
  return 1;
}

void hash_map_free(struct hash_map* map) {
  int i;
  struct node *ptr, *tmp;
  for(i=0; i<map->len; i++) {
    ptr = map->array[i];
    while (ptr) {
      tmp = ptr;
      ptr = ptr->next;
      free(tmp);
    }
  }
  free(map->array);
  free(map);
}


int hash_map_size(const struct hash_map* map) {
  int i, count;
  struct node* ptr;
  count = 0;
  for(i=0; i<map->len; i++) {
    ptr = map->array[i];
    while (ptr) {
      count++;
      ptr = ptr->next;
    }
  }
  return count;
}

//TODO rehash(struct hash_map map);
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_map.h"

const unsigned R = 10u;
const unsigned Q = 31u;

static unsigned get_hash(const char *pat) {
  unsigned p = 0;
  for (; *pat != '\0'; ++pat)
    p = (p * R + *pat) % Q;
  return p;
}

static void free_node(struct node* node) {
  free(node->key);
  free(node);
}

static struct node* create_node(const char *key, int value) {
  struct node* ret = malloc(sizeof(struct node));
  ret->key = malloc(strlen(key) * sizeof(char));
  if (ret == NULL) {
    printf("error creating node");
    return NULL;
  }
  strcpy(ret->key, key);
  ret->value = value;
  return ret;
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

//No rehashing
void hash_map_insert(struct hash_map* map, const char* key, int value){
  int hash;
  struct node *ptr;
  hash = get_hash(key);
  if (hash>=map->len) {
    printf("error inserting key");
    return;
  } 
  if (map->array[hash] == NULL) { //no collision
    map->array[hash] = create_node(key, value);
  } else { //collision
    ptr = map->array[hash];
    while (ptr->next)
    {
      ptr = ptr->next;
    }
    ptr->next = create_node(key, value);
  }
}

int hash_map_find(const struct hash_map* map, const char* key) {
  int hash;
  struct node *ptr;
  hash = get_hash(key);
  if (map->array[hash] == NULL) {
    return 0;
  } else {
    ptr = map->array[hash];
    while (ptr)
    {
      if (strcmp(key, ptr->key) == 0) {
        return 1;
      }
      ptr = ptr->next;
    }
  }
  return 0;
}

int hash_map_get(const struct hash_map* map, const char* key){
  int hash;
  struct node *ptr;
  hash = get_hash(key);
  if (!hash_map_find(map, key)) {
    printf("error getting value from hash_map: no element with such key found");
    abort();
  }
  ptr = map->array[hash];
  while (ptr) {
    if (strcmp(key, ptr->key) == 0) {
      return ptr->value;
    }
    ptr = ptr->next;
  }
  //we should not be here
  assert(0);
  return -1;
}

int hash_map_update(struct hash_map* map, const char* key, int value){ 
  return 1;
}

int hash_map_remove(struct hash_map* map, const char* key){
  int hash;
  struct node *ptr, *tmp;
  hash = get_hash(key);
  //if (!hash_map_find(map, key)) return 0;
  ptr = map->array[hash];
  if (strcmp(key, ptr->key)==0) {
    tmp = ptr;
    map->array[hash] = ptr->next;
    free_node(tmp);
    return 1;
  }
  while (ptr->next) {
    if (strcmp(key, ptr->next->key)) {
      tmp = ptr->next;
      ptr->next = ptr->next->next;
      free_node(tmp);
      return 1;
    }
    ptr = ptr->next;
  }
  return 0;
}

void hash_map_free(struct hash_map* map) {
  int i;
  struct node *ptr, *tmp;
  for(i=0; i<map->len; i++) {
    ptr = map->array[i];
    while (ptr) {
      tmp = ptr;
      ptr = ptr->next;
      free_node(tmp);
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

//TODO static void rehash(struct hash_map map);
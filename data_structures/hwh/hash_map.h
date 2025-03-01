#pragma once
struct node {
  struct node* next;
  char* key;
  int value;
};

struct hash_map {
  int len;
  struct node** array;
};

struct hash_map* hash_map_create(int size);
void hash_map_insert(struct hash_map* map, const char* key, int value);
int hash_map_find(const struct hash_map* map, const char* key);
int hash_map_get(const struct hash_map* map, const char* key);
int hash_map_update(struct hash_map* map, const char* key, int value);
int hash_map_remove(struct hash_map* map, const char* key);
int hash_map_size(const struct hash_map* map);
void hash_map_free(struct hash_map* map);

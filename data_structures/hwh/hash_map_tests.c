#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_map.h"
#include "hash_map_tests.h"

char key1[] = "Moscow";
char key2[] = "Berlin";
char key3[] = "Paris";
int value1 = 0;
int value2 = 32;
int value3 = 17;

static void fill_map(struct hash_map* map) {
  hash_map_insert(map, key1, value1);
  hash_map_insert(map, key2, value2);
  hash_map_insert(map, key3, value3);
}

static void test_create_free() {
  struct hash_map* map = hash_map_create(100);
  assert(map!=NULL);
  assert(hash_map_size(map)==0);
  hash_map_free(map);
  printf("Test 1 create_free passed successfully\n");
}

static void test_insert() {
  struct hash_map* map = hash_map_create(30);
  fill_map(map);
  assert(hash_map_size(map)==3);
  hash_map_free(map);
  printf("Test 2 insert passed successfully\n");
}

static void test_find() {
  struct hash_map* map = hash_map_create(30);
  fill_map(map);
  assert(hash_map_find(map, key2)>0);
  hash_map_free(map);
  printf("Test 3 find passed successfully\n");
}

static void test_get() {
  struct hash_map* map = hash_map_create(100);
  fill_map(map);
  assert(hash_map_get(map, key2)==value2);
  hash_map_free(map);
  printf("Test 4 get passed successfully\n");
}

static void test_remove() {
  struct hash_map* map = hash_map_create(100);
  fill_map(map);
  assert(hash_map_remove(map, key2)>0);
  assert(hash_map_find(map, key2) == 0);
  hash_map_free(map);
  printf("Test 5 remove passed successfully\n");
}

static void test_update() {
  struct hash_map* map = hash_map_create(100);
  fill_map(map);
  hash_map_update(map, key2, 40);
  assert(hash_map_get(map, key2) == 40);
  hash_map_free(map);
  printf("Test 6 update passed successfully\n");
}

void run_tests() {
  test_create_free();
  test_insert();
  test_find();
  test_get();
  test_remove();
  test_update();
}
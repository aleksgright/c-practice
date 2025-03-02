#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_map.h"
#include "hash_map_tests.h"

#define BUFF_SIZE 30

int main(int argc, char **argv)
{
  int i, n, text_len;
  char in;
  char buffer[BUFF_SIZE] = {0};
  char *buff_ptr = buffer;
  struct hash_map *map = hash_map_create(1000);
  if (argc > 1)
  {
    if (strcmp(argv[1], "--tests") == 0)
    {
      run_tests();
    }
  }

  if (scanf("%d", &n) != 1)
  {
    printf("Wrong input");
    abort();
  }
  if (scanf("%d", &text_len) != 1)
  {
    printf("Wrong input");
    abort();
  }

  i = 0;
  while (i < text_len)
  {
    if (scanf("%c", &in) != 1)
    {
      printf("Wrong input");
      abort();
    }
    if (isalpha(in))
    {
      *buff_ptr = in;
      buff_ptr++;
      i++;
    }
    else if (in == ' ')
    {
      buff_ptr = buffer;
      if (hash_map_find(map, buff_ptr))
      {
        hash_map_update(map, buff_ptr, hash_map_get(map, buff_ptr) + 1);
      }
      else
      {
        hash_map_insert(map, buff_ptr, 1);
      }
      memset(buffer, 0, sizeof(char) * BUFF_SIZE);
      i++;
    }
  }
  // flush buffer
  if (buffer != buff_ptr)
  {
    buff_ptr = buffer;
    if (hash_map_find(map, buff_ptr))
    {
      hash_map_update(map, buff_ptr, hash_map_get(map, buff_ptr) + 1);
    }
    else
    {
      hash_map_insert(map, buff_ptr, 1);
    }
    memset(buffer, 0, sizeof(char) * BUFF_SIZE);
  }

  if (scanf("%d", &text_len) != 1)
  {
    printf("Wrong input");
    abort();
  }
  i = 0;
  while (i < text_len)
  {
    if (scanf("%c", &in) != 1)
    {
      printf("Wrong input");
      abort();
    }
    if (isalpha(in))
    {
      *buff_ptr = in;
      buff_ptr++;
      i++;
    }
    else if (in == ' ')
    {
      buff_ptr = buffer;
      if (hash_map_find(map, buff_ptr))
      {
        printf("%d ", hash_map_get(map, buff_ptr));
      }
      else
      {
        printf("%d ", 0);
      }
      memset(buffer, 0, sizeof(char) * BUFF_SIZE);
      i++;
    }
  }

  if (buffer != buff_ptr)
  {
    buff_ptr = buffer;
    if (hash_map_find(map, buff_ptr))
    {
      printf("%d ", hash_map_get(map, buff_ptr));
    }
    else
    {
      printf("%d ", 0);
    }
  }

  hash_map_free(map);
  return 0;
}
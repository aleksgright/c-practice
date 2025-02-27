// This file contains most of the fuctions, which do not need main to pass tests

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "include/node_t.h"

struct node_t * createNode(int data) {
  struct node_t * ret;
  ret = (struct node_t*) malloc(sizeof(struct node_t));
  ret->data = data;
  ret->next = NULL;
  return ret;
}

void delete_list(struct node_t *top) {
  struct node_t* tmp;
  while(top) {
    tmp = top;
    top = top->next;
    free(tmp);
  }
}

int list_is_a_loop(struct node_t *top) {
  int p, i, end;
  struct node_t* fast = top;
  struct node_t* slow = top;
  p = 1;
  end = 0;
  if (top == NULL) {
    return 0;
  }
  while(!end) {
    for(i = 0; i < p;i++) {
      fast = fast->next;
      if (fast == NULL || fast == slow) {
        end = 1;
        break;
      }
    }
    p *= 2;
  }
  return fast == NULL ? 0 : 1;
}

struct node_t *read_list_al(FILE *inp)
{
  int in, res;
  struct node_t *odd = NULL;
  struct node_t *cur_odd = odd;
  struct node_t *even = NULL;
  struct node_t *cur_even = even;
  while (1) {
    res = fscanf(inp, "%d", &in);
    if (res == EOF) {
      break;
    }
    if (res != 1) {
      printf("Wrong input");
      abort();
    }
    if (in % 2) {
      if(odd == NULL) {
        odd = createNode(in);
        cur_odd = odd;
        continue;
      }
      cur_odd->next = createNode(in);
      cur_odd = cur_odd->next;
    }
    else {
      if(even == NULL) {
        even = createNode(in);
        cur_even = even;
        continue;
      }
      cur_even->next = createNode(in);
      cur_even = cur_even->next;
    }
  }

  if (even == NULL) {
    return odd;
  }
  cur_even->next = odd;
  return even;
}

struct node_t *read_list(FILE *inp)
{
  int in, res;
  struct node_t *top = NULL;
  struct node_t *cur_node = top;
  while (1) {
    res = fscanf(inp, "%d", &in);
    if (res == EOF) {
      break;
    }
    if (res != 1) {
      printf("Wrong input");
      abort();
    }
      if(top == NULL) {
        top = createNode(in);
        cur_node = top;
        continue;
      }
      cur_node->next = createNode(in);
      cur_node = cur_node->next;
  }
  return top;
}

void print_linked_list(const struct node_t * list) {
  while(list) {
    printf("%d ", list->data);
    list = list->next;
  }
}

int main()
{
  FILE *f;
  struct node_t* list;
  f = fopen("./out/test", "r");
  if (!f)
  {
    perror("Error opening file");
    abort();
  }
  list = read_list(f);
  printf("%d", list_is_a_loop(list));
  delete_list(list);
  return 0;
}
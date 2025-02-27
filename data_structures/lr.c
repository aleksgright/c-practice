#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
  struct node_t *next;
  int data;
};

struct node_t *reverse(struct node_t *top) {
  struct node_t* prev = NULL;
  struct node_t* n = NULL;
  if (top == NULL) {
    return NULL;
  }
  while (top->next) {
    n = top->next;
    top->next = prev;
    prev = top;
    top = n;
  }
  top->next = prev;
  return top;
}

int main() {
  int i, ncorr, nnodes, res;
  struct node_t *top = NULL, *cur = NULL;

  res = scanf("%d", &nnodes);
  assert(res == 1);
  assert(nnodes >= 0);

  if (nnodes > 0) {
    top = calloc(1, sizeof(struct node_t));
    top->data = 0;
    cur = top;
  }

  for (i = 1; i < nnodes; ++i) {
    cur->next = calloc(1, sizeof(struct node_t));
    cur->next->data = cur->data + 1;
    cur = cur->next;
  }

  ncorr = nnodes;
  top = reverse(top);
  while (top && top->next) {
    if (top->data <= top->next->data) {
      ncorr -= 1;
      printf("Wrong: %d\n", top->data);
    }
    top = top->next;
  }
  printf("%d\n", ncorr);
}
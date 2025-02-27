#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_t {
  struct node_t *next;
  int data;
};

int list_is_a_loop(struct node_t *top);
int loop_len(struct node_t *top);

int main() {
  int i, nnodes, looppos, res, outcome;
  struct node_t *top = NULL, *cur = NULL, *loopelem = NULL;

  res = scanf("%d%d", &nnodes, &looppos);
  assert(res == 2);
  assert(nnodes >= 0);
  assert(looppos > -2);
  assert(looppos < nnodes);

  if (nnodes > 0) {
    top = (struct node_t*) calloc(1, sizeof(struct node_t));
    cur = top;
    if (looppos == 0)
      loopelem = cur;
  }

  for (i = 1; i < nnodes; ++i) {
    cur->next = (struct node_t*) calloc(1, sizeof(struct node_t));
    if (looppos == i)
      loopelem = cur;
    cur = cur->next;
  }

  if (looppos != -1)
    cur->next = loopelem;

  outcome = loop_len(top);
  printf("%d\n", outcome);
}

int loop_len(struct node_t *top) {
  int p, i, end;
  struct node_t* fast = top;
  struct node_t* slow = top;
  p = 1;  
  end = 0;
  if (top == 0) {
    return 0;
  }
  while(!end) {
    for(i = 1; i <= p;i++) {
      fast = fast->next;
      if (fast == 0 || fast == slow) {
        if (fast == 0) i = 0;
        end = 1;
        break;
      }
    }
    slow = fast;
    p *= 2;
  }
  return i;
}

int list_is_a_loop(struct node_t *top) {
  int res = loop_len(top);
  return res == 0 ? 0 : 1;
}
#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct tree_t
{
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

struct tree_file_t
{
  int n;
  int *topology; // 2 * n
  int *values;   // n
};

struct stack
{
  struct stack *next;
  struct tree_t *data;
};

void push(struct stack **stack, struct tree_t *data)
{
  assert(stack != NULL);
  struct stack *new_top = (struct stack*) malloc(sizeof(struct stack));
  new_top->data = data;
  new_top->next = *stack;
  *stack = new_top;
}

struct tree_t *pop(struct stack **stack)
{
  assert(stack != 0);
  assert((*stack) != 0);
  struct tree_t *ret = (*stack)->data;
  struct stack *tmp = (*stack)->next;
  free(*stack);
  *stack = tmp;
  return ret;
}

int empty(const struct stack *stack)
{
  return stack == NULL ? 1 : 0;
}

int check_is_bst(struct tree_t *top)
{
  int is_bst = 1;
  int prev = INT_MIN;
  struct stack *stk = NULL;
  if (top == NULL)
    return 1;
  while (top || !empty(stk))
  {
    while (top)
    { 
      push(&stk, top);
      top = top->left;
    }
    if (!empty(stk)){
      top = pop(&stk);
      if (prev>top->data) is_bst = 0;
      prev = top->data;
    }
    top = top->right;
  }
  return is_bst;
}

void print_pre(struct tree_t *top)
{
  struct stack *stk = NULL;
  if (top == NULL)
    return;
  push(&stk, top);
  while (!empty(stk))
  {
    struct tree_t *node = pop(&stk);
    printf("%d ", node->data);
    if (node->right)
      push(&stk, node->right);
    if (node->left)
      push(&stk, node->left);
  }
}

void print_pre_recursive(struct tree_t *top)
{
  if (top == NULL)
    return;
  printf("%d ", top->data);
  print_pre(top->left);
  print_pre(top->right);
}

struct tree_file_t readfile(FILE *f)
{
  struct tree_file_t ret;
  int res, i;

  res = fscanf(f, "%d", &ret.n);
  if (!f) {
    perror("error opening file");
  }
  assert(res == 1);

  ret.topology = (int*) calloc(2 * ret.n, sizeof(int));
  ret.values = (int*) calloc(ret.n, sizeof(int));

  for (i = 0; i < 2 * ret.n; ++i)
  {
    res = fscanf(f, "%d", ret.topology + i);
    assert(res == 1);
  }

  for (i = 0; i < ret.n; ++i)
  {
    res = fscanf(f, "%d", ret.values + i);
    assert(res == 1);
  }

  return ret;
}

void free_temp(struct tree_file_t data)
{
  free(data.topology);
  free(data.values);
}

void free_tree(struct tree_t *top)
{
  if (top == NULL)
    return;
  free_tree(top->left);
  free_tree(top->right);
  free(top);
}

struct tree_t *create_node(int data, struct tree_t *l, struct tree_t *r)
{
  struct tree_t *ret =(struct tree_t*) malloc(sizeof(struct tree_t));
  assert(ret);

  ret->left = l;
  ret->right = r;
  ret->data = data;
  return ret;
}

struct tree_t *do_recover(struct tree_file_t data, int *cursor, int *curval)
{
  struct tree_t *n = NULL;
  int cur = *cursor;
  int curv = *curval;
  *cursor += 1;
  if (cur < (data.n * 2) && data.topology[cur] == 1)
  {
    struct tree_t *l, *r;
    *curval += 1;
    l = do_recover(data, cursor, curval);
    r = do_recover(data, cursor, curval);
    assert(curv < data.n);
    n = create_node(data.values[curv], l, r);
  }
  return n;
}

struct tree_t *recover(struct tree_file_t data)
{
  int cursor = 0;
  int curval = 0;
  return do_recover(data, &cursor, &curval);
}

void print_pre(struct tree_t *top);

int main()
{
  int is_search;
  struct tree_t *top;
  struct tree_file_t filetree;

  // read tree from file
  filetree = readfile(stdin);

  // recover tree
  top = recover(filetree);

  // check if search
  is_search = check_is_bst(top);

  printf("%d\n", is_search);

  // free everything
  free_tree(top);
  free_temp(filetree);
}
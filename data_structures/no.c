#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <limits.h>

struct tree_t
{
  struct tree_t *left;
  struct tree_t *right;
  int data;
};

struct stack
{
  struct stack *next;
  struct tree_t *data;
};

struct tree_t* create_tree_node(int data) {
  struct tree_t* ret = malloc(sizeof(struct tree_t));
  ret->left = NULL;
  ret->right = NULL;
  ret->data = data;
  return ret;
}

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

struct tree_t* read_no_tree() {
  int i, n, in, res;
  struct tree_t* top = NULL;
  res = fscanf(stdin, "%d", &n);
  if (res != 1) { 
    printf("Error reading file");
    abort();
  }
  for(i = 0 ; i < n; i++) {
    struct tree_t* place = top;
    res = fscanf(stdin, "%d", &in);
    if (res != 1) { 
      printf("Error reading file");
      abort();
    }
    if (top == NULL) {
      top = create_tree_node(in); continue;
    }
    while(1) {
      if (in < place->data) {
        if (place->left == NULL) {
          place->left = create_tree_node(in);
          break;
        }
        place = place->left;
      }
      else {
        if (place->right == NULL) {
          place->right = create_tree_node(in);
          break;
        }
        place = place->right;
      }
    }
  }
  return top;
}

void free_tree(struct tree_t *top)
{
  if (top == NULL)
    return;
  free_tree(top->left);
  free_tree(top->right);
  free(top);
}


int main()
{
  //FILE *f;
  struct tree_t* tree;
  #if 0
  f = fopen(stdin, "r");
  if (!f)
  {
    perror("Error opening file");
    abort();
  }
  #endif
  tree = read_no_tree();
  print_pre(tree);

  free_tree(tree);
  return 0;
}
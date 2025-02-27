//mp + mpk
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct pol
{
  int len;
  int *vals;
};

int *read_int_array(int len)
{
  int i;
  int *arr;
  arr = (int *)malloc(len * sizeof(int));
  if (arr == NULL)
  {
    abort();
  }
  for (i = 0; i < len; i++)
  {
    if (scanf("%d", arr + i) != 1)
    {
      printf("Wrong input");
      abort();
    }
  }
  return arr;
}

void print_int_array(int *arr, int len)
{
  int i = 0;
  for (i = 0; i < len; i++)
  {
    printf("%d ", *(arr + i));
  }
}

void mul(struct pol *res, struct pol a, struct pol b)
{
  int i, j;
  res->len = a.len + b.len;
  res->vals = (int *)malloc(res->len * sizeof(int));
  for (i = 0; i < a.len + b.len; i++)
  {
    res->vals[i] = 0;
  }
  for (i = 0; i < a.len; i++)
  {
    for (j = 0; j < b.len; j++)
    {
      res->vals[i + j] += a.vals[i] * b.vals[j];
    }
  }
  while (res->vals[res->len - 1] == 0)
  {
    res->len--;
  }
}

int main()
{
  int n, k;
  struct pol a, b;
  struct pol ans = {0};
  if (scanf("%d%d", &n, &k) != 2)
  {
    printf("Wrong input");
    abort();
  }
  a.len = n;
  b.len = k;
  a.vals = read_int_array(n);
  b.vals = read_int_array(k);

  assert(a.vals != NULL && b.vals != NULL);
  mul(&ans, a, b);
  print_int_array(ans.vals, ans.len);
  free(a.vals);
  free(b.vals);
  free(ans.vals);

  return 0;
}
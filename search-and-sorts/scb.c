// This file contains most of the fuctions, which do not need main to pass tests

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

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

int cmp_int(void const *x, void const *y)
{
  int const *ptr_x = (const int*) x;
  int const *ptr_y = (const int*) y;
  if (*ptr_x < *ptr_y)
  {
    return -1;
  }
  if (*ptr_x > *ptr_y)
  {
    return 1;
  }
  return 0;
}

typedef int (*cmp_t)(const void *lhs, const void *rhs);

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp)
{
  int l, r, m, res;
  const char *ch_base = (const char *) base;
  l = 0;
  r = num - 1;
  while (l <= r)
  {
    m = l + (r - l) / 2;
    res = cmp(key, base + m * size);
    if (res < 0)
    {
      r = m - 1;
    }
    if (res == 0)
    {
      return (void *)(base + m * size);
    }
    if (res >0)
    {
      l = m + 1;
    }
  }
  return NULL;
}

int main()
{
  int n, k;
  int *res;
  int *arr;
  if (scanf("%d", &n) != 1)
  {
    printf("Wrong input");
    abort();
  }
  if (n == 0)
  {
    printf("0");
    return 0;
  }
  arr = read_int_array(n);
  assert(&arr != NULL);
  if (scanf("%d", &k) != 1)
  {
    printf("Wrong input");
    abort();
  }
  res = (int*)cbsearch(&k, arr, n, sizeof(int), cmp_int);
  if (res == NULL) {
    printf("-1");
    return 0;
  }
  printf("%d", *res);

  free(arr);
  return 0;
}
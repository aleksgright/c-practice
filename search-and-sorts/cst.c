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

void print_int_array(int *arr, int len)
{
  int i = 0;
  for (i = 0; i < len; i++)
  {
    printf("%d ", *(arr + i));
  }
}

int *min(int *arr, int len)
{
  int i;
  int *ans;
  assert(len != 0);
  ans = arr;
  for (i = 1; i < len; i++)
  {
    if (*(arr + i) < *ans)
    {
      ans = arr + i;
    }
  }
  return ans;
}

int *max(int *arr, int len)
{
  int i;
  int *ans;
  assert(len != 0);
  ans = arr;
  for (i = 1; i < len; i++)
  {
    if (*(arr + i) > *ans)
    {
      ans = arr + i;
    }
  }
  return ans;
}

void print_bucket_array(int *arr, int len) {
  int i;
  int* ret;
  int *m;
  m = max(arr, len);
  ret = malloc((*m+1) * sizeof(int));
  for ( i = 0; i < *m+1; i++) {
    ret[i] = 0;
  }
  for ( i = 0; i < len; i++) {
    ret[arr[i]]++;
  }
  print_int_array(ret, *m+1);
}


int main()
{
  int n;
  int *arr;
  if (scanf("%d", &n) != 1)
  {
    printf("Wrong input");
    abort();
  }
  arr = read_int_array(n);
  assert(arr != NULL);
  print_bucket_array(arr, n);

  free(arr);
  return 0;
}
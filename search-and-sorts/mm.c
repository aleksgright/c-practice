#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int* read_int_array(int len)
{
  int i;
  int * arr;
  arr = (int *)malloc(len * sizeof(int));
  if (arr == NULL) {
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

int* min(int * arr, int len) {
  int i;
  int *ans;
  assert(len!=0);
  ans = arr;
  for (i = 1; i<len;i ++) {
    if (*(arr+i)<*ans) {
      ans = arr+i;
    }
  }
  return ans;
}

int* max(int * arr, int len) {
  int i;
  int *ans;
  assert(len!=0);
  ans = arr;
  for (i = 1; i<len;i ++) {
    if (*(arr+i)>*ans) {
      ans = arr+i;
    }
  }
  return ans;
}

int moveright(int *arr, int key, int last) {
  while (last > 0 &&arr[last-1] > key) {
    arr[last] = arr[last-1];
    last--;
  }
  return last;
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
  if (n == 0)
  {
    printf("0");
    return 0;
  }
  arr = read_int_array(n);
  assert(&arr!=NULL);
  printf("%d %d", *min(arr, n), *max(arr,n));
  free(arr);

  return 0;
}
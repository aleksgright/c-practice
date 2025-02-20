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

int myrand()
{
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

void fy(int *arr, unsigned int len)
{
  int i, j, tmp;
  if (len == 1)
  {
    return;
  }
  for (j = len - 1; j > 0; j--)
  {
    i = myrand() % (j + 1);
    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
  }
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
  fy(arr, n);
  print_int_array(arr, n);
  free(arr);

  return 0;
}
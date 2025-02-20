//This file contains most of the fuctions, which do not need main to pass tests 

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void swap(int* x, int* y) {
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

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

void sse(int*arr, int len, int k) {
  #if 0
  int i;
  for(i = 0; i <len; i++) {}
  #endif
  int *m;
  m = min(arr+k, len-k);
  swap(arr+k, m);
}

typedef int (*cmp_t)(void const * lhs, void const * rhs);

void swap_t(void* x, void* y, int eltsize) {
  char tmp;
  int i;
  char * ch_x = (char*)x;
  char* ch_y = (char*)y;
  for(i = 0; i < eltsize; i++) {
  tmp = *(ch_x+i);
  *(ch_x+i) = *(ch_y+i);
  *(ch_y+i) = tmp;
  }
}

void* min_t(void * arr, int len, int eltsize, cmp_t cmp) {
  int i;
  char *ans;
  char* ch_arr =(char*) arr;
  assert(len!=0);
  ans = (char*)arr;
  for (i = 1; i<len;i ++) {
    if (cmp(ch_arr + i*eltsize, ans)) {
      ans = ch_arr + i*eltsize;
    }
  }
  return ans;
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
  char * ptr = (char *)parr;
  void *m;

  m = min_t(ptr+nsorted*eltsize, numelts-nsorted, eltsize, cmp);
  swap_t(ptr+nsorted*eltsize, m, eltsize);
  return 0;
}

unsigned partition(int *arr, unsigned low, unsigned high) {
  int l, r;
  l = low+1;
  r = high;
  while (l<r) {
    while((l <= high) && (arr[l]<=arr[low])) {
      l++;
    }
    while((r>low)&&(arr[r]>arr[low])) {
      r--;
    }
    if(l<r) {
      swap(arr+l, arr+r);
    }
  }
  l--;
  swap(arr+low, arr+l);
  return l;
}

void merge(int *arr, int l, int m, int r) {
  int i,j;
  int n1 = m-l+1, n2=r-m;
  int arr_l[n1];
  int arr_r[n2];

  for(i = 0; i<n1; i++) {
    arr_l[i] = arr[l+i];
  }
  for(i = 0; i<n2; i++) {
    arr_r[i] = arr[m+1+i];
  }
  i = n1-1;
  j = n2-1;
  while((i>=0) || (j>=0)) {
    if ((i>=0) && (j>=0)) {
      if (arr_l[i] >= arr_r[j]) {
        arr[r] = arr_l[i];
        i--;
      }
      else {
        arr[r] = arr_r[j];
        j--;
      }
    }else if (i>=0) {
      arr[r] = arr_l[i];
      i--;
    }else if (j>=0) {
      arr[r] = arr_r[j];
      j--;
    }
    r--;
  }
}

int main()
{
  int n;
  //int k;
  //int res;
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
  assert(arr!=NULL);
  // if (scanf("%d", &k) != 1)
  // {
  //   printf("Wrong input");
  //   abort();
  // }
  merge(arr, 0, 3, n-1);
  print_int_array(arr, n);
  free(arr);

  return 0;
}
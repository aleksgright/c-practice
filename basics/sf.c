#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void compute(unsigned int x)
{
  int prev = 0, curr = 1, tmp;
  int i = 0;
  unsigned int storage[128];
  storage[0] = 1;

  if (x == 0) {
    printf("0");
  }

  while (curr <= x) {
    storage[i++] = curr;
    tmp = curr;
    curr = curr+prev;
    prev = tmp;
  }
  i--;
  while (x > 0 || i>0) {
    if (x>=storage[i]) {
      printf("1");
      x -= storage[i];
    }
    else{
      printf("0");
    }
    i--;
  } 
}

int main()
{
  unsigned int x, sys, ans, res;

  res = scanf("%u", &x);
  if (res != 1)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  compute(x);
  return 0;
}

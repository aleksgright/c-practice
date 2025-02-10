#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void compute(unsigned int x)
{
  int length = 0;
  int f_count = 2;
  unsigned int storage[32];
  while ( x > 0) {
    storage[length++] = x%f_count;
    x /= f_count;
    f_count++;
  }
  while (length > 0) {
    printf("%u.", storage[--length]);
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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void compute(unsigned int x, unsigned int sys)
{
  int length = 0;
  unsigned int storage[32];
  while ( x > 0) {
    storage[length++] = x%sys;
    x /= sys;
  }
  length--;
  while (length > -1) {
    printf("%u", storage[length--]);
  } 
}

int main()
{
  unsigned int x, sys, ans, res;

  res = scanf("%u%u", &x, &sys);
  if (res != 2 || sys == 0)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  compute(x, sys);
  return 0;
}

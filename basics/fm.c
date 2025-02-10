#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long fib_mod(long long m)
{
  long long first = 1, second = 1, tmp;
  long long i = 3;
  while (!(first == 0 && second == 1))
  {
    tmp = second;
    second = (second+first) % m;
    first = tmp;
    i++;
  }
  return i-2;
}

long long fm(long long x, long long m)
{
  long long p, prev = 0, curr = 1, tmp;
  int i;
  p = fib_mod(m);

  if ( x ==0 || (x%p ==0)) {
    return 0;
  }

  for (i = 1; i < (x%p); i++) {
    tmp = curr;
    curr = (prev+curr) % m;
    prev = tmp;
  }
  return curr;
}

int main()
{
  long long x = 0, y = 0, g;
  long long res;

  res = scanf("%ld%ld", &x, &y);
  if (res != 2 || y == 0)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  g = fm(x, y);
  printf("%d\n", g);
  return 0;
}

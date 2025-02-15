#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int x) { return (x < 0) ? -x : x; }

int eu_mod(int x, int y)
{
  int r;
  assert(y != 0);
  r = x % y;
  if (r < 0)
    r += iabs(y);
  return r;
}

int gcd(int x, int y)
{
  int q;

  while (y != 0)
  {
    q = eu_mod(x, y);
    x = y;
    y = q;
  }
  return x;
}

long long lcm(int n) {
  long long ans = 2;
  int i = 2;
  while (i <n) {
    i++;
    ans = (ans * i) / gcd(ans, i);
  }
  return ans;
}

int main()
{
  int x;
  long long res;

  res = scanf("%d", &x);
  if (res != 1 || x<2)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  res = lcm(x);
  printf("%lld\n", res);
  return 0;
}
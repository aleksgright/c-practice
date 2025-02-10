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

void cf(int x, int y)
{
  int q;

  while (y != 0)
  {
    printf("%d ", x/y);
    q= eu_mod(x, y);
    x = y;
    y = q;
  }
}

int main()
{
  int x = 0, y = 0, g;
  int res;

  res = scanf("%d%d", &x, &y);
  if (res != 2 || y == 0)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  cf(x, y);
  //printf("%d\n", g);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct ans
{
  int most;
  int least;
};

struct ans foo(int n)
{
  int val, count;
  struct ans ret = {-1, -1};
  count = 0;
  while (n != 0)
  {
    val = n & 1;
    if (val)
    {
      if (ret.least == -1)
      {
        ret.least = count;
      }
      ret.most = count;
    }
    n = n >> 1;
    count++;
  }
  return ret;
}

int main()
{
  int n;
  struct ans res;
  if (scanf("%d", &n) != 1)
  {
    printf("Wrong input");
    abort();
  }
  res = foo(n);
  if (res.least == -1)
  {
    printf("NO");
  }
  else
  {
    printf("%d %d", res.most, res.least);
  }
  return 0;
}
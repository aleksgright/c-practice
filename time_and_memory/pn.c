#include <stdio.h>
#include <stdlib.h>

int pn(int n);

int main()
{
  int n, res;
  if (scanf("%d", &n) != 1)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  res = pn(n);
  printf("%d", res);
  return 0;
}

int pn(int n)
{
  int j = 3, i, cur = 2;
  if (n == 1)
    return 2;
  if (n == 2)
    return 3;
  while (cur != n)
  {
    j++;
    for (i = 2; i * i <= j; i++)
    {
      if (j % i == 0)
      {
        break;
      }
    }
    if (i * i > j)
    {
      cur++;
    }
  }
  return j;
}
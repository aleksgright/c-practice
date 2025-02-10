#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

long long iabs(long long x) { return (x < 0) ? -x : x; }

long long eu_mod(long long x, long long y)
{
  long long r;
  assert(y != 0);
  r = x % y;
  if (r < 0)
    r += iabs(y);
  return r;
}

long long eu_div(long long x, long long y)
{
  long long r;
  assert(y != 0);
  if (x < 0)
  {
    if (y > 0)
    {
      return x / y - 1;
    }
    else
    {
      return x / y + 1;
    }
  }
  return x / y;
}

long long gcd(long long x, long long y, long long *a_ptr, long long *b_ptr)
{
  long long ta, tb, q, a_, b_;

  a_ = *b_ptr = 1;
  *a_ptr = b_ = 0;

  for (;;)
  {
    q = eu_mod(x, y);
    if (q == 0)
    {
      return y;
    }
    ta = a_;
    a_ = *a_ptr;
    *a_ptr = ta - eu_div(x, y) * (*a_ptr);

    tb = b_;
    b_ = *b_ptr;
    *b_ptr = tb - eu_div(x, y) * (*b_ptr);

    x = y;
    y = q;
  }
}

int main()
{
  long long x = 0, y = 0, g;
  long long res;
  long long a, b;

  res = scanf("%ld%ld", &x, &y);
  if (res != 2 || y == 0)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  g = gcd(x, y, &a, &b);
  printf("%ld %ld %ld\n", a, b, g);
  return 0;
}

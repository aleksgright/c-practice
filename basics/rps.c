#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int pow_mod(long long a, long long pow, long long n) {
  int tmp = 1;

  while (pow!=0) {
    if (pow%2) {
      tmp = (tmp * a) % n; 
    }
    a = (a * a) % n;
    pow /= 2;
  }
  return tmp;
}

long long rps(long long a, long long b, long long n)
{
  int tmp = 1;

  while (b) {
    if (b%2) {
      tmp = pow_mod(a, tmp, n);
    }
    a = pow_mod(a, a, n);
    b /= 2;
  }
  return tmp;
  
}

int main()
{
  long long a, b, n, ans, res;

  res = scanf("%ld%ld%ld", &a, &b, &n);
  if (res != 3)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  res = rps(a, b, n);
  printf("%ld", res);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

unsigned long long pow_mod(unsigned long long n, unsigned long long k, unsigned long long m) {
  unsigned long long acc, prod;
  assert(m > 1);
  if (k == 0)
    return 1;
  acc = n % m;
  prod = 1;
  for (; k > 0;) {
    if ((k % 2) == 1)
      prod = (prod * acc) % m;
    acc = (acc * acc) % m;
    k = k / 2;
  }
  return prod;
}

int main() 
{
  unsigned long long num, x;
  srand(time(NULL));
  scanf("%llu", &num);
  for(int i =0; i < 100; i++) {
    x = rand()%15670;
    if (pow_mod(x, num-1, num) != 1) {
      printf("0");
      return 0;
    }
  }
  printf("1");
  return 0;
}
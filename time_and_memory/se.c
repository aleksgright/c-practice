#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sieve
{
  int size;
  char *sieve;
};

int se(int n);
struct sieve init_sieve(int size);

int main()
{
  int n, res;
  if (scanf("%d", &n) != 1)
  {
    printf("%s\n", "Wrong input");
    abort();
  }
  res = se(n);
  printf("%d", res);
  return 0;
}

struct sieve init_sieve(int size)
{
  struct sieve ret;
  ret.sieve = malloc((size + 1) * sizeof(char));
  ret.size = size + 1;
  return ret;
}

int se(int n)
{
  int i = 2, j, count;
  struct sieve sieve_n = init_sieve(n);
  assert(sieve_n.sieve != NULL && sieve_n.size > 0);
  memset(sieve_n.sieve, 1, sieve_n.size);
  sieve_n.sieve[0] = 0;
  sieve_n.sieve[1] = 0;
  while (i * i <= sieve_n.size)
  {
    if (sieve_n.sieve[i])
    {
      j = i * i;
      while (j < sieve_n.size)
      {
        sieve_n.sieve[j] = 0;
        j += i;
      }
    }
    i++;
  }

  count = 0;
  for (i = 2; i < sieve_n.size; i++)
  {
    if (sieve_n.sieve[i])
      count++;
  }
  return count;
}
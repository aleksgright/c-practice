#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sieve_t
{
  int n;
  char *s;
};

void fill_sieve(struct sieve_t *sv);
int nth_prime(struct sieve_t *sv, int N);

int main()
{
  int n;
  scanf("%d", &n);
  struct sieve_t tmp;
  tmp.s = (char*) malloc(n*n*sizeof(char));
  tmp.n = n*n;
  fill_sieve(&tmp);
  int res = nth_prime(&tmp,n );
  printf("%d", res);
  free(tmp.s);
  return 0;
}

int nth_prime(struct sieve_t *sv, int N) {
  int i = 1, count;
  count = 0;
  while (count < N)
  {
    i++;
    if (!sv->s[i])
      count++;
  }
  return i;
}

void fill_sieve(struct sieve_t *sv)
{
  int i = 2, j;
  sv->s[0] = 1;
  sv->s[1] = 1;
  while (i * i <= sv->n)
  {
    if (!sv->s[i])
    {
      j = i * i;
      while (j < sv->n)
      {
        sv->s[j] = 1;
        j += i;
      }
    }
    i++;
  }
}
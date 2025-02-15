#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <math.h>

struct sieve_t
{
  int n;
  char *s;
};

int sieve_bound(int num)
{
    double dnum, dres;
    if (num <= 20 * CHAR_BIT)
        return 100 * CHAR_BIT;
    dnum = num;
    dres = dnum * (log(dnum) + log(log(dnum)));
    return (int) round(dres) + 1;
}


int nth_prime(struct sieve_t *sv, unsigned int n);
void fill_sieve(struct sieve_t *sv);
int is_prime(struct sieve_t *sv, unsigned int n);


//contest is broken
int main()
{
    int n, outp;
    int res;
    struct sieve_t *s;

    res = scanf("%d", &n);
    assert(res == 1);

    s = (struct sieve_t *) malloc(sizeof(struct sieve_t));
    assert(s);

    s->n = (sieve_bound(n) / CHAR_BIT) + CHAR_BIT;
    s->s = (char *) calloc(s->n, sizeof(char));
    assert(s->s);

    fill_sieve(s);
    #if 0
    for (int i = 2; i < n; ++i)
      printf("%d %d\n", i, is_prime(s, i));
      #endif

    outp = nth_prime(s, n);
    printf("%d\n", outp);

    free(s->s);
    free(s);
}

int is_prime(struct sieve_t *sv, unsigned int n)
{
    return (sv->s[n / 8] >> n % 8) & 1;
}

int nth_prime(struct sieve_t *sv, unsigned int n)
{
  int i, count;
  count = 0;
  i = 1;
  while (count < n) {
    i++;
    if (!((sv->s[i / 8] >> (i % 8)) & 1)) count++;
  }
  return i;
}

void fill_sieve(struct sieve_t *sv)
{
  int i, j;
  sv->s[0] = sv->s[0] | (1u << 0);
  sv->s[1] = sv->s[1] | (1u << 1);
  for (i = 2; i * i <= sv->n * 8; i++)
  {
    if (!((sv->s[i / 8] >> (i % 8)) & 1))
    {
      j = i * i;
      while (j < sv->n)
      {
        sv->s[j / 8] = sv->s[j / 8] | (1u << (j % 8));
        j += i;
      }
    }
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct int_cont
{
  int size;
  unsigned char *bytes;
};

void foo(struct int_cont* data, int pos)
{
  if (pos/8 > data->size) {
    return;
  }
  
  data->bytes[pos/8] = data->bytes[pos/8] ^ (1u<<(pos%8));  
}

struct int_cont scan_init_array()
{
  int n, i, tmp;
  struct int_cont ret;
  if (scanf("%d", &n) != 1)
  {
    printf("Wrong input");
    abort();
  }
  ret.size = n;
  ret.bytes = malloc(n * sizeof(char));
  for (i = 0; i < n; i++)
  {
    if (scanf("%u", &tmp) != 1)
    {
      printf("Wrong input");
      abort();
    }
    ret.bytes[i] = tmp;
  }
  return ret;
}

int main()
{
  int pos, i;
  struct int_cont in;
  in = scan_init_array();
  if (scanf("%d", &pos) != 1)
  {
    printf("Wrong input");
    abort();
  }
  foo(&in, pos);
  for(i=0; i < in.size; i++) {
    printf("%u ", in.bytes[i]);
  }
  return 0;
}
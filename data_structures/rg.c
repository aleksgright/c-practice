#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a, b, c, d;

int mygen(int num) {
  return (a * num + b) % c + d;
}

typedef int (*generator_t)(int);

unsigned cycle_len(generator_t gen) {
  int p, i, end;
  int slow, fast;
  p = 1;  
  end = 0;
  slow = gen(0);
  fast = gen(0);
  while(!end) {
    for(i = 1; i <= p;i++) {
      fast = gen(fast);
      if (fast == slow) {
        end = 1;
        break;
      }
    }
    slow = fast;
    p *= 2;
  }
  return i;
}

int main() {
  int res = scanf("%d%d%d%d", &a, &b, &c, &d);
  assert(res);
  printf("%u\n", cycle_len(mygen));
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hash_map.h"
#include "hash_map_tests.h"


int main(int argc, char** argv) {
  if (argc > 1) {
    if (strcmp(argv[1], "--tests")==0) {
      run_tests();
    }
  }

  
  return 0;
}
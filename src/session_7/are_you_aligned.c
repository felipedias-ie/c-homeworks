// SPDX-License-Identifier: MIT

#include <stdio.h>

typedef struct {
  char c;
  int i;
} StructA;

typedef struct {
  int i;
  char c;
} StructB;

int main(void) {
  printf("StructA size: %zu\n", sizeof(StructA));
  printf("StructB size: %zu\n", sizeof(StructB));

  // alignment requirements introduce padding so that members are aligned to their natural boundaries.
  // StructA has a char before an int, so it requires padding between them. StructB starts with the int, so less padding is needed.
  
  return 0;
}


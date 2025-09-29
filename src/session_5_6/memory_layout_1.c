#include "session_5_6/session5.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void memory_layout_1_demo(void) {
  printf("Memory Layout 1 Demo\n");
  int a = 1;
  int b = 2;

  printf("  Address of a: %p\n", (void *)&a);
  printf("  Address of b: %p\n", (void *)&b);
  printf("  Distance between a and b: %ld bytes\n", (long)((char *)&b - (char *)&a));

  // explain
  // printf("  Explanations:\n");
  // printf("    * ints are typically 4 bytes, so consecutive ints differ by 4 bytes\n");
  // printf("    * doubles are typically 8 bytes, chars 1 byte\n");
  // printf("    * mixing types can introduce padding due to alignment\n");
  // printf("    * the order of variables is not guaranteed across runs\n");
  // printf("\n");
}

void memory_layout_2_demo(void) {
  printf("Memory Layout 2 Demo\n");
  typedef double Type;
  Type a;
  size_t addr = (size_t)&a;
  printf("  Address: %zu\n", addr);
  printf("  sizeof(Type) = %zu\n", sizeof(Type));
  printf("  addr %% sizeof(Type) = %zu\n", addr % sizeof(Type));
  assert(addr % sizeof(Type) == 0);

  // explain
  printf("  Statement: Stack allocations respect alignment requirements.\n");
  printf("\n");
}

void memory_layout_3_demo(void) {
  printf("memory layut 3\n");
  printf("  sizeof(int) = %zu\n", sizeof(int));
  printf("  sizeof(double) = %zu\n", sizeof(double));
  printf("  sizeof(char) = %zu\n", sizeof(char));
  printf("  sizeof(long) = %zu\n", sizeof(long));

  int stack_arr[1000];
  int *heap_arr = (int *)malloc(1000 * sizeof(int));

  printf("  sizeof(stack_arr) = %zu\n", sizeof(stack_arr));
  printf("  sizeof(heap_arr) = %zu (pointer size)\n", sizeof(heap_arr));

  // explainnn
  // printf("  explanation: sizeof applies to types, not allocations.\n");

  free(heap_arr);
  printf("\n");
}


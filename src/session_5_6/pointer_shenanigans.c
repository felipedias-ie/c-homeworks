#include "session_5_6/session5.h"

#include <stdio.h>

void swap_ints(int *a, int *b)
{
  if (!a || !b)
  {
    return;
  }

  int tmp = *a;
  *a = *b;
  *b = tmp;
}

static void swap_without_temp(int *a, int *b)
{
  if (!a || !b || a == b)
  {
    return;
  }

  *a ^= *b;
  *b ^= *a;
  *a ^= *b;
}

void pointer_shenanigans_demo(void)
{
  printf("Pointer Swap Demo\n");
  int a = 1;
  int b = 2;
  printf("  Before regular swap: a=%d, b=%d\n", a, b);
  swap_ints(&a, &b);
  printf("  After regular swap: a=%d, b=%d\n", a, b);

  swap_without_temp(&a, &b);
  printf("  After XOR swap: a=%d, b=%d\n", a, b);
  printf("\n");
}


#include "session_5_6/session5.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

void casting_1_demo(void) {
  printf("Casting 1 Demo\n");
  int x = 2;
  float stored_as_float = (float)x;
  printf("  Stored as float via value cast: %f\n", stored_as_float);

  int reinterpret_value = 0x40000000; // IEEE-754 representation of 2.0f
  float reinterpreted = *(float *)&reinterpret_value;
  printf("  Reinterpreted int 0x40000000 as float: %f\n", reinterpreted);

  *(int *)&stored_as_float = reinterpret_value;
  printf("  Mutated stored float via pointer cast: %f\n", stored_as_float);
}


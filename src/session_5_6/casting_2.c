#include "session_5_6/session5.h"

#include <math.h>
#include <stdint.h>
#include <stdio.h>

void casting_2_demo(void) 
{
  printf("casting 2 demo (undefined behavior)\n");
  for (int i = 0; i < 3; ++i) 
  {
    int x = 0;
    double value = *(double *)&x;
    
    printf("  run %d: double view of zero int = %g\n", i + 1, value);
  }

  for (int i = 0; i < 3; ++i) 
  {
    int x = 0;
    float value = *(float *)&x;

    printf("  run %d: float view of zero int = %g\n", i + 1, value);
  }

  // explanation
  printf("  explanation: double requires 8 bytes, reading from 4-byte int uses stray stack data.\n");
  printf("\n");
}


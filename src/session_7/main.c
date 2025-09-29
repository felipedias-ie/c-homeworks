// SPDX-License-Identifier: MIT

#include <stdio.h>

#include "session_7/rectangle.h"

int main(void) {
  Rectangle rect = { .width = 5, .height = 3 };
  printf("Initial rectangle: %dx%d\n", rect.width, rect.height);
  int initial_area = area(rect);
  printf("Initial area: %d\n", initial_area);

  grow(&rect, 2, 4);
  printf("Grown rectangle: %dx%d\n", rect.width, rect.height);
  int grown_area = area(rect);
  printf("Grown area: %d\n", grown_area);

  return 0;
}


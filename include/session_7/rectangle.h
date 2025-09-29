// SPDX-License-Identifier: MIT

#ifndef SESSION_7_RECTANGLE_H
#define SESSION_7_RECTANGLE_H

typedef struct {
  int width;
  int height;} Rectangle;

int rectangle_is_valid(Rectangle r);

int area(Rectangle r);

void grow(Rectangle *r, int dw, int dh);

#endif


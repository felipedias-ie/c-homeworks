// SPDX-License-Identifier: MIT

#include "session_7/rectangle.h"

#include <limits.h>
#include <stddef.h>

static int clamp_to_int_bounds(long value) 
{
  if (value < 0) 
  {
    return 0;
  }

  if (value > INT_MAX) 
  {
    return INT_MAX;
  }

  return (int)value;
}

int rectangle_is_valid(Rectangle r) 
{
  return r.width > 0 && r.height > 0;
}

int area(Rectangle r) 
{
  long safe_width = r.width;
  long safe_height = r.height;

  if (!rectangle_is_valid(r)) 
  {
    return 0;
  }

  long area = safe_width * safe_height;
  if (area > INT_MAX) 
  {
    return INT_MAX;
  }

  return (int)area;
}

void grow(Rectangle *r, int dw, int dh) 
{
  if (r == NULL) 
  {
    return;
  }

  long new_width  = (long)r->width + dw;
  long new_height = (long)r->height + dh;

  r->width  = clamp_to_int_bounds(new_width);
  r->height = clamp_to_int_bounds(new_height);
}


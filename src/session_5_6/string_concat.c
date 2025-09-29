#include "session_5_6/session5.h"

#include <stdlib.h>
#include <string.h>

char *concat(const char *lhs, const char *rhs) 
{
  if (!lhs || !rhs) 
  {
    return NULL;
  }

  size_t lhs_len = strlen(lhs);
  size_t rhs_len = strlen(rhs);
  size_t total   = lhs_len + rhs_len + 1;
  char *result   = (char *)malloc(total);
  
  if (!result) 
  {
    return NULL;
  }

  memcpy(result, lhs, lhs_len);
  memcpy(result + lhs_len, rhs, rhs_len + 1);
  
  return result;
}


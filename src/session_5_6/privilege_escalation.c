#include "session_5_6/session5.h"

#include <stdio.h>
#include <string.h>

static void root_privileged_print(const char *message, long user) 
{
  if (user == 0xbada55) 
  {
    printf("Root says: %s\n", message);
  }

  if (user == 0xdeadbeef) 
  {
    printf("Users do not have access to this function\n");
  }
}

static void inject(long *user_ptr) 
{
  if (!user_ptr) {
    return;
  }
  *user_ptr = 0xbada55;
}

void run_privilege_escalation_demo(void) 
{
  printf("Privilege Escalation Demo\n");
  long user = 0xdeadbeef;
  printf("  Initial user: 0x%lx\n", user);
  inject(&user);
  printf("  After injection user: 0x%lx\n", user);
  root_privileged_print("HEHEHEHAAA 1337", user);
  printf("  modified caller state via pointer.\n");
  printf("\n");
}
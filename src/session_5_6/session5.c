#include "session_5_6/session5.h"

void run_all(void) {
  pointer_shenanigans_demo();
  memory_layout_1_demo();
  memory_layout_2_demo();
  memory_layout_3_demo();
  casting_1_demo();
  casting_2_demo();

  IntArray array;
  if (int_array_init(&array, 8)) {
    run_number_prompt(&array, stdin);
    int_array_free(&array);
  }

  run_privilege_escalation_demo();
}

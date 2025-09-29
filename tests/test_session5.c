#include "session_5_6/session5.h"

#include "../third_party/utest.h"

UTEST(Pointer, Swap) {
  int a = 1;
  int b = 2;
  swap_ints(&a, &b);
  ASSERT_EQ(2, a);
  ASSERT_EQ(1, b);
}

UTEST(Array, AppendSumAverage) {
  IntArray array;
  ASSERT_TRUE(int_array_init(&array, 1));
  ASSERT_TRUE(int_array_append(&array, 1));
  ASSERT_TRUE(int_array_append(&array, 2));
  ASSERT_TRUE(int_array_append(&array, 3));
  ASSERT_EQ(3u, array.size);
  ASSERT_EQ(6, int_array_sum(&array));
  ASSERT_NEAR(2.0, int_array_average(&array), 1e-6);
  int_array_free(&array);
}

UTEST(String, Concat) {
  char *joined = concat("hello", " world");
  ASSERT_TRUE(joined);
  ASSERT_STREQ("hello world", joined);
  free(joined);
}

UTEST_MAIN()


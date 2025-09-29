#include "session_7/rectangle.h"
#include "utest.h"

UTEST(rectangle, area_basic) {
  Rectangle rect = { .width = 5, .height = 4 };
  EXPECT_EQ(20, area(rect));
}

UTEST(rectangle, area_invalid_dimensions) {
  Rectangle zero_width = { .width = 0, .height = 10 };
  EXPECT_EQ(0, area(zero_width));

  Rectangle negative_height = { .width = 7, .height = -2 };
  EXPECT_EQ(0, area(negative_height));
}

UTEST(rectangle, grow_basic) {
  Rectangle rect = { .width = 3, .height = 2 };
  grow(&rect, 2, 5);
  EXPECT_EQ(5, rect.width);
  EXPECT_EQ(7, rect.height);
}

UTEST(rectangle, grow_with_negative_deltas) {
  Rectangle rect = { .width = 10, .height = 8 };
  grow(&rect, -3, -5);
  EXPECT_EQ(7, rect.width);
  EXPECT_EQ(3, rect.height);
}

UTEST(rectangle, grow_underflow_clamps_to_zero) {
  Rectangle rect = { .width = 2, .height = 2 };
  grow(&rect, -10, -1);
  EXPECT_EQ(0, rect.width);
  EXPECT_EQ(1, rect.height);
}

UTEST_MAIN();


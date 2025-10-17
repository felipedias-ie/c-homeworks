#include <stdio.h>
#include <stdlib.h>
#include "session10/super_assert.h"

/**
 * @brief Exercise 5.2: Super Assert
 * 
 * This program demonstrates the enhanced super_assert macro with configurable behavior.
 * 
 * Configuration options (set at compile time):
 * - NDEBUG: Disables all assertions
 * - SUPER_ASSERT_TRACE=1: Prints messages for passing assertions too
 * - SUPER_ASSERT_PERMISSIVE=1: Prints warnings instead of aborting
 * - SUPER_ASSERT_VERBOSE=1: Prints file, line, and function information
 */

static int divide(int a, int b)
{
    super_assert(b != 0, "division by zero");
    return a / b;
}

static int factorial(int n)
{
    super_assert(n >= 0, "negative factorial");
    super_assert(n <= 12, "factorial overflow");
    int result = 1;
    for (int i = 2; i <= n; ++i)
    {
        result *= i;
    }
    return result;
}

static void test_assertions(void)
{
    printf("=== testing super_assert ===\n\n");

    printf("1: div\n");
    int x = 10;
    int y = 2;
    super_assert(y != 0, "division by zero");
    int result = divide(x, y);
    printf("got: %d / %d = %d\n\n", x, y, result);

    printf("2: factorial\n");
    int n = 5;
    super_assert(n >= 0 && n <= 12, "factorial range");
    int fact = factorial(n);
    printf("got: %d! = %d\n\n", n, fact);

    printf("3: check str\n");
    const char *str = "Hello";
    super_assert(str != NULL, "string pointer null");
    super_assert(str[0] != '\0', "empty string");
    printf("str ok: \"%s\"\n\n", str);

    printf("4: range check\n");
    int value = 42;
    super_assert(value > 0, "value must be positive");
    super_assert(value < 100, "value too big");
    printf("value %d in range\n\n", value);

    printf("5: fail test\n");
    int bad_value = 150;
    super_assert(bad_value < 100, "value too big");
    printf("value %d in range\n\n", bad_value);
}

int main(void)
{
    printf("super_assert demo\n");
    printf("=================\n\n");

    printf("config:\n");
    #ifdef NDEBUG
        printf("  NDEBUG: on (asserts OFF)\n");
    #else
        printf("  NDEBUG: off (asserts on)\n");
    #endif

    #if defined(SUPER_ASSERT_TRACE) && SUPER_ASSERT_TRACE
        printf("  TRACE: on\n");
    #else
        printf("  TRACE: off\n");
    #endif

    #if defined(SUPER_ASSERT_PERMISSIVE) && SUPER_ASSERT_PERMISSIVE
        printf("  PERMISSIVE: on\n");
    #else
        printf("  PERMISSIVE: off\n");
    #endif

    #if defined(SUPER_ASSERT_VERBOSE) && SUPER_ASSERT_VERBOSE
        printf("  VERBOSE: on\n");
    #else
        printf("  VERBOSE: off\n");
    #endif

    printf("\n");

    test_assertions();

    return EXIT_SUCCESS;
}


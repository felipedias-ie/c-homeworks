### Building

default lang is english

```bash
# English (default)
cmake -DLANGUAGE=EN -B build
cmake --build build
./build/src/session10/preprocessor_101

# Spanish
cmake -DLANGUAGE=ES -B build
cmake --build build
./build/src/session10/preprocessor_101

# French
cmake -DLANGUAGE=FR -B build
cmake --build build
./build/src/session10/preprocessor_101

# German
cmake -DLANGUAGE=DE -B build
cmake --build build
./build/src/session10/preprocessor_101
```

## Exercise 5.2

An enhanced assertion macro that provides configurable behavior beyond the standard `assert()`.

### Features

1. **NDEBUG**: When defined, disables all assertions (standard behavior)
2. **SUPER_ASSERT_TRACE**: When set to 1, prints messages even for passing assertions
3. **SUPER_ASSERT_PERMISSIVE**: When set to 1, prints warnings instead of aborting on failure
4. **SUPER_ASSERT_VERBOSE**: When set to 1, prints file, line, and function information

### Building

```bash
cmake -B build
cmake --build build

# Default configuration (assertions enabled, no special features)
./build/src/session10/super_assert_demo

# TRACE enabled 
./build/src/session10/super_assert_trace

# VERBOSE enabled 
./build/src/session10/super_assert_verbose

# all features enabled
./build/src/session10/super_assert_full
```

manual confics:

```bash
# trace mode
cmake -DSUPER_ASSERT_TRACE=1 -B build
cmake --build build
./build/src/session10/super_assert_demo

# permissive mode (won't abort on failures)
cmake -DSUPER_ASSERT_PERMISSIVE=1 -B build
cmake --build build
./build/src/session10/super_assert_demo

# verbose mode
cmake -DSUPER_ASSERT_VERBOSE=1 -B build
cmake --build build
./build/src/session10/super_assert_demo

# multiple options
cmake -DSUPER_ASSERT_TRACE=1 -DSUPER_ASSERT_PERMISSIVE=1 -DSUPER_ASSERT_VERBOSE=1 -B build
cmake --build build
./build/src/session10/super_assert_demo

# releae mode (disables all assertions)
cmake -DNDEBUG=1 -B build
cmake --build build
./build/src/session10/super_assert_demo
```


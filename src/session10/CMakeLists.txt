# Session 10: Preprocessor Exercises

# Exercise 5.1: Preprocessor 101 - Welcome message with conditional compilation
add_library(welcome STATIC welcome.c)

target_include_directories(welcome
    PUBLIC
        ${PROJECT_SOURCE_DIR}/include
)

# Allow LANGUAGE to be set via CMake cache variable
if(NOT DEFINED LANGUAGE)
    set(LANGUAGE EN CACHE STRING "Language for welcome message (EN, ES, FR, DE)")
endif()

# Define the LANGUAGE macro for the welcome library
target_compile_definitions(welcome PRIVATE LANGUAGE=${LANGUAGE})

# Exercise 5.1 executable
add_executable(preprocessor_101 preprocessor_101.c)
target_link_libraries(preprocessor_101 PRIVATE welcome)

# Exercise 5.2: Super Assert - Configurable assertion macro
add_executable(super_assert_demo super_assert_demo.c)

target_include_directories(super_assert_demo
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

# Optionally set super_assert configuration via CMake
if(DEFINED SUPER_ASSERT_TRACE)
    target_compile_definitions(super_assert_demo PRIVATE SUPER_ASSERT_TRACE=${SUPER_ASSERT_TRACE})
endif()

if(DEFINED SUPER_ASSERT_PERMISSIVE)
    target_compile_definitions(super_assert_demo PRIVATE SUPER_ASSERT_PERMISSIVE=${SUPER_ASSERT_PERMISSIVE})
endif()

if(DEFINED SUPER_ASSERT_VERBOSE)
    target_compile_definitions(super_assert_demo PRIVATE SUPER_ASSERT_VERBOSE=${SUPER_ASSERT_VERBOSE})
endif()

# Create additional build targets with different configurations for easy testing

# Target with TRACE enabled
add_executable(super_assert_trace super_assert_demo.c)
target_include_directories(super_assert_trace PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(super_assert_trace PRIVATE 
    SUPER_ASSERT_TRACE=1
    SUPER_ASSERT_PERMISSIVE=1
)

# Target with VERBOSE and PERMISSIVE enabled
add_executable(super_assert_verbose super_assert_demo.c)
target_include_directories(super_assert_verbose PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(super_assert_verbose PRIVATE 
    SUPER_ASSERT_VERBOSE=1
    SUPER_ASSERT_PERMISSIVE=1
)

# Target with all features enabled
add_executable(super_assert_full super_assert_demo.c)
target_include_directories(super_assert_full PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_compile_definitions(super_assert_full PRIVATE 
    SUPER_ASSERT_TRACE=1
    SUPER_ASSERT_PERMISSIVE=1
    SUPER_ASSERT_VERBOSE=1
)


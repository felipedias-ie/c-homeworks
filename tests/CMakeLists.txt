
add_executable(test_some_library test_some_library.c)
target_include_directories(test_some_library PRIVATE ${PROJECT_SOURCE_DIR}/third_party)

add_test(NAME test_some_library COMMAND test_some_library)

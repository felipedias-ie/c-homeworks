add_executable(test_session5
  test_session5.c
)

target_include_directories(test_session5 PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/third_party
)

target_link_libraries(test_session5 PRIVATE session5)

add_test(NAME test_session5 COMMAND test_session5)

add_executable(test_session7_rectangle
  session_7/rectangle_test.c
)

target_include_directories(test_session7_rectangle PRIVATE
  ${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/third_party
)

target_link_libraries(test_session7_rectangle PRIVATE session7_rectangle)

add_test(NAME test_session7_rectangle COMMAND test_session7_rectangle)


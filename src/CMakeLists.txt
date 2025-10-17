add_library(session5 STATIC
  session_5_6/session5.c
  session_5_6/pointer_shenanigans.c
  session_5_6/memory_layout_1.c
  session_5_6/casting_1.c
  session_5_6/casting_2.c
  session_5_6/string_concat.c
  session_5_6/malloc_fun.c
  session_5_6/privilege_escalation.c
)

target_include_directories(session5
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(main main.c)
target_link_libraries(main PRIVATE session5)

add_executable(session5_demo session_5_6/main.c)
target_link_libraries(session5_demo PRIVATE session5)

add_subdirectory(session_7)

add_subdirectory(session8)

add_subdirectory(session10)
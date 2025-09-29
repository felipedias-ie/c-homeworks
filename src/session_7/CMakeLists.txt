add_library(session7_rectangle STATIC
  rectangle.c
)

target_include_directories(session7_rectangle PUBLIC
  ${PROJECT_SOURCE_DIR}/include
)

add_executable(session7
  main.c
)
target_link_libraries(session7 PRIVATE session7_rectangle)

add_executable(are_you_aligned
  are_you_aligned.c
)


find_package(PLPlot REQUIRED)

add_executable(zipf main.c zipf.c)

target_link_libraries(zipf PRIVATE PLPLOT::plplot)
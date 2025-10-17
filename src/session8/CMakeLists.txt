find_package(PLPlot)

if(PLPlot_FOUND)
    add_executable(zipf main.c zipf.c)
    target_link_libraries(zipf PRIVATE PLPLOT::plplot)
    message(STATUS "PLPlot found - building session8")
else()
    message(WARNING "PLPlot not found - skipping session8 (zipf)")
endif()
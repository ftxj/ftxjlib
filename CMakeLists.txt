cmake_minimum_required (VERSION 3.10)

project (ftxjlib)

option(BUILD_TEST "Build test suite" OFF)
# option(BUILD_BENCHMARK "Build benchmark suite" OFF)

set(CMAKE_CXX_STANDARD 14)

include(cmake/Dependencies.cmake)

if(BUILD_TEST)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DFTXJLIB_BUILD_TEST")
endif()

include_directories("${PROJECT_SOURCE_DIR}")
add_subdirectory(ftxjlib)


if(BUILD_TEST)
    set(FTXJLIB_TEST_SRCS)
    add_subdirectory(test)
    
    foreach(FILE ${FTXJLIB_TEST_SRCS})
        get_filename_component(TMP ${FILE} NAME_WE)
        string(CONCAT RUNNABLE_FILE ${TMP} ".out")
        add_executable(${RUNNABLE_FILE} ${FILE})
        target_link_libraries(${RUNNABLE_FILE} ftxjlib ${FTXJLIB_TEST_LIBS})
    endforeach(FILE)

endif()
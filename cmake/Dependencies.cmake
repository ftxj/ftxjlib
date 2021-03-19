# find_package(Glog REQUIRED)
# list(APPEND FTXJLIB_LIBS ${GLOG_LIBRARIES})

add_subdirectory(3rd_party/glog)
include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/3rd_party/glog/glog/include)
list(APPEND FTXJLIB_TEST_LIBS "glog::glog")
set(ENV{GLOG_log_dir} ${PROJECT_SOURCE_DIR}/log)

if(BUILD_TEST)
    add_subdirectory(3rd_party/googletest)
    include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/3rd_party/googletest/googletest/include)
    list(APPEND FTXJLIB_TEST_LIBS "gtest_main")
endif()

if(BUILD_BENCHMARK)
    add_subdirectory(3rd_party/benchmark)
    include_directories(SYSTEM ${PROJECT_SOURCE_DIR}/3rd_party/benchmark/include)
    list(APPEND FTXJLIB_BENCHMARK_LIBS "gtest;benchmark::benchmark::main")
endif()
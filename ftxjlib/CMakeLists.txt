set(FTXJLIB_SRCS)

add_subdirectory(tree)
add_subdirectory(graph)
add_subdirectory(utils)
add_subdirectory(sparse_format)
add_subdirectory(io)

set(DIR_SRCS)

file(GLOB TMP *.h)
list(APPEND DIR_SRCS ${TMP})

file(GLOB TMP *.cpp)
list(APPEND DIR_SRCS ${TMP})


file(GLOB TMP *.hpp)
list(APPEND DIR_SRCS ${TMP})


file(GLOB TMP *.cc)
list(APPEND DIR_SRCS ${TMP})

list(APPEND FTXJLIB_SRCS ${DIR_SRCS})

add_library(ftxjlib SHARED ${FTXJLIB_SRCS})
target_link_libraries(ftxjlib ${FTXJLIB_LIBS})


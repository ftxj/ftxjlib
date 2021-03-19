set(DIR_SRCS)

file(GLOB TMP *.h)
list(APPEND DIR_SRCS ${TMP})

file(GLOB TMP *.cpp)
list(APPEND DIR_SRCS ${TMP})


file(GLOB TMP *.hpp)
list(APPEND DIR_SRCS ${TMP})


file(GLOB TMP *.cc)
list(APPEND DIR_SRCS ${TMP})

set(FTXJLIB_SRCS ${FTXJLIB_SRCS} ${DIR_SRCS} PARENT_SCOPE)
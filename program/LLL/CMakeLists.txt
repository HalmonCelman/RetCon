set(LLL_SOURCES 
LLL.c
)

set(LLL_HEADERS
LLL_conf.h
LLL.h
)
add_library(LLL ${LLL_SOURCES} ${LLL_HEADERS})

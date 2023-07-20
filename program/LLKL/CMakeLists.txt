set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-Wall -mmcu=atmega1284p -std=c99)

set(LLKL_SOURCES 
LLKL.c
)

set(LLKL_HEADERS
LLKL_conf.h
LLKL.h
)
add_library(LLKL ${LLKL_SOURCES} ${LLKL_HEADERS})

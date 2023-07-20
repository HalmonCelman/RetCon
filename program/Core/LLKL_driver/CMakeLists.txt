set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-Wall -mmcu=atmega1284p -std=c99)

set(LLKL_DIRECTORY ../../LLKL)

add_library(LLKL_driver LLKL_RetCon.c LLKL_RetCon.h)

target_include_directories(LLKL_driver PUBLIC ${LLKL_DIRECTORY})
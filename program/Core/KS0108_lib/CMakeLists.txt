set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-Wall -mmcu=atmega1284p -std=c99)

set(KS0108_SOURCES 
graphic.c
KS0108-AVR.c
KS0108.c
multi_buff.c
)

set(KS0108_HEADERS
font5x8.h
graphic.h
KS0108.h
multi_buff.h
)
add_library(KS0108 ${KS0108_SOURCES} ${KS0108_HEADERS})
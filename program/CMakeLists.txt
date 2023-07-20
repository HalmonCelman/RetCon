cmake_minimum_required(VERSION 3.26.4)

# Compiler setup
set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-Wall -std=c99 -mmcu=atmega1284p)
add_link_options(-mmcu=atmega1284p)


project(RetCon VERSION 1.0 LANGUAGES C)

option(USE_FATFS "" ON)
option(USE_KS0108_LIB "use driver for 128x64 LCD" ON)
option(USE_LLKL "" ON)


IF(USE_FATFS)
add_subdirectory(Core/FatFs_lib)  # sd card
list(APPEND RETCON_INCLUDE_DIRECTORIES Core/FatFs_lib)
list(APPEND RETCON_LINK_LIBRARIES FatFS)
ENDIF()

IF(USE_KS0108_LIB)
add_subdirectory(Core/KS0108_lib) # display
list(APPEND RETCON_INCLUDE_DIRECTORIES Core/KS0108_lib)
list(APPEND RETCON_LINK_LIBRARIES KS0108)
ENDIF()

IF(USE_LLKL)
add_subdirectory(Core/LLKL_driver)
add_subdirectory(LLKL)
list(APPEND RETCON_INCLUDE_DIRECTORIES Core/LLKL_driver)
list(APPEND RETCON_INCLUDE_DIRECTORIES LLKL)
list(APPEND RETCON_LINK_LIBRARIES LLKL_driver)
list(APPEND RETCON_LINK_LIBRARIES LLKL)
ENDIF()


# main file
add_executable(${PROJECT_NAME} main.c)

target_include_directories(${PROJECT_NAME} PUBLIC ${RETCON_INCLUDE_DIRECTORIES})

target_link_libraries(${PROJECT_NAME} ${RETCON_LINK_LIBRARIES})
cmake_minimum_required(VERSION 3.26.0)

# Compiler setup
set(CMAKE_C_COMPILER avr-gcc)
add_compile_options(-Wall -std=c99 -mmcu=atmega1284p -Wno-array-bounds -Os)
add_link_options(-mmcu=atmega1284p)

# paths to libraries
set(ROOT_TO_FATFS Core/FatFs_lib )
set(ROOT_TO_KS0108 Core/KS0108_lib)
set(ROOT_TO_LLL_DRIVER Core/LLL_driver)
set(ROOT_TO_SYSTEM Core/system)
set(ROOT_TO_ADDITIONAL Core/additional_graphics)
set(ROOT_TO_LLL LLL)


set(PATH_TO_FATFS ${CMAKE_SOURCE_DIR}/${ROOT_TO_FATFS} )
set(PATH_TO_KS0108 ${CMAKE_SOURCE_DIR}/${ROOT_TO_KS0108} )
set(PATH_TO_LLL_DRIVER ${CMAKE_SOURCE_DIR}/${ROOT_TO_LLL_DRIVER} )
set(PATH_TO_SYSTEM ${CMAKE_SOURCE_DIR}/${ROOT_TO_SYSTEM} )
set(PATH_TO_ADDITIONAL ${CMAKE_SOURCE_DIR}/${ROOT_TO_ADDITIONAL} )
set(PATH_TO_LLL ${CMAKE_SOURCE_DIR}/${ROOT_TO_LLL} )

set(BUILD_PATH_TO_FATFS ${CMAKE_BINARY_DIR}/${ROOT_TO_FATFS} )
set(BUILD_PATH_TO_KS0108 ${CMAKE_BINARY_DIR}/${ROOT_TO_KS0108} )
set(BUILD_PATH_TO_LLL_DRIVER ${CMAKE_BINARY_DIR}/${ROOT_TO_LLL_DRIVER} )
set(BUILD_PATH_TO_SYSTEM ${CMAKE_BINARY_DIR}/${ROOT_TO_SYSTEM} )
set(BUILD_PATH_TO_ADDITIONAL ${CMAKE_BINARY_DIR}/${ROOT_TO_ADDITIONAL} )
set(BUILD_PATH_TO_LLL ${CMAKE_BINARY_DIR}/${ROOT_TO_LLL} )

project(RetCon VERSION 1.0 LANGUAGES C)

IF("${CMAKE_BUILD_TYPE}" STREQUAL "Debug")
set(DEBUG_MODE 1)
ELSE()
set(DEBUG_MODE 0)
ENDIF()

option(SHOW_ON_SCREEN "" 1)

configure_file( config.h.in ${CMAKE_BINARY_DIR}/generated/config.h )

option(USE_FATFS "" ON)
option(USE_KS0108_LIB "use driver for 128x64 LCD" ON)
option(USE_LLL "" ON)
option(USE_ADDITIONAL_GRAPHICS "" ON)


#submodules
#update
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(
            COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            RESULT_VARIABLE GIT_SUBMOD_RESULT
        )
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()


IF(USE_FATFS)
add_subdirectory(${PATH_TO_FATFS})  # sd card
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_FATFS})
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES FatFS)
ENDIF()

IF(USE_KS0108_LIB)
add_subdirectory(${PATH_TO_KS0108}) # display
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_KS0108})
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES KS0108)
ENDIF()

IF(USE_LLL)
add_subdirectory(${PATH_TO_LLL_DRIVER})
add_subdirectory(${PATH_TO_LLL})
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_LLL_DRIVER})
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_LLL})
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES ${LLL_driver})
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES ${LLL})
ENDIF()


IF(USE_ADDITIONAL_GRAPHICS)
add_subdirectory(${PATH_TO_ADDITIONAL})  # sd card
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_ADDITIONAL})
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES additional_graphics)
ENDIF()

#system
add_subdirectory(${PATH_TO_SYSTEM})  # sd card
list(APPEND ${PROJECT_NAME}_INCLUDE_DIRECTORIES ${PATH_TO_SYSTEM} )
list(APPEND ${PROJECT_NAME}_LINK_LIBRARIES system)

# main file
add_executable(${PROJECT_NAME} main.c main.h)

target_include_directories(${PROJECT_NAME} PRIVATE ${${PROJECT_NAME}_INCLUDE_DIRECTORIES} ${CMAKE_BINARY_DIR}/generated/)

target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_LINK_LIBRARIES})
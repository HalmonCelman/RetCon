set(SYSTEM_SOURCES 
base.c
input.c
)

set(SYSTEM_INCLUDE 
base.h 
input.h 
)

add_library(system ${SYSTEM_SOURCES} ${SYSTEM_INCLUDE})

target_include_directories(system PRIVATE ${PATH_TO_KS0108})
target_include_directories(system PRIVATE ${PATH_TO_FATFS})
target_include_directories(system PRIVATE ${PATH_TO_LLKL_DRIVER})
target_include_directories(system PRIVATE ${PATH_TO_LLKL})
target_include_directories(system PRIVATE ${CMAKE_BINARY_DIR}/generated/)

target_link_libraries(system KS0108)
target_link_libraries(system FatFS)
target_link_libraries(system LLKL_driver)
target_link_libraries(system LLKL)

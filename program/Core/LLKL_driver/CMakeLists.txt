add_library(LLKL_driver LLKL_RetCon.c LLKL_RetCon.h)

target_include_directories(LLKL_driver PRIVATE ${PATH_TO_LLKL})
target_include_directories(LLKL_driver PRIVATE ${PATH_TO_FATFS})
target_include_directories(LLKL_driver PRIVATE ${PATH_TO_KS0108})

target_link_libraries(LLKL_driver LLKL)
target_link_libraries(LLKL_driver FatFS)
target_link_libraries(LLKL_driver KS0108)

add_library(LLL_driver LLL_RetCon.c RC_streams.c LLL_RetCon.h RC_streams.h)

target_include_directories(LLL_driver PRIVATE ${PATH_TO_LLL})
target_include_directories(LLL_driver PRIVATE ${PATH_TO_SYSTEM})
target_include_directories(LLL_driver PRIVATE ${PATH_TO_FATFS})
target_include_directories(LLL_driver PRIVATE ${PATH_TO_KS0108})
target_include_directories(LLL_driver PRIVATE ${CMAKE_BINARY_DIR}/generated/)

target_link_libraries(LLL_driver LLL)
target_link_libraries(LLL_driver system)
target_link_libraries(LLL_driver FatFS)
target_link_libraries(LLL_driver KS0108)

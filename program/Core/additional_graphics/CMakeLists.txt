add_library(additional_graphics additional_graphics.c additional_graphics.h)

target_include_directories(additional_graphics PRIVATE ${PATH_TO_FATFS} )
target_include_directories(additional_graphics PRIVATE ${PATH_TO_SYSTEM} )
target_include_directories(additional_graphics PRIVATE ${PATH_TO_KS0108} )
target_include_directories(additional_graphics PRIVATE ${PATH_TO_LLL_DRIVER} )
target_include_directories(additional_graphics PRIVATE ${PATH_TO_LLL} )

target_link_libraries(additional_graphics FatFS )
target_link_libraries(additional_graphics system )
target_link_libraries(additional_graphics KS0108 )
target_link_libraries(additional_graphics LLL_driver )
target_link_libraries(additional_graphics LLL )

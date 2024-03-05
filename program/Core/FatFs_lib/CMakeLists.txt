set(FATFS_SOURCES 
diskio.c
ff.c
mmc_spi.c
)

set(FATFS_HEADERS
diskio.h
ff.h
ffconf.h
mmc_spi.h
rtc.h
)
add_library(FatFS ${FATFS_SOURCES} ${FATFS_HEADERS})
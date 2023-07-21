set(FATFS_SOURCES 
diskio.c
ff.c
mmc_avr_spi.c
)

set(FATFS_HEADERS
diskio.h
ff.h
ffconf.h
mmc_avr.h
rtc.h
)
add_library(FatFS ${FATFS_SOURCES} ${FATFS_HEADERS})
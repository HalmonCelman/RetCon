#ifndef LLL_RETCON_H_INCLUDED
#define LLL_RETCON_H_INCLUDED

///includes
#include <stdint.h>
#include <LLL.h>
#include <ff.h>

// config section
#define LLL_COMM_BUFF_SIZE 128

#define LOGFILE "logs.txt"
// * end of config section *

#if LLL_USE_EXTERNAL_MEMORY
    #define NUMOFFILES 6
    #define CACHEDIR "RC"
    #define SLOWMEMFILE CACHEDIR"/rc.mem" //file for slow memory on SD card
    #define LABELFILE CACHEDIR"/rc.lab" //file for labels
    #define LOGFILE "log.txt"   
#else
    #define NUMOFFILES 4
#endif
/*
 file 0 - main program
 file 1 - logs
 file 2 - additional data - if you want to copy something or for  music etc
 file 3 - data - animations, etc
 file 4 - external memory file - SLOWMeM
 file 5 - external memory file - Stack
 */
///defines to avialibe files usages
typedef enum{
    FIL_MAIN = 0,   //main program
    FIL_LOG,        //log file
    FIL_AD,         //additional data file
    FIL_D,          //data file
    FIL_SLOWMEM,    //slow memory
    FIL_STACK       //slow stack
} LLL_FILES;

typedef struct{
    volatile uint32_t buffCounter;  // buffor counter - it's value that says which load of buffer is now readed 
    volatile uint32_t command;      //actual command - says which command is actually in use(in this buffer load)
    volatile uint32_t dCounter;     //dynamic counter - which char is actually analyzed
} lll_pt;

 ///tables
extern FIL file[NUMOFFILES];
extern lll_pt file_pt[NUMOFFILES]; 

#if LLL_USE_EXTERNAL_MEMORY
    void lll_init_external_memory(void);
    void lll_external_mem_write(uint32_t,uint8_t);
    uint8_t lll_external_mem_read(uint32_t);
    void lll_close_external_memory(void);
    void lll_init_cache(void);
void lll_remove_cache(void);
#endif

uint8_t lll_init_program(char*,uint32_t);
uint8_t lll_end_program(void);
uint8_t lll_get(void);
void lll_send_info(char*, uint32_t);
void lll_throw_error(uint8_t,char *,uint8_t);
void lll_set_label(uint32_t);
uint64_t lll_get_label(uint32_t);
void lll_goTo(uint64_t);
uint64_t lll_getPosition(void);
//streams
lll_err lll_stream_out(uint8_t data,uint8_t stream);
lll_err lll_stream_in(uint8_t *data,uint8_t stream);

#endif // LLL_RETCON_H_INCLUDED

#ifndef LLKL_RETCON_H_INCLUDED
#define LLKL_RETCON_H_INCLUDED

///includes
#include <stdint.h>
#include <LLKL.h>
#include <ff.h>

#define NUMOFFILES 4
#define SLOWMEMFILE "RC.mem" //file for slow memory on SD card
#define CACHEDIR "RC" 
/*
 file 0 - main program
 file 1 - logs
 file 2 - additional data - if you want to copy something or for  music etc
 file 3 - data - animations, etc
 file 4 - external memory file - SLOWMeM
 */
///defines to avialibe files usages
typedef enum{
    FIL_MAIN = 0, //main program
    FIL_LOG, //log file
    FIL_AD, //additional data file
    FIL_D, //data file
    FIL_SLOWMEM //slow memory
} LLKL_FILES;

typedef struct{
    volatile uint32_t buffCounter; // buffor counter - it's value that says which load of buffer is now readed 
    volatile uint32_t command; //actual command - says which command is actually in use(in this buffer load)
    volatile uint32_t dCounter; //dynamic counter - which char is actually analyzed
} llkl_pt;


 ///tables
extern FIL file[NUMOFFILES];
extern llkl_pt file_pt[NUMOFFILES]; 

///varialibes
extern FATFS fs1;
extern WORD s1;
extern BYTE res;
extern volatile uint8_t llkl_physical_read; //says if it's needed to reload buffer - caused end of buffer
extern volatile uint8_t llkl_reload_buffer; //says if it's needed to reload buffer - caused change of file
extern volatile uint8_t llkl_actual_file; //says which file is already used

///functions
extern uint8_t errc(uint8_t,char*);
extern uint8_t err(uint8_t,char*);

#if LLKL_USE_EXTERNAL_MEMORY
    void llkl_init_external_memory(void);
    void llkl_external_mem_write(uint32_t,uint8_t);
    uint8_t llkl_external_mem_read(uint32_t);
    void llkl_close_external_memory(void);
#endif
void llkl_init_cache(void);
void llkl_remove_cache(void);
uint8_t llkl_init_main_program(char*,uint32_t);
uint8_t llkl_end_main_program(void);
uint8_t llkl_get(void);
void llkl_send_info(char*, uint32_t);
void llkl_throw_error(uint8_t,char *,uint8_t);


#endif // LLKL_RETCON_H_INCLUDED

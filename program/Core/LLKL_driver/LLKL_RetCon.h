#ifndef LLKL_RETCON_H_INCLUDED
#define LLKL_RETCON_H_INCLUDED

///includes
#include <stdint.h>
#include <LLKL.h>
#include "../FatFs_lib/ff.h"

#define NUMOFFILES 4
/*
 file 0 - main program
 file 1 - logs
 file 2 - additional data - if you want to copy something or for  music etc
 file 3 - data - animations, etc
 file 4 - subprogram 1
 */
 ///defines to avialibe files usages
 #define FIL_MAIN 0 //main program
 #define FIL_LOG 1 //log file
 #define FIL_AD 2 //additional data file
 #define FIL_D 3 //data file
 #define FIL_SUBOFFS 4 //offset for subprograms, also first subprogram
///and to file pointers
 #define LLKL_PT_MAIN file_pt[FIL_MAIN]
 #define LLKL_PT_DATA file_pt[FIL_D]
 #define LLKL_PT_DATA2 file_pt[FIL_AD]
 #define LLKL_PT_SUBP(x) file_pt[FIL_SUBOFFS+x]

 typedef struct{
    volatile uint32_t buffpt; // buffor pointer -it's an value that says which load of buffer is now readed
    volatile uint32_t compt; //command pointer - points which command is actually in use(in this buffer load)
    volatile uint32_t dpt; //dynamic pointer - which char is actually analyzed
} llkl_pt;


 ///tables
    extern FIL file[NUMOFFILES]; //extern and declaration in llkl_atmega1284p needed for gcc 12
    extern llkl_pt file_pt[NUMOFFILES]; //extern and declaration in llkl_atmega1284p needed for gcc 12

///varialibes
    extern FATFS fs1;
    extern WORD s1;
    extern BYTE res;
extern volatile uint8_t llkl_physical_read; //says if it's needed to reload buffer - caused end of buffer
extern volatile uint8_t llkl_reload_buffer; //says if it's needed to reload buffer - caused change of file
extern volatile uint8_t llkl_actual_file; //says which file is already used

///functions
extern uint8_t errc(uint8_t,char*);
uint8_t llkl_init_program(char*, uint8_t);
uint8_t llkl_end_program(uint8_t);
uint8_t llkl_get(void);
uint8_t llkl_disp_char(uint8_t);
void llkl_external_mem_write(uint32_t,uint8_t);
void llkl_send_info(char*, uint32_t);


extern volatile int Timer_delay;

#ifndef delay
#define delay(x) Timer_delay=x;while(Timer_delay);
#endif

#endif // LLKL_RETCON_H_INCLUDED

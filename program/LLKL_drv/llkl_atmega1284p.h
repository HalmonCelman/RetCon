#ifndef LLKL_ATMEGA1284P_H_INCLUDED
#define LLKL_ATMEGA1284P_H_INCLUDED

///includes
#include "../LLKL/LLKL.h"
#include "../FatFs_lib/ff.h"

///varialibes
extern FIL file2;
///functions
extern uint8_t errc(uint8_t,char*);
uint8_t llkl_get(void);
uint8_t llkl_disp_char(uint8_t);
void llkl_send_info(char*, uint32_t);

#endif // LLKL_ATMEGA1284P_H_INCLUDED

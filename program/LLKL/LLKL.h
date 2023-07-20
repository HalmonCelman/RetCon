#ifndef LLKL_TINY_H_INCLUDED
#define LLKL_TINY_H_INCLUDED

///include
#include <stdint.h>
#include "LLKL_conf.h"

///Avialibe errors

typedef enum{
    LLKL_OK = 0,
    LLKL_NO_COMMAND = 1,
    LLKL_UNKNOWN_TYPE =2,
    LLKL_EXPECTED_SYMBOL=3,
    LLKL_EOP=3 //end of program
}  llkl_err_status ;


///error stream
typedef struct{
    llkl_err_status status; //actual status returned
    uint8_t additional; //additional information about error
} llkl_err;

///memory
//***********LLKL_FLAG_MAP is in LLKL_conf.h in DANGER ZONE
extern uint8_t LLKL_FAST_MEM[LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER];
extern uint8_t LLKL_COMM_BUFF[LLKL_COMM_BUFF_SIZE];
extern uint32_t LLKL_LABEL[LLKL_LABEL_NUMBER];

///global varialibes

extern volatile uint8_t llkl_h8; //helpful 8bit varialibe
extern volatile uint8_t llkl_c; //command
///functions

void LLKL_init(void);
llkl_err LLKL_exec(void); //execute program
uint32_t LLKL_load_reg_addr(uint8_t); //load adress of register - MODE: 0 - normal register adress &, 1 - flag %, 2 - indirect *, returns adress
uint8_t LLKL_load_mem(uint32_t);
void LLKL_save_mem(uint32_t,uint8_t);

//driver functions - this functions should be specified in driver for device
extern uint8_t llkl_get(void);
extern void llkl_send_info(char*, uint32_t);
extern void llkl_external_mem_write(uint32_t,uint8_t);

///llkl_instructions
llkl_err LLKL_seri(void);

///some helpful macros
#define LLKL_REG_MODE ((llkl_h8 == '&') ? 0 : ((llkl_h8 == '%') ? 1 : 2))

#define LLKL_CHECK_INT(x)  if(llkl_get() != 0x27){ x.status=LLKL_EXPECTED_SYMBOL;x.additional=0x27;return x;}  //x should be an error handler

#define LLKL_CHECK_REG(x) llkl_h8=llkl_get(); \
 if(!(llkl_h8=='&' || llkl_h8=='%' || llkl_h8=='*')){ x.status=LLKL_EXPECTED_SYMBOL;x.additional='&';return x;}  //x should be an error handler, which symbol has been checked is in llkl_h8 varialibe

#endif // LLKL_TINY_H_INCLUDED

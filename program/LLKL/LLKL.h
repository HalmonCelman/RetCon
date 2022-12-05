#ifndef LLKL_TINY_H_INCLUDED
#define LLKL_TINY_H_INCLUDED

///types
//uint8_t
#ifndef uint8_t
#define uint8_t  unsigned char
#endif // uint8_t

#ifndef uint32_t
#define uint32_t  unsigned long int
#endif // uint32_t

#ifndef uint64_t
#define uint64_t  unsigned long long int
#endif // uint64_t


///Avialibe errors

typedef enum{
    LLKL_OK = 0,
    LLKL_NO_COMMAND = 1,
    LLKL_UNKNOWN_TYPE =2,
    LLKL_EXPECTED_SYMBOL=3
}  llkl_err_status ;


///error stream
typedef struct{
    llkl_err_status status; //actual status returned
    uint8_t additional; //additional information about error
} llkl_err;



///include
#include "LLKL_conf.h"

///memory
//***********LLKL_FLAG_MAP is in LLKL_conf.h in DANGER ZONE
uint8_t LLKL_FAST_MEM[LLKL_FAST_MEM_SIZE];
uint64_t LLKL_LABEL[LLKL_LABEL_NUMBER];

///global varialibes
volatile uint32_t llkl_compt; //command pointer
volatile uint32_t llkl_dpt; //dynamic pointer

volatile uint8_t llkl_h8; //helpful 8bit varialibe
volatile uint8_t llkl_c; //command
///functions
void LLKL_init(void);
llkl_err LLKL_exec(void); //execute program
uint64_t LLKL_load_reg_addr(uint8_t); //load adress of register - MODE: 0 - normal register adress &, 1 - flag %, 2 - indirect *, returns adress
uint8_t LLKL_load_mem(uint64_t);
void LLKL_save_mem(uint64_t,uint8_t);
///llkl_instructions
llkl_err LLKL_seri(void);

///some helpful macros
#define LLKL_REG_MODE (llkl_h8 == '&') ? 0 : ((llkl_h8 == '%') ? 1 : 2)

#define LLKL_CHECK_INT(x)  if(llkl_get()!=27){ x.status=LLKL_EXPECTED_SYMBOL;x.additional=27;return x;}  //x should be an error handler

#define LLKL_CHECK_REG(x) llkl_h8=llkl_get(); \
 if(!(llkl_h8=='&' || llkl_h8=='%' || llkl_h8=='*')){ x.status=LLKL_EXPECTED_SYMBOL;x.additional='&';return x;}  //x should be an error handler, which symbol has been checked is in llkl_h8 varialibe





#endif // LLKL_TINY_H_INCLUDED

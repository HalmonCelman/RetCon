#ifndef LLL_TINY_H_INCLUDED
#define LLL_TINY_H_INCLUDED

///include
#include <stdint.h>
#include "LLL_conf.h"

///Avialibe errors

typedef enum{
    LLL_OK = 0,
    LLL_NO_COMMAND,
    LLL_UNKNOWN_TYPE,
    LLL_EXPECTED_SYMBOL,
    LLL_WRONG_STREAM,
    LLL_EOP //end of program
}  lll_err_status ;

typedef enum{
    LLL_ADD = 0,
    LLL_ADDI,
    LLL_SUB,
    LLL_SUBI,
    LLL_MUL,
    LLL_MULI,
    LLL_DIV,
    LLL_DIVI,
    LLL_AND,
    LLL_ANDI,
    LLL_OR,
    LLL_ORI,
    LLL_NOT,
    LLL_INC,
    LLL_DEC,
    LLL_SER,
    LLL_SERI,
    LLL_LJMP,
    LLL_JMP,
    LLL_CMP,
    LLL_CMPI,
    LLL_SEQ,
    LLL_DEQ,
    LLL_SLO,
    LLL_DLO,
    LLL_SGR,
    LLL_DGR,
    LLL_IN,
    LLL_OUT
} lll_command_list;

///error stream
typedef struct{
    lll_err_status status; //actual status returned
    uint8_t additional; //additional information about error
} lll_err;

///memory
//***********LLL_FLAG_MAP is in LLL_conf.h in DANGER ZONE
extern uint8_t LLL_FAST_MEM[LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER];
extern uint8_t LLL_COMM_BUFF[LLL_COMM_BUFF_SIZE];
extern uint64_t LLL_LABEL[LLL_LABEL_NUMBER];

///global varialibes

extern volatile uint8_t lll_h8; //helpful 8bit varialibe
extern volatile uint8_t lll_number; //how many registers to copy itp
extern volatile uint8_t lll_c; //command
///functions

void LLL_init(void);
void LLL_end(void);
void LLL_run(char *);
lll_err LLL_exec(void); //execute command
uint32_t LLL_load_reg_addr(uint8_t); //load adress of register - MODE: 0 - normal register adress &, 1 - flag %, 2 - indirect *, returns adress
uint8_t LLL_load_mem(uint32_t);
void LLL_save_mem(uint32_t,uint8_t);

//driver functions - this functions should be specified in driver for device
#if LLL_USE_EXTERNAL_MEMORY
    extern void lll_init_external_memory(void);
    extern void lll_external_mem_write(uint32_t,uint8_t);
    extern uint8_t lll_external_mem_read(uint32_t);
    extern void lll_close_external_memory(void);
#endif
extern void lll_init_cache(void);
extern void lll_remove_cache(void);
extern uint8_t lll_init_main_program(char*,uint32_t);
extern uint8_t lll_end_main_program(void);
extern uint8_t lll_get(void);
extern void lll_send_info(char*, uint32_t);
extern void lll_throw_error(uint8_t,char *,uint8_t);
extern void lll_set_label(uint32_t);
//streams for device
extern lll_err lll_stream_out(uint32_t,uint8_t);

///lll_instructions
lll_err LLL_add(void);
lll_err LLL_addi(void);
lll_err LLL_seri(void);
lll_err LLL_out(void);

///some helpful macros
#define LLL_REG_MODE ((lll_h8 == '&') ? 0 : ((lll_h8 == '%') ? 1 : 2))
#define LLL_CHECK_LABEL(x) ((x == ':')? 1 : 0)

#define LLL_CHECK_REG(x) lll_h8=lll_get(); \
 if(!(lll_h8=='&' || lll_h8=='%' || lll_h8=='*')){ x.status=LLL_EXPECTED_SYMBOL;x.additional='&';return x;}  //x should be an error handler, which symbol has been checked is in lll_h8 varialibe

#endif // LLL_TINY_H_INCLUDED

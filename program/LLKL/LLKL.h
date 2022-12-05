#ifndef LLKL_TINY_H_INCLUDED
#define LLKL_TINY_H_INCLUDED

///Avialibe errors

typedef enum{
    LLKL_OK = 0,
    LLKL_NO_COMMAND = 1,
    LLKL_UNKNOWN_TYPE =2
}  llkl_err_status ;


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


///error stream
typedef struct{
    llkl_err_status status; //actual status returned
    uint8_t additional; //additional information about error
} llkl_err;

#define LLKL_EXEC(X,Y) if(Y.status!=LLKL_OK) return Y; else X=Y.additional;

///include
#include "LLKL_conf.h"

///memory
uint8_t LLKL_RAM[LLKL_RAM_SIZE];
uint8_t LLKL_PARAM[LLKL_MAX_PARAM_NUMBER];

///command table
#define LLKL_DISP_CHAR 'c'
#define LLKL_KEY_STATUS 's'

///global varialibes
volatile uint32_t llkl_compt; //command pointer
volatile uint32_t llkl_dpt; //dynamic pointer

///functions
llkl_err LLKL_exec(void);
llkl_err LLKL_aloccate_mem(uint64_t,uint64_t,uint8_t);
#endif // LLKL_TINY_H_INCLUDED

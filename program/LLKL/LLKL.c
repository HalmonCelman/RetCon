#include "LLKL.h"

void LLKL_init(void){
///initialze FLAG_MAP
LLKL_FLAG_MAP[0]='O';   //OVF - Overflow flag
LLKL_FLAG_MAP[1]='M';   // MUL - Multiplication flag
LLKL_FLAG_MAP[2]='R';   // Rest flag
}


llkl_err LLKL_exec(void){
    llkl_err exec_err; //error status

    exec_err.status=LLKL_OK; //default - OK

    llkl_c=llkl_get(); //read command

    #if LLKL_DEBUG_MODE==1
        llkl_send_info("MainExec command: ",llkl_c); //send debug info
    #endif // LLKL_DEBUG_MODE

    switch(llkl_c){ //execute
        case 24:    //SERI
            exec_err=LLKL_seri();
        break;

        default:
            ///if no command executed
            exec_err.status = LLKL_NO_COMMAND; //command not found
            exec_err.additional = llkl_c; //which command wasn't found
        break;
    }

    return exec_err;
}

uint32_t LLKL_load_reg_addr(uint8_t mode){
uint32_t llkl_reg=0;
    if(mode==0){ //if normal mode
        for(int i=0;i<4;i++){ //read adress
            llkl_reg = (llkl_reg<<8) + llkl_get();
        }
    }
    if(mode==1){ //if flag mode
        llkl_h8=llkl_get();
        for(int i=0;i<LLKL_FLAG_NUMBER;i++){ //find flag adress
            if(LLKL_FLAG_MAP[i]==llkl_h8){
                llkl_reg=LLKL_FAST_MEM_SIZE+i;
            }
        }
    }
    if(mode==2){ //if indirect mode
    uint32_t llkl_pom=0;
        for(int i=0;i<4;i++){ //get indirect adress
            llkl_pom = (llkl_pom<<8) + llkl_get();
        }
        for(int i=0;i<4;i++){ //get direct adress
            llkl_reg = (llkl_reg<<8) + LLKL_load_mem(llkl_pom+i);
        }
    }
    return llkl_reg;
}

uint8_t LLKL_load_mem(uint32_t adress){ //!!!!!!!!!!!!todo
return LLKL_FAST_MEM[adress];
}

void LLKL_save_mem(uint32_t adress, uint8_t value){ //!!!!!!!!!!!!todo
LLKL_FAST_MEM[adress]=value;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                                              LLKL instructions                                                                  //////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
llkl_err LLKL_seri(void){
llkl_err inst_err;

uint32_t llkl_reg; //adress of register

inst_err.status=LLKL_OK;

//main instruction code

#if LLKL_DEBUG_MODE==1
    LLKL_CHECK_REG(inst_err); //check if properly written
    llkl_send_info("seri reg mode: ",LLKL_REG_MODE); //send debug info
    llkl_reg=LLKL_load_reg_addr(LLKL_REG_MODE); //load register adress
    llkl_send_info("seri adress: ",llkl_reg); //send debug info
    LLKL_CHECK_INT(inst_err); //check if it's a number
    llkl_h8=llkl_get(); //read value
    llkl_send_info("seri value: ",llkl_reg); //send debug info
#else
    llkl_h8=llkl_get(); //load mode of register
    llkl_reg=LLKL_load_reg_addr(LLKL_REG_MODE); //load adress
    llkl_get(); //ignore '
    llkl_h8=llkl_get(); //read value
#endif // LLKL_DEBUG_MODE

LLKL_save_mem(llkl_reg,llkl_h8);
/////////////////////////////////////////////
return inst_err;
}

/*
llkl_err LLKL_seri(void){
llkl_err inst_err;
//main instruction code

//////////////////////////////////////////
return inst_err;
}
*/

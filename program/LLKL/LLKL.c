#include "LLKL.h"

///declarations of buffers due to gcc 12 
uint8_t LLKL_FAST_MEM[LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER];
uint8_t LLKL_COMM_BUFF[LLKL_COMM_BUFF_SIZE];
uint32_t LLKL_LABEL[LLKL_LABEL_NUMBER];
const uint8_t LLKL_FLAG_MAP[LLKL_FLAG_NUMBER]={'O','M','R'};

volatile uint8_t llkl_c;
volatile uint8_t llkl_h8;


void LLKL_init(void){
    llkl_init_cache();
    #if LLKL_USE_EXTERNAL_MEMORY
        //llkl_init_external_memory();
    #endif
}

void LLKL_end(void){
    #if LLKL_USE_EXTERNAL_MEMORY
        //llkl_close_external_memory();
    #endif
    llkl_remove_cache();
}

void LLKL_run(char * name){
    uint8_t res=0;
    res=llkl_init_main_program(name,0);
    llkl_throw_error(res,"Failed to run program!",0);

    if(!res){ //if initialized properly
    while(!res){
        res=LLKL_exec().status;
    }
    if(res != LLKL_EOP){
        llkl_send_info("ERROR EXEC: ",res);
        llkl_throw_error(res,"ERROR :",0);
    }
    llkl_end_main_program();
    }
}
llkl_err LLKL_exec(void){
    llkl_err exec_err; //error status

    exec_err.status=LLKL_OK; //default - OK

    llkl_c=llkl_get(); //read command
    if(llkl_c==0xFF){
        exec_err.status=LLKL_EOP;
        return exec_err;
    }
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

uint8_t LLKL_load_mem(uint32_t adress){
     #if LLKL_USE_EXTERNAL_MEMORY    
        if(adress<LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER){
            return LLKL_FAST_MEM[adress];
        }else{
            return llkl_external_mem_read(adress);
        }
    #else
        return LLKL_FAST_MEM[adress];
    #endif
}

void LLKL_save_mem(uint32_t adress, uint8_t value){ 
    #if LLKL_USE_EXTERNAL_MEMORY    
        if(adress<LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER){
            LLKL_FAST_MEM[adress]=value;
        }else{
        llkl_external_mem_write(adress,value);
        }
    #else
        LLKL_FAST_MEM[adress]=value;
    #endif
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
    llkl_send_info("seri value: ",llkl_h8); //send debug info
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


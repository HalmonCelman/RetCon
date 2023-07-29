#include "LLKL.h"

///declarations of buffers due to gcc 12 
uint8_t LLKL_FAST_MEM[LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER];
uint8_t LLKL_COMM_BUFF[LLKL_COMM_BUFF_SIZE];
uint64_t LLKL_LABEL[LLKL_LABEL_NUMBER];
const uint8_t LLKL_FLAG_MAP[LLKL_FLAG_NUMBER]={'O','A','R'};

volatile uint8_t llkl_c;
volatile uint8_t llkl_h8;
volatile uint8_t llkl_number;

static uint8_t LLKL_getFlagNumber(char flag){
    for(int i=0;i<LLKL_FLAG_NUMBER;i++){ //find flag adress
        if(LLKL_FLAG_MAP[i]==flag){
            return i;
        }
    }
    #if LLKL_DEBUG_MODE
        llkl_throw_error(1,"INVALID FLAG ",0);
    #endif
    return 0;
}

static uint32_t LLKL_get32bit(void){
    uint32_t val32=0;
    for(int i=0;i<4;i++){ //read adress
        val32 = (val32<<8) + llkl_get();
    }
    return val32;
}


void LLKL_init(void){
    #if LLKL_USE_EXTERNAL_MEMORY
        llkl_init_cache();
        llkl_init_external_memory();
    #endif
}

void LLKL_end(void){
    #if LLKL_USE_EXTERNAL_MEMORY
        llkl_close_external_memory();
        llkl_remove_cache();
    #endif
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
    if(LLKL_CHECK_LABEL(llkl_c)){
        llkl_set_label(LLKL_get32bit());
        llkl_c=llkl_get(); // read once more
    }
    if(llkl_c==0xFF){
        exec_err.status=LLKL_EOP;
        return exec_err;
    }
    #if LLKL_DEBUG_MODE==1
        llkl_send_info("MainExec command: ",llkl_c); //send debug info
    #endif // LLKL_DEBUG_MODE

    switch(llkl_c){ //execute
        case LLKL_ADD:    
            exec_err=LLKL_add();
        break;
        case LLKL_SERI:    
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
        llkl_reg=LLKL_get32bit();
        llkl_reg+=LLKL_FLAG_NUMBER;
    }
    if(mode==1){ //if flag mode
        return LLKL_getFlagNumber(llkl_get());
    }
    if(mode==2){ //if indirect mode
        uint32_t llkl_pom=LLKL_get32bit()+LLKL_FLAG_NUMBER;
        for(int i=0;i<4;i++){ //get direct adress
            llkl_reg = (llkl_reg<<8) + LLKL_load_mem(llkl_pom+i);
        }
        llkl_reg+=LLKL_FLAG_NUMBER;
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
llkl_err LLKL_add(void){
    llkl_err inst_err;
    inst_err.status=LLKL_OK;

    uint32_t llkl_reg;
    uint8_t llkl_ovf=0;
    uint16_t llkl_sum=0;

    #if LLKL_DEBUG_MODE
        llkl_number=llkl_get();
        llkl_send_info("add number: ",llkl_number);
        LLKL_CHECK_REG(inst_err);
        llkl_send_info("add reg mode: ",LLKL_REG_MODE);
        llkl_reg = LLKL_load_reg_addr(LLKL_REG_MODE);
    #else
        llkl_number=llkl_get();
        llkl_h8=llkl_get();
        llkl_reg1=LLKL_load_reg_addr(LLKL_REG_MODE);
    #endif

    for(int i=0;i<llkl_number,i++){
        llkl_sum += LLKL_load_mem(llkl_reg+i);
        if(llkl_sum > 255){
            llkl_sum -= 256;
            llkl_ovf=1;
        }    
    }
    LLKL_save_mem(llkl_reg, (uint8_t)llkl_sum);
    LLKL_save_mem(LLKL_getFlagNumber('O'), 255);
}



llkl_err LLKL_seri(void){
llkl_err inst_err;

uint32_t llkl_reg; //adress of register

inst_err.status=LLKL_OK;

//main instruction code

#if LLKL_DEBUG_MODE==1
    llkl_number=llkl_get(); //load number
    llkl_send_info("seri number: ",llkl_number); //send debug info
    LLKL_CHECK_REG(inst_err); //check if properly written
    llkl_send_info("seri reg mode: ",LLKL_REG_MODE); //send debug info
    llkl_reg=LLKL_load_reg_addr(LLKL_REG_MODE); //load register adress
    llkl_send_info("seri adress: ",llkl_reg); //send debug info
#else
    llkl_number=llkl_get(); //load number
    llkl_h8=llkl_get(); //load mode of register
    llkl_reg=LLKL_load_reg_addr(LLKL_REG_MODE); //load adress
#endif // LLKL_DEBUG_MODE
for(int i=0;i<llkl_number;i++){
    llkl_h8=llkl_get();
    #if LLKL_DEBUG_MODE
        llkl_send_info("seri value: ",llkl_h8);
    #endif
    LLKL_save_mem(llkl_reg+i,llkl_h8);
}
/////////////////////////////////////////////
return inst_err;
}


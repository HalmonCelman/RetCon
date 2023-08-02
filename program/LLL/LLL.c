#include "LLL.h"

///declarations of buffers due to gcc 12 
uint8_t LLL_FAST_MEM[LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER];
uint8_t LLL_COMM_BUFF[LLL_COMM_BUFF_SIZE];
uint64_t LLL_LABEL[LLL_LABEL_NUMBER];
const uint8_t LLL_FLAG_MAP[LLL_FLAG_NUMBER]={'O','A','R'};

volatile uint8_t lll_c;
volatile uint8_t lll_h8;
volatile uint8_t lll_number;

//returns flag number(which is also it's adress)
static uint8_t LLL_getFlagNumber(char flag){
    for(int i=0;i<LLL_FLAG_NUMBER;i++){ //find flag adress
        if(LLL_FLAG_MAP[i]==flag){
            return i;
        }
    }
    #if LLL_DEBUG_MODE
        lll_throw_error(1,"INVALID FLAG ",0);
    #endif
    return 0;
}

/*
LLL_get32bit: gets 32bit value from program
returns this value
*/
static uint32_t LLL_get32bit(void){
    uint32_t val32=0;
    for(int i=0;i<4;i++){ //read adress
        val32 = (val32<<8) + lll_get();
    }
    return val32;
}


void LLL_init(void){
    #if LLL_USE_EXTERNAL_MEMORY
        lll_init_cache();
        lll_init_external_memory();
    #endif
}

void LLL_end(void){
    #if LLL_USE_EXTERNAL_MEMORY
        lll_close_external_memory();
        lll_remove_cache();
    #endif
}

void LLL_run(char * name){
    uint8_t res=0;
    #if LLL_DEBUG_MODE
        lll_send_info(name,0);
    #endif
    res=lll_init_main_program(name,0);
    lll_throw_error(res,"Failed to run program!",0);

    if(!res){ //if initialized properly
    while(!res){
        res=LLL_exec().status;
    }
    if(res != LLL_EOP){
        lll_send_info("ERROR EXEC: ",res);
        lll_throw_error(res,"ERROR :",0);
    }
    lll_end_main_program();
    }
}


lll_err LLL_exec(void){
    lll_err exec_err; //error status

    exec_err.status=LLL_OK; //default - OK

    lll_c=lll_get(); //read command
    if(LLL_CHECK_LABEL(lll_c)){
        lll_set_label(LLL_get32bit());
        lll_c=lll_get(); // read once more
    }
    if(lll_c==0xFF){
        exec_err.status=LLL_EOP;
        return exec_err;
    }
    #if LLL_DEBUG_MODE==1
        lll_send_info("MainExec command: ",lll_c); //send debug info
    #endif // LLL_DEBUG_MODE

    switch(lll_c){ //execute
        case LLL_ADD:    
            exec_err=LLL_add();
        break;
        case LLL_ADDI:
            exec_err=LLL_addi();
        break;

        case LLL_SERI:    
            exec_err=LLL_seri();
        break;

        case LLL_OUT:
            exec_err=LLL_out();
        break;
        default:
            ///if no command executed
            exec_err.status = LLL_NO_COMMAND; //command not found
            exec_err.additional = lll_c; //which command wasn't found
        break;
    }

    return exec_err;
}

uint32_t LLL_load_reg_addr(uint8_t mode){
uint32_t lll_reg=0;
    if(mode==0){ //if normal mode
        lll_reg=LLL_get32bit();
        lll_reg+=LLL_FLAG_NUMBER;
    }
    if(mode==1){ //if flag mode
        return LLL_getFlagNumber(lll_get());
    }
    if(mode==2){ //if indirect mode
        uint32_t lll_pom=LLL_get32bit()+LLL_FLAG_NUMBER;
        for(int i=0;i<4;i++){ //get direct adress
            lll_reg = (lll_reg<<8) + LLL_load_mem(lll_pom+i);
        }
        lll_reg+=LLL_FLAG_NUMBER;
    }
    return lll_reg;
}

uint8_t LLL_load_mem(uint32_t adress){
     #if LLL_USE_EXTERNAL_MEMORY    
        if(adress<LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER){
            return LLL_FAST_MEM[adress];
        }else{
            return lll_external_mem_read(adress);
        }
    #else
        return LLL_FAST_MEM[adress];
    #endif
}

void LLL_save_mem(uint32_t adress, uint8_t value){ 
    #if LLL_USE_EXTERNAL_MEMORY    
        if(adress<LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER){
            LLL_FAST_MEM[adress]=value;
        }else{
        lll_external_mem_write(adress,value);
        }
    #else
        LLL_FAST_MEM[adress]=value;
    #endif
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////                                                              LLL instructions                                                                  //////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
lll_err LLL_add(void){
    lll_err inst_err;
    inst_err.status=LLL_OK;

    uint32_t lll_reg;
    uint8_t lll_ovf=0;
    uint16_t lll_sum=0;

    #if LLL_DEBUG_MODE
        lll_number=lll_get();
        lll_send_info("add number: ",lll_number);
        LLL_CHECK_REG(inst_err);
        lll_send_info("add reg mode: ",LLL_REG_MODE);
        lll_reg = LLL_load_reg_addr(LLL_REG_MODE);
    #else
        lll_number=lll_get();
        lll_h8=lll_get();
        lll_reg1=LLL_load_reg_addr(LLL_REG_MODE);
    #endif

    for(int i=0;i<lll_number;i++){
        lll_sum += LLL_load_mem(lll_reg+i);
        if(lll_sum > 255){
            lll_sum -= 255;
            lll_ovf=1;
        }    
    }

    #if LLL_DEBUG_MODE
        lll_send_info("add sum: ",lll_sum);
        lll_send_info("add ovf: ",(lll_ovf ? 255 : 0));
    #endif

    LLL_save_mem(lll_reg, (uint8_t)lll_sum);
    LLL_save_mem(LLL_getFlagNumber('O'), (lll_ovf ? 255 : 0));

    return inst_err;
}

lll_err LLL_addi(void){
    lll_err inst_err;
    inst_err.status=LLL_OK;

    uint32_t lll_reg;
    uint16_t lll_sum=0;

    #if LLL_DEBUG_MODE
        LLL_CHECK_REG(inst_err);
        lll_send_info("addi reg mode: ",LLL_REG_MODE);
        lll_reg=LLL_load_reg_addr(LLL_REG_MODE);
        lll_sum=LLL_load_mem(lll_reg)+lll_get();
        lll_send_info("addi sum: ",((lll_sum>256) ? (lll_sum-255) : lll_sum));
        lll_send_info("add ovf: ",((lll_sum>256) ? 255 : 0));
    #else
        lll_h8=lll_get();
        lll_reg=LLL_load_reg_addr(LLL_REG_MODE);
        lll_sum=LLL_load_mem(lll_reg)+lll_get();
    #endif

    if(lll_sum>255){
        lll_sum-=255;
        LLL_save_mem(LLL_getFlagNumber('O'), 255);
    }else{
        LLL_save_mem(LLL_getFlagNumber('O'), 0);
    }
    LLL_save_mem(lll_reg, (uint8_t)lll_sum);

    return inst_err;
}

lll_err LLL_seri(void){
lll_err inst_err;

uint32_t lll_reg; //adress of register

inst_err.status=LLL_OK;

//main instruction code

#if LLL_DEBUG_MODE==1
    lll_number=lll_get(); //load number
    lll_send_info("seri number: ",lll_number); //send debug info
    LLL_CHECK_REG(inst_err); //check if properly written
    lll_send_info("seri reg mode: ",LLL_REG_MODE); //send debug info
    lll_reg=LLL_load_reg_addr(LLL_REG_MODE); //load register adress
    lll_send_info("seri adress: ",lll_reg); //send debug info
#else
    lll_number=lll_get(); //load number
    lll_h8=lll_get(); //load mode of register
    lll_reg=LLL_load_reg_addr(LLL_REG_MODE); //load adress
#endif // LLL_DEBUG_MODE
for(int i=0;i<lll_number;i++){
    lll_h8=lll_get();
    #if LLL_DEBUG_MODE
        lll_send_info("seri value: ",lll_h8);
    #endif
    LLL_save_mem(lll_reg+i,lll_h8);
}
/////////////////////////////////////////////
return inst_err;
}

lll_err LLL_out(void){
    lll_err inst_err;
    inst_err.status=LLL_OK;
    
    inst_err = lll_stream_out(LLL_get32bit(),LLL_load_mem(LLL_getFlagNumber('A')));

    return inst_err;
}
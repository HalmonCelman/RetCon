#include "LLKL.h"

llkl_err LLKL_exec(void){
    llkl_err exec_err; //error status

    uint8_t llkl_c; //command
    uint8_t llkl_h8; //helpful 8bit varialibe
    uint64_t llkl_a; //adress of register/flag/number of parametres


    llkl_c=llkl_get();

    switch(llkl_c){
        case 7:
            llkl_a=0;
            for(int i=0;i<4;i++)    //get register number
                llkl_a=(llkl_a<<8)+llkl_get();
            if(llkl_get()=='\''){   //if it's number
                LLKL_aloccate_mem(llkl_a,llkl_get(),0); // allocate next
            }

        break;

    }


///if no command executed
    exec_err.status = LLKL_NO_COMMAND; //command not found
    exec_err.additional = llkl_c; //which command wasn't found

    return exec_err; //command not found
}

llkl_err LLKL_aloccate_mem(uint64_t reg,uint64_t m,uint8_t type){
    llkl_err err;
    if(type==0){ //if this is integer
    if(reg<LLKL_RAM_SIZE){ //if this is in fast MeM
        reg=(uint8_t)m; //reg=int
    }
    }
    else{
    if(type==1){ //if this is regster
//////////todo
    }else{
    err.status=LLKL_UNKNOWN_TYPE;
    err.additional = type;
    return err;
    }
    }


    err.status=LLKL_OK;
    return err;
}

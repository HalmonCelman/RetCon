#include "LLKL.h"

llkl_err LLKL_exec(void){
    llkl_err exec_err; //error status

    uint8_t llkl_c; //command
    uint8_t llkl_n; //number of parameters

    LLKL_EXEC(llkl_c,llkl_get());   //get command - via additional stream of err stream

    LLKL_EXEC(llkl_n,llkl_get());    //get number of parametres

    for(uint8_t i=0;i<llkl_n;i++){ //get parameters
        LLKL_EXEC(LLKL_PARAM[i],llkl_get());
    }

///execute - commands
    if(llkl_c==LLKL_DISP_CHAR) return llkl_disp_char(llkl_c);

///if no command executed
    exec_err.status = LLKL_NO_COMMAND; //command not found
    exec_err.additional = llkl_c; //which command wasn't found

    return exec_err; //command not found
}

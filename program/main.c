/*
*************************************************
*         by KK        RetCon core              *
*************************************************
 */
#include "main.h"

#define DEBUG_MODE 1


int main(void)
{

//***************
    ///->start ekranu
    GLCD_Initalize();
    key_init();
GLCD_ClearScreen();
GLCD_B_ClearScreen(); //clear buffer

init_buffering();

///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting KoKOS...",0,0);
GLCD_r;

init_fs();

animate("a.txt");

LLKL_init();
err(llkl_init_program("uno.txt",FIL_MAIN),"Error occured!");

uint8_t res=0;
while(!res){
res=LLKL_exec().status;
}
if(res != LLKL_EOP){
    llkl_send_info("ERROR EXEC: ",res);
    err(res,"ERROR :");
}
llkl_send_info("process ended: ",0xFEDCBA98);
llkl_send_info("process 2 ended: ",0x12345678);

close_fs();


while(1){

}

    return 0;
}

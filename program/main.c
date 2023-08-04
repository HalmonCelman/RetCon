/*
*************************************************
*         by KK        RetCon core              *
*************************************************
 */
#include "main.h"
#include <config.h>


int main(void)
{

//***************
///->start ekranu
GLCD_Initalize();
key_init();
GLCD_ClearScreen();
GLCD_B_ClearScreen(); //clear buffer

init_buffering();

#if DEBUG_MODE
GLCD_B_ClearScreen();
#if LLL_DEBUG_MODE
GLCD_B_WriteString("DEBUG MODE WITH LLL",0,0);
#else
GLCD_B_WriteString("DEBUG MODE WITHOUT LLL",0,0);
#endif
GLCD_r;
delay(100);
#endif
///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting KoKOS...",0,0);
GLCD_r;
init_fs();

animate("a.am");

LLL_init();
LLL_run("add.l");
LLL_run("addi.l");
LLL_run("sub.l");
LLL_run("subi.l");
LLL_run("mul.l");
LLL_run("muli.l");
LLL_run("div.l");
LLL_run("divi.l");
LLL_run("and.l");
LLL_run("andi.l");
LLL_run("or.l");
LLL_run("ori.l");
LLL_run("not.l");
LLL_run("inc.l");
LLL_run("dec.l");
LLL_end();

close_fs();

while(1){

}
    return 0;
}

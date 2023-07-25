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
#if LLKL_DEBUG_MODE
GLCD_B_WriteString("DEBUG MODE WITH LLKL",0,0);
#else
GLCD_B_WriteString("DEBUG MODE WITHOUT LLKL",0,0);
#endif
GLCD_r;
delay(100);
#endif
///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting KoKOS...",0,0);
GLCD_r;
init_fs();

animate("a.anim");

LLKL_init();

LLKL_run("uno.llkl");

LLKL_end();

close_fs();

while(1){

}
    return 0;
}

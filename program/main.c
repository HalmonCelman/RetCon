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

LLL_run("snake/main.l");

LLL_end();

close_fs();

while(1){

}
    return 0;
}

/*
*************************************************
*         by KK        RetCon core              *
*************************************************
 */
#define F_CPU 16000000UL
#ifndef __AVR_ATmega1284P__
    #define __AVR_ATmega1284P__
#endif

/// __ekran WinCom WG12864D ze sterownikiem KS0108
#include <KS0108.h>
#include <multi_buff.h>
#include <additional_graphics.h>

/// LLL
#include <LLL.h>

//system
#include <base.h>
#include <input.h>
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

///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting KoKOS...",0,0);
GLCD_r;

init_fs();

LLL_init();

LLL_run("program.l");

LLL_end();

close_fs();

while(1){

}
    return 0;
}

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


#include <avr/io.h>
int main(void)
{
    key_init();
    //***************
    ///->start ekranu
    GLCD_Initalize();
    GLCD_ClearScreen();
    GLCD_B_ClearScreen(); //clear buffer

    init_buffering();

    ///->main program
    GLCD_B_ClearScreen();
    GLCD_B_WriteString("starting KoKOS...",0,0);
    GLCD_r;

    init_fs();

    LLL_init();

    //LLL_run("program.l");
    while(1){
        //lll_send_info("joystick1 x",joysticks[0]);
        delay(200);
        //lll_send_info("joystick1 y",joysticks[1]);
        // delay(1000);
        // lll_send_info("joystick2 x",joysticks[2]);
        // delay(1000);
        lll_send_info("joystick2 y",joysticks[3]);
        // delay(1000);
    }
    LLL_end();

    close_fs();

    while(1){

    }
    return 0;
}

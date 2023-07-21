#include <avr/io.h>
#include <avr/interrupt.h>
#include "base.h"
#include <multi_buff.h>
#include <KS0108.h>
#include <mmc_avr.h>
#include <LLKL_RetCon.h>

uint8_t pointMenu;
unsigned char counter;
volatile int timerDelay;
uint8_t res;
UINT s1;
FATFS fs1;




void init_buffering(void){
	///->multiplexing    ( includes also mmc_disktimerproc )                          ///<-przy zmianie mikrokontrolera lub czestotliwosci zwrócic uwage
    TCCR0A = (1<<WGM01); //CTC mode, 64 prescaler 1000Hz
    TCCR0B  = (1<<CS01)  | (1<<CS00);
    OCR0A =249;// div by 25
    TIMSK0 |=(1<<1);//enable compare match
    sei();//enable interrupts
}

void init_fs(void){
	/// 1.init disk
	res=1;
	while(res){
		res=err(disk_initialize(0),"Disk 404 ");
	}
	///end 1
	///2.mount
	errc(f_mount(&fs1, "", 0),"MountERR");

	errc(f_open(&file[FIL_LOG], "log.txt",FA_WRITE | FA_CREATE_ALWAYS),"F2E");
}

void close_fs(void){
	f_close(&file[FIL_MAIN]);
	f_close(&file[FIL_LOG]);
	f_unmount("");
	///end 2
}

ISR(TIMER0_COMPA_vect){
counter++;
if(timerDelay) timerDelay--; //accurate delay
if(counter>=10){ //for 16MHz -> 100Hz
    mmc_disk_timerproc(); //for FatFS
    counter=0;
    if(bufferSwitch){
        bufferSwitch=0;

        int i,j;
        for(j = 0; j < 8; j++){
            GLCD_GoTo(0,j);
            for(i = 0; i < 128; i++)
                GLCD_WriteData(GLCD_Buffer[j*128+i]);
        }
    }
}
}


uint8_t err(uint8_t r,char * com){
#if DEBUG_MODE==1
if(r){
GLCD_B_ClearScreen();
GLCD_B_WriteString(com,0,0);
GLCD_B_WriteChar((char)(r+48),0,1);
GLCD_r;
delay(1000);
}
#endif // DEBUG_MODE
return r;
}

uint8_t errc(uint8_t r,char * com){
if(r){
GLCD_B_ClearScreen();
GLCD_B_WriteString(com,0,0);
GLCD_B_WriteChar((char)(r+48),0,1);
GLCD_r;
while(1);
}
return r;
}


void play(void){
//TBD
}


void minilook(void){
//TBD
}

void load_games_menu(void){
GLCD_B_CinRect(0,22,63,42);
GLCD_B_WriteStringAcc("snake",10,27-((pointMenu==1 || pointMenu==2)?3:0));
GLCD_B_WriteStringAcc("slimon",10,43-((pointMenu==1)?3:0)-((pointMenu==2)?7:0));
GLCD_B_WriteStringAcc("saper",10,55-((pointMenu==2)?3:0));

for (int j = 0; j < 52; j++)	{
		GLCD_B_SetPixel(6 + j, 23+R);
		GLCD_B_SetPixel(6 + j, 37+R);
	}

	GLCD_B_SetPixel(6, 24+R); //kropki
	GLCD_B_SetPixel(57, 24+R);
	GLCD_B_SetPixel(6, 36+R);
	GLCD_B_SetPixel(57, 36+R);

	GLCD_B_Rect(2,25+R,60,11); //obwod

	//strzalki
	GLCD_B_SetPixel(0, 30+R); //lewa
	GLCD_B_SetPixel(1, 30+R);
	GLCD_B_SetPixel(3, 30+R);
	GLCD_B_SetPixel(4, 30+R);
	GLCD_B_SetPixel(5, 30+R);
	GLCD_B_SetPixel(6, 30+R);
	GLCD_B_SetPixel(5, 29+R);
	GLCD_B_SetPixel(5, 31+R);
	GLCD_B_SetPixel(4, 29+R);
	GLCD_B_SetPixel(4, 28+R);
	GLCD_B_SetPixel(4, 31+R);
	GLCD_B_SetPixel(4, 32+R);

    GLCD_B_SetPixel(63, 30+R); //prawa
	GLCD_B_SetPixel(62, 30+R);
	GLCD_B_SetPixel(60, 30+R);
	GLCD_B_SetPixel(59, 30+R);
	GLCD_B_SetPixel(58, 30+R);
	GLCD_B_SetPixel(57, 30+R);
	GLCD_B_SetPixel(58, 29+R);
	GLCD_B_SetPixel(58, 31+R);
	GLCD_B_SetPixel(59, 29+R);
	GLCD_B_SetPixel(59, 28+R);
	GLCD_B_SetPixel(59, 31+R);
	GLCD_B_SetPixel(59, 32+R);

minilook();

}

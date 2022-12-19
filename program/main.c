/*
*************************************************
*         by KK        ©                        *
*************************************************
 */

#define F_CPU 16000000UL
#ifndef __AVR_ATmega1284P__
#define __AVR_ATmega1284P__
#endif
///__biblioteki standardowe
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>

///__ekran WinCom WG12864D ze sterownikiem KS0108
#include "KS0108_lib/KS0108.h"
#include "KS0108_lib/graphic.h"
#include "KS0108_lib/font5x8.h"
#include "KS0108_lib/multi_buff.h"

///FAT FS
#include "FatFs_lib/diskio.h"
#include "FatFs_lib/ff.h"
#include "FatFs_lib/ffconf.h"
#include "FatFs_lib/mmc_avr.h"
#include "FatFs_lib/rtc.h"

///LLKL
#include "LLKL/LLKL.h"

///__makra
#define PREP_TRICK_DDR(x,y) x##y
#define DDR(x) PREP_TRICK_DDR(DDR,x)

#define PREP_TRICK_PORT(x,y) x##y
#define PORT(x) PREP_TRICK_PORT(PORT,x)

#define PREP_TRICK_PIN(x,y) x##y
#define PIN(x) PREP_TRICK_PIN(PIN,x)
#define J(x,y) x##y
#define QUOTE(x) "x"

#define delay(x) Timer_delay=x;while(Timer_delay);

///very useful macros^


///////////////////////////////////////////////////////////////////konfiguracja
#define DEBUG_MODE 1


#define R 13*point_menu

///__przyciski
#define K_U_PIN 0  //up
#define K_U_PORT D

#define K_D_PIN 1  //down
#define K_D_PORT D

#define K_R_PIN 2  //right
#define K_R_PORT D

#define K_L_PIN 3  //left
#define K_L_PORT D

#define K_J_PIN 4  //jump
#define K_J_PORT D

#define K_P_PIN 5  //punch
#define K_P_PORT D


///__funkcje_deklaracje
    uint8_t err(uint8_t,char *); // normal error if error occure than it displays it on screen for 1000 ms and returns error code
    uint8_t errc(uint8_t,char *); //critic error, if error occure then program will no longer work( function causes infinite loop ),if no error returns 0
    void key_init(void); //initialize keys
    void GLCD_B_Bitmap_SD_exp(char*); //shows exported bitmap from path
    void GLCD_Animate_exp(char*); //shows exported animation from file
    void GLCD_B_Bitmap_SD(char*); //shows unexported bitmap(from .wbmp file)
    void load_games_menu(void);
    void play(void);
    void minilook(void);

///__zmienne globalne

    unsigned char licznik=0;
    

    uint8_t point_menu;
    volatile int Timer_delay;

///__struktury
struct animacja{
char *name; //nazwa
int frame; //nr aktualnej klatki
uint8_t x; //x
uint8_t y; //y
uint8_t w; //szerokosc
uint8_t h; //wysokosc
uint8_t active; //czy aktywna aktualnie
};

///__animacje
struct animacja a;

//pobieranie czasu

DWORD get_fattime (void)
{
	RTC rtc;

	rtc.year=2022;
	rtc.month=1;
	rtc.mday=1;
	rtc.hour=1;
	rtc.min=1;
	rtc.sec=1;

	/* Pack date and time into a DWORD variable */
	return	  ((DWORD)(rtc.year - 1980) << 25)
			| ((DWORD)rtc.month << 21)
			| ((DWORD)rtc.mday << 16)
			| ((DWORD)rtc.hour << 11)
			| ((DWORD)rtc.min << 5)
			| ((DWORD)rtc.sec >> 1);
}



int main(void)
{
//debuging
DDRA|=2;

//***************
    point_menu=0;
    xxx_zmiana=0;
    ///->start ekranu
    GLCD_Initalize();
    key_init();
GLCD_ClearScreen();
GLCD_B_ClearScreen(); //clear buffer
///->multiplexing    ( includes also mmc_disktimerproc )                          ///<-przy zmianie mikrokontrolera lub czestotliwosci zwrócic uwage
    TCCR0A = (1<<WGM01); //CTC mode, 64 prescaler 1000Hz
    TCCR0B  = (1<<CS01)  | (1<<CS00);
    OCR0A =249;// div by 25
    TIMSK0 |=(1<<1);//enable compare match
    sei();//enable interrupts
/*
PORTA|=2;
delay(100);
PORTA&=~2;
delay(100);
*/

///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting KoKOS...",0,0);
GLCD_r;

DDRB|=(1<<PB2);
PORTB&=~(1<<PB2);


/// 1.init disk
res=1;
while(res){
res=err(disk_initialize(0),"Disk 404 ");
}
///end 1
///2.mount
errc(f_mount(&fs1, "", 0),"MountERR");

errc(f_open(&file[FIL_LOG], "log.txt",FA_WRITE | FA_CREATE_ALWAYS),"F2E");
GLCD_B_ClearScreen();

a.name="a.txt";
a.frame=0;
a.active=0;
a.x=0;
a.y=0;
a.w=128;
a.h=64;

errc(f_open(&file[FIL_D], "a.txt", FA_READ),"FE");

a.active=1; //run animation

while(a.active){
GLCD_r;

res=err(f_lseek(&file[FIL_D],(DWORD)1024*a.frame),"LseekERR");
res?res:err(f_read(&file[FIL_D],&GLCD_Buffer[0],1024,&s1),"ReadERR");

a.frame++;
if(a.frame>=83 || res){ //end animation if this is end or error occured
    a.active=0;
}


}
/*LLKL_init();
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
llkl_send_info("process 2 ended: ",0x12345678);*/
f_close(&file[FIL_MAIN]);
f_close(&file[FIL_LOG]);
f_unmount("");
///end 2


while(1){

}

    return 0;
}


///__przerwania

ISR(TIMER0_COMPA_vect){
licznik++;
if(Timer_delay) Timer_delay--; //accurate delay
if(licznik>=10){ //for 16MHz -> 100Hz


mmc_disk_timerproc(); //for FatFS


        licznik=0;
        if(xxx_zmiana){
xxx_zmiana=0;

    int i,j;
    for(j = 0; j < 8; j++)
  {
  GLCD_GoTo(0,j);
  for(i = 0; i < 128; i++)
    GLCD_WriteData(GLCD_Buffer[j*128+i]);
  }

}
}

}




///__funkcje

void GLCD_B_Bitmap_SD(char* name){
    char g[16];
    res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
f_read(&file[FIL_D],g, 5 , &s1);



int i=0;
int j=0;

i=0;
int f=0;
while(i<64){
    f=0;
    res= f_read(&file[FIL_D],g, 16 , &s1);
    while(f<16){
    j=0;
        while(j<8){
        if(~g[f] & (128>>j)){
            GLCD_B_SetPixel(8*f+j,i);
        }
    j++;
        }
    f++;
    }
    i++;

}


f_close(&file[FIL_D]);

}else{
delay(1000);
    GLCD_B_ClearScreen();
GLCD_B_WriteString("Error - opf",0,0);
GLCD_r;
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



void GLCD_Animate_exp(char* name){
res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
int x=0;
while(!x){
    f_read(&file[FIL_D],GLCD_Buffer,1024,&s1);
    if(s1!=1024){
        x=1;
    }

if(x){
    GLCD_B_ClearScreen();
}else{
GLCD_r;
}
delay(33);
}
f_close(&file[FIL_D]);
}
}

void GLCD_B_Bitmap_SD_exp(char* name){
    res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
    f_read(&file[FIL_D],GLCD_Buffer,1024,&s1);
f_close(&file[FIL_D]);
}

}

void play(void){
}

void key_init(void){
DDRB|=(1<<4);
}



void minilook(void){
}

void load_games_menu(void){
GLCD_B_CinRect(0,22,63,42);
GLCD_B_WriteStringAcc("snake",10,27-((point_menu==1 || point_menu==2)?3:0));
GLCD_B_WriteStringAcc("slimon",10,43-((point_menu==1)?3:0)-((point_menu==2)?7:0));
GLCD_B_WriteStringAcc("saper",10,55-((point_menu==2)?3:0));

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


/*
*************************************************
*         by KK        ©                        *
*  ten program nie ma byc uniwersalny           *
* jest pisany na prosbe i liczy sie tylko efekt *
* program pisany na atmega32                    *
*************************************************
 */
///__biblioteki standardowe
#include <avr/io.h>
#include <stdio.h>
#include <avr/interrupt.h>
#include <util/delay.h>

///__ekran WinCom WG12864D ze sterownikiem KS0108
#include "KS0108_lib/KS0108.h"
#include "KS0108_lib/graphic.h"
#include "KS0108_lib/font5x8.h"
#include "KS0108_lib/multi_buff.h"

///Petit FAT FS
#include "Petit_FS_lib/diskio.h"
#include "Petit_FS_lib/integer.h"
#include "Petit_FS_lib/pff.h"




///__makra
#define CSCARDOFF PORTB|=(1<<CSCARDPIN)
#define CSCARDON PORTB&=~(1<<CSCARDPIN)
#define CSCARDPIN 2
#define CSCARDDDR DDRB

///__funkcje_deklaracje
    void GLCD_B_Bitmap_SD(char* name);
    void load_games_menu(void);

///__tablice
    const char file_name[]="l.wbmp";

///__zmienne globalne

    volatile unsigned char licznik=0;
    FATFS fs;
    WORD s1;
    BYTE res;


int main(void)
{

    xxx_zmiana=0;
    ///->start ekranu
    GLCD_Initalize();
GLCD_ClearScreen();
GLCD_B_ClearScreen(); //clear buffer
///->multiplexing                                                                                   ///<-przy zmianie mikrokontrolera lub czêstotliwoœci zwróciæ uwagê
    TCCR0 |= (1<<WGM01) | (1<<CS02) | (1<<CS00); //CTC mode 1024 prescaler
    OCR0 =19;// div by 20
    TIMSK |=(1<<1);//enable compare match
    sei();//enable interrupts

///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting system...",0,0);
GLCD_r;
DDRB|=(1<<PB2);
PORTB&=~(1<<PB2);

///init disk
uint8_t i=255;
while(i-- && (res=disk_initialize()));
if(res== FR_OK){

res=pf_mount(&fs);
if(res== FR_OK){




GLCD_B_ClearScreen();
GLCD_B_Bitmap_SD("l.txt");
GLCD_r;
_delay_ms(1000);
GLCD_B_ClearScreen();
GLCD_B_Bitmap_SD("menu.txt");
load_games_menu();
GLCD_r;



///interpreter
GLCD_B_ClearScreen();

LLKL("program.txt");

GLCD_r;


pf_mount(0); //wymontuj nosnik jesli wszystko skonczone


}else{
_delay_ms(1000);
    GLCD_B_ClearScreen();
GLCD_B_WriteString("Error - mount",0,0);
GLCD_r;
}

}else{
_delay_ms(1000);
    GLCD_B_ClearScreen();
GLCD_B_WriteString("Error - disk 404",0,0);
GLCD_r;
}


while(1){

}

    return 0;
}


///__przerwania

ISR(TIMER0_COMP_vect){

if(licznik>=13){
        licznik=0;
        if(xxx_zmiana){


    int i,j;
    for(j = 0; j < 8; j++)
  {
  GLCD_GoTo(0,j);
  for(i = 0; i < 128; i++)
    GLCD_WriteData(GLCD_Buffer[j][i]);
  }
xxx_zmiana=0;
}

 }
licznik++;
}


///__funkcje

void GLCD_B_Bitmap_SD(char* name){
    char g[16];
    res=pf_open(name);
if(res== FR_OK){
pf_read(g, 5 , &s1);



int i=0;
int j=0;

i=0;
int f=0;
while(i<64){
    f=0;
    res= pf_read(g, 16 , &s1);
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


write_close();

}else{
_delay_ms(1000);
    GLCD_B_ClearScreen();
GLCD_B_WriteString("Error - opf",0,0);
GLCD_r;
}

}




void load_games_menu(void){
GLCD_B_WriteString("slimon",10,24);
GLCD_B_WriteString("saper",10,40);
GLCD_B_WriteString("snake",10,56);
}


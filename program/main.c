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
#define PREP_TRICK_DDR(x,y) x##y
#define DDR(x) PREP_TRICK_DDR(DDR,x)

#define PREP_TRICK_PORT(x,y) x##y
#define PORT(x) PREP_TRICK_PORT(PORT,x)

#define PREP_TRICK_PIN(x,y) x##y
#define PIN(x) PREP_TRICK_PIN(PIN,x)
#define J(x,y) x##y
#define QUOTE(x) "x"
///very useful macros^


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
    void key_init(void);
    void GLCD_B_Bitmap_SD_exp(char*);
    void GLCD_Animate_exp(char*);
    void GLCD_B_Bitmap_SD(char*);
    void load_games_menu(void);
    void play(void);
    void minilook(void);

///__zmienne globalne

    unsigned char licznik=0;
    FATFS fs;
    WORD s1;
    BYTE res;

    uint8_t point_menu;


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




int main(void)
{
    point_menu=0;
    xxx_zmiana=0;
    ///->start ekranu
    GLCD_Initalize();
    key_init();
GLCD_ClearScreen();
GLCD_B_ClearScreen(); //clear buffer
///->multiplexing                                                                                   ///<-przy zmianie mikrokontrolera lub czêstotliwoœci zwróciæ uwagê
    TCCR0A = (1<<WGM01); //CTC mode 1024 prescaler
    TCCR0B  = (1<<CS02) | (1<<CS00);
    OCR0A =19;// div by 20
    TIMSK0 |=(1<<1);//enable compare match
    sei();//enable interrupts

///->main program
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting system.",0,0);
GLCD_r;
/* <- deleted for faster designing, add if needed later
_delay_ms(1000);
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting system..",0,0);
GLCD_r;
_delay_ms(1000);
GLCD_B_ClearScreen();
GLCD_B_WriteString("starting system...",0,0);
GLCD_r;
_delay_ms(1000);
*/
DDRB|=(1<<PB2);
PORTB&=~(1<<PB2);


///init disk
uint8_t i=255;
while(i-- && (res=disk_initialize()));
if(res== FR_OK){

res=pf_mount(&fs);
if(res== FR_OK){


GLCD_B_ClearScreen();
//GLCD_Animate_exp("ae.txt");

a.name="a.txt";
a.frame=0;
a.active=0;
a.x=0;
a.y=0;
a.w=128;
a.h=64;






if(res==FR_OK){
a.active=1;
}else{
    GLCD_B_ClearScreen();
GLCD_B_WriteString("FE",0,0);
GLCD_r;
}
res=pf_open(a.name);

while(a.active){


GLCD_r;
pf_lseek((DWORD)1024*a.frame);

pf_read(GLCD_Buffer,1024,&s1);
if(res==FR_OK){

}else{
    GLCD_B_ClearScreen();
GLCD_B_WriteString("RE",0,0);
GLCD_r;
_delay_ms(1000);
}

a.frame++;
if(a.frame>=83){
    a.active=0;
}




}

write_close();

//miejsce na gry

//GLCD_B_ClearScreen();
//GLCD_B_Bitmap_SD("menu.txt");
//load_games_menu();
//GLCD_r;

//play();




//pf_mount(0); //wymontuj nosnik jesli wszystko skonczone


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

ISR(TIMER0_COMPA_vect){
licznik++;
if(licznik>=20){ //for 12MHz
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

void GLCD_Animate_exp(char* name){
res=pf_open(name);
if(res== FR_OK){
int x=0;
while(!x){
    pf_read(GLCD_Buffer,1024,&s1);
    if(s1!=1024){
        x=1;
    }

if(x){
    GLCD_B_ClearScreen();
}else{
GLCD_r;
}
_delay_ms(33);
}
write_close();
}
}

void GLCD_B_Bitmap_SD_exp(char* name){
    res=pf_open(name);
if(res== FR_OK){
    pf_read(GLCD_Buffer,1024,&s1);
write_close();
}

}

void play(void){
}

void key_init(void){

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


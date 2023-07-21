#include <avr/io.h>
#include <avr/pgmspace.h>
#include "font5x8.h"
#include "multi_buff.h"


//gcc 12
unsigned char GLCD_Buffer[GLCD_Buffer_size];
volatile unsigned char bufferSwitch;


void GLCD_B_SetPixel(unsigned char x, unsigned char y)
{
unsigned char tmp;
tmp = GLCD_Buffer[(y/8)*128+x];
tmp |= (1 << (y % 8));
GLCD_Buffer[(y/8)*128+x]=tmp;

}


void GLCD_B_ClrPixel(unsigned char x, unsigned char y)
{
unsigned char tmp;
tmp = GLCD_Buffer[(y/8)*128+x];
tmp &=~ (1 << (y % 8));
GLCD_Buffer[(y/8)*128+x]=tmp;

}

void GLCD_B_WriteChar(char charToWrite,unsigned char x, unsigned char y)
{
uint8_t i;
int wsp;
charToWrite -= 32;
for(i = 0; i < 5; i++){
    wsp=y*128+x+i;
  GLCD_Buffer[wsp]=pgm_read_byte((char *)((int)font5x8 + (5 * charToWrite) + i));
}
 wsp=y*128+x+5;
GLCD_Buffer[wsp]=0;
}


void GLCD_B_WriteCharAcc(char charToWrite,unsigned char x, unsigned char y)
{

        int i;
charToWrite -= 32;
for(i = 0; i < 5; i++){
        GLCD_Buffer[(y/8)*128+x+i]|=(pgm_read_byte((char *)((int)font5x8 + (5 * charToWrite) + i))<<(y%8));
        GLCD_Buffer[((y/8)+1)*128+x+i]|=(pgm_read_byte((char *)((int)font5x8 + (5 * charToWrite) + i))>>(8-(y%8)));
}
}


void GLCD_B_ClearScreen(void)
{
int j;
for(j = 0; j < 1024; j++)
  {
    GLCD_Buffer[j]=0;
}
}

void GLCD_B_WriteString(char * stringToWrite,unsigned char x,unsigned char y)
{
while(*stringToWrite){
  GLCD_B_WriteChar(*stringToWrite++,x,y);
x+=6;
}
}

void GLCD_B_WriteStringAcc(char * stringToWrite,unsigned char x,unsigned char y)
{
while(*stringToWrite){
  GLCD_B_WriteCharAcc(*stringToWrite++,x,y);
x+=6;
}
}


void GLCD_B_Rect(uint8_t x,uint8_t y,uint8_t b,uint8_t a){
 unsigned char j; // zmienna pomocnicza
  // rysowanie linii pionowych (boki)
  for (j = 0; j < a; j++) {
		GLCD_B_SetPixel(x, y + j);
		GLCD_B_SetPixel(x + b - 1, y + j);
	}
  // rysowanie linii poziomych (podstawy)
  for (j = 0; j < b; j++)	{
		GLCD_B_SetPixel(x + j, y);
		GLCD_B_SetPixel(x + j, y + a - 1);
	}
}


void GLCD_B_CinRect(uint8_t x,uint8_t y,uint8_t b,uint8_t a){
 unsigned char i,j;
  for (j = 0; j < a; j++) {
		for (i = 0; i < b; i++)	{
		GLCD_B_ClrPixel(x + i, y+j);
	}
	}

}


void GLCD_B_Circle(unsigned char cx, unsigned char cy ,unsigned char radius)
{
int x, y, xchange, ychange, radiusError;
x = radius;
y = 0;
xchange = 1 - 2 * radius;
ychange = 1;
radiusError = 0;
while(x >= y)
  {
  GLCD_B_SetPixel(cx+x, cy+y);
  GLCD_B_SetPixel(cx-x, cy+y);
  GLCD_B_SetPixel(cx-x, cy-y);
  GLCD_B_SetPixel(cx+x, cy-y);
  GLCD_B_SetPixel(cx+y, cy+x);
  GLCD_B_SetPixel(cx-y, cy+x);
  GLCD_B_SetPixel(cx-y, cy-x);
  GLCD_B_SetPixel(cx+y, cy-x);
  y++;
  radiusError += ychange;
  ychange += 2;
  if ( 2*radiusError + xchange > 0 )
    {
    x--;
	radiusError += xchange;
	xchange += 2;
	}
  }
}


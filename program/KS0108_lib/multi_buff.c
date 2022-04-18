#include <avr/io.h>
#include <avr/pgmspace.h>
#include "font5x8.h"
#include "multi_buff.h"
void GLCD_B_SetPixel(unsigned char x, unsigned char y)
{
unsigned char tmp;
tmp = GLCD_Buffer[y/8][x];
tmp |= (1 << (y % 8));
GLCD_Buffer[y/8][x]=tmp;

}


void GLCD_B_WriteChar(char charToWrite,unsigned char x, unsigned char y)
{
int i;
charToWrite -= 32;
for(i = 0; i < 5; i++)
  GLCD_Buffer[y/8][x+i]=pgm_read_byte((char *)((int)font5x8 + (5 * charToWrite) + i));
GLCD_Buffer[y/8][x+5]=0;
}


void GLCD_B_ClearScreen(void)
{
unsigned char i, j;
for(j = 0; j < 8; j++)
  {
  for(i = 0; i < 128; i++)
    GLCD_Buffer[j][i]=0;
  }
}

void GLCD_B_WriteString(char * stringToWrite,unsigned char x,unsigned char y)
{
while(*stringToWrite){
  GLCD_B_WriteChar(*stringToWrite++,x,y);
x+=6;
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


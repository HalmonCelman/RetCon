#ifndef MULTI_BUFF_H_INCLUDED
#define MULTI_BUFF_H_INCLUDED



volatile unsigned char GLCD_Buffer[8][128];
volatile unsigned char xxx_zmiana;

void GLCD_B_SetPixel(unsigned char x, unsigned char y);
void GLCD_B_WriteChar(char charToWrite,unsigned char x,unsigned char y);
void GLCD_B_ClearScreen(void);
void GLCD_B_WriteString(char *,unsigned char x,unsigned char y);
void GLCD_B_Circle(unsigned char cx, unsigned char cy ,unsigned char radius);


#define GLCD_r xxx_zmiana=1;
#endif // MULTI_BUFF_H_INCLUDED

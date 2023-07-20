#ifndef MULTI_BUFF_H_INCLUDED
#define MULTI_BUFF_H_INCLUDED

#define GLCD_Buffer_size 1024
extern unsigned char GLCD_Buffer[GLCD_Buffer_size];
extern volatile unsigned char xxx_zmiana;

void GLCD_B_SetPixel(unsigned char, unsigned char);
void GLCD_B_ClrPixel(unsigned char, unsigned char);
void GLCD_B_WriteChar(char,unsigned char,unsigned char);
void GLCD_B_WriteCharAcc(char,unsigned char,unsigned char); //slower but you can in any pixel
void GLCD_B_ClearScreen(void);
void GLCD_B_WriteString(char*,unsigned char,unsigned char);
void GLCD_B_WriteStringAcc(char*,unsigned char,unsigned char);
void GLCD_B_Circle(unsigned char, unsigned char,unsigned char);
void GLCD_B_Rect(uint8_t, uint8_t, uint8_t, uint8_t);
void GLCD_B_CinRect(uint8_t, uint8_t, uint8_t, uint8_t);

#define GLCD_r xxx_zmiana=1;while(xxx_zmiana)
#endif // MULTI_BUFF_H_INCLUDED

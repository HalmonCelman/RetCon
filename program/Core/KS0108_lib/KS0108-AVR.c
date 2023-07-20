//-------------------------------------------------------------------------------------------------
// Universal KS0108 driver library
// Atmel AVR MCU low-level driver.
// (c) Rados�aw Kwiecie�, radek@dxp.pl
//-------------------------------------------------------------------------------------------------
#include <avr/io.h>
#include <avr/pgmspace.h>
#include "KS0108.h"

#ifndef asm
#define asm __asm__
#endif
extern unsigned char screen_x;
extern unsigned char screen_y;

#define DISPLAY_STATUS_BUSY	0x80

//-------------------------------------------------------------------------------------------------
// Delay function
//-------------------------------------------------------------------------------------------------
void GLCD_Delay(void)
{
asm("nop");
asm("nop");
}
//-------------------------------------------------------------------------------------------------
// Enalbe Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_EnableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_PORT &= ~KS0108_CS1; break;
	case 1 : KS0108_CTRL_PORT &= ~KS0108_CS2; break;
	case 2 : KS0108_CTRL_PORT &= ~KS0108_CS3; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Disable Controller (0-2)
//-------------------------------------------------------------------------------------------------
void GLCD_DisableController(unsigned char controller)
{
switch(controller){
	case 0 : KS0108_CTRL_PORT |= KS0108_CS1; break;
	case 1 : KS0108_CTRL_PORT |= KS0108_CS2; break;
	case 2 : KS0108_CTRL_PORT |= KS0108_CS3; break;
	}
}
//-------------------------------------------------------------------------------------------------
// Read Status from specified controller (0-2)
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadStatus(unsigned char controller)
{
unsigned char status;
KS0108_DATA_DIR = 0x00;
KS0108_CTRL_PORT |= KS0108_RW;
KS0108_CTRL_PORT &= ~KS0108_RS;
GLCD_EnableController(controller);
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
status = KS0108_DATA_PIN;
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(controller);
return status;
}
//-------------------------------------------------------------------------------------------------
// Write command to specified controller
//-------------------------------------------------------------------------------------------------
void GLCD_WriteCommand(unsigned char commandToWrite, unsigned char controller)
{
while(GLCD_ReadStatus(controller)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0xFF;
KS0108_CTRL_PORT &= ~(KS0108_RW | KS0108_RS);
GLCD_EnableController(controller);
GLCD_Delay();
KS0108_DATA_PORT = commandToWrite;
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_PORT &= ~KS0108_EN;
asm("nop");
GLCD_DisableController(controller);
asm("nop");
asm("nop");
asm("nop");
}
//-------------------------------------------------------------------------------------------------
// Read data from current position
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadData(void)
{
unsigned char data;
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0x00;
KS0108_CTRL_PORT |= (KS0108_RW | KS0108_RS);
GLCD_EnableController(screen_x / 64);
//GLCD_Delay();
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
data = KS0108_DATA_PIN;
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
return data;
}
//-------------------------------------------------------------------------------------------------
// Write data to current position
//-------------------------------------------------------------------------------------------------
void GLCD_WriteData(unsigned char dataToWrite)
{
while(GLCD_ReadStatus(screen_x / 64)&DISPLAY_STATUS_BUSY);
KS0108_DATA_DIR = 0xFF;
KS0108_CTRL_PORT &= ~KS0108_RW;
KS0108_CTRL_PORT |= KS0108_RS;
KS0108_DATA_PORT = dataToWrite;
GLCD_EnableController(screen_x / 64);
KS0108_CTRL_PORT |= KS0108_EN;
GLCD_Delay();
KS0108_CTRL_PORT &= ~KS0108_EN;
GLCD_DisableController(screen_x / 64);
screen_x++;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
void GLCD_InitalizePorts(void)
{
KS0108_CTRL_DIR |= (KS0108_CS1 | KS0108_CS2 | KS0108_CS3 | KS0108_RS | KS0108_RW | KS0108_EN);
KS0108_CTRL_PORT =0x00;
KS0108_CTRL_PORT |= (KS0108_CS1 | KS0108_CS2 | KS0108_CS3);
KS0108_DATA_DIR = 0xFF;
KS0108_DATA_PORT = 0x00;
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------
unsigned char GLCD_ReadByteFromROMMemory(char * ptr)
{
return pgm_read_byte(ptr);
}
//-------------------------------------------------------------------------------------------------
//
//-------------------------------------------------------------------------------------------------

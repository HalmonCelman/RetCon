

#define KS0108_SCREEN_WIDTH		128
#define KS0108_SCREEN_HEIGHT	64


#define KS0108_DATA_PORT	PORTC
#define KS0108_DATA_DIR		DDRC
#define KS0108_DATA_PIN		PINC

#define KS0108_CTRL_PORT	PORTD
#define KS0108_CTRL_DIR		DDRD

#define KS0108_RS			(1 << 5)
#define KS0108_RW			(1 << 6)
#define KS0108_EN			(1 << 7)

#define KS0108_CS1			(1 << 4) //there is some bug that means in program CS1 is used as CS2 and CS2 as CS1
#define KS0108_CS2			(1 << 3)
#define KS0108_CS3			(1 << 4)









#define DISPLAY_SET_Y       0x40
#define DISPLAY_SET_X       0xB8
#define DISPLAY_START_LINE  0xC0
#define DISPLAY_ON_CMD		0x3E
  #define ON	0x01
  #define OFF	0x00
#define DISPLAY_STATUS_BUSY	0x80

void GLCD_Initalize(void);
void GLCD_WriteData(unsigned char);
void GLCD_WriteCommand(unsigned char, unsigned char);
void GLCD_SetPixel(unsigned char x, unsigned char y);
void GLCD_ClearScreen(void);
void GLCD_GoTo(unsigned char, unsigned char);
void GLCD_WriteString(char *);
unsigned char GLCD_ReadByteFromROMMemory(char *);
unsigned char GLCD_ReadData(void);
void GLCD_Bitmap(char *, unsigned char, unsigned char, unsigned char, unsigned char);

void GLCD_Delay();


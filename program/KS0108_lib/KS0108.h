

#define KS0108_SCREEN_WIDTH		128
#define KS0108_SCREEN_HEIGHT	64


#define KS0108_DATA_PORT	PORTA
#define KS0108_DATA_DIR		DDRA
#define KS0108_DATA_PIN		PINA

#define KS0108_CTRL_PORT	PORTC
#define KS0108_CTRL_DIR		DDRC

#define KS0108_RS			(1 << 2)
#define KS0108_RW			(1 << 1)
#define KS0108_EN			(1 << 0)

#define KS0108_CS1			(1 << 6)
#define KS0108_CS2			(1 << 5)
#define KS0108_CS3			(1 << 5)









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


#include "llkl_atmega1284p.h"
#include "../KS0108_lib/multi_buff.h"


uint8_t llkl_get(void){
return 0;
}

uint8_t llkl_disp_char(uint8_t n){
return 0;
}

void llkl_send_info(char* info,uint32_t value){
UINT s1;

GLCD_B_ClearScreen();
GLCD_B_WriteString(info,0,0);
int len=0;
while(*info){
len++;
info++;
}
info-=len;
errc(f_write(&file2,info,len,&s1),"INFOERR");

uint8_t val2, val21, val22,hex;

for(int i=0;i<4;i++){
val2 = (value>>(32-8-i*8));
val21= (val2>>4);
val22 = val2<<4;
val22=val22>>4;

if(val21>=10){
hex=val21+'a'-10;
} else{
hex=val21+48;
}
GLCD_B_WriteChar(hex,i*14,1);
errc(f_write(&file2,&hex,1,&s1),"val21CE");

if(val22>=10){
hex=val22+'a'-10;
} else{
hex=val22+48;
}
GLCD_B_WriteChar(hex,6+i*14,1);
errc(f_write(&file2,&hex,1,&s1),"var22CE");
}
GLCD_r;
errc(f_write(&file2,"\n",1,&s1),"nCE");


}

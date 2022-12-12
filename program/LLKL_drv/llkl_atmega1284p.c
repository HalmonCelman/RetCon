#include "llkl_atmega1284p.h"
#include "../KS0108_lib/multi_buff.h"

uint8_t llkl_init_program(char* source,uint8_t num){ //todo - from which place it's starting <-
return f_open(&file[num],source,FA_READ); //open file in selected file

for(int i=0;i<NUMOFFILES;i++){
    file_pt[i].buffpt=0; //clear buffor page pointer
    file_pt[i].compt=0; //clear command pointer
    file_pt[i].dpt=0; // clear dynamic pointer
    }
llkl_actual_file=num;
llkl_physical_read=1;
}

uint8_t llkl_end_program(uint8_t num){
return f_close(&file[num]); //close selected file
}

uint8_t llkl_get(void){

if(file_pt[llkl_actual_file].dpt >= LLKL_COMM_BUFF_SIZE)
    llkl_physical_read = 1;


if(llkl_physical_read){ //reload command buffer and set pointers - shild be read from last command to avoid chain broke but will be implemented later
llkl_physical_read = 0;
f_read(&file[llkl_actual_file],LLKL_COMM_BUFF,LLKL_COMM_BUFF_SIZE,&s1);
if(s1<LLKL_COMM_BUFF_SIZE){
LLKL_COMM_BUFF[s1]=0xFF;
}
file_pt[llkl_actual_file].buffpt++;
file_pt[llkl_actual_file].dpt = 0;
file_pt[llkl_actual_file].compt = 0;

}

return LLKL_COMM_BUFF[file_pt[llkl_actual_file].dpt++];
}

uint8_t llkl_disp_char(uint8_t n){
//todo
return 0;
}

void llkl_send_info(char* info,uint32_t value){

GLCD_B_ClearScreen();
GLCD_B_WriteString(info,0,0);
int len=0;
while(*info){
len++;
info++;
}
info-=len;
errc(f_write(&file[FIL_LOG],info,len,&s1),"INFOERR");

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
errc(f_write(&file[FIL_LOG],&hex,1,&s1),"val21CE");

if(val22>=10){
hex=val22+'a'-10;
} else{
hex=val22+48;
}
GLCD_B_WriteChar(hex,6+i*14,1);
errc(f_write(&file[FIL_LOG],&hex,1,&s1),"var22CE");
}
GLCD_r;
errc(f_write(&file[FIL_LOG],"\n",1,&s1),"nCE");


}

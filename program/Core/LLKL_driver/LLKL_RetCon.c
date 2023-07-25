#include "LLKL_RetCon.h"
#include <config.h>
#include <multi_buff.h>

FIL file[NUMOFFILES];
llkl_pt file_pt[NUMOFFILES];


volatile uint8_t llkl_physical_read; //says if it's needed to reload buffer - caused end of buffer
volatile uint8_t llkl_reload_buffer; //says if it's needed to reload buffer - caused change of file
volatile uint8_t llkl_actual_file; //says which file is already used



uint8_t llkl_init_program(char* source,uint8_t num,uint32_t position){
#if LLKL_DEBUG_MODE==1
    llkl_send_info("INFO: opening file ",num);
#endif
uint8_t llkl_pom=f_open(&file[num],source,FA_READ); //open file in selected file
if(llkl_pom) return llkl_pom;
llkl_pom=f_lseek(&file[num],position);
for(int i=0;i<NUMOFFILES;i++){
    file_pt[i].buffCounter=0; //clear buffor page pointer
    file_pt[i].command=0; //clear command pointer
    file_pt[i].dCounter=0; // clear dynamic pointer
    }
#if LLKL_DEBUG_MODE==1
    llkl_send_info("INFO: opened succesfully ",0);
#endif
llkl_actual_file=num; //actual file change
llkl_reload_buffer=1; //reload data
return 0;
}

uint8_t llkl_init_main_program(char* source,uint32_t position){
    return llkl_init_program(source,FIL_MAIN,position);
}


uint8_t llkl_end_program(uint8_t num){
#if LLKL_DEBUG_MODE==1
    llkl_send_info("closing program in: ",num);
#endif
return f_close(&file[num]); //close selected file
}

uint8_t llkl_end_main_program(void){
    return llkl_end_program(FIL_MAIN);
}

uint8_t llkl_get(void){

if(file_pt[llkl_actual_file].dCounter >= LLKL_COMM_BUFF_SIZE)
    llkl_physical_read = 1;


if(llkl_physical_read | llkl_reload_buffer){ //reload command buffer and set pointers - should be read from last command to avoid chain broke but will be implemented later 

#if LLKL_DEBUG_MODE==1
    llkl_send_info("INFO: reloading buffer ",(llkl_physical_read<<1)|llkl_reload_buffer);
#endif

f_read(&file[llkl_actual_file],LLKL_COMM_BUFF,LLKL_COMM_BUFF_SIZE,&s1);
if(s1<LLKL_COMM_BUFF_SIZE){
LLKL_COMM_BUFF[s1]=0xFF; //reached EOF
}
if(llkl_physical_read){
llkl_physical_read = 0;
file_pt[llkl_actual_file].buffCounter++; //next page
}
if(llkl_reload_buffer){
llkl_reload_buffer = 0;
}
file_pt[llkl_actual_file].dCounter = 0;
file_pt[llkl_actual_file].command = 0;

}

uint8_t llkl_pom= LLKL_COMM_BUFF[file_pt[llkl_actual_file].dCounter++];

#if LLKL_DEBUG_MODE==1
    llkl_send_info("INFO: llkl_get() ",llkl_pom);
#endif

return llkl_pom;
}

uint8_t llkl_disp_char(uint8_t n){
#if LLKL_DEBUG_MODE==1
    llkl_send_info("INFO: not yet done ",0);
#endif
//todo
return 0;
}

/*
llkl_send_info: sends info to the user
info - information which you want to send
value - additional number which will show after info
*/
void llkl_send_info(char* info,uint32_t value){

GLCD_B_ClearScreen();
GLCD_B_WriteString(info,0,0);
int len=0;
while(*info++){
len++;
}
info-=len;
#if LLKL_DEBUG_MODE
errc(f_write(&file[FIL_LOG],info,len,&s1),"INFOERR");
#endif
uint8_t val2, val21, val22,hex;

for(int i=0;i<4;i++){ //conversion to hex
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
#if LLKL_DEBUG_MODE
err(f_write(&file[FIL_LOG],&hex,1,&s1),"val21CE"); //CE - conversion error
#endif
if(val22>=10){
hex=val22+'a'-10;
} else{
hex=val22+48;
}
GLCD_B_WriteChar(hex,6+i*14,1);
#if LLKL_DEBUG_MODE
errc(f_write(&file[FIL_LOG],&hex,1,&s1),"val22CE");
#endif
}
GLCD_r;
#if LLKL_DEBUG_MODE
errc(f_write(&file[FIL_LOG],"\n",1,&s1),"nCE");
#endif
}


/*
llkl_throw_error: throws error if critical always, if not only in debug
condition - if true, error will be thrown
message - message which will be displayed
critical - if true, program will stop if condition also true
*/
void llkl_throw_error(uint8_t condition,char * message,uint8_t critical){
    if(critical){
        errc(condition,message);
    }else{
        err(condition,message);
    }
}

void llkl_external_mem_write(uint32_t adress, uint8_t value){

}
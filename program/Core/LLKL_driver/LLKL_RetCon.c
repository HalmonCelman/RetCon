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
if(llkl_pom) return llkl_pom;
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

        #if DEBUG_MODE==1
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
    uint8_t llkl_pom = LLKL_COMM_BUFF[file_pt[llkl_actual_file].dCounter++];

    #if DEBUG_MODE==1
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
info - information which you want to send up to 255 lenght of info
value - additional number which will show after info
*/
void llkl_send_info(char* info,uint32_t value){

GLCD_B_ClearScreen();
GLCD_B_WriteString(info,0,0);
uint8_t len=0;
while(*info++){
len++;
}
info-=len+1;
llkl_throw_error(f_write(&file[FIL_LOG],info,len,&s1),"INFOERR",0);
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
llkl_throw_error(f_write(&file[FIL_LOG],&hex,1,&s1),"val21CE",0); //CE - conversion error
#endif
if(val22>=10){
hex=val22+'a'-10;
} else{
hex=val22+48;
}
GLCD_B_WriteChar(hex,6+i*14,1);
#if LLKL_DEBUG_MODE
llkl_throw_error(f_write(&file[FIL_LOG],&hex,1,&s1),"val22CE",0);
#endif
}
GLCD_r;
#if LLKL_DEBUG_MODE
llkl_throw_error(f_write(&file[FIL_LOG],"\n",1,&s1),"nCE",0);
#endif
}


/*
llkl_throw_error: throws error if critical always, if not - only in debug
condition - if true, error will be thrown
message - message which will be displayed
critical - if true, program will stop if condition also true
*/
void llkl_throw_error(uint8_t condition,char * message, uint8_t critical){
    if(critical){
        errc(condition,message);
    }else{
        err(condition,message);
    }
}

#if LLKL_USE_EXTERNAL_MEMORY

void llkl_init_external_memory(void){
    f_open(&file[FIL_SLOWMEM],SLOWMEMFILE,FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
    f_open(&file[FIL_LABELS],LABELFILE,FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
}

void llkl_close_external_memory(void){
    f_close(&file[FIL_LABELS]);
    f_close(&file[FIL_SLOWMEM]);
}

void llkl_external_mem_write(uint32_t adress, uint8_t value){
    adress-=LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER;
    f_lseek(&file[FIL_SLOWMEM],adress);
    llkl_throw_error(f_write(&file[FIL_SLOWMEM],&value,1,&s1),"SLOW MEM SAVE FAILED!",0);
}

uint8_t llkl_external_mem_read(uint32_t adress){ //todo reading more than 1 byte
    uint8_t value;
    adress-=LLKL_FAST_MEM_SIZE+LLKL_FLAG_NUMBER;
    f_lseek(&file[FIL_SLOWMEM],adress);
    llkl_throw_error(f_read(&file[FIL_SLOWMEM],&value,1,&s1),"SLOW MEM LOAD FAILED!",0);
    return value;
}


void llkl_init_cache(void){
    FRESULT res=f_mkdir(CACHEDIR);
    if(res != FR_EXIST){
        llkl_throw_error(res,"FAILED TO INIT CACHE",1);
        llkl_send_info("Cache initialized ",0);
    }else{
        llkl_send_info("Cache loaded ",0);
    }
}

void llkl_remove_cache(void){
    llkl_throw_error(f_unlink(LABELFILE),"FAILED TO DEL LABELS",0);
    llkl_throw_error(f_unlink(SLOWMEMFILE),"FAILED TO DEL SLOWMEM",0);
    llkl_throw_error(f_unlink(CACHEDIR),"FAILED TO DEL CACHE",0);
    llkl_send_info("Cache deleted ",0);
}

#endif

void llkl_set_label(uint32_t labelNumber){
    uint64_t labelValue=(((uint64_t)file_pt[FIL_MAIN].buffCounter)<<32)+file_pt[FIL_MAIN].dCounter;
    if(labelNumber<LLKL_LABEL_NUMBER){
        LLKL_LABEL[labelNumber]=labelValue;
    }else{
        #if LLKL_USE_EXTERNAL_MEMORY
            llkl_throw_error(f_lseek(&file[FIL_LABELS],(labelNumber-LLKL_LABEL_NUMBER)*4),"Cannot lseek save label",0);
            llkl_throw_error(f_write(&file[FIL_LABELS],&labelValue,4,&s1),"Cannot save label",0);
        #else
            llkl_throw_error(1,"WRONG LABEL NUMBER",0);
        #endif
    }
    #if LLKL_DEBUG_MODE
        llkl_send_info("Label set ",labelValue);
    #endif
}

uint64_t llkl_get_label(uint32_t labelNumber){
    uint64_t labelValue=0;
    if(labelNumber<LLKL_LABEL_NUMBER){
        labelValue=LLKL_LABEL[labelNumber];
    }else{
        #if LLKL_USE_EXTERNAL_MEMORY
            llkl_throw_error(f_lseek(&file[FIL_LABELS],(labelNumber-LLKL_LABEL_NUMBER)*4),"Cannot lseek read label",0);
            llkl_throw_error(f_read(&file[FIL_LABELS],&labelValue,4,&s1),"Cannot read label",0);
        #else
            llkl_throw_error(1,"WRONG LABEL NUMBER",0);
        #endif
    }
    #if LLKL_DEBUG_MODE
        llkl_send_info("Label get ",labelValue);
    #endif
    return labelValue;
}

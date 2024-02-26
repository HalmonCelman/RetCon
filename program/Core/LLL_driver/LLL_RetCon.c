#include "LLL_RetCon.h"
#include "RC_streams.h"
#include <config.h>
#include <multi_buff.h>

///varialibes
extern FATFS fs1;
extern WORD s1;
extern BYTE res;

///functions
extern uint8_t errc(uint8_t,char*);
extern uint8_t err(uint8_t,char*);

uint8_t stream_params[LLL_STREAM_PARAMS];
uint8_t param_counter = 0;
uint8_t last_stream = 255;

typedef void (* streamout_p)(void);
typedef uint8_t (* streamin_p)(void);

// stream config section

const streamout_p lll_stream_out_func[]={
    rc_stream_error,        // Error
    rc_stream_refresh,      // Refresh screen
    rc_stream_clear,        // Clear buffer
    rc_stream_set_px,       // SetPixel
    rc_stream_clr_px,       // ClearPixel
    rc_stream_write_char,   // writeChar
    rc_stream_stroke_rect,  // StrokeRect
    rc_stream_fill_rect,    // Fill Rect
    rc_stream_beep,         // Beep
    rc_stream_delay,        // Delay
    rc_stream_set_timer     // setTimer
};

const streamin_p lll_stream_in_func[]={
    rc_stream_error_in,     // Error
    rc_stream_10_val,       // get 1-0 buttons value
    rc_analog1_val,         // get analog 1 value
    rc_analog2_val,         // get analog 2 value
    0,                      // Not Used
    0,                      // Not Used
    0,                      // Not Used
    0,                      // Not Used
    0,                      // Not Used
    0,                      // Not Used
    rc_stream_get_timer     // getTimer
};

const uint8_t lll_stream_out_value_num[]={
    1,  // Error
    1,  // Refresh screen
    1,  // Clear buffer
    2,  // SetPixel
    2,  // ClearPixel
    3,  // writeChar
    4,  // StrokeRect
    4,  // Fill Rect
    1,  // Beep
    2,  // Delay
    2   // setTimer
};

const uint8_t lll_stream_in_value_num[]={
    1,  // Error
    1,  // get 1-0 buttons value
    1,  // get analog 1 value
    1,  // get analog 2 value
    0,  // Not Used
    0,  // Not Used
    0,  // Not Used
    0,  // Not Used
    0,  // Not Used
    0,  // Not Used
    2   // getTimer
};

// end of section

FIL file[NUMOFFILES];
lll_pt file_pt[NUMOFFILES];
uint8_t LLL_COMM_BUFF[LLL_COMM_BUFF_SIZE];

uint8_t lll_physical_read; //says if it's needed to reload buffer - caused end of buffer
uint8_t lll_reload_buffer; //says if it's needed to reload buffer - caused change of file
uint8_t lll_actual_file; //says which file is already used
uint8_t lll_eof;

// functions specified in LLL.h
uint8_t lll_init_program(char* source,uint32_t position){
    #if DEBUG_MODE
        lll_send_info("INFO: opening file ",0);
    #endif
    uint8_t lll_pom=f_open(&file[FIL_MAIN],source,FA_READ); //open file in selected file
    if(lll_pom) return lll_pom;
    lll_pom = f_open(&file[FIL_LOG], LOGFILE ,FA_WRITE | FA_CREATE_ALWAYS);
    if(lll_pom) return lll_pom;

    lll_eof=0;

    lll_pom=f_lseek(&file[FIL_MAIN],position);
    if(lll_pom) return lll_pom;

    for(int i=0;i<NUMOFFILES;i++){
        file_pt[i].buffCounter=0; //clear buffor page pointer
        file_pt[i].command=0; //clear command pointer
        file_pt[i].dCounter=0; // clear dynamic pointer
    }

    #if DEBUG_MODE
        lll_send_info("INFO: opened succesfully ",0);
    #endif
    lll_actual_file=FIL_MAIN; //actual file change
    lll_reload_buffer=1; //reload data
    return 0;
}

uint8_t lll_end_program(){
    #if DEBUG_MODE==1
        lll_send_info("closing program in: ",FIL_MAIN);
    #endif
    uint8_t lll_pom = f_close(&file[FIL_LOG]);
    if(lll_pom) return lll_pom;
    return f_close(&file[FIL_MAIN]); //close selected file
}

uint8_t lll_get(void){

    if(file_pt[lll_actual_file].dCounter >= LLL_COMM_BUFF_SIZE)
        lll_physical_read = 1;


    if(lll_physical_read | lll_reload_buffer){ //reload command buffer and set pointers - should be read from last command to avoid chain broke but will be implemented later 

        #if DEBUG_MODE==1
            lll_send_info("INFO: reloading buffer ",(lll_physical_read<<1)|lll_reload_buffer);
        #endif
        
        f_read(&file[lll_actual_file],LLL_COMM_BUFF,LLL_COMM_BUFF_SIZE,&s1);
        if(s1<LLL_COMM_BUFF_SIZE){
            LLL_COMM_BUFF[s1]=LLL_EXIT; //reached EOF
            lll_eof=1;
        }
        if(lll_physical_read){
            lll_physical_read = 0;
            file_pt[lll_actual_file].buffCounter++; //next page
        }
        if(lll_reload_buffer){
            lll_reload_buffer = 0;
        }
        file_pt[lll_actual_file].dCounter = 0;
        file_pt[lll_actual_file].command = 0;

    }

    return LLL_COMM_BUFF[file_pt[lll_actual_file].dCounter++];
}

/*
lll_send_info: sends info to the user
info - information which you want to send up to 255 lenght of info
value - additional number which will show after info
*/
void lll_send_info(char* info,uint32_t value){
    #if SHOW_ON_SCREEN
        GLCD_B_ClearScreen();
        GLCD_B_WriteString(info,0,0);
    #endif
    uint8_t len=0;
    while(*info++){
    len++;
    }
    info-=len+1;
    #if DEBUG_MODE || LLL_DEBUG_MODE
    lll_throw_error(f_write(&file[FIL_LOG],info,len,&s1),"INFOERR",0);
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
    #if SHOW_ON_SCREEN
        GLCD_B_WriteChar(hex,i*14,1);
    #endif
    #if DEBUG_MODE || LLL_DEBUG_MODE
    lll_throw_error(f_write(&file[FIL_LOG],&hex,1,&s1),"val21CE",0); //CE - conversion error
    #endif
    if(val22>=10){
    hex=val22+'a'-10;
    } else{
    hex=val22+48;
    }
    #if SHOW_ON_SCREEN
        GLCD_B_WriteChar(hex,6+i*14,1);
        GLCD_r;
    #endif
    #if DEBUG_MODE || LLL_DEBUG_MODE
    lll_throw_error(f_write(&file[FIL_LOG],&hex,1,&s1),"val22CE",0);
    #endif
    }
    #if DEBUG_MODE || LLL_DEBUG_MODE
    lll_throw_error(f_write(&file[FIL_LOG],"\n",1,&s1),"nCE",0);
    #endif
}


/*
lll_throw_error: throws error if critical always, if not - only in debug
condition - if true, error will be thrown
message - message which will be displayed
critical - if true, program will stop if condition also true
*/
void lll_throw_error(uint8_t condition,char * message, uint8_t critical){
    if(critical){
        errc(condition,message);
    }else{
        err(condition,message);
    }
}


void lll_goTo(uint64_t position){
    #if DEBUG_MODE
    lll_throw_error(f_lseek(&file[FIL_MAIN],position),"Failed to jump",1);
    #else
    f_lseek(&file[FIL_MAIN],position);
    #endif
    file_pt[FIL_MAIN].buffCounter=position>>32;
    file_pt[FIL_MAIN].dCounter=position & 0xFFFF;
}

uint64_t lll_getPosition(void){
    return (((uint64_t)file_pt[FIL_MAIN].buffCounter)<<32)+file_pt[FIL_MAIN].dCounter;
}

void lll_pushStack(uint8_t data){
    #if LLL_USE_EXTERNAL_MEMORY

    #else
        LLL_STACK[stack_pointer.value++]=data;
    #endif
}

uint8_t lll_popStack(void){
    #if LLL_USE_EXTERNAL_MEMORY

    #else
        return LLL_STACK[--stack_pointer.value];
    #endif
}

#if LLL_USE_EXTERNAL_MEMORY

void lll_init_external_memory(void){
    f_open(&file[FIL_SLOWMEM],SLOWMEMFILE,FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
    f_open(&file[FIL_LABELS],LABELFILE,FA_READ | FA_WRITE | FA_OPEN_ALWAYS);
}

void lll_close_external_memory(void){
    f_close(&file[FIL_LABELS]);
    f_close(&file[FIL_SLOWMEM]);
}

void lll_external_mem_write(uint32_t adress, uint8_t value){
    adress-=LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER;
    f_lseek(&file[FIL_SLOWMEM],adress);
    lll_throw_error(f_write(&file[FIL_SLOWMEM],&value,1,&s1),"SLOW MEM SAVE FAILED!",0);
}

uint8_t lll_external_mem_read(uint32_t adress){ //todo reading more than 1 byte
    uint8_t value;
    adress-=LLL_FAST_MEM_SIZE+LLL_FLAG_NUMBER;
    f_lseek(&file[FIL_SLOWMEM],adress);
    lll_throw_error(f_read(&file[FIL_SLOWMEM],&value,1,&s1),"SLOW MEM LOAD FAILED!",0);
    return value;
}


void lll_init_cache(void){
    #if DEBUG_MODE
        lll_throw_error(f_open(&file[FIL_LOG], LOGFILE ,FA_WRITE | FA_CREATE_ALWAYS),"Failed to create log file",1);
        FRESULT res=f_mkdir(CACHEDIR);
        if(res != FR_EXIST){
            lll_throw_error(res,"FAILED TO INIT CACHE",1);
            lll_send_info("Cache initialized ",0);
        }else{
            lll_send_info("Cache loaded ",0);
        }
    #else
        
        f_mkdir(CACHEDIR);
    #endif
}

void lll_remove_cache(void){
    #if DEBUG_MODE
        lll_throw_error(f_unlink(LABELFILE),"FAILED TO DEL LABELS",0);
        lll_throw_error(f_unlink(SLOWMEMFILE),"FAILED TO DEL SLOWMEM",0);
        lll_throw_error(f_unlink(CACHEDIR),"FAILED TO DEL CACHE",0);
        lll_send_info("Cache deleted ",0);
        lll_throw_error(f_close(&file[FIL_LOG]),"Failed to close log file",0);
    #else
        f_unlink(LABELFILE);
        f_unlink(SLOWMEMFILE);
        f_unlink(CACHEDIR);
        
    #endif
}

#endif

// streams
lll_err lll_stream_out(uint8_t data,uint8_t stream){
    lll_err inst_err;
    inst_err.status=LLL_OK;

    if(stream == last_stream){
        stream_params[param_counter++] = data;
    }else{
        last_stream = stream;
        stream_params[0] = data;
        param_counter = 1;
    }

    if(param_counter == lll_stream_out_value_num[stream]){
        param_counter = 0;
        lll_stream_out_func[stream]();
    }

    return inst_err;
}

lll_err lll_stream_in(uint8_t * data,uint8_t stream){
    lll_err inst_err;
    inst_err.status=LLL_OK;

    *data = lll_stream_in_func[stream]();

    return inst_err;
}



#include "additional_graphics.h"
#include <ff.h>
#include <base.h>
#include <multi_buff.h>
#include <LLKL_RetCon.h>
void animate(char* filename){

animation a1;

a1.name=filename;
a1.frame=0;
a1.active=0;
a1.x=0;
a1.y=0;
a1.w=128;
a1.h=64;

errc(f_open(&file[FIL_D], filename, FA_READ),"FE");

a1.active=1; //run animation

while(a1.active){
GLCD_r;

res=err(f_lseek(&file[FIL_D],(DWORD)1024*a1.frame),"LseekERR");
res?res:err(f_read(&file[FIL_D],&GLCD_Buffer[0],1024,&s1),"ReadERR");

a1.frame++;
if(a1.frame>=83 || res){ //end animation if this is end or error occured
    a1.active=0;
}
}
}




///__funkcje

void GLCD_B_Bitmap_SD(char* name){
    char g[16];
    res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
f_read(&file[FIL_D],g, 5 , &s1);



int i=0;
int j=0;

i=0;
int f=0;
while(i<64){
    f=0;
    res= f_read(&file[FIL_D],g, 16 , &s1);
    while(f<16){
    j=0;
        while(j<8){
        if(~g[f] & (128>>j)){
            GLCD_B_SetPixel(8*f+j,i);
        }
    j++;
        }
    f++;
    }
    i++;

}


f_close(&file[FIL_D]);

}else{
delay(1000);
    GLCD_B_ClearScreen();
GLCD_B_WriteString("Error - opf",0,0);
GLCD_r;
}

}

void GLCD_Animate_exp(char* name){
res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
int x=0;
while(!x){
    f_read(&file[FIL_D],GLCD_Buffer,1024,&s1);
    if(s1!=1024){
        x=1;
    }

if(x){
    GLCD_B_ClearScreen();
}else{
GLCD_r;
}
delay(33);
}
f_close(&file[FIL_D]);
}
}

void GLCD_B_Bitmap_SD_exp(char* name){
    res=f_open(&file[FIL_D],name,FA_READ);
if(res== FR_OK){
    f_read(&file[FIL_D],GLCD_Buffer,1024,&s1);
f_close(&file[FIL_D]);
}

}
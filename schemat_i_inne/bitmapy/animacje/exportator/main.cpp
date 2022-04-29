#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
   unsigned char tab[64][16];
    unsigned char tabc[8][128];
    int jkl;
    int abc=1;
    getchar();

    do{
    for(int i=0;i<4;i++){
        jkl=getchar();
        if(jkl == EOF){
            abc=0;
            break;
        }
    }
int klm=0;
    for(int i=0;i<64;i++){
        for(int j=0;j<16;j++){
            klm=getchar();
            if(klm != EOF){
                tab[i][j]=(unsigned char)klm;
            }else{
            tab[i][j]=255;
            }
        }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<128;j++){
            tabc[i][j]=0;
        }
    }

    for(int j=0;j<8;j++){
            for(int v=0;v<16;v++){
            for(int x=0;x<8;x++){
            for(int i=0;i<8;i++){
    unsigned char pom=(~tab[8*j+i][v])<<x;
    pom=(pom>>7);
    pom=pom<<i;
        tabc[j][8*v+x]|=pom;
            }
    }

    }
    }
    for(int i=0;i<8;i++){
        for(int j=0;j<128;j++){
            cout<<tabc[i][j];
        }
    }

    jkl=getchar();
    if(jkl == EOF){
            abc=0;
            break;
        }


    }while(abc);


    return 0;
}

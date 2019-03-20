//
// Created by 10 on 17.03.2019.
//
#include "show.h"

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void msleep(int ms)
{
#ifdef _WIN32
    Sleep(ms);
#else
    usleep(ms * 1000);
#endif
}
void myclean(){
  #ifdef _WIN32
    system("cls");
#else
    system("clear")
#endif
}

void show(cell_t *c, int sizeX, int sizeY) {
    myclean();
    for (int i = 0; i <sizeX ; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if( c[i * sizeY + j].z == 1)
                printf("%c",220);               //254- w asci to czarny kwadracik
            if(c[i*sizeY+j].z ==0)
                printf(" ");
        }
        printf("\n");
    }

    msleep(300);
    Sleep(200);
}

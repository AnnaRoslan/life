//
// Created by 10 on 17.03.2019.
//
#include "show.h"
#include <stdio.h>

void show(cell_t *c, int sizeX, int sizeY) {
    for (int i = 0; i <sizeX ; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            if( c[i * sizeY + j].z == 1)
                printf("%c",254);               //254- w asci to czarny kwadracik
            if(c[i*sizeY+j].z ==0)
                printf(" ");
        }
        printf("\n");

    }

}

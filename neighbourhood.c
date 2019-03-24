//
// Created by 10 on 03.03.2019.
//
#include <malloc.h>
#include "neighbourhood.h"
#include "life.h"
#include <stdio.h>

int neibourhood_morooea(Cell* c, int x, int y, int sizeX, int sizeY) {
    int i;
    int howManyN = 0;

    for(i= -1; i<2; i++){
        if((x-1) ==-1 || (x-1) == sizeX || (y+i) == -1 || (y+i) == sizeY) continue;
        if(c[((x - 1) * sizeY) + (y + i)].z == 1)
            howManyN++;
//	printf("[ %d][%d] \n",(x-1),(y+i) );
    }

    if( (y+1) != -1 && (y+1) != sizeY){
        if(c[((x)*sizeY)+(y+1)].z == 1)
            howManyN++;
//	printf("[ %d][%d] \n",(x),(y+1) );

    }

    for(i= -1; i<2; i++){
        if((x+1) ==-1 || (x+1) == sizeX || (y+i) == -1 || (y+i) == sizeY) continue;
        if(c[((x+1)*sizeY)+(y+i)].z == 1)
            howManyN++;
//	printf("[ %d][%d] \n",(x+1),(y+i) );
    }

    if( (y-1) != -1  && (y-1) != sizeY){
        if(c[((x)*sizeY)+(y-1)].z == 1)
            howManyN++;

//	printf("[ %d][%d] \n",(x),(y-1) );
    }
    return howManyN;
}

int neibourhood_neumann(Cell* c, int x, int y, int sizeX, int sizeY) {
    int howManyN = 0;//zmienna pomocnicza

    if((x-1) != -1)
        if(c[((x - 1) * sizeY) + (y)].z == 1)
            howManyN++;

    if((x+1) != sizeX)
        if(c[((x+1) * sizeY) + (y)].z == 1)
            howManyN++;

    if((y-1) != -1)
        if(c[((x) * sizeY) + (y-1)].z == 1)
            howManyN++;

    if((y+1) != sizeY)
        if(c[((x) * sizeY) + (y+1)].z == 1)
            howManyN++;

    return howManyN;
}

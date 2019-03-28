//
// Created by 10 on 03.03.2019.
//
#include <malloc.h>
#include "neighbourhood.h"
#include "life.h"
#include <stdio.h>

int neibourhood_morooea(Cell* cells, int x, int y, int sizeX, int sizeY) {
    int i;
    int NeighbourhoodCounter = 0;

    for(i= -1; i<2; i++){
        if((x-1) ==-1 || (x-1) == sizeX || (y+i) == -1 || (y+i) == sizeY) continue;
        if(cells[((x - 1) * sizeY) + (y + i)].z == 1)
            NeighbourhoodCounter++;
    }

    if( (y+1) != -1 && (y+1) != sizeY){
        if(cells[((x)*sizeY)+(y+1)].z == 1)
            NeighbourhoodCounter++;
    }

    for(i= -1; i<2; i++){
        if((x+1) ==-1 || (x+1) == sizeX || (y+i) == -1 || (y+i) == sizeY) continue;
        if(cells[((x+1)*sizeY)+(y+i)].z == 1)
            NeighbourhoodCounter++;
    }

    if( (y-1) != -1  && (y-1) != sizeY){
        if(cells[((x)*sizeY)+(y-1)].z == 1)
            NeighbourhoodCounter++;

    }
    return NeighbourhoodCounter;
}

int neibourhood_neumann(Cell* cells, int x, int y, int sizeX, int sizeY) {
    int neighbourhoodCounter = 0;

    if((x-1) != -1)
        if(cells[((x - 1) * sizeY)
        + (y)].z == 1)
            neighbourhoodCounter++;

    if((x+1) != sizeX)
        if(cells[((x+1) * sizeY) + (y)].z == 1)
            neighbourhoodCounter++;

    if((y-1) != -1)
        if(cells[((x) * sizeY) + (y-1)].z == 1)
            neighbourhoodCounter++;

    if((y+1) != sizeY)
        if(cells[((x) * sizeY) + (y+1)].z == 1)
            neighbourhoodCounter++;

    return neighbourhoodCounter;
}

//
// Created by 10 on 03.03.2019.
//
#include <stdlib.h>
#include "rand_life.h"
#include "life.h"

void randFill(Cell* cells, int sizeX, int sizeY, double per){
  int density =(int) per;
    for(int i=0; i<(sizeX*sizeY); i++)
        if(rand()% density ==0)
            cells[i].z=1;
}

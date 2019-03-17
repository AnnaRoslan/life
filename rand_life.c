//
// Created by 10 on 03.03.2019.
//
#include <stdlib.h>
#include "rand_life.h"
#include"life.h"


void randFill(cell_t* c, int sizeX, int sizeY, double per){
    int n = (int)((sizeX*sizeY)*(per/100));
    int max = (sizeX*sizeY)-1;
    for (int i=0; i<n; i++)
        c[rand()%max].z = 1;
}

//
// Created by 10 on 02.03.2019.
//
#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H

#include "loading.h"

typedef struct {
    short  int z;
    int x;
    int y;
} Cell;

Cell* createMap(int sizeX, int sizeY);

void life(Cell* cells, int sizeX, int sizeY, int* howManyNeighbourhood, int whichNeighbourhood);

void playGame(Parameters gameParameters, Pic_png *image, char* dirName);

#endif //LIFE_LIFE_H

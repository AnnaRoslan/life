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

//tworzy komorki na planszy o wym s1Xs2 i wypełnia 0 na poczatek
Cell* createMap(int sizeX, int sizeY);

//zwania pamiec ni mam pojecia czy to tak ma wygladac
void freeCell(Cell* c);

//tu sie dzieje 1 ruch
void life(Cell* c, int sizeX, int sizeY, int* howManyN, int whichOne);

// tu jest n ruchow
void playGame(Parameters gameParameters, Pic_png *image, char* pictureLocation);

#endif //LIFE_LIFE_H

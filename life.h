//
// Created by 10 on 02.03.2019.
//

#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H

#include "readParameters.h"

typedef struct cell{
     char z;// zyje czy nie zyje
    int x;// wsporzedna
    int y;//wsporzedna
}cell_t;

cell_t* Start( int sizeX, int sizeY);//tworzy komorki na planszy o wym s1Xs2 i wypełnia 0 na poczatek

//void free_cell(void **c, int sizeX, int sizeY);//zwania pamiec ni mam pojecia czy to tak ma wygladac

void life( cell_t *c, int sizeX, int sizeY,  short int* howManyN, int which_one);//tu sie dzieje 1 ruch

void game( int moves, Parameter* parameter); // tu jest n ruchow


#endif //LIFE_LIFE_H

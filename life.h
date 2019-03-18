//
// Created by 10 on 02.03.2019.
//

#ifndef LIFE_LIFE_H
#define LIFE_LIFE_H

typedef struct cell{
    short int z;// zyje czy nie zyje
    int x;// wsporzedna
    int y;//wsporzedna
    //int n;//ilosc sasiadow
}cell_t;

cell_t* Start( int sizeX, int sizeY);//tworzy komorki na planszy o wym s1Xs2 i wypełnia 0 na poczatek

void free_cell(cell_t *c, int sizeX, int sizeY);//zwania pamiec ni mam pojecia czy to tak ma wygladac

void life( cell_t *c, int sizeX, int sizeY, int* howManyN, int which_one);//tu sie dzieje 1 ruch

void game(cell_t* c, int moves,int sizeX, int sizeY, int which_neighbourhood); // tu jest n ruchow


#endif //LIFE_LIFE_H

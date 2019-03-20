//
// Created by 10 on 20.03.2019.
//
#include <stdio.h>

#ifndef LIFE_READPARAMETERS_H
#define LIFE_READPARAMETERS_H
typedef  struct Parameter{
    int sizeX; // rozmiar x
    int sizeY; // rozmiar y
    short int which_neighbourhood; // 80 sądziedztwo monrooea a 81 z filmem 40 sądziedztwo von neumanna 41 z fimem
    short int randomfill;

} Parameter;

Parameter  *readParameters ( FILE * file);

#endif //LIFE_READPARAMETERS_H

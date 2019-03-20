//
// Created by 10 on 02.03.2019.
//

#ifndef LIFE_NEIGHBOURHOOD_H
#define LIFE_NEIGHBOURHOOD_H
#include "life.h"

short int neibourhood_morooea(cell_t *c, int x, int y, int sizeX, int sizeY);

short int  neibourhood_neumann(cell_t *c, int x, int y, int sizeX, int sizeY);

#endif //LIFE_NEIGHBOURHOOD_iH

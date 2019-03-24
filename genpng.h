//
// Created by 01142586 on 20.03.2019.
//

#ifndef THEGAMEOFLIFE_GENPNG_H
#define THEGAMEOFLIFE_GENPNG_H

#include <png.h>
#include "life.h"


void generatePng(char* fileName, Pic_png *);

void processFile(Pic_png *, Cell *c);

#endif //THEGAMEOFLIFE_GENPNG_H

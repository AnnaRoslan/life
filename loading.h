//
// Created by 01142586 on 19.03.2019.
//

#ifndef LIFE_LOADING_H
#define LIFE_LOADING_H

#include <stdio.h>
#include <png.h>

#define MAXBUF 128

typedef  struct {
    int sizeX;
    int sizeY;
    int moves;
    short int which_neighbourhood; // 80 sądziedztwo monrooea a 81 z filmem 40 sądziedztwo von neumanna 41 z fimem
    short int density;
    short int animation;
    int howManyPictures;
    int howLongSinceTheLastPicture;

} Parameters;

typedef struct {
    int width, height;
    png_byte colorType;
    png_byte bitDepth;

    png_structp png_ptr;
    png_infop info_ptr;
    png_bytep * rowPointers;
} Pic_png;


void readParameters ( char *fileName, Parameters*, Pic_png* );


int createDictionary (char * dirName);

#endif //LIFE_LOADING_H

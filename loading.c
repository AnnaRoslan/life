//
// Created by 01142586 on 19.03.2019.
//

#include "loading.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readParameters (char *fileName, Parameters *gameParameters, Pic_png *image) {
    int i;
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("File gameconfig could not be opened for reading");
        exit(EXIT_FAILURE);
    }

    char buf[MAXBUF];
    while (fgets(buf, MAXBUF, fp) != NULL)
        if (strlen(buf) > 1 && buf[0] != '#')
            break;

    for(int n = 0; n < 8; n++) {
        for(i = 0; buf[i] != '='; i++)
            ;
        if(n==0)
            gameParameters->which_neighbourhood = (short) atoi(buf+i+1);
        else if(n==1)
            gameParameters->sizeX = atoi(buf+i+1);
        else if(n==2)
            gameParameters->sizeY = atoi(buf+i+1);
        else if(n==3)
            gameParameters->density = (short) atoi(buf+i+1);
        else if(n==4)
            gameParameters->moves = atoi(buf+i+1);
        else if(n==5)
            gameParameters->animation = (short) atoi(buf+i+1);
        else if(n==6)
            gameParameters->howManyPictures = atoi(buf+i+1);
        else if(n==7)
            gameParameters->howLongSinceTheLastPicture =atoi(buf+i+1);
        fgets(buf, MAXBUF, fp);
    }

    while (fgets(buf, MAXBUF, fp) != NULL)
        if (strlen(buf) > 1 && buf[0] != '#')
            break;

    for(i = 0; buf[i] != '='; i++)
        ;
    image->bitDepth = (png_byte) atoi(buf+i+1);
    image->height = gameParameters->sizeY;
    image->width = gameParameters->sizeX;
    image->colorType = PNG_COLOR_TYPE_GRAY;

    fclose(fp);

}

#ifdef _WIN32
#include <io.h>
#else
#include<sys/stat.h>
#endif

int createDictionary (char * dirName){
    char path[50] =  "../images/";
    strcat(path,dirName);
    strcpy(dirName,path);
#ifdef _WIN32
   return mkdir(dirName);
#else
   return mkdir(dirName, S_IRUSR | S_IWUSR | S_IXUSR);
#endif

}

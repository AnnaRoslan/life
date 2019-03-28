//
// Created by 10 on 03.03.2019.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "life.h"
#include "neighbourhood.h"
#include "show.h"
#include "genpng.h"
#include "rand_life.h"

Cell* createMap(int sizeX, int sizeY) {
    Cell* c = malloc((sizeX * sizeY) * sizeof(*c ));
    if(!c)
        printf("Map could not be created\n");
    for(int i = 0; i < sizeX; i++){
        for(int j = 0; j < sizeY; j++){
            c[i*sizeY+j].z = 0;
            c[i*sizeY+j].x = i;
            c[i*sizeY+j].y = j;
        }
    }
    return c;
}

void life(Cell* cells, int sizeX, int sizeY, int* howManyNeighbourhood, int whichNeighbourhood {
    int nr_born = 3;
    int nr_down_dead = 2;
    int nr_up_dead = 3;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if(whichNeighbourhood == 8)
                howManyNeighbourhood[(i * sizeY) + j] = neibourhood_morooea(cells, i, j, sizeX, sizeY);
            if(whichNeighbourhood ==4)
                howManyNeighbourhood[(i * sizeY) + j] = neibourhood_neumann(cells, i, j, sizeX, sizeY);
        }
    }
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if (howManyNeighbourhood[i * sizeY + j] == nr_born)
                cells[i * sizeY + j].z = 1;
            if (cells[i * sizeY + j].z == 1)
                if (howManyNeighbourhood[i * sizeY + j] < nr_down_dead || howManyNeighbourhood[i * sizeY + j] > nr_up_dead)
                    cells[i * sizeY + j].z = 0;
        }
    }
}

void playGame(Parameters gameParameters, Pic_png *image, char* dirName) {
    int sizeX = gameParameters.sizeX;
    int sizeY = gameParameters.sizeY;
    int whichNeighbourhood = gameParameters.which_neighbourhood;
    int howManyPictures = gameParameters.howManyPictures;
    int howLongSinceTheLastPicture = gameParameters.howLongSinceTheLastPicture;

    strcat(dirName,"/gen%d.png");

    int *howManyN = calloc( ( sizeX * sizeY), sizeof(*howManyN));
    if(!howManyN)
        printf("howManyN could not be allocated\n");

    Cell *cells =createMap(sizeX, sizeY);
    if(!cells)
        printf("Map could not be created\n");
    randFill(cells, sizeX, sizeY, gameParameters.density);

    char fileName[100];

    if((whichNeighbourhood == 8 || whichNeighbourhood == 4)&& gameParameters.animation == 1)
        for (int i = 0; i < gameParameters.moves; i++) {
            showMap(cells, sizeX, sizeY);
            if( i % howLongSinceTheLastPicture == 0 && i< (howManyPictures * howLongSinceTheLastPicture) ){
                sprintf(fileName,dirName, i);
            	processFile(image, cells);
            	generatePng(fileName, image);
	    }
           
            life(cells, sizeX, sizeY, howManyN, whichNeighbourhood);
        }
    else
        for (int i = 0; i < gameParameters.moves; i++) {
            
            if( i % howLongSinceTheLastPicture == 0 && i< (howManyPictures * howLongSinceTheLastPicture) ){
	    	sprintf(fileName,dirName, i);
            	processFile(image, cells);
            	generatePng(fileName, image);
	    } 
	    life(cells, sizeX, sizeY, howManyN, whichNeighbourhood);
        }

    png_free_data( image->png_ptr, image->info_ptr,PNG_FREE_ALL,-1);
    free(image);
    free(howManyN);
    free(cells);
}

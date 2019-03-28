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

void life(Cell* c, int sizeX, int sizeY, int* howManyN, int whichOne) {
    int nr_born = 3;
    int nr_down_dead = 2;
    int nr_up_dead = 3;

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if(whichOne == 8)
                howManyN[(i * sizeY) + j] = neibourhood_morooea(c, i, j, sizeX, sizeY);
            if(whichOne ==4)
                howManyN[(i * sizeY) + j] = neibourhood_neumann(c, i, j, sizeX, sizeY);
        }
    }
    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if (howManyN[i * sizeY + j] == nr_born)
                c[i * sizeY + j].z = 1;
            if (c[i * sizeY + j].z == 1)
                if (howManyN[i * sizeY + j] < nr_down_dead || howManyN[i * sizeY + j] > nr_up_dead)
                    c[i * sizeY + j].z = 0;
        }
    }
}

void playGame(Parameters gameParameters, Pic_png *image, char* pictureLocation) {
    int sizeX = gameParameters.sizeX;
    int sizeY = gameParameters.sizeY;
    int moves = gameParameters.moves;
    int whichOne = gameParameters.which_neighbourhood;
    int randomFill = gameParameters.density;
    int ifAnimation = gameParameters.animation;
    int howManyPictures = 10;
    int howLongSinceTheLastPicture = 5;
    
    int *howManyN = calloc( ( sizeX * sizeY), sizeof(*howManyN));
    if(!howManyN)
        printf("howManyN could not be allocated\n");

    Cell *map =createMap(sizeX, sizeY);
    if(!map)
        printf("Map could not be created\n");
    randFill(map, sizeX, sizeY, randomFill);

    char fileName[100];

    if((whichOne == 8 || whichOne == 4)&& ifAnimation==1)
        for (int i = 0; i < moves; i++) {
            showMap(map, sizeX, sizeY);
            if( i % howLongSinceTheLastPicture == 0 && i< (howManyPictures * howLongSinceTheLastPicture) ){
	    //	sprintf(fileName,"xx" , i);
            	processFile(image, map);
            	generatePng(fileName, image);
	    }
           
            life(map, sizeX, sizeY, howManyN, whichOne);
        }
    else
        for (int i = 0; i < moves; i++) {
            
            if( i % howLongSinceTheLastPicture == 0 && i< (howManyPictures * howLongSinceTheLastPicture) ){
	    	sprintf(fileName,pictureLocation, i);
            	processFile(image, map);
            	generatePng(fileName, image);
	    } 
	    life(map, sizeX, sizeY, howManyN, whichOne);
        }


    png_free_data( image->png_ptr, image->info_ptr,PNG_FREE_ALL,-1);
    free(image);
    free(howManyN);
    free(map);

}

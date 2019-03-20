//
// Created by 10 on 03.03.2019.
//
#include <stdio.h>
#include <stdlib.h.>
#include  "life.h"
#include "neighbourhood.h"
#include "show.h"
#include "readParameters.h"
#include "rand_life.h"

cell_t* Start( int sizeX, int sizeY){//tworzy komorki na planszy o wym s1Xs2 i wypełnia 0 na poczatek
    cell_t* c = malloc((sizeX*sizeY) *sizeof(struct cell));
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            c[i*sizeY+j].z =0; //c[i*s2+j].n = 0;
            c[i*sizeY+j].x = i; c[i*sizeY+j].y= j;
        }
    }
    return c;
}
void free_cell(void **c, int sizeX, int sizeY){ //zwania pamiec ni mam pojecia czy to tak ma wygladac

    free(c);

}
void life( cell_t *c, int sizeX, int sizeY, short int* howManyN,int which_one) {
    int nr_born =3;
    int nr_down_dead =2;
    int nr_up_dead= 3;

    for (int i = 0; i < sizeX * sizeY; ++i) {howManyN[i] = 0;}

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if(which_one ==80 || which_one == 81)
                howManyN[(i * sizeY) + j] = neibourhood_morooea(c, i, j, sizeX, sizeY);
            if(which_one ==41 || which_one ==40)
                 howManyN[(i * sizeY) + j] =  neibourhood_neumann(c, i, j, sizeX, sizeY);

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
void game( int moves, Parameter * parameter) {
    int sizeX = parameter->sizeX;
    int  sizeY = parameter->sizeY;
    int whichOne = parameter->which_neighbourhood;
    int fillRandom = parameter->randomfill;

    cell_t *c = Start(sizeX, sizeY);

     short int *howManyN = calloc((sizeX * sizeY), sizeof(short int));
     if(fillRandom !=0)
         randFill(c,sizeX,sizeX,fillRandom);

/* 81 - sąsiedztwo monrooea z wyswietlaniem
 * 80 - sąsziedztwo monrooea bez wyswietlania
 * 40, 41 analogicznie z sasziędztwem von neumanna
 */
    if(whichOne ==81 || whichOne == 41) {
        for (int i = 0; i < moves; i++) {
            life(c, sizeX, sizeY, howManyN, whichOne);
            show(c, sizeX, sizeY);
        }
    }
     else {
        for (int i = 0; i < moves; i++) {
            life(c, sizeX, sizeY, howManyN, whichOne);
        }
    }

        free(howManyN);
        free(c);

    // w przyszłosci tu gdzies trzeba zapisyc do pliku png
}



//
// Created by 10 on 03.03.2019.
//
#include <stdio.h>
#include <stdlib.h.>
#include  "life.h"
#include "neighbourhood.h"
#include "show.h"

#include "show.h"
#include <stdio.h>
#include <stdlib.h>

cell_t* Start( int sizeX, int sizeY){//tworzy komorki na planszy o wym s1Xs2 i wypełnia 0 na poczatek
    cell_t* c = malloc((sizeX*sizeY) *sizeof(cell_t));
    for(int i=0;i<sizeX;i++){
        for(int j=0;j<sizeY;j++){
            c[i*sizeY+j].z =0; //c[i*s2+j].n = 0;
            c[i*sizeY+j].x = i; c[i*sizeY+j].y= j;
        }
    }
    return c;
}
void free_cell(cell_t *c, int sizeX, int sizeY){ //zwania pamiec ni mam pojecia czy to tak ma wygladac
    for(int i=0; i< sizeX*sizeY ; i++)
        free(&c[i]);
    free(c);

}
void life( cell_t *c, int sizeX, int sizeY, int* howManyN,int which_one) {
    int nr_born =3;
    int nr_down_dead =2;
    int nr_up_dead= 3;

    for (int i = 0; i < sizeX * sizeY; ++i) {howManyN[i] = 0;}

    for (int i = 0; i < sizeX; i++) {
        for (int j = 0; j < sizeY; j++) {
            if(which_one ==80 || which_one == 81)
                howManyN[(i * sizeY) + j] = neibourhood_morooea(c, i, j, sizeX, sizeY);
            if(which_one ==41 || which_one ==40)
                 howManyN[(i * sizeY) + j] = neibourhood_neumann(c, i, j, sizeX, sizeY);

            //printf("|(%d)%d,%d|%d  ", ((i * sizeY) + j), i, j, howManyN[(i * sizeY) + j]);
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
void game(cell_t *c, int moves, int sizeX, int sizeY,int which_neighbourhood) {
    int which_one = which_neighbourhood;
    int *howManyN = calloc(sizeX*sizeY, sizeof(int));
    myclean();
     if(which_one ==81 || which_one == 41)
    for (int i = 0; i < moves; i++) {
        life(c, sizeX, sizeY, howManyN, which_one);
        show(c,sizeX,sizeY);
    }
     else
         for (int i = 0; i < moves; i++) {
             life(c, sizeX, sizeY, howManyN, which_one);
         }
        free(howManyN);
    // w przyszłosci tu gdzies trzeba zapisyc do pliku png
}



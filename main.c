#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#include "life.h"
#include "neighbourhood.h"
#include "rand_life.h"
#include "show.c"


void fill(cell_t *c);
void print(cell_t* c, int s1,int s2);

unsigned int time(void *pVoid);

int main() {
    srand(time(NULL));
    int s1 = 5; int s2=5;
    int which_neighbourhood = 8;

    cell_t *c = start(s1,s2);
    fill(c);
    print(c,s1,s2);
//randomFill(c,s1,s2,50)
    game(c,2,s1,s2,which_neighbourhood);
    print(c,s1,s2);
    show(c,s1,s2);
    free_cell(c,s1,s2);

    return 0;
}

void print(cell_t* c, int s1,int s2){// na potrzeby testu
    printf("\n");
    for(int i=0;i<s1;i++){
        for(int j=0 ; j<s2; j++){
            printf("%d " /*[%d]/*[%d][%d] "*/, c[i*s2+j].z);//,c[i*s2+j].n);//,c[i*s2+j].x,c[i*s2+j].y);
        }
        printf("\n");
    }
    printf("----------------------------------------\n");
}
void fill(cell_t *c){//powołujez do zycia komurki//do testów
    c[11].z = 1;
    c[12].z = 1;
    c[13].z = 1;

}
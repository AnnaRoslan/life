#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>

#include "life.h"
#include "neighbourhood.h"
#include "rand_life.h"
#include "show.c"


void fill(cell_t *c);
void print(cell_t* c, int s1,int s2);



int main() {
    clock_t start = clock();
    srand(time(NULL));
    int s1 = 100; int s2=100;
    int which_neighbourhood = 81;
/* nw dokładnie jak ale tos w stylu:
*80 monrooe
* 81 z filem
* 40 neumana
* 41 to z fimem
*/
    cell_t *c = Start(s1,s2);
    randFill(c,s1,s2,88.0);

   // print(c,s1,s2);
    game(c,100,s1,s2,which_neighbourhood);

    free_cell(c,s1,s2);
    clock_t stop = clock();
    double elapsed = (double) (stop - start) / CLOCKS_PER_SEC;
    printf("\nTime elapsed: %.5f\n", elapsed);
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
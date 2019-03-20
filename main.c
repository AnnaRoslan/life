#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "life.h"
#include "neighbourhood.h"
#include "rand_life.h"
#include "show.h"
#include "readParameters.h"


void fill(cell_t *c);
void print(cell_t* c, int s1,int s2);



int main(int argc, char** argv) {
//    if(argc == 1 ){
//        fprintf(stderr, "Nie wystarczająca ilość argómentów");
//        return 0;
//    }
    //else {
        FILE * f = fopen("paremeters.txt","r") ;//== NULL ? fprintf(stderr,"Zła nazwa pliku") : printf("działa");
               Parameter * parameter= readParameters(f);


        srand(time(NULL));
    game(100,parameter);
//int a;
//scanf("%d",&a);
        return 0;
   // }
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

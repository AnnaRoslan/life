#include <time.h>
#include <stdlib.h>
#include "life.h"
#include "neighbourhood.h"
#include "show.h"
#include "genpng.h"

int main(int argc, char** argv) {
    srand( (unsigned int) time(NULL));

    Parameters gameParameters;
    Pic_png *image = malloc(sizeof *image);

    readParameters("../gameconfig.txt", &gameParameters, image);
   	 printf("%d\n", gameParameters.animation);



    playGame( gameParameters, image );
	
    return 0;
}

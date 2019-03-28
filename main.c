#include <time.h>
#include<string.h>
#include <stdlib.h>
#include<string.h>

#include "life.h"
#include "neighbourhood.h"
#include "show.h"
#include "genpng.h"
#include "loading.h"

int main(int argc, char** argv) {
    srand( (unsigned int) time(NULL));
	
    Parameters gameParameters;
    Pic_png *image = malloc(sizeof *image);

    readParameters("../gameconfig.txt", &gameParameters, image);
	if(argc <1){
	    printf("Have to give a name of directory");
		exit(EXIT_FAILURE);
	}

	char dirName[50];
       	strcpy(dirName,argv[1]);

		int check = createDictionary(dirName);
		if(check ==-1){
			printf("Cannot create a directory try with difrent name");
			exit(EXIT_FAILURE);
		}

		playGame( gameParameters, image, dirName);

    return 0;
}

#include <time.h>
#include<string.h>
#include<sys/stat.h>
#include <stdlib.h>
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
//	if(argc >1){
    	char* dir = argv[1];
	char dirname[50] = "../images/";
	strcat(dirname,dir);
//printf("%s    ",dirname);
	int check;

		check =	mkdir(dirname, S_IRUSR | S_IWUSR | S_IXUSR);
		if(check ==-1){
			printf("Cannot create a directory try with difrent name");
			exit(EXIT_FAILURE);
	}
	char  pictureLocation[50];
//	strcat(pictureLocation,dirname );
//	strcat(pictureLocation,"/gen%d.png");
//printf("%s       ",pictureLocation);
//}


	strcat(dirname,"/gen%d.png");
      	playGame( gameParameters, image, dirname);

    
    return 0;
}

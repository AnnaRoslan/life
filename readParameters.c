//
// Created by 10 on 20.03.2019.
//

#include "readParameters.h"
#include <stdio.h>
#include <stdlib.h>

Parameter* readParameters (FILE * file){
    Parameter*  parameters;

    if(file == NULL) {
        fprintf(stderr, "Błąd przy otwieraniu pliku!");
        exit(EXIT_FAILURE);
    }
   // while(fscanf)
        fscanf(file," %d %d %hu %hu",&parameters->sizeX, &parameters->sizeY, &parameters->which_neighbourhood, &parameters->randomfill  );


   // printf("%d  %d  %hu  %hu ",parameters->sizeX, parameters->sizeY, parameters->which_neighbourhood, parameters->randomfill);
fclose(file);
    return parameters;
}




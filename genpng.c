#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

#include <png.h>
#include "genpng.h"



void generatePng(char* fileName, Pic_png* png) {
    FILE *fp = fopen(fileName, "wb");
    if (!fp)
        printf("File %s could not be opened for generating", fileName);

    png->png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
    if (!png->png_ptr)
        printf("png_create_write_struct failed");

    png->info_ptr = png_create_info_struct(png->png_ptr);
    if (!png->info_ptr)
        printf("png_create_info_struct failed");

    if (setjmp(png_jmpbuf(png->png_ptr)))
        printf("Error during init_io");

    png_init_io(png->png_ptr, fp);
    if (setjmp(png_jmpbuf(png->png_ptr)))
        printf("Error during writing header");

    png_set_IHDR(png->png_ptr, png->info_ptr, png->width, png->height,
                 png->bitDepth, png->colorType, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

    png_write_info(png->png_ptr, png->info_ptr);

    if (setjmp(png_jmpbuf(png->png_ptr)))
        printf("Error during writing bytes");

    png_write_image(png->png_ptr, png->rowPointers);

    if (setjmp(png_jmpbuf(png->png_ptr)))
        printf("Error during end of write");

    png_write_end(png->png_ptr, NULL);

    for (int y=0; y<png->height; y++)
        free(png->rowPointers[y]);
    free(png->rowPointers);

    png_destroy_write_struct( &png->png_ptr, &png->info_ptr);
   png_destroy_info_struct(png->png_ptr, &png->info_ptr);

    fclose(fp);
}

void processFile(Pic_png *png, Cell *c) {
    int x, y;
    png->rowPointers = (png_bytep*) malloc(sizeof(png_bytep) * png->height);
    for (y=0; y<png->height; y++)
        png->rowPointers[y] = (png_byte*) malloc(sizeof(png_byte) * png->width);

    for (y = 0; y < png->height; y++) {
        png_byte* row = png->rowPointers[y];
        for (x = 0; x < png->width; x++) {
            if (c[y * png->width + x].z == 0) {
                row[x] = 255;
            } else {
                row[x] = 0;
            }
        }
    }
}



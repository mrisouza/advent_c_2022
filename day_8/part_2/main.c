#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"

int main(int argc, char** argv){
    if(argc != 2){
        printf("No input given...\n");
        exit(EXIT_FAILURE);
    }
    FILE* pfile = fopen(argv[1], "r");
    if(pfile == NULL){
        perror("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    grid g;
    init_grid(&g);
    fill_grid(pfile, &g);
    scenic_spot(&g);
    print_grid(&g);
    fclose(pfile);
    return EXIT_SUCCESS;
}

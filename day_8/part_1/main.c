#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    FILE* pfile = fopen(argv[1], "r");
    if(pfile == NULL){
        printf("could not open file...\n");
        exit(EXIT_FAILURE);
    }
    grid g;
    init_grid(&g);
    fill_grid(pfile, &g);
    fill_visibility(&g);
    print_grid(&g);
    int num_vis = count_visible(&g);
    printf("%d\n", num_vis);
    return EXIT_SUCCESS;
}

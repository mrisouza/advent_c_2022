#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

bool is_subset(int l_1, int u_1, int l_2, int u_2);

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    char* filepath = argv[1];
    FILE* pfile = fopen(filepath, "r");
    
    if(pfile == NULL){
        perror("error opening file...\n");
        exit(EXIT_FAILURE);
    }
    int e_1x, e_1y, e_2x, e_2y;
    int total = 0;

    while(fscanf(pfile, "%d-%d,%d-%d", &e_1x, &e_1y, &e_2x, &e_2y) != EOF){
        if(is_subset(e_1x, e_1y, e_2x, e_2y)){
            total++;
        }
    }
    printf("%d\n", total);
    return EXIT_SUCCESS;
}

bool is_subset(int l_1, int u_1, int l_2, int u_2){
    if(l_1 <= l_2 && u_2 <= u_1){
        return true;
    }
    if(l_2 <= l_1 && u_1 <= u_2){
        return true;
    }
    return false;
}

#include <stdio.h>
#include <stdlib.h>

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
    char a, b;
    int score = 0;
    while(fscanf(pfile, "%c %c\n", &a, &b) != EOF){
        if(a == 'A' && b == 'X'){ // rock -> lose
            score += 3 + 0;
        }
        if(a == 'A' && b == 'Y'){ // rock -> draw
            score += 1 + 3;
        }
        if(a == 'A' && b == 'Z'){ // rock -> win
            score += 2 + 6;
        }
        if(a == 'B' && b == 'X'){ // paper -> lose
            score += 1 + 0;
        }
        if(a == 'B' && b == 'Y'){ // paper -> draw
            score += 2 + 3;
        }
        if(a == 'B' && b == 'Z'){ // paper -> win
            score += 3 + 6;
        }
        if(a == 'C' && b == 'X'){ // scissors -> lose
            score += 2 + 0;
        }
        if(a == 'C' && b == 'Y'){ // scissors -> draw
            score += 3 + 3;
        }
        if(a == 'C' && b == 'Z'){ // scissors -> win
            score += 1 + 6;
        }
    }
    printf("%d\n", score);
    return EXIT_SUCCESS;
}

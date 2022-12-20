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
        if(a == 'A' && b == 'X'){ // rock vs rock
            score += 1 + 3;
        }
        if(a == 'A' && b == 'Y'){ // rock vs paper
            score += 2 + 6;
        }
        if(a == 'A' && b == 'Z'){ // rock vs scissors
            score += 3 + 0;
        }
        if(a == 'B' && b == 'X'){ // paper vs rock
            score += 1 + 0;
        }
        if(a == 'B' && b == 'Y'){ // paper vs paper
            score += 2 + 3;
        }
        if(a == 'B' && b == 'Z'){ // paper vs scissors
            score += 3 + 6;
        }
        if(a == 'C' && b == 'X'){ // scissors vs rock
            score += 1 + 6;
        }
        if(a == 'C' && b == 'Y'){ // scissors vs paper
            score += 2 + 0;
        }
        if(a == 'C' && b == 'Z'){ // scissors vs scissors
            score += 3 + 3;
        }
    }
    printf("%d\n", score);
    return EXIT_SUCCESS;
}

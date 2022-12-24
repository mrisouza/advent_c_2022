#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#include "stack.h"

int main(int argc, char** argv){
    if(argc != 3){
        printf("no input given...\n");
        exit(EXIT_FAILURE);
    }
    
    char* fpath = argv[1];
    char* fpath_2 = argv[2];
    FILE* pfile = fopen(fpath, "r");
    FILE* pfile_2 = fopen(fpath_2, "r");

    if(pfile == NULL){
        perror("error opening the file...\n");
        exit(EXIT_FAILURE);
    }

    stack s[9];
    for(int i = 0; i < 9; i++){
        init_stack(&s[i]);
    }
    push(&s[0], 'L');
    push(&s[0], 'N');
    push(&s[0], 'W');
    push(&s[0], 'T');
    push(&s[0], 'D');
    
    push(&s[1], 'C');
    push(&s[1], 'P');
    push(&s[1], 'H');
    
    push(&s[2], 'W');
    push(&s[2], 'P');
    push(&s[2], 'H');
    push(&s[2], 'N');
    push(&s[2], 'D');
    push(&s[2], 'G');
    push(&s[2], 'M');
    push(&s[2], 'J');

    push(&s[3], 'C');
    push(&s[3], 'W');
    push(&s[3], 'S');
    push(&s[3], 'N');
    push(&s[3], 'T');
    push(&s[3], 'Q');
    push(&s[3], 'L');

    push(&s[4], 'P');
    push(&s[4], 'H');
    push(&s[4], 'C');
    push(&s[4], 'N');

    push(&s[5], 'T');
    push(&s[5], 'H');
    push(&s[5], 'N');
    push(&s[5], 'D');
    push(&s[5], 'M');
    push(&s[5], 'W');
    push(&s[5], 'Q');
    push(&s[5], 'B');

    push(&s[6], 'M');
    push(&s[6], 'B');
    push(&s[6], 'R');
    push(&s[6], 'J');
    push(&s[6], 'G');
    push(&s[6], 'S');
    push(&s[6], 'L');

    push(&s[7], 'Z');
    push(&s[7], 'N');
    push(&s[7], 'W');
    push(&s[7], 'G');
    push(&s[7], 'V');
    push(&s[7], 'B');
    push(&s[7], 'R');
    push(&s[7], 'T');

    push(&s[8], 'W');
    push(&s[8], 'G');
    push(&s[8], 'D');
    push(&s[8], 'N');
    push(&s[8], 'P');
    push(&s[8], 'L');

    //print(s);

    int qty, from, to;
    char c[100];
    char d[100];
    char e[100];
    
    while(fscanf(pfile_2, "%s %d %s %d %s %d", c, &qty, d, &from, e, &to) != EOF){
        from--;
        to--;
        while(qty > 0){
            char rem = pop(&s[from]);
            push(&s[to], rem);
            qty--;
        }
    }

    //print(s);
    for(int i = 0; i < 9; i++){
        printf("%c", pop(&s[i]));
    }
    printf("\n");
    fclose(pfile);
    fclose(pfile_2);
    return EXIT_SUCCESS;
}

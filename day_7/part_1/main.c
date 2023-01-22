#include <stdio.h>
#include <stdlib.h>
#include "file_handler.h"

#define MAX 10000

int main(int argc, char** argv){
    FILE* pfile = get_input(argc, argv);
    char line[MAX];
    enum types_of_lines {COMMAND, NON_COMMAND};
    
    while(fgets(line, MAX, pfile) != NULL){
        int type_of_line = treat_line(line);
        if(type_of_line == COMMAND){
            printf("Linha de comando.\n");
        } else {
            printf("Não é linha de comando.\n");
        }
    }
    
    fclose(pfile); 
    return EXIT_SUCCESS;
}

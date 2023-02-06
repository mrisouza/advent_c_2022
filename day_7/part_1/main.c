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
            printf("command line.\n");
        } else {
            printf("not command line.\n");
        }
    }
    
    fclose(pfile); 
    return EXIT_SUCCESS;
}

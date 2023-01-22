#include "file_handler.h"

FILE* get_input(int argc, char** argv){
    if(argc != 2){
        printf("No input was given...\n");
        exit(EXIT_FAILURE);
    }
    char* fpath = argv[1];
    FILE* pfile = fopen(fpath, "r");
    if(pfile == NULL){
        perror("Could not open file...\n");
        exit(EXIT_FAILURE);
    } else {
        return pfile;
    }
}

int treat_line(char line[]){
    enum {COMMAND, NON_COMMAND};
    if(line[0] == '$'){
        return COMMAND;
    } else {
        return NON_COMMAND;
    }
}

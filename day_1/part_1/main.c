#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    char* filepath = argv[1];
    FILE* pfile = fopen(filepath, "r");
    char line[MAX];
    int cals[MAX];
    int i = 0;
    cals[0] = 0;
    /* read and store from file */
    while (fgets(line, sizeof(line), pfile)){
        if(line[0] != '\n'){
            cals[i] += strtol(line, NULL, 10);
        } else {
            i++;
            cals[i] = 0;
        }
    }
    i++;
    int max_cal = 0;
    for(int j = 0; j < i; j++){
        if(cals[j] > max_cal){
            max_cal = cals[j];
        }
    }
    printf("%d\n", max_cal);
    fclose(pfile);
    return EXIT_SUCCESS;
}

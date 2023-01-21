#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100000
#define MARKER_DELIM 14

bool check_markers(char signals[], int i);

int main(int argc, char** argv){
    if(argc != 2){
        exit(EXIT_FAILURE);
    }
    char* fpath = argv[1];
    FILE* pfile = fopen(fpath, "r");
    
    if(pfile == NULL){
        perror("Could not open file...");
        exit(EXIT_FAILURE);
    }

    char signals[MAX];
    int c;
    int i = 0;

    while((c = getc(pfile))!= EOF){
        signals[i] = c;
        i++;
    }
    i = 0;
    while(signals[i + MARKER_DELIM - 1] != '\0'){
        //printf("%d\n", i);
        bool result = check_markers(signals, i);
        if(!result){
            printf("%d\n", i + MARKER_DELIM);
            break;
        }
        i++;
    }
    return EXIT_SUCCESS;
}

bool check_markers(char signals[], int i){
    int j = MARKER_DELIM - 1;
    while(j != 0){
        for(int k = 1; k <= j; k++){
            //printf("signals[%d] == signals[%d]\n", i , i + k);
            if(signals[i] == signals[i+k]){
                return true;
            }
        }
        j--;
        i++;
    }
    return false;
}

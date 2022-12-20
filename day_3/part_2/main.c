#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int string_size(char s[]);

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
    char lines[3][MAX];
    int total_char[3];
    char repeat[MAX];
    int i = 0;
    int total = 0;
    while(fscanf(pfile, "%s", lines[i % 3]) != EOF){
        total_char[i % 3] = string_size(lines[i % 3]);
        if(i % 3 == 2){
            // check first and second lines
            int m = 0;
            int loops = 0;
            for(int j = 0; j < total_char[0]; j++){
                for(int k = 0; k < total_char[1]; k++){
                    if(lines[0][j] == lines[1][k]){
                        repeat[m] = lines[0][j];
                        m++;
                    }
                }
                for(int n = 0; n < m; n++){
                    for(int p = 0; p < total_char[2]; p++){
                        if(repeat[n] == lines[2][p] && loops == 0){
                            if(islower(repeat[n])){
                                total += repeat[n] + 1 - 'a';
                            }
                            if(isupper(repeat[n])){
                                total += repeat[n] + 1 + 26 - 'A';
                            }
                            loops++;
                        }
                    }
                }
            }
        }
        i++;
    }
    printf("%d\n", total);
    return EXIT_SUCCESS;
}

int string_size(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

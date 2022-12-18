#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

int string_size(char s[]){
    int i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return i;
}

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
    char line[MAX];
    int total = 0;
    while(fscanf(pfile, "%s", line) != EOF){
        int total_char = string_size(line);
        int repeat = 0;
        for(int i = 0; i < (int) total_char / 2; i++){
            for(int j = (int) total_char / 2; j < total_char; j++){
                if(line[i] == line[j] && repeat == 0){
                    repeat += 1;
                    if(islower(line[i])){
                        total += line[i] + 1 - 'a';
                    }
                    if(isupper(line[i])){
                        total += line[i] + 1 + 26 - 'A';
                    }
                }
            }
        }
    }
    printf("%d\n", total);
    return EXIT_SUCCESS;
}

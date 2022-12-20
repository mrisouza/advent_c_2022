#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

void swap(int arr[], int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp; 
}

void order_array(int arr[], int sz){
    int i = 0;
    while(i < sz){
        for(int j = i; j < sz; j++){
            if(arr[j] > arr[i]){
                swap(arr, i, j);
            }
        }
        i++;
    }
}

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
    order_array(cals, i);
    int max_cal = cals[0] + cals[1] + cals[2];
    printf("%d\n", max_cal);
    fclose(pfile);
    return EXIT_SUCCESS;
}

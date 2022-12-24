#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

/* Initialization */
void init_stack(stack* s){
    s->top = 0;
}

/* Status */
bool is_full(stack* s){
    return s->top >= MAXSTACK;
}

bool is_empty(stack* s){
    return s->top <= 0;
}

void push(stack* s, char item){
    if(is_full(s)){
        printf("stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    s->entry[s->top++] = item;
}

char pop(stack* s){
    if(is_empty(s)){
        printf("stack is empty.\n");
        exit(EXIT_FAILURE);
    }
    return s->entry[--s->top];
}

void print(stack s[]){
    int max = MAXSTACK;
    while(max > 0){
        max--;

        char el_0 = ((s[0].top - 1) < max) ? ' ' : s[0].entry[max];
        char el_1 = ((s[1].top - 1) < max) ? ' ' : s[1].entry[max];
        char el_2 = ((s[2].top - 1) < max) ? ' ' : s[2].entry[max];
        char el_3 = ((s[3].top - 1) < max) ? ' ' : s[3].entry[max];
        char el_4 = ((s[4].top - 1) < max) ? ' ' : s[4].entry[max];
        char el_5 = ((s[5].top - 1) < max) ? ' ' : s[5].entry[max];
        char el_6 = ((s[6].top - 1) < max) ? ' ' : s[6].entry[max];
        char el_7 = ((s[7].top - 1) < max) ? ' ' : s[7].entry[max];
        char el_8 = ((s[8].top - 1) < max) ? ' ' : s[8].entry[max];

        printf("[%c]\t[%c]\t[%c]\t[%c]\t[%c]\t[%c]\t[%c]\t[%c]\t[%c]\n", el_0, el_1, el_2, el_3, el_4, el_5, el_6, el_7, el_8);
    }
}

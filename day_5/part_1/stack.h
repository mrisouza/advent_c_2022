#pragma once

#define MAXSTACK 56

typedef struct Stack {
    int top;
    char entry[MAXSTACK];
} stack;

void init_stack(stack* s);
void push(stack* s, char item);
char pop(stack* s);
void print(stack s[]);

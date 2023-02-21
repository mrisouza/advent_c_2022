#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "grid.h"

void init_grid(grid* g){
    for(int i = 0; i < MAXR; i++){
        for(int j = 0; j < MAXC; j++){
            g->t[i][j].r = i;
            g->t[i][j].c = j;
            g->t[i][j].h = 0;
            if(i == 0 || i == MAXR - 1 || j == 0 || j == MAXC - 1){
                g->t[i][j].is_visible = true;
            } else {
                g->t[i][j].is_visible = false;
            }
        }
    }
}

void print_grid(grid* g){
    for(int r_ = 0; r_ < MAXR; r_++){
        for(int c_ = 0; c_ < MAXC; c_++){
            if(g->t[r_][c_].is_visible){
                printf("V");
            } else {
                printf("%d", g->t[r_][c_].h);
            }
        }
        printf("\n");
    }
}

void fill_grid(FILE* pfile, grid* g){
    int ch;
    int r = 0;
    int c = 0;
    while((ch = getc(pfile)) != EOF){
        if(ch == '\n'){
            r++;
            c = 0;
        } else {
            g->t[r][c].h = ch - '0';
            c++;
        }
    }
}

bool is_visible_top(grid* g, int r, int c){
    int r_height = g->t[r][c].h;
    while(r > 0){
        r--;
        //printf("Comparing %d -> %d\n", r_height, g->t[r][c].h);
        if(g->t[r][c].h >= r_height){
            return false;
        }
    }
    return true;
}

bool is_visible_bottom(grid* g, int r, int c){
    int r_height = g->t[r][c].h; 
    while(r < MAXR - 1){
        r++;
        //printf("Comparing %d -> %d\n", r_height, g->t[r][c].h);
        if(g->t[r][c].h >= r_height){
            return false;
        }
    }
    return true;
}

bool is_visible_left(grid* g, int r, int c){
    int r_height = g->t[r][c].h; 
    while(c > 0){
        c--;
        //printf("Comparing %d -> %d\n", r_height, g->t[r][c].h);
        if(g->t[r][c].h >= r_height){
            //printf("not visible\n");
            return false;
        }
    }
    //printf("visible\n");
    return true;
}

bool is_visible_right(grid* g, int r, int c){
    int r_height = g->t[r][c].h; 
    while(c < MAXR - 1){
        c++;
        //printf("Comparing %d -> %d\n", r_height, g->t[r][c].h);
        if(g->t[r][c].h >= r_height){
            //printf("not visible\n");
            return false;
        }
    }
    //printf("visible\n");
    return true;
}

bool is_visible(grid* g, int r, int c){
    bool top = is_visible_top(g, r, c);
    bool bottom = is_visible_bottom(g, r, c);
    bool left = is_visible_left(g, r, c);
    bool right = is_visible_right(g, r, c);

    if(top || bottom || left || right){
        return true;
    } else {
        return false;
    }
}

void fill_visibility(grid* g){
    for(int r = 1; r < MAXR - 1; r++){
        for(int c = 1; c < MAXC - 1; c++){
            if(is_visible(g, r, c)){
                g->t[r][c].is_visible = true;
            } else {
                g->t[r][c].is_visible = false;
            }
        }
    } 
}

int count_visible(grid* g){
    int num_vis = 0;
    for(int r = 0; r < MAXR; r++){
        for(int c = 0; c < MAXC; c++){
            if(g->t[r][c].is_visible){
                num_vis++;
            }
        }
    }
    return num_vis;
}

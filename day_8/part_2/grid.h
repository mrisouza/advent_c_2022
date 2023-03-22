#pragma once

#define MAXR 99
#define MAXC 99

typedef struct Tree {
    int r;
    int c;
    int h;
    bool is_visible;
} tree;

typedef struct Grid {
    tree t[MAXR][MAXC];
} grid;

void init_grid(grid* g);
void print_grid(grid* g);
void fill_grid(FILE* pfile, grid* g);
void fill_visibility(grid* g);
bool is_visible(grid* g, int r, int c);
bool is_visible_top(grid* g, int r, int c);
bool is_visible_bottom(grid* g, int r, int c);
bool is_visible_left(grid* g, int r, int c);
bool is_visible_right(grid* g, int r, int c);
int count_visible(grid* g);
int scenic_spot(grid* g);

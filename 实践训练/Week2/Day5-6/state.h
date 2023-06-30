#ifndef STATE_H_
#define STATE_H_
#include "suan_png.h"
#include "pxl.h"


struct State {
    int width;
    int height;
    int industry[5000];//工业产值数组
};

// function
void init_State(struct State *s);
void delete_State(struct State *s);
void assign(struct State *a, struct State *b);
void parse(struct State *s, struct PNG *p);
int solve1(struct State *s);
int solve2(struct State *s);

#endif
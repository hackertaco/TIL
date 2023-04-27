
// Min, Max 한 번에 구하기
//.h
#ifndef SHAPE_H
#define SHAPE_H


typedef struct {
    int x;
    int y;
}point_t;

typedef struct {
    point_t start;
    point_t end;
}line_t;

typedef struct {
    point_t top_left;
    point_t bottom_right;
}rectangle_t;

rectangle_t build_rectangle(point_t p0, point_t p1);

int get_line_length_sq(line_t line);
int get_rectangle_area(rectangle_t rect);

#endif

// .c
#include <assert.h>
#include <stddef.h>
#include "shape.h"


rectangle_t build_rectangle(point_t p0, point_t p1)
{
    rectangle_t rect;
    if(p0.x < p1.x){
        rect.top_left.x = p0.x;
        rect.bottom_right.x = p1.x;
    }else{
        rect.top_left.x = p1.x;
        rect.bottom_right.x = p0.x;
    }

    if(p0.y < p1.y){
            rect.top_left.y = p0.y;
            rect.bottom_right.y = p1.y;
        }else{
            rect.top_left.y = p1.y;
            rect.bottom_right.y = p0.y;
        }


}

int get_line_length_sq(line_t line)
{
    int x_diff;
    int y_diff;

    x_diff = line.end.x - line.start.x;
    y_diff = line.end.y - line.end.y;

    return x_diff * x_diff + y_diff * y_diff;

}
int get_rectangle_area(rectangle_t rect)
{
    int w;
    int h;

    w = abs(rect.bottom_right.x - rect.top_left.x);
    h = abs(rect.bottom_right.y - rect.top_left.y);

    return w*h;
}

// main

#include <stdio.h>
#include "shape.h"

int main(void)
{
    point_t p0;
    point_t p1;
    line_t line0;
    line_t line1;
    rectangle_t rect;


}



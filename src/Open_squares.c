#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "./../include/Grid.h"
#include "./../include/Result.h"
#include "./../include/Open_squares.h"

Open_squares * open_squares_init() {
    // initialize size to 4;
    Open_squares * os = (Open_squares *)malloc(sizeof(Open_squares));
    check_null((void *)os , "could not allocate memory for Open Squares");
    os->arr = (Coordinate *)malloc(sizeof(Coordinate) * 4);
    check_null((void *)os->arr , "could not allocate arr in struct Open squares");
    os->size = 4;

    os->arr[0].x = ROWS / 2 - 1 ;
    os->arr[0].y = COLS / 2;
    os->arr[1].x = ROWS / 2;
    os->arr[1].y = COLS / 2 - 1;
    os->arr[2].x = ROWS / 2; 
    os->arr[2].y = COLS / 2 + 1; 
    os->arr[3].x = ROWS / 2 + 1;
    os->arr[3].y = COLS / 2;
    // open_squares_print(os);
    return os;
}

void open_squares_push(Open_squares *open_squares, Coordinate coordinate) {
    open_squares->size++;
    open_squares->arr = (Coordinate*)realloc(open_squares->arr, open_squares->size * sizeof(Coordinate));
    open_squares->arr[open_squares->size - 1] = coordinate;
}


void open_squares_delete(Open_squares *open_squares, Coordinate coordinate) {
    for (int i = 0; i < open_squares->size; i++) {
        if (open_squares->arr[i].x == coordinate.x && open_squares->arr[i].y == coordinate.y) {
            // Shift all elements after the removed element to the left
            for (int j = i; j < open_squares->size - 1; j++) {
                open_squares->arr[j] = open_squares->arr[j+1];
            }
            // Decrease the size of the array
            open_squares->size--;
            open_squares->arr = (Coordinate*)realloc(open_squares->arr, open_squares->size * sizeof(Coordinate));
            return;
        }
    }
}

Result open_squares_search(Open_squares *os, Coordinate position) {
    for (int i = 0; i < os->size; i++)
    {
        if (position.x == os->arr[i].x && position.y  == os->arr[i].y) {
            return VALID_GRID_POSTION;
        }
    }
    
    return INVALID_GRID_POSTION;
}


void open_squares_print(Open_squares *os) {
    printf("size open squares = %d\n" , os->size);
    for (int i = 0; i < os->size; i++)
    {
        printf(" {%d , %d} | " , os->arr[i].x , os->arr[i].y);
    }
    
    printf("\n");
}

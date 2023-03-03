#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "./../include/Grid.h"
#include "./../include/Result.h"
#include "./../include/Open_squares.h"


Open_squares *open_squares_init() {
     Open_squares * os = (Open_squares *)malloc(sizeof(Open_squares));
    check_null((void *)os , "could not allocate memory for Open Squares");
    os->arr = (Square_info *)malloc(sizeof(Square_info) * 4);
    check_null((void *)os->arr , "could not allocate arr for open_squares info  in struct Open squares");
    os->size = 4;
   
    // CONFIGURE THE INFO FOR SQUARE ON THE LEFT TO THE SPECIAL TILE
    os->arr[0].coor.x = ROWS / 2; 
    os->arr[0].coor.y = COLS / 2 - 1; 
    os->arr[0].edge_land_arr = (Edge_land *)malloc(sizeof(Edge_land) * 1); 
    os->arr[0].edge_land_arr[0].border = RIGHT;
    os->arr[0].edge_land_arr[0].landscape = ROAD;

   
    // CONFIGURE THE INFO FOR SQUARE ON THE TOP TO THE SPECIAL TILE
    os->arr[1].coor.x = ROWS / 2 - 1; 
    os->arr[1].coor.y = COLS / 2; 
    os->arr[1].edge_land_arr = (Edge_land *)malloc(sizeof(Edge_land) * 1); 
    os->arr[1].edge_land_arr[0].border = TOP;
    os->arr[1].edge_land_arr[0].landscape = VILLAGE;


   
    // CONFIGURE THE INFO FOR SQUARE ON THE RIGHT TO THE SPECIAL TILE
    os->arr[2].coor.x = ROWS / 2; 
    os->arr[2].coor.y = COLS / 2 + 1; 
    os->arr[2].edge_land_arr = (Edge_land *)malloc(sizeof(Edge_land) * 1); 
    os->arr[2].edge_land_arr[0].border = LEFT;
    os->arr[2].edge_land_arr[0].landscape = ROAD;


   
    // CONFIGURE THE INFO FOR SQUARE ON THE BOTTOM TO THE SPECIAL TILE
    os->arr[3].coor.x = ROWS / 2 + 1; 
    os->arr[3].coor.y = COLS / 2; 
    os->arr[3].edge_land_arr = (Edge_land *)malloc(sizeof(Edge_land) * 1); 
    os->arr[3].edge_land_arr[0].border = TOP;
    os->arr[3].edge_land_arr[0].landscape = CLOISTER;

    return os;
}

void open_squares_push(Open_squares *open_squares, Square_info info_square) {
    open_squares->size++;
    open_squares->arr = (Square_info*)realloc(open_squares->arr, open_squares->size * sizeof(Square_info));
    open_squares->arr[open_squares->size - 1] = info_square;
}

void open_squares_delete(Open_squares *open_squares, Square_info square) {
    for (int i = 0; i < open_squares->size; i++) {
        if (open_squares->arr[i].coor.x == square.coor.x && open_squares->arr[i].coor.y == square.coor.y) {
            // Shift all elements after the removed element to the left
            for (int j = i; j < open_squares->size - 1; j++) {
                open_squares->arr[j] = open_squares->arr[j+1];
            }
            // Decrease the size of the array
            open_squares->size--;
            open_squares->arr = (Square_info*)realloc(open_squares->arr, open_squares->size * sizeof(Square_info));
            return;
        }
    }
}

Result open_squares_search(Open_squares *os, Square_info square) {
    for (int i = 0; i < os->size; i++)
    {
        if (square.coor.x == os->arr[i].coor.x && square.coor.y == os->arr[i].coor.y) {
            return VALID_GRID_POSTION;
        }
    }
    
    return INVALID_GRID_POSTION;
}


void open_squares_print(Open_squares *os) {
    printf("size open squares = %d\n" , os->size);
    for (int i = 0; i < os->size; i++)
    {
        printf(" {%d , %d} " , os->arr[i].coor.x , os->arr[i].coor.y);
        
    }
    
    printf("\n");
}

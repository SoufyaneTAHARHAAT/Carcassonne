#ifndef OPEN_SQUARES_H
#define OPEN_SQUARES_H


#include "coordinate.h"
#include "Result.h"





// struct  {
//     Coordinate coor;
//     Edge land *EL;
// } 

// /*
//     [
//     {x0 , y0 , {right = route} }, 
//     {x1 , y1  , {left = free , top = free , right = pre , bottom = free} },
//     {X2 , Y2 , {left = free , top = free , right = route , bottom = free} },
//     {X3 , Y3 , {left = free , top = village , right = route , bottom = pre}  }
//     ];
// */



struct Open_squares_t {
    Coordinate *arr;
    int size;
};
typedef struct Open_squares_t Open_squares;


// taks the position of the first special Tile
Open_squares * open_squares_init();
void open_squares_push(Open_squares *open_squares, Coordinate coordinate);
void open_squares_delete(Open_squares *open_squares, Coordinate coordinate);
Result open_squares_search(Open_squares *os, Coordinate position); 
void open_squares_print(Open_squares *os);

#endif












#ifndef MEEPLE_H
#define MEEPLE_H

#include "coordinate.h"
#include "Tile.h"


struct Border_land_t;
typedef struct Border_land_t Border_land;


// create enum with IN and OUT
enum Meeple_State_t {
    IN_GRID,
    OUT_GRID
}; typedef enum Meeple_State_t Meeple_state;

// create enum with the colors green, red, blue, yellow and black
enum Color_t {
    GREEN,
    RED,
    BLUE,
    YELLOW,
    BLACK
}; typedef enum Color_t Color;


struct Meeple {
    // int id_meeple; we think that state is enough for the moment
    Meeple_state state;
    Coordinate position;
    Color color;
};

typedef struct Meeple Meeple;

Meeple * meeple_create(Color c);

#endif

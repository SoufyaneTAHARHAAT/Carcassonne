#ifndef MEEPLE_H
#define MEEPLE_H

#include "coordinate.h"

// create enum iwth IN and OUT
enum Meeple_State_t {
    IN,
    OUT
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
    int id_meeple;
    Meeple_state state;
    Coordinate position;
    Color color;
};

typedef struct Meeple Meeple;

#endif
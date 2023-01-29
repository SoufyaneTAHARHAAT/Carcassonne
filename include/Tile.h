#ifndef TILE_H
#define TILE_H

#include "coordinate.h"
#include "Meeple.h"

enum State_t {
    PLAYED,
    ON_HOLD, // STILL IN STACK OF TILES
}; typedef enum State_t Tile_state;

enum Borders_t {
    TOP,
    RIGHT,
    BOTTOM,
    LEFT,
    CENTER,
}; typedef enum Borders_t Borders;

enum  Landscape_t {
    ROAD,
    CITY,
    FIELD
}; typedef enum Landscape_t Landscape;

struct Border_land_t {
    Borders border;
    Landscape Landscape;
}; typedef struct Border_land_t Border_land;

// create struct for the tiles
struct Tile {
    int id_tile;
    Border_land borders[5];
    Tile_state tile_state;

};
typedef struct Tile Tile;

#endif
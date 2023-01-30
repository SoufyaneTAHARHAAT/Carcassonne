
#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Meeple.h"
#include "Tile.h"

struct Player {
    int id_player;
    Color player_color;
    char * name;
    short age;
    bool turn_to_play;
    unsigned short score;
    Tile* tiles;
};
typedef struct Player Player;

#endif

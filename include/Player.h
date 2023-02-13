
#ifndef PLAYER_H
#define PLAYER_H
#include <stdbool.h>
#include "Meeple.h"
#include "Tile.h"

struct Player_t {
    int id_player;
    Color player_color;
    char * name;
    short age;
    bool turn_to_play;
    unsigned short score;
    Tile* tiles_history; // to consider later nchllh
};
typedef struct Player_t Player;

Player * player_init(Color player_color  , char *name , short age);

#endif

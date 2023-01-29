// create template for the player

// create template for the player
#ifndef PLAYER_H
#define PLAYER_H
#include "Meeple.h"
#include <stdbool.h>

struct Player {
    int id_player;
    Color player_color;
    char * name;
    bool turn_to_play;
    unsigned short score;
    // Tiles* tiles;
};
typedef struct Player Player;

#endif

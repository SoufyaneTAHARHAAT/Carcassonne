#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include "Stuck.h"

enum State_g{
    UNFINISHED,
    FINISHED
};
typedef enum State_g State_game;

struct Game{
    int * id_players; // pointer to an array contains id players
    Grid * G; // pointer to the grid
    Stuck * S; // pointer to the stuck of tiles
    State_game state_game;

};


#endif
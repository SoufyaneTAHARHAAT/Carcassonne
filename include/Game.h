#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include "Stack.h"

enum State_g{
    UNFINISHED,
    FINISHED
};
typedef enum State_g State_game;

struct Game{
    int * id_players; // pointer to an array contains id players
    Grid * G; // pointer to the grid
    Stack * S; // pointer to the stack of tiles
    State_game state_game;

};


#endif
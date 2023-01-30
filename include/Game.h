#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include "Grid.h"
#include "Stack.h"

enum State_g{
    UNFINISHED,
    FINISHED
};
typedef enum State_g Game_state;

struct Game{
    int * id_players; // pointer to an array contains id players
    Grid * grid; // pointer to the grid
    Stack * stack; // pointer to the stack of tiles
    Game_state game_state;

};
 


Game * init_game(int *id_players , Grid * grid , Stack *stack);


#endif
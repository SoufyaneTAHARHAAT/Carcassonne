
#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Player.h"
#include "./../include/Grid.h"
#include "./../include/Stack.h"
#include "./../include/Result.h"



Game * game_init(Player * players_arr[MAX_PLAYERS] , Grid * g , Stack *s , __u_int num_players){
    Game * game = (Game *)malloc(sizeof(Game));
    check_null((void *)game , "could not allocate memory for Game struct");
    game->game_state = UNFINISHED;
    game->grid = g;
    game->stack = s;
    game->num_players = num_players;
    // game->players = &(players_arr[0]); //does not work
    if(num_players > (int)MAX_PLAYERS) {
        printf("number of players in the game should be less than %d\n" , MAX_PLAYERS);
        exit(EXIT_FAILURE);
    }
    // game_get_players(game->players , num_players);
    for (int i = 0; i < (int)num_players; i++)
    {
        game->players[i] = players_arr[i];
    }
    // when number of players < MAX_players
    for (int i = (int)num_players; i < MAX_PLAYERS; i++)
    {
        game->players[i] = NULL;
    }
    
    // make the first player true to true;

    game->players[0]->turn_to_play = true;
    
    return game;
}

void print_error(Result result) {
    switch (result) {
        case OK:
            printf("OK.\n");
            break;
        case EMPTY_STACK:
            printf("The stack is empty.\n");
            break;
        case INVALID_TURN:
            printf("Invalid turn.\n");
            break;
        case VALID_GRID_POSTION:
            printf("The position is valid on the grid.\n");
            break;
        case INVALID_GRID_POSTION:
            printf("The position is invalid on the grid.\n");
            break;
        case MATCHING_BORDERS:
            printf("The borders match.\n");
            break;
        case UNMATCHING_BORDERS:
            printf("The borders do not match.\n");
            break;
        default:
            printf("Unknown error.\n");
            break;
    }
};
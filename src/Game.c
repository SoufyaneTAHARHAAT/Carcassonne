
#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Player.h"
#include "./../include/Grid.h"
#include "./../include/Stack.h"



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
    for (int i = (int)num_players; i < MAX_PLAYERS; i++)
    {
        game->players[i] = NULL;
    }
    
    
    return game;
}

/*void game_get_players(Player * plyayers_arr[MAX_PLAYERS] , __u_int num_players) {
    for (int i = 0; i < num_players; i++)
    {
        // what am doing does not make any sense
    }
    
};*/
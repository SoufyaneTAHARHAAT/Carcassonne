#include <stdio.h>
#include <stdlib.h>
#include "./../include/Stack.h"
#include "./../include/Grid.h"
#include "./../include/Game.h"
#include "./../include/Player.h"

int main() { 
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  Grid *g = grid_create();
  read_tiles_file(filename, s);
  stack_mix(s);
  stack_summary(s);
  // create Players 

  Player * p1 = player_create(RED , "zineddine" , 26);
  Player * p2 = player_create(GREEN , "soufyane" , 26);

  Player * players_arr[5] = {p1 , p2 , NULL , NULL , NULL};

  // player_show(p1);
  // player_show(p2);
  Game * gm = game_init(players_arr , g , s, 2);
  
  for (int i = 0; i < gm->num_players ;i++)
  {
      player_show(gm->players[i]);
  }
  


  return 0;
}

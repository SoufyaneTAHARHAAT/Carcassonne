#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Grid.h"
#include "./../include/Grid_Validator.h"
#include "./../include/Open_squares.h"
#include "./../include/Player.h"
#include "./../include/Stack.h"
#include "./../include/Valid_squares.h"
#include "./../include/Road_construction.h"

int main(void) {
  char *filename = "docs/list_tiles.csv";
  Stack *s = stack_create();
  Grid *g = grid_create();
  read_tiles_file(filename, s);
  // tile_print(s->head->t);
  //  stack_shuffle(s);
  //  stack_summary(s);
  // stack_summary(s);
  // stack_show(s);
  Player *p1 = player_create(RED, "zineddine", 26, HUMAN);
  Player *p2 = player_create(GREEN, "soufyane", 26, AI);
  Player *p3 = player_create(BLACK, "manel", 26, HUMAN);
  Player *p4 = player_create(BLUE, "khireddine", 26, AI);
  Player *p5 = player_create(YELLOW, "Jedda", 26, AI);

  Player *players_arr[5] = {p1, p2, p3, p4, p5};
  Game *gm = game_init(players_arr, g, s, 5);
  for (int i = 0; i < (int)gm->num_players; i++) {
    // player_show(gm->players[i]);
  }
  int player_index_turn = 0;
  Open_squares *os = open_squares_init();
  Valid_squares *vs = valid_squares_init();
  Roads_construction *rd = roads_construction_init();
  // Roads_construction_print(rd);
  printf("--------------------------------------------------\n");
  // grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);
  // open_squares_print(os);
  while (true) {
    /* SHOW  INFO ABOUT THE GAME */
    // player_show(players_arr[player_index_turn]);
    /*------- START POP STACK FROM THE TILE ----------*/
    open_squares_print(os);
    
    Tile *t = stack_pop(s);
    // stack_show(s);
    printf("\n\tTILE POPPED FROM STACK\n");
    tile_print(t);
    /*------- END POP STACK FROM THE TILE ----------*/

    /*------- START SUGGEST VALID SQUARES ----------*/
    valid_squares_update(vs, os, t);
    valid_squares_print(vs);
    Coordinate pos = game_suggest_valid_squares(vs);
    int x = pos.x, y = pos.y;
    /*------- END SUGGEST VALID SQUARES ----------*/

    /*------- START SUGGEST TILE ROTATION ----------*/
    int num_rotation = game_suggest_tile_rotation(vs, x, y);
    tile_rotate(t, num_rotation);
    printf("\n\tTILE AFTER ROTATION\n");
    tile_print(t);
    /*------- END SUGGEST TILE ROTATION ----------*/

    grid_put_tile(s, g, t, players_arr[player_index_turn], x, y, os);
    /*------- START SUGGEST TO PUT MEEPLE ----------*/
    Result rs = roads_construction_update(rd, g, t, x , y);
    print_error(rs);

    int put_meeple_on = game_suggest_meeple();
    if (put_meeple_on != -1) {
      roads_construction_conquere_road(rd , players_arr[player_index_turn] , player_index_turn, x , y);
      player_move_meeple_to_grid(g, players_arr[player_index_turn], x , y , (Borders)put_meeple_on);
    }

    Roads_construction_print(rd);
    /*------- END SUGGEST TO PUT MEEPLE ----------*/


    valid_square_destory(vs);
    open_squares_update(g, os, x, y);
    grid_cut_show(g, SPECIAL_TILE_X_POS, SPECIAL_TILE_X_POS, 5);

    player_index_turn++;
    if (player_index_turn == gm->num_players) player_index_turn = 0;
   }
  return (0);
}
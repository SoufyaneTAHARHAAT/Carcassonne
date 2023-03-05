#include <stdio.h>
#include <stdlib.h>
#include "./../include/Game.h"
#include "./../include/Grid.h"
#include "./../include/Grid_Validator.h"
#include "./../include/Open_squares.h"
#include "./../include/Player.h"
#include "./../include/Stack.h"

int main(void) {
  printf("hello wolld\n");
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
  /*
   * player_show(p1);
   * player_show(p2);
   */
  Game *gm = game_init(players_arr, g, s, 5);
  for (int i = 0; i < (int)gm->num_players; i++) {
    // player_show(gm->players[i]);
  }
  Open_squares *os = open_squares_init();
  Square_info is;
  is.coor.x = 200;
  is.coor.y = 400;
  open_squares_push(os, is);
  // printf("%d\n" , s->tiles_number);
  Tile *second = stack_pop(s);
  // printf("%d\n" , s->tiles_number);
  // stack_summary(s);
  Coordinate posT = {70, 71};
  Coordinate posB = {71, 70};
  Coordinate posR = {71, 72};
  Coordinate posL = {72, 71};

  // open_squares_print(os);
  square_info_push_edge_land(os, 200, 400, TOP, ROAD);
  square_info_push_edge_land(os, 200, 400, BOTTOM, CITY);
  square_info_push_edge_land(os, 200, 400, RIGHT, CLOISTER);
  square_info_push_edge_land(os, 200, 400, LEFT, SHIELD);
  // open_squares_print(os);

  square_info_delete_edge_land(os, 200, 400, RIGHT);
  square_info_delete_edge_land(os, 200, 400, LEFT);
  square_info_delete_edge_land(os, 200, 400, BOTTOM);
  square_info_delete_edge_land(os, 200, 400, TOP);
  square_info_delete_edge_land(os, 71, 72, LEFT);
  open_squares_print(os);
  // Result resT = grid_validate_put_tile(s , second , g , p1 , posT , os);
  // Result resB = grid_validate_put_tile(s , second , g , p1 , posB , os);
  // Result resR = grid_validate_put_tile(s , second , g , p1 , posR , os);
  // Result resL = grid_validate_put_tile(s , second , g , p1 , posL , os);
  // print_error(resT);
  // print_error(resB);
  // print_error(resR);
  // print_error(resL);

  // tile_rotate(second, 2);
  // tile_print(second);
  // grid_put_tile(s, g, second, p1, posT, os);
  // grid_put_tile(s, g, second, p1, posB, os);
  // grid_put_tile(s, g, second, p1, posR, os);
  // grid_put_tile(s, g, second, p1, posL, os);

  // grid_cut_show(g, ROWS / 2, COLS / 2, 5);

  // tile_rotate(s->head->t , 2);
  // tile_print(s->head->t);

  return (0);
}

#include "./../../include/Grid_Validator.h"
#include "./../../include/Game.h"
#include "./../../include/Grid.h"
#include "./../../include/Open_squares.h"
#include "./../../include/Player.h"
#include "./../../include/Result.h"
#include "./../../include/Stack.h"
#include "./../../include/coordinate.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

Result grid_validate_put_tile(Stack *s, Tile *t, Grid *g, Player *p,
                              Coordinate position, Open_squares *os)
{
  // check if stack is empty

  if (s->tiles_number == 0)
  {
    return EMPTY_STACK;
  }

  // check if plyer's turn

  if (!p->turn_to_play)
  {
    return INVALID_TURN;
  }

  // check if positiion is included on open Saquares Array

  if ((Result)open_squares_search(os, position) == INVALID_GRID_POSTION)
  {
    return INVALID_GRID_POSTION;
  }

  // check if all borders are matching

  if ((Result)grid_validate_borders(g, t, position) == UNMATCHING_BORDERS)
  {
    return UNMATCHING_BORDERS;
  }

  return OK;
}

/*
 * We need to ckeck some cases later like if we are in the corners
 */

Result grid_validate_borders(Grid *g, Tile *t, Coordinate position)
{
  int x = position.x;
  int y = position.y;
  // LEFT with RIGHT
  if (g->tab[x][y - 1].square_state == OCCUPIED)
  {
    if (g->tab[x][y - 1].t->borders[2].landscape != t->borders[0].landscape)
    {
      printf("tile to put has landscape on the left as : ");
      landscape_print(t, 0);
      printf("\n");
      return UNMATCHING_BORDERS;
    }
  }
  // TOP with BOTTOM
  if (g->tab[x - 1][y].square_state == OCCUPIED)
  {
    if (g->tab[x - 1][y].t->borders[3].landscape != t->borders[1].landscape)
    {
      printf("tile to put has landscape on the top as : ");
      landscape_print(t, 1);
      printf("\n");
      return UNMATCHING_BORDERS;
    }
  }
  // RIGHT WITH LEFT
  if (g->tab[x][y + 1].square_state == OCCUPIED)
  {
    if (g->tab[x][y + 1].t->borders[0].landscape != t->borders[2].landscape)
    {
      printf("tile to put has landscape on the right as ");
      landscape_print(t, 2);
      printf("\n");
      return UNMATCHING_BORDERS;
    }
  }
  // BOTTOM WITH TOP
  if (g->tab[x + 1][y].square_state == OCCUPIED)
  {
    if (g->tab[x + 1][y].t->borders[1].landscape != t->borders[3].landscape)
    {
      printf("tile to put has landscape on the top as bottom ");
      landscape_print(t, 3);
      printf("\n");
      return UNMATCHING_BORDERS;
    }
  }

  return MATCHING_BORDERS;
}


Result grid_validate_left_border(Grid *g , Tile *t , Coordinate pos)  {

}

Result grid_validate_right_border(Grid *g , Tile *t , Coordinate pos) {

}

Result grid_validate_top_border(Grid *g , Tile *t , Coordinate pos) {

}

Result grid_validate_bottom_border(Grid *g , Tile *t , Coordinate pos) {

}

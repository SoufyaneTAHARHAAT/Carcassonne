#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../include/Game.h"
#include "./../../include/Grid.h"
#include "./../../include/Grid_Validator.h"
#include "./../../include/Open_squares.h"
#include "./../../include/Player.h"
#include "./../../include/Result.h"
#include "./../../include/Stack.h"
#include "./../../include/coordinate.h"

Result grid_validate_put_tile(Stack *s, Tile *t, Grid *g, Player *p, int x, int y, Open_squares *os) {
  // check if stack is empty

  if (s->tiles_number == 0) {
    return EMPTY_STACK;
  }

  // check if plyer's turn

  if (!p->turn_to_play) {
    return INVALID_TURN;
  }
  return OK;
}



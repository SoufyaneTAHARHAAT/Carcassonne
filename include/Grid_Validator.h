#ifndef GRID_VALIDATOR_H
#define GRID_VALIDATOR_H

#include <stdbool.h>
#include "Game.h"
#include "Grid.h"
#include "Meeple.h"
#include "Player.h"
#include "Stack.h"
#include "Open_squares.h"
#include "coordinate.h"
#include "Result.h"

Result grid_validate_put_tile(Stack *s, Tile *t, Grid *g, Player *p, Coordinate position , Open_squares *os);

Result grid_validate_borders(Grid *g, Tile *t , Coordinate position);


Result grid_validate_left_border(Grid *g , Tile *t , Coordinate pos) ;
Result grid_validate_right_border(Grid *g , Tile *t , Coordinate pos);
Result grid_validate_top_border(Grid *g , Tile *t , Coordinate pos);
Result grid_validate_right_border(Grid *g , Tile *t , Coordinate pos);


#endif
#ifndef GRID_VALIDATOR_H
#define GRID_VALIDATOR_H

#include <stdbool.h>
#include "Game.h"
#include "Grid.h"
#include "Meeple.h"
#include "Player.h"
#include "Stack.h"
#include "coordinate.h"
#include "Result.h"

Result grid_validate_put_tile(Stack *s , Tile *t , Grid *g , Player *p , Coordinate position);


#endif
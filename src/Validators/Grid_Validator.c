#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "./../../include/Game.h"
#include "./../../include/Player.h"
#include "./../../include/Grid.h"
#include "./../../include/Stack.h"
#include "./../../include/coordinate.h"
#include "./../../include/Result.h"

Result grid_validate_put_tile(Stack *s , Tile *t , Grid *g , Player *p , Coordinate postion) {
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
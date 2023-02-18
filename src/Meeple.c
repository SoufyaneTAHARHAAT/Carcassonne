#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "./../include/Meeple.h"
#include "./../include/Player.h"


Meeple * meeple_create(Color c){
    Meeple * mp = (Meeple *)malloc(sizeof(Meeple));
    check_null((void *)mp , "could not allocate memroy for Meeple struct");
    mp->color  = c;
    mp->position.x = mp->position.y = -1;
    mp->state = OUT_GRID;
    return mp;
}
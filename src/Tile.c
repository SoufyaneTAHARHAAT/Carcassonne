#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "./../include/Tile.h"

int id_indicator = 0;

Tile * create_tile(char arr1[], char arr2[] ,char arr3[] ,char arr4[],char arr5[]) {
    Tile * t = (Tile *)malloc(sizeof(Tile));
    if (t == NULL) {
        printf("could not allocate enough memory for strucutre Tile");
        exit(EXIT_FAILURE);
    }

    t->id_tile = ++id_indicator; // here we made a debate about starting with 0 or 1 it ended in draw
    t->tile_state = ON_HOLD;
    
    for (size_t i = 0; i < 5; i++)
    {
        Landscape l = compare(5 , i ,  arr1,  arr2 , arr3 , arr4, arr5);
        Border_land bl;
        switch (i)
        {
            case 0:
                bl.border = TOP;
                bl.Landscape = l;
                t->borders[i]= bl;
                break;
            case 1:
                bl.border = RIGHT;
                bl.Landscape = l;
                t->borders[i]= bl;
                break;
            case 2:
                bl.border = BOTTOM;
                bl.Landscape = l;
                t->borders[i]= bl;
                break;
            case 3:
                bl.border = LEFT;
                bl.Landscape = l;
                t->borders[i]= bl;
                break;
            case 4:
                bl.border = CENTER;
                bl.Landscape = l;
                t->borders[i]= bl;
                break;
        }
    }
    
    return t;
}


Landscape compare(int count , int stop ,  ...) {
  va_list args;
  va_start(args, count);

  for (int i = 0; i < count; i++) {
    if (i != stop) {
        continue;
    }
    if ( i == stop) {
        char * argument = va_arg(args, char *);
        // printf("Argument %d: %s\n", i + 1, argument);
        if (strcmp("route", argument) == 0) {
            return ROAD;
        } else if (strcmp("ville", argument) == 0) {
            return CITY;
        } else if (strcmp("blason", argument) == 0) {
            return SHIELD;
        } else if (strcmp( "village" , argument) == 0) {
            return VILLAGE;
        } else if (strcmp( "abbaye" , argument) == 0) {
            return FIELD;
        }
        else if (strcmp( "pre" , argument) == 0) {
            return CLOISTER;
        }
        break;
    }
  }
    va_end(args);
    printf("No string read from the file matched the Enum Landscap");
    exit(EXIT_FAILURE);
    return ROAD;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "./../include/Tile.h"

int id_indicator = 0;

Tile *create_tile(char arr1[], char arr2[], char arr3[], char arr4[], char arr5[])
{
    Tile *t = (Tile *)malloc(sizeof(Tile));
    if (t == NULL)
    {
        printf("could not allocate enough memory for strucutre Tile");
        exit(EXIT_FAILURE);
    }

    t->id_tile = ++id_indicator; // here we made a debate about starting with 0 or 1 it ended in draw
    t->tile_state = ON_HOLD;
    // print_args(5 , 0 , arr1, arr2, arr3, arr4, arr5);
    for (size_t i = 0; i < 5; i++)
    {
        Landscape l = compare(5, i, arr1, arr2, arr3, arr4, arr5);
        Border_land bl;
        switch (i)
        {
        case 0:
            bl.border = TOP;
            bl.landscape = l;
            t->borders[i] = bl;
            break;
        case 1:
            bl.border = RIGHT;
            bl.landscape = l;
            t->borders[i] = bl;
            break;
        case 2:
            bl.border = BOTTOM;
            bl.landscape = l;
            t->borders[i] = bl;
            break;
        case 3:
            bl.border = LEFT;
            bl.landscape = l;
            t->borders[i] = bl;
            break;
        case 4:
            bl.border = CENTER;
            bl.landscape = l;
            t->borders[i] = bl;
            break;
        }
    }
    
    return t;
} 

Landscape compare(int count, int stop, ...)
{
    va_list args;
    va_start(args, count);
    
    for (int i = 0; i < count; i++)
    {
        char *argument = va_arg(args, char *);
        if (i != stop)
        {
            continue;
        }
        if (i == stop)
        {
            if (strcmp("route", argument) == 0)
            {
                //printf("route");
                return ROAD;
            }
            else if (strcmp("ville", argument) == 0)
            {
                //printf("ville");
                return CITY;
            }
            else if (strcmp("blason", argument) == 0)
            {
                //printf("blason");
                return SHIELD;
            }
            else if (strcmp("village", argument) == 0)
            {
                //printf("village");
                return VILLAGE;
            }
            else if (strcmp("abbaye", argument) == 0)
            {
                //printf("abbaye");
                return FIELD;
            }
            else if (strcmp("pre", argument) == 0)
            {
                //printf("pre");
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

void print_args(int count, ...) {
  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; i++) {
    char * argument = va_arg(args, char *);
    printf("Argument %d: %s\n", i + 1, argument);
  }
  va_end(args);
}

void show_tile(Tile t)
{

    printf("tile id = %d\n", t.id_tile);

    for (int i = 0; i < 5; i++)
    {
        switch (t.borders[i].border)
        {
        case TOP:
            printf("borders[%d].border = %s \n", i + 1, "TOP");
            break;
        case RIGHT:
            printf("borders[%d].border = %s \n", i + 1, "RIHGT");
            break;
        case BOTTOM:

            printf("borders[%d].border = %s \n", i + 1, "BOTTM");
            break;
        case LEFT:
            printf("borders[%d].border = %s \n", i + 1, "LEFT");
            break;
        case CENTER:
            printf("borders[%d].border = %s \n", i + 1, "CENTER");
            break;
        default:
            break;
        }
        switch (t.borders[i].landscape)
        {
        case ROAD:
            printf("borders[%d].landscape = %s \n", i + 1, "ROAD");
            break;
        case CITY:
            printf("borders[%d].landscape = %s \n", i + 1, "CITY");
            break;
        case CLOISTER:

            printf("borders[%d].landscape = %s \n", i + 1, "CLOISTER");
            break;
        case FIELD:
            printf("borders[%d].landscape = %s \n", i + 1, "FIELD");
            break;
        case SHIELD:
            printf("borders[%d].landscape = %s \n", i + 1, "SHIELD");
            break;
        case VILLAGE:
            printf("borders[%d].landscape = %s \n", i + 1, "VILLAGE");
            break;
        default:
            break;
        }
    }

    if (t.tile_state == ON_HOLD) printf("tile state ON_HOLD\n"); else printf("tile state PLAYED \n");
}
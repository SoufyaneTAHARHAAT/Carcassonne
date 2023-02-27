#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>
#include "./../include/Tile.h"

int id_indicator = 0;

Tile *tile_create(char arr1[], char arr2[], char arr3[], char arr4[], char arr5[])
{
    Tile *t = (Tile *)malloc(sizeof(Tile));
    if (t == NULL)
    {
        printf("could not allocate enough memory for strucutre Tile");
        exit(EXIT_FAILURE);
    }

    t->id_tile = ++id_indicator; // here we made a debate about starting with 0 or 1 it ended in draw
    t->tile_state = ON_STACK;
    // print_args(5 , 0 , arr1, arr2, arr3, arr4, arr5);
    for (size_t i = 0; i < 5; i++)
    {
        Landscape l = compare(5, i, arr1, arr2, arr3, arr4, arr5);
        Border_land bl;
        switch (i)
        {
        case 0:
            bl.border = LEFT;
            bl.landscape = l;
            bl.meepled = false;
            t->borders[i] = bl;
            break;
        case 1:
            bl.border = TOP;
            bl.landscape = l;
            bl.meepled = false;
            t->borders[i] = bl;
            break;
        case 2:
            bl.border = RIGHT;
            bl.landscape = l;
            bl.meepled = false;
            t->borders[i] = bl;
            break;
        case 3:
            bl.border = BOTTOM;
            bl.landscape = l;
            bl.meepled = false;
            t->borders[i] = bl;
            break;
        case 4:
            bl.border = CENTER;
            bl.landscape = l;
            bl.meepled = false;
            t->borders[i] = bl;
            break;
        }
    }

    return t;
}


void tile_rotate(Tile *t , int n) {
    if (n  == 0) {
        return;
    }
    for (size_t i = 1; i <= 3; i++)
    {
    Border_land temp = t->borders[0];
        t->borders[0] = t->borders[1];
        t->borders[1]= t->borders[2];
        t->borders[2]= t->borders[3];
        t->borders[3] = temp; 
    } 
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
                // printf("route");
                return ROAD;
            }
            else if (strcmp("ville", argument) == 0)
            {
                // printf("ville");
                return CITY;
            }
            else if (strcmp("blason", argument) == 0)
            {
                // printf("blason");
                return SHIELD;
            }
            else if (strcmp("village", argument) == 0)
            {
                // printf("village");
                return VILLAGE;
            }
            else if (strcmp("abbaye", argument) == 0)
            {
                // printf("abbaye");
                return FIELD;
            }
            else if (strcmp("pre", argument) == 0)
            {
                // printf("pre");
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

void print_args(int count, ...)
{
    va_list args;
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        char *argument = va_arg(args, char *);
        printf("Argument %d: %s\n", i + 1, argument);
    }
    va_end(args);
}

void tile_print(Tile *t)
{
    printf("\n");
    printf("%12c", ' ');
    ;
    landscape_print(t, 1);
    printf("\n");
    printf("%5c", ' ');
    printf(" ---- ----- -----\n");
    printf("%5c", ' ');
    printf("|                |\n");
    printf("%5c", ' ');
    printf("|                |\n");
    printf("%5c", ' ');
    printf("|                |\n");
    landscape_print(t, 0);
    printf("%8c", ' ');
    landscape_print(t, 4);
    printf("%9c", ' ');
    ;
    landscape_print(t, 2);
    printf("\n");
    printf("%5c", ' ');
    printf("|                |\n");
    printf("%5c", ' ');
    printf("|                |\n");
    printf("%5c", ' ');
    printf("|                |\n");
    printf("%5c", ' ');
    printf(" ---- ----- -----\n");
    printf("%12c", ' ');
    ;
    landscape_print(t, 3);
    printf("\n");
}

void landscape_print(Tile *t, int l)
{

    switch (t->borders[l].landscape)
    {
    case CITY:
        printf("CITY");
        break;
    case FIELD:
        printf("FILD");
        break;
    case CLOISTER:
        printf("CLST");
        break;
    case SHIELD:
        printf("SHLD");
        break;
    case ROAD:
        printf("ROAD");
        break;
    case VILLAGE:
        printf("VLGE");
        break;
    default:
        break;
    }
}
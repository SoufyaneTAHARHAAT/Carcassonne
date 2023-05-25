#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../include/Grid.h"
#include "./../include/Player.h"
#include "./../include/Game.h"
#include "./../include/Grid_Validator.h"
Grid *grid_create()
{
  Grid *grid = (Grid *)malloc(sizeof(Grid));
  check_null((void *)grid, "could not allocate memory for the grid");
  // create special tile of start
  Tile *t = tile_create("route", "ville", "route", "pre", "route");
  t->tile_state = ON_GRID;
  tile_print(t);
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if ((i == ROWS / 2) && (j == COLS / 2))
      {
        grid->tab[i][j].square_state = OCCUPIED;
        grid->tab[i][j].t = t;
      }
      else
      {
        grid->tab[i][j].square_state = EMPTY;
        grid->tab[i][j].t = NULL;
      }
    }
  }
  return grid;
}

bool grid_put_tile(Stack *s, Grid *g, Tile *t, Player *p, int x, int y, Open_squares *os)
{

  if (grid_validate_put_tile(s, t, g, p, x, y, os) == OK)
  {
    print_error(OK);
    g->tab[x][y].square_state = OCCUPIED;
    g->tab[x][y].t = t;
    return true;
  }
  print_error(UNMATCHING_BORDERS);
  return false;
}

void grid_show(Grid *g)
{
  for (int i = 0; i < ROWS; i++)
  {
    for (int j = 0; j < COLS; j++)
    {
      if (g->tab[i][j].square_state == EMPTY)
      {
        printf("E ");
      }
      else
      {
        printf("%d ", g->tab[i][j].t->id_tile);
      }
    }
    printf("\n");
  }
}

void grid_cut_show(Grid *g, int row, int col, int dist)
{

  printf("    ");
  for (int k = col - dist; k < col + dist; k++)
  {
    printf("%d   ", k);
  }
  printf("\n");
  for (int i = row - dist; i < row + dist; i++)
  {
    printf("%d ", i);
    for (int j = col - dist; j < col + dist; j++)
    {
      if (g->tab[i][j].square_state == EMPTY)
      {
        printf("  E  ");
      }
      else
      {
        printf("  %d  ", g->tab[i][j].t->id_tile);
      }
    }
    printf("\n");
  }
}
/*
void grid_cut_show_v2(Grid *g, int row, int col)
{
  int i, j;
  int l = 7; // Assuming the rows represent the size of the grid

  for (i = 0; i < l * 3; i++)
  {
    for (j = 0; j < l * 3; j++)
    {
      if (i % 3 == 0)
      {
        if (j % 3 == 0)
        {
          printf(" ");
        }
        if (j % 3 == 1)
        {
          if (g->tab[i / 3][j / 3].square_state == EMPTY)
          {
            printf("%s", " N ");
          }
          else
          {
            printf("%s", print_landscape_v2(g->tab[i / 3][j / 3].square_state, g->tab[i / 3][j / 3].t->borders[LEFT].landscape));
          }
        }
        if (j % 3 == 2)
        {
          // We must include later the meeple
          printf(" ");
        }
      }
      if (i % 3 == 1)
      {
        if (j % 3 == 0)
        {
          if (g->tab[i / 3][j / 3].square_state == EMPTY)
          {
            printf("%s", " N ");
          }
          else
          {
            printf("%s", print_landscape_v2(g->tab[i / 3][j / 3].square_state, g->tab[i / 3][j / 3].t->borders[BOTTOM].landscape));
          }
        }
        if (j % 3 == 1)
        {
          if (g->tab[i / 3][j / 3].square_state == EMPTY)
          {
            printf("%s", " N ");
          }
          else
          {
            printf("%s", print_landscape_v2(g->tab[i / 3][j / 3].square_state, g->tab[i / 3][j / 3].t->borders[CENTER].landscape));
          }
        }
        if (j % 3 == 2)
        {
          if (g->tab[i / 3][j / 3].square_state == EMPTY)
          {
            printf("%s", " N ");
          }
          else
          {
            printf("%s", print_landscape_v2(g->tab[i / 3][j / 3].square_state, g->tab[i / 3][j / 3].t->borders[TOP].landscape));
          }
        }
      }
      if (i % 3 == 2)
      {
        if (j % 3 == 0)
          printf(" ");
        if (j % 3 == 1)
        {
          if (g->tab[i / 3][j / 3].square_state == EMPTY)
          {
            printf("%s", " N ");
          }
          else
          {
            printf("%s", print_landscape_v2(g->tab[i / 3][j / 3].square_state, g->tab[i / 3][j / 3].t->borders[RIGHT].landscape));
          }
        }
        if (j % 3 == 2)
          printf(" ");
        if (j % 3 == 2)
          printf(" ");
        else
          printf(" ");
      }
    }
    printf("\n");
  }
  printf("\n");
  for (j = 0; j < l * 3; j++)
    printf(" ");
  printf("\n");
}
*/
char * print_landscape_v2(Landscape i)
{
  switch (i)
  {
  case CITY:
    return "CTY";
    break;
  case FIELD:
    return "FLD";
    break;
  case CLOISTER:
    return "CLS";
    break;
  case SHIELD:
    return "SHL";
    break;
  case ROAD:
    return "ROD";
    break;
  case VILLAGE:
    return "VLG";
    break;
  default:
    break;
  }
}

void grid_cut_show_v3(Grid *g)
{

  for (int i = 70; i < 73; i++)
  {
    for (int j = 70; j < 71; j++)
    {
      for (int k = 0; k < 3; k++)
      {
        // we print the landscape of the top border
        if (k == 0)
        {
          printf("\t%s\t\t\t%s\t\t\t%s\n",
                 g->tab[i][j].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j].t->borders[TOP].landscape),
                 g->tab[i][j + 1].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 1].t->borders[TOP].landscape),
                 g->tab[i][j + 2].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 2].t->borders[TOP].landscape));
        }

        if (k == 1)
        {
          printf("%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\n",
                 g->tab[i][j].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j].t->borders[LEFT].landscape),
                 g->tab[i][j].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j].t->borders[CENTER].landscape),
                 g->tab[i][j].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j].t->borders[RIGHT].landscape),
                 g->tab[i][j + 1].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 1].t->borders[LEFT].landscape),
                 g->tab[i][j + 1].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 1].t->borders[CENTER].landscape),
                 g->tab[i][j + 1].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 1].t->borders[RIGHT].landscape),
                 g->tab[i][j + 2].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 2].t->borders[LEFT].landscape),
                 g->tab[i][j + 2].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 2].t->borders[CENTER].landscape),
                 g->tab[i][j + 2].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 2].t->borders[RIGHT].landscape));
        }

        if (k == 2)
        {
          printf("\t%s\t\t\t%s\t\t\t%s\n\n",
                 g->tab[i][j].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j].t->borders[BOTTOM].landscape),
                 g->tab[i][j + 1].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 1].t->borders[BOTTOM].landscape),
                 g->tab[i][j + 2].t == NULL ? "NUL" : print_landscape_v2(g->tab[i][j + 2].t->borders[BOTTOM].landscape));
        }
      }
    }
  }
}
#include "./../include/Road_construction.h"
#include "./../include/Meeple.h"
#include "./../include/Player.h"
#include "./../include/Tile.h"
#include <stdio.h>
#include <stdlib.h>

// x and y for the last put Tile
Result roads_construction_update(Roads_construction *rd, Grid *g, Tile *t, int x, int y)
{
  // // printf("calling roads_construction_update\n");
  // if (roads_construction_search_road(rd, x, y, TOP) != NULL
  //     && roads_construction_search_road(rd, x, y, BOTTOM) != NULL
  //     && roads_construction_search_road(rd, x, y, LEFT) != NULL
  //     && roads_construction_search_road(rd, x, y, RIGHT) != NULL
  //     && roads_construction_search_road(rd, x, y, CENTER) != NULL
  //   )
  // {
  //   printf("all roads are already conquered ==> the unsure condition\n");
  //   return CONQUERED_ROAD;
  // }

  int num_road = get_tile_number_of_roads(t);
  printf("number of roads is the tile is  %d \n", num_road);
  if (num_road == 0)
    return NOT_UPDATED_ROADS;
  bool center_is_road = is_center_road(t);

  // 0 means that  the first neighbor is an open square
  // 1 means that right border for the first neighbor contains a road
  Borders are_neighbors_roads[4] = {0, 0, 0, 0};

  bool temp = false;
  check_neighbors(g, x, y, are_neighbors_roads);
  printf("are_neighbors_roads array  %d %d %d %d\n", are_neighbors_roads[0], are_neighbors_roads[1],
         are_neighbors_roads[2], are_neighbors_roads[3]);

  Borders b = LEFT;
  road_search_result *res;
  Road *road;
  switch (num_road)
  {
  // if there is a road we add it an exsting one
  // otherwise create a new Road;
  case 1:
    // we look through the neighbor
    // becuase we are in case: 1 am sure there is only one road
    printf("case 1: ONE road in the tile\n");
    for (int i = 0; i < 4; i++)
    {
      if (are_neighbors_roads[i] == 1)
      {
        b = i;
        break;
      }
      if (i == 3)
        temp = true;
    }
    // we add the current road to an existing Roads_construction;
    // we must find the to wich part we add the current Road;
    if (!temp)
    {
      // why am passing x and y ?? it should be x - 1 or something
      switch (b)
      {
      case LEFT:
        res = roads_construction_search_road(rd, x, y - 1, RIGHT);
        road = res->road;
        printf("searching for road on pos x = %d and y = %d \n", x, y - 1);
        if (road != NULL)
        {
          double_linked_list_append_in_end(&road->dll->tail, b, x, y);
          printf("inserting in the tail\n");
        }
        break;
      case RIGHT:
         res = roads_construction_search_road(rd, x, y + 1, LEFT);
        road = res->road;
        printf("searching for road on pos x = %d and y = %d \n", x, y + 1);
        if (road != NULL)
        {
          double_linked_list_append_in_beg(&road->dll->head, b, x, y);
          printf("inserting in the head\n");
        }
        break;
      case TOP:
        res =  roads_construction_search_road(rd, x - 1, y, BOTTOM);
        road = res->road;
        printf("searching for road on pos x = %d and y = %d \n", x - 1, y);
        if (road != NULL)
        {
          double_linked_list_append_in_end(&road->dll->tail, b, x, y);
          printf("inserting in the tail\n");
        }
        break;
      case BOTTOM:
        res =  roads_construction_search_road(rd, x + 1, y, TOP);
        road = res->road;
        printf("searching for road on pos x = %d and y = %d \n", x + 1, y);
        if (road != NULL)
        {
          double_linked_list_append_in_beg(&road->dll->head, b, x, y);
          printf("inserting in the head\n");
        }
        break;
      case CENTER:
        printf("something went bad on roads construction update \n");
        exit(EXIT_FAILURE);
      }
    }
    else
    {
      roads_construction_add_road(rd, b, x, y);
      rd->size++;
    }

    break;
  case 2: // case of the tile having two roads
  {
    // center is road => means one continious road
    printf("case 2 : Two road in the tile\n");
    int pos_x = 0, pos_y = 0;
    if (center_is_road)
    {
      printf("case center is road\n");
      int num_neighbors_having_road = 0;
      for (int i = 0 ; i < 4; i++) if (are_neighbors_roads[i] == 1) num_neighbors_having_road++;
      for (int i = 0; i < 4; i++)
      {
        if (are_neighbors_roads[i] == 1)
        {
          switch (i)
          {
          case 0: // Left
            pos_x = x;
            pos_y = y - 1;
            res =  roads_construction_search_road(rd, pos_x, pos_y, RIGHT);
            road = res->road;
            printf("searching for road on pos x = %d and y = %d \n", pos_x, pos_y);
            if (road == NULL)
              printf("am scruid\n");
            else
            {
              if (res->ref == HEAD) {
                double_linked_list_append_in_beg(&road->dll->head, i, x, y);
                double_linked_list_append_in_beg(&road->dll->head, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_beg(&road->dll->head, j, x, y);
                  }
                }
              }

              else {
                double_linked_list_append_in_end(&road->dll->tail, i, x, y);
                double_linked_list_append_in_end(&road->dll->tail, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_end(&road->dll->tail, j, x, y);
                  }
                }
                // printf("inserting in the tail\n");
              }
            }
            break;
          case 1: // top
            pos_x = x - 1;
            pos_y = y;
            res =  roads_construction_search_road(rd, pos_x, pos_y, BOTTOM);
            road = res->road;
            printf("searching for road on pos x = %d and y = %d \n", pos_x, pos_y);
            if (road == NULL)
              printf("am scruid\n");
            else
            {
              if (res->ref == HEAD) {
                double_linked_list_append_in_beg(&road->dll->head, i, x, y);
                double_linked_list_append_in_beg(&road->dll->head, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_beg(&road->dll->head, j, x, y);
                  }
                }
              }

              else {
                double_linked_list_append_in_end(&road->dll->tail, i, x, y);
                double_linked_list_append_in_end(&road->dll->tail, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_end(&road->dll->tail, j, x, y);
                  }
                }
                // printf("inserting in the tail\n");
              }
            }
            break;
          case 2: // right
            pos_x = x;
            pos_y = y + 1;
            res =  roads_construction_search_road(rd, pos_x, pos_y, LEFT);
            road = res->road;
            printf("searching for road on pos x = %d and y = %d \n", pos_x, pos_y);
            if (road == NULL)
              printf("am scruid\n");
            if (road != NULL)
            {
              if (res->ref == HEAD) {
                double_linked_list_append_in_beg(&road->dll->head, i, x, y);
                double_linked_list_append_in_beg(&road->dll->head, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_beg(&road->dll->head, j, x, y);
                  }
                }
              }

              else {
                double_linked_list_append_in_end(&road->dll->tail, i, x, y);
                double_linked_list_append_in_end(&road->dll->tail, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_end(&road->dll->tail, j, x, y);
                  }
                }
                // printf("inserting in the tail\n");
              }
            }
            break;
          case 3: // bottom
            pos_x = x + 1;
            pos_y = y;
            res = roads_construction_search_road(rd, pos_x, pos_y, TOP);
            road = res->road;
            printf("searching for road on pos x = %d and y = %d \n", pos_x, pos_y); 
            if (road == NULL)
              printf("am scruid\n");
            if (road != NULL)
            {
              if (res->ref == HEAD) {
                double_linked_list_append_in_beg(&road->dll->head, i, x, y);
                double_linked_list_append_in_beg(&road->dll->head, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_beg(&road->dll->head, j, x, y);
                  }
                }
              }

              else {
                double_linked_list_append_in_end(&road->dll->tail, i, x, y);
                double_linked_list_append_in_end(&road->dll->tail, CENTER, x, y);
                for (int j = 0 ;j < 4 ; j++) {
                  if (g->tab[x][y].t->borders[j].landscape == ROAD && j != i) {
                    double_linked_list_append_in_end(&road->dll->tail, j, x, y);
                  }
                }
                // printf("inserting in the tail\n");
              }
            }
            break;
          }
        } 
      }

      if (num_neighbors_having_road == 0)
      {
        printf("wow all zeros\n");
        bool in_end = false;
        int first_index = -1;
        int second_index = -1;
        for (int i = 0; i < 4; i++)
        {
          if (g->tab[x][y].t->borders[i].landscape == ROAD) {
            if (!in_end) {
              first_index = i;
              in_end = true;
            } else {
              second_index = i;
              break;
            }
          }
        }
        Road * road = roads_construction_add_road(rd, first_index, x, y);
        double_linked_list_append_in_end(&road->dll->tail, CENTER, x, y);
        double_linked_list_append_in_end(&road->dll->tail, second_index, x, y);
  
      }

    
    }

    // center is not road
    else
    {
      printf("case center is not road\n");
      int ones_counter = 0;
      int first_index_one = -1, second_index_one = -1;
      for (int i = 0; i < 4; i++)
      {
        if (are_neighbors_roads[i] == 1 && first_index_one == -1)
        {
          ones_counter++;
          first_index_one = i;
          continue;
        }
        if (are_neighbors_roads[i] == 1 && first_index_one != -1)
        {
          ones_counter++;
          second_index_one = i;
        }
      }

      // we create two new roads
      if (ones_counter == 0)
      {

        switch (g->tab[x][y].t->borders[0].landscape)
        {
        case ROAD:
          roads_construction_add_road(rd, LEFT, x, y);
        default:
          break;
        }
        switch (g->tab[x][y].t->borders[1].landscape)
        {
        case ROAD:
          roads_construction_add_road(rd, TOP, x, y);
        default:
          break;
        }
        switch (g->tab[x][y].t->borders[2].landscape)
        {
        case ROAD:
          roads_construction_add_road(rd, RIGHT, x, y);
        default:
          break;
        }
        switch (g->tab[x][y].t->borders[3].landscape)
        {
        case ROAD:
          roads_construction_add_road(rd, BOTTOM, x, y);
        default:
          break;
        }
      }

      // we attach both borders
      else if (ones_counter == 2)
      {
        switch (first_index_one)
        {
        case 0:
          res = roads_construction_search_road(rd, x, y - 1, RIGHT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
            if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, LEFT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, LEFT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 1:
          res =  roads_construction_search_road(rd, x - 1, y, BOTTOM);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, TOP, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, TOP, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 2:
          res = roads_construction_search_road(rd, x, y + 1, LEFT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, RIGHT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, RIGHT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 3:
          res =  roads_construction_search_road(rd, x, y + 1, TOP);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, BOTTOM, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, BOTTOM, x, y);
              printf("inserting in the tail\n");

            }
          }

          break;
        }
        switch (second_index_one)
        {
        case 0:
          res =  roads_construction_search_road(rd, x, y - 1, RIGHT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, LEFT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, LEFT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 1:
          res =  roads_construction_search_road(rd, x - 1, y, BOTTOM);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
            if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, TOP, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, TOP, x, y);
              printf("inserting in the tail\n");

            }
          }

          break;
        case 2:

          res =  roads_construction_search_road(rd, x, y + 1, LEFT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, RIGHT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, RIGHT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 3:

        {
          res = roads_construction_search_road(rd, x, y + 1, TOP);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, BOTTOM, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, BOTTOM, x, y);
              printf("inserting in the tail\n");

            }
          }
        }
        break;
        }
      }
      // we create a new road and attach a a border to anotehr Road
      else if (ones_counter == 1)
      {
        switch (first_index_one)
        {
        case 0:
          res =  roads_construction_search_road(rd, x, y - 1, RIGHT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, LEFT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, LEFT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 1:

        {
         res =  roads_construction_search_road(rd, x - 1, y, BOTTOM);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, TOP, x, y);
              printf("inserting in the head\n");
            } else {
              double_linked_list_append_in_end(&road->dll->tail, TOP, x, y);
              printf("inserting in the tail\n");

            }
          }
        }
        break;
        case 2:

          res = roads_construction_search_road(rd, x, y + 1, LEFT);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, RIGHT, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, RIGHT, x, y);
              printf("inserting in the tail\n");

            }
          }
          break;
        case 3:

        {
          res = roads_construction_search_road(rd, x, y + 1 , TOP);
          road = res->road;
          if (road == NULL)
            printf("am scruid\n");
          else
          {
             if (res->ref == HEAD) {
              double_linked_list_append_in_beg(&road->dll->head, BOTTOM, x, y);
              printf("inserting in the head\n");
            }else {
              double_linked_list_append_in_end(&road->dll->tail, BOTTOM, x, y);
              printf("inserting in the tail\n");

            }
          }
        }
        break;
        }

        // create a new road
        for (int i = 0; i < 4; i++)
        {
          if (g->tab[x][y].t->borders[i].landscape == ROAD && i != first_index_one)
          {
            roads_construction_add_road(rd, i, x, y);
            rd->size++;
          }
        }
      }
    }
  }
  break;
  // 3 roads means the center is not road
  case 3:
  case 4:
  {
    printf("case 3 or 4 : three/ four roads in the tile\n");
    for (int i = 0; i < 4; i++)
    {
      if (g->tab[x][y].t->borders[i].landscape == ROAD)
      {
        if (are_neighbors_roads[i] == 0)
        {
          roads_construction_add_road(rd, i, x, y);
        }
        else
        {
          switch (i)
          {
              case 0:
                res = roads_construction_search_road(rd, x, y - 1, RIGHT);
                road = res->road;
                if (road == NULL)
                  printf("am scruid\n");
                else
                {
                  if (res->ref == HEAD) {
                    double_linked_list_append_in_beg(&road->dll->head, LEFT, x, y);
                    // printf("inserting in the head\n");
                  }else {
                    double_linked_list_append_in_end(&road->dll->tail, LEFT, x, y);
                    // printf("inserting in the tail\n");
                  }
                }
                break;
              case 1:
              {
                res =  roads_construction_search_road(rd, x - 1, y, BOTTOM);
                road = res->road;
                if (road == NULL)
                  printf("am scruid\n");
                else
                {
                  if (res->ref == HEAD) {
                    double_linked_list_append_in_beg(&road->dll->head, TOP, x, y);
                    // printf("inserting in the head\n");
                  }else {
                    double_linked_list_append_in_end(&road->dll->tail, TOP, x, y);
                    // printf("inserting in the tail\n");
                  }
                }
              }
              break;
              case 2:

                res =  roads_construction_search_road(rd, x, y + 1, LEFT);
                road = res->road;
                if (road == NULL)
                  printf("am scruid\n");
                else
                {
                  if (res->ref == HEAD) {
                    double_linked_list_append_in_beg(&road->dll->head, RIGHT, x, y);
                    // printf("inserting in the head\n");
                  }else {
                    double_linked_list_append_in_end(&road->dll->tail, RIGHT, x, y);
                    // printf("inserting in the tail\n");
                  }
                };
                break;
              case 3:
              {
                res = roads_construction_search_road(rd, x + 1, y, TOP);
                road = res->road;
                if (road == NULL)
                  printf("am scruid\n");
                else
                {
                  if (res->ref == HEAD) {
                    double_linked_list_append_in_beg(&road->dll->head, BOTTOM, x, y);
                    // printf("inserting in the head\n");
                  }else {
                    double_linked_list_append_in_end(&road->dll->tail, BOTTOM, x, y);
                    // printf("inserting in the tail\n");
                  }
                }
              }
              break;
          }
        }
      }
    }
  }
  }
  return UPDATED_ROADS;
}

Roads_construction *roads_construction_init()
{
  Roads_construction *road_cons =
      (Roads_construction *)malloc(sizeof(Roads_construction));
  check_null((void *)road_cons,
             "could not allocate memory for Roads_construction struct");
  // becuase the specail tile already contains a special tile we can crate a
  // Road
  road_cons->arr = malloc(sizeof(Road *));
  // road_cons->arr[0] = roads_construction_add_road(CENTER, SPECIAL_TILE_X_POS, SPECIAL_TILE_Y_POS);
  Road *rd = (Road *)malloc(sizeof(Road));
  check_null((void *)rd, "could not allocate memory for Road struct");
  // create the double linked list
  rd->dll = double_linked_list_info_create();

  // no owners by default
  for (int i = 0; i < 5; i++)
  {
    rd->owners[i] = NULL;
    rd->num_meeples[i] = 0;
  }

  r_node *node = (r_node *)malloc(sizeof(r_node));

  node->border = CENTER;
  node->pos.x = SPECIAL_TILE_X_POS;
  node->pos.y = SPECIAL_TILE_Y_POS;
  node->next = node->prev = NULL;

  rd->dll->origine = node;
  rd->dll->head = node;
  rd->dll->tail = node;
  rd->conquered = false;

  double_linked_list_append_in_beg(&rd->dll->head, LEFT, SPECIAL_TILE_X_POS, SPECIAL_TILE_Y_POS);
  double_linked_list_append_in_end(&rd->dll->tail, RIGHT, SPECIAL_TILE_X_POS, SPECIAL_TILE_Y_POS);

  road_cons->arr[0] = rd;
  road_cons->size = 1;
  return road_cons;
}

// must not forget to add the pointers to every plyer
Road *roads_construction_add_road(Roads_construction *R, Borders b, int x, int y)
{
  printf("calling roads_construction_add_road\n");
  Road *rd = (Road *)malloc(sizeof(Road));
  check_null((void *)rd, "could not allocate memory for Road struct");
  // create the double linked list
  rd->dll = double_linked_list_info_create();

  r_node *node = (r_node *)malloc(sizeof(r_node));

  node->border = b;
  node->pos.x = x;
  node->pos.y = y;
  node->next = node->prev = NULL;

  rd->dll->origine = node;
  rd->dll->head = node;
  rd->dll->tail = node;
  rd->conquered = false;

  // by defalut no player owns the road yet
  for (int i = 0; i < 5; i++)
    rd->owners[i] = NULL;

  // by default every player has 0 meeples roea
  for (int i = 0; i < 5; i++)
    rd->num_meeples[i] = 0;

  R->size++;
  R->arr = (Road **)realloc(R->arr, R->size * sizeof(Road *));
  R->arr[R->size - 1] = rd;

  return rd;
}

// search in all Roads and return a road that goes through x and y coordinates
// of course we need to check only the head and th tail
road_search_result * roads_construction_search_road(Roads_construction *rd, int x, int y, Borders b)
{

  // allocate memory for the result
  road_search_result *result = (road_search_result *)malloc(sizeof(road_search_result));
  check_null((void *)result, "could not allocate memory for road_search_result");
  Road **ptr_roads = rd->arr;

  for (int i = 0; i < rd->size; i++) {
    if (ptr_roads[i]->dll->head->pos.x == x && ptr_roads[i]->dll->head->pos.y == y && ptr_roads[i]->dll->head->border == b) {
      result->road = ptr_roads[i];
      result->ref = HEAD;
      return result;
    }
    if (ptr_roads[i]->dll->tail->pos.x == x && ptr_roads[i]->dll->tail->pos.y == y && ptr_roads[i]->dll->tail->border == b) {
      result->road = ptr_roads[i];
      result->ref = TAIL;
      return result;
      }
  }
  return NULL;
}

void roads_construction_conquere_road(Roads_construction *rd, Player *p, int index_player, int x, int y)
{

  for (int i = 0;i < 5; i++) {

    Road *road; 
    road_search_result *res = roads_construction_search_road(rd, x, y, i);
    road = res->road;

    if (road != NULL)
    {
      if (road->conquered)
      {
        printf("road is already conquered can not put a  meeple\n");
        return;
      }
      road->conquered = true;
      road->owners[index_player] = p;
      road->num_meeples[index_player]++;
    }
    else
    {
      printf("OOOOOOOOOOOOOOPS SOMETHING WENT WORONG\n");
    }
    }
}

Double_linked_list_info *double_linked_list_info_create()
{
  Double_linked_list_info *dll = (Double_linked_list_info *)malloc(sizeof(Double_linked_list_info));
  check_null((void *)dll, "could not allocate memory for Double_linked_list_info");
  dll->origine = NULL;
  dll->head = NULL;
  dll->tail = NULL;
  return dll;
}

void double_linked_list_append_in_beg(r_node **head, Borders B, int x, int y)
{
  if (head == NULL)
    printf("attention head is null \n");
  r_node *new_node = (r_node *)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_beg");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->prev = NULL;

  if (*head == NULL)
  { // If the list is empty
    new_node->next = NULL;
    *head = new_node;
    return;
  }

  // If the list is not empty
  new_node->next = *head;
  (*head)->prev = new_node;
  *head = new_node;
}

void double_linked_list_append_in_end(r_node **tail, Borders B, int x, int y)
{
  r_node *new_node = (r_node *)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in double_linked_list_append_in_beg");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->next = NULL;

  if (*tail == NULL)
  { // If the list is empty
    new_node->next = NULL;
    *tail = new_node;
    return;
  }

  // If the list is not empty
  new_node->prev = *tail;
  (*tail)->next = new_node;
  *tail = new_node;
}
void double_linked_list_append_in_origin(Double_linked_list_info *dll, Borders B, int x, int y)
{
  r_node *new_node = (r_node *)malloc(sizeof(r_node));
  check_null((void *)new_node, "could not allocate memory for new_node in "
                               "double_linked_list_append_in_origin");

  new_node->border = B;
  new_node->pos.x = x;
  new_node->pos.y = y;
  new_node->next = dll->origine;
  new_node->prev = NULL;

  if (dll->origine != NULL)
  { // If the list is not empty
    dll->origine->prev = new_node;
  }
  else
  { // If the list is empty
    dll->tail = new_node;
  }

  dll->origine = new_node;
}

int get_tile_number_of_roads(Tile *t)
{

  int count = 0;
  for (int i = 0; i < 4; i++)
    if (t->borders[i].landscape == ROAD)
      count++;
  return count;
}

bool is_center_road(Tile *t) { return t->borders[4].landscape == ROAD; }

void check_neighbors(Grid *g, int x, int y, Borders tab[4])
{
  // check the left
  if (g->tab[x][y - 1].square_state != EMPTY && g->tab[x][y - 1].t->borders[2].landscape == ROAD)
    tab[0] = 1; // there is  road

  // check the top
  if (g->tab[x - 1][y].square_state != EMPTY && g->tab[x - 1][y].t->borders[3].landscape == ROAD)
    tab[1] = 1;

  // check the right
  if (g->tab[x][y + 1].square_state != EMPTY && g->tab[x][y + 1].t->borders[0].landscape == ROAD)
    tab[2] = 1;

  // check the bottom
  if (g->tab[x + 1][y].square_state != EMPTY && g->tab[x + 1][y].t->borders[1].landscape == ROAD)
    tab[3] = 1;
}

void Roads_construction_print(Roads_construction *roads_construction)
{
  printf("Roads construction information:\n");
  printf("Number of roads: %d\n", roads_construction->size);
  printf("--------------------------------------\n");

  for (int i = 0; i < roads_construction->size; i++)
  {
    Road *road = roads_construction->arr[i];

    printf("Road %d:\n", i + 1);
    printf("Conquered: %s\n", road->conquered ? "Yes" : "No");

    printf("Owners:\n");
    for (int j = 0; j < 5; j++)
    {
      if (road->owners[j] != NULL)
      {
        printf("\t%s (%d meeples)\n", road->owners[j]->name, road->num_meeples[j]);
      }
    }

    printf("Nodes:\n");
    Double_linked_list_info *dll = road->dll;
    r_node *node = dll->head;

    while (node != NULL)
    {
      if(node == dll->head) printf("\tHead\n");
      if(node == dll->tail) printf("\tTail\n");
      printf("\tPosition: (%d, %d)\n", node->pos.x, node->pos.y);
      printf("\t ROAD on border %d \n", node->border);
      printf("--------------------------------------\n");

      node = node->next;
    }
  }
}

void Roads_construction_get_connected_roads(Roads_construction *rd)
{

  for (int i = 0; i < rd->size; i++)
  {
    Road *r1 = rd->arr[i];
    for (int j = i + 1; j < rd->size; j++)
    {
      Road *r2 = rd->arr[j];
      if (r1->dll->head->pos.x == r2->dll->tail->pos.x && r1->dll->head->pos.y == r2->dll->tail->pos.y)
      {
        printf("the two roads %d %d  are connected\n", i, j);
      }
      if (r1->dll->tail->pos.x == r2->dll->head->pos.x && r1->dll->tail->pos.y == r2->dll->head->pos.y)
      {
        printf("the two roads %d %d  are connected\n", i, j);
      }
    }
  }
}


Road * Roads_construction_finished_roads(Roads_construction *rd, Grid *g) {
  for (int i = 0; i < rd->size; i++) {
    Road * road = rd->arr[i];
    int x =  road->dll->head->pos.x;
    int y = road->dll->head->pos.y;
    int x2 = road->dll->tail->pos.x;
    int y2 = road->dll->tail->pos.y;

    if (
      
        (g->tab[x][y].t->borders[4].landscape == VILLAGE &&
        g->tab[x2][y2].t->borders[4].landscape == VILLAGE ) ||

        (g->tab[x][y].t->borders[4].landscape == CLOISTER &&
        g->tab[x2][y2].t->borders[4].landscape == CLOISTER ) ||

        (g->tab[x][y].t->borders[4].landscape == VILLAGE &&
        g->tab[x2][y2].t->borders[4].landscape == CLOISTER ) ||

        ( 
          g->tab[x][y].t->borders[4].landscape == CLOISTER &&
          g->tab[x2][y2].t->borders[4].landscape == VILLAGE )
        
        
        ) {
      printf("found a finished road where the head strts from %d %d and finishes on %d %d \n", x, y, x2, y2);
      return road;
    }

  }
  return NULL;
}
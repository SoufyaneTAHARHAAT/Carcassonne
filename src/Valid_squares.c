#include "./../include/Valid_squares.h"
#include "./../include/Grid.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"

Valid_squares *valid_squares_init() {
  Valid_squares *vs = (Valid_squares *)malloc(sizeof(Valid_squares));
  check_null((void *)vs, "could not allocate memory for Valid_squares struct");
  vs->arr = NULL;
  vs->size = 0;
  return vs;
}

/*
    @vs: pointer to Valid_squares struct
    @os: pointer to Open_sqaures struct
    @t: pointer to Tile struct
    to update valid squares we loop through every open square and compare them
    to the tile popped from the stack if any match is possible we push a new
   Square Oprientation to the vs->arr
*/

void valid_squares_update(Valid_squares *vs, Open_squares *os, Tile *t) {
  // we loop through the open squares and compare each one to the tile Edges
  int vs_index = 0;
  bool is_there_one = false;
  for (int i = 0; i < os->size; i++) {
    
    printf("calling are_borders_matching function for os.arr[%d] on x = %d, y =  %d \n" , i , os->arr[i].coor.x , os->arr[i].coor.y);
    int *arr = are_borders_matching(os->arr[i].edge_land_arr, t->borders);
    // check if the array contains at least 1 matching possiblity
    printf("arr resume after calling are are_borders_matching function \n");
    for (int i = 0; i < 4; i++) {
      printf("arr[%d] = %d \n" , i , arr[i]);
      if (arr[i] == 1) {
        is_there_one = true;
        break;
      }
    }

    // if bordrs matching we push a squar eorietation to Valid Squres;
    if (is_there_one) {
      int possible_fits = 0;
      Square_Orientation temp;
      temp.coor.x = os->arr[vs_index].coor.x;
      temp.coor.y = os->arr[vs_index].coor.y;

      for (int i = 0 ; i < 4; i++){ if(arr[i] == 1) possible_fits++;}
      temp.orientation = arr;
      temp.possible_fits = possible_fits;
      valid_squares_push(vs, temp);
      vs_index++;
      is_there_one =false;
    } else {
      free(arr);
      continue;
    }
  }
  // we must free the memory for int * arr; later nchhlhz
}

/*
    @edge_land_arr: array from Open Squres
    @tile_borders: array from Tile
    the function return the number of possible ways the borders can match;
    -1 if no match
    1...3 inclusive if there is a match

    if there is only one condition we look how many squares have that  condition
    if there is only two condtions
*/

int *are_borders_matching(Edge_land edge_land_arr[4],
                          Border_land tile_borders[5]) {
  bool is_match = true;
  int *arr = (int *)calloc(4 , sizeof(int) * 4);
  check_null((void *)arr,
             "could not allocate memory for array border matching");

  Landscape tile_ladscape_copy[4] = {
      tile_borders[0].landscape, tile_borders[1].landscape,
      tile_borders[2].landscape, tile_borders[3].landscape};

  // conpare all tile positions with orietation
  for (int i = 0; i < 4; i++) {
    printf("i = %d \n" , i);
    is_match = true;
    // compare both arrays
    for (int j = 0; j < 4; j++) {
      if (edge_land_arr[j].landscape == FREE){
        printf("free condition on j = %d \n" , j);
        // continue;
      }
      else {
        if (edge_land_arr[j].landscape != tile_ladscape_copy[j]) {
        printf("diffrent borders on j = %d \n" , j);
          is_match = false;
        }
        else {
          printf("mathcing borders on j = %d \n", j);
        }
      }
    }

    if (is_match){
      printf("affection 1 to arr[%d] \n" , i);
      arr[i] = 1;}
    else{
      printf("affection 0 to arr[%d] \n" , i);
      arr[i] = 0;}

    // shift the array

    // shift_array(tile_ladscape_copy, 5);
    Landscape temp = tile_ladscape_copy[3];
    tile_ladscape_copy[0] = tile_ladscape_copy[1];
    tile_ladscape_copy[1] = tile_ladscape_copy[2];
    tile_ladscape_copy[2] = tile_ladscape_copy[3];
    tile_ladscape_copy[3] = temp;
  }

  return arr;
}


void valid_squares_push(Valid_squares *vs, Square_Orientation so){
  vs->size++;
  vs->arr = (Square_Orientation*)realloc(vs->arr,vs->size * sizeof(Square_Orientation));
  vs->arr[vs->size - 1] = so;

}

// void shift_array(Landscape *arr, int size) {
//   printf("calliign shift array\n");
//   Landscape temp = arr[size - 1];

//   for (int i = size - 1; i > 0; i--) {
//     arr[i] = arr[i - 1];
//   }

//   arr[0] = temp;
// }

void valid_squares_print(Valid_squares *vs) {
  printf("size valid squares = %d\n", vs->size);
  for (int i = 0; i < vs->size; i++) {
    printf(" {%d , %d } ", vs->arr[i].coor.x, vs->arr[i].coor.y);
    for (int j = 0; j < 4; j++) {
      printf (" %d " , vs->arr[i].orientation[j]);
    }
    printf("\n");
  }
}

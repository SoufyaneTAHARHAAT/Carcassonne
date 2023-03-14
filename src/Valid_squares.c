#include "./../include/Grid.h"
#include "./../include/Open_squares.h"
#include "./../include/Result.h"
#include "./../include/Valid_squares.h"

Valid_squares *valid_squares_init() {
    Valid_squares * vs = (Valid_squares*)malloc(sizeof(Valid_squares));
    check_null((void *)vs , "could not allocate memory for Valid_squares struct");
    vs->arr = NULL;
    vs->size = 0;
    return vs;
}

/*
    @vs: pointer to Valid_squares struct
    @os: pointer to Open_sqaures struct
    @t: pointer to Tile struct
    to update valid squares we loop through every open square and compare them 
    to the tile popped from the stack if any match is possible we push a new Square
    Oprientation to the vs->arr 
*/

void valid_squres_update(Valid_squares *vs, Open_squares *os , Tile *t) {

    for (int i = 0; i < os->size; i++)
    {

        are_borders_matching(os->arr[i].edge_land_arr , t->borders);

    }
    
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

int are_borders_matching(Edge_land edge_land_arr[4] , Border_land tile_borders[5]) {
    int n_matches = 0;
    bool is_match = true;

    Landscape tile_ladscape_copy[4] = {
        tile_borders[0].landscape,
        tile_borders[1].landscape,
        tile_borders[2].landscape,
        tile_borders[3].landscape
    };

    // conpare all cases
    for (int i = 0; i < 3; i++)
    {
        is_match = true;
        // compare both arrays
        for (int j = 0; j < 4; j++)
        {
            if (edge_land_arr[j].landscape == FREE) continue;
            else {
                if (edge_land_arr[j].landscape != tile_ladscape_copy[j]) {
                    is_match = false;
                    break;
                }
            }
            
        }
        
        if (is_match) n_matches++;
        // shift the array
        shift_array(tile_ladscape_copy , 4);
    }

    return n_matches;
}

void shift_array(Landscape arr[] , int size) {
    Landscape temp = arr[size - 1];

    for(int i = size - 1; i > 0; i--)
    {
        arr[i] = arr[i-1];
    }

    arr[0] = temp;
}
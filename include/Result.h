#ifndef RESULT_H
#define RESULT_H

enum Result_t {
    OK,
    EMPTY_STACK,
    INVALID_TURN,
    VALID_GRID_POSTION, 
    INVALID_GRID_POSTION,
    MATCHING_BORDERS,
    UNMATCHING_BORDERS,
    UPDATED_ROADS, 
    NOT_UPDATED_ROADS,
    CONQUERED_ROAD,
};

typedef enum Result_t Result;

#endif

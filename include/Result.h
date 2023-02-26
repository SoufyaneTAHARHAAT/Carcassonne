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
};

typedef enum Result_t Result;

#endif
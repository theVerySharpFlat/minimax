#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#include <stdbool.h>

typedef enum {
    TURN_X = 1,
    TURN_O = 2
} Turn_t;

typedef enum {
    STATE_MT = 0,
    STATE_X,
    STATE_O
} GridState_t;

typedef struct {
    GridState_t state[3][3];
    Turn_t turn;
} Board_t;

bool hasSideWon(const Board_t* board, GridState_t side);
bool hasTie(const Board_t* board);

#endif

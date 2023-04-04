#include "tictactoe.h"

bool hasSideWon(const Board_t* board, GridState_t side) {
    bool us[3][3];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            us[i][j] = (board->state[i][j] == side);
        }
    }

    for (int i = 0; i < 3; i++) {
        if (us[i][0] && us[i][1] && us[i][2])
            return true;
        if (us[0][i] && us[1][i] && us[2][i])
            return true;
    }

    if (us[0][0] && us[1][1] && us[2][2])
        return true;
    if (us[2][0] && us[1][1] && us[0][2])
        return true;

    return false;
}

bool hasTie(const Board_t* board) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board->state[i][j] == STATE_MT) {
                return false;
            }
        }
    }

    return true;
}

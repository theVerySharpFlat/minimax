#include "minimax.h"
#include "tictactoe.h"

#include "inttypes.h"
#include <stdio.h>

int minimax(const Board_t board, GridState_t player, bool ai, int* oScore) {

    int bestScore;
    int bestLocation;
    if (ai) {
        bestScore = INT32_MIN;
    } else {
        bestScore = INT32_MAX;
    }

    GridState_t otherPlayer;
    if (player == STATE_O) {
        otherPlayer = STATE_X;
    } else {
        otherPlayer = STATE_O;
    }

    if (hasSideWon(&board, player)) {
        *oScore = ai ? 1 : -1;
        return -1;
    } else if (hasSideWon(&board, otherPlayer)) {
        *oScore = ai ? -1 : 1;
        return -1;
    } else if(hasTie(&board)){
        *oScore = 0;
        return -1;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board.state[i][j] == STATE_MT) {

                Board_t newBoard = board;
                newBoard.state[i][j] = player;

                int score;
                int move = minimax(newBoard, otherPlayer, !ai, &score);

                if (ai && score > bestScore) {
                    bestScore = score;
                    bestLocation = i * 3 + j;
                } else if (!ai && score < bestScore) {
                    bestScore = score;
                    bestLocation = i * 3 + j;
                }
            }
        }
    }

    *oScore = bestScore;
    return bestLocation;
}

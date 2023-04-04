#include <stdio.h>

#include "minimax.h"
#include "tictactoe.h"

Board_t board;

static void printBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            GridState_t currentState = board.state[i][j];

            switch (currentState) {
            case STATE_X: {
                printf(" \033[38;5;196mX\033[0m ");
            } break;
            case STATE_O: {
                printf(" \033[38;5;38mO\033[0m ");
            } break;
            case STATE_MT: {
                printf(" \033[38;5;245m%c\033[0m ", i * 3 + j + '0');
            } break;
            }

            if (j < 2) {
                printf("|");
            } else {
                printf("\n");
                if (i < 2) {
                    printf("-----------\n");
                }
            }
        }
    }
}

static char turnToChar(Turn_t turn) {
    switch (turn) {
    case TURN_X:
        return 'X';
    case TURN_O:
        return 'O';
    default:
        return '\0';
    }
}

int main() {
    board.turn = TURN_X;

    for (;;) {
        printBoard();

        int targetIndex = -1;

        if (board.turn == TURN_X) {
            while ((targetIndex < 0 || targetIndex > 8) ||
                   board.state[targetIndex / 3][targetIndex % 3] != STATE_MT) {
                printf("It is %c's turn, enter board index: ",
                       turnToChar(board.turn));

                char c = '\0';
                scanf(" %c", &c);

                while (getchar() != '\n')
                    ;

                targetIndex = c - '0';
            }
        } else {
            int score;
            targetIndex = minimax(board, board.turn, true, &score);
        }

        board.state[targetIndex / 3][targetIndex % 3] = (GridState_t)board.turn;

        if (board.turn == TURN_X)
            board.turn = TURN_O;
        else
            board.turn = TURN_X;

        if (hasSideWon(&board, STATE_X)) {
            printBoard();
            printf("X wins!\n");
            break;
        } else if (hasSideWon(&board, STATE_O)) {
            printBoard();
            printf("O wins!\n");
            break;
        } else if (hasTie(&board)) {
            printBoard();
            printf("Tie!\n");
            break;
        }
    }

    return 0;
}

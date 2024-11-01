#include <stdio.h>
#include <stdlib.h>

// function that clears the terminal screen
int clear(void) {
    printf("\x1B[2J");
    return 0;
}

int p_board(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("[%c]", board[i][j]);
        }

        printf("\n");
    }
    return 0;
}

int test_win(char board[3][3]) {
    for(int i = 0; i < 3; i++) {

        // test for lines
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '-') {
            return 1;
        }

        // test for columns
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '-') {
            return 1;
        }
    }

    // test for diagonals
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '-') {
        return 1;
    }

    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '-') {
        return 1;
    }
}

int test_tie(char board[3][3]) {
    int empty_tiles = 0;

    // look for empty tiles
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == '-') {
                empty_tiles++;
            }
        }
    }

    if(empty_tiles == 0) {
        return 1;
    }

    else {
        return 0;
    }
}

int main(void) {
    printf("Welcome to your Tic Tac Toe terminal player!!\npress enter to continue...\n");

    getchar();

    char player = 0;
    char player_c[2] = {'X', 'O'};
    char board[3][3];
    int has_ended = 0;
    int has_chosen = 0;
    int position[2];

    // fills board with 'empty' characters
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }

    // game loop
    while(has_ended == 0) {
        clear();

        // print turn information
        if(player == 0) {
            printf("Player 1's turn: select the coordinates (1-3) to place the 'X'!\n\n");
        }

        else {
            printf("Player 2's turn: select the coordinates (1-3) to place the 'O'!\n\n");
        }

        p_board(board);

        while (has_chosen == 0) {
            // get player input
            printf("\nx: \ny: \x1B[1A");
            scanf("%d", &position[1]);

            printf("y: ");
            scanf("%d", &position[0]);

            // check if position is available
            if(board[position[0] - 1][position[1] - 1] == '-') {

                // insert character in the board and continue
                board[position[0] - 1][position[1] - 1] = player_c[player];
                break;
            }

            else {
                printf("\x1B[3A\x1B[0JPlease select a valid position!");
            }
        }

        if(test_win(board) == 1) {
            clear();

            p_board(board);
            printf("\nPlayer %d won!", player + 1);

            break;
        }

        if(test_tie(board) == 1) {
            clear();

            p_board(board);
            printf("\nThere is a tie!");

            break;
        }

        if(player == 0) {
            player = 1;
        }

        else {
            player = 0;
        }
        
    }
}
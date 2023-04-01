# include <stdio.h>

# define BOARD_SIZE 7


void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%c|", board[i][j]);
            }
            printf("\n");
            }
    printf("1 2 3 4 5 6 7");
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE],int column, char player) {
    int row = 6;
    while (board[row][column] != ' ' && row >= 0) {
        row--;
    }
    if (row >= 0) {
        board[row][column] = player;
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE],char player) {
    // check rows
    for (int i = 0; i < 7; i++) {
        int count = 0;
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == player) {
                count++;
                if (count == 3) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }
    // check columns
    for (int j = 0; j < 7; j++) {
        int count = 0;
        for (int i = 0; i < 7; i++) {
            if (board[i][j] == player) {
                count++;
                if (count == 3) {
                    return 1;
                }
            } else {
                count = 0;
            }
        }
    }
    // check diagonals
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player) {
                return 1;
            }
            if (board[i][j+2] == player && board[i+1][j+1] == player && board[i+2][j] == player) {
                return 1;
            }
        }
    }
    return 0;
}




int main() {
    char player = 'X';

    // initialize board
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            board[i][j] = ' ';
        }
    }

    displayBoard(board);
    while (1) {
        

        // get player input
        int column;
        printf("\nPlayer %c, choose a column (1-7): ", player);
        scanf("%d", &column);
        column--;

        // make move
        makeMove(board, column, player);

        // display board
        displayBoard(board);

        // check for win
        if (checkWin(board, player)) {
            printf("\n!!Player %c wins!!\n", player);
            break;
        }

        // switch player
        if (player == 'X') {
            player = 'O';
        } else {
            player = 'X';
        }
    }

    return 0;
}

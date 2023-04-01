# include <stdio.h>

# define BOARD_SIZE 7

void displayBoard(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            printf("%c|", board[i][j]);
            }
            printf("\n");
            }
    printf("1 2 3 4 5 6 7\n");
}

int isValidMove(char board[BOARD_SIZE][BOARD_SIZE],int col)
{
    return board[0][col] == ' ';
}

void makeMove(char board[BOARD_SIZE][BOARD_SIZE],int col, char player) {
    // int row = 6;
    int row = BOARD_SIZE - 1;

    while (board[row][col] != ' ' && row >= 0) {
        row--;
    }
    if (row >= 0) {
        board[row][col] = player;
        
    }
}

int checkWin(char board[BOARD_SIZE][BOARD_SIZE],char player) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE - 3; col++)
        {

            if (board[row][col] == player && board[row][col + 1] == player && board[row][col + 2] == player)
            {
                return 1;
            }
        }
    }
    // Check columns
    for (int row = 0; row < BOARD_SIZE - 3; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == player && board[row + 1][col] == player && board[row + 2][col] == player)
            {
                return 1;
            }
        }
    }
    // Check diagonals
    for (int i = 0; i < BOARD_SIZE - 2; i++) {
        for (int j = 0; j < BOARD_SIZE - 2; j++) {
            // Checking like this ' / '
            if (board[i][j] == player && board[i+1][j+1] == player && board[i+2][j+2] == player) {
                return 1;
            }
            // Checking like this ' \ '
            if (board[i][j+2] == player && board[i+1][j+1] == player && board[i+2][j] == player) {
                return 1;
            }
        }
    }
    return 0;
}


int isTie(char board[BOARD_SIZE][BOARD_SIZE])
{
    for (int row = 0; row < BOARD_SIZE; row++)
    {
        for (int col = 0; col < BOARD_SIZE; col++)
        {
            if (board[row][col] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}



int main() {
    // Player X starts the Game
    char player = 'X';
    int col;
    // initialize board
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    displayBoard(board);
    while (1) {
        
        // Get player input
        printf("Player %c's turn\n", player);
        printf("Enter column number (1-7): ");
        scanf("%d", &col);
        col--; // adjust for 0-based index

        if (col < 0 || col >= BOARD_SIZE)
        {
            printf("Invalid column number. Try again.\n");
            continue;
        }

        if (!isValidMove(board,col))
        {
            printf("Column is full. Try again.\n");
            continue;
        }

        // make move
        makeMove(board, col, player);

        // display board
        displayBoard(board);

        // check for win
        if (checkWin(board, player)) {
            printf("\n!!Player %c wins!!\n", player);
            break;
        }

        if (isTie(board))
        {
            printf("It's a tie!\n");
            break;
        }

        // switch player
        player = (player == 'X') ? 'O' : 'X';
        
    }

    return 0;
}

#include <stdio.h>

#define ROWS 7
#define COLS 7

char board[ROWS][COLS];

void init_board()
{
    int row, col;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            board[row][col] = '-';
        }
    }
}

void display_board()
{
    int row, col;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int is_valid_move(int col)
{
    return board[0][col] == '-';
}

int drop_checker(int col, char checker)
{
    int row;
    for (row = ROWS - 1; row >= 0; row--)
    {
        if (board[row][col] == '-')
        {
            board[row][col] = checker;
            return row;
        }
    }
    return -1; // invalid move
}

int check_horizontal(int row, char checker)
{
    int col;
    for (col = 0; col <= COLS - 3; col++)
    {
        if (board[row][col] == checker && board[row][col + 1] == checker && board[row][col + 2] == checker)
        {
            return 1;
        }
    }
    return 0;
}

int check_vertical(int col, char checker)
{
    int row;
    for (row = 0; row <= ROWS - 3; row++)
    {
        if (board[row][col] == checker && board[row + 1][col] == checker && board[row + 2][col] == checker)
        {
            return 1;
        }
    }
    return 0;
}

int check_diagonal_down(char checker)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 3; col < 7; col++)
        {
            if (board[row][col] == checker && board[row + 1][col - 1] == checker && board[row + 2][col - 2] == checker)
            {
                return 1;
            }
        }
    }
    return 0;
}

int check_diagonal_up(char checker)
{
    for (int row = 0; row < 4; row++)
    {
        for (int col = 0; col < 4; col++)
        {
            if (board[row][col] == checker && board[row + 1][col + 1] == checker && board[row + 2][col + 2] == checker)
            {
                return 1;
            }
        }
    }
    return 0;
}

int check_winner(int row, int col, char checker)
{
    return check_horizontal(row, checker) || check_vertical(col, checker) || check_diagonal_up(checker) || check_diagonal_down(checker);
}

int is_tie()
{
    int row, col;
    for (row = 0; row < ROWS; row++)
    {
        for (col = 0; col < COLS; col++)
        {
            if (board[row][col] == '-')
            {
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int player = 1;
    char player1_checker = 'X';
    char player2_checker = 'O';
    int row, col, move;
    init_board();
    display_board();

    while (1)
    {
        printf("Player %d's turn\n", player);
        printf("Enter column number (1-7): ");
        scanf("%d", &col);
        col--; // adjust for 0-based index

        if (col < 0 || col >= COLS)
        {
            printf("Invalid column number. Try again.\n");
            continue;
        }

        if (!is_valid_move(col))
        {
            printf("Column is full. Try again.\n");
            continue;
        }

        row = drop_checker(col, player == 1 ? player1_checker : player2_checker);
        display_board();

        if (check_winner(row, col, player == 1 ? player1_checker : player2_checker))
        {
            printf("Player %d wins!\n", player);
            break;
        }

        if (is_tie())
        {
            printf("It's a tie!\n");
            break;
        }

        player = player == 1 ? 2 : 1;
    }

    return 0;
}

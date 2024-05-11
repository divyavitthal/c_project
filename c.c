#include<stdio.h>
#include<conio.h>
void display_board(char board[3][3]) {
    printf("  %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf(" ---|---|---\n");
    printf("  %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int check_win(char board[3][3], char player) {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    
    return 0;
}

int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int row, col;
    char player = 'X';
    int turn = 0;
    int game_over = 0;

    printf("Welcome to Tic-Tac-Toe!\n");

    while (!game_over && turn < 9) {
        // Display the board
        display_board(board);
        
        // Get player's move
        printf("Player %c, enter your move (row column): ", player);
        scanf("%d %d", &row, &col);

        // Check if the entered position is valid
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Update the board
        board[row][col] = player;

        // Check if the current player wins
        if (check_win(board, player)) {
            printf("Player %c wins!\n", player);
            game_over = 1;
        } else {
            // Switch player
            player = (player == 'X') ? 'O' : 'X';
            turn++;
        }
    }

    if (!game_over)
        printf("It's a draw!\n");

    // Display the final board
    display_board(board);

    return 0;
}

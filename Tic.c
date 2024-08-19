#include <stdio.h>

#define SIZE 3

void print_board(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int check_winner(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;

    return 0;
}

int main() {
    char board[SIZE][SIZE] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    int row, col, moves = 0;
    char player = 'X';

    while (1) {
        print_board(board);
        printf("Player %c, enter row and column (0-2): ", player);
        scanf("%d %d", &row, &col);

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || board[row][col] != 'X' && board[row][col] != 'O') {
            printf("Invalid move. Try again.\n");
            continue;
        }

        board[row][col] = player;
        moves++;

        if (check_winner(board, player)) {
            print_board(board);
            printf("Player %c wins!\n", player);
            break;
        }

        if (moves == SIZE * SIZE) {
            print_board(board);
            printf("It's a draw!\n");
            break;
        }

        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

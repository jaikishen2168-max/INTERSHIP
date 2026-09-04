#include <iostream>
using namespace std;

char board[3][3] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'}
};

// Display the game board
void displayBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
}

// Check whether a player has won
bool checkWin(char player) {

    // Rows
    for (int i = 0; i < 3; i++)
        if (board[i][0] == player &&
            board[i][1] == player &&
            board[i][2] == player)
            return true;

    // Columns
    for (int i = 0; i < 3; i++)
        if (board[0][i] == player &&
            board[1][i] == player &&
            board[2][i] == player)
            return true;

    // Diagonals
    if (board[0][0] == player &&
        board[1][1] == player &&
        board[2][2] == player)
        return true;

    if (board[0][2] == player &&
        board[1][1] == player &&
        board[2][0] == player)
        return true;

    return false;
}

// Check for draw
bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] >= '1' && board[i][j] <= '9')
                return false;

    return true;
}

// Reset board for replay
void resetBoard() {
    char value = '1';

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = value++;
}

int main() {

    char player;
    int choice;
    char replay;

    do {
        resetBoard();
        player = 'X';

        while (true) {

            displayBoard();

            cout << "\nPlayer " << player << ", enter position (1-9): ";
            cin >> choice;

            // Convert position into array index
            int row = (choice - 1) / 3;
            int col = (choice - 1) % 3;

            // Validate move
            if (choice < 1 || choice > 9 ||
                board[row][col] == 'X' ||
                board[row][col] == 'O') {

                cout << "Invalid move! Try again.\n";
                continue;
            }

            board[row][col] = player;

            // Check winner
            if (checkWin(player)) {
                displayBoard();
                cout << "\nPlayer " << player << " wins!\n";
                break;
            }

            // Check draw
            if (checkDraw()) {
                displayBoard();
                cout << "\nIt's a draw!\n";
                break;
            }

            // Change player
            player = (player == 'X') ? 'O' : 'X';
        }

        cout << "\nDo you want to play again? (Y/N): ";
        cin >> replay;

    } while (replay == 'Y' || replay == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}

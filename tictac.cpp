#include <iostream>
using namespace std;

char board[3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} };
char currentMark;
int currentPlayer;

void printBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---+---+---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

bool placeMark(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (slot < 1 || slot > 9 || board[row][col] == 'X' || board[row][col] == 'O')
        return false;
    board[row][col] = currentMark;
    return true;
}

bool checkWin() {
    // check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    // check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;

    return false;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 1) ? 2 : 1;
    currentMark = (currentMark == 'X') ? 'O' : 'X';
}

int main() {
    currentPlayer = 1;
    currentMark = 'X';
    int slot;

    cout << "=== Tic Tac Toe ===\n";
    printBoard();

    while (true) {
        cout << "Player " << currentPlayer << " (" << currentMark << ") - Enter slot (1-9): ";
        cin >> slot;

        if (!placeMark(slot)) {
            cout << "Invalid move! Try again.\n";
            continue;
        }

        printBoard();

        if (checkWin()) {
            cout << "🎉 Player " << currentPlayer << " wins!\n";
            break;
        }

        if (checkDraw()) {
            cout << "🤝 It's a draw!\n";
            break;
        }

        switchPlayer();
    }
    return 0;
}

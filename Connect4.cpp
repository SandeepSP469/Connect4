#include <iostream>
#include <stdlib.h>
using namespace std;

void Title() { 
    cout << " ############################# \n";
    cout << endl;
    cout << "           WELCOME  \n";
    cout << "             TO \n";
    cout << "          CONNECT-4 \n";
    cout << endl;
    cout << " ############################# \n";
}

void Rules() {

    cout << "Instructions :\n";
    cout << "1) Game will always start with player-1 i.e. Red(R) \n";
    cout << "2) In Each turn choose the column number in Which you want to drop the ball \n";
    cout << "3) Rows will be filled from bottom to top in every column \n";
    cout << "4) A player wins if he/she is able to connect 4 dots horizontally, vertically or diagonally \n";
    cout << "\n\n";
};

void InitializeBoard(char board[8][7]) {
    for (int i = 0; i < 8; i++) {

        for (int j = 0; j < 7; j++) {
            if (i < 6)
                board[i][j] = 'O';
            else if (i == 6)
                board[i][j] = '-';
            else if (i == 7)
                board[i][j] = '0' + (j + 1);
        }
    }
};

void PrintBoard(char board[8][7]) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'R') {
                cout << board[i][j] << " ";
            }
            else if (board[i][j] == 'B') {
                cout << board[i][j] << " ";
            }
            else {
                cout << board[i][j] << " ";
            }

            cout << "| ";
        }
        cout << "\n";
    }
    cout << "\n";
}

bool RedInput(int col, char board[8][7]) {
    col--;
    if (board[0][col] != 'O') {
        cout << "The column is filled. Please enter another column.\n";
        return true;
    }
    else {
        for (int i = 5; i >= 0; i--) {
            if (board[i][col] == 'O') {
                board[i][col] = 'R';
                break;
            }
        }
        return false;
    }
};

bool BlueInput(int col, char board[8][7]) {
    col--;
    if (board[0][col] != 'O') {
        cout << "\nThe column is filled. Please enter another column.\n";
        return true;
    }
    else {
        for (int i = 5; i >= 0; i--) {
            if (board[i][col] == 'O') {
                board[i][col] = 'B';
                break;
            }
        }
        return false;
    }
};

bool StartGame() {
    cout << "START GAME  (Y/N) :   ";
    char input;
    cin >> input;
    if (input == 'N') {
        cout << "\n#########################  THANKS FOR PLAYING  #########################" "\n\n";
        return false;
    }
    else if (input != 'Y') {
        cout << "\nPlease Enter a valid input \n\n";
        StartGame();
    }
    else {
        return true;
    }
}

bool CheckForWin(char Player, char board[8][7]) {
    bool win = false;

    for (int i = 5; i >= 0; i--) {
        for (int j = 6; j >= 0; j--) {
            if (board[i][j] == Player && board[i - 1][j - 1] == Player &&
                board[i - 2][j - 2] == Player && board[i - 3][j - 3] == Player) {
                win = true;
            }

            if (board[i][j] == Player && board[i][j - 1] == Player &&
                board[i][j - 2] == Player && board[i][j - 3] == Player) {
                win = true;
            }

            if (board[i][j] == Player && board[i - 1][j] == Player &&
                board[i - 2][j] == Player && board[i - 3][j] == Player) {
                win = true;
            }

            if (board[i][j] == Player && board[i - 1][j + 1] == Player &&
                board[i - 2][j + 2] == Player && board[i - 3][j + 3] == Player) {
                win = true;
            }

            if (board[i][j] == Player && board[i][j + 1] == Player &&
                board[i][j + 2] == Player && board[i][j + 3] == Player) {
                win = true;
            }
        }
    }

    return win;
};

int main() {
    Title();
    Rules();
    char board[8][7];
    InitializeBoard(board);
    bool GameEnds = false;
    bool RedTurn = true;
    bool BlueTurn = false;
    if (!StartGame()) {
        return 0;
    }
    while (!GameEnds) {
        if (RedTurn) {
            PrintBoard(board);
            cout << "Player - 1\n";
            cout << "Enter Column Number to drop the ball:  ";

            int r;
            cin >> r;
            RedTurn = RedInput(r, board);
            bool won = CheckForWin('R', board);
            if (won) {
                GameEnds = true;
                cout << "\n Player-1 Won the Game!!!\n\n";
                PrintBoard(board);
                continue;
            }
            BlueTurn = !RedTurn;
            if (RedTurn)
                continue;
        }
        if (BlueTurn) {
            PrintBoard(board);
            cout << "Player - 2\n";
            cout << "Enter Column Number to drop the ball:  ";
            int b;
            cin >> b;
            BlueTurn = BlueInput(b, board);
            bool won = CheckForWin('B', board);
            if (won) {
                GameEnds = true;
                cout << "\nPlayer - 2 Won the Game!!!\n\n";
                PrintBoard(board);
                continue;
            }
            RedTurn = !BlueTurn;
            if (BlueTurn)
                continue;
        }
        if (bool GameEnds = true) {
            cout << "Player Won";
        }
    }
}

#include <iostream>
using namespace std;
void initializeBoard(char (*board)[3]);
void displayBoard(char (*board)[3]);
bool makeMove(char (*board)[3], int row, int col, char player);
bool checkWin(char (*board)[3], char player);
bool checkDraw(char (*board)[3]);

int main(){
    
    /*this part 'from int main () until return 0' is for displaying the basic
    rules and moves for the game that will be displayed for the players (users) 
    'like making infinite loops and winning and draw-ing conditions' */
    
    char board[3][3];
    char currentPlayer = 'X';
    int row, col;
    
    initializeBoard(board);
    
    //stop only when win or draw
    while (true) {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;
    // checking if the move is valid
        if (!makeMove(board, row, col, currentPlayer)) {
            cout << "Invalid move, Try again.\n";
            continue;
        }
    // Check winning condition
        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player" << currentPlayer << " wins\n";
            break;
        }
    // Check draw-ing condition
        if (checkDraw(board)) {
            displayBoard(board);
            cout << "It's a draw\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    return 0;
}

/*this paert 'from after return 0 to return true' is for the functions behind the 
game (like displaying the board after every move 'loop' and checking of winning
and draw-ing 'loop')*/

void initializeBoard(char (*board)[3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}
void displayBoard(char (*board)[3]) {
    cout << "\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " " << board[i][j] << " ";
            
            if (j < 2) cout << "|";
        }
        cout << "\n";
        
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}
// checking if the move is valid or not
bool makeMove(char (*board)[3], int row, int col, char player) {
// checks if the move is out of the range of the board
    if (row < 0 || row > 2 || col < 0 || col > 2)
        return false;
//checks if the cell is not empty
    else if (board[row][col] != ' ')
        return false;
        
    board[row][col] = player;
    return true;
}

bool checkWin(char (*board)[3], char player) {
    for (int i = 0; i < 3; i++) {
        // this part checks if the same 3 cells in a row belong to the same player
        if ((board[i][0] == player &&
             board[i][1] == player &&
             board[i][2] == player) ||
            (board[0][i] == player &&
             board[1][i] == player &&
             board[2][i] == player))
            return true;
    }
    // OR if the same 3 cells in a column belong to the same player
    
    // Checking if the Diagonals belong to the same player
    
    if ((board[0][0] == player &&
         board[1][1] == player &&
         board[2][2] == player) ||
        (board[0][2] == player &&
         board[1][1] == player &&
         board[2][0] == player))
        return true;
        
    return false;
}

bool checkDraw(char (*board)[3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}
//checks if there are still empty cells (meaning the game should continue still)
//if there're still empty cells it 'returns false' and the game continues
/*if there aren't any empty cells, the game will stop and draw (that's if one
of the players didn't win already)*/
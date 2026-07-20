#include <iostream>
using namespace std;

const int SIZE = 9;

int board[SIZE][SIZE] = 
{
    {5,3,0,0,7,0,0,0,0},
    {6,0,0,1,9,5,0,0,0},
    {0,9,8,0,0,0,0,6,0},

    {8,0,0,0,6,0,0,0,3},
    {4,0,0,8,0,3,0,0,1},
    {7,0,0,0,2,0,0,0,6},

    {0,6,0,0,0,0,2,8,0},
    {0,0,0,4,1,9,0,0,5},
    {0,0,0,0,8,0,0,7,9}
};

int original[SIZE][SIZE];
int initialBoard[SIZE][SIZE];

void copyOriginal()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            original[i][j] = board[i][j];
            initialBoard[i][j] = board[i][j];
        }
    }
}

void restartGame()
{
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = initialBoard[i][j];
        }
    }
    cout << "\nGame restarted successfully!\n";
}

void printBoard() 
{
    cout << "\n";
    for(int i = 0; i < SIZE; i++) {
        if (i%3 == 0) {
            cout << "-----------------------------\n";
        }
        for(int j = 0; j < SIZE; j++) {
            if(j%3 == 0)
                cout << " | ";

            if (board[i][j]==0)
                cout << ". ";
            else 
                cout << board[i][j]<< " ";
        }
        cout << "|\n";
    }
    cout << "---------------------------------\n";
}

bool usedInRow(int row, int num) 
{
    for (int col = 0; col < SIZE; col++) {
        if (board[row][col] == num)
            return true;
    }
    return false;
}

bool usedInCol(int col, int num) {
    for (int row = 0; row < SIZE; row++) {
        if (board[row][col]==num)
            return true;
    }
    return false;
}

bool usedInBox(int startRow, int startCol, int num){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[startRow+i][startCol+j]==num)
                return true;
        }
    }
    return false;
}

bool isSafe(int row, int col, int num) {
    return !usedInRow(row,num)
        && !usedInCol(col, num)
        && !usedInBox(row-row%3,col-col%3,num);
}

bool isComplete()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j]==0)
                return false;
        }
    }
    return true;
}

bool findEmptyLocation(int &row, int &col)
{
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (board[row][col] == 0)
                return true;
        }
    }
    return false;
}

bool solveSudoku()
{
    int row, col;
    if(!findEmptyLocation(row, col))
        return true;

    for(int num = 1; num <= 9; num++) {
        if(isSafe(row, col, num))
        {
            board[row][col] = num;
            if (solveSudoku())
                return true;
            board[row][col] = 0;
        }
    }
    return false;
}

void giveHint() 
{
    int temp[SIZE][SIZE];
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            temp[i][j] = board[i][j];
        }
    }
    if (!solveSudoku())
    {
        cout << "\nNo solution exists.\n";
        return;
    }
    for(int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE;  j++) {
            if (temp[i][j] == 0) 
            {
                cout << "\nHint\n";
                cout << "Row " << i + 1 << ", Column " << j + 1 << " = " << board[i][j] << endl;
                for(int r = 0; r < SIZE; r++) {
                    for (int c = 0; c < SIZE; c++) {
                        board[r][c] = temp[r][c];
                    }
                }
                return;
            }
        }
    }
    cout << "\nBoard already complete!\n";
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            board[r][c] = temp[r][c];
        }
    }
}

void makeMove() {
    int row, col, num;

    cout << "\nRow (1-9): ";
    cin >> row;

    cout << "Column (1-9): ";
    cin >> col;

    cout << "Number (1-9): ";
    cin >> num;

    row--;
    col--;

    if (row<0||row>=9||col<0||col>=9) {
        cout << "\nInvalid position!\n";
        return;
    }

    if (num<1||num>9)
    {
        cout << "\nInvalid number!\n";
        return;
    }

    if (original[row][col] != 0) {
        cout << "\nThis cell cannot be changed!\n";
        return ;
    }

    if (isSafe(row,col,num))
    {
        board[row][col] = num;
        cout << "\nMove successful!\n";
    }
    else {
        cout << "\nInvalid move!\n";
    }
}

void menu()
{
    cout << "\n----------------- SUDOKU ----------------\n";
    cout << "1. Display Board\n";
    cout << "2. Make Move\n";
    cout << "3. Solve Puzzle\n";
    cout << "4. Give Hint\n";
    cout << "5. Restart Game\n";
    cout << "6. Exit\n";
}

int main () 
{
    copyOriginal();
    int choice;

    while(true)
    {
        menu();
        cout <<"\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                printBoard();
                break;

            case 2:
                printBoard();
                makeMove();
                if (isComplete())
                {
                    printBoard();
                    cout << "\nCongratulations! You solved the Sudoku!\n";
                    return 0;
                }
                break;

            case 3:
                cout << "Solving puzzle\n";
                if (solveSudoku())
                {
                    printBoard();
                    cout << "\nPuzzle solved successfully!\n";
                }
                else {
                    cout << "\nNo solution exists.\n";
                }
                break;

            case 4:
                giveHint();
                break;

            case 5:
                restartGame();
                break;

            case 6:
                cout << "\nThank You for playing!\n";
                return 0;

            default:
                cout << "\nInvalid choice!\n";
        }
    }
    return 0;
}

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

int orginal[SIZE][SIZE];

void copyOriginal()
{
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            orginal[i][j] = board[i][j];
        }
    }
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


void makeMove() {
    int row, col, num;

    cout << "\nRow (1-9): ";
    cin >> row;

    cout << "Column (1-9): ";
    cin >> col;

    cout << num;

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

    if (orginal[row][col] != 0) {
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
    cout <<"2. Make Move\n";
    cout << "3. Solve Puzzle\n";
    cout << "4. Exit\n";
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
                cout << "\nSolver will be implemented later\n";
                break;

            case 4:
                cout << "\nThank You for playing!\n";
                return 0;

            default:
                cout << "\nInvalid choice!\n";
        }
    }
    return 0;
}

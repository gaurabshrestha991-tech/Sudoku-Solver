# Sudoku-Solver
A classic Sudoku puzzle game implemented in C++ with an interactive console interface. Challenge yourself to solve a pre-loaded 9x9 Sudoku puzzle by filling in the empty cells with numbers 1-9 while following the standard Sudoku rules.

## Features
Interactive Gameplay: Make moves by entering row, column, and number values

Visual Board Display: Clean grid layout showing the current puzzle state with . representing empty cells

Move Validation: Automatically checks if moves violate Sudoku rules (row, column, or 3x3 box conflicts)

Fixed Cells: Pre-filled numbers are locked and cannot be modified

Win Detection: Automatically detects when the puzzle is solved and congratulates the player

Menu System: Simple navigation with options to view the board, make moves, or exit

Instant Auto-Solver: Uses a smart search method to solve the entire board for you in less than a second.

Hint Button: Stuck? The program calculates the solution in the background and gives you one correct number for an empty space.

Reset Anytime: Easily wipe your moves and start over from the beginning without closing the program.0


## How to Play
Run the program

Select option 1 to view the current board

Select option 2 to make a move:

Enter the row (1-9)

Enter the column (1-9)

Enter the number (1-9)

Continue making valid moves until the puzzle is solved

Select option 4 to exit the game

## Built With
This program is built using basic, standard programming tools. You don't need to install any external libraries to run it:

C++ Language: The core programming language used to write the logic.

Standard Input/Output (<iostream>): Used to print the game board on the screen and read your inputs (keyboard typing).

2D Arrays (Matrices): Used to hold the grid numbers and keep track of empty spots.

Recursion & Backtracking: A classic programming method where the computer tries a number, moves forward, and if it hits a dead end, it steps back ("backtracks") to try a different number until it finds the perfect match.


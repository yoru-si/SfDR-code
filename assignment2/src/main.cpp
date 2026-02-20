/*
file: main.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: This is the main function for the maze traversal program.
It initializes the maze grid and calls the necessary functions to find the starting position and traverse the maze.
*/
#include <array> // For using array to represent the maze grid
#include <iostream> // For input/output operations
#include "maze_utils.h" // Include the header file for maze utilities

int main(){
    // Initialize the maze grid with the given configuration
    MazeGrid maze = {{
        {'#','#','#','#','#','#','#','#','#','#','#','#'},
        {'#','.','.','.','#','.','.','.','.','.','.','#'},
        {'.','.','#','.','#','.','#','#','#','#','.','#'},
        {'#','#','#','.','.','.','.','.','.','#','.','#'},
        {'#','.','.','.','.','#','#','#','.','#','.','x'},
        {'#','#','#','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','#','.','#','.','#','.','#','.','#'},
        {'#','#','.','#','.','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','#','.','#'},
        {'#','#','#','#','#','#','.','#','#','#','.','#'},
        {'#','.','.','.','.','.','.','.','.','.','.','#'},
        {'#','#','#','#','#','#','#','#','#','#','#','#'}
    }};;

    
    int StartRow, StartCol;
    // Find the starting position of 'X' in the maze and store it in StartRow and StartCol
    std::tie(StartRow, StartCol) = findX(maze);

    //Proceed only if 'X' is found in the maze, otherwise print an error message and exit
    if (StartRow == -1 || StartCol == -1) {
        std::cerr << "Error: 'X' not found in the maze." << std::endl;
        return 1;
    }

    else {
        std::cout << "Starting position of 'X': (" << StartRow << ", " << StartCol << ")\n";
        traverseMaze(maze, StartRow, StartCol, Direction::Right, 0);
    }
}

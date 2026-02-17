#include <array>
#include <string>
#include <iostream>
#include "maze_utils.h"


void printMaze(const MazeGrid& maze)
{
    for (int i = 0; i < MAZE_SIZE; ++i) {
        for (int j = 0; j < MAZE_SIZE; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

std::pair<int,int> findX(const MazeGrid& maze)
{
    for (int r = 0; r < MAZE_SIZE; ++r) {
        for (int c = 0; c < MAZE_SIZE; ++c) {
            if (maze[r][c] == 'X') {
                return {r , c};
            }
        }
    }
    return {-1, -1}; // Return an invalid position if 'X' is not found
}

void traverseMaze(MazeGrid& maze, int r, int c, Direction dir){
    maze[r][c] = 'X';
    printMaze(maze);

    // Exit Condition: 
    // If the position is at the edge of the maze and the cell is not 'X' and is '.'
    if ((r == 0 || r == MAZE_SIZE-1 || c == 0 || c == MAZE_SIZE-1) && maze[r][c] == '.') {
        maze[r][c] = 'X';
        printMaze(maze);
        std::cout << "\nMaze Solved!\n";
        exit(0);
    }

    // Visualize current position by marking it as 'X'
    maze[r][c] = 'X';
    printMaze(maze);


    
}


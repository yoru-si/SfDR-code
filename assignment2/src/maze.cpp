/*
file: maze.cpp
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: This file contains the definitions of the functions declared in maze_utils.h, 
These are used for maze operations such as printing the maze, finding the starting position, and traversing the maze.
*/
#include <array> // For using array to represent the maze grid
#include <string> // For using string operations
#include <iostream> // For input/output operations
#include <thread> // For using sleep_for to create a delay between maze prints
#include <chrono> // For using milliseconds in sleep_for
#include "maze_utils.h" // Include the header file for maze utilities

// Function to print the maze grid to the console
void printMaze(const MazeGrid& maze)
{
    // Iterate through each cell in the maze grid and print its character, followed by a space for better readability
    for (int i = 0; i < MAZE_SIZE; ++i) {
        for (int j = 0; j < MAZE_SIZE; ++j) {
            std::cout << maze[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    // Delay of 500ms for better visualization of the maze traversal process
   std::this_thread::sleep_for(std::chrono::milliseconds(500));
}


// Function to find the position of 'X' in the maze grid and return it as a pair of row and column indices
std::pair<int,int> findX(const MazeGrid& maze)
{
//Iterate through each cell in the maze grid to find the position of 'X' 
    for (int r = 0; r < MAZE_SIZE; ++r) {
        for (int c = 0; c < MAZE_SIZE; ++c) {
            if (maze[r][c] == 'X' || maze[r][c] == 'x') {
                return {r , c}; // return the row and column indices of 'X' as a pair
            }
        }
    }
    return {-1, -1}; // Return an invalid position if 'X' is not found
}

void traverseMaze(MazeGrid& maze, int r, int c, Direction dir, int steps = 0) {
    // out of bounds or boxed into a wall edge case
    if (r < 0 || r >= MAZE_SIZE || c < 0 || c >= MAZE_SIZE || maze[r][c] == '#') {
        return; // Stop immediately
    }

    if (steps > 500) {  
        std::cout << "\nError: Maze has no exit!!\n";
        exit(1); 
    }
    
    // Reach border and given that the cell is a dot for exit condition
    if ((r == 0 || r == MAZE_SIZE - 1 || c == 0 || c == MAZE_SIZE - 1) && maze[r][c] == '.') {
        maze[r][c] = 'X'; 
        printMaze(maze);
        std::cout << "\nMaze Solved!!\n";
        exit(0);
    }

    // Mark current position
    maze[r][c] = 'X';
    printMaze(maze);

    // Determine relative directions based on current facing direction using ennum class Direction
    int right_r = r, right_c = c; Direction right_dir;
    int straight_r = r, straight_c = c; Direction straight_dir;
    int left_r = r, left_c = c; Direction left_dir;
    
    if (dir == Direction::Up) {
        right_r = r; right_c = c + 1; right_dir = Direction::Right;
        straight_r = r - 1; straight_c = c; straight_dir = Direction::Up;
        left_r = r; left_c = c - 1; left_dir = Direction::Left;
    } else if (dir == Direction::Right) {
        right_r = r + 1; right_c = c; right_dir = Direction::Down;
        straight_r = r; straight_c = c + 1; straight_dir = Direction::Right;
        left_r = r - 1; left_c = c; left_dir = Direction::Up;
    } else if (dir == Direction::Down) {
        right_r = r; right_c = c - 1; right_dir = Direction::Left;
        straight_r = r + 1; straight_c = c; straight_dir = Direction::Down;
        left_r = r; left_c = c + 1; left_dir = Direction::Right;
    } else if (dir == Direction::Left) {
        right_r = r - 1; right_c = c; right_dir = Direction::Up;
        straight_r = r; straight_c = c - 1; straight_dir = Direction::Left;
        left_r = r + 1; left_c = c; left_dir = Direction::Down;
    }

    // Move based on priority: Right -> Straight -> Left -> Turn Around
    // We check != '#' so the algorithm can step on its own 'X' marks to escape dead ends.
    if (right_r >= 0 && right_r < MAZE_SIZE && right_c >= 0 && right_c < MAZE_SIZE && maze[right_r][right_c] != '#') {
        traverseMaze(maze, right_r, right_c, right_dir, steps + 1);
    } 
    else if (straight_r >= 0 && straight_r < MAZE_SIZE && straight_c >= 0 && straight_c < MAZE_SIZE && maze[straight_r][straight_c] != '#') {
        traverseMaze(maze, straight_r, straight_c, straight_dir, steps + 1);
    } 
    else if (left_r >= 0 && left_r < MAZE_SIZE && left_c >= 0 && left_c < MAZE_SIZE && maze[left_r][left_c] != '#') {
        traverseMaze(maze, left_r, left_c, left_dir, steps + 1);
    } 
    else {
        // Dead end: turn 180 degrees and step back
        if (dir == Direction::Up) traverseMaze(maze, r + 1, c, Direction::Down, steps + 1);
        else if (dir == Direction::Right) traverseMaze(maze, r, c - 1, Direction::Left, steps + 1);
        else if (dir == Direction::Down) traverseMaze(maze, r - 1, c, Direction::Up, steps + 1);
        else if (dir == Direction::Left) traverseMaze(maze, r, c + 1, Direction::Right, steps + 1);
    }
}


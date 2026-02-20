/*
file: maze_utils.h
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: This is the header file for the maze utilities. It contains the function prototypes for maze operations.
*/

#ifndef MAZE_UTILS_H 
#define MAZE_UTILS_H

#include <array> // For using array to represent the maze grid
#include <iostream> // For input/output operations

const int MAZE_SIZE = 12; // Define the size of the maze grid

// Define a type alias for the maze grid, which is a 2D array of characters
using MazeGrid = std::array<std::array<char, MAZE_SIZE>, MAZE_SIZE>; 

//enum class to represent the four possible directions of movement in the maze
enum class Direction { Right,Up,Left,Down };

// Function prototypes for maze operations
void printMaze(const MazeGrid& maze);
std::pair<int,int> findX(const MazeGrid& maze);
void traverseMaze(MazeGrid& maze, int r, int c, Direction dir, int steps);

#endif

#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H

#include <array>
#include <iostream>

const int MAZE_SIZE = 12;

using MazeGrid = std::array<std::array<char, MAZE_SIZE>, MAZE_SIZE>;

enum class Direction { Right,Up,Left,Down };

void printMaze(const MazeGrid& maze);
std::pair<int,int> findX(const MazeGrid& maze);
void traverseMaze(MazeGrid& maze, int r, int c, Direction dir);

#endif

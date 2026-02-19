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

void traverseMaze(MazeGrid& maze, int r, int c, Direction dir) {

    // Reach border and given that the cell is a dot for exit condition
    if ((r == 0 || r == MAZE_SIZE - 1 || c == 0 || c == MAZE_SIZE - 1) && maze[r][c] == '.') {
        maze[r][c] = 'X'; 
        printMaze(maze);
        std::cout << "\nMaze Solved!\n";
        exit(0);
    }

    // Mark current position
    maze[r][c] = 'X';
    printMaze(maze);

    // Determine relative directions based on current facing direction
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
        traverseMaze(maze, right_r, right_c, right_dir);
    } 
    else if (straight_r >= 0 && straight_r < MAZE_SIZE && straight_c >= 0 && straight_c < MAZE_SIZE && maze[straight_r][straight_c] != '#') {
        traverseMaze(maze, straight_r, straight_c, straight_dir);
    } 
    else if (left_r >= 0 && left_r < MAZE_SIZE && left_c >= 0 && left_c < MAZE_SIZE && maze[left_r][left_c] != '#') {
        traverseMaze(maze, left_r, left_c, left_dir);
    } 
    else {
        // Dead end: turn 180 degrees and step back
        if (dir == Direction::Up) traverseMaze(maze, r + 1, c, Direction::Down);
        else if (dir == Direction::Right) traverseMaze(maze, r, c - 1, Direction::Left);
        else if (dir == Direction::Down) traverseMaze(maze, r - 1, c, Direction::Up);
        else if (dir == Direction::Left) traverseMaze(maze, r, c + 1, Direction::Right);
    }
}


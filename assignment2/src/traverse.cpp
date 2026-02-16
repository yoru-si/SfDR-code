#include <iostream>
#include <array>
#include <cstdlib>

template <typename T, std::size_t Row, std::size_t Col>
void traverseMaze(std::array<std::array<T, Col>, Row> &maze, std::size_t r, std::size_t c)
{
    maze[r][c]='X';

    printArray(maze);
    std::cout<<"\n---------------\n";
    // maybe a delay
    
    if(r==0 || r==Row - 1 || c==0 || c==Col - 1)
    {
        std::cout<<"Maze Solved\n";
        std::exit(0);
    }
}

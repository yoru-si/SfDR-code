#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H

#include <array>
#include <utility>
 
template <typename T, std::size_t Row, std::size_t Col>
int FindX(const std::array<std::array<T, Col>, Row> &maze)
{
    for (std::size_t r = 0; r<Row; ++r)
    {
        for (std::size_t c=0; c<Col; ++c)
            if (maze[r][c] == 'X'){
                return std::make_pair(r, c);
            }
        return std::make_pair(Row, Col);
    }
}

#endif

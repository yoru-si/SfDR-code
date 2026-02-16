#ifndef MAZE_UTILS_H
#define MAZE_UTILS_H

#include <array>
#include <utility>
 
template <typename T, std::size_t Row, std::size_t Col>
std::pair<std::size_t, std::size_t> FindX(const std::array<std::array<T, Col>, Row> &maze)
{
    for (std::size_t r = 0; r<Row; ++r)
    {
        for (std::size_t c=0; c<Col; ++c)
            if (maze[r][c] == 'X'){
                return {r , c};
            }
    }
    return {Row, Col};
}

#endif

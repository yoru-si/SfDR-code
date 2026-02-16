#ifndef PRINTARRAY_H
#define PRINTARRAY_H
#include <array>
#include <iostream>


template <typename T, std::size_t Row, std::size_t Col>
void PrintArray(const std::array<std::array<T, Col>, Row> &maze)
{
    for (const auto& arow: maze)   //access each row
    {
        for (const auto& e: arow)  //access each element of a row
            std::cout <<e<< ' ';
            
        std::cout << '\n';
    }
}

#endif

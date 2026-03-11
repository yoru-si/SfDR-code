Assignment 1.1 - Compile and run a simple divide program
________________________________

1. Compile Command:
cd assignment1.1/
g++ -Iinclude -c src/divide.cpp -o divide.o
g++ -Iinclude -c src/main.cpp -o main.o

2. Link Command:
g++ main.o divide.o -o division

3. What it does:
- Two numbers defined in the main.cpp are sent as input to the divide function and an output is printed back.
- The compile command compiles the division.cpp and main.cpp files individually, later they are linked together by running a command with their output files into another executable file.


Locate files:
- Functions src/divide.cpp
- Function Declarations include/divide.h
- Main file src/main.cpp

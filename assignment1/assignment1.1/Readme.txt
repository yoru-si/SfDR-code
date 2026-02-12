Assignment 1.1 - Compile and run a simple divide program
________________________________

1. Build Command:
cd assignment1.1/
g++ -Iinclude src/*.cpp -o my_program

2. Run Command
Linux: ./my_program

3. What it does:
- Two numbers defined in the main.cpp are sent as input to the divide function and an output is printed back.
- The compile command includes header files (-Iinclude) and complies all files that end with .cpp extension listed in the src folder (src/*.cpp). An executable my_program is generated (-o my_program)


Locate files:
- Functions src/divide.cpp
- Function Declarations include/divide.h
- Main file src/main.cpp

/*
file: main.cpp
Author: Srikrishnan Srinivasan(s3603288), Raghavendran Srinivasan(s3656721)
Group number: SDfR-PPD 16

Description: Main file where the division function is called.
*/
#include "divide.h"
#include <iostream>

int main(void){
    int a =7;
    int b =3;
    int c =divide(a,b);
    std::cout<<a<<"/"<<b<<"="<<c<<std::endl;
}

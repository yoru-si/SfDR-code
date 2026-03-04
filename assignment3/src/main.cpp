//==============================================================
// Filename    : main.cpp    
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// License     : N.A. or opensource license like LGPL
// Description : Main File, contains the fillList function definition and calls the concatenate function here.
//==============================================================
#include <iostream>
#include "ListNode.h"
#include "List.h"
#include <string>

void fillList(List<char>& myList){
    std::string userInput;
    std::cout << "Enter input string: \n";
    std::getline(std::cin, userInput);
    for (char letter : userInput){
        myList.insertAtBack(letter);
    }
}



int main() {
    List<char> newlist1;
    List<char> newlist2;
    fillList(newlist1);
    fillList(newlist2);
    newlist1.print();
    newlist2.print();
    List<char> conlist1;
    List<char> conlist2;
    fillList(conlist1);
    fillList(conlist2);
    conlist1.concatenate(conlist2);
    newlist2.concatenate(conlist1);
    newlist2.print();
    return 0;
}

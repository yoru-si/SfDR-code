//==============================================================
// Filename    : 
// Authors     : 
// Group       :
// License     :  N.A. or opensource license like LGPL
// Description : 
//==============================================================

#include <iostream>
#include <string>
#include "List.h"

using namespace std;


void fillList(const string& str, List<char>& list) {
    for (char ch : str) {
        list.insertAtBack(ch);
    }
}

int main() {    
    List<char> List1;
    List<char> List2;

    fillList("singlylinkedlist", List1);
    fillList("abcdefg", List2);

    cout << "List 1: ";
    List1.print();

    cout << "List 2: ";
    List2.print();

    return 0;
}

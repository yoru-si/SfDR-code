//==============================================================
// Filename    : main.cpp
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// Description : Main file to demonstrate the usage of Package, TwoDayPackage and OvernightPackage classes. 
//==============================================================
#include "Package.h"
#include <iostream>
#include <vector>
using namespace std;

//Function to print cost of package
void printCosts(vector<Package*> packages) { //Create a vector of Package objects to store the packages and their costs
    for (Package* pkg : packages) {
        cout << "Package from " << pkg->getSenderName()
             << " to " << pkg->getReceiverName()
             << " costs: " << pkg->CalculateCost() << endl;
    }
}


int main() {
    vector<Package*> packages; //Vector initialized to store the packages and their costs

    packages.push_back(new TwoDayPackage("Alice", "123 Main St", "Bob", "456 Elm St", 10));
    packages.push_back(new TwoDayPackage("Charlie", "789 Oak St", "Dave", "321 Pine St", 5));
    packages.push_back(new OvernightPackage("Eve", "654 Maple St", "Frank", "987 Cedar St", 3));
    printCosts(packages);

    cout << "\nEdge test cases\n";
    packages.push_back(new TwoDayPackage("SmallSender", "1 Start St", "SmallReceiver", "1 End St", 0.1));
    packages.push_back(new OvernightPackage("SmallSender", "1 Start St", "SmallReceiver", "1 End St", 0.1));
    packages.push_back(new TwoDayPackage("LargeSender", "100 Start St", "LargeReceiver", "100 End St", 100));
    packages.push_back(new OvernightPackage("LargeSender", "100 Start St", "LargeReceiver", "100 End St", 100));
    printCosts(packages);

    cout << "\n Invalid cases\n";
    // negative weight test case
    packages.push_back(new TwoDayPackage("Charlie", "789 Oak St", "Dave", "321 Pine St", -5));

    cout << "\n Invalid case\n";
    // empty string test case
    packages.push_back(new OvernightPackage("", "111 Blank Ave", "", "222 Nowhere Rd", 2));

    cout << "\n Invalid case\n";
    // identical addresses test case
    packages.push_back(new TwoDayPackage("Gary", "Same House St", "Gina", "Same House St", 4));

    printCosts(packages);

    // Memory cleanup: delete the dynamically allocated packages
    for (Package* pkg : packages) { 
        delete pkg;
    }

    return 0;
}

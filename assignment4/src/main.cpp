//==============================================================
// Filename    : main.cpp
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// Description : Main function to demonstrate the usage of Package, TwoDayPackage and OvernightPackage classes. 
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

    // Memory cleanup: delete the dynamically allocated packages
    for (Package* pkg : packages) { 
        delete pkg;
    }

    return 0;
}
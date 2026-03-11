// src/main.cpp
#include "Package.h"
#include <iostream>
#include <vector>
using namespace std;

void printCosts(vector<Package*> packages) {
    for (auto pkg : packages) {
        cout << "Package from " << pkg->getSenderName()
             << " to " << pkg->getReceiverName()
             << " costs: " << pkg->CalculateCost() << endl;
    }
}


int main() {
    vector<Package*> packages;

    packages.push_back(new TwoDayPackage("Alice", "123 Main St", "Bob", "456 Elm St", 10));
    packages.push_back(new TwoDayPackage("Charlie", "789 Oak St", "Dave", "321 Pine St", 5));
    packages.push_back(new OvernightPackage("Eve", "654 Maple St", "Frank", "987 Cedar St", 3));

    printCosts(packages);

    // Clean up memory
    for (auto pkg : packages) {
        delete pkg;
    }

    return 0;
}
//==============================================================
// Filename    : Package.cpp
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// Description : Defines the functions of the Package, TwoDayPackage and OvernightPackage classes. 
//==============================================================

#include "Package.h"
#include <cmath>
#include <iostream>
#include <string>

// Constructor for package class to initilize the member variables
Package::Package(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : senderName(s_Name),
      senderAddress(s_Address),
      receiverName(r_Name),
      receiverAddress(r_Address),
      weight(w) 
{
      // edge case of zero or negative weight
      while (weight <= 0){
        std::cout<<"Warning: Invalid weight entered!"<< std::endl;
        std::cout<<"Please enter a valid weight for the package "<< senderName <<" to "<< receiverName <<"(>0) in Kilograms: ";
        std::cin>>weight;
      }

      // edge case of empty strings
      while (senderName.empty()) {
        std::cout << "\nWarning: Sender name is empty!" << std::endl;
        std::cout << "Please enter the sender's name for this new package: ";
        std::getline(std::cin >> std::ws, senderName); 
      }


      while (senderAddress.empty()) {
        std::cout << "\nWarning: Sender address is empty for " << senderName << "!" << std::endl;
        std::cout << "Please enter " << senderName << "'s address: ";
        std::getline(std::cin >> std::ws, senderAddress);
      }

      while (receiverName.empty()) {
        std::cout << "\nWarning: Receiver name is empty for the package from " << senderName << "!" << std::endl;
        std::cout << "Please enter the receiver's name: ";
        std::getline(std::cin >> std::ws, receiverName);
      }

      while (receiverAddress.empty()) {
        std::cout << "\nWarning: Receiver address is empty for the package going to " << receiverName << "!" << std::endl;
        std::cout << "Please enter " << receiverName << "'s address: ";
        std::getline(std::cin >> std::ws, receiverAddress);
      }

      // identical senders address and receivers address 
      while (senderAddress == receiverAddress){
        std::cout<<"Warning: Sender and Receiver Addresses for the delivery "<< senderName <<" to "<< receiverName <<" the same!"<< std::endl;
        std::cout<<"Please re-enter the receiver's address: ";
        std::getline(std::cin >> std::ws, receiverAddress); //getline reads the full text with spaces and is much suited for edge cases testing scenarios 
      }
}

double Package::CalculateCost() {
    return 0;
}

//Constructor for TwoDayPackage class to initilize the member variables
//Also calls the constructor of the base class to initilize the inherited member variables
TwoDayPackage::TwoDayPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : Package(s_Name, s_Address, r_Name, r_Address, w),
      flat_Fee(5),
      fee_per_kg(2.5) {}


//CalculateCost function for TwoDayPackage class to calculate the cost of the package based on the flat fee and the fee per kg
double TwoDayPackage::CalculateCost() { 
    return flat_Fee + (fee_per_kg * weight);
}

//Constructor for OvernightPackage class to initilize the member variables
//Also calls the constructor of the base class to initilize the inherited member variables
OvernightPackage::OvernightPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : TwoDayPackage(s_Name, s_Address, r_Name, r_Address, w),
      extra_fee(1.10) {}

//CalculateCost function for OvernightPackage class to calculate the cost of the package based on the cost calculated by the TwoDayPackage class and adding the extra fee for overnight delivery
double OvernightPackage::CalculateCost() {
    return TwoDayPackage::CalculateCost() + (extra_fee * pow(weight,2)); 
}

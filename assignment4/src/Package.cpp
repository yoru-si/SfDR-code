//==============================================================
// Filename    : Package.cpp
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// Description : Defines the functions of the Package, TwoDayPackage and OvernightPackage classes. 
//==============================================================

#include "Package.h"
#include <cmath>

#include <string>

// Constructor for package class to initilize the member variables
Package::Package(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : senderName(s_Name),
      senderAddress(s_Address),
      recieverName(r_Name),
      recieverAddress(r_Address),
      weight(w) {}

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
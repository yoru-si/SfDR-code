#include "Package.h"
#include <cmath>

#include <string>

Package::Package(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : senderName(s_Name),
      senderAddress(s_Address),
      recieverName(r_Name),
      recieverAddress(r_Address),
      weight(w) {}

double Package::CalculateCost() {
    return 0;
}

TwoDayPackage::TwoDayPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : Package(s_Name, s_Address, r_Name, r_Address, w),
      flat_Fee(5),
      fee_per_kg(2.5) {}

double TwoDayPackage::CalculateCost() {
    return flat_Fee + (fee_per_kg * weight);
}

OvernightPackage::OvernightPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w)
    : TwoDayPackage(s_Name, s_Address, r_Name, r_Address, w),
      extra_fee(1.10) {}

double OvernightPackage::CalculateCost() {
    return TwoDayPackage::CalculateCost() + (extra_fee * pow(weight,2)); 
}
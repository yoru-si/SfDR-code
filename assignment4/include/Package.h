//==============================================================
// Filename    : Package.h    
// Authors     : Srikrishnan Srinivasan (s3603288), Raghavendran Srinivasan (s3656721)
// Group       : Group 16
// Description : Defines the classes and functions prototypes for the Package, TwoDayPackage and OvernightPackage classes. 
//==============================================================
#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package{
    protected: // protected members to allow access in derived classes
        string senderName;
        string senderAddress;
        string recieverName;
        string recieverAddress;
        double weight;

    public:
    Package(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost(); // virtual function to allow overriding in derived classes

    //get functions for sender and receiver names, used in main.cpp to print the costs of the packages
    string getSenderName() const { return senderName; }
    string getReceiverName() const { return recieverName; }
};

class TwoDayPackage : public Package{
    private:
        double flat_Fee;
        double fee_per_kg;

    public:
    TwoDayPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost() override; //override specifier to indicate that this function overrides a virtual function in the base class
};

class OvernightPackage : public TwoDayPackage{
    private:
        double extra_fee;

    public:
    OvernightPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost() override; //override specifier to indicate that this function overrides a virtual function in the base class
};

#endif
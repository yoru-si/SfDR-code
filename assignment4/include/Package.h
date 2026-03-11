#ifndef PACKAGE_H
#define PACKAGE_H

#include <string>
using namespace std;

class Package{
    protected:
        string senderName;
        string senderAddress;
        string recieverName;
        string recieverAddress;
        double weight;

    public:
    Package(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost();

    string getSenderName() const { return senderName; }
    string getReceiverName() const { return recieverName; }
};

class TwoDayPackage : public Package{
    private:
        double flat_Fee;
        double fee_per_kg;

    public:
    TwoDayPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost() override;
};

class OvernightPackage : public TwoDayPackage{
    private:
        double extra_fee;

    public:
    OvernightPackage(string s_Name, string s_Address, string r_Name, string r_Address, double w);
    virtual double CalculateCost() override;
};

#endif
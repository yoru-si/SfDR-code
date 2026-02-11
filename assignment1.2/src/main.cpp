/*
File: main.cpp
Author: Raghavendran Srinivasan(s3656721), Srinkrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: This is the main file for the BMI calculator. 
It contains the main function which calls the functions defined in BMI.cpp to calculate and evaluate the BMI value based on user input.
*/


#include <iostream> //for cin, cout, endl
#include "bmi.h"    //BMI module header file

using namespace std;

//Function to verify that the user input for weight and height is valid (positive numbers in this case)
//Helps to prevent errors like runtime errors due to invalid input (like negative numbers or zero)
bool verifyInput(double weight, double height)
{
    return (weight > 0.0) && (height > 0.0);
}

int main()
{
    double weightKg, heightM; //Define variables to store user input for weight and height


    //User interaction
    cout << "Welcome to the BMI Calculator!" << endl;
    cout << "Please enter your weight in kilograms: ";
    cin >> weightKg;
    cout << "Please enter your height in meters: ";
    cin >> heightM;

    //Input verification
    if (!verifyInput(weightKg, heightM))
    {
        cout << "Invalid input. Weight and height must be positive numbers." << endl;
        return 1; // Exit with error code
    }

    //Execution of BMI calculation and evaluation
    double bmi = calculateBMI(weightKg, heightM);
    cout << "Your BMI is: " << bmi << endl;

    evaluateAndPrintBMI(bmi);
    
    printInfo();

    return 0; // Exit with success code
}


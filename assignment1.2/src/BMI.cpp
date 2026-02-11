/*
File Name: BMI.cpp
Author: Raghavendran Srinivasan(s3656721), Srinkrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16


Description: Definition of all the functions declared in BMI.h, which can be called my the main function
*/

#include <iostream>
#include "bmi.h"


// Function to calculate the BMI value given weight in kilograms and height in meters, returns a decimal value
double calculateBMI(double weightKg, double heightM)
{
    double heightSquared = heightM * heightM;
    return weightKg / heightSquared;
}


// Function to evaluate the BMI value and print the corresponding category 
void evaluateAndPrintBMI(double bmi)
{
    // Category thresholds based on the assignment table
    if (bmi < 18.5)
    {
        std::cout << "Your body is underweight." << std::endl;
    }
    else if (bmi < 25.0)
    {
        std::cout << "Your body is normal weight." << std::endl;
    }
    else if (bmi < 30.0)
    {
        std::cout << "Your body is overweight." << std::endl;
    }
    else
    {
        std::cout << "Your body is obese." << std::endl;
    }
}


// Function to print the information chart given in the assignment instructions
void printInfo()
{
    std::cout << "\nBMI VALUES (Department of Health and Human Services / NIH):\n";
    std::cout << "Underweight: less than 18.5\n";
    std::cout << "Normal:      between 18.5 and 24.9\n";
    std::cout << "Overweight:  between 25 and 29.9\n";
    std::cout << "Obese:       30 or greater\n";
}
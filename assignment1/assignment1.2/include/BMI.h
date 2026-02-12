/*
file: BMI.h
Author: Raghavendran Srinivasan(s3656721), Srikrishnan Srinivasan(s3603288)
Group number: SDfR-PPD 16

Description: This is the header file for the BMI calculator. It contains the function prototype for evaluating
*/

#ifndef divide_h
#define divide_h



/* Calculates the Body Mass Index (BMI), returns a decimal value */
double calculateBMI(double weight, double height);

/*Determines BMI category text, prints text of the datatype string*/
void evaluateAndPrintBMI(double bmi);

/*Prints the information chart, no input arguments, prints the information chart*/
void printInfo();

#endif

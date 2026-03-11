#include <iostream>
#include "BMI.h"

int main(void) {
    int wt = std::cin.get();
    int ht = std::cin.get();

    evaluateAndPrintBMI(wt, ht);

    return 0;
}

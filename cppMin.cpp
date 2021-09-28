#include <iostream>
#include "cppMin.hpp"

int cppMin(int num1, int num2) {
    std::cout << "Running C++ min." << std::endl;
    int result;

    if (num1 > num2)
        result = num1;
    else
        result = num2;

    return result;
}
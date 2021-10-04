#include <iostream>
#include "cppMin.hpp"

int cppMin(int num1, int num2) {
    std::cout << "Message from C++." << std::endl;
    int result;

    if (num1 < num2)
        result = num1;
    else
        result = num2;

    std::cout << "Minimum in C++ is " << result << "." << std::endl;
    return result;
}

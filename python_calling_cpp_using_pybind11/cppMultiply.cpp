#include <iostream>
#include <pybind11/pybind11.h>

float cppMultiply(int number0, float number1) {
    std::cout << "Message from C++." << std::endl;
    float product = number0 * number1;
    std::cout << "Product in C: " << product << std::endl;
    return product;
}

PYBIND11_MODULE(cpp_library, m) {
    m.doc() = "Module docstring.";

    m.def("cpp_multiply", &cppMultiply, "Function docstring.");
}

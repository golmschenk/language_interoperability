#include <iostream>
#include <pybind11/embed.h> // Everything needed for embedding Python.
namespace py = pybind11;

int main() {
    std::cout << "Message from C++." << std::endl;
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive.
    py::module_ calculator = py::module_::import("calculator");
    py::object result = calculator.attr("add")(1, 2);
    int number = result.cast<int>();
    std::cout << "Sum in C++ is " << number << "." << std::endl;
}

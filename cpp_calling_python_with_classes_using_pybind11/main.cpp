#include <iostream>
#include <pybind11/embed.h> // Everything needed for embedding Python.
namespace py = pybind11;

int main() {
    std::cout << "Message from C++." << std::endl;
    py::scoped_interpreter guard{}; // Start the interpreter and keep it alive.
    py::module_ robot_module = py::module_::import("robot");
    py::object robot = robot_module.attr("Robot")();
    robot.attr("move_forward")(1.5);
    py::object robot_position_python_object = robot.attr("position");
    auto robot_position = robot_position_python_object.cast<float>();
    std::cout << "Position in C++ is " << robot_position << "." << std::endl;
}

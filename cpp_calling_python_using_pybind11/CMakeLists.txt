cmake_minimum_required(VERSION 3.4)
project(cpp_calling_python_using_pybind11)

find_package(pybind11 REQUIRED)

add_executable(main.cpp)
target_link_libraries(cpp_calling_python_using_pybind11 PRIVATE pybind11::embed)

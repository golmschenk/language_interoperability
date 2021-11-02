cmake_minimum_required(VERSION 3.20)
project(fortran_calling_cpp_with_classes)

enable_language(Fortran)

add_library(robot SHARED robot.cpp robot.hpp robot.h)
add_executable(main main.f90)
target_link_libraries(main robot)

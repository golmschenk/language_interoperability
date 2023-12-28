cmake_minimum_required(VERSION 3.27)
project(fortran_calling_python_using_cffi Fortran)

enable_language(Fortran)

add_executable(fortran_calling_python_using_cffi src/main.f90)
target_link_libraries(fortran_calling_python_using_cffi ${CMAKE_SOURCE_DIR}/src/python_module_0.1.dylib)

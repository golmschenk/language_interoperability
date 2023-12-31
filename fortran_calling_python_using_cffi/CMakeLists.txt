cmake_minimum_required(VERSION 3.17)
project(fortran_calling_python_using_cffi Fortran)

enable_language(Fortran)

find_package(Python REQUIRED Interpreter Development)

add_custom_command(
        OUTPUT ${CMAKE_BINARY_DIR}/python_library_api_0.1.dylib
        COMMAND ${Python_EXECUTABLE} ${CMAKE_SOURCE_DIR}/src/python_library_api_build.py ${CMAKE_BINARY_DIR}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/src
)

add_custom_target(python_library_api_build DEPENDS ${CMAKE_BINARY_DIR}/python_library_api_0.1.dylib)

add_library(python_library_api SHARED IMPORTED)
add_dependencies(python_library_api python_library_api_build)
set_target_properties(python_library_api PROPERTIES
        IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/python_library_api_0.1.dylib
)

add_executable(fortran_executable src/main.f90)
target_link_libraries(fortran_executable python_library_api)

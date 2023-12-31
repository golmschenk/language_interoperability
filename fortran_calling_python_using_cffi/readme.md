# Fortran calling Python using CFFI.

An example of Fortran calling Python using CFFI.

## Usage

1. Build using the CMake file, using standard build commands (e.g., `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug` then `cmake --build build --config Debug `)
2. Run the built Fortran executable with `build/fortran_executable`.

## Language interoperability explanation
* Fortran is calling Python in this case.
* The CFFI package creates the interface between two.
* CMake is used as the build system.
* CMake also directly calls the Python script to build the shared library with CFFI.

## Caveats
* `dylib` has been hard coded in the CMake script, which will only work on macOS. It shouldn't be too hard to adapt to be general, but I have not yet done this.
* The way CMake is building the shared library though direct Python calls probably has plenty of failure points that are not checked for. This can probably be improved on. 
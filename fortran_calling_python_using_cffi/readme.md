# Fortran calling Python using CFFI.

## Incomplete

The current setup runs, but it requires a few manual steps. There is certainly a way to do this better. However, due to several parts feeling a bit to messy, I didn't pursue this route farther yet.

## Current steps
1. Build the Python shared library by going to `src` and running `python python_module_api_build.py`.
2. Build the Fortran executable via CMake.
3. Copy the Python shared library to the same directory as the Fortran executable.
4. Run the Fortran executable.

# Rust calling Python using pyo3

An example of Rust calling Python through pyo3.

## Usage

1. Build using the CMake file, using standard build commands (e.g., `cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug` then `cmake --build build --config Debug `)
2. Run the built Rust executable with `build/rust_executable`.

## Language interoperability explanation
* Rust is calling Python in this case.
* The pyo3 crate creates the interface between two.
* Python is dynamically linked, so the `libpython` shared library needs to be findable at runtime.
* CMake is used as the build system, with the corrosion package allowing CMake to work with Rust.
* CMake also installs the Python package through a direct call to `pip`. This might be a bit hacky, and there might be better options.

## Caveats
* Only tested on macOS. The CMake build uses an `rpath` linking to the Python library. This might not work on other OSes, and might need to be adjusted for them.

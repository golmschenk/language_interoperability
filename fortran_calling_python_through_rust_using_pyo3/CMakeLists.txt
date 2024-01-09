cmake_minimum_required(VERSION 3.17)

project(fortran_calling_python_through_rust_using_pyo3 LANGUAGES Fortran)

find_package(Python REQUIRED Interpreter Development)

include(FetchContent)

FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.4
)

FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)
# Required to make sure Rust uses the correct path to libpython at runtime.
corrosion_add_target_local_rustflags(rust_library "-Clink-args=-Wl,-rpath,${Python_LIBRARY_DIRS}")

add_executable(fortran_executable src/main.f90)
target_link_libraries(fortran_executable rust_library)

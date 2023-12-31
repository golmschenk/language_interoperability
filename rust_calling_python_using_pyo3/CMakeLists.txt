cmake_minimum_required(VERSION 3.17)

project(rust_calling_python_using_pyo3)

find_package(Python REQUIRED Interpreter Development)

add_custom_target(python_library
        COMMAND ${Python_EXECUTABLE} -m pip install -e ${CMAKE_SOURCE_DIR}
)

include(FetchContent)

FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.4
)

FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)
# Required to make sure Rust uses the correct path to libpython at runtime.
corrosion_add_target_local_rustflags(rust_executable "-Clink-args=-Wl,-rpath,${Python_LIBRARY_DIRS}")
add_dependencies(cargo-prebuild_rust_executable python_library)

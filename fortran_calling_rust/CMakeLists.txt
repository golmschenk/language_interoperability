cmake_minimum_required(VERSION 3.17)

project(fortran_calling_rust LANGUAGES Fortran)

include(FetchContent)

FetchContent_Declare(
        Corrosion
        GIT_REPOSITORY https://github.com/corrosion-rs/corrosion.git
        GIT_TAG v0.4
)

FetchContent_MakeAvailable(Corrosion)

corrosion_import_crate(MANIFEST_PATH Cargo.toml)

add_executable(fortran_executable src/main.f90)
target_link_libraries(fortran_executable rust_library)

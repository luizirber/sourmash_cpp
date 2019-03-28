#--------------------------------------------------------
# The CMakeLists.txt for:
# Author(s):                              AndrewGaspar
#--------------------------------------------------------

cmake_minimum_required (VERSION 3.10)
project (sourmash_cpp)

# Boiler plate to import cmake-cargo CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/cmake-cargo/cmake")

# Bootstraps building cmake-cargo-gen tool - in the future, cmake-cargo will
# support installation rather than having to build the helper-tool every time
# you configure
set(CARGO_DEV_MODE ON CACHE INTERNAL "")

# includes the Cargo CMake module
include(Cargo)

# Imports the rust_hello crate and all its targets into CMake.
# This will result in two build targets:
# - cargo_rust_hello
# - cargo-clean_rust_hello
# And three library targets:
# - rust_hello-static
# - rust_hello-shared
# - rust_hello (if BUILD_SHARED_LIBS, points to rust_hello-shared, eles rust_hello-static)
#
# cmake-cargo builds debug for CMAKE_BUILD_TYPE=Debug, and release for
# Release, RelWithDebInfo (with -g), and MinSizeRel (+ other flags)
add_crate(sourmash/Cargo.toml)

# Searches for cbindgen
#find_program(CBINDGEN cbindgen)

# Generates rust_hello.h
#add_custom_command(
#    OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/binding/rust_hello.h
#    COMMAND
#        ${CBINDGEN} ${CMAKE_CURRENT_SOURCE_DIR}/rust_hello/
#        -o ${CMAKE_CURRENT_BINARY_DIR}/binding/rust_hello.h
#    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/rust_hello/src/lib.rs)

# Adds target for generating rust_hello.h
add_custom_target(sourmash-include DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/sourmash/include/kmer_min_hash.hh)

# Defines the say_hello executable
add_executable(sourmash_cpp src/main.cpp)
target_compile_features(sourmash_cpp PRIVATE cxx_std_11)

# Make sure to add dependency on rust_hello.h generation
add_dependencies(sourmash_cpp sourmash-include)
target_include_directories(sourmash_cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sourmash/include)

# This links static rust_hello
target_link_libraries(sourmash_cpp sourmash-static)

# This links shared rust_hello
# target_link_libraries(say_hello rust_hello-shared)

#--------------------------------------------------------
# The CMakeLists.txt for: sourmash_cpp
# Author(s): luizirber
#--------------------------------------------------------

cmake_minimum_required (VERSION 3.10)
project (sourmash_cpp LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 11)

# Boiler plate to import cmake-cargo CMake modules
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/deps/cmake-cargo/cmake")

# Bootstraps building cmake-cargo-gen tool - in the future, cmake-cargo will
# support installation rather than having to build the helper-tool every time
# you configure
set(CARGO_DEV_MODE ON CACHE INTERNAL "")

# includes the Cargo CMake module
include(Cargo)

add_crate(sourmash/Cargo.toml)

add_custom_target(sourmash-include DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/sourmash/include/kmer_min_hash.hh)

# Defines the sourmash_cpp executable
add_executable(sourmash_cpp src/main.cpp)

add_dependencies(sourmash_cpp sourmash-include)
target_include_directories(sourmash_cpp PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sourmash/include)

# This links static sourmash
target_link_libraries(sourmash_cpp sourmash-static)

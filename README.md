# Compiling a C++ Program with a Statically-Linked Rust Library Using CMake

This is based on https://github.com/AndrewGaspar/cmake_including_rust
but using sourmash as an example.
 
#### Project Set-Up

This is an test case for adding Rust to a C++ project that is currently being
compiled using CMake, through the ExternalProject module. It's desired to have
this library be *statically* linked (using a `*.a` file) vs. dynamically-linked (using a `.so` file).

Clone with submodules:
```
$ git clone https://github.com/luizirber/sourmash_cpp
$ cd sourmash_cpp
$ git submodule update --init --remote --recursive
```

The project can be built by doing the following:
```
$ mkdir -p _build 
$ cd _build 
$ cmake ..
$ make
```

The set-up is currently the following:
``` 
    .
    ├── CMakeLists.txt
    ├── README.md
    ├── sourmash
    │   ├── include
    │   │   └── kmer_min_hash.hh
    │   ├── Cargo.toml
    │   └── src
    │       └── ...
    └── src
        └── main.cpp
```

The Rust library is compiled using `cargo build` through the ExternalProject module in CMake.

The `Cargo.toml` file for that project specifies that both a static and dynamic library should be built,
by specifying `crate-type = ["staticlib","cdylib"]` under `[lib]`.

### Links from the original repo

Reddit thread about this:
- https://www.reddit.com/r/rust/comments/8vnf2h/statically_linking_a_rust_program_for_c/
- https://github.com/TheYokai/rust-cpp-cmake

Rust Embedded's "A little Rust with your C":
- https://rust-embedded.github.io/book/interoperability/rust-with-c.html

A project using CMake and Rust to run Rust on a BBC micro:bit (search for ExternalProject):
- https://github.com/rossng/microbit-rust-hal

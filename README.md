# `feature-extractor`

[![License][badge-license]](LICENSE)
[![Status][badge-status]](https://github.com/andrefz/feature-extractor/actions?query=workflow%3Abuild)
[![Latest Release][badge-release]](https://github.com/andrefz/feature-extractor/releases/latest)
[![Downloads][badge-downloads]](https://github.com/andrefz/feature-extractor/releases)

[badge-license]: https://img.shields.io/github/license/andrefz/feature-extractor?style=for-the-badge
[badge-status]: https://img.shields.io/github/workflow/status/andrefz/feature-extractor/build?style=for-the-badge
[badge-release]: https://img.shields.io/github/v/release/andrefz/feature-extractor?style=for-the-badge
[badge-downloads]: https://img.shields.io/github/downloads/andrefz/feature-extractor/total?style=for-the-badge

`feature-extractor` is a LLVM analysis pass to extract static program
features for use in machine learning projects. The extracted features
are those present in the following article:

[Practical Aggregation of Semantical Program Properties for Machine Learning Based Optimization][inria-00551512]

[inria-00551512]: https://hal.inria.fr/inria-00551512/document

## Table of Contents

- [Requirements](#requirements)
  * [Platform Requirements](#platform-requirements)
  * [Build Requirements](#build-requirements)
  * [Runtime Requirements](#runtime-requirements)
- [Building from Source](#building-from-source)
- [Contributors](#contributors)
- [License](#license)

## Requirements

### Platform Requirements

This pass has only been tested on Linux, although it is expected to run on
MacOS without any modifications; Other platforms may require modifications
to the source code (contributions are welcome).

### Build Requirements

In order to build `feature-extractor` from source you will need:

* LLVM 9 or higher
* CMake 3.4.3 or higher
* CMake compatible build system like Make or Ninja
* Modern C++14 compiler (Clang is recommended)

### Runtime Requirements

In order to run this pass, you will need a compiler that either emits LLVM IR
to be used with `llvm-opt` or can use LLVM out-of-tree passes natively, such
as Clang or Rust.

## Building from Source

Example using Clang as compiler and Ninja as build system:

```sh
export CC=clang
export CXX=clang++
export CMAKE_GENERATOR=Ninja
export CMAKE_BUILD_TYPE=Release
git clone https://github.com/andrefz/feature-extractor.git
cd feature-extractor
mkdir build
cd build
cmake .. && cmake --build .
```

## Contributors

Those are the people who contributed to this project, in alphabetical order:

* [@andrefz](https://github.com/andrefz) - _André F. Zanella_
* [@leonardohn](https://github.com/leonardohn) - _Leonardo H. Neumann_

## License

This project is licensed under the [MIT License](LICENSE).

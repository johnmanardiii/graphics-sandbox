# Graphics Sandbox

This repository is intended to be a clean (currently Windows/MSVC only) repository for basing my graphics projects off of. It uses vcpkg for dependencies, but vcpkg is included as a local git submodule in manifest mode, so the project doesn't rely on a global installation.

## Windows Dependencies
* [CMake](https://cmake.org/download/) at least version 3.25
* A compiler that supports C++20

## Installation

Clone using 

``git clone --recurse-submodules https://github.com/johnmanardiii/graphics-sandbox.git``

``cd graphics-sandbox``

### CMake Configuration:

Create a binary directory, run the cmake configuration step, then build the binary:

```
mkdir build
cd build
cmake ..
```

Then open the generated .sln file.

### Tested on
* Visual Studio
* CLion
* MSVC
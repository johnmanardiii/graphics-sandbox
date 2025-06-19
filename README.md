# Graphics Sandbox

## Dependencies
* [CMake](https://cmake.org/download/) at least version 3.25
* A compiler that supports C++20
* Currently Windows only

## Installation

Clone using 

``git clone --recurse-submodules https://github.com/johnmanardiii/graphics-sandbox.git``

``cd graphics-sandbox``

### CMake Steps:

Create a binary directory, run the cmake configuration step, then build the binary:

```
mkdir build
cd build
cmake ..
cmake --build .
```

# TODO:
* Generate srcs by folder rather than specifying every source file